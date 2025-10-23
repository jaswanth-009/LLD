//
// Created by Jassvanthh Kunjeti on 23/10/25.
//

#ifndef PARKINGLOT_TIMEBASEDFEESSTRATEGY_H
#define PARKINGLOT_TIMEBASEDFEESSTRATEGY_H
#include "FeeStrategy.h"
#include  <unordered_map>

class TimeBasedFeesStrategy : public FeeStrategy {
private:
    std::unordered_map<VehicleType, double> fares{};
public:
    TimeBasedFeesStrategy();
    double calculateFees(ParkingTicket* ticket) override;
};
#endif //PARKINGLOT_TIMEBASEDFEESSTRATEGY_H