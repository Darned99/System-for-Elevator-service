/****************************************************************************************************
 * This file is part of System for Elevator service
 * 
 ****************************************************************************************************/

/**
 * @file   elevator.cpp
 * @author Bartlomiej Kisielewski
 * @date   Jan 2025
 * @brief  Project conduct basic class of elevator and bigger class of system for elevator with proper logic.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "elevator.hpp"


namespace bk{
    
    bk::Elevator::Elevator(int currentFloor,int maxFloor, int minFloor) : 
        m_currentFloor(currentFloor),
        m_currentDirection(direction::idle),
        m_maxFloor(maxFloor),
        m_minFloor(minFloor) {
        
    };
    

    /**
     * Overloaded operators
     * 
     */
    bool bk::Elevator::operator==(const bk::Elevator& other) const {
        return (m_currentFloor == other.m_currentFloor &&
        m_maxFloor == other.m_maxFloor &&
        m_minFloor == other.m_minFloor);
    }
    
    bool bk::Elevator::operator!=(const bk::Elevator& other) const {
        return !(*this == other);
    }
    
    /**
     * Getters
     * 
     */
    int bk::Elevator::getCurrentFloor() const {
        return m_currentFloor;
    }

    direction bk::Elevator::getDirection() const {
        return m_currentDirection;
    }

    std::vector<int> bk::Elevator::getBuffer() const {
        return m_buffer;
    }
   
    int bk::Elevator::getNextTarget() const {
        if (m_buffer.empty()) {
            return m_currentFloor;
        }
        else {
            return m_buffer.front();
        }
    }


    /**
     * Convert enum into string
     * 
     */
    std::string bk::Elevator::directionToString(direction dir) const {
        switch (dir) {
            case direction::up:
                return "Up";
            case direction::down:
                return "Down";
            case direction::idle:
                return "Idle";
            default:
                return "Unknown";
        }
    }

    /**
     * Displaying status of elevator
     */
    void bk::Elevator::displayStatus(int id) const {
        
        std::cout << "Elevator " << id << ":" << std::endl;
        std::cout << "\tCurrent floor: " << getCurrentFloor() 
                    << " || Direction: " << directionToString(getDirection())
                    << " || Next Target: " << getNextTarget()
                    << " || Floors in queue: ";

        for (const int floor : getBuffer()) { 
                std::cout << floor << " ";
        }

        std::cout << "\n";

    }

    /**
     * Methods for movement
     * 
     * 
     */
    void bk::Elevator::moveUp() {
        m_currentFloor++;
        std::cout << "Moving up to floor: " << m_currentFloor << std::endl;

        auto it = std::find(m_buffer.begin(), m_buffer.end(), m_currentFloor);
        if (it != m_buffer.end()) {
            m_buffer.erase(it);
            std::cout << "Stopping at floor: " << m_currentFloor << std::endl;
        }
    }

    void bk::Elevator::moveDown() {
        m_currentFloor--;
        std::cout << "Moving down to floor: " << m_currentFloor << std::endl;

        auto it = std::find(m_buffer.begin(), m_buffer.end(), m_currentFloor);
        if (it != m_buffer.end()) {
            m_buffer.erase(it);
            std::cout << "Stopping at floor: " << m_currentFloor << std::endl;
        }
    }

    void bk::Elevator::stop(){
            m_currentDirection = direction::idle;
            std::cout << "Elevator stopped at floor: " << m_currentFloor << std::endl;
    }


    void bk::Elevator::moveToFloor() {
        if (m_buffer.empty()) {
            std::cout << "No requests in buffer, elevator idle." << std::endl;
            m_currentDirection = direction::idle;
            return;
        }

        if (m_currentFloor == m_buffer.front()) {
            std::cout << "Stopping at floor: " << m_currentFloor << std::endl;
            m_buffer.erase(m_buffer.begin());
        }

        if (!m_buffer.empty()) {
            if (m_buffer.front() > m_currentFloor) {
                m_currentDirection = direction::up;
                moveUp();
            }
            else if (m_buffer.front() < m_currentFloor) {
                m_currentDirection = direction::down;
                moveDown();
            }
            else {
                stop();
            }
        }
    }
    
    /**
     * Handling requests
     * 
     */
    void bk::Elevator::addTargetFloor(int floor) {
        if (floor < m_minFloor || floor > m_maxFloor) {
            
            std::cout << "Invalid floor request: " << floor << std::endl;
            return;
        }

        if (std::find(m_buffer.begin(), m_buffer.end(), floor) == m_buffer.end()) {
            
            m_buffer.push_back(floor);
            std::cout << "Added target floor: " << floor << std::endl;

            if (m_currentDirection == direction::up || m_currentDirection == direction::idle) {
                std::sort(m_buffer.begin(), m_buffer.end());
            } 
            else if (m_currentDirection == direction::down) {
                std::sort(m_buffer.rbegin(), m_buffer.rend());
            }
        }
    }

    /**
     * Checks whether the elevator can handle a given call
     * 
     */
    bool bk::Elevator::canElevatorServeRequest(direction dir) const {
        return ((dir == direction::up && getDirection() != direction::down) ||
                (dir == direction::down && getDirection() != direction::up) ||
                getDirection() == direction::idle);
    }
    
};

