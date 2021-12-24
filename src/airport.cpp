#include <iostream>
#include "airport.h"
#include "vehicles/plane.h"
#include <algorithm>
#include <fstream>
#include <memory>
#include <fileapi.h>


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

// remove host -> remove host from related tasks(flights)
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
    getPlane(f->getPlaneSerial())->removeTask(f);
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
    if (!found) {
        cout << "no flights" << endl;
    }
}

void airport::viewPeople_sortedByBirthdate() {
    vector<person *> people;
    people.insert(people.end(), pilots.begin(), pilots.end());
    people.insert(people.end(), hosts.begin(), hosts.end());
    people.insert(people.end(), passengers.begin(), passengers.end());

    if (!people.empty()) {
        cout << "people:" << endl;
        sort(people.begin(), people.end(), person::compareBirthDate);
        for (const person *p: people) {
            p->printInfo();
        }
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
        for (const worker *p: workers) {
            p->printInfo();
        }
    } else {
        cout << "no workers" << endl;
    }
}

void airport::viewFlights_sortedBySerial() {
    if (!flights.empty()) {
        cout << "flights:" << endl;
        sort(flights.begin(), flights.end(), flight::compareSerial);
        for (const flight *f: flights) {
            f->printInfo();
        }
    } else {
        cout << "no flights" << endl;
    }
}

void airport::viewVehicleTasks_bySerial(string &serial) {
    for (const plane *p: planes) {
        if (p->getSerial() == serial) {
            p->printInfo();
            for (flight *task: p->getTasks()) {
                task->printInfo();
            }
            if (p->getTasks().empty()) {
                cout << "no tasks" << endl;
            }
            return;
        }
    }
    for (const carrier *c: carriers) {
        if (c->getSerial() == serial) {
            c->printInfo();
            for (ticket *task: c->getTasks()) {
                task->printInfo();
            }
            if (c->getTasks().empty()) {
                cout << "no tasks" << endl;
            }
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
            for (const flight *task: w->getTasks()) {
                task->printInfo();
            }
            if (w->getTasks().empty()) {
                cout << "no tasks" << endl;
            }
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

template<typename T>
void airport::readFile(vector<T *> &v, string path) {
    ifstream fin;
    fin.open(path, ios::app);
    if (!fin) {
        cerr << "Error in opening file" << endl;
        exit(1);
    }
    while (true) {
        T *obj = new T();
        fin >> *obj;
        if (fin.eof()) break;
        v.push_back(obj);
    }
    fin.close();
}

template<typename T>
void airport::saveToFile(vector<T *> &v, string path) {
    fstream file;
    file.open(path, ios::out);
    if (!file) {
        cerr << "Error in opening file" << endl;
        exit(3);
    }
    for (T *obj: v) {
        file << *obj;
    }
    file.close();
}

void airport::loadProject() {
    readFile(pilots, "pilots.txt");
    readFile(hosts, "hosts.txt");
    readFile(passengers, "passengers.txt");
    readFile(planes, "planes.txt");
    readFile(carriers, "carriers.txt");
    readFile(tickets, "tickets.txt");
    readFile(flights, "flights.txt");

    loadTasks();
}

void airport::saveProject() {
    saveToFile(pilots, "pilots.txt");
    saveToFile(hosts, "hosts.txt");
    saveToFile(passengers, "passengers.txt");
    saveToFile(planes, "planes.txt");
    saveToFile(carriers, "carriers.txt");
    saveToFile(tickets, "tickets.txt");
    saveToFile(flights, "flights.txt");

    saveTasks();
}


// save tasks to file
// how it works:
// read Ids and search them in vectors

void airport::saveTasks() {
    fstream file;
    file.open("tasks.txt", ios::out);
    if (!file) {
        cerr << "Error in opening file" << endl;
        exit(3);
    }

    for (flight *f: flights) {

        file << "flight " << f->getFlightSerial()
             << " pilot " << f->getPilot()->getPCode()
             << " plane " << f->getPlaneSerial()
             << " hosts";

        for (host *h: f->getHosts()) {
            file << " " << h->getPCode();
        }
        file << " passengers";
        for (passenger *p: f->getPassengers()) {
            file << " " << p->getId();
        }
        file << " end\n";
    }
    for (carrier *c: carriers) {
        file << "carrier " << c->getSerial()
             << " tickets";
        for (ticket *t: c->getTasks()) {
            file << " " << t->getPassengerId();
        }
        file << " end\n";
    }

    file.close();
}


// read tasks from file

void airport::loadTasks() {
    ifstream file;
    file.open("tasks.txt", ios::app);

    if (!file) {
        cerr << "Error in opening file" << endl;
        exit(3);
    }

    while (!file.eof()) {

        string type;
        file >> type;

        if (type == "flight") {

            string tmp, flightSerial, pilotPCode, planeSerial, hostPCode, passengerId;

            file >> flightSerial >> tmp >> pilotPCode >> tmp >> planeSerial >> tmp;

            // search in vectors by Ids
            flight *f = getFlight(flightSerial);
            pilot *pi = getPilot(pilotPCode);
            plane *pl = getPlane(planeSerial);

            pi->addTask(f);         // add flight to pilot tasks
            f->setPilot(pi);             // set flight pilot
            pl->addTask(f);       // add flight to plane tasks

            // read hosts Ids
            while (true) {
                file >> hostPCode;
                if (hostPCode == "passengers") break;
                host *h = getHost(hostPCode);
                h->addTask(f);      // add flight to host tasks
                f->addHost(h);           // add host to list of hosts of flight
            }

            // read passengers Ids
            while (true) {
                file >> passengerId;
                if (passengerId == "end") break;
                passenger *pass = getPassenger(passengerId);
                f->addPassenger(pass);  // add passenger to list of passengers of flight
            }

            // read carriers tasks (tickets Ids)
        } else if (type == "carrier") {

            string tmp, carrierSerial, passengerId;
            file >> carrierSerial >> tmp;
            carrier *c = getCarrier(carrierSerial);     // search carrier in vector

            while (true) {
                file >> passengerId;
                if (passengerId == "end") break;
                ticket *t = getTicket(passengerId);
                c->addTask(t);      // add ticket to carrier tasks
            }
        }
    }

    file.close();
}
