//
// Created by Jassvanthh Kunjeti on 20/10/25.
//

#ifndef PARKINGLOT_PARKINGLOT_H
#define PARKINGLOT_PARKINGLOT_H
#include "ParkingType.h"
#include "Vehicle.h"
#include <mutex>

class ParkingLot {
    public:
        bool isEmpty();
        Vehicle* getVehicle();
        bool park(Vehicle* vehicle);
        bool unpark(Vehicle* vehicle);
        ParkingLot(ParkingType type, std::string slotId);
        bool doesVehicleFits(VehicleType type);
        std::string getSlotId() const;
    private:
        ParkingType parkingType;
        Vehicle* vehicle;
        std::mutex mtx;
        std::string slotId;
};
#endif //PARKINGLOT_PARKINGLOT_H