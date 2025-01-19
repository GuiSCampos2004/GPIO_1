#ifndef MENU_H
#define MENU_H

#include <stdio.h>

void display_menu() {
    printf("\n========= MENU PRINCIPAL =========\n");
   
    printf("1. Ativar LED Verde.\n");
    printf("2. Ativar LED Azul. \n");
    printf("A. Ativar Buzzer.\n");
    printf("0. Sair\n");
    printf("==================================\n");
    printf("Escolha uma opção: ");
}
#endif