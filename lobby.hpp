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
        bool operator==(const Elevator& other) const {
            return (Elevator == other.Elevator);
        }

        bool operator!=(const Elevator& other) const {
            return !(*this == other);
        }

    }
}