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

const string &ticket::getPassengerId() const {
    return passengerId;
}

const string &ticket::getCarrierId() const {
    return carrierId;
}

double ticket::getTicketPrice() const {
    return ticketPrice;
}


void ticket::printInfo() const {
    cout << getType() << " ---------------------\n";
    cout << "flightSerial: " << flightSerial << ", flightDate: " << flightDate << ", flightTime: " << flightTime << endl;
    cout << "origin: " << origin << ", dest: " << dest << endl;
    cout << "passengerId: " << passengerId << ", passengerName: " << passengerName << ", passengerFamily: " << passengerFamily << endl;
    cout << "planeSerial: " << planeSerial << ", pilotPId: " << pilotPId << ", carrierId: " << carrierId << endl;
    cout << "ticketPrice: " << ticketPrice << ", profitRate: " << profitRate << endl;
}

void ticket::setTicketPrice(double price) {
    ticketPrice = price;
}

void ticket::setProfitRate(double rate) {
    profitRate = rate;
}
