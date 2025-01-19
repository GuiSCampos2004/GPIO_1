#ifndef LedSequencial_h
#define LedSequencial_h
#include "pico/stdlib.h"

// Definições dos pinos dos LEDs RGB
#define LED1_R 16
#define LED1_G 17
#define LED1_B 18
#define LED2_R 19
#define LED2_G 20
#define LED2_B 21
#define LED3_R 22
#define LED3_G 26
#define LED3_B 27

void led_sequence(const uint8_t leds[8])
{
    // Loop para cada LED
    for (size_t led = 0; led < 9; led++)
    {
        // Loop para cada cor (R, G, B)

        gpio_put(leds[led], 1); // Liga
        sleep_ms(100);          // Espera 100ms
        gpio_put(leds[led], 0); // Desliga
    }
}

#endif
