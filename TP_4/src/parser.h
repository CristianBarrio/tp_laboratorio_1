/*
 * parser.h
 *
 *  Created on: 16 jun. 2022
 *      Author: Barrio Cristian
 */

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Passenger.h"


#endif /* SRC_PARSER_H_ */


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * @param pFile FILE* archivo a parsear
 * @param pArrayListPassenger LinkedList* puntero a la lista de pasajeros
 * @return retorna 0 si hubo un problema, de lo contrario 1
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);
