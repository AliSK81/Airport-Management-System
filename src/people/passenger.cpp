#include <iostream>
#include "passenger.h"

passenger::passenger(const string &id, const string &name, const string &family, const string &birthDate,
                     const string &fatherName) : person(id, name, family, birthDate), fatherName(fatherName) {}

void passenger::printInfo() const {
    person::printInfo();
    cout << "fatherName: " << fatherName << endl;
}
