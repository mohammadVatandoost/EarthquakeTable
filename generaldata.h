#ifndef GENERALDATA_H
#define GENERALDATA_H
#include <iostream>

#define offValue  100

using namespace std;

struct GeneralData {
    int torque;
    int floor[4] = {offValue, offValue, offValue, offValue};
};


#endif // GENERALDATA_H
