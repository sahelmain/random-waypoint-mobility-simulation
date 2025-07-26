/* Project #3; Azzam, Sahel */

#ifndef CONFIG_H
#define CONFIG_H

/* Simulation Parameters */
#define NUM_NODES 25
#define NETWORK_WIDTH 1000.0
#define NETWORK_HEIGHT 1000.0

/* Speed configurations (m/sec) */
#define SPEED_SLOW 1.0
#define SPEED_FAST 2.0

/* Pause time configurations (seconds) */
#define PAUSE_SHORT 0
#define PAUSE_LONG 50

/* Simulation time parameters */
#define SNAPSHOT_TIME_1 2000
#define SNAPSHOT_TIME_2 4000
#define SIMULATION_END_TIME 5000

/* Output configuration */
#define ENABLE_TOPOLOGY_OUTPUT 1
#define ENABLE_DISTANCE_TRACKING 1
#define ENABLE_SNAPSHOTS 1

/* Random seed (0 for time-based) */
#define RANDOM_SEED 0

#endif /* CONFIG_H */ 