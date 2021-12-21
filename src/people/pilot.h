#ifndef AIRPORTMANAGEMENTSYSTEM_PILOT_H
#define AIRPORTMANAGEMENTSYSTEM_PILOT_H

#include "worker.h"

class flight;

class pilot : public worker {
private:
    int rank;

public:
    pilot(const string &id, const string &name, const string &family, const string &birthDate, const string &pCode,
          const string &employDate, int rank);

    int getRank() const;

    void printInfo() const;

    virtual string getType() const { return "pilot"; }
};


#endif //AIRPORTMANAGEMENTSYSTEM_PILOT_H
