#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "Headers\\menu.h"
#include "Headers\\empleados.h"

//contraseña duenñon
#define passOwner "admin1234"
//contraseña gerente
#define passManager "manag123"
//contraseña cajero
#define passEmploy "gul123"

#define datosempleados "empleado.dat"

int main()
{
    Empleado empleados[50];
    system("COLOR B0");
    srand(time(NULL));

    int tipoUsuario = 0;

    mostrarLogo();
    do
    {
        tipoUsuario = SeleccionUsuario();
    } while (tipoUsuario == 0);

    switch (tipoUsuario)
    {
    case 1:
        mostrarDuenio();
        break;
    case 2:
        mostrarGerente();
        break;
    case 3:
        mostrarCajero();
        break;
    default:
        break;
    }

    return 0;
}
