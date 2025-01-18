#include <stdio.h>
#include "pico/stdlib.h"

#define led_green_pin 11
#define led_red_pin 13

// Protótipo da função:
void led_vemelho_verde(char caractere);

int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}


// Função que liga o led vermelho e verde quando clicar na tecla 6

void led_vermelho_verde(char caractere){
    if (caractere == 6){
        // Caso já tenha uma função para inicializar esses pinos, temos que apagar essas inicializações:
        gpio_init(led_red_pin);
        gpio_init(led_green_pin);
        
        gpio_set_dir(led_green_pin, GPIO_OUT);
        gpio_set_dir(led_red_pin, GPIO_OUT);

        gpio_put(led_green_pin, 1);
        gpio_put(led_red_pin, 1);
        printf("Voce ligou o led vermelho e verde\n");
    }
}