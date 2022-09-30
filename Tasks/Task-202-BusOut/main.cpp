#include "mbed.h"

// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2
#define TRAF_GRN2_PIN PB_0
#define TRAF_YEL2_pin PB_7
#define TRAF_RED2_PIN PB_14
#define avingwait 500000
// Objects
// DigitalOut grn(TRAF_GRN1_PIN);
// DigitalOut yel(TRAF_YEL1_PIN);
// DigitalOut red(TRAF_RED1_PIN,1);
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN, TRAF_GRN2_PIN, TRAF_YEL2_pin, TRAF_RED2_PIN);

int main()
{
    //int count = 0;
    while (true) {
        leds = 63;
        wait_us(avingwait);
        leds = 0;
        wait_us(avingwait);
    }
}


