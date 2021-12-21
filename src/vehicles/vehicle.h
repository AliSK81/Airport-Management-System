#ifndef AIRPORTMANAGEMENTSYSTEM_VEHICLE_H
#define AIRPORTMANAGEMENTSYSTEM_VEHICLE_H

#include "string"
#include <vector>

using namespace std;

class vehicle {
private:
    string serial;
    string buildDate;

public:
    vehicle(const string &serial, const string &buildDate);

    const string &getSerial() const;

    const string &getBuildDate() const;

    void printInfo() const;

    virtual string getType() const = 0;

    void setBuildDate(const string &buildDate);


};


#endif //AIRPORTMANAGEMENTSYSTEM_VEHICLE_H
