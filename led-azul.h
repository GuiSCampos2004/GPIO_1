#ifndef LED_AZUL_H
#define LED_AZUL_H

#include <stdbool.h>
#include "pico/stdlib.h"

// Defina o pino GPIO para o LED azul
#define LED_AZUL_PIN 12

// Inicializa o LED azul
void led_azul_init(uint8_t pin);

// Liga o LED azul
void led_azul_ligar(uint8_t pin);

// Desliga o LED azul
void led_azul_desligar(uint8_t pin);

// Alterna o estado do LED azul
void led_azul_alternar(uint8_t pin);

#endif // LED_AZUL_H
