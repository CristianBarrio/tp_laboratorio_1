/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* pasajero;

	if(pasajero != NULL)
	{
		pasajero = (Passenger*) malloc(sizeof(Passenger));
	}

	return pasajero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr, char* apellido, char* codigo, char* precio, char* estado)
{
	Passenger* pasajero;

	pasajero = Passenger_new();


	if(pasajero != NULL &&
		Passenger_setId(pasajero,atoi(idStr)) &&
		Passenger_setNombre(pasajero,nombreStr) &&
		Passenger_setApellido(pasajero,apellido) &&
		Passenger_setCodigoVuelo(pasajero,codigo) &&
		Passenger_setTipoPasajero(pasajero,atoi(tipoPasajeroStr)) &&
		Passenger_setPrecio(pasajero,atof(precio)) &&
		Passenger_setEstadoVuelo(pasajero,atoi(estado)))
	{
		return pasajero;
	}else
	{
		Passenger_delete(pasajero);
	}
	//strcpy(pasajero->nombre, nombreStr);
	//strcpy(pasajero->tipoPasajero, tipoPasajeroStr);
	//strcpy(pasajero->apellido, apellido);
	//strcpy(pasajero->codigoVuelo, codigo);
	//pasajero->precio = atof(precio);
	//strcpy(pasajero->estadoVuelo = estado);

	return 0;
}

void Passenger_delete(Passenger* this)
{
	free(this);
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno = 0;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno = 0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre,nombre);
		//*this->nombre = nombre;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		//*nombre = this->nombre;
		retorno = 1;
	}

	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = 0;

	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido,apellido);
		//*this->apellido = apellido;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = 0;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		//*apellido = this->apellido;
		retorno = 1;
	}

	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = 0;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		//*this->codigoVuelo = codigoVuelo;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = 0;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		//*codigoVuelo = this->codigoVuelo;
		retorno = 1;
	}

	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = 0;

	if(this != NULL)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = 0;

	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 1;
	}

	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = 0;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = 0;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 1;
	}

	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo)
{
	int retorno = 0;

	if(this != NULL)
	{
		this->estadoVuelo = estadoVuelo;
		retorno = 1;
	}

	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo)
{
	int retorno = 0;

	if(this != NULL && estadoVuelo != NULL)
	{
		*estadoVuelo = this->estadoVuelo;
		retorno = 1;
	}

	return retorno;
}

void Passenger_mostrarUnPasajero(Passenger* unPasajero)
{
	int id;
	char nombre[TAM_NOMBRE];
	char apellido[TAM_NOMBRE];
	char codigoVuelo[TAM];
	int tipoPasajero;
	char tipoStr[TAM_TIPO];
	float precio;
	int estadoVuelo;
	char estadoStr[TAM_TIPO];

	if(unPasajero != NULL && Passenger_getId(unPasajero,&id) &&
							Passenger_getNombre(unPasajero,nombre) &&
							Passenger_getApellido(unPasajero,apellido) &&
							Passenger_getCodigoVuelo(unPasajero,codigoVuelo) &&
							Passenger_getTipoPasajero(unPasajero,&tipoPasajero) &&
							Passenger_getPrecio(unPasajero,&precio) &&
							Passenger_getEstadoVuelo(unPasajero,&estadoVuelo))
	{

		switch(tipoPasajero)
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

		switch(estadoVuelo)
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

		printf("%d, %15s, %15s, %.2f, %10s, %10s, %10s\n", id,
												nombre,
												apellido,
												precio,
												codigoVuelo,
												tipoStr,
												estadoStr);
	}
}

int Passenger_buscarPasajero(LinkedList* this, int id)
{
	int retorno = 0;
	int tam;
	Passenger* pasajero;

	if(this != NULL && id > 0)
	{
		tam = ll_len(this);

		for(int i = 0; i < tam; i++)
		{
			pasajero = (Passenger*)ll_get(this,i);

			if(pasajero->id == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


int Passenger_compararApellido(void* pasajero1, void* pasajero2)
{
	int retorno = -1;
	char apellido1[TAM_NOMBRE];
	char apellido2[TAM_NOMBRE];

	if(pasajero1 != NULL && pasajero2 != NULL)
	{
		if(Passenger_getApellido(pasajero1,apellido1) && Passenger_getApellido(pasajero2,apellido2))
		{
			retorno = strcmp(apellido1,apellido2);
		}
	}

	return retorno;
}
