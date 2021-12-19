#include <iostream>
#include "airport.h"
#include "vehicles/plane.h"
#include <algorithm>
#include <memory>

using namespace std;

void airport::addPilot(const pilot &p) {
    pilots.push_back(p);
}

void airport::addHost(const host &h) {
    hosts.push_back(h);
}

void airport::addPassenger(const passenger &p) {
    passengers.push_back(p);
}

void airport::addTicket(const ticket &t) {
    tickets.push_back(t);
}

void airport::addFlight(const flight &f) {
    flights.push_back(f);
}

void airport::addCarrier(const carrier &c) {
    carriers.push_back(c);
}

void airport::addPlane(const plane &p) {
    planes.push_back(p);
}

bool airport::removePilot(const string &pCode) {
    return false;
}

bool airport::removeHost(const string &pCode) {
    return false;
}

bool airport::removeTicket(const string &flightSerial) {
    return false;
}

bool airport::removeFlight(string &flightSerial) {
    return false;
}

bool airport::removeCarrier(string &serial) {
    return false;

}

bool airport::removePlane(string &serial) {
    return false;
}

pilot *airport::getPilot(string &pCode) {
    for (pilot &p: pilots) {
        if (p.getPCode() == pCode) {
            return &p;
        }
    }
    return nullptr;
}

flight *airport::getFlight(string &serial) {
    for (flight &f: flights) {
        if (f.getFlightSerial() == serial) {
            return &f;
        }
    }
    return nullptr;
}

void airport::viewFlights_byDate(string &date) {
    for (const flight &f: flights) {
        if (f.getFlightDate() == date) {
            cout << f.getFlightSerial() << endl;
        }
    }
}

void airport::viewPeople_sortedByBirthdate() {
    if (!pilots.empty()) {
        cout << "pilots:" << endl;
        sort(pilots.begin(), pilots.end(), person::compareBirthDate);
        for (const pilot &p: pilots) {
            cout << p.getId() << endl;
        }
    }
    if (!hosts.empty()) {
        cout << "hosts:" << endl;
        sort(hosts.begin(), hosts.end(), person::compareBirthDate);
        for (const host &h: hosts) {
            cout << h.getId() << endl;
        }
    }
    if (!passengers.empty()) {
        cout << "passengers:" << endl;
        sort(passengers.begin(), passengers.end(), person::compareBirthDate);
        for (const passenger &p: passengers) {
            cout << p.getId() << endl;
        }
    }
    if (pilots.empty() && hosts.empty() && passengers.empty()) {
        cout << "no people" << endl;
    }
}

void airport::viewWorkers_sortedByFamily() {
    if (!pilots.empty()) {
        cout << "pilots:" << endl;
        sort(pilots.begin(), pilots.end(), person::compareFamily);
        for (const pilot &p: pilots) {
            cout << p.getId() << endl;
        }
    }
    if (!hosts.empty()) {
        cout << "hosts:" << endl;
        sort(hosts.begin(), hosts.end(), person::compareFamily);
        for (const host &h: hosts) {
            cout << h.getId() << endl;
        }
    }
    if (pilots.empty() && hosts.empty()) {
        cout << "no workers" << endl;
    }
}

void airport::viewFlights_sortedBySerial() {
    if (!flights.empty()) {
        cout << "flights:" << endl;
        sort(flights.begin(), flights.end(), flight::compareSerial);
        for (const flight &f: flights) {
            cout << f.getFlightSerial() << endl;
        }
    }
    cout << "no flights";
}

void airport::viewVehicleTasks_bySerial(string &serial) {
    for (const plane& p: planes) {
        if (p.getSerial() == serial) {
            for (const flight& task: p.getTasks()) {
                cout << task.getFlightSerial() << endl;
            }
            return;
        }
    }
    for (const carrier& c: carriers) {
        if (c.getSerial() == serial) {
            for (const ticket& task: c.getTasks()) {
                cout << task.getFlightSerial() << endl;
            }
            return;
        }
    }
    cout << "no tasks" << endl;
}

void airport::viewWorkersTask_byPCode(string &pCode) {
    for (const pilot& p: pilots) {
        if (p.getPCode() == pCode) {
            for (const flight* task: p.getTasks()) {
                cout << task->getFlightSerial() << endl;
            }
            return;
        }
    }
    for (const host& h: hosts) {
        if (h.getPCode() == pCode) {
            for (const flight* task: h.getTasks()) {
                cout << task->getFlightSerial() << endl;
            }
            return;
        }
    }
    cout << "no tasks" << endl;
}

void airport::viewPersonInfo_byId(string &id) {
    for (const host& h: hosts) {
        if (h.getId() == id) {
            cout << h.getId() << endl;
            return;
        }
    }
    for (const passenger& p: passengers) {
        if (p.getId() == id) {
            cout << p.getId() << endl;
            return;
        }
    }
    for (const pilot& p: pilots) {
        if (p.getId() == id) {
            cout << p.getId() << endl;
            return;
        }
    }
    cout << "wrong id" << endl;
}














