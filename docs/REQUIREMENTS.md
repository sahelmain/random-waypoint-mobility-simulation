# Project Requirements

## Course Information
- **Course**: CS5331 - Mobile Data Management and Privacy
- **Term**: Summer II 2025
- **Project**: #3 - Mobile Users Random Waypoint Mobility (RWP)
- **Points**: 20 total

## Implementation Requirements

### Network Configuration
- 25 nodes uniformly distributed
- Network size: 1,000 x 1,000 m²
- Random Waypoint mobility model

### Parameter Variations
Must run simulation with 4 parameter combinations:
1. Speed: 1 m/s, Pause: 0 seconds
2. Speed: 1 m/s, Pause: 50 seconds  
3. Speed: 2 m/s, Pause: 0 seconds
4. Speed: 2 m/s, Pause: 50 seconds

### Required Outputs
For each simulation run, generate:
- Initial network topology graph
- Network topology snapshots at times 2,000 and 4,000
- Average moving distance calculation
- Comparative analysis

### Technical Requirements
- Use CSIM simulation library
- Source code must include project header comment
- Follow specified file naming convention
- Include compilation and run instructions

### Submission Requirements
- Source code file: `proj3_azzam_sahel.c`
- Report file: `proj3_azzam_sahel.pdf`
- Include all graphs and analysis
- Provide run instructions and assumptions
- Submit through Raider Canvas before midnight on due date

## Compilation Command
```bash
./csim.gcc proj3_azzam_sahel.c -o proj3_azzam_sahel
```

## Execution Command
```bash
./proj3_azzam_sahel
``` 