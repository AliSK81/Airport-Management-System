#ifndef AIRPORTMANAGEMENTSYSTEM_PASSENGER_H
#define AIRPORTMANAGEMENTSYSTEM_PASSENGER_H

#include "person.h"

class passenger : person {
private:
    string fatherName;

public:
    passenger(const string &id, const string &name, const string &family, const string &birthDate,
              const string &fatherName);

    const string &getFatherName() const;
};


#endif //AIRPORTMANAGEMENTSYSTEM_PASSENGER_H
