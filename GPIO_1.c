#include <stdio.h>
#include "pico/stdlib.h"


char leitura() {
  uint colunas[4]={0,1,2,3};
  uint linhas[4]={4,5,6,7};
  char teclado[4][4] = {{'1', '2', '3', 'A'}, 
                        {'4', '5', '6', 'B'}, 
                        {'7', '8', '9', 'C'}, 
                        {'*', '0', '#', 'D'}};

    for (int i = 0; i < 4; i++) {
        gpio_put(linhas[i], 1); // Set row low
        sleep_ms(1); // Atraso para garantir leitura correta
        for (int j = 0; j < 4; j++) {
            if (gpio_get(colunas[j]) == 1) {
                gpio_put(linhas[i], 0); // Set row high
                return teclado[i][j];
            }
        }
        gpio_put(linhas[i], 0); // Set row high
    }
    return 'X'; // No key pressed
}


int main() {

  char tecla;
  uint colunas[4]={0,1,2,3};
  uint linhas[4]={4,5,6,7};
  
  
  for (int i = 0; i < 4; i++) {
    gpio_init(colunas[i]);
    gpio_set_dir(colunas[i], GPIO_IN);
    gpio_pull_down(colunas[i]);
  }
  for (int i = 0; i < 4; i++) {
    gpio_init(linhas[i]);
    gpio_set_dir(linhas[i], GPIO_OUT);
    gpio_put(linhas[i], 0);
  }
  gpio_init(9);
  gpio_set_dir(9, GPIO_OUT);
  gpio_init(28);
  gpio_set_dir(28, GPIO_OUT);


  while (true) {
    tecla = leitura();
    if (tecla == 'A') {
      gpio_put(9, true);
      gpio_put(9, false);
    }
  }

  return 0;
}