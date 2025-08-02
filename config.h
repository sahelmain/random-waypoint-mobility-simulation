/* Project #3; Azzam, Sahel */
/* Random Waypoint Mobility Simulation Configuration */
/* CS5331 - Mobile Data Management and Privacy */

#ifndef CONFIG_H
#define CONFIG_H

/* ============================================================================
 * SIMULATION PARAMETERS
 * ============================================================================ */

/* Network Configuration */
#define NUM_NODES 25                    /* Number of mobile nodes in simulation */
#define NETWORK_WIDTH 1000.0           /* Network width in meters */
#define NETWORK_HEIGHT 1000.0          /* Network height in meters */

/* Speed configurations (m/sec) */
#define SPEED_SLOW 1.0                 /* Low mobility speed */
#define SPEED_FAST 2.0                 /* High mobility speed */

/* Pause time configurations (seconds) */
#define PAUSE_SHORT 0                  /* No pause between movements */
#define PAUSE_LONG 50                  /* Extended pause duration */

/* Simulation time parameters (seconds) */
#define SNAPSHOT_TIME_1 2000           /* First topology snapshot time */
#define SNAPSHOT_TIME_2 4000           /* Second topology snapshot time */
#define SIMULATION_END_TIME 5000       /* Total simulation duration */

/* ============================================================================
 * OUTPUT CONFIGURATION
 * ============================================================================ */

/* Output control flags */
#define ENABLE_TOPOLOGY_OUTPUT 1       /* Generate topology files */
#define ENABLE_DISTANCE_TRACKING 1     /* Track and calculate distances */
#define ENABLE_SNAPSHOTS 1             /* Create time-based snapshots */
#define ENABLE_VERBOSE_OUTPUT 0        /* Detailed console output */

/* File naming configuration */
#define MAX_FILENAME_LENGTH 256        /* Maximum filename buffer size */
#define TOPOLOGY_FILE_PREFIX "scenario" /* Prefix for output files */

/* ============================================================================
 * SIMULATION TUNING PARAMETERS
 * ============================================================================ */

/* Time step configuration */
#define DEFAULT_TIME_STEP 1.0          /* Default simulation time step */
#define MIN_TIME_STEP 0.1              /* Minimum allowed time step */
#define MAX_TIME_STEP 10.0             /* Maximum allowed time step */

/* Movement precision */
#define MOVEMENT_EPSILON 0.01          /* Minimum movement threshold */
#define POSITION_PRECISION 2           /* Decimal places for position output */

/* Random number generation */
#define RANDOM_SEED 0                  /* 0 for time-based, >0 for fixed seed */
#define USE_HIGH_QUALITY_RANDOM 1      /* Enhanced randomness if available */

/* ============================================================================
 * VALIDATION CONSTANTS
 * ============================================================================ */

/* Boundary validation */
#define MIN_COORDINATE 0.0             /* Minimum valid coordinate */
#define MAX_X_COORDINATE NETWORK_WIDTH /* Maximum X coordinate */
#define MAX_Y_COORDINATE NETWORK_HEIGHT /* Maximum Y coordinate */

/* Performance limits */
#define MAX_SIMULATION_TIME 86400      /* Maximum simulation time (24 hours) */
#define MAX_NODES 1000                 /* Maximum supported nodes */
#define MIN_NODES 1                    /* Minimum required nodes */

/* Speed and pause validation */
#define MIN_SPEED 0.1                  /* Minimum node speed (m/s) */
#define MAX_SPEED 50.0                 /* Maximum node speed (m/s) */
#define MIN_PAUSE_TIME 0               /* Minimum pause duration */
#define MAX_PAUSE_TIME 3600            /* Maximum pause duration (1 hour) */

/* ============================================================================
 * DEBUG AND DEVELOPMENT
 * ============================================================================ */

#ifdef DEBUG
    #define DEBUG_PRINT(fmt, ...) printf("DEBUG: " fmt "\n", ##__VA_ARGS__)
    #define TRACE_FUNCTION(name) printf("TRACE: Entering %s\n", name)
#else
    #define DEBUG_PRINT(fmt, ...)
    #define TRACE_FUNCTION(name)
#endif

/* Development flags */
#define ENABLE_ASSERTIONS 1            /* Enable runtime assertions */
#define ENABLE_PERFORMANCE_TIMING 0    /* Track function execution times */
#define ENABLE_MEMORY_TRACKING 0       /* Monitor memory usage */

/* ============================================================================
 * PROJECT METADATA
 * ============================================================================ */

#define PROJECT_VERSION "1.0.0"
#define PROJECT_AUTHOR "Sahel Azzam"
#define PROJECT_COURSE "CS5331"
#define PROJECT_DESCRIPTION "Random Waypoint Mobility Simulation"
#define BUILD_DATE __DATE__
#define BUILD_TIME __TIME__

#endif /* CONFIG_H */ 