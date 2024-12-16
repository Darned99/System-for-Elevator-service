#pragma once
#include <iostream>
#include <vector>

enum class direction {up, down, idle};

namespace bk {
    class Elevator {
        private:
            double m_CurrentFloor;
            double m_TargetFloor;
            double m_MaxFloor;
            double m_MinFloor;
            bool m_isOperational;
            direction m_CurrentDirection;

        public:
            Elevator(double currentFloor, double targetFloor,
            double maxFloor, double minFloor);

            void moveUp();
            void moveDown();
            void stop();
            void addTargetFloor(double floor);
            void removeTargetFloor(double floor);
            double getNextTarget();
            direction getDirection() const;

            ~Elevator();
    };
}