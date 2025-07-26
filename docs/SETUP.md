# Setup Instructions

## Installing CSIM20

### Prerequisites

Before installing CSIM20, ensure you have:
- GCC compiler
- Make utility
- Standard C development tools

### CSIM20 Installation

1. Download CSIM20 from the official website
2. Extract the archive
3. Follow the installation instructions for your platform

### Environment Setup

Add CSIM to your environment:

```bash
export CSIM_PATH=/path/to/csim
export PATH=$PATH:$CSIM_PATH/bin
```

## Compilation

Use the following command to compile the simulation:

```bash
./csim.gcc proj3_azzam_sahel.c -o proj3_azzam_sahel
```

## Troubleshooting

### Common Issues

- **CSIM not found**: Ensure CSIM is properly installed and in PATH
- **Compilation errors**: Check that all required headers are available
- **Runtime errors**: Verify simulation parameters are within valid ranges 