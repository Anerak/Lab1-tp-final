# Programa de comida

## Empleados

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

|       Acción      |Mesero|Cajero|Manager|Owner|
|-------------------|------|------|-------|-----|
|Tomar orden        |     x|      |      x|    x|
|Modificar orden    |     x|      |      x|    x|
|Cerrar orden       |     x|     x|      x|    x|
|Cancelar orden     |      |      |      x|    x|
|Modificar mesa     |      |      |      x|    x|
|Modificar empleados|      |      |       |    x|
|Modificar productos|      |      |      x|    x|
|Modificar caja     |      |     x|      x|    x|

---

## Comida

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

## Mesa

```c
typedef struct {
    int id;
    int activo;
    int sillas;
    int ocupada;
    Orden orden[30];
}
```

---

## Transacción

```c
typedef enum {Efectivo, Tarjeta} MEDIOPAGO;

typedef struct {
    int id;
    int orden_id;
    int cancelada;
    float monto;
    MEDIOPAGO medio_pago;
} Transaccion;
```
