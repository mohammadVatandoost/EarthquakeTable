#ifndef PACKET_H
#define PACKET_H

#include <iostream>

using namespace std;

#define SensorRxPkt 0
#define MotorSpeedRxPkt 1
#define ConfigTxPkt 2
#define TorqueRxPkt 3

#define SensorDisconnected 255

#define CALIBRATION	10
#define CONFIG		20
#define RUN			30

#define MoveRight	1
#define MoveLeft	2
#define Stop		0

#pragma pack(push, 1)

struct SensorRx {
    uint8_t sensorId;
    int16_t x;
    int16_t y;
    int16_t z;
};

struct MotorSpeedRx {
    uint16_t frq;
};

struct ConfigTx {
    uint8_t packetCode = ConfigTxPkt;
    uint8_t mode;
    uint8_t move;
    uint8_t loopTime;
};

struct TorqueRx {
    uint16_t torque;
};


#endif // PACKET_H
