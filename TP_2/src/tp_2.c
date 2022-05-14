/*
 ============================================================================
 Name        : tp_2.c
 Author      : Barrio Cristian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayPassenger.h"
#include "cargaForzada.h"

int main(void)
{
	setbuf(stdout, NULL);

	ePassenger pasajeros[LEN];
	int auxId = 1000;
	char auxName[51];
	char auxLastName[51];
	float auxPrice;
	char auxFlyCode[10];
	int auxTypePassenger;
	int auxStatusFlight;
	int flagIngreso = 0;

	int continuar = 0;
	int continuarInformes = 0;

	/*ePassenger pasajerosEntradaForzada[LEN] = {
			{idIngresoForzado, "Jorge", "Gomez", 165000.5, "asdjkh", 1, 0},
			{idIngresoForzado++, "Julio", "Rolandi", 267000, "jkhhm", 2, 1},
			{idIngresoForzado++, "Rosana", "Garcia", 151628.32, "vbncv", 1, 0},
			{idIngresoForzado++, "Benjamin", "Mara", 7800, "lkmnj", 0, 1},
			{idIngresoForzado++, "Claudia", "Torres", 124027.6, "asdfv", 1, 2},
			{idIngresoForzado++, "Agustin", "Gonzalez", 96000, "jnfgg", 1, 0},
			{idIngresoForzado++, "Camila", "Benitez", 104210, "gjnfg", 0, 2},
			{idIngresoForzado++, "Julieta", "Magnetto", 87000, "ertyi", 2, 1},
			{idIngresoForzado++, "Martin", "Carrera", 99800, "uioyp", 1, 0},
			{idIngresoForzado++, "Cristina", "Linares", 185600, "zxcvb", 1, 0}
	};*/


	initPassengers(pasajeros, LEN);

	do{
		system("cls");

		switch(menu())
		{
			case 1:
				if(addPassenger(pasajeros, LEN, auxId, auxName, auxLastName, auxPrice, auxTypePassenger, auxFlyCode, auxStatusFlight) == 0)
				{
					printf("Alta realizada con exito.\n");
					auxId++;
					flagIngreso = 1;
				}
				break;
			case 2:
				if (flagIngreso)
				{
					modifyPassenger(pasajeros, LEN, auxId, auxName, auxLastName, auxPrice, auxTypePassenger, auxFlyCode, auxStatusFlight);
					printf("Modificacion realizada con exito.\n");
				} else
				{
					printf("No se pueden realizar modificaciones sin antes ingresar pasajeros.\n");
				}
				break;
			case 3:
				if (flagIngreso)
				{
					removePassenger(pasajeros, LEN, auxId);
					printf("Baja realizada con exito\n");
				} else
				{
					printf("No se puede realizar la baja sin antes ingresar pasajeros.\n");
				}
				break;
			case 4:
				if(flagIngreso)
				{
					do{
						switch(menuInformes())
						{
							case 1:
								sortPassengers(pasajeros, LEN, 1);
								printPassengers(pasajeros, LEN);
								sortPassengersByCode(pasajeros, LEN, 1);
								printPassengers(pasajeros, LEN);
								averagePrice(pasajeros, LEN);
								continuarInformes = 1;
								break;
							case 2:
								sortPassengers(pasajeros, LEN, 0);
								printPassengers(pasajeros, LEN);
								sortPassengersByCode(pasajeros, LEN, 0);
								printPassengers(pasajeros, LEN);
								averagePrice(pasajeros, LEN);
								continuarInformes = 1;
								break;
							case 3:
								continuarInformes = 1;
								break;
							default:
								printf("Ingrese una opcion valida.\n");
								break;
						}
					}while(continuarInformes == 0);

				} else
				{
					printf("No se pueden realizar los informes sin antes ingresar pasajeros.\n");
				}
				break;
			case 5:
				do{
					switch(menuInformes())
					{
						case 1:
							/*system("cls");
							sortPassengers(pasajerosEntradaForzada, LEN, 1);
							printPassengers(pasajerosEntradaForzada, LEN);
							sortPassengersByCode(pasajerosEntradaForzada, LEN, 1);
							printPassengers(pasajerosEntradaForzada, LEN);
							averagePrice(pasajerosEntradaForzada, LEN);
							continuarInformes = 1;
							break;
						case 2:
							system("cls");
							sortPassengers(pasajerosEntradaForzada, LEN, 0);
							printPassengers(pasajerosEntradaForzada, LEN);
							sortPassengersByCode(pasajerosEntradaForzada, LEN, 0);
							printPassengers(pasajerosEntradaForzada, LEN);
							averagePrice(pasajerosEntradaForzada, LEN);
							continuarInformes = 1;
							break;
						case 3:
							continuarInformes = 1;
							break;*/
						default:
							printf("Ingrese una opcion valida.\n");
							break;
					}
				}while(continuarInformes == 0);
				break;
			case 6:
				continuar = 1;
				break;
			default:
				printf("Ingrese una opcion valida.\n");
				break;
		}
		system("pause");
	} while(continuar == 0);

	return EXIT_SUCCESS;
}
