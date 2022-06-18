/*
 * Controller.h
 *
 *  Created on: 16 jun. 2022
 *      Author: Barrio Cristian
 */

#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "UTN.h"

#endif /* SRC_CONTROLLER_H_ */


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char* archivo a cargar
 * \param pArrayListPassenger LinkedList* puntero a la lista de pasajeros
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/** \brief Permite ingresar un pasajero al LinkedList
 *
 * \param pArrayListPassenger LinkedList* puntero a la lista de pasajeros
 * \nparam idsUsados int cantidad de IDs ya utilizados
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger);

/** \brief Permite modificar los datos de un pasajero seleccionado
 *
 * \param pArrayListPassenger LinkedList* puntero a la lista de pasajeros
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);

/** \brief Permite eliminar a un pasajero de la lista
 *
 * \param pArrayListPassenger LinkedList* puntero a la lista de pasajeros
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);

/** \brief Muestra la lista de pasajeros
 *
 * \param pArrayListPassenger LinkedList* puntero a la lista de pasajeros
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/** \brief Ordena los pasajeros por apellido
 *
 * \param pArrayListPassenger LinkedList* puntero a la lista de pasajeros
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char* archivo a guardar
 * \param pArrayListPassenger LinkedList* puntero a la lista de pasajeros
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
