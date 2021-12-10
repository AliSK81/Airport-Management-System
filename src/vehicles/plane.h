#ifndef AIRPORTMANAGEMENTSYSTEM_PLANE_H
#define AIRPORTMANAGEMENTSYSTEM_PLANE_H

#include "vehicle.h"
#include "vector"
#include "../etc/flight.h"

class plane : public vehicle {
private:
    int numOfSeats;
    vector<flight> flights;

public:
    plane(const string &serial, const string &buildDate, int numOfSeats, const vector<flight> &flights);

    int getNumOfSeats() const;

    const vector<flight> &getFlights() const;
};


#endif //AIRPORTMANAGEMENTSYSTEM_PLANE_H
