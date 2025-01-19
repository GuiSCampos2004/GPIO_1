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

void led_sequence()
{
    // Matriz com todos os pinos organizados por LED
    const uint8_t leds[][3] = {
        {LED1_R, LED1_G, LED1_B}, // LED 1
        {LED2_R, LED2_G, LED2_B}, // LED 2
        {LED3_R, LED3_G, LED3_B}  // LED 3
    };

    // Loop para cada LED
    for (int led = 0; led < 3; led++)
    {
        // Loop para cada cor (R,G,B)
        for (int cor = 0; cor < 3; cor++)
        {
            gpio_put(leds[led][cor], 1); // Liga
            sleep_ms(100);               // Espera 100ms
            gpio_put(leds[led][cor], 0); // Desliga
        }
    }
}

#endif