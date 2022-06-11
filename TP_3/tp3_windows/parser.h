#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * @param pFile FILE* archivo a parsear
 * @param pArrayListPassenger LinkedList* puntero a la lista de pasajeros
 * @return retorna 0 si hubo un problema, de lo contrario 1
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * @param pFile FILE* archivo a parsear
 * @param pArrayListPassenger LinkedList* puntero a la lista de pasajeros
 * @return retorna 0 si hubo un problema, de lo contrario 1
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
