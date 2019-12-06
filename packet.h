#ifndef PACKET_H
#define PACKET_H

#include <iostream>

using namespace std;

#define MAX_SEG_DATA	10
#define MAX_FILE_DATA	10000

#define SensorRxPkt 0
#define MotorSpeedRxPkt 1
#define ConfigTxPkt 2
#define TorqueRxPkt 3
#define	FileTxPkt		4
#define AckRxPkt		5

#define SensorDisconnected 255

#define CALIBRATION	10
#define CONFIG		20
#define RUN			30
#define SendData	40

#define Stop		0
#define MoveRight	1
#define MoveLeft	2


//#pragma pack(push, 1)

struct SensorRx {
    int16_t sensorId;
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
    uint8_t move = Stop;
    uint8_t loopTime = 0;
};

struct TorqueRx {
    uint16_t torque;
};


struct GeneralData {
    int torque;
};

struct DataSegment{
    uint16_t packetCode = FileTxPkt;
    uint16_t 	packetId;
    int16_t 	data[MAX_SEG_DATA];
};

struct AckRx{
    uint16_t packetId;
};


#endif // PACKET_H
