#ifndef AIRPORTMANAGEMENTSYSTEM_WORKER_H
#define AIRPORTMANAGEMENTSYSTEM_WORKER_H
#include "person.h"
#include "../etc/flight.h"
#include "list"

class worker : public person{
private:
    string pCode;
    string employDate;
    list<flight> tasks;

public:
    worker(const string &id, const string &name, const string &family, const string &birthDate, const string &pCode,
           const string &employDate);

    const string &getPCode() const;

    const string &getEmployDate() const;

    const list<flight> &getTasks() const;

    void addTask(const flight &task);

};


#endif //AIRPORTMANAGEMENTSYSTEM_WORKER_H
