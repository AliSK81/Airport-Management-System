#include <iostream>
#include "people/pilot.h"
#include "airport.h"
#include "etc/ticket.h"

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

    return 0;
}

// menus ---------------------------------------------------------------------------------------------------------------

void addMenu() {
    cout << "Add Menu:" << endl;
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
    cout << "Remove Menu:" << endl;
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
    cout << "View Menu:" << endl;
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
    cout << "Edit Menu:" << endl;

    cout << "8) Back" << endl;
    int act;
    cin >> act;
}

// add -----------------------------------------------------------------------------------------------------------------

void addPilot() {
    cout << "Enter blow info seperated by space: " << endl;
    cout << "melli-code, name, family, birthDate, personnel-code, employDate, rank" << endl;
    string id, name, family, birthDate, pCode, employDate; int rank;
    cin >> id >> name >> family >> birthDate >> pCode >> employDate >> rank;
    ap->addPilot(pilot(id, name, family, birthDate, pCode, employDate, rank));
    cout << "new pilot added" << endl;
}

void addHost() {
    cout << "Enter blow info seperated by space: " << endl;
    cout << "id, name, family, birthDate, pCode, employDate" << endl;
    string id, name, family, birthDate, pCode, employDate;
    cin >> id >> name >> family >> birthDate >> pCode >> employDate;
    ap->addHost(host(id, name, family, birthDate, pCode, employDate));
    cout << "new host added" << endl;
}

void addTicket() {
    cout << "Enter blow info seperated by space: " << endl;
    cout << "flightSerial, flightDate, flightTime, origin, dest, passengerName, passengerFamily,"
            " passengerId, planeSerial, pilotPId, carrierId, ticketPrice, profitRate" << endl;
    string flightSerial, flightDate, flightTime, origin, dest, passengerName,
            passengerFamily, passengerId, planeSerial, pilotPId, carrierId;
    double ticketPrice, profitRate;
    cin >> flightSerial >> flightDate >> flightTime >> origin >> dest >> passengerName >> passengerFamily >>
        passengerId >> planeSerial >> pilotPId >> carrierId >> ticketPrice >> profitRate;
    ap->addTicket(ticket(flightSerial, flightDate, flightTime, origin, dest, passengerName,passengerFamily,
                         passengerId, planeSerial, pilotPId, carrierId, ticketPrice, profitRate));
    cout << "new ticket added" << endl;
}

void addFlight() {
    cout << "Enter blow info seperated by space: " << endl;
    cout << "flightSerial,  planeSerial, origin, dest,flightDate, flightTime, numOfPassengers, pilot pCode, ticketsIncome" << endl;
    string flightSerial,  planeSerial, origin, dest,flightDate, flightTime;
    int numOfPassengers; pilot *p = nullptr; double ticketsIncome;
    string pilot_pCode; // TODO get pilot by id from ap
    cin >> flightSerial >>  planeSerial >> origin >> dest >> flightDate >>
    flightTime >> numOfPassengers >> pilot_pCode >> ticketsIncome;
    ap->addFlight(flight(flightSerial, planeSerial, origin, dest,flightDate, flightTime, numOfPassengers, *ap->getPilot(pilot_pCode), ticketsIncome));
    cout << "new flight added" << endl;
}

void addCarrier() {
    cout << "Enter blow info seperated by space: " << endl;
    cout << "serial, buildDate";
    string serial, buildDate;
    cin >> serial >> buildDate;
    ap->addCarrier(carrier(serial, buildDate));
    cout << "new carrier added" << endl;
}

void addPlane() {
    string serial, buildDate; int numOfSeats;
    cin >> serial >> buildDate >> numOfSeats;
    ap->addPlane(plane(serial , buildDate, numOfSeats));
    cout << "new plane added" << endl;
}

// remove --------------------------------------------------------------------------------------------------------------

void removePilot(){
    string pCode;
    cout << "Enter personnel code: ";
    cin >> pCode;
    if(ap->removePilot(pCode)) cout << "pilot removed\n"; else cout << "wrong id\n";
}

void removeHost(){
    string pCode;
    cout << "Enter personnel code: ";
    cin >> pCode;
    if(ap->removeHost(pCode)) cout << "host removed\n"; else cout << "wrong id\n";
}

void removeCarrier(){
    string serial;
    cout << "Enter serial: ";
    cin >> serial;
    if(ap->removeCarrier(serial)) cout << "carrier removed\n"; else cout << "wrong id\n";
}

void removePlane() {
    string serial;
    cout << "Enter serial: ";
    cin >> serial;
    if(ap->removePlane(serial)) cout << "plane removed\n"; else cout << "wrong id\n";
}

void removeTicket(){
    string flightSerial;
    cout << "Enter flight serial: ";
    cin >> flightSerial;
    if(ap->removeTicket(flightSerial)) cout << "ticket removed\n"; else cout << "wrong id\n";
}

void removeFlight(){
    string flightSerial;
    cout << "Enter flight serial: ";
    cin >> flightSerial;
    if(ap->removeFlight(flightSerial)) cout << "flight removed\n"; else cout << "wrong id\n";
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

