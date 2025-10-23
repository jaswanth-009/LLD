//
// Created by Jassvanthh Kunjeti on 20/10/25.
//

#include <iostream>

#include "headers/ParkingLot.h"

ParkingLot::ParkingLot(ParkingType type, std::string slotId) {
    this->parkingType = type;
    this->vehicle = nullptr;
    this->slotId = slotId;
    std::cout << "Created a parking lot of type " << getParkingType(this->parkingType) << " with slotId: " << this->slotId << "\n";
}

bool ParkingLot::isEmpty() {
    std::lock_guard<std::mutex> l(mtx);
    return vehicle == nullptr;
}

Vehicle *ParkingLot::getVehicle() {
    std::lock_guard<std::mutex> l(mtx);
    return vehicle;
}

bool ParkingLot::park(Vehicle *vehicle) {
    std::lock_guard<std::mutex> lock(mtx);

    if (this->vehicle != nullptr) {
        std::cout << "Parking lot is occupied\n";
        return false;
    }

    vehicle = vehicle;
    return true;
}

bool ParkingLot::unpark(Vehicle *vehicle) {
    std::lock_guard<std::mutex> l(mtx);
    if (vehicle == nullptr) {
        std::cout << "Parking lot is already empty\n";
        return false;
    }

    vehicle = nullptr;
    return true;
}

bool ParkingLot::doesVehicleFits(VehicleType type) {
    if (parkingType == ParkingType::Compact) {
        return type <= VehicleType::Bike;
    }

    if (parkingType == ParkingType::Medium) {
        return type <= VehicleType::SUV;
    }

    if (parkingType == ParkingType::Large) {
        return type <= VehicleType::Truck;
    }
    return false;
}

std::string ParkingLot::getSlotId() const {
    return this->slotId;
}

