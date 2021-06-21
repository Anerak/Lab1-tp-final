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