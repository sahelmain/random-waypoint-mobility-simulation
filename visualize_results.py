#!/usr/bin/env python3
"""
Data visualization script for Random Waypoint Mobility results
Generates comparative analysis charts and statistical summaries
"""

import matplotlib.pyplot as plt
import numpy as np
import json

def create_comparison_chart():
    scenarios = ['S1(1,0)', 'S2(1,50)', 'S3(2,0)', 'S4(2,50)']
    distances = [4986.2, 4580.1, 9943.7, 8384.5]
    
    plt.figure(figsize=(10, 6))
    bars = plt.bar(scenarios, distances, color=['#FF6B6B', '#4ECDC4', '#45B7D1', '#96CEB4'])
    plt.title('Average Moving Distance by Scenario')
    plt.ylabel('Distance (meters)')
    plt.xlabel('Scenario (Speed, Pause)')
    
    # Add value labels on bars
    for bar, distance in zip(bars, distances):
        plt.text(bar.get_x() + bar.get_width()/2, bar.get_height() + 100,
                f'{distance:.1f}m', ha='center', va='bottom')
    
    plt.tight_layout()
    plt.savefig('distance_comparison.png', dpi=300, bbox_inches='tight')
    print('Comparison chart saved as distance_comparison.png')

if __name__ == '__main__':
    create_comparison_chart()