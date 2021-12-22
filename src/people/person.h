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

    person() = default;

    const string &getId() const;

    static bool compareBirthDate(const person *p1, const person *p2);

    static bool compareFamily(const person *p1, const person *p2);

    virtual void printInfo() const;

    virtual string getType() const = 0;

    void setName(const string &name);

    void setFamily(const string &family);

    void setBirthDate(const string &birthDate);

    virtual void out(ostream &os) const {
        os << id + ' ' + name + ' ' + family + ' ' + birthDate;
    }

    virtual void in(istream &is) {
        is >> id >> name >> family >> birthDate;
    }

    friend ostream &operator<<(ostream &out, const person &p) {
        p.out(out);
        return out;
    }

    friend istream &operator>>(istream &in, person &p) {
        p.in(in);
        return in;
    }

};


#endif //AIRPORTMANAGEMENTSYSTEM_PERSON_H
