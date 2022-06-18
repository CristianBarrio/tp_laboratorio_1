/*
 * Controller.c
 *
 *  Created on: 16 jun. 2022
 *      Author: Barrio Cristian
 */


#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* pFile = fopen(path,"r");

		if(pFile != NULL)
		{
			if(parser_PassengerFromText(pFile,pArrayListPassenger))
			{
				printf("Archivos cargados con exito.\n");
				retorno = 1;
			}
			fclose(pFile);
		}
	}else
	{
		printf("Error al abrir el archivo.\n");
	}

	return retorno;
}


int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	Passenger* pasajero;
	int id;
	char idStr[TAM];
	char nombre[TAM_NOMBRE];
	char apellido[TAM_NOMBRE];
	float precio;
	char precioStr[TAM];
	int tipo;
	char tipoStr[TAM_TIPO];
	char codigo[TAM];
	int estado;
	char estadoStr[TAM_TIPO];

	if(pArrayListPassenger != NULL)
	{
		int tam = ll_len(pArrayListPassenger);
		id = tam + 1;

		printf("     ALTA PASAJERO\n"
				"------------------------------\n");

		utn_getString(nombre,"Ingrese el nombre: ","Nombre invalido.\n");
		utn_getString(apellido,"Ingrese el apellido: ","Apellido invalido.\n");
		utn_getFloat(&precio,"Ingrese el precio: ","Precio invalido.\n", 1, 999999);
		utn_getInt(&tipo,"Ingrese el tipo: \n"
						"FirstClass (1) ExecutiveClass (2) EconomyClass (3) ", "Tipo invalido.\n",1,3);
		utn_getString(codigo,"Ingrese el codigo de vuelo: ","Codigo invalido.\n");
		utn_getInt(&estado,"Ingrese el estado del vuelo: \n"
							"Aterrizado (1) En vuelo (2) En horario (3) Demorado (4) ","Estado invalido.\n",1,4);

		itoa(id,idStr,TAM);
		itoa(precio,precioStr,TAM);
		itoa(tipo,tipoStr,TAM);
		itoa(estado,estadoStr,TAM);

		pasajero = Passenger_newParametros(idStr,nombre,tipoStr,apellido,codigo,precioStr,estadoStr);

		if(pasajero != NULL)
		{
			if(!ll_add(pArrayListPassenger,pasajero))
			{
				retorno = 1;
			}
		}

	}


    return retorno;
}


int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int continuar = 0;
	int indice;
	int tam = ll_len(pArrayListPassenger);
	int id;
	char nombre[TAM_NOMBRE];
	char apellido[TAM_NOMBRE];
	float precio;
	int tipo;
	char codigo[TAM];
	int estado;
	int datoModificado;
	Passenger* pasajero;
	Passenger* pasajeroModificado;

	if(pArrayListPassenger != NULL && tam > 0)
	{
		system("cls");
		printf("        MODIFICAR PASAJEROS\n"
				"-----------------------------------------------\n");

		utn_getInt(&id,"Ingrese ID del pasajero: ", "ID invalido.\n",1,999999);
		indice = Passenger_buscarPasajero(pArrayListPassenger,id);

		if(indice < 1)
		{
			printf("No existe un pasajero con ID %d.\n",id);
		}else
		{
			pasajero = (Passenger*)ll_get(pArrayListPassenger,indice);
			pasajeroModificado = Passenger_new();

			if(pasajero != NULL && pasajeroModificado != NULL)
			{
				Passenger_mostrarUnPasajero(pasajero);

				while(!continuar)
				{
					switch(menuModificacion())
					{
						case 1:
							utn_getString(nombre,"Ingrese el nombre: ","Nombre invalido.\n");
							if(Passenger_setNombre(pasajeroModificado,nombre))
							{
								datoModificado = 1;
							}else
							{
								datoModificado = 0;
							}
							break;
						case 2:
							utn_getString(apellido,"Ingrese el apellido: ","Apellido invalido.\n");
							if(Passenger_setApellido(pasajeroModificado,apellido))
							{
								datoModificado = 1;
							}else
							{
								datoModificado = 0;
							}
							break;
						case 3:
							utn_getFloat(&precio,"Ingrese el precio: ","Precio invalido.\n",1,999999);
							if(Passenger_setPrecio(pasajeroModificado,precio))
							{
								datoModificado = 1;
							}else
							{
								datoModificado = 0;
							}
							break;
						case 4:
							utn_getInt(&tipo,"Ingrese el tipo: \n"
												"FirstClass (1) ExecutiveClass (2) EconomyClass (3) ", "Tipo invalido.\n",1,3);
							if(Passenger_setTipoPasajero(pasajeroModificado,tipo))
							{
								datoModificado = 1;
							}else
							{
								datoModificado = 0;
							}
							break;
						case 5:
							utn_getString(codigo,"Ingrese el codigo de vuelo: ","Codigo invalido.\n");
							if(Passenger_setCodigoVuelo(pasajeroModificado,codigo))
							{
								datoModificado = 1;
							}else
							{
								datoModificado = 0;
							}
							break;
						case 6:
							utn_getInt(&estado,"Ingrese el estado del vuelo: \n"
												"Aterrizado (1) En vuelo (2) En horario (3) Demorado (4) ","Estado invalido.\n",1,4);
							if(Passenger_setEstadoVuelo(pasajeroModificado,estado))
							{
								datoModificado = 1;
							}else
							{
								datoModificado = 0;
							}
							break;
						case 7:
							continuar = 1;
							break;
					}

					if(datoModificado && !continuar)
					{
						if(!ll_push(pArrayListPassenger,indice,pasajeroModificado))
						{
							printf("Dato modificado correctamente.\n");
						}
					}else if(!continuar)
					{
						printf("Hubo un error al modificar el dato.\n");
					}
				}
				retorno = 1;
			}
		}
	}

    return retorno;
}


