/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#define TAM_NOMBRE 50
#define TAM_TIPO 20
#define TAM 10

typedef struct
{
	int id;
	char nombre[TAM_NOMBRE];
	char apellido[TAM_NOMBRE];
	float precio;
	int tipoPasajero;
	char codigoVuelo[TAM];
	int estadoVuelo;
}Passenger;

/** Crea un nuevo pasajero y le da un espacio en la memoria
 *
 * @return retorna el nuevo pasajero
 */
Passenger* Passenger_new();

/** Asigna nuevos parametros al pasajero
 *
 * @param idStr char* puntero al id
 * @param nombreStr char* puntero al nombre
 * @param tipoPasajeroStr char* puntero al tipo de pasajero
 * @param apellido char* puntero al apellido
 * @param codigo char* puntero al codigo de vuelo
 * @param precio char* puntero al precio
 * @param estado char* puntero al estado del vuelo
 * @return
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr, char* apellido, char* codigo, char* precio, char* estado);

/** Elimina al pasajero
 *
 * @param this Passenger* puntero al pasajero
 */
void Passenger_delete(Passenger* this);

/** Asigna el ID al pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param id int ID del pasajero
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Passenger_setId(Passenger* this,int id);

/** Obtiene el ID del pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param id int* puntero al ID del pasajero
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Passenger_getId(Passenger* this,int* id);

/** Asigna el nombre al pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param nombre char* puntero al nombre del pasajero
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Passenger_setNombre(Passenger* this,char* nombre);

/** Obtiene el nombre del pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param nombre char* puntero al nombre del pasajero
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Passenger_getNombre(Passenger* this,char* nombre);

/** Asigna el apellido al pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param apellido char* puntero al apellido del pasajero
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Passenger_setApellido(Passenger* this,char* apellido);

/** Obtiene el apellido del pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param apellido char* puntero al apellido del pasajero
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Passenger_getApellido(Passenger* this,char* apellido);

/** Asigna el codigo de vuelo al pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param codigoVuelo char* puntero al codigo de vuelo
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/** Obtiene el codigo de vuelo del pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param codigoVuelo char* puntero al codigo de vuelo
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/** Asigna el tipo al pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param tipoPasajero int tipo de pasajero
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);

/** Obtiene el tipo del pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param tipoPasajero int* puntero al tipo de pasajero
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

/** Asigna el precio al pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param precio float Precio del vuelo
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Passenger_setPrecio(Passenger* this,float precio);

/** Obtiene el precio del pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param precio float* puntero al precio del vuelo
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Passenger_getPrecio(Passenger* this,float* precio);

/** Asigna el estado del vuelo al pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param estadoVuelo int estado del vuelo
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo);

/** Obtiene el estado del vuelo del pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param estadoVuelo int* puntero al estado del vuelo
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo);

/** Muestra los datos de un pasajero
 *
 * @param unPasajero Passenger* puntero al pasajero
 */
void Passenger_mostrarUnPasajero(Passenger* unPasajero);

/** Busca un pasajero segun su ID
 *
 * @param this LinkedList* puntero al LinkedList
 * @param id int ID a buscar
 * @return retorna 0 si hubo un error, de lo contrario devuelve el indice del pasajero en el LinkedList
 */
int Passenger_buscarPasajero(LinkedList* this, int id);

/** Compara los apellidos de dos pasajeros
 *
 * @param pasajero1 void* puntero a un pasajero de la lista
 * @param pasajero2 void* puntero a otro pasajero de la lista
 * @return retorna el resultado de la funcion strcmp
 */
int Passenger_compararApellido(void* pasajero1, void* pasajero2);

#endif /* PASSENGER_H_ */
