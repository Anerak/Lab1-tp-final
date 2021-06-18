#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

//contraseña duenño
#define passOwner "admin1234"
//contraseña gerente
#define passManager "manag123"
//contraseña cajero
#define passEmploy "gul123"

#define datosempleados "empleado.dat"

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
void mostrarDuenio();
void mostrarGerente();
void mostrarCajero();
void inicioDuenio();
void inicioGerente();
void inicioCajero();
void SeleccionUsuario(int tipoUsuario);
void selecIngresoOwner();
void ingEliEmpleado();
void ingEliGerente();
void manejoMesas();
void menuMesa();
void ingProductosMesa();
void ingComidas();
void ingBebidas();
void ingPostres();
void gotoxy(int x, int y);
Empleado agregarEmpl(int rolValido);
void addEmpFile(Empleado empleados);

int main()
{
    Empleado empleados[50];
    system("COLOR B0");

    int tipoUsuario = 0;
    int devolUsuario = 0;

    mostrarLogo();

    do
    {
        system("cls");
        mostrarMenu();
        gotoxy(85, 11);
        scanf("%d", &tipoUsuario);
    } while (tipoUsuario < 0 || tipoUsuario > 3);

    SeleccionUsuario(tipoUsuario);

    return 0;
}
int comprobarPass(int tipoUsuario)
{

    char password[9];
    char caracter;
    int flag = 0;
    int c = 0;

    switch (tipoUsuario)
    {
    case 1:
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
        if (strcmp(password, passOwner) == 0)
        {
            inicioDuenio();
        }
        else
        {
            gotoxy(65, 11);
            printf("Contrasena incorrecta");
            gotoxy(46, 13);
            system("pause");
            flag = 1;
        }
        break;
    case 2:

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
        if (strcmp(password, passManager) == 0)
        {
            inicioGerente();
        }
        else
        {
            gotoxy(65, 11);
            printf("Contrasena incorrecta");
            gotoxy(46, 13);
            system("pause");
            flag = 1;
        }

    case 3:
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
        if (strcmp(password, passEmploy) == 0)
        {
            manejoMesas();
        }
        else
        {
            gotoxy(65, 11);
            printf("Contrasena incorrecta");
            gotoxy(46, 13);
            system("pause");
            flag = 1;
        }
    }

    return flag;
}

void SeleccionUsuario(int tipoUsuario)
{
    system("cls");
    char password[9];
    char caracter;
    int flag = 0;
    int c = 0;
    int passcomprobation = 0;
    int opmenu2 = 0;
    do
    {
        switch (tipoUsuario)
        {

        case 1:

            system("cls");
            mostrarDuenio();
            gotoxy(65, 11);
            passcomprobation = comprobarPass(tipoUsuario);
            gotoxy(52, 11);
            scanf("%d", &opmenu2);
            menu2duenio(opmenu2);

            break;
        case 2:

            system("cls");
            mostrarGerente();
            gotoxy(65, 11);
            passcomprobation = comprobarPass(tipoUsuario);

            break;
        case 3:

            system("cls");
            mostrarCajero();
            gotoxy(65, 11);
            passcomprobation = comprobarPass(tipoUsuario);

            break;
        }
    } while (passcomprobation == 1);
}
void menu2duenio(int op)
{
    int opelegida = 0;
    switch (op)
    {
    case 1:
        ingEliEmpleado();
        gotoxy(55, 9);
        scanf("%d", &opelegida);
        ingelempSwitch(opelegida);

        break;
    }
}

void ingelempSwitch(int op)
{

    switch (op)
    {
    case 1:
        mostrarArchEmpl();
        break;

    case 2:
        cargEstrucYarchi(1);

        break;
    }
}

