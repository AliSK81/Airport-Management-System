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
    plane(const string &serial, const string &buildDate, int numOfSeats);

    int getNumOfSeats() const;

    const vector<flight> &getTasks() const;
};


#endif //AIRPORTMANAGEMENTSYSTEM_PLANE_H
