//
// Created by Jassvanthh Kunjeti on 23/10/25.
//

#ifndef PARKINGLOT_TIMEBASEDFEESSTRATEGY_H
#define PARKINGLOT_TIMEBASEDFEESSTRATEGY_H
#include "ParkingTicket.h"
#include  <unordered_map>

class TimeBasedFeesStrategy {
private:
    std::unordered_map<VehicleType, double> fares{};
public:
    TimeBasedFeesStrategy();
    void setFare(VehicleType type, double fare);
    double calculateFees(ParkingTicket* ticket);
};
#endif //PARKINGLOT_TIMEBASEDFEESSTRATEGY_H