//
// Created by Jassvanthh Kunjeti on 20/10/25.
//

#ifndef PARKINGLOT_VEHICLETYPE_H
#define PARKINGLOT_VEHICLETYPE_H

#include <vector>

enum VehicleType {
    Bike,
    Car,
    SUV,
    Truck
};

static inline std::vector<VehicleType> getAllVehicleTypes() {
    return {Bike, Car, SUV, Truck};
}
#endif //PARKINGLOT_VEHICLETYPE_H