void gotoxy(int x, int y)
{
    HANDLE Manipulador;
    COORD Coordenadas;
    Manipulador = GetStdHandle(STD_OUTPUT_HANDLE);
    Coordenadas.X = x;
    Coordenadas.Y = y;
    SetConsoleCursorPosition(Manipulador, Coordenadas);
}
Empleado agregarEmpl(int rolValido)
{
    system("cls");
    Empleado aux;
    int opEmp = 0;
    aux.id = idRandom();
    printf("\n\n\n\n\n\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |                                                    Gulyx      |\n");
    printf("                          | ID del empleado:  %d                                          |\n", aux.id);
    printf("                          |                                                               |\n");
    printf("                          |Ingrese SOLO el nombre:                                        |\n");
    printf("                          |                                                               |\n");
    printf("                          |Ingrese el apellido:                                           |\n");

    if (rolValido == 1)
    {
        printf("                          |Seleccione un Rol:    1-Gerente  2-Cajero  3-Camarero          |\n");
    }
    else
    {
        printf("                          |Seleccione un Rol:      1-Cajero  2-Camarero                   |\n");
    }
    printf("                          |        Opcion:                                                |\n");
    printf("                          '---------------------------------------------------------------'\n");
    gotoxy(53, 11);
    gets(aux.nombre);
    gotoxy(49, 13);
    gets(aux.apellido);
    if (rolValido == 1)
    {
        do
        {
            scanf("%d", opEmp);
        } while (opEmp < 0 || opEmp > 3);
    }
    else
    {
        do
        {
            scanf("%d", opEmp);
        } while (opEmp < 0 || opEmp > 2);
    }
    aux.rol = opEmp;

    aux.activo = 1;

    return aux;
}

void addEmpFile(Empleado empleados)
{
    FILE *archi = fopen(datosempleados, "ab");

    if (archi == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        fwrite(&empleados, sizeof(Empleado), 1, archi);
        fclose(datosempleados);
    }
}
void cargEstrucYarchi(int rolValido)
{
    char seguir = 's';
    Empleado aux;
    while (seguir == 's')
    {
        aux = agregarEmpl(rolValido);
        printf("Desea cargar otro empleado? s/n\n");
        fflush(stdin);
        scanf("%c", &seguir);
    }
}

void mostrarEmpleado(Empleado empleados)
{
    printf("\n\n\n\n\n\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |                                                    Gulyx      |\n");
    printf("                          | ID del empleado: %i                                           |\n", empleados.id);
    printf("                          |                                                               |\n");
    printf("                          |Ingrese SOLO el nombre: %s                                     |\n", empleados.nombre);
    printf("                          |                                                               |\n");
    printf("                          |Ingrese el apellido: %s                                        |\n", empleados.apellido);
    printf("                          |                                                               |\n");
    printf("                          |Rol: %i                                                        |\n", empleados.rol);
    printf("                          |                                                               |\n");
    printf("                          '---------------------------------------------------------------'\n");
}
int idRandom()
{

    srand(time(NULL));
    int numrand = 1 + rand() % 1000;
    comprobarId(numrand);

    return numrand;
}
void comprobarId(int idrand)
{
    FILE *archi = fopen(datosempleados, "rb");
    Empleado aux;
    int flag = 0;
    do
    {
        if (archi != NULL)
        {
            while (fread(&aux, sizeof(Empleado), 1, archi) > 0 && flag == 0)
            {
                if (aux.id == idrand)
                {
                    idrand++;
                    flag = 1;
                }
            }
            fclose(archi);
        }

    } while (flag == 1);
}

void mostrarArchEmpl()
{
    Empleado aux;
    FILE *archi = fopen(datosempleados, "rb");
    if (archi != NULL)
    {
        while (fread(&aux, sizeof(Empleado), 1, archi) > 0)
        {
            mostrarEmpleado(aux);
        }
        fclose(archi);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
}
void mostrarMenu()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |                      Bienvenido a Gulyx!                      |\n");
    printf("                          |                                                               |\n");
    printf("                          |        Seleccione un usuario para ingresar al sistema:        |\n");
    printf("                          |                                                               |\n");
    printf("                          |                          1-Duenio                             |\n");
    printf("                          |                          2-Gerente                            |\n");
    printf("                          |                          3-Cajero                             |\n");
    printf("                          |                                                               |\n");
    printf("                          '---------------------------------------------------------------'\n");
}

