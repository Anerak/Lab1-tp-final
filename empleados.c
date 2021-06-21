#include "Headers\\empleados.h"

Empleado agregarEmpl(int rolValido)
{
    system("cls");
    Empleado aux;
    int opEmp = 0;
    aux.id = idRandom();
    printf("\n\n\n\n\n\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |                                                    Gulyx      |\n");
    printf("                          | ID del empleado:  %d                                           \n", aux.id);
    printf("                          |                                                               |\n");
    printf("                          |                                                               |\n");
    printf("                          |Ingrese SOLO el nombre:                                        |\n");
    printf("                          |                                                               |\n");
    printf("                          |Ingrese el apellido:                                           |\n");
    printf("                          |                                                               |\n");
    if (rolValido == 1)
    {
        printf("                          |Seleccione un Rol:    1-Gerente  2-Cajero  3-Camarero          |\n");
        printf("                          |                                                               |\n");
    }
    else
    {
        printf("                          |Seleccione un Rol:      1-Cajero  2-Camarero                   |\n");
        printf("                          |                                                               |\n");
    }
    printf("                          |        Opcion:                                                |\n");
    printf("                          '---------------------------------------------------------------'\n");
    fflush(stdin);
    gotoxy(52, 13);
    gets(aux.nombre);
    fflush(stdin);
    gotoxy(49, 15);
    gets(aux.apellido);
    if (rolValido == 1)
    {
        do
        {
            gotoxy(44, 19);
            scanf("%d", &opEmp);
        } while (opEmp < 0 || opEmp > 3);
    }
    else
    {
        do
        {
            gotoxy(44, 19);
            scanf("%d", &opEmp);
        } while (opEmp < 0 || opEmp > 2);
    }
    aux.rol = opEmp;

    aux.activo = 1;

    return aux;
}

void mostrarArchEmpl()
{
    system("cls");
    Empleado aux;
    FILE *archi;
    archi = fopen(datosempleados, "rb");
    if (archi != NULL)
    {
        while (fread(&aux, sizeof(Empleado), 1, archi) > 0)
        {
            if (aux.activo == 1)
                ;
            mostrarEmpleado(aux);
        }
        fclose(archi);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
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
int idRandom()
{

    srand(time(NULL));
    int numrand = 1 + rand() % 1000;
    comprobarId(numrand);

    return numrand;
}
void mostrarEmpleado(Empleado empleados)
{
    int roles = 0;

    printf("\n\n\n");
    printf("                          .---------------------------------------------------------------.\n");
    printf("                          |                                                    Gulyx      |\n");
    printf("                          | ID del empleado: %i                                            \n", empleados.id);
    printf("                          |                                                               |\n");
    printf("                          |Ingrese SOLO el nombre: %s                                     \n", empleados.nombre);
    printf("                          |                                                               |\n");
    printf("                          |Ingrese el apellido: %s                                        \n", empleados.apellido);
    printf("                          |                                                               |\n");
    if (empleados.rol == 1)
    {
        printf("                          |Rol: Gerente                                                   |\n");
    }
    else if (empleados.rol == 2)
    {
        printf("                          |Rol: Cajero                                                    |\n");
    }
    else
    {
        printf("                          |Rol: Camarero                                                  |\n");
    }
    printf("                          |                                                               |\n");
    printf("                          '---------------------------------------------------------------'\n");
}
void cargEstrucYarchi(int rolValido)
{
    char seguir = 's';
    Empleado aux;
    while (seguir == 's')
    {
        aux = agregarEmpl(rolValido);
        addEmpFile(aux);
        printf("Desea cargar otro empleado? s/n\n");
        fflush(stdin);
        scanf("%c", &seguir);
    }
}
void addEmpFile(Empleado empleados)
{
    FILE *archi;
    archi = fopen(datosempleados, "ab");

    if (archi == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {

        fwrite(&empleados, sizeof(Empleado), 1, archi);
        fclose(archi);
    }
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
            do
            {
                gotoxy(52, 11);
                scanf("%d", &opmenu2);
                menu2duenio(opmenu2);
            } while (opmenu2 != 0);

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
            manejoMesas();

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
        system("pause");
        break;

    case 2:
        cargEstrucYarchi(1);

        break;
    }
}