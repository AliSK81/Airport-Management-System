#include "person.h"

person::person(const string &id, const string &name, const string &family, const string &birthDate) :
        id(id), name(name), family(family), birthDate(birthDate) {}

const string &person::getId() const {
    return id;
}

const string &person::getName() const {
    return name;
}

const string &person::getFamily() const {
    return family;
}

const string &person::getBirthDate() const {
    return birthDate;
}

