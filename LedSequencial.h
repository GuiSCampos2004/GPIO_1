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

void led_sequence(const uint8_t leds[][3], size_t num_leds) {
    // Loop para cada LED
    for (size_t led = 0; led < num_leds; led++) {
        // Loop para cada cor (R, G, B)
        for (size_t cor = 0; cor < 3; cor++) {
            gpio_put(leds[led][cor], 1); // Liga
            sleep_ms(100);               // Espera 100ms
            gpio_put(leds[led][cor], 0); // Desliga
        }
    }
}

#endif
