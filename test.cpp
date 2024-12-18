#include <iostream>
#include "elevator.hpp"
//#include "lobby.hpp"
//#include <string>
//#include <vector>

int main(){
    
    /*double number_of_elevators;
    double number_of_floors;

    std::cout << "Set up program. How many elevator would you like" << std::endl;
    std::cin << number_of_elevators;

    std::cout << "How many floors are in the building?" << std::endl;
    std::cin << number_of_floors;



    std::cout << ""
    */
    bk::Elevator elevator(5, 15, 0);

    elevator.addTargetFloor(7);
    elevator.addTargetFloor(-3);
    elevator.addTargetFloor(11);

    elevator.processRequests();

    return 0;
}