void mostrarDuenio()
{
    printf("\n\n\n\n\n\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |                                                    Gulyx      |\n");
    printf("                          |                    Rango: Duenio                              |\n");
    printf("                          |                  Ingrese contrasena:                          |\n");
    printf("                          |                                                               |\n");
    printf("                          |                                                               |\n");
    printf("                          '---------------------------------------------------------------'\n");
}

void mostrarGerente()
{
    printf("\n\n\n\n\n\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |                                                    Gulyx      |\n");
    printf("                          |                      Rango: Gerente                           |\n");
    printf("                          |                   Ingrese contrasena:                         |\n");
    printf("                          |                                                               |\n");
    printf("                          |                                                               |\n");
    printf("                          '---------------------------------------------------------------'\n");
}

void mostrarCajero()
{
    printf("\n\n\n\n\n\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |                                                     Gulyx     |\n");
    printf("                          |                      Rango: Cajero                            |\n");
    printf("                          |                   Ingrese contrasena:                         |\n");
    printf("                          |                                                               |\n");
    printf("                          |                                                               |\n");
    printf("                          '---------------------------------------------------------------'\n");
}

void inicioDuenio()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |  Inicio de sesion exitoso                   Gulyx             |\n");
    printf("                          |                                                               |\n");
    printf("                          |  Seleccione una opcion:                                       |\n");
    printf("                          |                                                               |\n");
    printf("                          | 1-Ingresar/eliminar/ver empleado o gerente                    |\n");
    /*  printf("                          | 2-Ingresar productos al menu                                  |\n");*/
    printf("                          | 2-Ventas del dia                                              |\n");
    printf("                          | 3-Manejo de mesas                                             |\n");
    printf("                          |                                                               |\n");
    printf("                          '---------------------------------------------------------------'\n");
}

void inicioGerente()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |  Inicio de sesion exitoso                     Gulyx           |\n");
    printf("                          |                                                               |\n");
    printf("                          |  Seleccione una opcion:                                       |\n");
    printf("                          |                                                               |\n");
    printf("                          | 1-Ingresar o eliminar empleado                                |\n");
    //  printf("                          | 2-Ingresar productos al menu                                  |\n");
    printf("                          | 2-Manejo de mesas                                             |\n");
    printf("                          |                                                               |\n");
    printf("                          '---------------------------------------------------------------'\n");
}

/*void inicioCajero()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          ----------------------------------------------------------------\n");
    printf("                          |  Inicio de sesion exitoso                     Gulyx           |\n");
    printf("                          |                                                               |\n");
    printf("                          |  Seleccione una opcion:                                       |\n");
    printf("                          |                                                               |\n");
    // printf("                          | 2-Ingresar productos al menu                                  |\n");
    printf("                          | 1-Manejo de mesas                                             |\n");
    printf("                          |                                                               |\n");
    printf("                          ----------------------------------------------------------------\n");
}*/

/*void selecIngresoOwner()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |  Seleccione una opcion:                       Gulyx           |\n");
    printf("                          |                                                               |\n");
    printf("                          | 1-Empleado                                                    |\n");
    printf("                          | 2-Gerente                                                     |\n");
    printf("                          | 3-Volver al menu de opciones                                  |\n");
    printf("                          |                                                               |\n");
    printf("                          '---------------------------------------------------------------'\n");
}*/
void ingEliEmpleado()
{

    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |  Seleccione una opcion:                       Gulyx           |\n");
    printf("                          |                                                               |\n");
    printf("                          |  1-Ver todos los empleados                                    |\n");
    printf("                          |  2-Ingresar nuevo empleado                                    |\n");
    printf("                          |  3-Eliminar empleado                                          |\n");
    printf("                          |  4-Volver al menu de opciones                                 |\n");
    printf("                          |                                                               |\n");
    printf("                          '---------------------------------------------------------------'\n");
}

