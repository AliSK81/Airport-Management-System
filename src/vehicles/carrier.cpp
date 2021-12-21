#include <iostream>
#include "carrier.h"
#include "../airport.h"


carrier::carrier(const string &serial, const string &buildDate) : vehicle(serial, buildDate) {}

void carrier::addTask(ticket *task) {
    tasks.push_back(task);
}

const vector<ticket *> &carrier::getTasks() const {
    return tasks;
}

void carrier::removeTask(ticket *task) {
    airport::removeElement(tasks, task);
//    tasks.erase(remove(tasks.begin(), tasks.end(), task), tasks.end());

}

void carrier::printInfo() const {
    vehicle::printInfo();
    cout << "tasks: " << tasks.size() << endl;
}


