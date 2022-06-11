/*
 * utn.c
 *
 *  Created on: 2 jun. 2022
 *      Author: Barrio Cristian
 */


#include "utn.h"

int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	if (cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)
	{
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n')
		{
			cadena[strlen(cadena) - 1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int esNumerica(char* cadena)
{
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0)
	{
		while (cadena[i] != '\0')
		{
			if (isalpha(cadena[i]) != 0)
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int bufferInt;
	int retorno = -1;

	while (retorno != 0)
	{
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0)
		{
			if (bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
		{
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo)
{
	float bufferFloat;
	int retorno = -1;

	while (retorno != 0)
	{
		printf("%s", mensaje);
		if (getFloat(&bufferFloat) == 0)
		{
			if (bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int utn_getString(char* cadena, char* mensaje, char* mensajeError)
{
	int retorno = 1;

	while(retorno != 0)
	{
		printf(mensaje);
		fflush(stdin);
		gets(cadena);
		for (int i = 0; i < strlen(cadena); i++)
		{
			if(isalpha(cadena[i]) == 0 && isspace(cadena[i]) == 0 && cadena[i] != 'ñ')
			{
				retorno = 1;
				printf(mensajeError);
				break;
			}
			retorno = 0;
		}
	}

	return retorno;
}

int menu()
{
	int opcion;

	printf("1. CARGAR LOS DATOS DE LOS PASAJEROS DESDE data.csv (texto)\n"
		  "2. CARGAR LOS DATOS DE LOS PASAJEROS DESDE data.csv (binario)\n"
		  "3. INGRESAR PASAJERO\n"
		  "4. MODIFICAR PASAJERO\n"
		  "5. DAR DE BAJA\n"
		  "6. LISTAR PASAJEROS\n"
		  "7. ORDENAR PASAJEROS\n"
		  "8. GUARDAR LOS DATOS DE LOS PASAJEROS EN data.csv (texto)\n"
		  "9. GUARDAR LOS DATOS DE LOS PASAJEROS EN data.csv (binario)\n"
		  "10. SALIR\n");

	utn_getInt(&opcion, "Ingrese una opcion: ", "Opcion invalida.\n", 1, 10);

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
		  "7. Cancelar\n");

	utn_getInt(&opcion, "Ingrese una opcion para modificar: ", "Opcion invalida.\n", 1, 7);

	return opcion;
}
