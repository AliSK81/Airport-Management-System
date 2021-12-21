#include <iostream>
#include "ticket.h"

ticket::ticket(const string &flightSerial, const string &flightDate, const string &flightTime, const string &origin,
               const string &dest, const string &passengerName, const string &passengerFamily,
               const string &passengerId, const string &planeSerial, const string &pilotPId, const string &carrierId,
               double ticketPrice, double profitRate) : flightSerial(flightSerial), flightDate(flightDate),
                                                        flightTime(flightTime), origin(origin), dest(dest),
                                                        passengerName(passengerName), passengerFamily(passengerFamily),
                                                        passengerId(passengerId), planeSerial(planeSerial),
                                                        pilotPId(pilotPId), carrierId(carrierId),
                                                        ticketPrice(ticketPrice), profitRate(profitRate) {}

const string &ticket::getFlightSerial() const {
    return flightSerial;
}

const string &ticket::getFlightDate() const {
    return flightDate;
}

const string &ticket::getFlightTime() const {
    return flightTime;
}

const string &ticket::getOrigin() const {
    return origin;
}

const string &ticket::getDest() const {
    return dest;
}

const string &ticket::getPassengerName() const {
    return passengerName;
}

const string &ticket::getPassengerFamily() const {
    return passengerFamily;
}

const string &ticket::getPassengerId() const {
    return passengerId;
}

const string &ticket::getPlaneSerial() const {
    return planeSerial;
}

const string &ticket::getPilotPId() const {
    return pilotPId;
}

const string &ticket::getCarrierId() const {
    return carrierId;
}

double ticket::getTicketPrice() const {
    return ticketPrice;
}

double ticket::getProfitRate() const {
    return profitRate;
}

void ticket::printInfo() const {
    cout << getType() << " ---------------------\n";
    cout << "flightSerial: " << flightSerial << ", flightDate: " << flightDate << ", flightTime: " << flightTime << endl;
    cout << "origin: " << origin << ", dest: " << dest << endl;
    cout << "passengerId: " << passengerId << ", passengerName: " << passengerName << ", passengerFamily: " << passengerFamily << endl;
    cout << "planeSerial: " << planeSerial << ", pilotPId: " << pilotPId << ", carrierId: " << carrierId << endl;
    cout << "ticketPrice: " << ticketPrice << ", profitRate: " << profitRate << endl;
}
