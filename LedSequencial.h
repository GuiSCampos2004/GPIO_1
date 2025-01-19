#ifndef LedSequencial_h
#define LedSequencial_h
#include "pico/stdlib.h"

void led_sequence(uint8_t leds[])
{
    for (int i = 0; i < 9; i++)
    {
        gpio_put(leds[i], 1); // Liga
        sleep_ms(500);        // Aumentei o tempo para melhor visualização
        gpio_put(leds[i], 0); // Desliga
        sleep_ms(100);
    }
}

#endif