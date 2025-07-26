# Random Waypoint Mobility Algorithm

## Overview

The Random Waypoint Mobility (RWP) model is a widely used mobility pattern in mobile ad hoc network simulations.

## Algorithm Steps

1. **Initialization**: Nodes are randomly distributed across the network area
2. **Destination Selection**: Each node randomly selects a destination point within the network boundaries
3. **Movement**: Node moves toward the destination at a constant speed
4. **Pause**: Upon reaching destination, node pauses for a specified duration
5. **Repeat**: Process repeats with new random destination selection

## Mathematical Model

### Position Update

```
x(t+1) = x(t) + v * cos(θ) * Δt
y(t+1) = y(t) + v * sin(θ) * Δt
```

Where:
- `v` is the node velocity
- `θ` is the direction angle toward destination
- `Δt` is the time step

### Distance Calculation

```
distance = √[(x_dest - x_current)² + (y_dest - y_current)²]
```

## Implementation Considerations

- Uniform random distribution for initial positions
- Uniform random distribution for destination selection
- Constant speed movement between waypoints
- Configurable pause times at destinations 