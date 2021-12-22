#ifndef AIRPORTMANAGEMENTSYSTEM_FLIGHT_H
#define AIRPORTMANAGEMENTSYSTEM_FLIGHT_H

#include "string"
#include "vector"
#include "../people/pilot.h"
#include "../people/passenger.h"

using namespace std;

class host;

class flight {
private:
    string flightSerial;
    string planeSerial;
    string origin;
    string dest;
    string flightDate;
    string flightTime;
    int numOfPassengers;
    pilot *pilot;
    vector<host *> hosts;
    vector<passenger *> passengers;
    double ticketsIncome;

public:
    flight() = default;

    flight(const string &flightSerial, const string &planeSerial, const string &origin, const string &dest,
           const string &flightDate, const string &flightTime, class pilot *pilot);

    const string &getFlightSerial() const;

    const string &getPlaneSerial() const;

    const string &getOrigin() const;

    const string &getDest() const;

    const string &getFlightDate() const;

    const string &getFlightTime() const;

    class pilot *getPilot();

    const vector<host *> &getHosts() const;

    vector<struct passenger *> getPassengers() const;

    double getTicketsIncome() const;

    static bool compareSerial(const flight *f1, const flight *f2);

    void addHost(host *h);

    void removeHost(host *h);

    void addPassenger(passenger *p);

    void removePassenger(passenger *p);

    void setTicketsIncome(double ticketsIncome);

    void printInfo() const;

    virtual string getType() const { return "flight"; }

    void setOrigin(const string &origin);

    void setDest(const string &dest);

    void setFlightDate(const string &flightDate);

    void setFlightTime(const string &flightTime);

    void setPilot(class pilot *pilot);

    virtual void out(ostream &os) const {
        os <<
           flightSerial
           + ' ' + planeSerial
           + ' ' + origin
           + ' ' + dest
           + ' ' + flightDate
           + ' ' + flightTime
           + ' ' + pilot->getPCode()
           + ' ' + to_string(ticketsIncome)
           << endl;
    }

    virtual void in(istream &is) {
        string pilotPCode, income;
        is >> flightSerial >> planeSerial >> origin >> dest >> flightDate >> flightTime >> pilotPCode >> income;
        if (income != "")
            ticketsIncome = stof(income);

    }

    friend ostream &operator<<(ostream &out, const flight &f) {
        f.out(out);
        return out;
    }

    friend istream &operator>>(istream &in, flight &f) {
        f.in(in);
        return in;
    }

};


#endif //AIRPORTMANAGEMENTSYSTEM_FLIGHT_H
