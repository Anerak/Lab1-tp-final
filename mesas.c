#include "Headers\\mesas.h"
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
    printf("Mesas disponibles\n\n");
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
        printf("carta\n");
        mostrarCarta(productos, size);
        printf("Que producto desea ingresar?\n");

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
void vaciarMesa(Mesa *mesa)
{

    desocuparMesa(mesa);
    borrarPedido(mesa->pedidos);
    mesa->cantOrd = 0;
}
void menuMesas()
{
    printf("1) Mostrar mesa\n");
    printf("2) Ocupar mesa\n");
    printf("3) Tomar orden mesa\n");
    printf("4) Cobrar mesa/desocupar\n");
    printf("5) Volver a menu inicial\n");
}
void funcionesMesas()
{
    int idMesa = 0;
    char nuevaMesa = 's';
    int opciones = 0;
    Comida productos[PRODUCTOS_LIMITE];
    int productosCargados = 0;

    productosCargados = productosPrueba(productos);
    if (productosCargados == -1)
    {
        printf("Error cargando productos!");
    }
    Mesa mesas[CANT_MESA];

    inicMesas(mesas);

    do
    {
        menuMesas();
        scanf("%d", &opciones);
        switch (opciones)
        {
        case 1:
            mostrarMesas(mesas); //muestra mesas todas vacias
            break;

        case 2:
            mostrarMesas(mesas);
            printf("Alguna mesa para por ser ocupada S/N\n");
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

                    ocuparMesa(&tmpMesa); //ocupa mesa
                }
                break;

            case 3:
                if (posMesa > -1)
                {
                    Mesa tmpMesa = mesas[posMesa];
                    Pedido tmpPedido;
                    ordenMesa(productos, productosCargados, &tmpMesa); // mostrar carta , ordena mesa

                    mostrarPedido(tmpMesa.pedidos[tmpMesa.cantOrd - 1]);
                }
                break;

            case 4:
                if (posMesa > -1)
                {
                    Mesa tmpMesa = mesas[posMesa];
                    Pedido tmpPedido; // mostrar carta , ordena mesa

                    mesas[posMesa] = tmpMesa;

                    mostrarMesas(mesas);

                    vaciarMesa(&mesas[posMesa]); //cobrar mesa, limpiarmesa(desocupar) mesa.
                    mostrarPedido(mesas[posMesa].pedidos[0]);
                }
                break;

            case 5:
                nuevaMesa = 'm';
                break;
            }
        }

        system("pause");
        system("cls");

    } while (nuevaMesa == 's');
}
