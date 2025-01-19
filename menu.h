#ifndef menu_h
#define menu_h

#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int escolha;

    system("cls");

    printf("Sistema iniciado.Pressione teclas\n");

    printf("Sua escolha: ");

    scanf("%d", &escolha);

    return escolha;
}

#endif