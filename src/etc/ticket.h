#ifndef AIRPORTMANAGEMENTSYSTEM_TICKET_H
#define AIRPORTMANAGEMENTSYSTEM_TICKET_H

#include "string"

using namespace std;

class ticket {
private:
    string flightSerial;
    string flightDate;
    string flightTime;
    string origin;
    string dest;
    string passengerName;
    string passengerFamily;
    string passengerId;
    string planeSerial;
    string pilotPId;
    string carrierId;
    double ticketPrice;
    double profitRate;

public:
    ticket(const string &flightSerial, const string &flightDate, const string &flightTime, const string &origin,
           const string &dest, const string &passengerName, const string &passengerFamily, const string &passengerId,
           const string &planeSerial, const string &pilotPId, const string &carrierId, double ticketPrice,
           double profitRate);

    const string &getFlightSerial() const;

    const string &getFlightDate() const;

    const string &getFlightTime() const;

    const string &getOrigin() const;

    const string &getDest() const;

    const string &getPassengerName() const;

    const string &getPassengerFamily() const;

    const string &getPassengerId() const;

    const string &getPlaneSerial() const;

    const string &getPilotPId() const;

    const string &getCarrierId() const;

    double getTicketPrice() const;

    double getProfitRate() const;

    void printInfo() const;

    virtual string getType() const { return "ticket"; }

};


#endif //AIRPORTMANAGEMENTSYSTEM_TICKET_H
