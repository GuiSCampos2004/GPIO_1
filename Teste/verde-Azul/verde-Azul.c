#include <stdio.h>
#include <pico/stdlib.h>
#include "Menu.h"

#define LED_GREEN 13
#define LED_BLUE 17
#define BUZZER 21

#define ROWS 4
#define COLS 4

char key_map[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};


int row_pins[ROWS] = {2, 3, 4, 5};
int col_pins[COLS] = {6, 7, 8, 9};

void keypad_init() {
    for (int i = 0; i < ROWS; i++) {
        gpio_init(row_pins[i]);
        gpio_set_dir(row_pins[i], GPIO_OUT);
        gpio_put(row_pins[i], 1); 
    }
    for (int i = 0; i < COLS; i++) {
        gpio_init(col_pins[i]);
        gpio_set_dir(col_pins[i], GPIO_IN);
        gpio_pull_up(col_pins[i]); 
    }
}

// Verifica qual tecla foi pressionada
char keypad_get_key() {
    for (int row = 0; row < ROWS; row++) {
        gpio_put(row_pins[row], 0); 
        for (int col = 0; col < COLS; col++) {
            if (gpio_get(col_pins[col]) == 0) { 
                sleep_ms(50); 
                while (gpio_get(col_pins[col]) == 0); 
                gpio_put(row_pins[row], 1); 
                return key_map[row][col]; 
            }
        }
        gpio_put(row_pins[row], 1); 
    }
    return '\0'; 
}

// Ativa LEDs ou buzzer com base na tecla pressionada
void activate_output(char key) {
    switch (key) {
        case '1':
            gpio_put(LED_GREEN, 1); 
            sleep_ms(2000);         
            gpio_put(LED_GREEN, 0); 
            break;
        case '2':
            gpio_put(LED_BLUE, 1);  
            sleep_ms(2000);         
            gpio_put(LED_BLUE, 0);  
            break;
        case 'A':
            gpio_put(BUZZER, 1);    
            sleep_ms(200);          
            gpio_put(BUZZER, 0);    
            break;
        default:
            printf("Tecla '%c' não associada a nenhuma ação.\n", key);
            break;
    }
}

int main() {
    stdio_init_all(); 
    printf("Sistema iniciado.\n");

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);

    keypad_init();

    while (1) {
        char key = keypad_get_key(); 
        if (key != '\0') {
            printf("Tecla pressionada: %c\n", key);
            activate_output(key); 
        }
    }

    return 0;
}