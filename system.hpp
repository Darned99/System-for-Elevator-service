#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>


namespace bk {

    class System {
        protected:
            std::vector<Elevator> elevators; 
            void LinePrint(int length, int counter) const;
            Elevator m_CurrentFloor; 

        public:
            System(int numElevators, int maxFloors);

            void performNextStep();
            void elevatorStatus() const;
            //void addElevator(const Elevator& elevator);

            //int handleHallCall(int pickupFloor, direction dir);
            int corridor_buttom_push(int pickupFloor, direction dir);
        
            //bool isBelow(const Elevator& elevator, int floor);
            //bool isAbove(const Elevator& elevator, int floor);

      
            //Elevator& getElevator(int index);  
            //const Elevator& getElevator(int index) const;  
    };
}

