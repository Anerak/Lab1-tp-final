#include <stdio.h>
#include <string.h>

typedef enum
{
    Efectivo,
    Tarjeta
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
    printf("%d\n", Tarjeta == Entrada);
    return 0;
}