# Makefile for Random Waypoint Mobility Simulation
# Author: Sahel Azzam
# Course: CS5331 - Mobile Data Management and Privacy

# Project settings
PROJECT_NAME = proj3_azzam_sahel
SOURCE_DIR = src
SOURCE_FILE = $(PROJECT_NAME).c
TARGET = $(PROJECT_NAME)

# CSIM settings
CSIM_CC = ./csim.gcc
GCC_FALLBACK = gcc
CFLAGS = -lm

# Check if CSIM compiler exists
CSIM_EXISTS := $(shell command -v $(CSIM_CC) 2> /dev/null)

# Default target
all: $(TARGET)

# Build the simulation with CSIM if available, fallback to GCC
$(TARGET): $(SOURCE_FILE)
ifdef CSIM_EXISTS
	@echo "Compiling with CSIM..."
	$(CSIM_CC) $(SOURCE_FILE) -o $(TARGET)
else
	@echo "CSIM not found, using GCC fallback..."
	@echo "Note: Commenting out CSIM include for GCC compilation"
	@sed 's/#include "csim.h"/\/\/ #include "csim.h"  \/\/ Commented for GCC/' $(SOURCE_FILE) > $(SOURCE_FILE).tmp
	$(GCC_FALLBACK) $(SOURCE_FILE).tmp -o $(TARGET) $(CFLAGS)
	@rm -f $(SOURCE_FILE).tmp
endif

# Clean build artifacts
clean:
	rm -f $(TARGET)
	rm -f *.o
	rm -f *.out
	rm -f *.tmp
	@echo "Cleaned build artifacts"

# Run the simulation
run: $(TARGET)
	./$(TARGET)

# Generate graphs from simulation output
graphs:
	@echo "Generating topology graphs..."
	python3 create_graphs.py

# Show analysis summary
analysis:
	@echo "Displaying analysis summary..."
	python3 analysis_summary.py

# Complete workflow: build, run, generate graphs, show analysis
complete: clean $(TARGET) run graphs analysis
	@echo "Complete simulation workflow finished!"

# Test compilation only
test-compile: $(TARGET)
	@echo "Compilation test successful!"

# Help target
help:
	@echo "Available targets:"
	@echo "  all         - Build the simulation (default)"
	@echo "  clean       - Remove build artifacts"
	@echo "  run         - Build and run the simulation"
	@echo "  graphs      - Generate topology visualization graphs"
	@echo "  analysis    - Display analysis summary"
	@echo "  complete    - Full workflow: clean, build, run, graphs, analysis"
	@echo "  test-compile- Test compilation only"
	@echo "  help        - Show this help message"
	@echo ""
	@echo "Note: Will use CSIM if available, otherwise falls back to GCC"

.PHONY: all clean run graphs analysis complete test-compile help 