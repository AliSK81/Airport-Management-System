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

    const string &getEmployDate() const;

    const vector<flight *> &getTasks() const;

    void addTask(flight *task);

    void removeTask(flight *task);

    const string &getPCode() const;

    void printInfo() const;

    virtual string getType() const = 0;
};


#endif //AIRPORTMANAGEMENTSYSTEM_WORKER_H
