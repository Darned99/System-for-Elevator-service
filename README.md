# System-for-Elevator-service

Project conduct basic class of elevator and bigger class of system for elevator with proper logic.

## Features 
- **Elevator functionality**: Each elevator can move up, move down, and handle floor requests.
- **System coordination**: Assigns the best elevator to handle hall calls based on distance.
- **Buffer functionality**: Maintains a queue of target floors for each elevator
- **Status display**: Provides detailed information about the state of all elevators, including:
    - Current floor
    - Current direction (`up`, `down`, or `idle`)
    - Next target floor
    - Floors in the request queue


## Classes

### `Elevator`

#### Constructor
- **`Elevator(int CurrentFloor, int MaxFloor, int MinFloor)`**:
    Initializes an elevator object with the current floor, maximum floor and minimum floor.

#### Methods
- **`getCurrentFloor()`**: Returns the current floor of the elevator.
- **`getDirection()`**: Returns the current direction of the elevator (`idle`, `up`, `down`).
- **`getBuffer()`**: Returns the queue of target floors.
- **`getNextTarget()`**: Returns the next target floor from the queue.
- **`moveUp()`**: Moves the elevator up by one floor.
- **`moveDown()`**: Moves the elevator down by one floor.
- **`stop()`**: Sets the elevator direction to 'idle'
- **`moveToFloor()`**: Handles movement to the next target floor.
- **`displayStatus()`**: Displays current status of elevator
- **`directionToString()`**: Convert direction enum into string
- **`addTargetFloor(int floor)`**: Adds a floor to the target queue if valid and not already present.
- **`canElevatorServeRequest(direction dir)`**: Checks if an elevator can handle a request based on its direction.


### `System`

#### Constructor
- **`System(int numElevators, int maxFloors)`**:
  Initializes a system with the number of elevators and maximum floors in the building.

#### Methods
- **`getElevator(int elevatorID)`**: Returns a reference to the specified elevator by its ID.
- **`elevatorStatus()`**: Displays the status of all elevators in the system.
- **`performNextStep()`**: Executes the next movement step for all elevators.
- **`findBestElevator(int pickupFloor, direction dir)`**: Finds the most suitable elevator for a hall call based on distance and direction.
- **`handleHallCall(int pickupFloor, direction dir)`**: Processes a hall call and assigns it to the best elevator.

## Requirements
- A C++20-compatible compiler
- CMake version 3.10 or higher

## Compilation and Usage

### Selecting a Generator

CMake requires a generator to create the build system, the generator depends on your operating system and tools:

- **CMake should detect genererator by itself then we would type commands below, however I've run into some troubles and I had to use cmake with -G option**
```bash
cmake -B build
cmake --build build
./build/ElevatorSystem
```

- **My configuration is Windows with MinGW**: Use `"MinGW Makefiles"`:
```bash
cmake -G "MinGW Makefiles" -B build
cmake --build build
./bu
