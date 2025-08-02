# Setup Instructions

## Installing CSIM20

### Prerequisites

Before installing CSIM20, ensure you have:
- GCC compiler (version 4.0 or later)
- Make utility
- Standard C development tools
- Python 3.x (for graph generation)
- Matplotlib library for Python

### Python Dependencies Setup

Install required Python packages:
```bash
pip3 install matplotlib pandas numpy
```

### CSIM20 Installation

1. Download CSIM20 from the official website: http://www.mesquite.com/
2. Extract the archive to your desired location
3. Follow the installation instructions for your platform
4. Ensure the `csim.gcc` wrapper is executable

### Environment Setup

Add CSIM to your environment:

```bash
export CSIM_PATH=/path/to/csim
export PATH=$PATH:$CSIM_PATH/bin
```

Add these lines to your `.bashrc` or `.zshrc` for permanent setup.

## Project Compilation

### Method 1: Using Make (Recommended)

The project includes an intelligent Makefile that automatically detects CSIM availability:

```bash
# Build the simulation
make

# Run complete workflow
make complete

# Individual operations
make run           # Build and run simulation
make graphs        # Generate topology graphs
make analysis      # Show analysis summary
make clean         # Clean build artifacts
```

### Method 2: Manual Compilation

#### With CSIM (Preferred)
```bash
./csim.gcc proj3_azzam_sahel.c -o proj3_azzam_sahel
```

#### Without CSIM (Fallback)
```bash
# Comment out the CSIM include first
sed 's/#include "csim.h"/\/\/ #include "csim.h"/' proj3_azzam_sahel.c > proj3_azzam_sahel_gcc.c
gcc proj3_azzam_sahel_gcc.c -o proj3_azzam_sahel -lm
```

## Running the Simulation

### Basic Execution
```bash
./proj3_azzam_sahel
```

### Complete Analysis Workflow
```bash
# Run simulation
./proj3_azzam_sahel

# Generate visual graphs
python3 create_graphs.py

# View analysis summary
python3 analysis_summary.py
```

## Output Files

The simulation generates the following files:
- `scenario1_initial.txt` through `scenario4_snapshot_4000.txt` (12 topology files)
- `scenario1_initial.png` through `scenario4_snapshot_4000.png` (12 graph files)

## Troubleshooting

### Common Issues

#### CSIM not found
**Error**: `./csim.gcc: No such file or directory`
**Solution**: 
1. Verify CSIM installation path
2. Check PATH environment variable
3. Use the Makefile which provides automatic fallback to GCC

#### Compilation errors
**Error**: `'csim.h' file not found`
**Solution**: 
1. Ensure CSIM is properly installed
2. Use the Makefile's automatic fallback feature
3. Manually compile with GCC using the fallback method

#### Python graph generation fails
**Error**: `ModuleNotFoundError: No module named 'matplotlib'`
**Solution**: 
```bash
pip3 install matplotlib pandas numpy
```

#### Runtime errors
**Error**: Simulation produces unexpected results
**Solution**: 
1. Verify simulation parameters are within valid ranges
2. Check random seed initialization
3. Review node movement and pause logic

### Performance Optimization

For large-scale simulations:
1. Adjust time step size in the source code
2. Modify network size parameters in `config.h`
3. Consider output file frequency for memory management

### Debugging Tips

1. **Enable verbose output**: Add debug print statements in key functions
2. **Check intermediate results**: Examine topology files manually
3. **Validate algorithms**: Test individual functions with known inputs
4. **Monitor resource usage**: Watch memory and CPU usage during long simulations

## Project Structure

```
Project3/
├── proj3_azzam_sahel.c      # Main simulation source
├── create_graphs.py         # Graph generation utility
├── analysis_summary.py      # Results analysis tool
├── Makefile                 # Build automation
├── config.h                 # Configuration parameters
├── docs/                    # Documentation
│   ├── SETUP.md            # This file
│   ├── REQUIREMENTS.md     # Project requirements
│   └── ALGORITHM.md        # Algorithm details
└── scenario*.{txt,png}     # Output files (generated)
```

## Verification

To verify your setup is working correctly:

1. **Test compilation**: `make test-compile`
2. **Run quick test**: `make run` (should complete without errors)
3. **Check outputs**: Verify 12 .txt files are generated
4. **Generate graphs**: `make graphs` (should create 12 .png files)
5. **View analysis**: `make analysis` (should display summary statistics)

## Getting Help

If you encounter issues:
1. Check this troubleshooting section
2. Review the project requirements in `docs/REQUIREMENTS.md`
3. Examine the algorithm details in `docs/ALGORITHM.md`
4. Consult CSIM documentation at http://www.mesquite.com/documentation/ 