/*void ingEliGerente()
{

    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |  Seleccione una opcion:                       Gulyx           |\n");
    printf("                          |                                                               |\n");
    printf("                          |  1-Ingresar nuevo gerente                                     |\n");
    //   printf("                          |  2-Editar gerente                                             |\n");
    printf("                          |  2-Eliminar gerente                                           |\n");
    printf("                          |  3-Volver al menu de opciones                                 |\n");
    printf("                          |                                                               |\n");
    printf("                          '---------------------------------------------------------------'\n");
}*/

/*void ingStock()
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
}*/

/*void ventasDiaras()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          ----------------------------------------------------------------\n");
    printf("                          |  Seleccione una opcion:                       Gulyx           |\n");
    printf("                          |                                                               |\n");
    printf("                          |  1-Venta diaria total                                         |\n");
    printf("                          |  2-Venta diaria por empleado                                  |\n");
    printf("                          |  2-Volver al menu de opciones                                 |\n");
    printf("                          |                                                               |\n");
    printf("                          ----------------------------------------------------------------\n");
}*/

void manejoMesas()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |  Seleccione una Mesa:                       Gulyx             |\n");
    printf("                          |                                                               |\n");
    printf("                          |                                                               |\n");
    printf("                          |    Mesas:        | 1 |   | 2 |   | 3 |  | 4 |                 |\n");
    printf("                          |                                                               |\n");
    printf("                          |                  | 5 |   | 6 |   | 7 |  | 8 |                 |\n");
    printf("                          |                                                               |\n");
    printf("                          |  - O = Mesa ocupada                                           |\n");
    printf("                          |  0-Cerrar caja del dia                                        |\n");
    printf("                          |                                                               |\n");
    printf("                          |                                                               |\n");
    printf("                          '---------------------------------------------------------------'\n");
}

void menuMesa()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |  Seleccione una opcion:                       Gulyx           |\n");
    printf("                          |                                                               |\n");
    printf("                          |  1-Ingresar productos                                         |\n");
    printf("                          |  2-Editar productos                                           |\n");
    printf("                          |  3-Cobrar Mesa                                                |\n");
    printf("                          |  4-Cancelar Mesa                                              |\n");
    printf("                          |  5-Volver al menu de Mesas                                    |\n");
    printf("                          '---------------------------------------------------------------'\n");
}

void ingProductosMesa()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |  Seleccione una categoria:                       Gulyx        |\n");
    printf("                          |                                                               |\n");
    printf("                          | 1-Comidas                                                     |\n");
    printf("                          | 2-Bebidas                                                     |\n");
    printf("                          | 3-Postres                                                     |\n");
    printf("                          | 4-Volver al menu de Mesas                                     |\n");
    printf("                          |                                                               |\n");
    printf("                          '---------------------------------------------------------------'\n");
}

void ingComidas()
{
    system("cls");
    printf("\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |  Comidas:                                        Gulyx        |\n");
    printf("                          |                                                               |\n");
    printf("                          |  PASTAS--------------------------                PRECIO       |\n");
    printf("                          |                                                               |\n");
    printf("                          | 1-SORRENTINOS CON BOLOGNESA                       $260        |\n");
    printf("                          |                                                               |\n");
    printf("                          | 2-CANELONES CON FILETO                            $230        |\n");
    printf("                          |                                                               |\n");
    printf("                          | 3-FIDEOS CON BLANCA                               $200        |\n");
    printf("                          |                                                               |\n");
    printf("                          | MINUTAS--------------------------                             |\n");
    printf("                          |                                                               |\n");
    printf("                          | 4-MILANESA CON FRITAS Y 2 HUEVOS                  $250        |\n");
    printf("                          |                                                               |\n");
    printf("                          | 5-HAMBURGUESA COMPLETA                            $280        |\n");
    printf("                          |                                                               |\n");
    printf("                          | 6-PRECHUGA GRILLE CON ENSALADA                    $300        |\n");
    printf("                          |                                                               |\n");
    printf("                          | PIZZAS---------------------------                             |\n");
    printf("                          |                                                               |\n");
    printf("                          | 7-NAPOLITANA/ESPECIAL/EXTRAGULYX                  $500        |\n");
    printf("                          |                                                               |\n");
    printf("                          | EMPANADAS------------------------                             |\n");
    printf("                          |                                                               |\n");
    printf("                          | 8-CARNE/POLLO/JYQ/CAPRESSE/HUMITA                 $70         |\n");
    printf("                          |                                                               |\n");
    printf("                          '---------------------------------------------------------------'\n");
}

