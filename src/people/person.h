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

    static bool compareBirthDate(const person *p1, const person *p2);

    static bool compareFamily(const person *p1, const person *p2);

    virtual void printInfo() const;

    virtual string getType() const = 0;

    void setName(const string &name);

    void setFamily(const string &family);

    void setBirthDate(const string &birthDate);

};


#endif //AIRPORTMANAGEMENTSYSTEM_PERSON_H
