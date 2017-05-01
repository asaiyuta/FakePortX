#ifndef FAKE_PINTOPORT
#define FAKE_PINTOPORT
#include "datas/teensy3.2utils/portRegArray.h"

uint8_t* fakePinToPort(const uint8_t PinNumber){
    PortRegArray* RegArray = new PortRegArray();
    uint8_t* ptBuf = RegArray -> mapPinToReg[PinNumber];
    return  ptBuf;
}

void changeModeDigitalWrite(const uint8_t PinNumber){
    PortRegArray* RegArray = new PortRegArray();
    *(RegArray -> gpioBitBand[PinNumber]) = 1;
    *(RegArray -> pinConfig[PinNumber]) = RegArray -> pullUp;
}

#endif
