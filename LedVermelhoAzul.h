#ifndef LedVermelhoAzul_h
#define LedVermelhoAzul_h
#include "pico/stdlib.h"

void led_vermelho_azul (char caractere)
  { 
    if (caractere == 7){     
      gpio_init(led_red_pin);
      gpio_init(led_blue_pin);
      
      gpio_set_dir(led_blue_pin, GPIO_OUT);
      gpio_set_dir(led_red_pin, GPIO_OUT);

      gpio_put(led_blue_pin, 1);
      gpio_put(led_red_pin, 1);
      printf("Voce ligou o led vermelho e azul\n");
    }
  }

#endif