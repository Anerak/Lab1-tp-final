typedef enum {Efectivo, Tarjeta} MedioPago;

typedef struct {
    int id;
    int activo;
    int monto;
    MedioPago medio_pago;
} Venta;