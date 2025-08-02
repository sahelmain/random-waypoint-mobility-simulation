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

## Implementation Status: ✅ COMPLETE

The simulation has been fully implemented and tested with all required features:

### ✅ Completed Features
- Random Waypoint algorithm implementation
- 25 mobile nodes with configurable parameters
- Four simulation scenarios: (1,0), (1,50), (2,0), (2,50)
- Network topology snapshots at times 0, 2000, and 4000
- Distance tracking and average calculations
- Visual graph generation from topology data
- Comprehensive analysis and reporting tools

## Expected Outputs

The simulation generates:
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

## Results Summary

Recent simulation results show expected behavior:
- **Scenario 1** (1 m/s, 0 pause): ~4,986m average distance
- **Scenario 2** (1 m/s, 50s pause): ~4,580m average distance  
- **Scenario 3** (2 m/s, 0 pause): ~9,943m average distance
- **Scenario 4** (2 m/s, 50s pause): ~8,384m average distance

## Documentation

- [Project Requirements](docs/REQUIREMENTS.md) - Official project specifications and deliverables
- [Setup Instructions](docs/SETUP.md) - How to install and configure CSIM20
- [Algorithm Details](docs/ALGORITHM.md) - Technical details of the RWP model
- [Contributing Guidelines](CONTRIBUTING.md) - How to contribute to this project

## Getting Started

### Compilation
```bash
./csim.gcc project3_azzam_sahel.c -o project3_azzam_sahel
```

### Execution
```bash
./project3_azzam_sahel
```

### Generate Graphs
```bash
python3 create_graphs.py
```

### View Analysis
```bash
python3 analysis_summary.py
```

## Files in Repository

- `project3_azzam_sahel.c` - Main simulation source code
- `create_graphs.py` - Graph generation utility
- `analysis_summary.py` - Results analysis tool
- `scenario*.txt` - Topology data files (12 files)
- `scenario*.png` - Network topology graphs (12 files)

## Authors

- Sahel Azzam - CS5331 Project Implementation

## License

This project is licensed under the MIT License - see the LICENSE file for details. 