#include <iostream>
#include <iterator>
#include "people/pilot.h"
#include "airport.h"
#include "etc/ticket.h"
#include <sstream>

using namespace std;

airport *ap;

void addMenu(), addPilot(), addTicket(), addHost(), addFlight(), addCarrier(), addPlane();

void removeMenu(), removePilot(), removeTicket(), removeHost(), removeFlight(), removeCarrier(), removePlane();

void viewMenu(), viewFlights_byDate(), viewVehicleTasks_bySerial(), viewWorkersTask_byPCode(), viewPersonInfo_byId();

void editMenu(), editPilot(), editTicket(), editHost(), editFlight(), editCarrier(), editPlane();


int main() {

    cout << "Welcome to Airport Management System" << endl;

    ap = new airport();

    // load project from files
    ap->loadProject();

    // main menu

    while (true) {

        cout << "Menu:" << endl;

        cout << "1) Add item to airport" << endl;
        cout << "2) Remove from airport" << endl;
        cout << "3) View airport reports" << endl;
        cout << "4) Edit items information" << endl;
        cout << "5) Save data & Exit" << endl;

        int act;
        cin >> act;

        switch (act) {
            case 1:
                addMenu();
                break;
            case 2:
                removeMenu();
                break;
            case 3:
                viewMenu();
                break;
            case 4:
                editMenu();
                break;
            case 5: {
                ap->saveProject();
                exit(0);
            }
        }

    }

}

// menus ---------------------------------------------------------------------------------------------------------------

void addMenu() {
    cout << "\nAdd Menu:" << endl;
    cout << "1) Add pilot" << endl;
    cout << "2) Add ticket" << endl;
    cout << "3) Add host" << endl;
    cout << "4) Add flight" << endl;
    cout << "5) Add carrier" << endl;
    cout << "6) Add plane" << endl;
    cout << "7) Back" << endl;

    int act;
    cin >> act;


    switch (act) {
        case 1:
            addPilot();
            break;
        case 2:
            addTicket();
            break;
        case 3:
            addHost();
            break;
        case 4:
            addFlight();
            break;
        case 5:
            addCarrier();
            break;
        case 6:
            addPlane();
            break;
        case 7:
            return;
    }

    addMenu();
}

void removeMenu() {
    cout << "\nRemove Menu:" << endl;
    cout << "1) Remove pilot" << endl;
    cout << "2) Remove ticket" << endl;
    cout << "3) Remove host" << endl;
    cout << "4) Remove flight" << endl;
    cout << "5) Remove carrier" << endl;
    cout << "6) Remove plane" << endl;
    cout << "7) Back" << endl;

    int act;
    cin >> act;

    switch (act) {
        case 1:
            removePilot();
            break;
        case 2:
            removeTicket();
            break;
        case 3:
            removeHost();
            break;
        case 4:
            removeFlight();
            break;
        case 5:
            removeCarrier();
            break;
        case 6:
            removePlane();
            break;
        case 7:
            return;
    }

    removeMenu();
}

void viewMenu() {
    cout << "\nView Menu:" << endl;
    cout << "1) View tasks by date" << endl;
    cout << "2) View people (sorted by birth date)" << endl;
    cout << "3) View workers (sorted by family)" << endl;
    cout << "4) View tasks (sorted by flight serial)" << endl;
    cout << "5) View vehicle tasks by serial" << endl;
    cout << "6) View workers task by personnel code" << endl;
    cout << "7) View person information by melli code" << endl;
    cout << "8) Back" << endl;

    int act;
    cin >> act;

    switch (act) {
        case 1:
            viewFlights_byDate();
            break;
        case 2:
            ap->viewPeople_sortedByBirthdate();
            break;
        case 3:
            ap->viewWorkers_sortedByFamily();
            break;
        case 4:
            ap->viewFlights_sortedBySerial();
            break;
        case 5:
            viewVehicleTasks_bySerial();
            break;
        case 6:
            viewWorkersTask_byPCode();
            break;
        case 7:
            viewPersonInfo_byId();
            break;
        case 8:
            return;
    }

    viewMenu();
}

