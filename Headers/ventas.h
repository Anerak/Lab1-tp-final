#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
    Efectivo,
    Tarjeta
} MedioPago;

typedef struct
{
    int id;
    int activo;
    int monto;
    MedioPago medio_pago;
} Venta;

#define ventasTotales "ventas.dat"
int ventaidRandom();
int comprobarIdventa(int idrand);
Venta cargaVenta(int cobroTotal);
void cargarVentaArchivo(Venta cobro);
void mostrarVenta(Venta unaVenta);
void totalVentas();