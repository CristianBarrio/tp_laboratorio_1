/*
 * ArrayPassenger.c
 *
 *  Created on: May 9, 2022
 *      Author: Cristian
 */

#include "ArrayPassenger.h"

int initPassengers(ePassenger* list, int len)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[], int statusFlight)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		system("cls");
		printf("        ALTA PASAJERO \n");
		printf("----------------------------------\n");

		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty)
			{
				obtenerCadena("Ingrese el nombre: ", name);
				obtenerCadena("Ingrese el apellido: ", lastName);
				obtenerFloatPositivo("Ingrese el precio del vuelo: ", &price);
				obtenerIntPositivo("Ingrese el tipo de pasajero: \n"
									"Menor (0), Adulto (1), Jubilado (2)", &typePassenger);

				if(typePassenger != 0 && typePassenger != 1 && typePassenger != 2)
				{
					printf("Tipo de pasajero invalido.\n");
					obtenerIntPositivo("Ingrese el tipo de pasajero: \n"
										"Menor (0), Adulto (1), Jubilado (2)", &typePassenger);
				}

				obtenerCadena("Ingrese el codigo del vuelo: ", flyCode);

				obtenerIntPositivo("Ingrese el estado del vuelo: \n"
									"Activo (0), Inactivo (1), Demorado (2)", &statusFlight);

				if(statusFlight != 0 && statusFlight != 1 && statusFlight != 2)
				{
					printf("Estado de vuelo invalido.\n");
					obtenerIntPositivo("Ingrese el estado del vuelo: \n"
										"Activo (0), Inactivo (1), Demorado (2)", &statusFlight);
				}

				list[i].isEmpty = 0;
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].price = price;
				list[i].typePassenger = typePassenger;
				strcpy(list[i].flyCode, flyCode);
				list[i].statusFlight = statusFlight;
				i = len + 1;

			}
		}

		retorno = 0;

	}

	return retorno;
}

int modifyPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[], int statusFlight)
{
	int retorno = -1;
	int indice;
	int continuar = 0;

	if(list != NULL && len > 0)
	{
		system("cls");
		printf("      MODIFICACION DE PASAJEROS \n");
		printf("-------------------------------------------\n");

		obtenerIntPositivo("Ingrese ID del pasajero: ", &id);
		indice = findPassengerById(list, len, id);

		if(indice == -1)
		{
			printf("No existe un pasajero con ID %d.\n", id);
		}else
		{
			printPassenger(list[indice]);

			while(continuar == 0)
			{
				switch(menuModificacion())
				{
					case 1:
						obtenerCadena("Ingrese nuevo nombre: ", name);
						strcpy(list[indice].name, name);
						break;
					case 2:
						obtenerCadena("Ingrese un nuevo apellido: ", lastName);
						strcpy(list[indice].lastName, lastName);
						break;
					case 3:
						obtenerFloatPositivo("Ingrese nuevo precio del vuelo: ", &price);
						list[indice].price = price;
						break;
					case 4:
						obtenerIntPositivo("Ingrese nuevo tipo de pasajero: \n"
													"Menor (0), Adulto (1), Jubilado (2)", &typePassenger);
						if(typePassenger != 0 && typePassenger != 1 && typePassenger != 2)
						{
							printf("Tipo de pasajero invalido.\n");
							obtenerIntPositivo("Ingrese el tipo de pasajero: \n"
													"Menor (0), Adulto (1), Jubilado (2)", &typePassenger);
						}
						list[indice].typePassenger = typePassenger;
						break;
					case 5:
						obtenerCadena("Ingrese nuevo codigo del vuelo: ", flyCode);
						strcpy(list[indice].flyCode, flyCode);
						break;
					case 6:
						obtenerIntPositivo("Ingrese el estado del vuelo: \n"
											"Activo (0), Inactivo (1), Demorado (2)", &statusFlight);

						if(statusFlight != 0 && statusFlight != 1 && statusFlight != 2)
						{
							printf("Estado de vuelo invalido.\n");
							obtenerIntPositivo("Ingrese el estado del vuelo: \n"
												"Activo (0), Inactivo (1), Demorado (2)", &statusFlight);
						}
						list[indice].statusFlight = statusFlight;
						break;
					case 7:
						continuar = 1;
						break;
					default:
						printf("\nIngrese una opcion valida.\n");
						break;
				}

			}

			retorno = 0;
		}
	}

	return retorno;
}

