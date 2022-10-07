#include "uop_msb.h"
#include "SwitchTimerLedManager.hpp"
#include "FlashingLED.hpp"
#include <chrono>
#include <ratio>
using namespace uop_msb;
using namespace chrono;

Timer tmrLED;
SwitchTimerLedManager fsm1(BTN1_PIN, SwitchTimerLedManager::UP);
SwitchTimerLedManager fsm2(BTN2_PIN, SwitchTimerLedManager::DOWN);
LED Grnled(TRAF_GRN1_PIN, 250ms);
LED Redled(TRAF_RED1_PIN, 350ms);
LED Yelled(TRAF_YEL1_PIN, 420ms);

//Dual Digit 7-segment Display
LatchedLED disp(LatchedLED::SEVEN_SEG);

microseconds timeLED;

int main()
{
    int count = 0;

    //Turn ON the 7-segment display
    disp.enable(true);
    disp = 0;
    disp = count;

    while (true) {

        // **********
        //Poll inputs
        // **********
        fsm1.readInputs();
        fsm2.readInputs();
        Grnled.readinput();
        Yelled.readinput();
        Redled.readinput();

        // **********************************
        // UPDATE "STATE" for buttons A and B
        // **********************************
        fsm1.updateState(count);
        fsm2.updateState(count);
        Grnled.updateState();
        Yelled.updateState();
        Redled.updateState();

        // UPDATE OUTPUTS
        disp = count;
  
    }
}





