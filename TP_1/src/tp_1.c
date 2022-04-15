/*
 ============================================================================
 Name        : tp_1.c
 Author      : Barrio, Cristian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "calcular.h"

int main()
{
	setbuf(stdout,NULL);

    int km = 0;
    int precioAerolineas = 0;
    int precioLatam = 0;

    float precioDebitoAerolineas = 0;
    float precioCreditoAerolineas = 0;
    float precioBtcAerolineas = 0;
    float precioUnitarioAerolineas = 0;

    float precioDebitoLatam = 0;
    float precioCreditoLatam = 0;
    float precioBtcLatam = 0;
    float precioUnitarioLatam = 0;

    int difPrecio = 0;

    int flagKm = 0;
    int flagAerolineas = 0;
    int flagLatam = 0;
    int flagResultados = 0;

    char continuar = 's';

    do
    {
        system("cls");
        printf("    AGENCIA DE VIAJES\n"
               "----------------------------\n\n");

        switch(menu(km, precioAerolineas, precioLatam))
        {
            case 1:
                if(ingresarKm(&km))
                {
                    printf("Valor ingresado correctamente.\n");
                    flagKm = 1;
                }else
                {
                    printf("Hubo un error al ingresar los datos.\n");
                }
                break;
            case 2:
                menuPrecios(&precioAerolineas, &precioLatam, &flagAerolineas, &flagLatam);
                break;
            case 3:
                if(flagKm && flagAerolineas && flagLatam)
                {
                    calcularCostoDebito(precioAerolineas, &precioDebitoAerolineas);
                    calcularCostoCredito(precioAerolineas, &precioCreditoAerolineas);
                    calcularCostoBtc(precioAerolineas, &precioBtcAerolineas);
                    calcularCostoUnitario(precioAerolineas, km, &precioUnitarioAerolineas);

                    calcularCostoDebito(precioLatam, &precioDebitoLatam);
                    calcularCostoCredito(precioLatam, &precioCreditoLatam);
                    calcularCostoBtc(precioLatam, &precioBtcLatam);
                    calcularCostoUnitario(precioLatam, km, &precioUnitarioLatam);

                    calcularDiferencia(precioAerolineas, precioLatam, &difPrecio);

                    flagResultados = 1;
                    printf("Calculos realizados con exito.\n");
                }else
                {
                    printf("No se pueden realizar los calculos sin haber ingresado los valores.\n");
                }
                break;
            case 4:
                if(flagResultados)
                {
                    system("cls");

                    mostrarResultadosAerolineas(km, precioAerolineas, precioDebitoAerolineas, precioCreditoAerolineas, precioBtcAerolineas, precioUnitarioAerolineas);
                    mostrarResultadosLatam(precioLatam, precioDebitoLatam, precioCreditoLatam, precioBtcLatam, precioUnitarioLatam, difPrecio);

                }else
                {
                    printf("Hubo un error al mostrar los resultados. Primero se deben realizar los calculos.\n");
                }
                break;
            case 5:
                system("cls");
                calcularCostoDebito(162965, &precioDebitoAerolineas);
                calcularCostoCredito(162965, &precioCreditoAerolineas);
                calcularCostoBtc(162965, &precioBtcAerolineas);
                calcularCostoUnitario(162965, 7090, &precioUnitarioAerolineas);

                calcularCostoDebito(159339, &precioDebitoLatam);
                calcularCostoCredito(159339, &precioCreditoLatam);
                calcularCostoBtc(159339, &precioBtcLatam);
                calcularCostoUnitario(159339, 7090, &precioUnitarioLatam);
                calcularDiferencia(162965, 159339, &difPrecio);

                mostrarResultadosAerolineas(7090, 162965, precioDebitoAerolineas, precioCreditoAerolineas, precioBtcAerolineas, precioUnitarioAerolineas);
                mostrarResultadosLatam(159339, precioDebitoLatam, precioCreditoLatam, precioBtcLatam, precioUnitarioLatam, difPrecio);
                break;
            case 6:
                continuar = 'n';
                break;
            default:
                printf("Ingrese una opcion valida.\n");
                break;
        }
        system("pause");

    }while(continuar == 's');

    return EXIT_SUCCESS;
}
