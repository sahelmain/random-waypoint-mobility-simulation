# Random Waypoint Mobility Algorithm

## Overview

The Random Waypoint Mobility (RWP) model is a widely used mobility pattern in mobile ad hoc network simulations. This implementation provides a comprehensive simulation of 25 mobile nodes operating within a 1000×1000 meter network area.

## Algorithm Steps

### 1. Initialization Phase
- Nodes are randomly distributed across the network area using uniform distribution
- Each node is assigned initial parameters (speed, pause time)
- Random destinations are selected for each node
- Distance tracking variables are initialized to zero

### 2. Movement Phase
Each simulation time step involves:
- **Destination Selection**: Each node randomly selects a destination point within network boundaries
- **Direction Calculation**: Calculate movement vector toward destination
- **Movement Execution**: Node moves toward destination at constant speed
- **Boundary Validation**: Ensure movements stay within network limits

### 3. Arrival and Pause Phase
When a node reaches its destination:
- **Pause Initiation**: Node enters pause state for specified duration
- **State Tracking**: Node state changed from MOVING to PAUSED
- **Distance Accumulation**: Total travel distance updated
- **Next Destination**: New random destination selected after pause

### 4. Data Collection Phase
At specified intervals (0, 2000, 4000 seconds):
- **Topology Snapshots**: Current positions and states recorded
- **Distance Metrics**: Calculate average distances traveled
- **State Analysis**: Count of moving vs paused nodes

## Mathematical Model

### Position Update Equations

For a node moving from position (x, y) toward destination (x_dest, y_dest):

```
Direction Vector:
dx = x_dest - x_current
dy = y_dest - y_current
distance = √(dx² + dy²)

Normalized Direction:
dx_norm = dx / distance
dy_norm = dy / distance

Position Update:
x(t+1) = x(t) + v × dx_norm × Δt
y(t+1) = y(t) + v × dy_norm × Δt
```

Where:
- `v` is the node velocity (1.0 or 2.0 m/s)
- `Δt` is the time step (1.0 second)
- `θ` is the direction angle toward destination

### Distance Calculation

Euclidean distance between two points:
```
distance = √[(x_dest - x_current)² + (y_dest - y_current)²]
```

### Arrival Detection

A node is considered to have arrived at its destination when:
```
distance_to_destination ≤ speed × time_step
```

## Implementation Details

### Data Structures

```c
typedef struct {
    int identifier;              // Unique node ID (0-24)
    double x, y;                // Current position coordinates
    double x_destination, y_destination;  // Target coordinates
    double speed;               // Movement speed (m/s)
    double pause_time;          // Pause duration (seconds)
    double total_distance_traveled;  // Cumulative distance
    int state;                  // MOVING (0) or PAUSED (1)
    double pause_end_time;      // When current pause ends
} Node;
```

### Core Functions

1. **`initialize_nodes()`**: Set up initial node positions and parameters
2. **`select_random_destination()`**: Choose random target within bounds
3. **`move_node()`**: Update node position based on current state
4. **`calculate_distance()`**: Compute Euclidean distance
5. **`print_topology()`**: Save current network state to file

### State Management

Each node operates in one of two states:
- **MOVING**: Node is traveling toward its destination
- **PAUSED**: Node has reached destination and is stationary

State transitions:
- MOVING → PAUSED: When destination is reached
- PAUSED → MOVING: When pause duration expires

## Performance Analysis

### Computational Complexity

- **Time Complexity**: O(n × t) where n = number of nodes, t = simulation time steps
- **Space Complexity**: O(n) for storing node information
- **Movement Calculation**: O(1) per node per time step

### Scalability Considerations

- **Node Count**: Current implementation optimized for 25 nodes
- **Network Size**: 1000×1000m provides adequate space for mobility
- **Time Resolution**: 1-second time steps balance accuracy vs performance

### Memory Usage

- **Node Storage**: ~200 bytes per node
- **Total Memory**: ~5KB for 25 nodes plus overhead
- **Output Files**: ~1KB per topology snapshot

## Simulation Parameters

### Network Configuration
- **Area**: 1000×1000 meters (1 km²)
- **Node Count**: 25 mobile nodes
- **Boundary Handling**: Destinations constrained within network area

### Mobility Parameters
- **Speed Options**: 1.0 m/s (slow) or 2.0 m/s (fast)
- **Pause Options**: 0 seconds (continuous) or 50 seconds (intermittent)
- **Movement Pattern**: Straight-line travel to destinations

### Temporal Parameters
- **Simulation Duration**: 5000 seconds (83.33 minutes)
- **Time Step**: 1.0 second resolution
- **Snapshot Times**: 0, 2000, 4000 seconds

## Validation and Verification

### Expected Behaviors

1. **Speed Relationship**: Doubling speed should approximately double distance traveled
2. **Pause Impact**: Longer pauses should reduce total distance covered
3. **Distribution**: Nodes should maintain relatively uniform spatial distribution
4. **Boundary Respect**: No nodes should move outside network boundaries

### Performance Metrics

- **Average Distance**: Total distance / number of nodes
- **Spatial Distribution**: Node position variance over time
- **State Transitions**: Frequency of pause/movement cycles
- **Boundary Compliance**: Verification of coordinate limits

## Implementation Considerations

### Random Number Generation
- **Seed**: Time-based for different results per run
- **Distribution**: Uniform random for positions and destinations
- **Quality**: Standard C library functions adequate for simulation

### Numerical Precision
- **Floating Point**: Double precision for position calculations
- **Distance Accuracy**: Sufficient for meter-scale measurements
- **Time Resolution**: 1-second steps provide smooth movement

### Output Format
- **Topology Files**: Tab-separated values with headers
- **Position Precision**: 2 decimal places (centimeter accuracy)
- **State Encoding**: Text labels (MOVING/PAUSED) for clarity

## Extensions and Modifications

### Possible Enhancements

1. **Variable Speed**: Allow speed changes during simulation
2. **Realistic Mobility**: Add acceleration/deceleration phases
3. **Obstacle Avoidance**: Implement barriers within network area
4. **Group Mobility**: Coordinate movement of node clusters
5. **Battery Modeling**: Include energy consumption effects

### Parameter Tuning

- **Network Size**: Adjust area for different node densities
- **Speed Range**: Modify for walking vs vehicular mobility
- **Pause Distribution**: Use exponential or normal distributions
- **Destination Selection**: Weight certain areas more heavily

This implementation provides a solid foundation for mobile network simulation research and can be extended for more complex mobility patterns and analysis requirements. 