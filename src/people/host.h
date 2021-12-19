#ifndef AIRPORTMANAGEMENTSYSTEM_HOST_H
#define AIRPORTMANAGEMENTSYSTEM_HOST_H

#include "worker.h"
class flight;
class host : public worker {
public:
    host(const string &id, const string &name, const string &family, const string &birthDate, const string &pCode,
         const string &employDate);

};


#endif //AIRPORTMANAGEMENTSYSTEM_HOST_H
