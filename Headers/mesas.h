#include "pedidos.h"

typedef struct
{
    int id;
    int activo;
    int sillas;
    int ocupada;
    int cantOrd;
    Pedido pedidos[30];
} Mesa;

#define CANT_MESA 12

void ocuparMesa(Mesa *mesa);
void inicMesas(Mesa mesas[]);
int buscarMesa(Mesa mesas[], int id);
void desocuparMesa(Mesa *mesa);
void mostrarMesas(Mesa mesas[]);
void ordenMesa(Comida productos[PRODUCTOS_LIMITE], int size, Mesa *mesa);
void restablecerMesas(Mesa mesas[]);
void vaciarMesa(Mesa *mesa);
void menuMesas();
void funcionesMesas();