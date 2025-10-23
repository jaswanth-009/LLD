//
// Created by Jassvanthh Kunjeti on 20/10/25.
//

#include "headers/ParkingFloor.h"

#include <iostream>
#include <ostream>

ParkingFloor::ParkingFloor() {
    std::cout <<"Created an empty Parking Floor\n";
    this->toalParkingLots = 0;
    this->occupiedParkingLots = 0;
    this->feeStrategy = nullptr;
}

void ParkingFloor::addSlot(ParkingLot *plot) {
    this->parkingLots.push_back(plot);
    this->toalParkingLots++;
}


int ParkingFloor::getAvailableParkingLots() {
    std::lock_guard<std::mutex> l(mtx);
    return toalParkingLots-occupiedParkingLots;
}

ParkingFloor::~ParkingFloor() {
    parkingLots.clear();
    this->occupiedParkingLots = 0;
}

bool ParkingFloor::chekAndParkVehicle(Vehicle *v) {
    std::lock_guard<std::mutex> l(mtx);
    VehicleType vType = v->getVehicleType();
    std::string vNumber = v->getVehicleNumber();

    for (int i = 0; i < parkingLots.size(); i++) {
        ParkingLot* pLot = parkingLots.at(i);
        if (pLot->isEmpty() && pLot->doesVehicleFits(vType)) {
            // park
            if (pLot->park(v)) {
                parked[vNumber] = pLot;
                occupiedParkingLots++;

                ParkingTicket* ticket = new ParkingTicket(v, pLot);
                parkingTickets[vNumber] = ticket;
                std::cout << "Successfullt Parked the vehicle " << vNumber << std::endl;
                return true;
            }
        }
    }
    return false;
}

double ParkingFloor::unparkVehicle(Vehicle *v) {
    std::lock_guard<std::mutex> l(mtx);

    std::string vNumber = v->getVehicleNumber();

    if (parked.find(vNumber) == parked.end()) {
        std::cout << "Vehicle not found\n";
        return 0.0;
    }

    ParkingLot* pLot = parked.at(vNumber);
    if (pLot->unpark(v)) {
        parked.erase(vNumber);
        occupiedParkingLots--;
        ParkingTicket* ticket = parkingTickets.at(vNumber);

        double finalCost = 0.0;
        if (feeStrategy != nullptr)
            finalCost = feeStrategy->calculateFees(ticket);
        parkingTickets.erase(vNumber);
        std::cout << "Successfully unparked vehicle " << vNumber << std::endl;
        return finalCost;
    }

    std::cout << "Failed to unpark vehicle from the lot" << vNumber << "\n";
    return 0.0;
}

bool ParkingFloor::isFull() {
    std::lock_guard<std::mutex> l(mtx);
    return toalParkingLots == occupiedParkingLots;
}

bool ParkingFloor::isVehiclePresent(std::string vNumber) {
    std::lock_guard<std::mutex> l(mtx);
    return parked.find(vNumber) != parked.end();
}


void ParkingFloor::setFeeStrategy(TimeBasedFeesStrategy* feeStrategy) {
    this->feeStrategy = feeStrategy;
}