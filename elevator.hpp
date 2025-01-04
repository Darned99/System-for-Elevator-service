#pragma once

#include <iostream>
#include <vector>



namespace bk {

    /**
     * @enum direction
     * @brief Represents the direction of the elevator
     */
    enum class direction {up, down, idle};

    /**
     * @class Elevator
     * @brief Represents an elevator
     */
    class Elevator {
        protected:
            /**< Current floor of the elevator */
            int m_CurrentFloor;
            /**< Maximum floor of the elevator can reach */
            int m_MaxFloor;
            /**< Minimum floor of the elevator can reach */
            int m_MinFloor;
            /**< Current direction of the elevator */
            direction m_CurrentDirection;
            /**< Buffer holding target floors */
            std::vector<int> buffer;

        public:
            /**
             * @brief Parametric constructor of elevator
             * @param CurrentFloor - initial floor of the elevator
             * @param MaxFloor - maximum floor in the building that elevator can reach
             * @param MinFloor - minimum floor in the building that elevator can reach
             */
            Elevator(int CurrentFloor = 0, int MaxFloor = 0, int MinFloor = 0);
            
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
             * @brief Moves the elevator to the next target floor
             */
            void moveToFloor();


            /**
             * Handling request
             * @brief Adds a target floor to the buffer
             * @param floor Added floor to the buffer
             */
            void addTargetFloor(int floor);
    };
}
