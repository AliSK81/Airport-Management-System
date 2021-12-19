#ifndef AIRPORTMANAGEMENTSYSTEM_CARRIER_H
#define AIRPORTMANAGEMENTSYSTEM_CARRIER_H

#include "vehicle.h"
#include "vector"
#include "../etc/ticket.h"

class carrier : public vehicle {
private:
    vector<ticket> tasks;

public:
    carrier(const string &serial, const string &buildDate);

    void addTask(const ticket &task);

    const vector<ticket> &getTasks() const;

};


#endif //AIRPORTMANAGEMENTSYSTEM_CARRIER_H
