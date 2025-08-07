/* Project #3; Azzam, Sahel */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "csim.h"


#define NUM_OF_NODES 25
#define NETWORK_SIZE 1000
#define SIMULATION_TIME 5000.0
#define SNAPSHOT_TIME_1 2000.0
#define SNAPSHOT_TIME_2 4000.0

typedef struct {
    int id;
    double x, y, dest_x, dest_y
    double speed, pause_time, total_distance;
    int is_moving;
} Node;

Node nodes[NUM_OF_NODES];
FILE *topology_files[12];
int file_index = 0;

void select_random_destination(int node_id) 
{
    nodes[node_id].dest_x = uniform(0.0, NETWORK_SIZE);
    nodes[node_id].dest_y = uniform(0.0, NETWORK_SIZE);
}

// calculates the distance between two points
double calculate_distance(double x1, double y1, double x2, double y2) 
{
    double x_diff = x2 - x1;
    double y_diff = y2 - y1;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}



// prints the topology to a file
void print_topology(char* filename, double current_time) 
{
    FILE *file = fopen(filename, "w");
    
    fprintf(file, "# Network Topology at time %.1f\n", current_time);
    fprintf(file, "# Node_ID X_Position Y_Position State\n");
    
    for(int i = 0; i < NUM_OF_NODES; i++) 
    {
        fprintf(file, "%d %.2f %.2f %s\n", 
                nodes[i].id, 
                nodes[i].x, 
                nodes[i].y,
                nodes[i].is_moving ? "MOVING" : "PAUSED");
    }
    
    fclose(file);
    printf("Topology saved to %s at time %.1f\n", filename, current_time);
}


void node_process(int node_id) 
{
    Node* node = &nodes[node_id];
    
    while(clock < SIMULATION_TIME) 
    {
        select_random_destination(node_id);
        node->is_moving = 1;
        
        // calculate distance and travel time
        double distance = calculate_distance(node->x, node->y, node->dest_x, node->dest_y);
        double travel_time = distance / node->speed;
        
        hold(travel_time);
        

        node->x = node->dest_x;
        node->y = node->dest_y;
        node->total_distance += distance;
        

        if(node->pause_time > 0) 
        {
            node->is_moving = 0;
            hold(node->pause_time);
        }
    }
}


void snapshot_process(char* scenario_name) 
{
    char filename[100];
    
    // initial snapshot
    sprintf(filename, "%s_initial.txt", scenario_name);
    print_topology(filename, 0.0);
    
    // this waits for first snapshot time
    hold(SNAPSHOT_TIME_1);
    sprintf(filename, "%s_snapshot_2000.txt", scenario_name);
    print_topology(filename, SNAPSHOT_TIME_1);
    
    // this waits for second snapshot time
    hold(SNAPSHOT_TIME_2 - SNAPSHOT_TIME_1);
    sprintf(filename, "%s_snapshot_4000.txt", scenario_name);
    print_topology(filename, SNAPSHOT_TIME_2);
}


void initialize_nodes(double speed, double pause_time) 
{
    for(int i = 0; i < NUM_OF_NODES; i++) 
    {
        nodes[i].id = i;
        nodes[i].x = uniform(0.0, NETWORK_SIZE);
        nodes[i].y = uniform(0.0, NETWORK_SIZE);
        nodes[i].speed = speed;
        nodes[i].pause_time = pause_time;
        nodes[i].total_distance = 0.0;
        nodes[i].is_moving = 1;
    }
}

// calculates the average distance traveled by all nodes
double calculate_average_distance() 
{
    double total = 0.0;

    for(int i = 0; i < NUM_OF_NODES; i++) 
    {
        total += nodes[i].total_distance;
    }
    return total / NUM_OF_NODES;
}


void run_scenario(double speed, double pause_time, char* scenario_name) 
{
    printf("\nRunning %s: Speed %.1f m/s, Pause %.1f seconds\n", 
           scenario_name, speed, pause_time);
    
    // this initializes the simulation
    initialize_nodes(speed, pause_time);
    
    // this is the snapshot process creaiton
    create("snapshot_process");
    snapshot_process(scenario_name);
    

    for(int i = 0; i < NUM_OF_NODES; i++) 
    {
        create("node_process");
        node_process(i);
    }
    
    hold(SIMULATION_TIME);
    

    double avg_distance = calculate_average_distance();
    printf("Simulation completed for %s\n", scenario_name);
    printf("Average distance traveled: %.2f meters\n", avg_distance);
}


void sim() 
{
    // this sets the fixed seed for fixed initial topology
    reseed(12345, 1);  
    
    
    printf("Random Waypoint Mobility Simulation\n");
    
    // all scenarios
    run_scenario(1.0, 0.0, "Scenario 1");
    reset();
    

    run_scenario(1.0, 50.0, "Scenario 2");
    reset();
    
    run_scenario(2.0, 0.0, "Scenario 3");
    reset();
    

    run_scenario(2.0, 50.0, "Scenario 4");
}