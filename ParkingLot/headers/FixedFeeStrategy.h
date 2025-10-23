//
// Created by Jassvanthh Kunjeti on 23/10/25.
//

#ifndef PARKINGLOT_FIXEDFEESTRATEGY_H
#define PARKINGLOT_FIXEDFEESTRATEGY_H
#include "FeeStrategy.h"

class FixedFeeStrategy: public FeeStrategy {
    private:
        double fees;
    public:
        FixedFeeStrategy(double fees);
        double calculateFees(ParkingTicket *ticket) override;
};
#endif //PARKINGLOT_FIXEDFEESTRATEGY_H