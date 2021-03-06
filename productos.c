#include "Headers\\productos.h"

//int main()
//{
//    Comida productos[PRODUCTOS_LIMITE];
//    if (productosPrueba(productos))
//    {
//        printf("Productos de prueba anadidos satisfactoriamente");
//    }
//    guardarProductos(productos);
//    return 0;
//}

int productosPrueba(Comida productos[])
{
    char *nombres[] = {
        "Sorrentinos", "Canelones", "Fideos", "Milanesa", "Hamburguesa", "Pechuga Grille", "Pizza", "Pizza", "Pizza", "Empanadas", "Empanadas", "Empanadas", "Empanadas", "Empanadas", "Coca Cola", "Sprite", "Fanta", "Agua", "Agua", "Gatorade", "Vasco Viejo 3/4", "Vasco Viejo 3/4", "Santa Julia 3/4", "Fernet", "Gin Tonic", "Caipirinha", "Caipiroska", "Almendrado", "Tricolor", "Bombon", "Bombon", "Bocha de helado", "Bocha de helado", "Flan", "Flan", "Flan", "Chocotorta", "Lemon Pie"};
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
        agregarProducto(&productos[i], nombres[i], detalles[i], precios[i], i + 1, comidaTipo[i], comidaSubcategoria[i]);
    }

    return size;
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

int buscarPosProducto(Comida productos[PRODUCTOS_LIMITE], int size, int id)
{
    for (int i = 0; i < size; i++)
    {
        if (productos[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void mostrarCarta(Comida productos[PRODUCTOS_LIMITE], int size)
{
    Comida tmp;

    printf("-----------------------\n");
    printf("|\tMenu\n");
    printf("-----------------------\n");

    for (int x = 0; x < 4; x++)
    {
        if (x > 0)
        {
            printf("\n-----------------------\n");
            printf("|\t");
        }
        switch (x)
        {
        //case 0:
        //    printf("Entradas\n");
        //    break;
        case 1:
            printf("Platos principales\n");
            break;
        case 2:
            printf("Postres\n");
            break;
        case 3:
            printf("Bebidas\n");
            break;
        default:
            break;
        }
        if (x > 0)
        {

            printf("-----------------------\n");
        }

        for (int i = 0; i < size; i++)
        {
            if (productos[i].comida_tipo == x)
            {
                tmp = productos[i];
                printf("|\t(%d) %s %s\n", tmp.id, tmp.nombre, tmp.detalles);
                printf("|\t\t $%.2f\n", tmp.precio);
            }
        }
    }
}