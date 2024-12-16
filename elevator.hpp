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

#pragma once
#include <iostream>
#include <vector>

/*
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
*/

//#define number_of_floors(30)
//#define QueueVector(number_of_floors)

// Could be simpler, however class give us better encapsulation
enum class direction {up, down, idle}; //idle non operating in that moment

namespace bk{
    class Elevator{
        private:
            // State of elevator 
            double m_CurrentFloor; 
            double m_TargetFloor;
            double m_MaxFloor;
            double m_MinFloor;
            bool isOperational;
            //std::vector<double> m_TargetFloors; //Queue vector for elevator floors to handle
            direction currentDirection;


        public: 
            std::vector<double> number_of_floors; //Queue vector for elevator floors to handle
            
            Elevator(double CurrentFloor, double TargetFloor, double MaxFloor, double MinFloor) : 
            m_CurrentFloor(CurrentFloor), m_TargetFloor(TargetFloor),
            currentDirection(direction::idle), m_MaxFloor(MaxFloor),
            m_MinFloor(MinFloor), m_isOperational(true) {};


        //Sprawdzamy stan czy działa, na tej podstawie dodajemy (dlaczego tu nie ma destinated floor)

        // Vector buffer

        

        //Elevator movement
        void moveUp(){
            if(isOperational){
                if(m_CurrentFloor < m_MaxFloor){
                    currentDirection = direction::up;
                    m_CurrentFloor++;
                    std::cout << "Moving up. Current floor: " << m_CurrentFloor;
                }
                else {
                    std::cout << "Cannot go higher, we reached the top floor: " << m_CurrentFloor;
                }
            }
        }

        void moveDown(){
            if(isOperational){
                if(m_CurrentFloor > m_MinFloor){
                    currentDirection = direction::down;
                    m_CurrentFloor--;
                    std::cout << "Moving down. Current floor: " << m_CurrentFloor;
                }
                else {
                    std::cout << "Cannot go lower, we reached the bottom floor: " << m_CurrentFloor;
                }
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