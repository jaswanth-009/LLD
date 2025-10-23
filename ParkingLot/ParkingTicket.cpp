//
// Created by Jassvanthh Kunjeti on 23/10/25.
//

#include "headers/ParkingTicket.h"

ParkingTicket::ParkingTicket(Vehicle *v, ParkingLot *p) {
    this->vehicle = v;
    this->parkingLot = p;
    time(&this->entryTimeStamp);
}

time_t ParkingTicket::getEntryTimeStamp() {
    return this->entryTimeStamp;
}

ParkingLot* ParkingTicket::getParkingLot() {
    return this->parkingLot;
}

Vehicle *ParkingTicket::getVehicle() {
    return this->vehicle;
}

time_t ParkingTicket::getExitTimeStamp() {
    return this->exitTimeStamp;
}

void ParkingTicket::setExitTimeStamp(time_t time) {
    this->exitTimeStamp = time;
}

