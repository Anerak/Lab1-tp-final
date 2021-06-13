# Programa de restaurante

## Indice

* [Empleados](#Empleados)
* [Comida](#Comida)
* [Ordenes](#Orden)
* [Mesas](#Mesa)
* [Transacciones](#Transacción)

## Empleados

[↑](#Indice)

```c
typedef enum {Mesero, Cajero, Manager, Owner} Rol;

typedef struct {
    int id;
    int activo;
    char nombre[20];
    char apellido[20];
    Rol rol;
} Empleado;
```

|        Acción      |Mesero|Cajero|Manager|Owner|
|--------------------|------|------|-------|-----|
|    Tomar orden     |   x  |      |   x   |  x  |
|   Modificar orden  |   x  |      |   x   |  x  |
|   Cerrar orden     |   x  |   x  |   x   |  x  |
|   Cancelar orden   |      |      |   x   |  x  |
|   Modificar mesa   |      |      |   x   |  x  |
|   Modificar caja   |      |   x  |   x   |  x  |
|Modificar empleados |      |      |       |  x  |
|Modificar productos |      |      |   x   |  x  |

---

## Comida

[↑](#Indice)

```c
typedef enum {Entrada, Plato_principal, Postre, Bebida} ComidaTipo;

typedef struct {
    int id;
    int activo;
    char nombre[30];
    float precio;
    ComidaTipo comida_tipo;
} Comida;
```

---

## Orden

[↑](#Indice)

```c
typedef struct {
    int id;
    int activo;
    int cantItems;
    Comida items[30];
} Orden;
```

---

## Mesa

[↑](#Indice)

```c
typedef struct {
    int id;
    int activo;
    int sillas;
    int ocupada;
    int cantOrd;
    Orden orden[30];
} Mesa;
```

---

## Transacción

[↑](#Indice)

```c
typedef enum {Efectivo, Tarjeta} MedioPago;

typedef struct {
    int id;
    int orden_id;
    int cancelada;
    float monto;
    MedioPago medio_pago;
} Transaccion;
```
