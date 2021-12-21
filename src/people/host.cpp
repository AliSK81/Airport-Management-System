#include "host.h"

host::host(const string &id, const string &name, const string &family, const string &birthDate, const string &pCode,
           const string &employDate) : worker(id, name, family, birthDate, pCode, employDate) {}

void host::printInfo() const{
    worker::printInfo();
}
