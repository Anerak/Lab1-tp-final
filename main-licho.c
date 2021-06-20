#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CANT_MESA 10
#define PRODUCTOS_LIMITE 50
typedef enum
{
    Mesero,
    Cajero,
    Manager,
    Owner
} Rol;

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

typedef struct
{
    int id;
    int activo;
    char nombre[20];
    char apellido[20];
    Rol rol;
} Empleado;

typedef struct Pedido
{
    int id;
    int activo;
    int cantItems;
    Comida items[30];
} Pedido;

typedef struct
{
    int id;
    int activo;
    int sillas;
    int ocupada;
    int cantOrd;
    Pedido pedidos[30];
} Mesa;
//prototipados//
void ocuparMesa(Mesa *mesa);
void inicMesas(Mesa mesas[]);
int buscarMesa(Mesa mesas[], int id);
void desocuparMesa(Mesa *mesa);
void mostrarMesas(Mesa mesas[]);
int productosPrueba(Comida productos[]);
void agregarProducto(Comida *producto, char nombre[40], char detalles[40], float precio, int id, int comidaTipo, int comidaSubcategoria);
void mostrarProducto(Comida producto);
int guardarProductos(Comida productos[PRODUCTOS_LIMITE]);
int buscarPosProducto(Comida productos[PRODUCTOS_LIMITE], int size, int id);
void ordenMesa(Comida productos[PRODUCTOS_LIMITE], int size, Mesa *mesa);
void mostrarPedido(Pedido pedido);

int main()
{
    int idMesa = 0;
    char nuevaMesa = 's';
    Comida productos[PRODUCTOS_LIMITE];
    int productosCargados = 0;
    productosCargados = productosPrueba(productos);
    if (productosCargados == -1)
    {
        printf("Error cargando productos!");
    }
    Mesa mesas[CANT_MESA];
    inicMesas(mesas);
    mostrarMesas(mesas);

    printf("alguna mesa para por ser ocupada S/n\n");
    fflush(stdin);
    scanf("%c", &nuevaMesa);

    if (nuevaMesa == 's')
    {
        printf("Que mesa esta por ser ocupada?\n");

        scanf("%d", &idMesa);

        int posMesa = buscarMesa(mesas, idMesa);
        if (posMesa > -1)
        {
            Mesa tmpMesa = mesas[posMesa];
            Pedido tmpPedido;
            ocuparMesa(&tmpMesa);
            ordenMesa(productos, productosCargados, &tmpMesa);
            
            mostrarPedido(tmpMesa.pedidos[tmpMesa.cantOrd - 1]);
            mesas[posMesa]= tmpMesa;
            //tmpPedido = tmpMesa.pedidos[0];
            //printf("%d\n", tmpPedido.id);
            //printf("%s %s", tmpPedido.items[0].nombre, tmpPedido.items[0].detalles);
        }
    }
    mostrarMesas(mesas);

    return 0;
}
//funcion para ocupar mesa, para tomar orden de la mesa.

//funcion para realizar pedido.

void ocuparMesa(Mesa *mesa)
{

    mesa->ocupada = 1;
}
void inicMesas(Mesa mesas[])
{
    for (int i = 0; i < CANT_MESA; i++)
    {
        mesas[i].sillas = 4;
        mesas[i].ocupada = 0;
        mesas[i].id = i + 1;
        mesas[i].activo = 1;
        mesas[i].cantOrd = 0;
    }
}
int buscarMesa(Mesa mesas[], int id)
{

    for (int i = 0; i < CANT_MESA; i++)
    {
        if (mesas[i].id == id)
        {
            return i;
        }
    }
    printf("No se encontro la mesa\n");
    return -1;
}
void desocuparMesa(Mesa *mesa)
{

    mesa->ocupada = 0;
}
void mostrarMesas(Mesa mesas[])
{
    printf("Mesas disponibles\n");
    for (int i = 0; i < CANT_MESA; i++)
    {
        if ((i % 3 == 0) && i > 0)
        {
            printf("\n");
        }
        if (mesas[i].ocupada == 0)
        {
            printf("\t%d", mesas[i].id);
        }
        else
        {
            printf("\t|%d|", mesas[i].id);
        }
    }
    printf("\n");
}
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
    printf("CARGA TOTAL DE PRODUCTOS: %d", size);
    for (int i = 0; i < size; i++)
    {
        if (nombres[i] == NULL && detalles[i] == NULL)
        {
            break;
        }
        agregarProducto(&productos[i], nombres[i], detalles[i], precios[i], i, comidaTipo[i], comidaSubcategoria[i]);
    }

    printf("\nProductos cargados\n");
    return size;
}
void agregarProducto(Comida *producto, char nombre[40], char detalles[40], float precio, int id, int comidaTipo, int comidaSubcategoria)
{
    producto->activo = 1;
    producto->id = id;
    producto->precio = precio;

    strcpy(producto->nombre, nombre);
    strcpy(producto->detalles, detalles);

    producto->comida_tipo = comidaTipo;
    producto->subCategoria = comidaSubcategoria;
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
void ordenMesa(Comida productos[PRODUCTOS_LIMITE], int size, Mesa *mesa)
{
    Pedido *temp;
    Comida tempComida;
    int categoria = 0, idProducto = 0;
    int posProducto = 0;
    char seguir = 's';
    temp = &mesa->pedidos[mesa->cantOrd];
    temp->cantItems = 0;
    //mesa->pedidos[mesa->cantOrd] = temp;
    temp->id = mesa->cantOrd + 1;
    do
    {
        printf("Elija la categoria 1 2 3\n");
        scanf("%d", &categoria);
        fflush(stdin);
        switch (categoria)
        {
        case 1:
            printf("Comidas\n");
            fflush(stdin);
            scanf("%d", &idProducto);
            posProducto = buscarPosProducto(productos, size, idProducto);
            if (posProducto > -1)
            {
                mesa->pedidos[mesa->cantOrd].items[mesa->pedidos->cantItems] = productos[posProducto];
                tempComida = productos[posProducto];
                printf("\nAgregando %s %s\n", tempComida.nombre, tempComida.detalles);
                temp->items[temp->cantItems] = tempComida;
                temp->cantItems++;
            }
            else
            {
                printf("\nNo se pudo encontrar el producto indicado\n");
            }
            break;
        case 2:
            printf("Bebidas\n");
            break;
        case 3:
            printf("Postres\n");
            break;

        default:
            break;
        }
        printf("Desea continuar ingresando pedidos? s/n \n");
        fflush(stdin);
        scanf("%c", &seguir);
    } while (seguir == 's');
    mesa->cantOrd++;
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
    printf("No se pudo encontrar el producto en buscarPosProducto");
    return -1;
}
void mostrarPedido(Pedido pedido)
{
    float suma = 0;
    printf("\nPedido %d \n", pedido.id);
    for (int i = 0; i < pedido.cantItems; i++)
    {
        suma += pedido.items[i].precio;
        printf("%s %s - %.2f\n", pedido.items[i].nombre, pedido.items[i].detalles, pedido.items[i].precio);
    }
    printf("Total: %.2f\n", suma);
}