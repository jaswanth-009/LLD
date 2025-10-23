//
// Created by Jassvanthh Kunjeti on 23/10/25.
//

#ifndef PARKINGLOT_PARKINGTICKET_H
#define PARKINGLOT_PARKINGTICKET_H
#include "ParkingLot.h"

class ParkingTicket {
    private:
        Vehicle* vehicle;
        ParkingLot* parkingLot;
        time_t entryTimeStamp;
        time_t exitTimeStamp;
public:
        ParkingTicket(Vehicle* v, ParkingLot* p);
        Vehicle* getVehicle();
        ParkingLot* getParkingLot();
        time_t getEntryTimeStamp();
    time_t getExitTimeStamp();
    void setExitTimeStamp(time_t time);
};

#endif //PARKINGLOT_PARKINGTICKET_H