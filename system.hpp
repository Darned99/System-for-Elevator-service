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
        private:
            /** A vector of elevators to be managed by the system */
            std::vector<Elevator> m_elevators; 
            

            /**
             * @brief Prints a asthetic line with a counter
             * @param length Length of the line
             * @param counter Counter value to display
             */
            void LinePrint(int length, int counter) const; 

            

            /**
             * Finds the best elevator that can handle the call
             * @brief Finds the best elevator to handle a given call
             * @param pickupFloor The floor where the call is from
             * @param dir The direction of the requested elevator movement
             * @return ID of the best elevator, or -1 if no suitable elevator is found
             */
            int findBestElevator(int pickupFloor, direction dir); // też może być prywatne tu może być że winda nie przyjmie użytkownika calla nie dostanie czegos do bufora


        public:
            /**
             * Parametric constructor
             * @brief Parametric constructor that conctructs a system
             * @param numElevators Number of elevator in the system
             * @param maxFloors Maximum number of floors the elevators can service
             */
            System(int numElevators, int maxFloors);  // walidacje dodać

            /**
             * Getter for elevator id
             * @brief It retreives an elevator object by its ID
             * @param elevatorID ID of the elevator to retreive
             * @return Reference to the requested elevator object
             */
            Elevator& getElevator(int elevatorID);


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
            void elevatorStatus() const;  //direction to string  też może być w elevator 

            /**
             * Next step
             * @brief Performs the next step for all elevators in the system
             */
            void performNextStep();

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