int findPassengerById(ePassenger* list, int len,int id)
{
	int indice = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(!list[i].isEmpty && list[i].id == id)
			{
				indice = i;
				break;
			}
		}
	}

	return indice;
}

int removePassenger(ePassenger* list, int len, int id)
{
	int retorno = -1;
	int indice;
	int confirmacion;

	if(list != NULL && len > 0)
	{
		system("cls");
		printf("       BAJA PASAJERO\n");
		printf("----------------------------------\n");

		printf("Ingrese ID del pasajero: ");
		scanf("%d", &id);

		indice = findPassengerById(list,len,id);

		if(indice == -1)
		{
			printf("No existe un pasajero con ID %d.\n", id);
			confirmacion = 0;
		}else
		{
			printf("Confirmar baja? Si (1) No (0): ");
			scanf("%d", &confirmacion);

			if(confirmacion == 1)
			{
				list[indice].isEmpty = 1;
				retorno = 0;
			}else
			{
				printf("Se ha cancelado la baja.\n");
			}
		}
	}

	return retorno;
}

void printPassenger(ePassenger passenger)
{
	printf("%d    %s       %s      %.2f      %s       %d      %d\n", passenger.id,
												 		passenger.lastName,
														passenger.name,
														passenger.price,
														passenger.flyCode,
														passenger.typePassenger,
														passenger.statusFlight);
}

int printPassengers(ePassenger* list, int len)
{
	int retorno = -1;
	int flagVacio = 1;

	if(list != NULL && len > 0)
	{
		printf("         PASAJEROS  \n");
		printf(" ID   APELLIDO   NOMBRE   PRECIO   CODIGO   TIPO   ESTADO\n");
		printf("-------------------------------------------------------------------\n");

		for(int i = 0; i < len; i++)
		{
			if(!list[i].isEmpty)
			{
				printPassenger(list[i]);
				flagVacio = 0;
			}
		}

		if(flagVacio)
		{
			printf("No hay pasajeros que mostrar.\n");
		}

		retorno = 0;
	}

	return retorno;
}

int sortPassengers(ePassenger* list, int len, int order)
{
	int retorno = -1;
	ePassenger auxPassenger;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len - 1; i++)
		{
			for(int j = i + 1; j < len; j++)
			{
				if((strcmp(list[i].lastName, list[j].lastName) > 0 && order == 1)
						|| (list[i].typePassenger > list[j].typePassenger && order == 1))
				{
					auxPassenger = list[i];
					list[i] = list[j];
					list[j] = auxPassenger;

				}else if((strcmp(list[i].lastName, list[j].lastName) < 0 && order == 0)
						|| ((list[i].typePassenger < list[j].typePassenger) && order == 0))
				{
					auxPassenger = list[i];
					list[i] = list[j];
					list[j] = auxPassenger;
				}
			}
		}

		retorno = 0;
	}

	return retorno;
}

int sortPassengersByCode(ePassenger* list, int len, int order)
{
	int retorno = -1;
	ePassenger auxPassenger;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len - 1; i++)
		{
			for(int j = i + 1; j < len; j++)
			{
				if((list[i].flyCode > list[j].flyCode && order == 1) ||
						((list[i].statusFlight > list[j].statusFlight) && order == 1))
				{
					auxPassenger = list[i];
					list[i] = list[j];
					list[j] = auxPassenger;

				}else if((list[i].flyCode < list[j].flyCode && order == 0) ||
						((list[i].statusFlight < list[j].statusFlight) && order == 0))
				{
					auxPassenger = list[i];
					list[i] = list[j];
					list[j] = auxPassenger;
				}
			}
		}

		retorno = 0;
	}

	return retorno;
}

int averagePrice(ePassenger* list, int len)
{
	int retorno = -1;
	int contadorDePasajeros = 0;
	float acumuladorDePrecios = 0;
	float promedioDePrecios = 0;
	int contadorSuperanPromedio = 0;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(!list[i].isEmpty)
			{
				acumuladorDePrecios += list[i].price;
				contadorDePasajeros++;
			}

			if(list[i].price > promedioDePrecios)
			{
				contadorSuperanPromedio++;
			}
		}


		promedioDePrecios = acumuladorDePrecios / contadorDePasajeros;
		printf("Total del precio de los pasajes: %.2f\nPrecio promedio: %.2f\n"
				"%d pasajeros superan el precio promedio.\n", acumuladorDePrecios, promedioDePrecios, contadorSuperanPromedio);

		retorno = 0;
	}

	return retorno;
}


