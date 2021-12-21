#include <iostream>
#include "flight.h"
#include "../airport.h"

flight::flight(const string &flightSerial, const string &planeSerial, const string &origin, const string &dest,
               const string &flightDate, const string &flightTime, class pilot *pilot)
        : flightSerial(flightSerial), planeSerial(planeSerial), origin(origin), dest(dest),
          flightDate(flightDate), flightTime(flightTime), numOfPassengers(0), ticketsIncome(0),
          pilot(pilot) {}

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

pilot *flight::getPilot() {
    return pilot;
}

const vector<host *> &flight::getHosts() const {
    return hosts;
}

vector<passenger *> flight::getPassengers() const {
    return passengers;
}

double flight::getTicketsIncome() const {
    return ticketsIncome;
}

bool flight::compareSerial(const flight *f1, const flight *f2) {
    return f1->flightSerial > f2->flightSerial;
}

void flight::addHost(host *h) {
    hosts.push_back(h);
}

void flight::addPassenger(passenger *p) {
    passengers.push_back(p);
    numOfPassengers++;
}

void flight::setTicketsIncome(double ticketsIncome) {
    flight::ticketsIncome = ticketsIncome;
}

void flight::removeHost(host *h) {
    airport::removeElement(hosts, h);
}

void flight::removePassenger(passenger *p) {
    airport::removeElement(passengers, p);
}

void flight::printInfo() const {
    cout << getType() << " ---------------------\n";
    cout << "flightSerial: " << flightSerial << ", flightDate: " << flightDate << ", flightTime: " << flightTime << endl;
    cout << "origin: " << origin << ", dest: " << dest << endl;
    cout << "planeSerial: " << planeSerial << ", numOfPassengers: " << numOfPassengers << ", ticketsIncome: " << ticketsIncome << endl;
    cout << "hosts: " << hosts.size() << ", passengers: " << passengers.size() << endl;
    cout << "pilot info:" << endl;
    pilot->printInfo();
}

void flight::setOrigin(const string &origin) {
    flight::origin = origin;
}

void flight::setDest(const string &dest) {
    flight::dest = dest;
}

void flight::setFlightDate(const string &flightDate) {
    flight::flightDate = flightDate;
}

void flight::setFlightTime(const string &flightTime) {
    flight::flightTime = flightTime;
}

