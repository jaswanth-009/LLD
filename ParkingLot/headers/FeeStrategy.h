//
// Created by Jassvanthh Kunjeti on 23/10/25.
//

#ifndef PARKINGLOT_FEESTRATEGY_H
#define PARKINGLOT_FEESTRATEGY_H

#include "ParkingTicket.h"
#include <unordered_map>

class FeeStrategy {
    public:
        virtual double calculateFees(ParkingTicket* ticket) = 0;
};
#endif //PARKINGLOT_FEESTRATEGY_H