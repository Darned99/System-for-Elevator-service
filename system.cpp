#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "elevator.hpp"
#include "system.hpp"


namespace bk{
        
    bk::System::System(int numElevators, int maxFloors) {
        for (int i = 0; i < numElevators; ++i) {
            elevators.emplace_back(0, maxFloors, 0); 
        }
    }

    /*
    static bool should_move_down(const Elevator& elevator) {
        return (elevator.getCurrentFloor() > elevator.getBuffer().front());
    }

    bool bk::System::isBelow(const Elevator& elevator, int floor) {
        return (elevator.getCurrentFloor() <= floor);
    }

    bool bk::System::isAbove(const Elevator& elevator, int floor) {
        return (elevator.getCurrentFloor() >= floor);
    }

    static bool goes_to_the_top(const Elevator& elevator) {
        return (elevator.getBuffer().front() == NUM_FLOORS -1);
    }

    static bool goes_to_the_bottom(const Elevator& elevator) {
        return (elevator.getBuffer().front() == 0);
    }

    static bool goes_above(const Elevator& elevator, int floor) {
        return (elevator.getBuffer().front() >= floor);
    }

    static bool goes_below(const Elevator& elevator, int floor) {
        return (elevator.getBuffer().front() <= floor);
    }

    static bool elevator_has_empty_buffer(const Elevator& elevator) {
        return elevator.getBuffer().empty();
    }

    static bool has_floor_in_buffer(const Elevator& elevator, int floor) {
        const auto& buffer = elevator.getBuffer();
        return std::find(buffer.begin(), buffer.end(), floor) != buffer.end();
    }
    */

   /**
    * Just asthetic function later used in elevatorStatus method
    * 
    */
    void bk::System::LinePrint(int length, int counter) const {
        std::cout << "\n";
        for (int i = 0; i < length; i++) {
            std::cout << "=";
        }
        std::cout << " [counter: " << counter << "]" << std::endl; 
    }



    /**
     * It displays a status of elevator that contains:
     *  - direction
     *  - next target
     *  - floors in queue
     */
    void bk::System::elevatorStatus() const {
        static int counter = 0;

        bk::System::LinePrint(100, counter++);

        for (int i = 0; i < elevators.size(); ++i) {
            const Elevator& elevator = elevators[i];
            std::cout << "Elevator " << i << ":" << std::endl;

            std::string dir;
            if (elevator.getDirection() == direction::up) {
                dir = "Up";
            }
            else if (elevator.getDirection() == direction::down) {
                dir = "Down";
            }
            else {
                dir = "Idle";
            }

            std::cout << "\tCurrent floor: " << elevator.getCurrentFloor() 
                    << " || Direction: " << dir 
                    << " || Next Target: " << elevator.getNextTarget()
                    << " || Floors in queue: ";

            for (const int floor : elevator.getBuffer()) { 
                std::cout << floor << " ";
            }
            std::cout << "\n";
        }

        bk::System::LinePrint(100, counter++);
    }

    /**
     *  It performs next step
     * 
     */
    void bk::System::performNextStep() {
        for (auto &elevator : elevators) { 
            elevator.moveToFloor();
        }
    }

    /**
     * Getter for elevator ID
     */
    Elevator& bk::System::getElevator(int elevatorID) {
        return elevators[elevatorID];
    }


    // Przepatrzeć te funkcje 
    /**
     * It handles calls from the corridor
     * 
     */
    int bk::System::handleHallCall(int pickupFloor, direction dir) {
        int bestElevator = -1;
        int minDistance = -1; 

        for (int i = 0; i < elevators.size(); ++i) { 
            const Elevator& elevator = elevators[i];
            int distance = std::abs(elevator.getCurrentFloor() - pickupFloor);

            if ((dir == direction::up && elevator.getDirection() != direction::down) ||
                (dir == direction::down && elevator.getDirection() != direction::up) ||
                elevator.getDirection() == direction::idle) {

            
                if (minDistance == -1 || distance < minDistance) {
                    minDistance = distance;
                    bestElevator = i; 
                }
            }
        }

        if (bestElevator != -1) {
            elevators[bestElevator].addTargetFloor(pickupFloor);
        }

        return bestElevator;
    }
    
        /*
        int bk::System::corridor_buttom_push(Elevator& elevator, int pickup_floor, direction dir){

            switch (dir) {
                case direction::up:
                    for (int i = 0; i < elevators.size(); i++) {
                        if ((isBelow(elevators[i], pickup_floor) && goes_to_the_top(elevators[i])) ||
                            (isBelow(elevators[i], pickup_floor) &&
                            goes_above(elevators[i], pickup_floor) && elevator_has_empty_buffer(elevators[i]))) {
                            if (has_floor_in_buffer(elevators[i], pickup_floor)) {
                                return i;
                            }
                        }
                    }
                break;

                case direction::down:
                    for (int i = 0; i < elevators.size(); i++) {
                        if ((isAbove(elevators[i], pickup_floor) && goes_to_the_bottom(elevators[i])) ||
                            (isAbove(elevators[i], pickup_floor) &&
                            goes_below(elevators[i], pickup_floor) && elevator_has_empty_buffer(elevators[i]))) {
                            if (has_floor_in_buffer(elevators[i], pickup_floor)) {
                                return i;
                            }
                        }
                    }
                    break;
            }
            return -1;
        }

        */

        /*
        Elevator& bk::System::getElevator(int index) {
            return elevators[index];
        }

        const Elevator& bk::System::getElevator(int index) const {
            return elevators[index];
        }
        
        */
};