#include "productos.h"

typedef struct Pedido
{
    int id;
    int activo;
    int cantItems;
    Comida items[30];
} Pedido;

void mostrarPedido(Pedido pedido);

void borrarPedido(Pedido *pedido);