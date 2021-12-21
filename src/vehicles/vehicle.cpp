#include <iostream>
#include "vehicle.h"

vehicle::vehicle(const string &serial, const string &buildDate) : serial(serial), buildDate(buildDate) {}

const string &vehicle::getSerial() const {
    return serial;
}

const string &vehicle::getBuildDate() const {
    return buildDate;
}

void vehicle::printInfo() const {
    cout << getType() << " ------------------------\n";
    cout << "serial: " << serial << ", buildDate: " << buildDate << endl;
}





