# Banker's Algorithm Implementation
(This is the second project of the Operating Systems course at the Egyptian Chinese University)

## Overview

This project implements the Banker's Algorithm, a deadlock avoidance algorithm used in operating systems to manage resource allocation. The implementation was developed as the second project for the Operating Systems course at the Egyptian Chinese University.

The Banker's Algorithm determines whether a system state is safe or unsafe by simulating resource allocation and checking if all processes can complete their execution without encountering deadlock.

## Features

The implementation provides two input methods for system configuration:

**File Input Mode**: Reads system state from a predefined input file (`input.txt`)
**User Input Mode**: Allows manual entry of system parameters through console interaction

## System Requirements

- C++ compiler with C++11 support or later
- Standard Template Library (STL) support
- Input file (`input.txt`) for file-based input mode

## Input File Format

When using file input mode, the `input.txt` file should follow this structure:

```
[number_of_processes] [number_of_resources]
[available_resource_1] [available_resource_2] ... [available_resource_n]
[allocation_matrix_for_all_processes]
[max_matrix_for_all_processes]
```

The allocation and max matrices should be provided row by row, with each process's allocation followed immediately by its maximum resource requirements.

## Algorithm Implementation

The program implements the core Banker's Algorithm through these key steps:

**Matrix Calculation**: Computes the Need matrix by subtracting the Allocation matrix from the Max matrix for each process.

**Safety Check**: Iteratively searches for processes that can complete execution with currently available resources.

**Resource Simulation**: Temporarily allocates resources to safe processes and updates the available resource pool.

**State Determination**: Identifies whether the system is in a safe state with a valid execution sequence or an unsafe state with potential deadlock.

## Program Execution

Upon running the program, users select between two operational modes:

**Mode 1 (File Input)**: Automatically reads system configuration from `input.txt` and processes the data to determine system safety.

**Mode 2 (User Input)**: Prompts for manual entry of the number of processes, resources, allocation matrix, maximum requirements matrix, and available resources.

## Output

The program provides clear feedback on system state:

**Safe State**: Displays the safe execution sequence showing the order in which processes can complete without deadlock.

**Unsafe State**: Identifies problematic processes that cannot complete execution with the current resource allocation, indicating potential deadlock conditions.

## Technical Implementation Details

The implementation uses dynamic memory allocation through STL vectors to handle varying numbers of processes and resources. The algorithm employs boolean flags to track process completion status and floating-point arithmetic to accommodate fractional resource units.

The safety verification process continues until no additional processes can be safely executed, ensuring comprehensive deadlock detection across all system states.

## Educational Purpose

This implementation serves as a practical demonstration of deadlock avoidance principles in operating systems, providing hands-on experience with resource management algorithms and concurrent process execution simulation.
