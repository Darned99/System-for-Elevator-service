#include <iostream>
#include "elevator.hpp"
#include "system.hpp"

int main() {

    int numElevators;
    int maxFloors;

    std::cout << "\nSet up program: " << std::endl;
    
    std::cout << "\nEnter the number of floors in the building: ";
    std::cin >> maxFloors;
    maxFloors += 1;
    
    std::cout << "\nEnter the number of elevators in the building: ";
    std::cin >> numElevators;

    bk::System elevatorSystem(numElevators, maxFloors);

    std::cout << "\nSimulation started with " << numElevators << " elevators." << std::endl;
    elevatorSystem.elevatorStatus();

    while (true) {
       
        std::cout << "\nChoose an option:" << std::endl;
        std::cout << "1. Call elevator" << std::endl;
        std::cout << "2. Pick floor in the elevator" << std::endl;
        std::cout << "3. Perform next step (movement)" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            int floor;
            int dirChoice;

            std::cout << "Enter the floor to call from (0-" << maxFloors - 1 << "): ";
            std::cin >> floor;

            if (floor < 0 || floor >= maxFloors) {
                std::cout << "Invalid floor. Please try again." << std::endl;
                continue;
            }

            std::cout << "Enter the direction (1 for up, 2 for down): ";
            std::cin >> dirChoice;

            if (dirChoice != 1 && dirChoice != 2) {
                std::cout << "Invalid direction. Please try again." << std::endl;
                continue;
            }

            bk::direction dir;
            if (dirChoice == 1) {
                dir = bk::direction::up;
            }
            else {
                dir = bk::direction::down;
            }

            int bestElevator = elevatorSystem.handleHallCall(floor, dir);
            
            if (bestElevator != -1) {
                std::cout << "Call assigned to elevator " << bestElevator << "." << std::endl;
            } else {
                std::cout << "No elevator available for the call." << std::endl;
            }

            elevatorSystem.elevatorStatus();
        }

        else if (choice == 2) {
            int elevatorID;
            int targetFloor;

            std::cout << "Pick elevator ID (0-" << numElevators - 1 << "): ";
            std::cin >> elevatorID;

            if (elevatorID < 0 || elevatorID >= numElevators) {
                std::cout << "Invalid elevator ID. Please try again." << std::endl;
                continue;
            }

            std::cout << "Pick target floor (0-" << maxFloors - 1 << "): ";
            std::cin >> targetFloor;

            if (targetFloor < 0 || targetFloor >= maxFloors) {
                std::cout << "Invalid floor. Please try again" << std::endl;
                continue;
            }

            elevatorSystem.getElevator(elevatorID).addTargetFloor(targetFloor);
            std::cout << "Floor " << targetFloor << " added to queue for elevator " << elevatorID << std::endl;

            elevatorSystem.elevatorStatus();
        }
        
        else if (choice == 3) {
            elevatorSystem.performNextStep();
            elevatorSystem.elevatorStatus();
        } 
        else if (choice == 4) {
            std::cout << "Exiting simulation." << std::endl;
            break;
        } 
        else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
