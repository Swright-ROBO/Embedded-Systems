#include "mbed.h"

// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2
#define LEDMASK 0b0000000001001100

#define ON_BOARD_GRN PB_0
#define ON_BOARD_YEL PB_7
#define ON_BOARD_RED PB_14
#define ON_LEDMASK 0b0100000010000001
// Objects
//BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
PortOut leds(PortC, LEDMASK);
PortOut leds2(PortB, ON_LEDMASK);

int main()
{
    while (true) {
        leds = leds ^LEDMASK;   //Binary 000
        leds2 = leds2 ^ON_LEDMASK;
        wait_us(500000);  
    }
}