int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int id;
	int indice;
	int tam = ll_len(pArrayListPassenger);
	int confirmar;
	Passenger* pasajero;
	Passenger* pasajeroEliminado;

	if(pArrayListPassenger != NULL && tam > 0)
	{
		system("cls");
		printf("     BAJA PASAJERO\n"
				"------------------------------\n");
		utn_getInt(&id,"Ingrese ID del pasajero: ","ID invalido.\n",1,999999);
		indice = Passenger_buscarPasajero(pArrayListPassenger,id);

		if(indice < 1)
		{
			printf("No existe un pasajero con ID %d.\n",id);
		}else
		{
			pasajero = (Passenger*)ll_get(pArrayListPassenger,indice);

			if(pasajero != NULL)
			{
				Passenger_mostrarUnPasajero(pasajero);
				utn_getInt(&confirmar, "Confirmar Baja? Si (1) No (0): ", "Opcion invalida.\n", 0, 1);

				if(confirmar)
				{
					pasajeroEliminado = ll_pop(pArrayListPassenger,indice);
					printf("Se ha eliminado el pasajero: ");
					Passenger_mostrarUnPasajero(pasajeroEliminado);
				}else
				{
					printf("Se ha cancelado la baja.\n");
				}

				retorno = 1;
			}
		}
	}

    return retorno;
}


int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	Passenger* pasajero;
	int tam = ll_len(pArrayListPassenger);

	system("cls");
	printf("        PASAJEROS\n"
			"-----------------------------------------\n");

	if(pArrayListPassenger != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			pasajero = (Passenger*) ll_get(pArrayListPassenger,i);
			if(pasajero != NULL)
			{
				Passenger_mostrarUnPasajero(pasajero);
			}
		}

		retorno = 1;
	}

	return retorno;
}


int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;

	if(pArrayListPassenger != NULL)
	{
		if(ll_sort(pArrayListPassenger,Passenger_compararApellido,1))
		{
			retorno = 1;
		}
	}

	return retorno;
}


int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int id;
	char nombre[TAM_NOMBRE];
	char apellido[TAM_NOMBRE];
	float precio;
	char codigo[TAM];
	int tipo;
	int estado;
	char tipoStr[TAM_TIPO];
	char estadoStr[TAM_TIPO];
	Passenger* pasajero;
	int tam = ll_len(pArrayListPassenger);

		if(path != NULL && pArrayListPassenger != NULL)
		{
			if(tam > 0)
			{
				FILE* pFile = fopen(path,"a");

				if(pFile != NULL)
				{
					fprintf(pFile,"\n\nid,name,lastname,price,flycode,typePassenger,statusFlight\n");
					for(int i = 0; i < tam; i++)
					{
						pasajero = (Passenger*)ll_get(pArrayListPassenger,i);

					if(pasajero != NULL && Passenger_getId(pasajero,&id) &&
							Passenger_getNombre(pasajero,nombre) &&
							Passenger_getApellido(pasajero,apellido) &&
							Passenger_getCodigoVuelo(pasajero,codigo) &&
							Passenger_getTipoPasajero(pasajero,&tipo) &&
							Passenger_getPrecio(pasajero,&precio) &&
							Passenger_getEstadoVuelo(pasajero,&estado))
					{
						switch(tipo)
								{
									case 1:
										strcpy(tipoStr,"FirstClass");
										break;
									case 2:
										strcpy(tipoStr,"ExecutiveClass");
										break;
									default:
										strcpy(tipoStr,"EconomyClass");
										break;
								}

								switch(estado)
								{
									case 1:
										strcpy(estadoStr,"Aterrizado");
										break;
									case 2:
										strcpy(estadoStr,"En vuelo");
										break;
									case 3:
										strcpy(estadoStr,"En horario");
										break;
									default:
										strcpy(estadoStr,"Demorado");
										break;
								}

						fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n",id,nombre,apellido,precio,codigo,tipoStr,estadoStr);
					}
					retorno = 1;
				}
			}

			fclose(pFile);
			}
		}
    return retorno;
}

