#include <iostream>
#include "airport.h"
#include "vehicles/plane.h"
#include <algorithm>
#include <memory>

using namespace std;

void airport::addPilot(pilot *p) {
    pilots.push_back(p);
}

void airport::addHost(host *h) {
    hosts.push_back(h);
}

void airport::addPassenger(passenger *p) {
    passengers.push_back(p);
}

void airport::addTicket(ticket *t) {
    tickets.push_back(t);
}

void airport::addFlight(flight *f) {
    flights.push_back(f);
}

void airport::addCarrier(carrier *c) {
    carriers.push_back(c);
}

void airport::addPlane(plane *p) {
    planes.push_back(p);
}

bool airport::removePilot(const string &pCode) {
    pilot *p = getPilot(pCode);
    if(p == nullptr || !p->getTasks().empty()) return false;
    removeElement(pilots, getPilot(pCode));
    return true;
}

bool airport::removeHost(const string &pCode) {
    host *h = getHost(pCode);
    if(h == nullptr) return false;
    removeElement(hosts, h);
}

bool airport::removeTicket(const string &passengerId) {
    bool success;
    auto it = remove_if(tickets.begin(), tickets.end(),
                        [passengerId](ticket *t) { return t->getPassengerId() == passengerId; });
    if ((success = it != tickets.end())) {
        tickets.erase(it, tickets.end());
    }
    return success;
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

pilot *airport::getPilot(const string &pCode) {
    for (pilot *p: pilots) {
        if (p->getPCode() == pCode) {
            return p;
        }
    }
    return nullptr;
}

host *airport::getHost(const string &pCode) {
    for (host *h: hosts) {
        if (h->getPCode() == pCode) {
            return h;
        }
    }
    return nullptr;
}

passenger *airport::getPassenger(string &id) {
    for (passenger *p: passengers) {
        if (p->getId() == id) {
            return p;
        }
    }
    return nullptr;
}

flight *airport::getFlight(string &serial) {
    for (flight *f: flights) {
        if (f->getFlightSerial() == serial) {
            return f;
        }
    }
    return nullptr;
}

ticket *airport::getTicket(const string &passengerId) {
    for (ticket *t: tickets) {
        if (t->getPassengerId() == passengerId) {
            return t;
        }
    }
    return nullptr;
}

plane *airport::getPlane(const string &serial) {
    for (plane *p: planes) {
        if (p->getSerial() == serial) {
            return p;
        }
    }
    return nullptr;
}

carrier *airport::getCarrier(const string &serial) {
    for (carrier *c: carriers) {
        if (c->getSerial() == serial) {
            return c;
        }
    }
    return nullptr;
}

void airport::viewFlights_byDate(string &date) {
    for (const flight *f: flights) {
        if (f->getFlightDate() == date) {
            cout << f->getFlightSerial() << endl;
        }
    }
}

void airport::viewPeople_sortedByBirthdate() {
    if (!pilots.empty()) {
        cout << "pilots:" << endl;
        sort(pilots.begin(), pilots.end(), person::compareBirthDate);
        for (const pilot *p: pilots) {
            cout << p->getId() << endl;
        }
    }
    if (!hosts.empty()) {
        cout << "hosts:" << endl;
        sort(hosts.begin(), hosts.end(), person::compareBirthDate);
        for (const host *h: hosts) {
            cout << h->getId() << endl;
        }
    }
    if (!passengers.empty()) {
        cout << "passengers:" << endl;
        sort(passengers.begin(), passengers.end(), person::compareBirthDate);
        for (const passenger *p: passengers) {
            cout << p->getId() << endl;
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
        for (const pilot *p: pilots) {
            cout << p->getId() << endl;
        }
    }
    if (!hosts.empty()) {
        cout << "hosts:" << endl;
        sort(hosts.begin(), hosts.end(), person::compareFamily);
        for (const host *h: hosts) {
            cout << h->getId() << endl;
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
        for (const flight *f: flights) {
            cout << f->getFlightSerial() << endl;
        }
    }
    cout << "no flights";
}

void airport::viewVehicleTasks_bySerial(string &serial) {
    for (const plane *p: planes) {
        if (p->getSerial() == serial) {
            for (flight *task: p->getTasks()) {
                cout << task->getFlightSerial() << endl;
            }
            return;
        }
    }
    for (const carrier *c: carriers) {
        if (c->getSerial() == serial) {
            for (ticket *task: c->getTasks()) {
                cout << task->getFlightSerial() << endl;
            }
            return;
        }
    }
    cout << "no tasks" << endl;
}

void airport::viewWorkersTask_byPCode(string &pCode) {
    for (const pilot *p: pilots) {
        if (p->getPCode() == pCode) {
            for (const flight *task: p->getTasks()) {
                cout << task->getFlightSerial() << endl;
            }
            return;
        }
    }
    for (const host *h: hosts) {
        if (h->getPCode() == pCode) {
            for (const flight *task: h->getTasks()) {
                cout << task->getFlightSerial() << endl;
            }
            return;
        }
    }
    cout << "no tasks" << endl;
}

void airport::viewPersonInfo_byId(string &id) {
    for (const host *h: hosts) {
        if (h->getId() == id) {
            cout << h->getId() << endl;
            return;
        }
    }
    for (const passenger *p: passengers) {
        if (p->getId() == id) {
            cout << p->getId() << endl;
            return;
        }
    }
    for (const pilot *p: pilots) {
        if (p->getId() == id) {
            cout << p->getId() << endl;
            return;
        }
    }
    cout << "wrong id" << endl;
}

template<typename T>
void airport::removeElement(vector<T>& v, T e) {
    v.erase(remove(v.begin(), v.end(), e), v.end());
}












