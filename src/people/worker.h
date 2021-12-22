#ifndef AIRPORTMANAGEMENTSYSTEM_WORKER_H
#define AIRPORTMANAGEMENTSYSTEM_WORKER_H

#include "person.h"
#include <vector>

class flight;

class worker : public person {
private:
    string pCode;
    string employDate;
    vector<flight *> tasks;

public:
    worker(const string &id, const string &name, const string &family, const string &birthDate, const string &pCode,
           const string &employDate);

    worker() = default;

    const string &getEmployDate() const;

    const vector<flight *> &getTasks() const;

    void addTask(flight *task);

    void removeTask(flight *task);

    const string &getPCode() const;

    void printInfo() const;

    virtual string getType() const = 0;

    void setEmployDate(const string &employDate);

    virtual void out(ostream &os) const {
        person::out(os);
        os << ' ' + pCode + ' ' + employDate;
    }

    virtual void in(istream &is) {
        person::in(is);
        is >> pCode >> employDate;
    }
};


#endif //AIRPORTMANAGEMENTSYSTEM_WORKER_H
