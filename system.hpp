#pragma once
#include <iostream>
#include "elevator.hpp"

namespace bk{
    class Lobby{
        private:
            Elevator m_elevator;
            double m_id;
            

        public:
            double m_current_floor;
            double m_next_floor;


        
        //Potential use for overloading operator
        bool operator==(const Elevator& other) const;
        bool operator!=(const Elevator& other) const;

        //bool operator==(const System& other) const;
        //bool operator!=(const System& other) const;

        // Potential methods for elevator system
        void isAbove();
        void isBellow();
    };
}