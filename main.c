#include <stdio.h>
#include "pico/stdlib.h"
#include "menu.h"
#include "LedSequencial.h"

// Define os pinos do teclado com as portas GPIO
uint columns[4] = {10, 11, 12, 13};
uint rows[4] = {6, 7, 8, 9};

#define LED1_R 16
#define LED1_G 17
#define LED1_B 18
#define LED2_R 19
#define LED2_G 20
#define LED2_B 21
#define LED3_R 22
#define LED3_G 26
#define LED3_B 27

const char keymap[16] = {
    '1', '2', '3', 'A',
    '4', '5', '6', 'B',
    '7', '8', '9', 'C',
    '*', '0', '#', 'D'};

const uint8_t pins[] = {
    LED1_R, LED1_G, LED1_B,
    LED2_R, LED2_G, LED2_B,
    LED3_R, LED3_G, LED3_B};

void init_leds()
{

    // Inicializa todos os leds
    for (int i = 0; i < 9; i++)
    {
        gpio_init(pins[i]);
        gpio_set_dir(pins[i], GPIO_OUT);
    }
}

// Função de inicialização do teclado
void pico_keypad_init()
{
    for (int i = 0; i < 4; i++)
    {
        gpio_init(columns[i]);
        gpio_init(rows[i]);

        gpio_set_dir(columns[i], GPIO_IN);
        gpio_pull_down(columns[i]);

        gpio_set_dir(rows[i], GPIO_OUT);
        gpio_put(rows[i], 0); // Inicialmente desativa todas as linhas
    }
}

// Função para obter a tecla pressionada
char pico_keypad_get_key()
{
    for (int row = 0; row < 4; row++)
    {
        gpio_put(rows[row], 1); // Ativa a linha atual

        busy_wait_us(1000); // Pequeno delay para estabilizar

        for (int col = 0; col < 4; col++)
        {
            if (gpio_get(columns[col]))
            {                           // Verifica se a coluna está ativada
                gpio_put(rows[row], 0); // Reseta a linha antes de retornar
                return keymap[row * 4 + col];
            }
        }

        gpio_put(rows[row], 0); // Desativa a linha atual
    }

    return 0; // Nenhuma tecla pressionada
}

// Função principal
int main()
{
    stdio_init_all();
    init_leds();
    pico_keypad_init();
    printf("Sistema iniciado. Pressione teclas.\n");

    char key;

    do
    {
        menu();
        key = pico_keypad_get_key(); // Obtém a tecla pressionada

        if (key != 0)
        { // Se uma tecla foi pressionada
            printf("Tecla pressionada: %c\n", key);

            if (key == '8')
            {
                led_sequence(pins); // Executa a sequência de LEDs
            }
            else if (key == 'D')
            {
                printf("Saindo do loop...\n");
                break; // Sai do loop quando a tecla 'D' é pressionada
            }
            else
            {
                printf("Nenhuma ação definida para a tecla pressionada.\n");
            }
        }

        busy_wait_us(500000); // Aguarda meio segundo
    } while (true); // Loop infinito (será interrompido pelo 'break')

    return 0;
}
