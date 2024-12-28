#include <iostream>
#include "elevator.hpp"
#include "system.hpp"

int main() {
    int numElevators = 3; 
    int maxFloors = 20;

    // Konfiguracja symulacji
    //std::cout << "Set up program:\n";
    //std::cout << "Enter the number of floors in the building: ";
    //std::cin >> maxFloors;

    bk::System elevatorSystem(numElevators, maxFloors);

    std::cout << "\nSimulation started with " << numElevators << " elevators.\n";

    while (true) {
       
        std::cout << "\nChoose an option:\n";
        std::cout << "1. Call elevator\n";
        std::cout << "2. Perform next step (movement)\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            int floor;
            int dirChoice;

            std::cout << "Enter the floor to call from (0-" << maxFloors - 1 << "): ";
            std::cin >> floor;
            if (floor < 0 || floor >= maxFloors) {
                std::cout << "Invalid floor. Please try again.\n";
                continue;
            }

            std::cout << "Enter the direction (1 for up, 2 for down): ";
            std::cin >> dirChoice;
            if (dirChoice != 1 && dirChoice != 2) {
                std::cout << "Invalid direction. Please try again.\n";
                continue;
            }

            bk::direction dir = (dirChoice == 1) ? bk::direction::up : bk::direction::down;

            int bestElevator = elevatorSystem.corridor_buttom_push(floor, dir);
            if (bestElevator != -1) {
                std::cout << "Call assigned to elevator " << bestElevator << ".\n";
            } else {
                std::cout << "No elevator available for the call.\n";
            }
        } 
        
        else if (choice == 2) {
            elevatorSystem.elevatorStatus();
            elevatorSystem.performNextStep();
        } 
        else if (choice == 3) {
            std::cout << "Exiting simulation.\n";
            break;
        } 
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
