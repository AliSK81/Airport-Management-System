#ifndef AIRPORTMANAGEMENTSYSTEM_PLANE_H
#define AIRPORTMANAGEMENTSYSTEM_PLANE_H

#include "vehicle.h"
#include "vector"
#include "../etc/flight.h"

class plane : public vehicle {
private:
    int numOfSeats;
    vector<flight *> flights;

public:
    plane() = default;

    plane(const string &serial, const string &buildDate, int numOfSeats);

    void setNumOfSeats(int seats);

    const vector<flight *> &getTasks() const;

    void addTask(flight *flight);

    void removeTask(flight *f);

    void printInfo() const;

    virtual string getType() const { return "plane"; }

    virtual void out(ostream &os) const {
        vehicle::out(os);
        os << ' ' << numOfSeats << endl;
    }

    virtual void in(istream &is) {
        vehicle::in(is);
        is >> numOfSeats;
    }

};


#endif //AIRPORTMANAGEMENTSYSTEM_PLANE_H
