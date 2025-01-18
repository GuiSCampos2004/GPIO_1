#include <stdio.h>
#include "pico/stdlib.h"



int main()
{
    stdio_init_all();

    printf("Olá mundo");

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
