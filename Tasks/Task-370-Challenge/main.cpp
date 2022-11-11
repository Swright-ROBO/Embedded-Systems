#include "uop_msb.h"
#include <chrono>
using namespace uop_msb;

//Used this to 
Ticker tick;
Thread t1;
void task1();
void ADCTrigger()
{
    t1.flags_set(1);
}

int main(void)
{
/*
1. Create an ISR - called by a Ticker every 1ms. This ISR simply has the job of signalling a waiting thread to perform an ADC conversion
2. Create a thread that waits for a signal from the ISR. This thread should ideally have the highest priority
3. Each time it is unblocked by the signal, it should read the ADC (Use `AnalogIn`) for the LDR and add it to a running sum.
4. Every 1s, it should print out the average of the past 1000 samples to the terminal. 
*/
    t1.start(task1);
    tick.attach(&ADCTrigger, 1ms);
    while (true) {
        ThisThread::sleep_for(1000ms);
    }
    
}

void task1()
{
    ThisThread::flags_wait_any(1);
    printf("Recieved ping\n");
    ThisThread::flags_clear(1);
}