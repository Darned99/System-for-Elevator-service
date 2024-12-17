#pragma once
#include <iostream>
#include <vector>
#include <queue>

// Could be simpler, however class give us better encapsulation
enum class direction {up, down, idle}; //idle non operating in that moment

namespace bk {
    class Elevator {
        private:
            int m_CurrentFloor;
            int m_TargetFloor;
            int m_MaxFloor;
            int m_MinFloor;
            bool m_isOperational;
            direction m_CurrentDirection;
            std::queue<int> m_requests;

        public:
            Elevator(int currentFloor, int targetFloor,
            int maxFloor, int minFloor);


            void moveUp();
            void moveDown();
            void stop();
            void moveToFloor(int destinationFloor);

            void addTargetFloor(int floor);            
            int getNextTarget();
            void processRequests();

            direction getDirection() const;

            ~Elevator();
    };
}