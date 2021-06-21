#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "menu.h"

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

Empleado agregarEmpl(int rolValido);
void mostrarArchEmpl();
void comprobarId(int idrand);
int idRandom();
void mostrarEmpleado(Empleado empleados);
void cargEstrucYarchi(int rolValido);
void addEmpFile(Empleado empleados);
void ingelempSwitch(int op);
void menu2duenio(int op);
void SeleccionUsuario(int tipoUsuario);
int comprobarPass(int tipoUsuario);
