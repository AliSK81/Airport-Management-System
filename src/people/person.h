#ifndef AIRPORTMANAGEMENTSYSTEM_PERSON_H
#define AIRPORTMANAGEMENTSYSTEM_PERSON_H

#include <string>

using namespace std;

class person {
private:
    string id;
    string name;
    string family;
    string birthDate;

public:
    person(const string &id, const string &name, const string &family, const string &birthDate);

    const string &getId() const;

    const string &getName() const;

    const string &getFamily() const;

    const string &getBirthDate() const;

};


#endif //AIRPORTMANAGEMENTSYSTEM_PERSON_H
