#include <iostream>
#include "plane.h"
#include "../airport.h"

plane::plane(const string &serial, const string &buildDate, int numOfSeats) : vehicle(serial, buildDate),
                                                                              numOfSeats(numOfSeats) {}

void plane::setNumOfSeats(int seats) {
    numOfSeats = seats;
}

void plane::addTask(flight *flight) {
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

