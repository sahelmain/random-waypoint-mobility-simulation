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

def main():
    """Main function with command line argument support"""
    import argparse
    
    parser = argparse.ArgumentParser(description='Generate topology graphs for RWP simulation')
    parser.add_argument('--scenario', type=str, help='Generate graphs for specific scenario only (e.g., scenario1)')
    parser.add_argument('--time', type=str, help='Generate graphs for specific time only (e.g., initial, snapshot_2000)')
    parser.add_argument('--output-dir', type=str, default='.', help='Output directory for graphs')
    parser.add_argument('--dpi', type=int, default=300, help='DPI for output images')
    parser.add_argument('--format', type=str, default='png', choices=['png', 'pdf', 'svg'], help='Output format')
    args = parser.parse_args()
    
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
    
    # Filter based on command line arguments
    if args.scenario:
        scenarios = [(s, d) for s, d in scenarios if s == args.scenario]
        if not scenarios:
            print(f"Error: Scenario '{args.scenario}' not found")
            return
    
    if args.time:
        times = [(t, d) for t, d in times if t == args.time]
        if not times:
            print(f"Error: Time '{args.time}' not found")
            return
    
    print("Creating topology graphs...")
    
    generated_count = 0
    for scenario, scenario_desc in scenarios:
        for time_suffix, time_desc in times:
            input_file = f"{scenario}_{time_suffix}.txt"
            output_file = f"{args.output_dir}/{scenario}_{time_suffix}.{args.format}"
            title = f"{scenario_desc}\n{time_desc}"
            
            try:
                create_topology_graph(input_file, title, output_file, args.dpi, args.format)
                generated_count += 1
            except FileNotFoundError:
                print(f"Warning: {input_file} not found")
    
    print(f"Graph generation complete! Generated {generated_count} graphs.")

def create_topology_graph(filename, title, output_file, dpi=300, format='png'):
    """Create a scatter plot of node positions with enhanced options"""
    nodes = read_topology_file(filename)
    
    if not nodes:
        print(f"Warning: No valid data found in {filename}")
        return
    
    # Separate moving and paused nodes
    moving_nodes = [n for n in nodes if n['state'] == 'MOVING']
    paused_nodes = [n for n in nodes if n['state'] == 'PAUSED']
    
    plt.figure(figsize=(10, 10))
    
    # Plot moving nodes in blue
    if moving_nodes:
        moving_x = [n['x'] for n in moving_nodes]
        moving_y = [n['y'] for n in moving_nodes]
        plt.scatter(moving_x, moving_y, c='blue', label=f'Moving ({len(moving_nodes)})', s=50, alpha=0.7)
    
    # Plot paused nodes in red
    if paused_nodes:
        paused_x = [n['x'] for n in paused_nodes]
        paused_y = [n['y'] for n in paused_nodes]
        plt.scatter(paused_x, paused_y, c='red', label=f'Paused ({len(paused_nodes)})', s=50, alpha=0.7)
    
    plt.xlim(0, 1000)
    plt.ylim(0, 1000)
    plt.xlabel('X Position (meters)')
    plt.ylabel('Y Position (meters)')
    plt.title(title)
    plt.legend()
    plt.grid(True, alpha=0.3)
    
    # Add node count annotation
    plt.text(950, 50, f'Total Nodes: {len(nodes)}', 
             bbox=dict(boxstyle="round,pad=0.3", facecolor="yellow", alpha=0.7),
             horizontalalignment='right')
    
    plt.savefig(output_file, dpi=dpi, bbox_inches='tight', format=format)
    plt.close()
    print(f"Graph saved: {output_file}")

if __name__ == "__main__":
    main() 