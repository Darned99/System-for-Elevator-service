# System-for-Elevator-service

Project conduct basic class of elevator and bigger class of system for elevator with proper logic.

## Features 
- **Elevator management**: Each elevator can move up, move down, and handle floor requests.
- **System coordination**: Assigns the best elevator to handle hall calls based on distance.
- **Buffer anagement**: Maintains a queue of target floors for each elevator
- **Displaying current status of elevators**: Provides information about each elevator's status, including current floor, direction, next target, and queued floors.

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
- **`addTargetFloor(int floor)`**: Adds a floor to the target queue if valid and not already present.


### `System`

#### Constructor
- **`System(int numElevators, int maxFloors)`**:
  Initializes a system with the number of elevators and maximum floors in the building.

#### Methods
- **`getElevator(int elevatorID)`**: Returns a reference to the specified elevator by its ID.
- **`elevatorStatus()`**: Displays the status of all elevators in the system.
- **`performNextStep()`**: Executes the next movement step for all elevators.
- **`canElevatorServeRequest(Elevator& elevator, direction dir)`**: Checks if an elevator can handle a request based on its direction.
- **`findBestElevator(int pickupFloor, direction dir)`**: Finds the most suitable elevator for a hall call based on proximity and direction.
- **`handleHallCall(int pickupFloor, direction dir)`**: Processes a hall call and assigns it to the best elevator.

## Requirements
- A C++20-compatible compiler
- C++ libraries: `<iostream>`, `<vector>`, `<algorithm>`, `<string>`

## Compilation and Usage
```bash
g++ -std=c++20 elevator.cpp system.cpp test.cpp -o elevator_system
```