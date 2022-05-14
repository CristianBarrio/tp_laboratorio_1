/*
 * utn.c
 *
 *  Created on: May 9, 2022
 *      Author: Cristian
 */
#include "utn.h"


int obtenerIntPositivo(char mensaje[], int* numero)
{
	int retorno = -1;
	printf(mensaje);
	scanf("%d", numero);

	/*while(*numero < 0 || isdigit(*numero) == 0)
	{
		printf("Hubo un problema al ingresar el numero.\n");
		printf(mensaje);
		scanf("%d", numero);
	}*/

	retorno = 0;

	return retorno;
}

int obtenerFloatPositivo(char mensaje[], float* numero)
{
	int retorno = -1;
	printf(mensaje);
	scanf("%f", numero);

	/*if(*numero < 0 || isdigit(*numero) == 0)
	{
		printf("Hubo un problema al ingresar el numero.\n");
		printf(mensaje);
		scanf("%f", numero);
	}*/

	retorno = 0;

	return retorno;
}

int obtenerCadena(char mensaje[], char cadena[])
{
	int retorno = -1;

	printf(mensaje);
	fflush(stdin);
	gets(cadena);

	if(cadena != NULL)
	{
		for(int i = 0; cadena[i] != '\0'; i++)
		{
			if(isalpha(cadena[i]) == 0)
			{
				printf("Hubo un problema al ingresar la cadena.\n");
				printf(mensaje);
				fflush(stdin);
				gets(cadena);
			}
		}
		retorno = 0;
	}

	return retorno;
}

int menu()
{
	int opcion;

	printf("  AEROLINEA\n"
		  "-----------------\n"
		  "1. INGRESAR PASAJERO\n"
		  "2. MODIFICAR PASAJERO\n"
		  "3. DAR DE BAJA\n"
		  "4. INFORMES\n"
		  "5. CARGA FORZADA DE PASAJEROS\n"
		  "6. SALIR\n");

	obtenerIntPositivo("Ingrese una opcion: ", &opcion);

	return opcion;
}

int menuModificacion()
{
	int opcion;

	printf("1. Nombre\n"
		   "2. Apellido\n"
		   "3. Precio\n"
		   "4. Tipo de pasajero\n"
		   "5. Codigo de vuelo\n"
		   "6. Estado del vuelo\n"
		   "7. Cancelar modificacion\n");

	obtenerIntPositivo("Ingrese una opcion: ", &opcion);

	return opcion;
}

int menuInformes()
{
	int opcion;

	printf("1. Ordenamiento ascendente\n"
			"2. Ordenamiento descendente\n"
			"3. Salir\n");
	obtenerIntPositivo("Ingrese una opcion: ", &opcion);

	return opcion;
}

