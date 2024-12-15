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
- 
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

#pragma once
#include <iostream>
#include <vector>

// Coule be simpler, however class give us better encapsulation
enum class direction {up, down, idle}; //idle non operating in that moment

namespace bk{
    class Elevator{
        private:
            // State of elevator 
            double m_CurrentFloor; 
            double m_TargetFloor;
            bool isOperational;
            std::vector<double> m_TargetFloors; //Queue vector for elevator floors to handle
            direction currentDirection;


        public: 
            Elevator(double CurrentFloor, double TargetFloor) : 
            m_CurrentFloor(CurrentFloor), m_TargetFloor(TargetFloor),
            currentDirection(direction::idle), isOperational(true) {};


        //Sprawdzamy stan czy działa, na tej podstawie dodajemy (dlaczego tu nie ma destinated floor)


        //Elevator movement
        void moveUp(){
            if(isOperational){
                currentDirection = direction::up;
                m_CurrentFloor++;
                std::cout << "Moving up. Current floor: " << m_CurrentFloor;
            }
        }

        void moveDown(){
            if(isOperational){
                currentDirection = direction::down;
                m_CurrentFloor--;
                std::cout << "Moving down. Current floor: " << m_CurrentFloor;
            }
        }

        void stop(){
            if(isOperational){
                currentDirection = direction::idle;
                std::cout << "Elevator stopped at floor: " << m_CurrentFloor;

            }
        }

        //Elevator targets
        void addTargetFloor(double floor){

        }

        void removeTargetFloor(double floor){

        }

        double getNextTarget(){

        }

        //Curent state
        direction getDirection() const;


~Elevator();
}
}