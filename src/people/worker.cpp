#include "worker.h"

worker::worker(const string &id, const string &name, const string &family, const string &birthDate, const string &pCode,
               const string &employDate) : person(id, name, family, birthDate), pCode(pCode), employDate(employDate) {}

const string &worker::getPCode() const {
    return pCode;
}

const string &worker::getEmployDate() const {
    return employDate;
}

const list<flight> &worker::getTasks() const {
    return tasks;
}

void worker::addTask(const flight &task) {

}


