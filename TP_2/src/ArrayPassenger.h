/*
 * ArrayPassenger.h
 *
 *  Created on: May 9, 2022
 *      Author: Barrio Cristian
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#define LEN 2000

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}ePassenger;

#endif /* ARRAYPASSENGER_H_ */

/**brief To indicate that all position in the array are empty,* this function put the flag (isEmpty)
 * 		in TRUE in all* position of the array
 * @param list ePassenger* Pointer to array of passenger
 * @param len int Array length
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initPassengers(ePassenger* list, int len);

/**brief add in a existing list of passengers the values received as parameters* in the first
 * 		empty position
 *
 * @param list
 * @param len
 * @param id
 * @param name
 * @param lastName
 * @param price
 * @param typePassenger
 * @param flyCode
 * @param statusFlight
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[], int statusFlight);

/**brief permite modificar alguno de los valores pertenecientes al pasajero
 * @param list ePassenger*
 * @param len
 * @param id
 * @param name
 * @param lastName
 * @param price
 * @param typePassenger
 * @param flyCode
 * @param statusFlight
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int modifyPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[], int statusFlight);

/**brief find a Passenger by Id en returns the index position in array.
 *
 * @param list find a Passenger by Id en returns the index position in array.
 * @param len
 * @param id
 * @return Return passenger index position or (-1) if [Invalid length or
 * 			NULL pointer received or passenger not found]
 */
int findPassengerById(ePassenger* list, int len,int id);

/**brief Remove a Passenger by Id (put isEmpty Flag in 1)
 *
 * @param list
 * @param len
 * @param id
 * @return int Return (-1) if Error
 * 			 [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
 */
int removePassenger(ePassenger* list, int len, int id);

/**brief informa los datos pertenecientes a un pasajero
 *
 * @param passenger
 */
void printPassenger(ePassenger passenger);

/**brief print the content of passengers array
 *
 * @param list
 * @param len
 * @return
 */
int printPassengers(ePassenger* list, int len);

/**brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
 *
 * @param list
 * @param len
 * @param order int [1] indicate UP - [0] indicate DOWN
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int sortPassengers(ePassenger* list, int len, int order);

/**brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
 *
 * @param list
 * @param len
 * @param order int [1] indicate UP - [0] indicate DOWN
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int sortPassengersByCode(ePassenger* list, int len, int order);

/**brief calcula el precio promedio, el total de los precios y el numero de pasajeros
 * que superan el promedio
 *
 * @param list
 * @param len
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int averagePrice(ePassenger* list, int len);
