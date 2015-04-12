#include "mbed.h"

DigitalOut led(LED1);           // on-board led is connected to D13

int main()
{
    while (true) {
        led = !led;
        wait(0.1);
    }
}