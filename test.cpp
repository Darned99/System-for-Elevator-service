#include <iostream>
#include "elevator.hpp"
//#include "system.hpp"


int main(){
    
    /*double number_of_elevators;
    double number_of_floors;

    std::cout << "Set up program. How many elevator would you like" << std::endl;
    std::cin >> number_of_elevators;

    std::cout << "How many floors are in the building?" << std::endl;
    std::cin >> number_of_floors;



    std::cout << ""
    */

    int CurrentFloor;
    int MaxFloor;
    int MinFloor;
    
    int TargetFloor;

    std::cout << "Set up program. Which floor we're starting at: ";
    std::cin >> CurrentFloor;
    std::cout << " What's the top floor the building has: ";
    std::cin >> MaxFloor;
    std::cout << " What's the bottom floor the building has: ";
    std::cin >> MinFloor;

    bk::Elevator elevator(CurrentFloor, MaxFloor, MinFloor);

    std::cout << "Proceed to enter destination: ";
    std::cin >> TargetFloor;
    elevator.addTargetFloor(TargetFloor);       //Example 7
    elevator.getQueueSize();
    //elevator.processRequests();
    
    std::cout << "Proceed to enter destination: ";
    std::cin >> TargetFloor;
    elevator.addTargetFloor(TargetFloor);       //Example -3
    elevator.getQueueSize();
    //elevator.processRequests();
    
    
    std::cout << "Proceed to enter destination: ";
    std::cin >> TargetFloor;
    elevator.addTargetFloor(TargetFloor);       //Example 11
    elevator.getQueueSize();
    //elevator.processRequests();
    

    elevator.processRequests();

    return 0;
}