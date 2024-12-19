#include <iostream>
#include "elevator.hpp"
#include "system.hpp"


    // System WIP
namespace bk{
    class System : Elevator{
        protected:
            int m_id;


        public:
            // Constructor wip
        
        
       bool bk::System::operator==(const bk::System& other) const {
        return (m_CurrentFloor == other.m_CurrentFloor &&
        m_MaxFloor == other.m_MaxFloor &&
        m_MinFloor == other.m_MinFloor);
    }
    
    bool bk::System::operator!=(const bk::System& other) const {
        return !(*this == other);
    }
        


    };
}