#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char* archivo a cargar
 * \param pArrayListPassenger LinkedList* puntero a la lista de pasajeros
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char* archivo a cargar
 * \param pArrayListPassenger LinkedList* puntero a la lista de pasajeros
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/** \brief Permite ingresar un pasajero al LinkedList
 *
 * \param pArrayListPassenger LinkedList* puntero a la lista de pasajeros
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger,int idsUsados);

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

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char* archivo a guardar
 * \param pArrayListPassenger LinkedList* puntero a la lista de pasajeros
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

/** Modifica el ID en caso de realizar un alta previo a la carga del archivo
 *
 * @param pArrayListPassenger puntero a la lista de pasajeros
 * @param pasajerosIngresados int cantidad de pasajeros ingresados por alta
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int controller_changeId(LinkedList* pArrayListPassenger, int pasajerosIngresados);


