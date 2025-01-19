#include <stdio.h>
#include "pico/stdlib.h"

uint colunas[4]={0,1,2,3}; //Variáveis necessárias uma vez que funções 
uint linhas[4]={4,5,6,7}; //gpio precisam de parametros do tipo uint

//--------------------------------------------------------------------------------------------
char leitura() { //Função que realiza leitura das teclas
  char teclado[4][4] = {{'1', '2', '3', 'A'}, 
                        {'4', '5', '6', 'B'}, 
                        {'7', '8', '9', 'C'}, 
                        {'*', '0', '#', 'D'}};//Matriz com os respectivos valores do teclado

    for (int i = 0; i < 4; i++) {
        gpio_put(linhas[i], 0); //A linha recebe estado low para iniciar a varredura por ela
        sleep_ms(1); //Atraso para garantir leitura correta
        for (int j = 0; j < 4; j++) {
            if (gpio_get(colunas[j]) == 0) { //Checa se a mudança de estado da linha influencia nessa coluna
                gpio_put(linhas[i], 1); //Reestabelece o estado high para futuras leituras
                return teclado[i][j]; //Retorna a qual tecla foi apertada com base na localização da mesma na matriz
            }
        }
        gpio_put(linhas[i], 1);
    }
    return 'X'; //Caso nenhuma tecla seja apertada, retorna um valor que não interfere em futuros if's
}
//--------------------------------------------------------------------------------------------

int main() {

  char tecla; //Essa variável irá receber o valor da tecla apertada
  for (int i = 0; i < 4; i++) {
    gpio_init(colunas[i]); //Inicializa porta das colunas
    gpio_set_dir(colunas[i], GPIO_IN); //Configura as portas como entrada
    gpio_pull_up(colunas[i]); //Estabelece o uso de resistores pull-up para as colunas
  }
  for (int i = 0; i < 4; i++) {
    gpio_init(linhas[i]); //Inicializa porta das linhas
    gpio_set_dir(linhas[i], GPIO_OUT); //Configura as portas como saída
    gpio_put(linhas[i], 1); //Coloca as linhas em estado high
  }

  while (true) {
    tecla = leitura();
    //A partir daqui havera a relação entre o valor de 'tecla' e os OUTPUT's
  }
  
  return 0;
}