//
// Created by Jassvanthh Kunjeti on 23/10/25.
//

#include  "headers/FixedFeeStrategy.h"

double FixedFeeStrategy::calculateFees(ParkingTicket *ticket) {
    return fees;
}

FixedFeeStrategy::FixedFeeStrategy(double fees) {
    this->fees = fees;
}

