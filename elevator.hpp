/****************************************************************************************************
 * This file is part of System for Elevator service
 * 
 ****************************************************************************************************/

/**
 * @file   elevator.hpp
 * @author Bartlomiej Kisielewski
 * @date   Jan 2025
 * @brief  Project conduct basic class of elevator and bigger class of system for elevator with proper logic.
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>


namespace bk {

    /**
     * @enum direction
     * @brief Represents the direction of the elevator
     */
    enum class direction {up, down, idle};

    /**
     * 
     * 
     */
    //enum class AddTargetResult {Success, InvalidFloor, DuplicateFloor};


    /**
     * @class Elevator
     * @brief Represents an elevator
     */
    class Elevator {
        private: 
            /** Current floor of the elevator */
            int m_currentFloor;
            /** Maximum floor of the elevator can reach */
            int m_maxFloor;
            /** Minimum floor of the elevator can reach */
            int m_minFloor;
            /** Current direction of the elevator */
            direction m_currentDirection;
            /** Buffer holding target floors */
            std::vector<int> m_buffer;

            /**
             * Methods responsible for movement 
             */

            /**
             * @brief Moves the elevator up by one floor
             */
            void moveUp(); 

            /**
             * @brief Moves the elevator up by one floor
             */
            void moveDown();

            /**
             * @brief The elevator is idle
             */
            void stop();

            /**
             * Direction to string
             * @brief Convert direction enum into string
             * @param dir 
             */
            std::string directionToString(direction dir) const;

        public:
            /**
             * @brief Parametric constructor of elevator
             * @param currentFloor - initial floor of the elevator
             * @param maxFloor - maximum floor in the building that elevator can reach
             * @param minFloor - minimum floor in the building that elevator can reach
             */
            Elevator(int currentFloor = 0, int maxFloor = 0, int minFloor = 0);  
            
            /**
             * Overloaded operators
             * @brief Compares two elevator objects for equality
             * @param other - another elevator object to compare
             * @return true if both objects are equal, if not it returns false
             */
            bool operator==(const Elevator& other) const;

            /**
             * @brief Compares two elevator objects for inequality
             * @param other - another elevator object to compare
             * @return true if objects are not equal, if not i returns true
             */
            bool operator!=(const Elevator& other) const;
            

            /**
             * Getters
             */

            /**
             * @brief Gets the current floor of the elevator
             * @return Current floor
             */
            int getCurrentFloor() const;

            /**
             * @brief Gets the current direction of the elevator
             * @return Current direction as an enum value
             */
            direction getDirection() const;

            /**
             * @brief Gets the buffer of target floors
             * @return A vector containing target floors
             */
            std::vector<int> getBuffer() const;

            /**
             * @brief Gets the next target floor from the buffer
             * @return Next target floor
             */
            int getNextTarget() const;

            /**
             * Displays current elevators status
             * @brief Displays the current status of all elevators
             * @param id Displays id of each elevator
             * The status includes:
             * - Current floor 
             * - Current direction
             * - Next target floor
             * - Floors in the request buffer
             */
            void displayStatus(int id) const;

            /**
             * @brief Moves the elevator to the next target floor
             */
            void moveToFloor();

            /**
             * Handling request
             * @brief Adds a target floor to the buffer
             * @param floor Added floor to the buffer
             */
            void addTargetFloor(int floor); //kod błędu powinien zwracac 

            /**
             * Checks whether the elevator can handle a given call
             * @brief Determines if an elevator can handle a given request
             * @param elevator The elevator to check
             * @param dir Direction of the request
             * @return true if the elevator can handle the request, if not it returns false
             */
            bool canElevatorServeRequest(direction dir) const;  

    };
}
