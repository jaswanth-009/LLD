//
// Created by Jassvanthh Kunjeti on 20/10/25.
//

#ifndef PARKINGLOT_PARKINGTYPE_H
#define PARKINGLOT_PARKINGTYPE_H

#include <string>

enum ParkingType {
    Compact,
    Medium,
    Large
};

static inline std::string getParkingType(ParkingType parkingType) {
    switch (parkingType) {
        case Compact: return "Compact";
        case Medium: return "Medium";
        case Large: return "Large";
        default: return "Unknown";
    }
    return "Unknown";
}
#endif //PARKINGLOT_PARKINGTYPE_H