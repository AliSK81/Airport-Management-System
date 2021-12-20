#include "plane.h"

plane::plane(const string &serial, const string &buildDate, int numOfSeats) : vehicle(
        serial, buildDate), numOfSeats(numOfSeats), flights(flights) {}

int plane::getNumOfSeats() const {
    return numOfSeats;
}

void plane::addFlight(flight *flight) {
    flights.push_back(flight);
}

bool plane::removeFlight(string &serial) {
    for (auto f = flights.begin(); f != flights.end(); f++) {
        if ((*f)->getFlightSerial() == serial) {
            flights.erase(f, f + 1);
            return true;
        }
    }
    return false;
}

const vector<flight *> &plane::getTasks() const {
    return flights;
}
