#ifndef AIRPORTMANAGEMENTSYSTEM_PASSENGER_H
#define AIRPORTMANAGEMENTSYSTEM_PASSENGER_H

#include "person.h"

class flight;

class passenger : public person {
private:
    string fatherName;

public:
    passenger(const string &id, const string &name, const string &family, const string &birthDate,
              const string &fatherName);

    const string &getFatherName() const;

    void printInfo() const;

    virtual string getType() const { return "passenger"; }

};


#endif //AIRPORTMANAGEMENTSYSTEM_PASSENGER_H
