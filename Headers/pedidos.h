#include "Headers\\productos.h"

typedef struct Pedido
{
    int id;
    int activo;
    int cantItems;
    Comida items[30];
} Pedido;