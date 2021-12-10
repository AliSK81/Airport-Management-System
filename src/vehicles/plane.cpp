#include "plane.h"

plane::plane(const string &serial, const string &buildDate, int numOfSeats, const vector<flight> &flights) : vehicle(
        serial, buildDate), numOfSeats(numOfSeats), flights(flights) {}

int plane::getNumOfSeats() const {
    return numOfSeats;
}

const vector<flight> &plane::getFlights() const {
    return flights;
}
