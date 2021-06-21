#include "Headers\\ventas.h"

int ventaidRandom()
{
    int numrand = 0;
    int comprobation = 0;
    do
    {

        numrand = 1 + rand() % 1000;

        comprobation = comprobarIdventa(numrand);

    } while (comprobation == 1);

    return numrand;
}
int comprobarIdventa(int idrand)
{
    FILE *archi = fopen(ventasTotales, "rb");
    Venta aux;
    int flag = 0;

    if (archi != NULL)
    {
        while (fread(&aux, sizeof(Venta), 1, archi) > 0 && flag == 0)
        {
            if (aux.id == idrand)
            {
                flag = 1;
            }
        }
        fclose(archi);
    }

    return flag;
}

//Struct que recibe el cobro
Venta cargaVenta(int cobroTotal)
{

    int metPago = 0;
    Venta aux;

    printf("\n\n\n\n\n\n\n\n");
    printf("                          .----------------------------------------------------.\n");
    printf("                          |                                         Gulyx      |\n");
    printf("                          |  Monto:   %d                                        \n", cobroTotal);
    printf("                          |                                                    |\n");
    printf("                          |  Seleccione el metodo de pago:                     |\n");
    printf("                          |                                                    |\n");
    printf("                          |      1-Efectivo                   2-Tarjeta        |\n");
    printf("                          |                                                    |\n");
    printf("                          '----------------------------------------------------'\n");
    do
    {
        scanf("%d", &metPago);
    } while (metPago < 1 && metPago > 2);
    aux.activo = 1;
    aux.monto = cobroTotal;
    if (metPago == 1)
    {
        aux.medio_pago = 0;
    }
    else
    {
        aux.medio_pago = 1;
    }
    aux.id = ventaidRandom();
}
//funcion cargar archivo con los cobrarmesa
void cargarVentaArchivo(Venta cobro)
{
    FILE *archi;
    archi = fopen(ventasTotales, "ab");
    Venta aux;

    if (archi != NULL)
    {
        fwrite(&aux, sizeof(Venta), 1, archi);
        fclose(archi);
    }
    else
    {
        printf("No se pudo abrir el archivo:\n");
    }
}
void mostrarArchVenta(Venta unaVenta)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                          .-----------------------------------.\n");
    printf("                          |                        Gulyx      |\n");
    printf("                          |       %d-%02d-%02d %02d:%02d:%02d |\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("                          |                                   |\n");
    printf("                          | ID DE LA VENTA: %d                 \n");
    printf("                          |                                   |\n");
    printf("                          | MONTO: %d                          \n", unaVenta.monto);
    printf("                          |                                   |\n");
    if (unaVenta.medio_pago == 0)
    {
        printf("                          | MEDIO DE PAGO:   EFECTIVO         |\n");
    }
    else
    {
        printf("                          | MEDIO DE PAGO:   TARJETA          |\n");
    }
    printf("                          |                                   |\n");
    printf("                          '-----------------------------------'\n");
}

//funcion leer archivo total de ventas
void totalVentas()
{
    system("cls");
    int acumuladorVentas = 0;
    Venta aux;
    FILE *archi;
    archi = fopen(ventasTotales, "rb");
    if (archi != NULL)
    {
        while (fread(&aux, sizeof(Venta), 1, archi) > 0)
        {
            if (aux.activo != 0)
            {
                mostrarArchVenta(aux);
                acumuladorVentas += aux.monto;
            }
        }
        fclose(archi);
    }
    printf("El total de las ventas es: %d", acumuladorVentas);
    system("pause");
}

//funcion eliminar venta ya hecha
int buscarIDVenta(int idRecibido)
{
    int idbuscado = 0;
    int flag = 0;
    idbuscado = comprobarIdventa(idRecibido);
    if (idbuscado == 1)
    {
        elimiVentArchi(idRecibido);
        system("cls)");
        printf("La venta a sido eliminada\n");
        system("pause");
    }
    else
    {
        printf("El ID ingresado no pertenece a una venta existente o presione 0 para volver:");
        system("pause");
        flag = 1;
    }
    return flag;
}

void elimiVentArchi(int idRecibido)
{
    int flag = 0;
    FILE *archi;
    archi = fopen(ventasTotales, "r+b");
    Venta aux;

    while (flag == 0 && fread(&aux, sizeof(Venta), 1, archi) > 0)
    {
        if (aux.id == idRecibido)
        {
            flag = 1;
        }
    }
    fseek(archi, (-1) * sizeof(Venta), SEEK_CUR);
    aux.activo = 0;
    fwrite(&aux, sizeof(Venta), 1, archi);
    fclose(archi);
}
void elimiYmostrarVenta()
{
    int idrecibido = 0;

    int flag = 0;
    totalVentas();
    printf("Ingrese el ID de la venta que desea eliminar: ");
    do
    {
        scanf("%d", &idrecibido);
        flag = buscarIDVenta(idrecibido);
    } while (flag == 1);
}