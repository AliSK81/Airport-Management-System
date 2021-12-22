#ifndef AIRPORTMANAGEMENTSYSTEM_PASSENGER_H
#define AIRPORTMANAGEMENTSYSTEM_PASSENGER_H

#include <iostream>
#include "person.h"

class flight;

class passenger : public person {
private:
    string fatherName;

public:
    passenger() = default;

    passenger(const string &id, const string &name, const string &family, const string &birthDate,
              const string &fatherName);

    void printInfo() const;

    virtual string getType() const { return "passenger"; }

    virtual void out(ostream &os) const {
        person::out(os);
        os << ' ' + fatherName << endl;
    }

    virtual void in(istream &is) {
        person::in(is);
        is >> fatherName;
    }

};


#endif //AIRPORTMANAGEMENTSYSTEM_PASSENGER_H
