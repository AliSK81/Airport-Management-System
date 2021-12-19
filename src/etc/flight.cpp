#include "flight.h"

flight::flight(const string &flightSerial, const string &planeSerial, const string &origin, const string &dest,
               const string &flightDate, const string &flightTime, int numOfPassengers, const class pilot &pilot,
               double ticketsIncome) : flightSerial(flightSerial), planeSerial(planeSerial), origin(origin), dest(dest),
                                       flightDate(flightDate), flightTime(flightTime), numOfPassengers(numOfPassengers),
                                       pilot(pilot), ticketsIncome(ticketsIncome) {}

const string &flight::getFlightSerial() const {
    return flightSerial;
}

const string &flight::getPlaneSerial() const {
    return planeSerial;
}

const string &flight::getOrigin() const {
    return origin;
}

const string &flight::getDest() const {
    return dest;
}

const string &flight::getFlightDate() const {
    return flightDate;
}

const string &flight::getFlightTime() const {
    return flightTime;
}

int flight::getNumOfPassengers() const {
    return numOfPassengers;
}

const pilot &flight::getPilot() const {
    return pilot;
}

const vector<host *> &flight::getHosts() const {
    return hosts;
}

const vector<passenger> &flight::getPassengers() const {
    return passengers;
}

double flight::getTicketsIncome() const {
    return ticketsIncome;
}

bool flight::compareSerial(const flight& f1, const flight& f2) {
    return f1.flightSerial > f2.flightSerial;
}
