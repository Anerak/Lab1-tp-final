
#include "Headers\\utils.h"

void gotoxy(int x, int y)
{
    HANDLE Manipulador;
    COORD Coordenadas;
    Manipulador = GetStdHandle(STD_OUTPUT_HANDLE);
    Coordenadas.X = x;
    Coordenadas.Y = y;
    SetConsoleCursorPosition(Manipulador, Coordenadas);
}