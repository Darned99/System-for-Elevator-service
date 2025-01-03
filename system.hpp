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
             * Method that handles calls from the corridor
             * 
             */
            int handleHallCall(int pickupFloor, direction dir);

            /**
             * Getter for elevator id
             */
            Elevator& getElevator(int elevatorID);

            //bool isBelow(const Elevator& elevator, int floor);
            //bool isAbove(const Elevator& elevator, int floor);

      
            //Elevator& getElevator(int index);  
            //const Elevator& getElevator(int index) const;  
    };
}

