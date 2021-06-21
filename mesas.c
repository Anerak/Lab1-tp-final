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
void restablecerMesas(Mesa mesas[])
{
    for (int i = 0; i < CANT_MESA; i++)
    {
        vaciarMesa(&mesas[i]);
    }

}
void vaciarMesa (Mesa *mesa)
{

    desocuparMesa(mesa);
    borrarPedido(mesa->pedidos);
    mesa->cantOrd=0;

}