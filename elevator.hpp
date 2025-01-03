#pragma once

#include <iostream>
#include <vector>

namespace bk {

    enum class direction {up, down, idle};

    class Elevator {
        protected:
            int m_CurrentFloor;
            int m_MaxFloor;
            int m_MinFloor;
            direction m_CurrentDirection;
            std::vector<int> buffer;

        public:
            /**
             * Parametric contructor
             */
            Elevator(int CurrentFloor = 0, int maxFloor = 0, int minFloor = 0);
            
            /**
             * Overloaded operators
             */
            bool operator==(const Elevator& other) const;
            bool operator!=(const Elevator& other) const;
            
            /**
             * Getters
             */
            int getCurrentFloor() const;
            direction getDirection() const;
            std::vector<int> getBuffer() const;
            int getNextTarget() const;

            /**
             * Methods responsible for movement 
             */
            void moveUp();
            void moveDown();
            void stop();
            void moveToFloor();


            /**
             * Handling request
             */
            void addTargetFloor(int floor);
    };
}
