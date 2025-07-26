# Makefile for Random Waypoint Mobility Simulation

# Project settings
PROJECT_NAME = proj3_azzam_sahel
SOURCE_DIR = src
SOURCE_FILE = $(SOURCE_DIR)/$(PROJECT_NAME).c

# CSIM settings
CSIM_CC = ./csim.gcc
TARGET = $(PROJECT_NAME)

# Default target
all: $(TARGET)

# Build the simulation
$(TARGET): $(SOURCE_FILE)
	$(CSIM_CC) $(SOURCE_FILE) -o $(TARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET)
	rm -f *.o
	rm -f *.out

# Run the simulation
run: $(TARGET)
	./$(TARGET)

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Build the simulation (default)"
	@echo "  clean   - Remove build artifacts"
	@echo "  run     - Build and run the simulation"
	@echo "  help    - Show this help message"

.PHONY: all clean run help 