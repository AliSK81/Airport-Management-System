#ifndef AIRPORTMANAGEMENTSYSTEM_FLIGHT_H
#define AIRPORTMANAGEMENTSYSTEM_FLIGHT_H

#include "string"
#include "vector"
#include "../people/pilot.h"
#include "../people/host.h"

using namespace std;

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
    vector<host> hosts;
    double ticketsIncome;

public:
    flight(const string &flightSerial, const string &planeSerial, const string &origin, const string &dest,
           const string &flightDate, const string &flightTime, int numOfPassengers, const pilot &pilot,
           const vector<host> &hosts, double ticketsIncome);

    const string &getFlightSerial() const;

    const string &getPlaneSerial() const;

    const string &getOrigin() const;

    const string &getDest() const;

    const string &getFlightDate() const;

    const string &getFlightTime() const;

    int getNumOfPassengers() const;

    const pilot &getPilot() const;

    const vector<host> &getHosts() const;

    double getTicketsIncome() const;

};


#endif //AIRPORTMANAGEMENTSYSTEM_FLIGHT_H
