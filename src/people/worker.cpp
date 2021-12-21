#include "worker.h"
#include "../airport.h"
#include <algorithm>
#include <iostream>

worker::worker(const string &id, const string &name, const string &family, const string &birthDate, const string &pCode,
               const string &employDate) : person(id, name, family, birthDate), pCode(pCode), employDate(employDate) {}

const string &worker::getPCode() const {
    return pCode;
}

const string &worker::getEmployDate() const {
    return employDate;
}

const vector<flight *> &worker::getTasks() const {
    return tasks;
}

void worker::addTask(flight *task) {
    tasks.push_back(task);
}

void worker::removeTask(flight *task) {
//    airport::removeElement(tasks, task);
    tasks.erase(remove(tasks.begin(), tasks.end(), task), tasks.end());

}

void worker::printInfo() const {
    person::printInfo();
    cout << "personnel-code: " << pCode + ", " << "employDate: " << employDate << ", tasks: " << tasks.size() << endl;
}

void worker::setEmployDate(const string &employDate) {
    worker::employDate = employDate;
}
