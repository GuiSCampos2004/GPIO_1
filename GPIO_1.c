#include <stdio.h>
#include "pico/stdlib.h"



int main(){

    gpio_init(27);
    gpio_set_dir(27,GPIO_OUT);

    while(true){
        gpio_put(27,1);
        sleep_ms(500);
        gpio_put(27,0);
        sleep_ms(500);
    }
}
