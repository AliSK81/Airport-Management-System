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
    ticket() = default;

    ticket(const string &flightSerial, const string &flightDate, const string &flightTime, const string &origin,
           const string &dest, const string &passengerName, const string &passengerFamily, const string &passengerId,
           const string &planeSerial, const string &pilotPId, const string &carrierId, double ticketPrice,
           double profitRate);

    const string &getFlightSerial() const;

    const string &getPassengerId() const;

    const string &getCarrierId() const;

    double getTicketPrice() const;

    void printInfo() const;

    virtual string getType() const { return "ticket"; }

    void setTicketPrice(double price);

    void setProfitRate(double rate);

    virtual void out(ostream &os) const {
        os <<
           flightSerial
           + ' ' + flightDate
           + ' ' + flightTime
           + ' ' + origin
           + ' ' + dest
           + ' ' + passengerName
           + ' ' + passengerFamily
           + ' ' + passengerId
           + ' ' + planeSerial
           + ' ' + pilotPId
           + ' ' + carrierId
           + ' ' + to_string(ticketPrice)
           + ' ' + to_string(profitRate)
           << endl;
    }

    virtual void in(istream &is) {
        string tp, pr;
        is >>
           flightSerial
           >> flightDate
           >> flightTime
           >> origin
           >> dest
           >> passengerName
           >> passengerFamily
           >> passengerId
           >> planeSerial
           >> pilotPId
           >> carrierId
           >> tp
           >> pr;
        if (tp != "")
            ticketPrice = stod(tp);
        if (pr != "")
            profitRate = stod(pr);
    }

    friend ostream &operator<<(ostream &out, const ticket &t) {
        t.out(out);
        return out;
    }

    friend istream &operator>>(istream &in, ticket &t) {
        t.in(in);
        return in;
    }

};


#endif //AIRPORTMANAGEMENTSYSTEM_TICKET_H
