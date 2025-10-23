//
// Created by Jassvanthh Kunjeti on 20/10/25.
//

#ifndef PARKINGLOT_PARKINGFLOOR_H
#define PARKINGLOT_PARKINGFLOOR_H

#include <vector>
#include <mutex>
#include <unordered_map>
#include "ParkingLot.h"
#include "ParkingTicket.h"
#include "FeeStrategy.h"

class ParkingFloor {
private:
    int toalParkingLots;
    int numCompactParkingLots;
    int numMediumParkingLots;
    int numLargerParkingLots;
    int occupiedParkingLots;
    std::mutex mtx;
    std::vector<ParkingLot*> parkingLots;
    std::unordered_map<std::string, ParkingLot*> parked;
    std::unordered_map<std::string, ParkingTicket*> parkingTickets;
    FeeStrategy* feeStrategy;

public:
    ParkingFloor();
    bool chekAndParkVehicle(Vehicle* v);
    double unparkVehicle(Vehicle* v);
    int getAvailableParkingLots() ;
    bool isFull();
    bool isVehiclePresent(std::string vNumber);
    void addSlot(ParkingLot* plot);
    void setFeeStrategy(FeeStrategy* feeStrategy);
    ~ParkingFloor();
};
#endif //PARKINGLOT_PARKINGFLOOR_H