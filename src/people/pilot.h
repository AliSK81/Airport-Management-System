#ifndef AIRPORTMANAGEMENTSYSTEM_PILOT_H
#define AIRPORTMANAGEMENTSYSTEM_PILOT_H
#include <iostream>

#include "worker.h"

class flight;

class pilot : public worker {
private:
    int rank;

public:
    pilot() = default;

    pilot(const string &id, const string &name, const string &family, const string &birthDate, const string &pCode,
          const string &employDate, int rank);

    void printInfo() const;

    virtual string getType() const { return "pilot"; }

    int getRank() const;

    void setRank(int rank);

    virtual void out(ostream &os) const {
        worker::out(os);
        os << ' ' + to_string(rank) << endl;
    }

    virtual void in(istream &is) {
        worker::in(is);
        string tmp;
        is >> tmp;
        if (tmp != "")
            rank = stoi(tmp);
    }
};


#endif //AIRPORTMANAGEMENTSYSTEM_PILOT_H
