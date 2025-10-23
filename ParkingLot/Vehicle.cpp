//
// Created by Jassvanthh Kunjeti on 20/10/25.
//

#include "headers/Vehicle.h"

Vehicle::Vehicle(VehicleType type, std::string number) {
    this->vehicleType = type;
    this->vNumber = number;
}

std::string Vehicle::getVehicleNumber() const {
    return this->vNumber;
}

VehicleType Vehicle::getVehicleType() const {
    return this->vehicleType;
}

