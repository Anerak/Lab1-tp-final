#include <stdlib.h>
#include <stdio.h>

#define CANT_MESA 10

typedef enum {Mesero, Cajero, Manager, Owner} Rol;

typedef struct {
    int id;
    int activo;
    char nombre[20];
    char apellido[20];
    Rol rol;
} Empleado;

typedef enum {Entrada, Plato_principal, Minutas, Postre, Bebida} ComidaTipo;
//typedef enum {Minutas, Plato_principal, Minutas, Postre, Bebida} SubCategoria;

typedef struct {
    int id;
    int activo;
    char nombre[30];
    float precio;
    ComidaTipo comida_tipo;
    //SubCategoria subCategoria = 0;
} Comida;

typedef struct {
    int id;
    int activo;
    int cantItems;
    Comida items[30];
} Pedido;

typedef struct {
    int id;
    int activo;
    int sillas;
    int ocupada;
    int cantOrd;
    Pedido pedidos[30];
} Mesa;
//prototipados//
void ocuparMesa (Mesa *mesa);
void inicMesas (Mesa mesas[]);
int buscarMesa (Mesa mesas[],int id);
void desocuparMesa (Mesa *mesa);
void mostrarMesas (Mesa mesas[]);

int main ()
{
    int idMesa=0;
    char nuevaMesa = 's';
    Mesa mesas[CANT_MESA];
    inicMesas(mesas);
    mostrarMesas(mesas);
    printf("alguna mesa para por ser ocupada S/n\n");
    fflush(stdin);
    scanf("%c",&nuevaMesa);
    if (nuevaMesa == 's')
    {
        printf("Que mesa esta por ser ocupada?\n");

        scanf("%d",&idMesa);
        
        int posMesa = buscarMesa(mesas,idMesa);
        if (posMesa >-1)
        {
        ocuparMesa (&mesas[posMesa]);
        }
    }
    mostrarMesas(mesas);
}
//funcion para ocupar mesa, para tomar orden de la mesa.

//funcion para realizar pedido.

void ocuparMesa (Mesa *mesa)
{

    mesa->ocupada=1;

}
void inicMesas (Mesa mesas[])
{    
    for (int i=0; i < CANT_MESA; i++)
    {
        mesas[i].sillas=4;
        mesas[i].ocupada=0;
        mesas[i].id= i+1;
        mesas[i].activo=1;

    }
}
int buscarMesa (Mesa mesas[],int id)
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
void desocuparMesa (Mesa *mesa)
{

    mesa->ocupada=0;

}
void mostrarMesas (Mesa mesas[])
{
    printf("Mesas disponibles\n");
    for (int i = 0; i < CANT_MESA; i++)
    {
        if ((i %3 == 0)&& i>0)
        {
         printf("\n");
        }
        if (mesas[i].ocupada == 0)
        {
            printf("\t%d",mesas[i].id);
        }else{
            printf("\t|%d|",mesas[i].id);
        }
    }
    printf("\n");

}