void editMenu() {
    cout << "\nEdit Menu:" << endl;
    cout << "1) Edit pilot" << endl;
    cout << "2) Edit ticket" << endl;
    cout << "3) Edit host" << endl;
    cout << "4) Edit flight" << endl;
    cout << "5) Edit carrier" << endl;
    cout << "6) Edit plane" << endl;
    cout << "7) Back" << endl;

    int act;
    cin >> act;

    switch (act) {
        case 1:
            editPilot();
            break;
        case 2:
            editTicket();
            break;
        case 3:
            editHost();
            break;
        case 4:
            editFlight();
            break;
        case 5:
            editCarrier();
            break;
        case 6:
            editPlane();
            break;
        case 7:
            return;
    }

    editMenu();
}

// add -----------------------------------------------------------------------------------------------------------------

void addPilot() {
    cout << "Enter blow info seperated by space: " << endl;
    cout << "melli-code, name, family, birthDate, personnel-code, employDate, rank" << endl;
    string id, name, family, birthDate, pCode, employDate;
    int rank;
    cin >> id >> name >> family >> birthDate >> pCode >> employDate >> rank;
    ap->addPilot(new pilot(id, name, family, birthDate, pCode, employDate, rank));
    cout << "new pilot added" << endl;
}

void addHost() {
    cout << "Enter blow info seperated by space: " << endl;
    cout << "melli-code, name, family, birthDate, personnel-code, employDate" << endl;
    string id, name, family, birthDate, pCode, employDate;
    cin >> id >> name >> family >> birthDate >> pCode >> employDate;
    ap->addHost(new host(id, name, family, birthDate, pCode, employDate));
    cout << "new host added" << endl;
}

void addTicket() {
    cout << "Enter blow info seperated by space: " << endl;
    cout << "flightSerial, carrierId, ticketPrice, profitRate" << endl;
    string flightSerial,
            passengerName, passengerFamily, passengerId, passengerFatherName, passengerBirthDate,
            carrierId;
    double ticketPrice, profitRate;
    cin >> flightSerial >> carrierId >> ticketPrice >> profitRate;

    flight *f = ap->getFlight(flightSerial);
    if (f == nullptr) {
        cout << "wrong flightSerial" << endl;
        return;
    }
    carrier *c = ap->getCarrier(carrierId);
    if (c == nullptr) {
        cout << "wrong carrierId" << endl;
        return;
    }
    cout << "Enter blow info seperated by space: " << endl;
    cout << "passengerName, passengerFamily, passengerId, passengerFatherName, passengerBirthDate" << endl;
    cin >> passengerName >> passengerFamily >> passengerId >> passengerFatherName >> passengerBirthDate;

    passenger *p = new passenger(passengerId, passengerName, passengerFamily,
                                 passengerBirthDate, passengerFatherName);

    f->setTicketsIncome(f->getTicketsIncome() + ticketPrice);

    auto *t = new ticket(flightSerial, f->getFlightDate(), f->getFlightTime(),
                         f->getOrigin(), f->getDest(), passengerName, passengerFamily,
                         passengerId, f->getPlaneSerial(), f->getPilot()->getId(), carrierId, ticketPrice, profitRate);

    c->addTask(t);
    ap->addTicket(t);
    f->addPassenger(p);
    ap->addPassenger(p);
    cout << "new ticket added" << endl;
}

