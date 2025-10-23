#include <iostream>
#include <thread>

#include "headers/ParkingFloor.h"
#include "headers/TimeBasedFeesStrategy.h"

int main() {

    ParkingLot* l1 = new ParkingLot(ParkingType::Medium, "m1");
    ParkingLot* l2 = new ParkingLot(ParkingType::Medium, "m2");
    ParkingLot* l3 = new ParkingLot(ParkingType::Large, "l1");

    ParkingFloor* floor = new ParkingFloor();
    floor->addSlot(l1);
    floor->addSlot(l2);
    floor->addSlot(l3);

    Vehicle* v1 = new Vehicle(VehicleType::Car, "qwerty");
    Vehicle* v2 = new Vehicle(VehicleType::SUV, "iuytr");

    FeeStrategy* st = new TimeBasedFeesStrategy();

    floor->setFeeStrategy(st);

    std::this_thread::sleep_for(std::chrono::seconds(3));

    floor->chekAndParkVehicle(v1);
    std::cout << "Sleeping for 10 seconds\n";
    std::this_thread::sleep_for(std::chrono::seconds(10));

    floor->chekAndParkVehicle(v2);
    std::cout << floor->unparkVehicle(v1) << std::endl;

    std::cout << "Sleeping for 20 seconds\n";
    std::this_thread::sleep_for(std::chrono::seconds(20));
    std::cout << floor->unparkVehicle(v2) << std::endl;

    delete l1, l2, l3, v1, v2, floor, st;
}