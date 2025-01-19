#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int escolha;

    system("cls");

    printf("=== Sistema Iniciado ===\n");
    printf("Pressione uma tecla para escolher uma opcao:\n\n");
    printf("8 - Acender os LEDs sequencialmente\n");
    printf("\nSua escolha: ");

    scanf("%d", &escolha);

    return escolha;
}

#endif // MENU_H
