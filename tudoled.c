#include <stdio.h>
#include "pico/stdlib.h"

const uint led_pin_red = 13;
const uint led_pin_blue = 12;
const uint led_pin_green = 11;

int main(){
  gpio_init(led_pin_red);
  gpio_set_dir(led_pin_red, GPIO_OUT);

  gpio_init(led_pin_blue);
  gpio_set_dir(led_pin_blue, GPIO_OUT);

  gpio_init(led_pin_green);
  gpio_set_dir(led_pin_green, GPIO_OUT);

  stdio_init_all();
    
  while (true) {
    
    gpio_put(led_pin_red, true);
    

    
    gpio_put(led_pin_blue, true);
    

    
    gpio_put(led_pin_green, true);
    ;
  }
}