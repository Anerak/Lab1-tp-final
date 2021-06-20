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

int main()
{
    Comida productos[PRODUCTOS_LIMITE];
    if (productosPrueba(productos))
    {
        printf("Productos de prueba anadidos satisfactoriamente");
    }
    guardarProductos(productos);
    return 0;
}

int productosPrueba(Comida productos[])
{
    char *nombres[] = {
        "Sorrentinos",
        "Canelones",
        "Fideos",
        "Milanesa",
        "Hamburguesa",
        "Pechuga Grille",
        "Pizza",
        "Pizza",
        "Pizza",
        "Empanadas",
        "Empanadas",
        "Empanadas",
        "Empanadas",
        "Empanadas",
        "Coca Cola",
        "Sprite",
        "Fanta",
        "Agua",
        "Agua",
        "Gatorade",
        "Vasco Viejo 3/4",
        "Vasco Viejo 3/4",
        "Santa Julia 3/4",
        "Fernet",
        "Gin Tonic",
        "Caipirinha",
        "Caipiroska", "Almendrado", "Tricolor", "Bombon", "Bombon", "Bocha de helado", "Bocha de helado", "Flan", "Flan", "Flan", "Chocotorta", "Lemon Pie"};
    char *detalles[] = {
        "con bolognesa", "con filetto", "con salsa blanca", "a caballo", "completa", "con ensalada", "Napolitana", "Especial", "Extra Gulyx", "Carne", "Pollo", "Jamon y Queso", "Capresse", "Humita", "", "", "", "Saborizada", "c/s gas", "", "Tinto", "Blanco", "Blanco", "con Coca Cola", "", "", "", "", "", "Suizo", "Escoces", "Chocolate", "Vainilla", "solo", "con dulce de leche o crema", "mixto", "", ""};
    float precios[] = {
        260.0, 230.0, 200.0, 250.0, 280.0, 300.0, 500.0, 500.0, 500.0, 70.0, 70.0, 70.0, 70.0, 70.0, 120.0, 120.0, 120.0, 140.0, 100.0, 180.0, 260.0, 260.0, 350.0, 300.0, 300.0, 340.0, 340.0, 160.0, 160.0, 180.0, 180.0, 100.0, 100.0, 140.0, 170.0, 190.0, 300.0, 280.0};
    ComidaTipo comidaTipo[] = {
        Plato_principal, Plato_principal, Plato_principal, Plato_principal, Plato_principal, Plato_principal, Plato_principal, Plato_principal, Plato_principal, Plato_principal, Plato_principal, Plato_principal, Plato_principal, Plato_principal, Bebida, Bebida, Bebida, Bebida, Bebida, Bebida, Bebida, Bebida, Bebida, Bebida, Bebida, Bebida, Bebida, Postre, Postre, Postre, Postre, Postre, Postre, Postre, Postre, Postre, Postre, Postre};
    ComidaSubcategoria comidaSubcategoria[] = {
        Pastas, Pastas, Pastas, Minutas, Minutas, Minutas, Pizzas, Pizzas, Pizzas, Empanadas, Empanadas, Empanadas, Empanadas, Empanadas, Gaseosas, Gaseosas, Gaseosas, Aguas, Aguas, Aguas, Vinos, Vinos, Vinos, Tragos, Tragos, Tragos, Tragos, Helados, Helados, Helados, Helados, Helados, Helados, Flan, Flan, Flan, Cupcakes, Cupcakes};

    int size = sizeof(nombres) / sizeof(nombres[0]);
    int i = 0;
    for (i; i < size; i++)
    {
        if (nombres[i] == NULL && detalles[i] == NULL)
        {
            break;
        }
        agregarProducto(&productos[i], nombres[i], detalles[i], precios[i], i, comidaTipo[i], comidaSubcategoria[i]);
    }

    printf("\nProductos cargados\n");
    return 1;
}

int agregarProducto(Comida *producto, char nombre[40], char detalles[40], float precio, int id, int comidaTipo, int comidaSubcategoria)
{
    producto->activo = 1;
    producto->id = id;
    producto->precio = precio;

    strcpy(producto->nombre, nombre);
    strcpy(producto->detalles, detalles);

    producto->comida_tipo = comidaTipo;
    producto->subCategoria = comidaSubcategoria;

    return 1;
}

void mostrarProducto(Comida producto)
{
    printf("\nID: %d\n", producto.id);
    printf("\nNombre: %s\n", producto.nombre);
    printf("Detalles: %s\n", producto.detalles);
    printf("Precio: %.2f\n", producto.precio);
    printf("Categoria: %d\n", producto.comida_tipo);
    printf("Subcategoria: %d\n", producto.subCategoria);
    printf("\n");
}

int guardarProductos(Comida productos[PRODUCTOS_LIMITE])
{
    FILE *fProductos;
    char *ubicacion = "Productos.dat";

    fProductos = fopen(ubicacion, "wb");
    if (fProductos != NULL)
    {
        fwrite(&productos, sizeof(Comida), 1, fProductos);
        return 1;
    }
    fclose(fProductos);
    return 0;
}