#include "Headers\\pedidos.h"

void mostrarPedido(Pedido pedido)
{
    system("cls");
    float suma = 0;
    printf("-----------------------------------------");
    printf("\nPedido %d \n", pedido.id);
    for (int i = 0; i < pedido.cantItems; i++)
    {
        suma += pedido.items[i].precio;
        printf("%s %s - %.2f\n", pedido.items[i].nombre, pedido.items[i].detalles, pedido.items[i].precio);
    }
    printf("Total: %.2f\n", suma);
    printf("-----------------------------------------\n");
    system("pause");
}

void borrarPedido(Pedido *pedido)
{
    pedido->id = 0;
    pedido->activo = 0;
    pedido->cantItems = 0;
}