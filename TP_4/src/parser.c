/*
 * parser.c
 *
 *  Created on: 16 jun. 2022
 *      Author: Cristian
 */


#include "parser.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	char id[TAM];
	char nombre[TAM_NOMBRE];
	char apellido[TAM_NOMBRE];
	char precio[TAM];
	char codigo[TAM];
	char estado[TAM_TIPO];
	char tipo[TAM_TIPO];
	Passenger* pasajero;


	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigo,estado,tipo);

		while(!feof(pFile))
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigo,estado,tipo) == 7)
			{

				pasajero = Passenger_newParametros(id,nombre,tipo,apellido,codigo,precio,estado);

				if(pasajero != NULL)
				{
					ll_add(pArrayListPassenger,pasajero);
					retorno = 1;
				}
			}

		}
	}else
	{
		printf("Error al leer el archivo.\n");
	}

    return retorno;
}
