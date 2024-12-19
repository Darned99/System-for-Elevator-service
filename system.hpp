#pragma once
#include <iostream>
#include "elevator.hpp"

namespace bk{
    class System{
        private:
            
            double m_id;
            

        public:
           


        
        //Potential use for overloading operator
        bool operator==(const Elevator& other) const;
        bool operator!=(const Elevator& other) const;

        bool operator==(const System& other) const;
        bool operator!=(const System& other) const;

        // Potential methods for elevator system
        void isAbove();
        void isBelow();
    };
}