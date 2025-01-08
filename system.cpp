#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "elevator.hpp"
#include "system.hpp"


namespace bk{
        
    bk::System::System(int numElevators, int maxFloors) {
        for (int i = 0; i < numElevators; ++i) {
            elevators.emplace_back(0, maxFloors, 0); 
        }
    }

    /**
     * Getter for elevator ID
     */
    Elevator& bk::System::getElevator(int elevatorID) {
        return elevators[elevatorID];
    }

   /**
    * Just asthetic function later used in elevatorStatus method
    * 
    */
    void bk::System::LinePrint(int length, int counter) const {
        std::cout << "\n";
        for (int i = 0; i < length; i++) {
            std::cout << "=";
        }
        std::cout << " [counter: " << counter << "]" << std::endl; 
    }



    /**
     * It displays a status of elevator that contains:
     *  - current floor
     *  - direction
     *  - next target
     *  - floors in queue
     */
    void bk::System::elevatorStatus() const {
        static int counter = 0;

        bk::System::LinePrint(100, counter++);

        for (int i = 0; i < elevators.size(); ++i) {
            const Elevator& elevator = elevators[i];
            std::cout << "Elevator " << i << ":" << std::endl;

            std::string dir;
            if (elevator.getDirection() == direction::up) {
                dir = "Up";
            }
            else if (elevator.getDirection() == direction::down) {
                dir = "Down";
            }
            else {
                dir = "Idle";
            }
            
            std::cout << "\tCurrent floor: " << elevator.getCurrentFloor() 
                    << " || Direction: " << dir 
                    << " || Next Target: " << elevator.getNextTarget()
                    << " || Floors in queue: ";

            for (const int floor : elevator.getBuffer()) { 
                std::cout << floor << " ";
            }
            std::cout << "\n";
        }

        bk::System::LinePrint(100, counter++);
    }

    /**
     *  It performs next step
     * 
     */
    void bk::System::performNextStep() {
        for (auto &elevator : elevators) { 
            elevator.moveToFloor();
        }
    }

    /**
     * Checks whether the elevator can handle a given call
     * 
     */
    bool bk::System::canElevatorServeRequest(const Elevator& elevator, direction dir) {
        return ((dir == direction::up && elevator.getDirection() != direction::down) ||
                (dir == direction::down && elevator.getDirection() != direction::up) ||
                elevator.getDirection() == direction::idle);
    }

    /**
     * Finds the best elevator that can handle the call
     * 
     */
    int bk::System::findBestElevator(int pickupFloor, direction dir) {
        int bestElevator = -1;
        int minDistance = -1;

        for (int i=0; i < elevators.size(); ++i) {
            const Elevator& elevator = elevators[i];
            int distance = std::abs(elevator.getCurrentFloor() - pickupFloor);
        
            if (canElevatorServeRequest(elevator, dir)) {
                if (minDistance == -1 || distance < minDistance) {
                    minDistance = distance;
                    bestElevator = i;
                }
            }
        }
        return bestElevator;
    }

    /**
     * It handles the calls from the corridor
     * 
     */
    int bk::System::handleHallCall(int pickupFloor, direction dir) {
        int bestElevator = findBestElevator(pickupFloor, dir);
        if (bestElevator != -1) {
            elevators[bestElevator].addTargetFloor(pickupFloor);
        }
        return bestElevator;
    }

};