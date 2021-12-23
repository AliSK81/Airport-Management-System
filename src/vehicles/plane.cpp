#include <iostream>
#include "plane.h"
#include "../airport.h"

plane::plane(const string &serial, const string &buildDate, int numOfSeats) : vehicle(serial, buildDate),
                                                                              numOfSeats(numOfSeats) {}

void plane::setNumOfSeats(int seats) {
    numOfSeats = seats;
}

void plane::addTask(flight *flight) {
    tasks.push_back(flight);
}

void plane::removeTask(flight *f) {
    airport::removeElement(tasks, f);
}

const vector<flight *> &plane::getTasks() const {
    return tasks;
}

void plane::printInfo() const {
    vehicle::printInfo();
    cout << "numOfSeats: " << numOfSeats << ", tasks: " << tasks.size() << endl;
}

