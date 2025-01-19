#include <stdio.h>
#include "pico/stdlib.h"
#include "menu.h"

#define LED1_R 16
#define LED1_G 17
#define LED1_B 18
#define LED2_R 19
#define LED2_G 20
#define LED2_B 21
#define LED3_R 22
#define LED3_G 26
#define LED3_B 27
#define BUZZ 14


uint colunas[4]={9,8,7,6}; //Variáveis necessárias uma vez que funções 
uint linhas[4]={13,12,11,10}; //gpio precisam de parametros do tipo uint
uint OUTs[10] = {LED1_R,LED1_G,LED1_B,LED2_R,LED2_G,LED2_B,LED3_R,LED3_G,LED3_B,BUZZ};

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
  bool mostra_menu=false;


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
  for (int i = 0; i < 10; i++){
    gpio_init(OUTs[i]);
    gpio_set_dir(OUTs[i], GPIO_OUT);
  }

  stdio_init_all();
  busy_wait_us(1000000); // Aguarda 1 segundo para garantir que o stdio está pronto

  menu();

  while (true) {
    
    tecla = leitura();

    if (tecla != 'X'){ // Se uma tecla foi pressionada
      printf("\nTecla pressionada: %c\n", tecla);

      switch (tecla){
        case '1':
          
          
          mostra_menu = true;
          break;

        case '2':
          
          
          mostra_menu = true;
          break;

        case '3':
          
          
          mostra_menu = true;
          break;

        case '4':
          
          
          mostra_menu = true;
          break;

        case '5':
          
          
          mostra_menu = true;
          break;

        case '6':
          gpio_put(LED1_R, 1);
          gpio_put(LED2_R, 1);
          gpio_put(LED3_R, 1);
          gpio_put(LED1_G, 1);
          gpio_put(LED2_G, 1);
          gpio_put(LED3_G, 1);
          sleep_ms(100);
          gpio_put(LED1_R, 0);
          gpio_put(LED2_R, 0);
          gpio_put(LED3_R, 0);
          gpio_put(LED1_G, 0);
          gpio_put(LED2_G, 0);
          gpio_put(LED3_G, 0);
          sleep_ms(100);
          mostra_menu = true;
          break;

        case '7':
          gpio_put(LED1_R, 1);
          gpio_put(LED2_R, 1);
          gpio_put(LED3_R, 1);
          gpio_put(LED1_B, 1);
          gpio_put(LED2_B, 1);
          gpio_put(LED3_B, 1);
          sleep_ms(100);
          gpio_put(LED1_R, 0);
          gpio_put(LED2_R, 0);
          gpio_put(LED3_R, 0);
          gpio_put(LED1_B, 0);
          gpio_put(LED2_B, 0);
          gpio_put(LED3_B, 0);
          sleep_ms(100);
          mostra_menu = true;
          break;

        case '8':
          for (int i = 0; i < 9; i++){
            gpio_put(OUTs[i], 1);
            sleep_ms(100);
            gpio_put(OUTs[i], 0);
            sleep_ms(100);
          }
          mostra_menu = true;
          break;

        case '9':
          
          
          mostra_menu = true;
          break;

        case 'A':
          
          
          mostra_menu = true;
          break;

        case 'B':
        

          mostra_menu = true;
          break;

        case 'C':
          
          
          mostra_menu = true;
          break;

        case 'D':
          
          
          mostra_menu = true;
          break;

        default:
      }

      if (mostra_menu){
        menu();
        mostra_menu = false;
      }
    }

    busy_wait_us(50000); // 50ms para responsividade
  }
  
  return 0;
}
