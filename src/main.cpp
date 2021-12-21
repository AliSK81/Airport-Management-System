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

void editMenu();


int main() {

    cout << "Welcome to Airport Management System" << endl;

    ap = new airport();

    // main menu

    while (true) {

        cout << "Menu:" << endl;

        cout << "1) Add new object" << endl;
        cout << "2) Remove objects" << endl;
        cout << "3) View reports" << endl;
        cout << "4) Edit information" << endl;
        cout << "5) Exit system" << endl;

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
            case 5:
                exit(0);
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
    cout << "1) View flights by date" << endl;
    cout << "2) View people (sorted by birth date)" << endl;
    cout << "3) View workers (sorted by family)" << endl;
    cout << "4) View flights (sorted by flight serial)" << endl;
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

    cout << "8) Back" << endl;
    int act;
    cin >> act;
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
    cout << "id, name, family, birthDate, pCode, employDate" << endl;
    string id, name, family, birthDate, pCode, employDate;
    cin >> id >> name >> family >> birthDate >> pCode >> employDate;
    ap->addHost(new host(id, name, family, birthDate, pCode, employDate));
    cout << "new host added" << endl;
}

void addTicket() {
    cout << "Enter blow info seperated by space: " << endl;
    cout << "flightSerial, planeSerial, pilotPId, carrierId, ticketPrice, profitRate" << endl;
    string flightSerial, passengerName, passengerFamily, passengerId,
            passengerFatherName, passengerBirthDate, planeSerial, pilotPId, carrierId;
    double ticketPrice, profitRate;
    cin >> flightSerial >> planeSerial >> pilotPId >> carrierId >> ticketPrice >> profitRate;

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
    f->setTicketsIncome(f->getTicketsIncome() + ticketPrice);

    auto *t = new ticket(flightSerial, f->getFlightDate(), f->getFlightTime(),
                         f->getOrigin(), f->getDest(), passengerName, passengerFamily,
                         passengerId, planeSerial, pilotPId, carrierId, ticketPrice, profitRate);

    c->addTask(t);
    ap->addTicket(t);

    cout << "Enter blow info seperated by space: " << endl;
    cout << "passengerName, passengerFamily, passengerId, passengerFatherName, passengerBirthDate" << endl;
    cin >> passengerName >> passengerFamily >> passengerId >> passengerFatherName >> passengerBirthDate;

    passenger *p = new passenger(passengerId, passengerName, passengerFamily,
                                 passengerBirthDate, passengerFatherName);
    f->addPassenger(p);
    ap->addPassenger(p);

    cout << "new ticket added" << endl;
}

void addFlight() {
    cout << "Enter blow info seperated by space: " << endl;
    cout << "flightSerial,  planeSerial, origin, dest,flightDate, flightTime, pilot personnel-code" << endl;
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
    cin >> line;
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
            cout << "a host not found (personnel-code: " + pCode + ")";
        }
    }
    pl->addFlight(f);
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
    cout << "Enter personnel code: ";
    cin >> pCode;
    if (ap->removePilot(pCode)) cout << "pilot removed\n"; else cout << "wrong id\n";
}

void removeHost() {
    string pCode;
    cout << "Enter personnel code: ";
    cin >> pCode;
    if (ap->removeHost(pCode)) cout << "host removed\n"; else cout << "wrong id\n";
}

void removeCarrier() {
    string serial;
    cout << "Enter serial: ";
    cin >> serial;
    if (ap->removeCarrier(serial)) cout << "carrier removed\n"; else cout << "wrong id\n";
}

void removePlane() {
    string serial;
    cout << "Enter serial: ";
    cin >> serial;
    if (ap->removePlane(serial)) cout << "plane removed\n"; else cout << "wrong id\n";
}

void removeTicket() {
    string passengerId;
    cout << "Enter passenger id: ";
    cin >> passengerId;
    if (ap->removeTicket(passengerId)) cout << "ticket removed\n"; else cout << "wrong id\n";
}

void removeFlight() {
    string flightSerial;
    cout << "Enter flight serial: ";
    cin >> flightSerial;
    if (ap->removeFlight(flightSerial)) cout << "flight removed\n"; else cout << "wrong id\n";
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


// --------------------------------------