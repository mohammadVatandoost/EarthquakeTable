#ifndef PACKET_H
#define PACKET_H

#include <iostream>

using namespace std;

#define SensorRxPkt 0
#define MotorSpeedRxPkt 1
#define ColibrateTxPkt 2
#define TorqueRxPkt 3

struct SensorRx {
    uint8_t sensorId;
    uint16_t x;
    uint16_t y;
    uint16_t z;
};

struct MotorSpeedRx {
    uint16_t speed;
};

struct ColibrateTx {
    uint8_t start;
};

struct TorqueRx {
    uint16_t torque;
};


#endif // PACKET_H
