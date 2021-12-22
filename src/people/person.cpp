#include "person.h"
#include <iostream>

person::person(const string &id, const string &name, const string &family, const string &birthDate) :
        id(id), name(name), family(family), birthDate(birthDate) {}

const string &person::getId() const {
    return id;
}

bool person::compareBirthDate(const person *p1, const person *p2) {
    return p1->birthDate > p2->birthDate;
}

bool person::compareFamily(const person *p1, const person *p2) {
    return p1->family > p2->family;
}

void person::printInfo() const {
    cout << getType() << " -------------------------------\n";
    cout << "id: " << id << ", name: " << name << ", family: " << family << ", birthDate: " << birthDate << endl;
}

void person::setName(const string &pname) {
    person::name = pname;
}

void person::setFamily(const string &pfamily) {
    person::family = pfamily;
}

void person::setBirthDate(const string &pbirthDate) {
    person::birthDate = pbirthDate;
}


