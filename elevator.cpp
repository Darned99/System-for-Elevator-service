/****************************************************************************************************
 * This file is part of System for Elevator service
 * 
 ****************************************************************************************************/

#include <iostream>
#include <vector>
#include <queue> //Needed for FIFO buffer
#include "elevator.hpp"

namespace bk{

    bk::Elevator::Elevator(double CurrentFloor, double TargetFloor, double MaxFloor, double MinFloor) : 
        m_CurrentFloor(CurrentFloor), m_TargetFloor(TargetFloor),
        m_CurrentDirection(direction::idle), m_MaxFloor(MaxFloor),
        m_MinFloor(MinFloor), m_isOperational(true) {};
  

    //Elevator movement
    void bk::Elevator::moveUp(){
        if(m_isOperational){
            if(m_CurrentFloor < m_MaxFloor){
                m_CurrentDirection = direction::up;
                m_CurrentFloor++;
                std::cout << "Moving up. Current floor: " << m_CurrentFloor;
            }
            else {
                std::cout << "Cannot go higher, elevator reached the top floor: " << m_CurrentFloor;
            }
        }
    }

    void bk::Elevator::moveDown(){
        if(m_isOperational){
            if(m_CurrentFloor > m_MinFloor){
                m_CurrentDirection = direction::down;
                m_CurrentFloor--;
                std::cout << "Moving down. Current floor: " << m_CurrentFloor;
            }
            else {
                std::cout << "Cannot go lower, elevator reached the bottom floor: " << m_CurrentFloor;
            }
        }
    }

    void bk::Elevator::stop(){
        if(m_isOperational){
            m_CurrentDirection = direction::idle;
            std::cout << "Elevator stopped at floor: " << m_CurrentFloor;
        }
    }


    void bk::Elevator::moveToFloor(double destinationFloor) {
        if(m_isOperational){
            while (m_CurrentFloor != destinationFloor){
                if (m_CurrentFloor < destinationFloor) {
                    moveUp();
                }
                else if (m_CurrentFloor > destinationFloor) {
                    moveDown();
                } 
            }
        }
    }


    double bk::Elevator::getNextTarget(){
        if(!m_requests.empty()) {
            double nextFloor = m_requests.front(); 
            m_requests.pop();
            return nextFloor;
        }
        else {
            return m_CurrentFloor;
        }
    }


    //Elevator targets
    /* I'll be using targets with buffer FIFO (First in first out) 
    */
    void bk::Elevator::addTargetFloor(double floor){
        if(floor >= m_MinFloor && floor <= m_MaxFloor){
            m_requests.push(floor);
            std::cout << "Added target floor: " << floor << "\n";
        }
         else {
            std::cout << "Invalid floor request: " << floor << "\n";
         }
    }

    // This method process all queued floors and moves the elevator to each target
    void bk::Elevator::processRequests(){
        while (!m_requests.empty()) {
            double nextFloor = getNextTarget();
            moveToFloor(nextFloor);
            stop();
        }
    }

    //Curent state
    direction bk::Elevator::getDirection() const {
        return m_CurrentDirection;
    }

    bk::Elevator::~Elevator() {}
}
