# GuLyX

## Indice

* [Compilar](#Compilar)
* [Empleados](#Empleados)
* [Comida](#Comida)
* [Ordenes](#Orden)
* [Mesas](#Mesa)
* [Transacciones](#Transacción)

## Compilar

Para compilar, agremos la siguiente línea a `settings.json` de VSCode.
```json
"c": "start cmd.exe /k \"cd $dir && gcc -std=c99 $fileName menu.c empleados.c mesas.c productos.c pedidos.c ventas.c utils.c -o $fileNameWithoutExt && $dir$fileNameWithoutExt\"",
```

### Si no se esta usando VSCode, usar la siguiente línea en Command Prompt, estando en el directorio del proyecto.

```bat
start cmd.exe /k \"cd $dir && gcc -std=c99 main.c menu.c empleados.c mesas.c productos.c pedidos.c ventas.c utils.c -o gulyx.exe && gulyx.exe"
```

## Empleados

[↑](#Indice)

```c
typedef enum {Mesero, Cajero, Manager, Owner} Rol;

typedef struct {
    int id;
    int activo;.
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
typedef enum {Entrada, Plato_principal, Minutas, Postre, Bebida} ComidaTipo;
//pendiente agregar subcategoria
typedef struct {
    int id;
    int activo;
    char nombre[30];
    float precio;
    ComidaTipo comida_tipo;
    SubCategoria subCategoria = 0;
} Comida;
```

---

## Pedido

[↑](#Indice)

```c
typedef struct {
    int id;
    int activo;
    int cantItems;
    Comida items[30];
} Pedido;
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
    Pedido pedidos[30];
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
