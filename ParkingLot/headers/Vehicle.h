//
// Created by Jassvanthh Kunjeti on 20/10/25.
//

#ifndef PARKINGLOT_VEHICLE_H
#define PARKINGLOT_VEHICLE_H
#include "VehicleType.h"
#include <string>

class Vehicle {
    public:
        Vehicle(VehicleType type, std::string number);
        VehicleType getVehicleType() const;
        std::string getVehicleNumber() const;
    private:
        VehicleType vehicleType;
        std::string vNumber;
};

#endif //PARKINGLOT_VEHICLE_H
