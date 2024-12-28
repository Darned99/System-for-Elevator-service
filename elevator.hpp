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
            Elevator(int CurrentFloor = 0, int maxFloor = 0, int minFloor = 0);
            
            // Overloaded operators
            bool operator==(const Elevator& other) const;
            bool operator!=(const Elevator& other) const;
            

            // Getters
            int getCurrentFloor() const;
            int getNextTarget() const;
            direction getDirection() const;

            // Funtions responsible for movement
            void MoveUp();
            void MoveDown();
            void stop();
            void MoveToFloor();
            void addTargetFloor(int floor);   


            std::vector<int> getBuffer() const;
           
            //~Elevator();
    };
}
