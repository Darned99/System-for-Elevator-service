/****************************************************************************************************
 * This file is part of System for Elevator service
 * 
 ****************************************************************************************************/

/**
 * @file   system.hpp
 * @author Bartlomiej Kisielewski
 * @date   Jan 2025
 * @brief  Project conduct basic class of elevator and bigger class of system for elevator with proper logic.
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


namespace bk {

    /**
     * @class System
     * @brief Manages a group of elevators and coordinates their movement
     */
    class System {
        protected:
            /** A vector of elevators to be managed by the system */
            std::vector<Elevator> elevators; 
            //Elevator m_CurrentFloor; 

        public:
            /**
             * Parametric constructor
             * @brief Parametric constructor that conctructs a system
             * @param numElevators Number of elevator in the system
             * @param maxFloors Maximum number of floors the elevators can service
             */
            System(int numElevators, int maxFloors);

            /**
             * Getter for elevator id
             * @brief It retreives an elevator object by its ID
             * @param elevatorID ID of the elevator to retreive
             * @return Reference to the requested elevator object
             */
            Elevator& getElevator(int elevatorID);

            /**
             * @brief Prints a asthetic line with a counter
             * @param length Length of the line
             * @param counter Counter value to display
             */
            void LinePrint(int length, int counter) const;

            /**
             * Displays current elevators status
             * @brief Displays the current status of all elevators
             * 
             * The status includes:
             * - Current floor 
             * - Current direction
             * - Next target floor
             * - Floors in the request buffer
             */
            void elevatorStatus() const;

            /**
             * Next step
             * @brief Performs the next step for all elevators in the system
             */
            void performNextStep();

            /**
             * Checks whether the elevator can handle a given call
             * @brief Determines if an elevator can handle a given request
             * @param elevator The elevator to check
             * @param dir Direction of the request
             * @return true if the elevator can handle the request, if not it returns false
             */
            bool canElevatorServeRequest(const Elevator& elevator, direction dir);

            /**
             * Finds the best elevator that can handle the call
             * @brief Finds the best elevator to handle a given call
             * @param pickupFloor The floor where the call is from
             * @param dir The direction of the requested elevator movement
             * @return ID of the best elevator, or -1 if no suitable elevator is found
             */
            int findBestElevator(int pickupFloor, direction dir);

            /**
             * It handles the calls from the corridor
             * @brief Handles a hall call by assigning it to the best elevator
             * @param pickupFloor The floor where the call is from
             * @param dir The direction of the requested elevator movement
             * @return ID of the assigned elevator, or -1 if no suitable elevator is found
             */
            int handleHallCall(int pickupFloor, direction dir);
            
    };
}

