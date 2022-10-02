#include "uop_msb.h"
using namespace uop_msb;

// Inputs
DigitalIn SW2(BTN1_PIN);
DigitalIn SW3(BTN2_PIN);

// Outputs
DigitalOut ledRed(TRAF_RED1_PIN);
DigitalOut ledYel(TRAF_YEL1_PIN);
DigitalOut ledGrn(TRAF_GRN1_PIN);

// Timers (modified version from Timer)
TimerCompat tmr_flash;
TimerCompat tmr_debounce_2;
TimerCompat tmr_debounce_3;

// THE CODE BELOW IS NOT A SOLUTION
//
// IT IS FUNDAMENTALLY FLAWED (AND INCOMPLETE)
//
//

typedef enum
{
    WAITING_PRESS,
    FIRST_WAIT,
    WAITING_RELEASE,
    SECOND_WAIT
}SWITCHSTATE;

SWITCHSTATE Sw2_State = WAITING_PRESS;
SWITCHSTATE Sw3_State = WAITING_PRESS;

int main()
{
    //Start flashing timer
    tmr_flash.start();

    while (true) {

        long long Yell_flash = tmr_flash.read_ms();
        int sw2 = SW2.read();
        int sw3 = SW3.read();
        long long sw2_time = tmr_debounce_2.read_ms();
        long long sw3_time = tmr_debounce_3.read_ms();

        if (Yell_flash >= 500)
        {
            ledYel = !ledYel;
            tmr_flash.reset();
        }

        switch (Sw2_State)
        {
            case WAITING_PRESS:
            if (sw2 == 1)
            {
                Sw2_State = FIRST_WAIT;
                tmr_debounce_2.start();
                ledGrn = !ledGrn;
            }
            case FIRST_WAIT:
            if (sw2_time >= 500)
            {
                Sw2_State = WAITING_RELEASE;
                tmr_debounce_2.stop();
                tmr_debounce_2.reset();
            }
            case WAITING_RELEASE:
            if (sw2 == 0)
            {
                Sw2_State = SECOND_WAIT;
                tmr_debounce_2.start();
            }
            case SECOND_WAIT:
            if (sw2_time >= 500)
            {
                Sw2_State = WAITING_PRESS;
                tmr_debounce_2.stop();
                tmr_debounce_2.reset();
            }
        }
        switch (Sw3_State)
        {
            case WAITING_PRESS:
            if (sw3 == 1)
            {
                Sw3_State = FIRST_WAIT;
                tmr_debounce_3.start();
                ledRed = !ledRed;
            }
            case FIRST_WAIT:
            if (sw3_time >= 500)
            {
                Sw3_State = WAITING_RELEASE;
                tmr_debounce_3.stop();
                tmr_debounce_3.reset();
            }
            case WAITING_RELEASE:
            if (sw3 == 0)
            {
                Sw3_State = SECOND_WAIT;
                tmr_debounce_3.start();
            }
            case SECOND_WAIT:
            if (sw3_time >= 500)
            {
                Sw3_State = WAITING_PRESS;
                tmr_debounce_3.stop();
                tmr_debounce_3.reset();
            }
        }
    }
}





