#ifndef AIRPORTMANAGEMENTSYSTEM_VEHICLE_H
#define AIRPORTMANAGEMENTSYSTEM_VEHICLE_H

#include "string"

using namespace std;

class vehicle {
private:
    string serial;
    string buildDate;

public:
    vehicle(const string &serial, const string &buildDate);

    const string &getSerial() const;

    const string &getBuildDate() const;

};


#endif //AIRPORTMANAGEMENTSYSTEM_VEHICLE_H
