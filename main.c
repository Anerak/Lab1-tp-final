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
