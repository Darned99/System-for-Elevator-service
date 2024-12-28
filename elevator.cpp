/****************************************************************************************************
 * This file is part of System for Elevator service
 * 
 ****************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include "elevator.hpp"


namespace bk{
    
    bk::Elevator::Elevator(int CurrentFloor,int MaxFloor, int MinFloor) : 
        m_CurrentFloor(CurrentFloor),
        m_CurrentDirection(direction::idle),
        m_MaxFloor(MaxFloor),
        m_MinFloor(MinFloor) {
        
        std::cout << "Constructor: " 
            << "Current floor: " << CurrentFloor 
            << " Max Floor: " << MaxFloor 
            << " Min Floor: " << MinFloor << std::endl;
    };
    
    
    // Overloaded operators
    bool bk::Elevator::operator==(const bk::Elevator& other) const {
        return (m_CurrentFloor == other.m_CurrentFloor &&
        m_MaxFloor == other.m_MaxFloor &&
        m_MinFloor == other.m_MinFloor);
    }
    
    bool bk::Elevator::operator!=(const bk::Elevator& other) const {
        return !(*this == other);
    }
    

    // Getters to possible implementation for data validation
    
    int bk::Elevator::getCurrentFloor() const {
        return m_CurrentFloor;
    }

    direction bk::Elevator::getDirection() const {
        return m_CurrentDirection;
    }

    std::vector<int> bk::Elevator::getBuffer() const {
        return buffer;
    }
   
    int bk::Elevator::getNextTarget() const {
        if (buffer.empty()) {
            return m_CurrentFloor;
        }
        else {
            return buffer.front();
        }
    }

    
    void bk::Elevator::MoveUp() {
        m_CurrentFloor++;
        std::cout << "Moving up to floor: " << m_CurrentFloor << std::endl;

        auto it = std::find(buffer.begin(), buffer.end(), m_CurrentFloor);
        if (it != buffer.end()) {
            buffer.erase(it);
            std::cout << "Stopping at floor: " << m_CurrentFloor << std::endl;
        }

        if (!buffer.empty() && buffer.front() > m_CurrentFloor) {
            m_CurrentDirection = direction::up;
        }
    }

    void bk::Elevator::MoveDown() {
        m_CurrentFloor--;
        std::cout << "Moving down to floor: " << m_CurrentFloor << std::endl;

        auto it = std::find(buffer.begin(), buffer.end(), m_CurrentFloor);
        if (it != buffer.end()) {
            buffer.erase(it);
            std::cout << "Stopping at floor: " << m_CurrentFloor << std::endl;
        }

        if (!buffer.empty() && buffer.front() < m_CurrentFloor) {
            m_CurrentDirection = direction::down;
        }
    }


    void bk::Elevator::stop(){
            m_CurrentDirection = direction::idle;
            std::cout << "Elevator stopped at floor: " << m_CurrentFloor << std::endl;
    }


    void bk::Elevator::MoveToFloor() {
        if (buffer.empty()) {
            std::cout << "No requests in buffer, elevator idle." << std::endl;
            m_CurrentDirection = direction::idle;
            return;
        }

        if (m_CurrentFloor == buffer.front()) {
            std::cout << "Stopping at floor: " << m_CurrentFloor << std::endl;
            buffer.erase(buffer.begin());
        }

        if (!buffer.empty()) {
            if (buffer.front() > m_CurrentFloor) {
                m_CurrentDirection = direction::up;
                MoveUp();
            }
            else if (buffer.front() < m_CurrentFloor) {
                m_CurrentDirection = direction::down;
                MoveDown();
            }
            else {
                stop();
            }
        }
    }


    void bk::Elevator::addTargetFloor(int floor) {
        if (floor < m_MinFloor || floor > m_MaxFloor) {
            
            std::cout << "Invalid floor request: " << floor << std::endl;
            return;
        }

        if (std::find(buffer.begin(), buffer.end(), floor) == buffer.end()) {
            
            buffer.push_back(floor);
            std::cout << "Added target floor: " << floor << std::endl;

            if (m_CurrentDirection == direction::up) {
                std::sort(buffer.begin(), buffer.end());
            } 
            else if (m_CurrentDirection == direction::down) {
                std::sort(buffer.rbegin(), buffer.rend());
            }
        }
    }

};