void addFlight() {
    cout << "Enter blow info seperated by space: " << endl;
    cout << "flightSerial, planeSerial, origin, dest, flightDate, flightTime, pilot personnel-code" << endl;
    string flightSerial, planeSerial, origin, dest, flightDate, flightTime, pilot_pCode;
    cin >> flightSerial >> planeSerial >> origin >> dest >> flightDate >> flightTime >> pilot_pCode;

    plane *pl = ap->getPlane(planeSerial);
    if (pl == nullptr) {
        cout << "wrong plane serial" << endl;
        return;
    }
    pilot *p = ap->getPilot(pilot_pCode);
    if (p == nullptr) {
        cout << "wrong pilot personnel-code" << endl;
        return;
    }
    auto *f = new flight(flightSerial, planeSerial, origin, dest, flightDate, flightTime, p);

    string line;
    cout << "Enter hosts [personnel-code] seperated by space:" << endl;
    cin.ignore();
    getline(cin, line);
    // split Ids into vector
    stringstream hid(line);
    istream_iterator<string> begin(hid);
    istream_iterator<string> end;
    vector<string> hostsPCode(begin, end);
    for (const string &pCode: hostsPCode) {
        host *h = ap->getHost(pCode);
        if (h != nullptr) {
            f->addHost(h);
            h->addTask(f);
        } else {
            cout << "a host not found (personnel-code: " + pCode + ")\n";
        }
    }
    pl->addTask(f);
    p->addTask(f);

    ap->addFlight(f);
    cout << "new flight added" << endl;
}

void addCarrier() {
    cout << "Enter blow info seperated by space: " << endl;
    cout << "serial, buildDate" << endl;
    string serial, buildDate;
    cin >> serial >> buildDate;
    ap->addCarrier(new carrier(serial, buildDate));
    cout << "new carrier added" << endl;
}

void addPlane() {
    cout << "Enter blow info seperated by space: " << endl;
    cout << "serial, buildDate, numOfSeats" << endl;
    string serial, buildDate;
    int numOfSeats;
    cin >> serial >> buildDate >> numOfSeats;
    ap->addPlane(new plane(serial, buildDate, numOfSeats));
    cout << "new plane added" << endl;
}

// remove --------------------------------------------------------------------------------------------------------------

void removePilot() {
    string pCode;
    cout << "Enter personnel-code: ";
    cin >> pCode;
    pilot *p = ap->getPilot(pCode);
    if (p != nullptr) {
        ap->removePilot(p);
        cout << "pilot removed\n";
    } else {
        cout << "wrong id\n";
    }
}

void removeHost() {
    string pCode;
    cout << "Enter personnel-code: ";
    cin >> pCode;
    host *h = ap->getHost(pCode);
    if (h != nullptr) {
        ap->removeHost(h);
        cout << "host removed\n";
    } else {
        cout << "wrong id\n";
    }
}

void removeCarrier() {
    string serial;
    cout << "Enter serial: ";
    cin >> serial;
    carrier *c = ap->getCarrier(serial);
    if (c != nullptr) {
        ap->removeCarrier(c);
        cout << "carrier removed\n";
    } else {
        cout << "wrong id\n";
    }
}

void removePlane() {
    string serial;
    cout << "Enter serial: ";
    cin >> serial;
    plane *p = ap->getPlane(serial);
    if (p != nullptr) {
        ap->removePlane(p);
        cout << "plane removed\n";
    } else {
        cout << "wrong id\n";
    }
}

void removeTicket() {
    string passengerId;
    cout << "Enter passenger id: ";
    cin >> passengerId;
    ticket *t = ap->getTicket(passengerId);
    if (t != nullptr) {
        ap->removeTicket(t);
        cout << "ticket removed\n";
    } else {
        cout << "wrong id\n";
    }
}

void removeFlight() {
    string flightSerial;
    cout << "Enter flight serial: ";
    cin >> flightSerial;
    flight *f = ap->getFlight(flightSerial);
    if (f != nullptr) {
        ap->removeFlight(f);
        cout << "flight removed\n";
    } else {
        cout << "wrong id\n";
    }
}

// view ----------------------------------------------------------------------------------------------------------------


void viewFlights_byDate() {
    string date;
    cout << "Enter date: ";
    cin >> date;
    ap->viewFlights_byDate(date);
}

void viewVehicleTasks_bySerial() {
    string serial;
    cout << "Enter vehicle serial: ";
    cin >> serial;
    ap->viewVehicleTasks_bySerial(serial);
}

