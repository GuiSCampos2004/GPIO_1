#ifndef MENU_H
#define MENU_H

#include <stdio.h>

void menu()
{
    // Limpa a tela usando caracteres de escape ANSI
    printf("\033[2J\033[H"); // Limpa a tela e move o cursor para o início

    printf("=== Sistema Iniciado ===\n");
    printf("Pressione uma tecla para escolher uma opcao:\n\n");
    printf("7 - Acender os LEDs Vermelho e Azul\n");
    printf("8 - Acender os LEDs sequencialmente\n");
}

#endif // MENU_H