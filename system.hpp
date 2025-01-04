#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


namespace bk {

    class System {
        protected:
            std::vector<Elevator> elevators; 
            void LinePrint(int length, int counter) const;
            Elevator m_CurrentFloor; 

        public:
            /**
             * Parametric constructor
             * 
             */
            System(int numElevators, int maxFloors);

            /**
             * Getter for elevator id
             */
            Elevator& getElevator(int elevatorID);

            /**
             * Next step
             * 
             */
            void performNextStep();

            /**
             * Displays current elevators status
             * 
             */
            void elevatorStatus() const;

            /**
             * Checks whether the elevator can handle a given call
             * 
             */
            bool canElevatorServeRequest(const Elevator& elevator, direction dir);

            /**
             * Finds the best elevator that can handle the call
             * 
             */
            int findBestElevator(int pickupFloor, direction dir);

            /**
             * It handles the calls from the corridor
             * 
             */
            int handleHallCall(int pickupFloor, direction dir);
            
    };
}

