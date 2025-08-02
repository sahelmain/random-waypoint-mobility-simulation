# Contributing to Random Waypoint Mobility Simulation

Thank you for your interest in contributing to this mobile data management project!

## Project Overview

This repository contains a complete implementation of Random Waypoint Mobility simulation for CS5331 coursework. The project demonstrates mobile node behavior in a 1000x1000m network with configurable parameters.

## Development Setup

### Prerequisites

- **CSIM20** simulation library (preferred) or GCC compiler
- **Python 3.x** with matplotlib, pandas, numpy
- **Git** for version control
- **Make** utility for build automation

### Installation Steps

1. **Clone the repository**:
   ```bash
   git clone https://github.com/sahelmain/random-waypoint-mobility-simulation.git
   cd random-waypoint-mobility-simulation
   ```

2. **Install Python dependencies**:
   ```bash
   pip3 install matplotlib pandas numpy
   ```

3. **Install CSIM20** (optional but recommended):
   - Download from http://www.mesquite.com/
   - Follow platform-specific installation instructions
   - Ensure `csim.gcc` is in your PATH

### Building the Project

#### Using Make (Recommended)
```bash
# Build simulation
make

# Complete workflow (build + run + graphs + analysis)
make complete

# Individual targets
make run           # Build and run simulation
make graphs        # Generate topology graphs
make analysis      # Show analysis summary
make clean         # Clean build artifacts
```

#### Manual Compilation
```bash
# With CSIM
./csim.gcc proj3_azzam_sahel.c -o proj3_azzam_sahel

# With GCC fallback
gcc proj3_azzam_sahel.c -o proj3_azzam_sahel -lm
```

### Running the Simulation

```bash
# Execute simulation (generates all scenarios)
./proj3_azzam_sahel

# Generate visual graphs
python3 create_graphs.py

# View analysis summary
python3 analysis_summary.py
```

## Code Style Guidelines

### C Code Standards
- **Formatting**: Use consistent indentation (4 spaces or tabs)
- **Comments**: Include header comments with project/author information
- **Functions**: Document each function with purpose and parameters
- **Variables**: Use descriptive names (e.g., `node_speed` vs `s`)
- **Constants**: Use `#define` for magic numbers and configuration

### Python Code Standards
- **PEP 8**: Follow Python style guidelines
- **Docstrings**: Document all functions with purpose and parameters
- **Error Handling**: Include try/catch blocks for file operations
- **Imports**: Group imports logically (standard, third-party, local)

### File Organization
- **Source code**: Main simulation in `proj3_azzam_sahel.c`
- **Configuration**: Parameters in `config.h`
- **Documentation**: All docs in `docs/` directory
- **Scripts**: Analysis tools in root directory
- **Output**: Generated files (`scenario*.txt`, `scenario*.png`)

## Contribution Process

### 1. Fork and Branch
```bash
# Fork the repository on GitHub
git clone https://github.com/yourusername/random-waypoint-mobility-simulation.git
cd random-waypoint-mobility-simulation

# Create feature branch
git checkout -b feature/your-enhancement
```

### 2. Make Changes
- Follow code style guidelines
- Test your changes thoroughly
- Update documentation if needed
- Add comments explaining complex logic

### 3. Test Your Changes
```bash
# Verify compilation
make test-compile

# Run full simulation
make run

# Generate outputs
make graphs

# Check analysis
make analysis
```

### 4. Commit and Push
```bash
# Commit with descriptive message
git add .
git commit -m "Add feature: brief description of changes"

# Push to your fork
git push origin feature/your-enhancement
```

### 5. Submit Pull Request
- Create pull request on GitHub
- Include clear description of changes
- Reference any related issues
- Ensure all tests pass

## Types of Contributions

### Code Enhancements
- **Algorithm improvements**: Optimize RWP implementation
- **Performance optimizations**: Reduce memory usage or execution time
- **Error handling**: Add robustness to edge cases
- **New features**: Additional mobility models or analysis tools

### Documentation
- **API documentation**: Function and parameter descriptions
- **User guides**: Setup and usage instructions
- **Examples**: Sample configurations or use cases
- **Comments**: Code clarification and explanations

### Testing
- **Unit tests**: Individual function testing
- **Integration tests**: Full simulation workflow testing
- **Performance tests**: Benchmarking and optimization
- **Edge case testing**: Boundary condition validation

### Bug Reports and Issues

When reporting bugs:
1. **Clear title**: Descriptive summary of the issue
2. **Environment**: OS, compiler version, dependencies
3. **Steps to reproduce**: Exact commands and inputs used
4. **Expected vs actual**: What should happen vs what does happen
5. **Logs/output**: Include relevant error messages or output

Example bug report:
```
Title: Simulation crashes with pause time > 100 seconds

Environment: macOS 12.0, GCC 11.2, Python 3.9
Steps: ./proj3_azzam_sahel with PAUSE_LONG=150 in config.h
Expected: Normal simulation execution
Actual: Segmentation fault at node initialization
Error: [include error output]
```

## Development Guidelines

### Performance Considerations
- **Memory efficiency**: Minimize dynamic allocation
- **Computational complexity**: Optimize algorithms for large node counts
- **File I/O**: Batch file operations when possible
- **Visualization**: Consider memory usage for large graphs

### Security Best Practices
- **Input validation**: Check all user inputs and file data
- **Buffer safety**: Use safe string functions (snprintf vs sprintf)
- **File permissions**: Set appropriate permissions for output files
- **Memory management**: Free all allocated memory

### Compatibility
- **CSIM integration**: Maintain compatibility with CSIM library
- **GCC fallback**: Ensure code works without CSIM
- **Python versions**: Support Python 3.6+
- **Cross-platform**: Test on multiple operating systems

## Project Structure

```
random-waypoint-mobility-simulation/
├── proj3_azzam_sahel.c      # Main simulation source
├── config.h                 # Configuration parameters
├── Makefile                 # Build automation
├── create_graphs.py         # Graph generation utility
├── analysis_summary.py      # Results analysis tool
├── docs/                    # Documentation
│   ├── SETUP.md            # Installation instructions
│   ├── REQUIREMENTS.md     # Project requirements
│   └── ALGORITHM.md        # Algorithm details
├── scenario*.txt           # Topology data (generated)
├── scenario*.png           # Visualization graphs (generated)
├── README.md               # Project overview
├── CONTRIBUTING.md         # This file
├── LICENSE                 # MIT license
└── .gitignore              # Git ignore patterns
```

## Getting Help

### Resources
- **CSIM Documentation**: http://www.mesquite.com/documentation/
- **Project Issues**: Use GitHub issue tracker
- **Algorithm Reference**: See `docs/ALGORITHM.md`
- **Setup Guide**: See `docs/SETUP.md`

### Contact
- **Course**: CS5331 - Mobile Data Management and Privacy
- **Institution**: Texas Tech University
- **Author**: Sahel Azzam (saazzam@ttu.edu)

Thank you for contributing to this mobile data management simulation project! 