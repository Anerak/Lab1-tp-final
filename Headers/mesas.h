#include "Headers\\pedidos.h"
#define CANT_MESA 10

void ocuparMesa(Mesa *mesa);
void inicMesas(Mesa mesas[]);
int buscarMesa(Mesa mesas[], int id);
void desocuparMesa(Mesa *mesa);
void mostrarMesas(Mesa mesas[]);
void ordenMesa(Comida productos[PRODUCTOS_LIMITE], int size, Mesa *mesa);

typedef struct
{
    int id;
    int activo;
    int sillas;
    int ocupada;
    int cantOrd;
    Pedido pedidos[30];
} Mesa;