void viewWorkersTask_byPCode() {
    string pCode;
    cout << "Enter personnel code: ";
    cin >> pCode;
    ap->viewWorkersTask_byPCode(pCode);
}

void viewPersonInfo_byId() {
    string id;
    cout << "Enter melli code code: ";
    cin >> id;
    ap->viewPersonInfo_byId(id);
}


// edit ----------------------------------------------------------------------------------------------------------------

void editPilot() {
    string pCode;
    cout << "Enter personnel-code: ";
    cin >> pCode;
    pilot *p = ap->getPilot(pCode);
    if (p == nullptr) {
        cout << "wrong id" << endl;
        return;
    }
    cout << "Enter blow info seperated by space: " << endl;
    cout << "name, family, birthDate, employDate, rank" << endl;
    string name, family, birthDate, employDate;
    int rank;
    cin >> name >> family >> birthDate >> employDate >> rank;
    p->setName(name);
    p->setFamily(family);
    p->setBirthDate(birthDate);
    p->setEmployDate(employDate);
    p->setRank(rank);
    cout << "edited" << endl;
}

void editTicket() {
    string passengerId;
    cout << "Enter passenger id: ";
    cin >> passengerId;
    ticket *t = ap->getTicket(passengerId);
    if (t == nullptr) {
        cout << "wrong id" << endl;
        return;
    }
    cout << "Enter blow info seperated by space: " << endl;
    cout << "ticketPrice, profitRate" << endl;
    double ticketPrice, profitRate;
    cin >> ticketPrice >> profitRate;
    t->setTicketPrice(ticketPrice);
    t->setProfitRate(profitRate);
    cout << "edited" << endl;
}

void editHost() {
    string pCode;
    cout << "Enter personnel code: ";
    cin >> pCode;
    host *h = ap->getHost(pCode);
    if (h == nullptr) {
        cout << "wrong id" << endl;
        return;
    }
    cout << "Enter blow info seperated by space: " << endl;
    cout << "name, family, birthDate, employDate" << endl;
    string name, family, birthDate, employDate;
    cin >> name >> family >> birthDate >> employDate;
    h->setName(name);
    h->setFamily(family);
    h->setBirthDate(birthDate);
    h->setEmployDate(employDate);
    cout << "edited" << endl;
}

void editFlight() {
    string flightSerial;
    cout << "Enter flight serial: ";
    cin >> flightSerial;
    flight *f = ap->getFlight(flightSerial);
    if (f == nullptr) {
        cout << "wrong id" << endl;
        return;
    }
    cout << "Enter blow info seperated by space: " << endl;
    cout << "origin, dest, flightDate, flightTime" << endl;
    string origin, dest, flightDate, flightTime;
    cin >> origin >> dest >> flightDate >> flightTime;
    f->setOrigin(origin);
    f->setDest(dest);
    f->setFlightDate(flightDate);
    f->setFlightTime(flightTime);
    cout << "edited" << endl;
}

void editCarrier() {
    string serial, buildDate;
    cout << "Enter serial: ";
    cin >> serial;
    carrier *c = ap->getCarrier(serial);
    if (c == nullptr) {
        cout << "wrong id" << endl;
        return;
    }
    cout << "Enter buildDate: ";
    cin >> buildDate;
    c->setBuildDate(buildDate);
    cout << "edited" << endl;
}

void editPlane() {
    string serial, buildDate;
    cout << "Enter serial: ";
    cin >> serial;
    plane *p = ap->getPlane(serial);
    if (p == nullptr) {
        cout << "wrong id" << endl;
        return;
    }
    cout << "Enter blow info seperated by space: " << endl;
    cout << "buildDate, numOfSeats" << endl;
    int numOfSeats;
    cin >> buildDate >> numOfSeats;
    p->setBuildDate(buildDate);
    p->setNumOfSeats(numOfSeats);
    cout << "edited" << endl;
}