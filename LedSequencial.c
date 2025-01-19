#include <stdio.h>
#include "pico/stdlib.h"
#include "LedSequencial.h"

// Define os pinos do teclado com as portas GPIO

uint columns[4] = {13, 12, 11, 10};
uint roms[4] = {9, 8, 7, 6};

const char keymap[16] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

int main()
{
    stdio_init_all();

}