#ifndef AIRPORTMANAGEMENTSYSTEM_FLIGHT_H
#define AIRPORTMANAGEMENTSYSTEM_FLIGHT_H

#include "string"
#include "vector"
#include "../people/pilot.h"
#include "../people/passenger.h"

using namespace std;

class host;

class flight {
private:
    string flightSerial;
    string planeSerial;
    string origin;
    string dest;
    string flightDate;
    string flightTime;
    int numOfPassengers;
    pilot pilot;
    vector<host*> hosts;
    vector<passenger> passengers;
    double ticketsIncome;

public:
    flight(const string &flightSerial, const string &planeSerial, const string &origin, const string &dest,
           const string &flightDate, const string &flightTime, int numOfPassengers, const class pilot &pilot,
           double ticketsIncome);

    const string &getFlightSerial() const;

    const string &getPlaneSerial() const;

    const string &getOrigin() const;

    const string &getDest() const;

    const string &getFlightDate() const;

    const string &getFlightTime() const;

    int getNumOfPassengers() const;

    const class pilot &getPilot() const;

    const vector<host *> &getHosts() const;

    const vector<passenger> &getPassengers() const;

    double getTicketsIncome() const;

    static bool compareSerial(const flight &f1, const flight &f2);
};


#endif //AIRPORTMANAGEMENTSYSTEM_FLIGHT_H
