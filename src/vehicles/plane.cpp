#include <iostream>
#include "plane.h"
#include "../airport.h"

plane::plane(const string &serial, const string &buildDate, int numOfSeats) : vehicle(serial, buildDate),
                                                                              numOfSeats(numOfSeats) {}

int plane::getNumOfSeats() const {
    return numOfSeats;
}

void plane::addFlight(flight *flight) {
    flights.push_back(flight);
}

void plane::removeFlight(flight *f) {
    airport::removeElement(flights, f);
}

const vector<flight *> &plane::getTasks() const {
    return flights;
}

void plane::printInfo() const {
    vehicle::printInfo();
    cout << "numOfSeats: " << numOfSeats << ", tasks: " << flights.size() << endl;
}

void plane::setNumOfSeats(int numOfSeats) {
    plane::numOfSeats = numOfSeats;
}

