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

// remove pilot -> remove pilot tasks(flights)
void airport::removePilot(pilot *p) {
    for (flight *f: p->getTasks()) {
        removeFlight(f);
    }
    removeElement(pilots, p);
}

// remove pilot -> remove host from related tasks(flights)
void airport::removeHost(host *h) {
    for (flight *f: h->getTasks()) {
        f->removeHost(h);
    }
    removeElement(hosts, h);
}

// remove ticket -> remove related passengers, carrier task & return ticket income
void airport::removeTicket(ticket *t) {
    passenger *p = getPassenger(t->getPassengerId());
    carrier *c = getCarrier(t->getCarrierId());
    flight *f = getFlight(t->getFlightSerial());
    f->removePassenger(p);
    f->setTicketsIncome(f->getTicketsIncome() - t->getTicketPrice());
    c->removeTask(t);
    removeElement(passengers, p);
    removeElement(tickets, t);
}

// remove flight -> remove tickets & passengers; remove tasks of hosts & pilot; remove plane task
void airport::removeFlight(flight *f) {
    for (passenger *p: f->getPassengers()) {
        removeTicket(getTicket(p->getId()));
    }
    for (host *h: f->getHosts()) {
        h->removeTask(f);
    }
    getPlane(f->getPlaneSerial())->removeFlight(f);
    f->getPilot()->removeTask(f);
    removeElement(flights, f);
}

// remove carrier -> remove related tickets
void airport::removeCarrier(carrier *c) {
    for (ticket *t: c->getTasks()) {
        removeTicket(t);
    }
    removeElement(carriers, c);
}

// remove plane -> remove related flights
void airport::removePlane(plane *p) {
    for (flight *f: p->getTasks()) {
        removeFlight(f);
    }
    removeElement(planes, p);
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
        if (h->getPCode() == pCode) return h;
    }
    return nullptr;
}

passenger *airport::getPassenger(const string &id) {
    for (passenger *p: passengers) {
        if (p->getId() == id) return p;
    }
    return nullptr;
}

flight *airport::getFlight(const string &serial) {
    for (flight *f: flights) {
        if (f->getFlightSerial() == serial) return f;
    }
    return nullptr;
}

ticket *airport::getTicket(const string &passengerId) {
    for (ticket *t: tickets) {
        if (t->getPassengerId() == passengerId) return t;
    }
    return nullptr;
}

plane *airport::getPlane(const string &serial) {
    for (plane *p: planes) {
        if (p->getSerial() == serial) return p;
    }
    return nullptr;
}

carrier *airport::getCarrier(const string &serial) {
    for (carrier *c: carriers) {
        if (c->getSerial() == serial) return c;
    }
    return nullptr;
}

void airport::viewFlights_byDate(string &date) {
    bool found = false;
    for (const flight *f: flights) {
        if (f->getFlightDate() == date) {
            f->printInfo();
            found = true;
        }
    }
    if (!found) cout << "no flights" << endl;
}

void airport::viewPeople_sortedByBirthdate() {
    vector<person *> people;
    people.insert(people.end(), pilots.begin(), pilots.end());
    people.insert(people.end(), hosts.begin(), hosts.end());
    people.insert(people.end(), passengers.begin(), passengers.end());

    if (!people.empty()) {
        cout << "people:" << endl;
        sort(people.begin(), people.end(), person::compareBirthDate);
        for (const person *p: people) p->printInfo();
    } else {
        cout << "no people" << endl;
    }
}

void airport::viewWorkers_sortedByFamily() {
    vector<worker *> workers;
    workers.insert(workers.end(), pilots.begin(), pilots.end());
    workers.insert(workers.end(), hosts.begin(), hosts.end());

    if (!workers.empty()) {
        cout << "workers:" << endl;
        sort(workers.begin(), workers.end(), person::compareFamily);
        for (const worker *p: workers) p->printInfo();
    } else {
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
    } else {
        cout << "no flights" << endl;
    }
}

void airport::viewVehicleTasks_bySerial(string &serial) {
    for (const plane *p: planes) {
        if (p->getSerial() == serial) {
            p->printInfo();
            for (flight *task: p->getTasks()) task->printInfo();
            if (p->getTasks().empty()) cout << "no tasks" << endl;
            return;
        }
    }
    for (const carrier *c: carriers) {
        if (c->getSerial() == serial) {
            c->printInfo();
            for (ticket *task: c->getTasks()) task->printInfo();
            if (c->getTasks().empty()) cout << "no tasks" << endl;
            return;
        }
    }
    cout << "wrong id" << endl;
}

void airport::viewWorkersTask_byPCode(string &pCode) {
    vector<worker *> workers;
    workers.insert(workers.end(), pilots.begin(), pilots.end());
    workers.insert(workers.end(), hosts.begin(), hosts.end());
    for (const worker *w: workers) {
        if (w->getPCode() == pCode) {
            for (const flight *task: w->getTasks()) task->printInfo();
            if (w->getTasks().empty()) cout << "no tasks" << endl;
            return;
        }
    }
    cout << "wrong id" << endl;
}

void airport::viewPersonInfo_byId(string &id) {
    vector<person *> people;
    people.insert(people.end(), pilots.begin(), pilots.end());
    people.insert(people.end(), hosts.begin(), hosts.end());
    people.insert(people.end(), passengers.begin(), passengers.end());
    for (const person *p: people) {
        if (p->getId() == id) {
            p->printInfo();
            return;
        }
    }
    cout << "wrong id" << endl;
}

// a template to remove an element from vector
template<typename T>
void airport::removeElement(vector<T> &v, T e) {
    v.erase(remove(v.begin(), v.end(), e), v.end());
}
