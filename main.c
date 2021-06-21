#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "Headers\\menu.h"

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
int comprobarPass(int tipoUsuario);
void cargEstrucYarchi(int rolValido);
void mostrarEmpleado(Empleado empleados);
int idRandom();
void comprobarId(int idrand);
void mostrarArchEmpl();
void menu2duenio(int op);
void ingelempSwitch(int op);

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
