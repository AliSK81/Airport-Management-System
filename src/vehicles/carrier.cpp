#include "carrier.h"

carrier::carrier(const string &serial, const string &buildDate) : vehicle(serial, buildDate) {}

void carrier::addTask(const ticket &task) {

}

const vector<ticket> &carrier::getTasks() const {
    return tasks;
}

