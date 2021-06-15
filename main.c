#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//contraseña duenño
#define passOwner "admin1234";
//contraseña gerente
#define passManager "manag123";
//contraseña cajero
#define passEmploy "gul123";

typedef enum
{
    Mesero,
    Cajero,
    Manager,
    Owner
} Rol;

typedef struct
{
    int id;
    int activo;
    char nombre[20];
    char apellido[20];
    Rol rol;
} Empleado;

void mostrarLogo();
void mostrarMenu();
void inicioDuenio();
void inicioGerente();
void inicioCajero();
int SeleccionUsuario(int tipoUsuario);

int main()
{
    int tipoUsuario = 0;
    int devolUsuario = 0;

    mostrarLogo();

    mostrarMenu();

    do
    {
        scanf("                          %d", &tipoUsuario);
        devolUsuario = SeleccionUsuario(tipoUsuario);
    } while (devolUsuario == 1);

    return 0;
}

void mostrarLogo()
{
    printf("\n\n\n\n\n\n\n\n");
    printf("                               ,ad8888ba,                88\n");
    printf("                              d8\"\'    `\"8b               88\n");
    printf("                             d8\'                         88\n");
    printf("                             88             88       88  88  8b       d8  8b,     ,d8\n");
    printf("                             88      88888  88       88  88  `8b     d8\'   `Y8, ,8P\'\n");
    printf("                             Y8,        88  88       88  88   `8b   d8\'      )888(\n");
    printf("                              Y8a.    .a88  \"8a,   ,a88  88    `8b,d8'     ,d8\" \"8b,\n");
    printf("                               `\"Y88888P\"    `\"YbbdP\'Y8  88      Y88\'     8P\'     `Y8\n");
    printf("                                                                d8\'\n");
    printf("                                                               d8\'\n");
    printf("\n\n\n\n\n\n\n\n");
    printf("                                                                                             Copyright ©2020 Gulyx\n");
    printf("                                                                                              All rights reserved.\n");

    system("pause");
    system("cls");
}

void mostrarMenu()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          ----------------------------------------------------------------\n");
    printf("                          |                      Bienvenido a Gulyx!                      |\n");
    printf("                          |                                                               |\n");
    printf("                          |        Seleccione un usuario para ingresar al sistema         |\n");
    printf("                          |                                                               |\n");
    printf("                          |                          1-Duenio                             |\n");
    printf("                          |                          2-Gerente                            |\n");
    printf("                          |                          3-Cajero                             |\n");
    printf("                          |                                                               |\n");
    printf("                          ----------------------------------------------------------------\n");
}

int SeleccionUsuario(int tipoUsuario)
{
    system("cls");
    char password[9];
    char caracter;
    int flag = 0;
    int c = 0;
    if (tipoUsuario == 1)
    {
        printf("\n\n\n\n\n\n\n\n");
        printf("                          ----------------------------------------------------------------\n");
        printf("                          |                    Rango: Duenio                Gulyx         |\n");
        printf("                          |                  Ingrese contrasena:                          |\n");
        printf("                          ----------------------------------------------------------------\n");
        while (caracter = getch())
        {
            if (caracter == 13)
            {
                password[c] = '\0';
                break;
            }
            else
            {
                printf("*");
                password[c] = caracter;
                c++;
            }
        }

        if (strcmp(password, "admin1234") == 0)
        {
            inicioDuenio();
        }
        else
        {
            printf("                          \nContrasena incorrecta\n");
            flag = 1;
        }
    }
    else if (tipoUsuario == 2)
    {
        printf("\n\n\n\n\n\n\n\n");
        printf("                          ----------------------------------------------------------------\n");
        printf("                         |                             Rango: Gerente          Gulyx      |\n");
        printf("                         |                          Ingrese contrasena:                   |\n");
        printf("                          ----------------------------------------------------------------\n");
        while (caracter = getch())
        {
            if (caracter == 13)
            {
                password[c] = '\0';
                break;
            }
            else
            {
                printf("*");
                password[c] = caracter;
                c++;
            }
        }
        if (strcmp(password, "manag123") == 0)
        {
            inicioGerente();
        }
        else
        {
            printf("                          \nContrasena incorrecta\n");
            flag = 1;
        }
    }
    else
    {
        printf("\n\n\n\n\n\n\n\n");
        printf("                          ----------------------------------------------------------------\n");
        printf("                         |                         Rango: Cajero               Gulyx      |\n");
        printf("                         |                      Ingrese contrasena:                       |\n");
        printf("                          ----------------------------------------------------------------\n");
        while (caracter = getch())
        {
            if (caracter == 13)
            {
                password[c] = '\0';
                break;
            }
            else
            {
                printf("*");
                password[c] = caracter;
                c++;
            }
        }
        if (strcmp(password, "gul123") == 0)
        {
            inicioCajero();
        }
        else
        {
            printf("                          \nContrasena incorrecta\n");
            flag = 1;
        }
    }
    return flag;
}

void inicioDuenio()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          ----------------------------------------------------------------\n");
    printf("                          |  Inicio de sesion exitoso                   Gulyx             |\n");
    printf("                          |                                                               |\n");
    printf("                          |  Seleccione una opcion:                                       |\n");
    printf("                          |                                                               |\n");
    printf("                          | 1-Ingresar o eliminar empleado o gerente                      |\n");
    printf("                          | 2-Ingresar productos al menu                                  |\n");
    printf("                          | 3-Ventas del dia                                              |\n");
    printf("                          | 4-Manejo de mesas                                             |\n");
    printf("                          |                                                               |\n");
    printf("                          ----------------------------------------------------------------\n");
}

