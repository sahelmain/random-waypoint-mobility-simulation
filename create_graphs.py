#!/usr/bin/env python3
"""
Graph generator for Random Waypoint Mobility simulation
Converts topology .txt files to visual graphs
Author: Sahel Azzam
Course: CS5331 - Mobile Data Management and Privacy
"""

import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import os
import sys

def read_topology_file(filename):
    """Read topology data from file with error handling"""
    nodes = []
    try:
        with open(filename, 'r') as f:
            for line_num, line in enumerate(f, 1):
                if line.startswith('#') or line.strip() == '':
                    continue
                parts = line.strip().split()
                if len(parts) >= 4:
                    try:
                        node_id = int(parts[0])
                        x = float(parts[1])
                        y = float(parts[2])
                        state = parts[3]
                        nodes.append({'id': node_id, 'x': x, 'y': y, 'state': state})
                    except ValueError as e:
                        print(f"Warning: Invalid data on line {line_num} in {filename}: {e}")
                        continue
        return nodes
    except FileNotFoundError:
        print(f"Error: File {filename} not found")
        return []
    except Exception as e:
        print(f"Error reading {filename}: {e}")
        return []

def create_topology_graph(filename, title, output_file):
    """Create a scatter plot of node positions"""
    nodes = read_topology_file(filename)
    
    # Separate moving and paused nodes
    moving_nodes = [n for n in nodes if n['state'] == 'MOVING']
    paused_nodes = [n for n in nodes if n['state'] == 'PAUSED']
    
    plt.figure(figsize=(10, 10))
    
    # Plot moving nodes in blue
    if moving_nodes:
        moving_x = [n['x'] for n in moving_nodes]
        moving_y = [n['y'] for n in moving_nodes]
        plt.scatter(moving_x, moving_y, c='blue', label='Moving', s=50, alpha=0.7)
    
    # Plot paused nodes in red
    if paused_nodes:
        paused_x = [n['x'] for n in paused_nodes]
        paused_y = [n['y'] for n in paused_nodes]
        plt.scatter(paused_x, paused_y, c='red', label='Paused', s=50, alpha=0.7)
    
    plt.xlim(0, 1000)
    plt.ylim(0, 1000)
    plt.xlabel('X Position (meters)')
    plt.ylabel('Y Position (meters)')
    plt.title(title)
    plt.legend()
    plt.grid(True, alpha=0.3)
    plt.savefig(output_file, dpi=300, bbox_inches='tight')
    plt.close()
    print(f"Graph saved: {output_file}")

def main():
    # List of scenarios and files
    scenarios = [
        ("scenario1", "Speed 1 m/s, Pause 0 seconds"),
        ("scenario2", "Speed 1 m/s, Pause 50 seconds"),
        ("scenario3", "Speed 2 m/s, Pause 0 seconds"),
        ("scenario4", "Speed 2 m/s, Pause 50 seconds")
    ]
    
    times = [
        ("initial", "Initial Topology"),
        ("snapshot_2000", "Topology at 2000 seconds"),
        ("snapshot_4000", "Topology at 4000 seconds")
    ]
    
    print("Creating topology graphs...")
    
    for scenario, scenario_desc in scenarios:
        for time_suffix, time_desc in times:
            input_file = f"{scenario}_{time_suffix}.txt"
            output_file = f"{scenario}_{time_suffix}.png"
            title = f"{scenario_desc}\n{time_desc}"
            
            try:
                create_topology_graph(input_file, title, output_file)
            except FileNotFoundError:
                print(f"Warning: {input_file} not found")
    
    print("Graph generation complete!")

if __name__ == "__main__":
    main() 