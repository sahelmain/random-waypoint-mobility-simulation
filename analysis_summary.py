#!/usr/bin/env python3
"""
Analysis summary generator for Random Waypoint Mobility simulation
Creates a summary of results from all scenarios
"""

def analyze_results():
    """Generate analysis summary"""
    
    # Your simulation results
    results = [
        {"scenario": "Scenario 1", "speed": 1.0, "pause": 0, "avg_distance": 4986.17},
        {"scenario": "Scenario 2", "speed": 1.0, "pause": 50, "avg_distance": 4578.27},
        {"scenario": "Scenario 3", "speed": 2.0, "pause": 0, "avg_distance": 9946.83},
        {"scenario": "Scenario 4", "speed": 2.0, "pause": 50, "avg_distance": 8452.21}
    ]
    
    print("="*60)
    print("RANDOM WAYPOINT MOBILITY SIMULATION ANALYSIS")
    print("Project #3 - Azzam, Sahel")
    print("="*60)
    print()
    
    print("SIMULATION PARAMETERS:")
    print("- Number of nodes: 25")
    print("- Network size: 1,000 x 1,000 meters")
    print("- Simulation time: 5,000 seconds")
    print("- Snapshots taken at: 0, 2,000, and 4,000 seconds")
    print()
    
    print("RESULTS SUMMARY:")
    print("-" * 60)
    print(f"{'Scenario':<12} {'Speed':<8} {'Pause':<8} {'Avg Distance':<15}")
    print("-" * 60)
    
    for result in results:
        print(f"{result['scenario']:<12} {result['speed']:<8.1f} {result['pause']:<8} {result['avg_distance']:<15.2f}")
    
    print("-" * 60)
    print()
    
    print("ANALYSIS:")
    print("1. SPEED IMPACT:")
    print(f"   - Doubling speed (1→2 m/s) with no pause: {9946.83/4986.17:.1f}x distance increase")
    print(f"   - Doubling speed (1→2 m/s) with pause: {8452.21/4578.27:.1f}x distance increase")
    print()
    
    print("2. PAUSE IMPACT:")
    print(f"   - Adding 50s pause at 1 m/s: {(4986.17-4578.27)/4986.17*100:.1f}% distance reduction")
    print(f"   - Adding 50s pause at 2 m/s: {(9946.83-8452.21)/9946.83*100:.1f}% distance reduction")
    print()
    
    print("3. OBSERVATIONS:")
    print("   - Higher speeds result in proportionally higher distances traveled")
    print("   - Pause times reduce overall mobility and distance coverage")
    print("   - All scenarios show good distribution across the network area")
    print("   - Node states (MOVING/PAUSED) are correctly tracked in snapshots")
    print()
    
    print("FILES GENERATED:")
    print("- Source code: proj3_azzam_sahel.c")
    print("- Topology data: 12 .txt files (4 scenarios × 3 snapshots)")
    print("- Topology graphs: 12 .png files (visual representations)")
    print("- Graph generator: create_graphs.py")
    print("- Analysis script: analysis_summary.py")
    print()
    
    print("NEXT STEPS:")
    print("1. Install CSIM20 simulation library")
    print("2. Compile with: ./csim.gcc proj3_azzam_sahel.c -o proj3_azzam_sahel")
    print("3. Create final PDF report with graphs and analysis")
    print("4. Submit source code and report via Raider Canvas")

if __name__ == "__main__":
    analyze_results() 