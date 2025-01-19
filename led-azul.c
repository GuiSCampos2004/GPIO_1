#include "led-azul.h"
#include "pico/stdlib.h"

void led_azul_init(uint8_t pin) {
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
    gpio_put(pin, false);
}

void led_azul_ligar(uint8_t pin) {
    gpio_put(pin, true);
}

void led_azul_desligar(uint8_t pin) {
    gpio_put(pin, false);
}

void led_azul_alternar(uint8_t pin) {
    bool estado = gpio_get(pin);
    gpio_put(pin, !estado);
}

