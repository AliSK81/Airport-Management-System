#ifndef AIRPORTMANAGEMENTSYSTEM_VEHICLE_H
#define AIRPORTMANAGEMENTSYSTEM_VEHICLE_H

#include "string"
#include <vector>

using namespace std;

class vehicle {
private:
    string serial;
    string buildDate;

public:
    vehicle(const string &serial, const string &buildDate);

    vehicle() = default;

    const string &getSerial() const;

    virtual void printInfo() const;

    virtual string getType() const = 0;

    void setBuildDate(const string &buildDate);


    virtual void out(ostream &os) const {
        os << serial + ' ' + buildDate;
    }

    virtual void in(istream &is) {
        is >> serial >> buildDate;
    }

    friend ostream &operator<<(ostream &out, const vehicle &v) {
        v.out(out);
        return out;
    }

    friend istream &operator>>(istream &in, vehicle &v) {
        v.in(in);
        return in;
    }

};


#endif //AIRPORTMANAGEMENTSYSTEM_VEHICLE_H
