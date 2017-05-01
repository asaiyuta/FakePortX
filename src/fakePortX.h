
#ifndef FAKEPORTX
#define FAKEPORTX

#include "fakePinToPort.h"
#include <array>
#include <stdarg.h>

namespace PortX{
    union Bit8{
        Bit8()
        : column(0)
        {}
        struct{
            uint8_t bit0:1;
            uint8_t bit1:1;
            uint8_t bit2:1;
            uint8_t bit3:1;
            uint8_t bit4:1;
            uint8_t bit5:1;
            uint8_t bit6:1;
            uint8_t bit7:1;
        };
        uint8_t column;
    };

    union Bit16{
        Bit16()
        : column(0)
        {}
        struct{
            uint8_t bit0:1;
            uint8_t bit1:1;
            uint8_t bit2:1;
            uint8_t bit3:1;
            uint8_t bit4:1;
            uint8_t bit5:1;
            uint8_t bit6:1;
            uint8_t bit7:1;
            uint8_t bit8:1;
            uint8_t bit9:1;
            uint8_t bit10:1;
            uint8_t bit11:1;
            uint8_t bit12:1;
            uint8_t bit13:1;
            uint8_t bit14:1;
            uint8_t bit15:1;
        };
        uint16_t column;
    };
};

template<std::size_t NUM>
class FakePortX8{
public:
    FakePortX8()
    : HighLowCommonMask{ 0xFE , 0x01 }
    {}
    ~FakePortX8(){}

    template<class... PINS>
    void init(const PINS... pins){
        setUpPortAndMode(0, pins...);
    }

    void operator = (const uint8_t c){}
private:
    template<class FIRST,class... REST>
    void setUpPortAndMode(int count,const FIRST first,const REST... rest){
        regs[count] = fakePinToPort(first);
        changeModeDigitalWrite(first);
        ++count;
        setUpPortAndMode(count,rest...);
    }

    void setUpPortAndMode(int count){}
    std::array<uint8_t, 2> HighLowCommonMask;
    std::array<uint8_t*, NUM> regs;
    PortX::Bit8 bits;

};

template<>
void FakePortX8<1>::operator = (const uint8_t c){
    bits.column = c;
    *(regs[0]) = HighLowCommonMask[bits.bit0];
}

template<>
void FakePortX8<2>::operator = (const uint8_t c){
    bits.column = c;
    *(regs[0]) = HighLowCommonMask[bits.bit0];
    *(regs[1]) = HighLowCommonMask[bits.bit1];
}

template<>
void FakePortX8<3>::operator = (const uint8_t c){
    bits.column = c;
    *(regs[0]) = HighLowCommonMask[bits.bit0];
    *(regs[1]) = HighLowCommonMask[bits.bit1];
    *(regs[2]) = HighLowCommonMask[bits.bit2];
}

template<>
void FakePortX8<4>::operator = (const uint8_t c){
    bits.column = c;
    *(regs[0]) = HighLowCommonMask[bits.bit0];
    *(regs[1]) = HighLowCommonMask[bits.bit1];
    *(regs[2]) = HighLowCommonMask[bits.bit2];
    *(regs[3]) = HighLowCommonMask[bits.bit3];
}

template<>
void FakePortX8<5>::operator = (const uint8_t c){
    bits.column = c;
    *(regs[0]) = HighLowCommonMask[bits.bit0];
    *(regs[1]) = HighLowCommonMask[bits.bit1];
    *(regs[2]) = HighLowCommonMask[bits.bit2];
    *(regs[3]) = HighLowCommonMask[bits.bit3];
    *(regs[4]) = HighLowCommonMask[bits.bit4];
}

template<>
void FakePortX8<6>::operator = (const uint8_t c){
    bits.column = c;
    *(regs[0]) = HighLowCommonMask[bits.bit0];
    *(regs[1]) = HighLowCommonMask[bits.bit1];
    *(regs[2]) = HighLowCommonMask[bits.bit2];
    *(regs[3]) = HighLowCommonMask[bits.bit3];
    *(regs[4]) = HighLowCommonMask[bits.bit4];
    *(regs[5]) = HighLowCommonMask[bits.bit5];
}

template<>
void FakePortX8<7>::operator = (const uint8_t c){
    bits.column = c;
    *(regs[0]) = HighLowCommonMask[bits.bit0];
    *(regs[1]) = HighLowCommonMask[bits.bit1];
    *(regs[2]) = HighLowCommonMask[bits.bit2];
    *(regs[3]) = HighLowCommonMask[bits.bit3];
    *(regs[4]) = HighLowCommonMask[bits.bit4];
    *(regs[5]) = HighLowCommonMask[bits.bit5];
    *(regs[6]) = HighLowCommonMask[bits.bit6];
}

template<>
void FakePortX8<8>::operator = (const uint8_t c){
    bits.column = c;
    *(regs[0]) = HighLowCommonMask[bits.bit0];
    *(regs[1]) = HighLowCommonMask[bits.bit1];
    *(regs[2]) = HighLowCommonMask[bits.bit2];
    *(regs[3]) = HighLowCommonMask[bits.bit3];
    *(regs[4]) = HighLowCommonMask[bits.bit4];
    *(regs[5]) = HighLowCommonMask[bits.bit5];
    *(regs[6]) = HighLowCommonMask[bits.bit6];
    *(regs[7]) = HighLowCommonMask[bits.bit7];
}

#endif
