//
// Created by Jassvanthh Kunjeti on 23/10/25.
//

#include "headers/TimeBasedFeesStrategy.h"
#include <iostream>

TimeBasedFeesStrategy::TimeBasedFeesStrategy() {
    std::cout << "Default fares are update\n";
    std::vector<VehicleType> vtypes = getAllVehicleTypes();

    fares[VehicleType::Bike] = 10;
    fares[VehicleType::Car] = 20;
    fares[VehicleType::SUV] = 30;
    fares[VehicleType::Truck] = 40;
}

double TimeBasedFeesStrategy::calculateFees(ParkingTicket* ticket) {
    time_t exitTime;
    time(&exitTime);

    ticket->setExitTimeStamp(exitTime);

    time_t entryTime = ticket->getEntryTimeStamp();

    double difference = difftime(exitTime, entryTime);
    difference = ceil(difference/3600);

    double finalCost = fares[ticket->getVehicle()->getVehicleType()] * difference;
    return finalCost;
}