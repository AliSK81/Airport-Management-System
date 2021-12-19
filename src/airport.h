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
    vector<pilot> pilots;
    vector<host> hosts;
    vector<passenger> passengers;
    vector<ticket> tickets;
    vector<flight> flights;
    vector<carrier> carriers;
    vector<plane> planes;


public:

    void addPilot(const pilot &p);

    void addHost(const host &h);

    void addPassenger(const passenger &p);

    void addTicket(const ticket &t);

    void addFlight(const flight &f);

    void addCarrier(const carrier &c);

    void addPlane(const plane &p);

    // --------------------------------

    bool removePilot(const string& pCode);

    bool removeHost(const string& pCode);

//    void removePassenger(const passenger &p);

    bool removeTicket(const string& flightSerial);

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

    flight* getFlight(string &serial);

    pilot* getPilot(string &pCode);


};


#endif //AIRPORTMANAGEMENTSYSTEM_AIRPORT_H
