#include "Headers\\mesas.h"

// Inicializa las mesas
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

// Busca la mesa en el arreglo y devuelve la posicion
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

// Ocupar la mesa elegida
void ocuparMesa(Mesa *mesa)
{
    if (mesa->ocupada == 1)
    {
        printf("\nLa mesa %d ya esta ocupada\n", mesa->id);
        system("pause");
        return;
    }
    mesa->ocupada = 1;
}

// Desocupar mesa elegida
void desocuparMesa(Mesa *mesa)
{

    mesa->ocupada = 0;
}
// Mostrar todas las mesas
void mostrarMesas(Mesa mesas[])
{
    system("cls");
    printf("\t\tMesas disponibles\n\n");
    for (int i = 0; i < CANT_MESA; i++)
    {
        if ((i % 3 == 0) && i > 0)
        {
            printf("\n");
        }
        if (mesas[i].ocupada == 0)
        {
            printf("\t\t%d", mesas[i].id);
        }
        else
        {
            printf("\t\t\b|%d|", mesas[i].id);
        }
    }
    printf("\n\n");
}

// Toma la orden de la mesa
void ordenMesa(Comida productos[PRODUCTOS_LIMITE], int size, Mesa *mesa)
{
    if (mesa->ocupada == 0)
    {
        ocuparMesa(mesa);
    }
    Pedido *temp;
    Comida tempComida;
    int categoria = 0, idProducto = 0;
    int posProducto = 0;
    char seguir = 's';
    temp = &mesa->pedidos[mesa->cantOrd];
    temp->cantItems = 0;
    temp->id = mesa->cantOrd + 1;

    do
    {
        printf("carta\n");
        mostrarCarta(productos, size);
        printf("Que producto desea ingresar?\n");

        fflush(stdin);
        scanf("%d", &idProducto);

        posProducto = buscarPosProducto(productos, size, idProducto);
        if (posProducto > -1)
        {
            // Accedemos al ultimo itenm del ultimo pedido de la mesa
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

        printf("Desea continuar ingresando pedidos? s/n \n");
        fflush(stdin);
        scanf("%c", &seguir);

    } while (seguir == 's');
    mesa->cantOrd++;
}
void restablecerMesas(Mesa mesas[])
{
    for (int i = 0; i < CANT_MESA; i++)
    {
        vaciarMesa(&mesas[i]);
    }
}
// Vacia la mesa elegida
void vaciarMesa(Mesa *mesa)
{

    desocuparMesa(mesa);
    borrarPedido(mesa->pedidos);
    mesa->cantOrd = 0;
}

// Inicializar las funciones de meses
void initFuncionesMesas()
{
    system("cls");
    Comida productos[PRODUCTOS_LIMITE];
    int productosCargados = productosPrueba(productos);
    if (productosCargados == -1)
    {
        printf("Error cargando productos!");
    }

    Mesa mesas[CANT_MESA];
    inicMesas(mesas);

    mesasMenuFunciones(productos, productosCargados, mesas);
}

// Switch para el menu de opciones
void mesasMenuFunciones(Comida productos[PRODUCTOS_LIMITE], int size, Mesa mesas[CANT_MESA])
{
    int op = 0;
    int aux = 0;
    do
    {
        menuMesa();
        gotoxy(54, 9);
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            mostrarMesas(mesas);
            system("pause");
            break;
        case 2:
            ocuparMesa(&mesas[elegirMesa(mesas)]);
            break;
        case 3:
            ordenMesa(productos, size, &mesas[elegirMesa(mesas)]);
            break;
        case 4:
            aux = elegirMesa(mesas);
            cargarVentaArchivo(cargaVenta(cobrarMesa(mesas[aux])));
            vaciarMesa(&mesas[aux]);
            break;
        case 0:
            return;
            break;
        default:
            break;
        }
    } while (op != 0);
}

// Devolver posicion de mesa
int elegirMesa(Mesa mesas[CANT_MESA])
{
    int mesaId = 0;
    system("cls");
    printf("\nElija una mesa\n");
    mostrarMesas(mesas);
    printf("\nIngrese la mesa elegida: ");
    scanf("%d", &mesaId);
    mesaId -= 1;
    return mesaId;
}

// Cobrar mesa devuelve el monto total de la mesa
int cobrarMesa(Mesa mesa)
{
    int total = 0;
    for (int i = 0; i < mesa.cantOrd; i++)
    {
        for (int x = 0; x < mesa.pedidos[i].cantItems; x++)
        {
            total += (int)mesa.pedidos[i].items[x].precio;
        }
    }
    return total;
}