void inicioGerente()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          ----------------------------------------------------------------\n");
    printf("                          |  Inicio de sesion exitoso                     Gulyx           |\n");
    printf("                          |                                                               |\n");
    printf("                          |  Seleccione una opcion:                                       |\n");
    printf("                          |                                                               |\n");
    printf("                          | 1-Ingresar o eliminar empleado                                |\n");
    printf("                          | 2-Ingresar productos al menu                                  |\n");
    printf("                          | 3-Manejo de mesas                                             |\n");
    printf("                          |                                                               |\n");
    printf("                          ----------------------------------------------------------------\n");
}

void inicioCajero()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          ----------------------------------------------------------------\n");
    printf("                          |  Inicio de sesion exitoso                     Gulyx           |\n");
    printf("                          |                                                               |\n");
    printf("                          |  Seleccione una opcion:                                       |\n");
    printf("                          |                                                               |\n");
    printf("                          | 2-Ingresar productos al menu                                  |\n");
    printf("                          | 3-Manejo de mesas                                             |\n");
    printf("                          |                                                               |\n");
    printf("                          ----------------------------------------------------------------\n");
}

void selecIngresoOwner()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          ----------------------------------------------------------------\n");
    printf("                          |  Seleccione una opcion:                       Gulyx           |\n");
    printf("                          |                                                               |\n");
    printf("                          | 1-Empleado                                                    |\n");
    printf("                          | 2-Gerente                                                     |\n");
    printf("                          | 3-Volver al menu de opciones                                  |\n");
    printf("                          |                                                               |\n");
    printf("                          ----------------------------------------------------------------\n");
}
void ingEliEmpleado()
{

    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          ----------------------------------------------------------------\n");
    printf("                          |  Seleccione una opcion:                       Gulyx           |\n");
    printf("                          |                                                               |\n");
    printf("                          |  1-Ingresar nuevo empleado                                    |\n");
    printf("                          |  2-Editar empleado                                            |\n");
    printf("                          |  3-Eliminar empleado                                          |\n");
    printf("                          |  4-Volver al menu de opciones                                 |\n");
    printf("                          |                                                               |\n");
    printf("                          ----------------------------------------------------------------\n");
}

void ingEliGerente()
{

    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          ----------------------------------------------------------------\n");
    printf("                          |  Seleccione una opcion:                       Gulyx           |\n");
    printf("                          |                                                               |\n");
    printf("                          |  1-Ingresar nuevo gerente                                     |\n");
    printf("                          |  2-Editar gerente                                             |\n");
    printf("                          |  3-Eliminar gerente                                           |\n");
    printf("                          |  4-Volver al menu de opciones                                 |\n");
    printf("                          |                                                               |\n");
    printf("                          ----------------------------------------------------------------\n");
}

void ingStock()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          ----------------------------------------------------------------\n");
    printf("                          |  Seleccione una opcion:                       Gulyx           |\n");
    printf("                          |                                                               |\n");
    printf("                          |  1-Ingresar nuevo producto                                    |\n");
    printf("                          |  2-Editar producto                                            |\n");
    printf("                          |  3-Eliminar producto                                          |\n");
    printf("                          |  4-Volver al menu de opciones                                 |\n");
    printf("                          |                                                               |\n");
    printf("                          ----------------------------------------------------------------\n");
}

void ventasDiaras()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          ----------------------------------------------------------------\n");
    printf("                          |  Seleccione una opcion:                       Gulyx           |\n");
    printf("                          |                                                               |\n");
    printf("                          |  1-Venta diaria total                                         |\n");
    printf("                          |  2-Venta diaria por empleado                                  |\n");
    printf("                          |  3-Volver al menu de opciones                                 |\n");
    printf("                          |                                                               |\n");
    printf("                          ----------------------------------------------------------------\n");
}

void manejoMesas()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          ----------------------------------------------------------------\n");
    printf("                          |  Seleccione una Mesa:                       Gulyx             |\n");
    printf("                          |                                                               |\n");
    printf("                          |                                                               |\n");
    printf("                          |    Mesas:        | 1 |   | 2 |   | 3 |  | 4 |                 |\n");
    printf("                          |                                                               |\n");
    printf("                          |                  | 5 |   | 6 |   | 7 |  | 8 |                 |\n");
    printf("                          |                                                               |\n");
    printf("                          |  - O = Mesa ocupada                                           |\n");
    printf("                          |  0-Volver al menu de opciones                                 |\n");
    printf("                          |                                                               |\n");
    printf("                          |                                                               |\n");
    printf("                          ----------------------------------------------------------------\n");
}

void menuMesa()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          ----------------------------------------------------------------\n");
    printf("                          |  Seleccione una opcion:                       Gulyx           |\n");
    printf("                          |                                                               |\n");
    printf("                          |  1-Ingresar productos                                         |\n");
    printf("                          |  2-Editar productos                                           |\n");
    printf("                          |  3-Cobrar Mesa                                                |\n");
    printf("                          |  4-Cancelar Mesa                                              |\n");
    printf("                          |  5-Volver al menu de Mesas                                    |\n");
    printf("                          ----------------------------------------------------------------\n");
}

void ingProductosMesa()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          ----------------------------------------------------------------\n");
    printf("                          |  Seleccione una categoria:                       Gulyx        |\n");
    printf("                          |                                                               |\n");
    printf("                          | 1-Comidas                                                     |\n");
    printf("                          | 2-Bebidas                                                     |\n");
    printf("                          | 3-Postres                                                     |\n");
    printf("                          | 4-Volver al menu de Mesas                                     |\n");
    printf("                          |                                                               |\n");
    printf("                          ----------------------------------------------------------------\n");
}
