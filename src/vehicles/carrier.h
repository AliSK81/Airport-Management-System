#ifndef AIRPORTMANAGEMENTSYSTEM_CARRIER_H
#define AIRPORTMANAGEMENTSYSTEM_CARRIER_H

#include "vehicle.h"
#include "vector"
#include "../etc/ticket.h"

class carrier : public vehicle {
private:
    vector<ticket *> tasks;

public:
    carrier() = default;

    carrier(const string &serial, const string &buildDate);

    const vector<ticket *> &getTasks() const;

    void addTask(ticket *task);

    void removeTask(ticket *task);

    void printInfo() const;

    virtual string getType() const { return "carrier"; }

    virtual void out(ostream &os) const {
        vehicle::out(os);
        os << endl;
    }

    virtual void in(istream &is) {
        vehicle::in(is);
    }

};


#endif //AIRPORTMANAGEMENTSYSTEM_CARRIER_H
