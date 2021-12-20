#ifndef AIRPORTMANAGEMENTSYSTEM_AIRPORT_H
#define AIRPORTMANAGEMENTSYSTEM_AIRPORT_H

#include <vector>
#include "people/passenger.h"
#include "people/pilot.h"
#include "people/host.h"
#include "etc/ticket.h"
#include "etc/flight.h"
#include "vehicles/carrier.h"
#include "vehicles/plane.h"
#include "people/person.h"
using namespace std;

class airport {
private:
    vector<pilot *> pilots;
    vector<host *> hosts;
    vector<passenger *> passengers;
    vector<ticket *> tickets;
    vector<flight *> flights;
    vector<carrier *> carriers;
    vector<plane *> planes;


public:

    void addPilot(pilot *p);

    void addHost(host *h);

    void addPassenger(passenger *p);

    void addTicket(ticket *t);

    void addFlight(flight *f);

    void addCarrier(carrier *c);

    void addPlane(plane *p);

    // --------------------------------

    bool removePilot(const string& pCode);

    bool removeHost(const string& pCode);

//    void removePassenger(const passenger &p);

    bool removeTicket(const string &passengerId);

    bool removeFlight(string &flightSerial);

    bool removeCarrier(string &serial);

    bool removePlane(string &serial);

    // --------------------------------

    void viewFlights_byDate(string &date);

    void viewPeople_sortedByBirthdate();

    void viewWorkers_sortedByFamily();

    void viewFlights_sortedBySerial();

    void viewVehicleTasks_bySerial(string &serial);

    void viewWorkersTask_byPCode(string &pCode);

    void viewPersonInfo_byId(string &id);

    // --------------------------

    flight *getFlight(string &serial);

    pilot *getPilot(const string &pCode);


    host *getHost(const string &pCode);

    passenger *getPassenger(string &id);

    plane *getPlane(const string &serial);

    ticket *getTicket(const string &passengerId);

    carrier *getCarrier(const string &serial);


    template<typename T>
    static void removeElement(vector<T> &v, T e);
};


#endif //AIRPORTMANAGEMENTSYSTEM_AIRPORT_H
