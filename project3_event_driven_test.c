/* Project #3; Azzam, Sahel */
/* Event-Driven Local Test Implementation (No CSIM) */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_OF_NODES 25
#define NETWORK_SIZE 1000
#define SIMULATION_TIME 5000.0
#define SNAPSHOT_TIME_1 2000.0
#define SNAPSHOT_TIME_2 4000.0

typedef struct {
    int id;
    double x, y;
    double dest_x, dest_y;
    double speed;
    double pause_time;
    double total_distance;
    int is_moving;
} Node;

typedef struct Event {
    double time;
    int node_id;
    int type; // 0 = arrival, 1 = end_pause, 2 = snapshot
    char* snapshot_filename;
    struct Event* next;
} Event;

Node nodes[NUM_OF_NODES];
Event* event_queue = NULL;
double current_time = 0.0;
char* current_scenario;

// Forward declarations
void process_end_pause(int node_id);

// Event queue functions
void insert_event(double time, int node_id, int type, char* filename) {
    Event* new_event = (Event*)malloc(sizeof(Event));
    new_event->time = time;
    new_event->node_id = node_id;
    new_event->type = type;
    new_event->snapshot_filename = filename;
    new_event->next = NULL;
    
    if(event_queue == NULL || time < event_queue->time) {
        new_event->next = event_queue;
        event_queue = new_event;
    } else {
        Event* current = event_queue;
        while(current->next != NULL && current->next->time <= time) {
            current = current->next;
        }
        new_event->next = current->next;
        current->next = new_event;
    }
}

Event* get_next_event() {
    if(event_queue == NULL) return NULL;
    Event* next = event_queue;
    event_queue = event_queue->next;
    return next;
}

double uniform(double min, double max) {
    return min + (max - min) * ((double)rand() / RAND_MAX);
}

void select_random_destination(int node_id) {
    nodes[node_id].dest_x = uniform(0.0, NETWORK_SIZE);
    nodes[node_id].dest_y = uniform(0.0, NETWORK_SIZE);
}

double calculate_distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

void print_topology(char* filename, double time) {
    FILE *file = fopen(filename, "w");
    if(file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    
    fprintf(file, "# Network Topology at time %.1f\n", time);
    fprintf(file, "# Node_ID X_Position Y_Position State\n");
    
    for(int i = 0; i < NUM_OF_NODES; i++) {
        fprintf(file, "%d %.2f %.2f %s\n", 
                nodes[i].id, 
                nodes[i].x, 
                nodes[i].y,
                nodes[i].is_moving ? "MOVING" : "PAUSED");
    }
    
    fclose(file);
    printf("Topology saved to %s at time %.1f\n", filename, time);
}

void schedule_node_arrival(int node_id, double start_time) {
    Node* node = &nodes[node_id];
    
    // Calculate travel time
    double distance = calculate_distance(node->x, node->y, node->dest_x, node->dest_y);
    double travel_time = distance / node->speed;
    
    // Schedule arrival event
    insert_event(start_time + travel_time, node_id, 0, NULL);
}

void process_arrival(int node_id) {
    Node* node = &nodes[node_id];
    
    // Calculate distance traveled
    double distance = calculate_distance(node->x, node->y, node->dest_x, node->dest_y);
    node->total_distance += distance;
    
    // Update position
    node->x = node->dest_x;
    node->y = node->dest_y;
    
    // Set paused state
    node->is_moving = 0;
    
    // Schedule end of pause
    if(node->pause_time > 0) {
        insert_event(current_time + node->pause_time, node_id, 1, NULL);
    } else {
        // If no pause, immediately start moving again
        process_end_pause(node_id);
    }
}

void process_end_pause(int node_id) {
    Node* node = &nodes[node_id];
    
    // Select new destination
    select_random_destination(node_id);
    node->is_moving = 1;
    
    // Schedule next arrival
    schedule_node_arrival(node_id, current_time);
}

void initialize_nodes(double speed, double pause_time) {
    for(int i = 0; i < NUM_OF_NODES; i++) {
        nodes[i].id = i;
        nodes[i].x = uniform(0.0, NETWORK_SIZE);
        nodes[i].y = uniform(0.0, NETWORK_SIZE);
        nodes[i].speed = speed;
        nodes[i].pause_time = pause_time;
        nodes[i].total_distance = 0.0;
        nodes[i].is_moving = 1;
        
        // Select initial destination
        select_random_destination(i);
        
        // Schedule first arrival
        schedule_node_arrival(i, 0.0);
    }
}

double calculate_average_distance() {
    double total = 0.0;
    for(int i = 0; i < NUM_OF_NODES; i++) {
        total += nodes[i].total_distance;
    }
    return total / NUM_OF_NODES;
}

void run_scenario(double speed, double pause_time, char* scenario_name) {
    printf("\nRunning %s: Speed %.1f m/s, Pause %.1f seconds\n", 
           scenario_name, speed, pause_time);
    
    // Reset simulation
    current_time = 0.0;
    event_queue = NULL;
    current_scenario = scenario_name;
    
    // Initialize nodes
    initialize_nodes(speed, pause_time);
    
    // Schedule snapshots
    char* filename1 = malloc(100);
    sprintf(filename1, "%s_initial.txt", scenario_name);
    insert_event(0.0, -1, 2, filename1);
    
    char* filename2 = malloc(100);
    sprintf(filename2, "%s_snapshot_2000.txt", scenario_name);
    insert_event(SNAPSHOT_TIME_1, -1, 2, filename2);
    
    char* filename3 = malloc(100);
    sprintf(filename3, "%s_snapshot_4000.txt", scenario_name);
    insert_event(SNAPSHOT_TIME_2, -1, 2, filename3);
    
    // Process events
    Event* event;
    while((event = get_next_event()) != NULL && event->time <= SIMULATION_TIME) {
        current_time = event->time;
        
        switch(event->type) {
            case 0: // Arrival
                process_arrival(event->node_id);
                break;
            case 1: // End pause
                process_end_pause(event->node_id);
                break;
            case 2: // Snapshot
                print_topology(event->snapshot_filename, current_time);
                free(event->snapshot_filename);
                break;
        }
        
        free(event);
    }
    
    // Clean up remaining events
    while((event = get_next_event()) != NULL) {
        if(event->snapshot_filename) free(event->snapshot_filename);
        free(event);
    }
    
    // Calculate results
    double avg_distance = calculate_average_distance();
    printf("Simulation completed for %s\n", scenario_name);
    printf("Average distance traveled: %.2f meters\n", avg_distance);
}

int main() {
    srand(time(NULL));
    
    printf("Random Waypoint Mobility Simulation - Event-Driven Test\n");
    
    // Run all scenarios
    run_scenario(1.0, 0.0, "scenario1_event");
    run_scenario(1.0, 50.0, "scenario2_event");
    run_scenario(2.0, 0.0, "scenario3_event");
    run_scenario(2.0, 50.0, "scenario4_event");
    
    return 0;
}