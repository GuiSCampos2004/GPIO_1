#ifndef MENU_H
#define MENU_H

#include <stdio.h>

void menu()
{
    // Limpa a tela usando caracteres de escape ANSI
    printf("\033[2J\033[H"); // Limpa a tela e move o cursor para o início

    printf("=== Sistema Iniciado ===\n");
    printf("Pressione uma tecla para escolher uma opcao:\n\n");
    printf("1 - Liga Buzzer\n");
    printf("2 - Acender o LED verde\n");
    printf("3 - Acender o LED azul\n");
    printf("4 - Acender o LED vermelho\n");
    printf("5 - Acender o LED's verde e azul\n");
    printf("6 - Acender o LED's verde e vermelho\n");
    printf("7 - Acender os LEDs azul e vermelho\n");
    printf("8 - Acender os LEDs de forma sequencial\n");
    printf("9 - Acender todos os LEDs\n");
    printf("A - Liga buzzer e LED verde\n");
    printf("B - Liga buzzer e LED azul\n");
    printf("C - Liga buzzer e LED verdemelho\n");
    printf("D - Liga buzzer e todos os LED's\n");
}

#endif
