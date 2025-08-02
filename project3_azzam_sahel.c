/* Project #3; Azzam, Sahel */
/* Random Waypoint Mobility Simulation */
/* CS5331 - Mobile Data Management and Privacy */

#include "csim.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_OF_NODES 25
#define size_of_network 1000
#define SIMULATION_TIME 5000
#define snapshot_time1 2000
#define snapshot_time2 4000


#define MOVING 0
#define PAUSED 1

typedef struct {
    int identifier;
    double x, y;
    double x_destination, y_destination;
    double speed;
    double pause_time, total_distance_traveled;
    int state;
    double pause_end_time;
} Node;


void initialize_nodes(Node nodes[], double speed, double pause_time);
void select_random_destination(Node* node);
double calculate_distance(double x1, double y1, double x2, double y2);
void move_node(Node* node, double time_step, double current_time);
void print_topology(Node nodes[], char* filename, double current_time);
double calculate_average_distance(Node nodes[]);
void run_simulation(double speed, double pause_time, char* scenario_name);

int main() 
{
    // Display project header and simulation information
    printf("/* Project #3; Azzam, Sahel */\n");
    printf("Random Waypoint Mobility Simulation\n\n");
    
    // Execute all four required simulation scenarios
    // Each scenario tests different combinations of speed and pause parameters
    
    printf("Running scenario 1: Speed 1 m/s, Pause 0 seconds\n");
    run_simulation(1.0, 0.0, "scenario1");
    
    printf("Running scenario 2: Speed 1 m/s, Pause 50 seconds\n");
    run_simulation(1.0, 50.0, "scenario2");
    
    printf("Running scenario 3: Speed 2 m/s, Pause 0 seconds\n");
    run_simulation(2.0, 0.0, "scenario3");
    
    printf("Running scenario 4: Speed 2 m/s, Pause 50 seconds\n");
    run_simulation(2.0, 50.0, "scenario4");
    
    return 0;
}

double calculate_distance(double x1, double y1, double x2, double y2) 
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

void select_random_destination(Node* node) 
{
    double random_x = (double)rand() / RAND_MAX;
    double random_y = (double)rand() / RAND_MAX;
    
    node->x_destination = random_x * size_of_network;
    node->y_destination = random_y * size_of_network;
}

void initialize_nodes(Node nodes[], double speed, double pause_time) 
{
    // Input validation
    if (nodes == NULL) {
        printf("Error: nodes array is NULL\n");
        return;
    }
    if (speed < 0.1 || speed > 50.0) {
        printf("Warning: speed %.2f outside recommended range [0.1, 50.0]\n", speed);
    }
    if (pause_time < 0 || pause_time > 3600) {
        printf("Warning: pause_time %.2f outside recommended range [0, 3600]\n", pause_time);
    }
    
    srand(time(NULL));
    for(int i = 0; i < NUM_OF_NODES; i++) 
    {
        Node* node = &nodes[i];
        node->identifier = i;
        node->x = (double)rand() / RAND_MAX * size_of_network;
        node->y = (double)rand() / RAND_MAX * size_of_network;
        node->speed = speed;
        node->pause_time = pause_time;
        node->total_distance_traveled = 0.0;
        node->state = MOVING;
        node->pause_end_time = 0.0;
        
        select_random_destination(node);
    }
}

void move_node(Node* node, double time_step, double current_time) 
{
    if(node->state == PAUSED) 
    {
        if(current_time >= node->pause_end_time) 
        {
            node->state = MOVING;
            select_random_destination(node);
        }
        return;
    }
    
    double distance_to_dest = calculate_distance(node->x, node->y, node->x_destination, node->y_destination);
    
    if(distance_to_dest <= node->speed * time_step) 
    {
        node->total_distance_traveled += distance_to_dest;
        node->x = node->x_destination;
        node->y = node->y_destination;
        
        node->state = PAUSED;
        node->pause_end_time = current_time + node->pause_time;
    } 
    else 
    {
        double dx = node->x_destination - node->x;
        double dy = node->y_destination - node->y;
        double distance = sqrt(dx*dx + dy*dy);
        
        dx /= distance;
        dy /= distance;
        
        double move_distance = node->speed * time_step;
        node->x += dx * move_distance;
        node->y += dy * move_distance;
        node->total_distance_traveled += move_distance;
    }
}

void print_topology(Node nodes[], char* filename, double current_time) 
{
    FILE *file = fopen(filename, "w");
    if(file == NULL) 
    {
        printf("Error opening file %s\n", filename);
        return;
    }
    
    fprintf(file, "# Network Topology at time %.1f\n", current_time);
    fprintf(file, "# Node_ID X_Position Y_Position State\n");
    
    for(int i = 0; i < NUM_OF_NODES; i++) 
    {
        fprintf(file, "%d %.2f %.2f %s\n", 
                nodes[i].identifier, 
                nodes[i].x, 
                nodes[i].y,
                (nodes[i].state == MOVING) ? "MOVING" : "PAUSED");
    }
    
    fclose(file);
    printf("Topology saved to %s\n", filename);
}

double calculate_average_distance(Node nodes[]) 
{
    double total_distance = 0.0;
    
    for(int i = 0; i < NUM_OF_NODES; i++) 
    {
        total_distance += nodes[i].total_distance_traveled;
    }
    
    return total_distance / NUM_OF_NODES;
}

void run_simulation(double speed, double pause_time, char* scenario_name) 
{
    Node nodes[NUM_OF_NODES];
    double current_time = 0.0;
    double time_step = 1.0;
    
    initialize_nodes(nodes, speed, pause_time);
    
    char filename[100];
    sprintf(filename, "%s_initial.txt", scenario_name);
    print_topology(nodes, filename, current_time);
    
    printf("Running simulation...\n");
    
    while(current_time < SIMULATION_TIME) 
    {
        for(int i = 0; i < NUM_OF_NODES; i++) 
        {
            move_node(&nodes[i], time_step, current_time);
        }
        
        current_time += time_step;
        
        if(current_time == snapshot_time1) 
        {
            sprintf(filename, "%s_snapshot_2000.txt", scenario_name);
            print_topology(nodes, filename, current_time);
        }
        
        if(current_time == snapshot_time2) 
        {
            sprintf(filename, "%s_snapshot_4000.txt", scenario_name);
            print_topology(nodes, filename, current_time);
        }
    }
    
    double avg_distance = calculate_average_distance(nodes);
    printf("Simulation completed for %s\n", scenario_name);
    printf("Average distance traveled: %.2f meters\n", avg_distance);
    printf("Speed: %.1f m/s, Pause time: %.1f seconds\n\n", speed, pause_time);
}