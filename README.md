# Random Waypoint Mobility (RWP) Simulation

A mobile data management project implementing Random Waypoint Mobility model for network simulation.

## Project Overview

This project simulates 25 mobile nodes in a 1000x1000m network using the Random Waypoint Mobility model. Each node randomly selects destinations, moves at specified speeds, and pauses for configurable durations.

### Simulation Parameters

- **Number of nodes**: 25
- **Network size**: 1,000 x 1,000 m²
- **Mobility model**: Random Waypoint (RWP)
- **Speed**: 1 or 2 m/sec
- **Pause time**: 0 or 50 seconds

## Expected Outputs

The simulation will generate:
- Initial network topology graph
- Network topology snapshots at 2,000 and 4,000 simulation times
- Average moving distance calculations
- Comparative analysis across different parameter sets

## Test Scenarios

The simulation runs with four different parameter combinations:
1. Speed: 1 m/s, Pause time: 0 seconds
2. Speed: 1 m/s, Pause time: 50 seconds
3. Speed: 2 m/s, Pause time: 0 seconds
4. Speed: 2 m/s, Pause time: 50 seconds

## Documentation

- [Setup Instructions](docs/SETUP.md) - How to install and configure CSIM20
- [Algorithm Details](docs/ALGORITHM.md) - Technical details of the RWP model
- [Contributing Guidelines](CONTRIBUTING.md) - How to contribute to this project

## Getting Started

Coming soon...

## Authors

- Your Name - Initial work

## License

This project is licensed under the MIT License - see the LICENSE file for details. 