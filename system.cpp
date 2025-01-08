/****************************************************************************************************
 * This file is part of System for Elevator service
 * 
 ****************************************************************************************************/

/**
 * @file   system.cpp
 * @author Bartlomiej Kisielewski
 * @date   Jan 2025
 * @brief  Project conduct basic class of elevator and bigger class of system for elevator with proper logic.
 */

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
            elevators[i].displayStatus(i);
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
     * Finds the best elevator that can handle the call
     * 
     */
    int bk::System::findBestElevator(int pickupFloor, direction dir) {
        int bestElevator = -1;
        int minDistance = -1;

        for (int i=0; i < elevators.size(); ++i) {
            const Elevator& elevator = elevators[i];
            int distance = std::abs(elevator.getCurrentFloor() - pickupFloor);
        
            if (elevator.canElevatorServeRequest(dir)) {
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