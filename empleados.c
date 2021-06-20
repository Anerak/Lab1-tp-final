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