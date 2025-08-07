#!/bin/bash
# Automated test runner for all simulation scenarios
echo "Running Random Waypoint Mobility Simulation Tests..."
echo "========================================="

for scenario in 1 2 3 4; do
    echo "Testing Scenario $scenario..."
    ./project3_event_driven_test $scenario
    echo "Scenario $scenario completed."
    echo ""
done

echo "All tests completed successfully!"
