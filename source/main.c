#include "main.h"

const uint16_t LEDS = GPIO_Pin_1;
const uint16_t LED[1] = {GPIO_Pin_1};
const long LED_COUNT = 1;

int main()
{
    init();
    do
    {
        loop();
    }
    while (1);

    return 0; // never reached
}

void loop()
{
    uint32_t counter = 0;

    while (1) {
        counter++;

        GPIO_ResetBits(GPIOC, LEDS);
        GPIO_SetBits(GPIOC, LED[counter % 2]);

        delay(250);
    };
}

void init() {
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    GPIO_InitTypeDef gpio;
    GPIO_StructInit(&gpio);

    gpio.GPIO_Mode = GPIO_Mode_OUT;
    gpio.GPIO_Pin = LEDS;

    GPIO_Init(GPIOC, &gpio);
    GPIO_SetBits(GPIOC, LEDS);
}


void delay(uint32_t ms) {
    ms *= 3360;
    while(ms--) {
        __NOP();
    }
}
