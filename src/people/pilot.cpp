#include <iostream>
#include "pilot.h"

pilot::pilot(const string &id, const string &name, const string &family, const string &birthDate, const string &pCode,
             const string &employDate, int rank) : worker(id, name, family, birthDate, pCode, employDate), rank(rank) {}

void pilot::printInfo() const{
    worker::printInfo();
    cout << "rank: " << rank << endl;
}

int pilot::getRank() const {
    return rank;
}

void pilot::setRank(int prank) {
    pilot::rank = prank;
}
