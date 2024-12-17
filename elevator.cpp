/****************************************************************************************************
 * This file is part of System for Elevator service
 * 
 ****************************************************************************************************/

/*
Do zrealizowania: 
- maksymalnie trzy poziomy dziedziczenia
- przestrzeń swoja tj. bk::
- konstruktory
- przeciążenie operatorów (ale też bez sensu nie przeciążać)
- template (chociaż dla windy raczej bez sensu)
- repo github
*/

/*
Do przekminy:
    aktualne piętro
    liczba pięter
    liczba wind
    kierunek (góra, dół)
    stan windy (czy porusza się, czy jest w miejscu)
    logika jazdy i doboru windy
*/

#include <iostream>
#include <vector>
#include <elevator.hpp>

namespace bk{

    bk::Elevator::Elevator(double CurrentFloor, double TargetFloor, double MaxFloor, double MinFloor) : 
        m_CurrentFloor(CurrentFloor), m_TargetFloor(TargetFloor),
        m_CurrentDirection(direction::idle), m_MaxFloor(MaxFloor),
        m_MinFloor(MinFloor), m_isOperational(true) {};


    //Sprawdzamy stan czy działa, na tej podstawie dodajemy (dlaczego tu nie ma destinated floor)

    // Vector buffer

        

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

    //Elevator targets
    void bk::Elevator::addTargetFloor(double floor){
        if(floor >= m_MinFloor && floor <= m_MaxFloor){
            m_requests.push(floor);
            std::cout << "Added target floor: " << floor << "\n";
        }
         else{
            std::cout << "Invalid floor request: " << floor << "\n";
         }

    }

    void bk::Elevator::removeTargetFloor(double floor){

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

    //Curent state
    direction bk::Elevator::getDirection() const {
        return m_CurrentDirection;
    }

    bk::Elevator::~Elevator();
}
