#include <stdio.h>
#include "pico/stdlib.h"

int main(){

    char tecla='\0';

    gpio_init(27);
    gpio_set_dir(27,GPIO_OUT);

    while(true){

        if (tecla == '1'){
            gpio_put(27,1);
            gpio_put(27,0);
        }
    }
}
