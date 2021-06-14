#include <stdio.h>
#include <string.h>

typedef enum
{
    Efectivo,
    Tarjeta = 12,
} MedioPago;

typedef enum
{
    Entrada,
    Plato_principal,
    Postre,
    Bebida
} ComidaTipo;

void showMenu();

int main()
{
    printf("%d\n",Tarjeta);
    Tarjeta = 5;
    printf("%d\n",Tarjeta);
    return 0;
}