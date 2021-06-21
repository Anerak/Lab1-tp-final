#include <stdio.h>
#include <string.h>

#define PRODUCTOS_LIMITE 50

typedef enum
{
    Entrada,
    Plato_principal,
    Postre,
    Bebida
} ComidaTipo;

typedef enum
{
    Pastas = 100,
    Minutas,
    Pizzas,
    Empanadas,
    Gaseosas = 200,
    Aguas,
    Vinos,
    Tragos,
    Helados = 300,
    Flan,
    Cupcakes
} ComidaSubcategoria;

typedef struct
{
    int id;
    int activo;
    char nombre[40];
    char detalles[40];
    float precio;
    ComidaTipo comida_tipo;
    ComidaSubcategoria subCategoria;
} Comida;

int productosPrueba(Comida productos[]);
int agregarProducto(Comida *producto, char nombre[40], char detalles[40], float precio, int id, int comidaTipo, int comidaSubcategoria);
void mostrarProducto(Comida producto);
int guardarProductos(Comida productos[PRODUCTOS_LIMITE]);
int buscarPosProducto(Comida productos[PRODUCTOS_LIMITE], int size, int id);
void mostrarCarta(Comida productos[PRODUCTOS_LIMITE], int size);