void ingBebidas()
{
    system("cls");
    printf("\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |                                                               |\n");
    printf("                          |  Bebidas:                                        Gulyx        |\n");
    printf("                          |                                                               |\n");
    printf("                          |  GASEOSAS------------------------                PRECIO       |\n");
    printf("                          |                                                               |\n");
    printf("                          |  1-COCA/SPRITE/MIRINDA                            $120        |\n");
    printf("                          |                                                               |\n");
    printf("                          |  2-AGUA SABORIZADA                                $140        |\n");
    printf("                          |                                                               |\n");
    printf("                          |  3-AGUA CON O SIN GAS                             $100        |\n");
    printf("                          |                                                               |\n");
    printf("                          |  4-GATORADE                                       $180        |\n");
    printf("                          |                                                               |\n");
    printf("                          |  VINOS---------------------------                             |\n");
    printf("                          |                                                               |\n");
    printf("                          |  5-VASCO VIEJO 3/4 TINTO O BLANCO                 $260        |\n");
    printf("                          |                                                               |\n");
    printf("                          |  6-SANTA JULIA BLANCO 3/4                         $350        |\n");
    printf("                          |                                                               |\n");
    printf("                          |                                                               |\n");
    printf("                          |  TRAGOS--------------------------                             |\n");
    printf("                          |                                                               |\n");
    printf("                          |  7-FERNET CON COCA/GIN TONIC                      $300        |\n");
    printf("                          |                                                               |\n");
    printf("                          |  8-CAIPIRINHA/CAIPIROSKA                          $340        |\n");
    printf("                          |                                                               |\n");
    printf("                          '---------------------------------------------------------------'\n");
}

void ingPostres()
{
    system("cls");
    printf("\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |                                                               |\n");
    printf("                          |  Postres:                                        Gulyx        |\n");
    printf("                          |                                                               |\n");
    printf("                          |  HELADOS-------------------------                PRECIO       |\n");
    printf("                          |                                                               |\n");
    printf("                          |  1-ALMENDRADO/3 GUSTOS                            $160        |\n");
    printf("                          |                                                               |\n");
    printf("                          |  2-BOMBON SUIZO/ESCOCES                           $180        |\n");
    printf("                          |                                                               |\n");
    printf("                          |  3-BOCHA HELADO CHOCOLATE/VAINILLA                $100        |\n");
    printf("                          |                                                               |\n");
    printf("                          |  FLAN O BUDIN--------------------                             |\n");
    printf("                          |                                                               |\n");
    printf("                          |  4-SOLO                                           $140        |\n");
    printf("                          |                                                               |\n");
    printf("                          |  5-DULCE DE LECHE O CREMA                         $170        |\n");
    printf("                          |                                                               |\n");
    printf("                          |  6-MIXTO                                          $190        |\n");
    printf("                          |                                                               |\n");
    printf("                          |  CUPCAKES------------------------                             |\n");
    printf("                          |                                                               |\n");
    printf("                          |  7-CHOCOTORTA                                     $300        |\n");
    printf("                          |                                                               |\n");
    printf("                          |  8-LEMONPIE                                       $280        |\n");
    printf("                          |                                                               |\n");
    printf("                          '---------------------------------------------------------------'\n");
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
