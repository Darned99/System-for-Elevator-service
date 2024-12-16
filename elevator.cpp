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
    class Elevator{
    private:
        double m_CurrentFloor;
        double m_TargetFloor;
        double m_MaxFloor;
        double m_MinFloor;
        bool m_isOperational;
        direction m_CurrentDirection;


    public:
    Elevator(double CurrentFloor, double TargetFloor, double MaxFloor, double MinFloor) : 
        m_CurrentFloor(CurrentFloor), m_TargetFloor(TargetFloor),
        currentDirection(direction::idle), m_MaxFloor(MaxFloor),
        m_MinFloor(MinFloor), m_isOperational(true) {};


    //Sprawdzamy stan czy działa, na tej podstawie dodajemy (dlaczego tu nie ma destinated floor)

    // Vector buffer

        

    //Elevator movement
    void Elevator::moveUp(){
        if(isOperational){
            if(m_CurrentFloor < m_MaxFloor){
                currentDirection = direction::up;
                m_CurrentFloor++;
                std::cout << "Moving up. Current floor: " << m_CurrentFloor;
            }
            else {
                std::cout << "Cannot go higher, elevator reached the top floor: " << m_CurrentFloor;
            }
        }
    }

    void Elevator::moveDown(){
        if(isOperational){
            if(m_CurrentFloor > m_MinFloor){
                currentDirection = direction::down;
                m_CurrentFloor--;
                std::cout << "Moving down. Current floor: " << m_CurrentFloor;
            }
            else {
                std::cout << "Cannot go lower, elevator reached the bottom floor: " << m_CurrentFloor;
            }
        }
    }

    void Elevator::stop(){
        if(isOperational){
            currentDirection = direction::idle;
            std::cout << "Elevator stopped at floor: " << m_CurrentFloor;
        }
    }

    //Elevator targets
    void Elevator::addTargetFloor(double floor){

    }

    void Elevator::removeTargetFloor(double floor){

    }

    double Elevator::getNextTarget(){

    }

    //Curent state
    direction Elevator::getDirection() const;


    Elevator::~Elevator();
}
}