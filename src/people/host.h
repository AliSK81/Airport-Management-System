#ifndef AIRPORTMANAGEMENTSYSTEM_HOST_H
#define AIRPORTMANAGEMENTSYSTEM_HOST_H

#include <iostream>
#include "worker.h"

class flight;

class host : public worker {
public:
    host() = default;

    host(const string &id, const string &name, const string &family, const string &birthDate, const string &pCode,
         const string &employDate);

    void printInfo() const;

    virtual string getType() const { return "host"; }

    virtual void out(ostream &os) const {
        worker::out(os);
        os << endl;
    }

    virtual void in(istream &is) {
        worker::in(is);
    }

};


#endif //AIRPORTMANAGEMENTSYSTEM_HOST_H
