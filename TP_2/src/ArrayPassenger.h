/*
 * ArrayPassenger.h
 *
 *  Created on: May 9, 2022
 *      Author: Cristian
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

/**
 *
 * @param list
 * @param len
 * @return
 */
int initPassengers(ePassenger* list, int len);

/**
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
 * @return
 */
int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[], int statusFlight);

/**
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
 * @return
 */
int modifyPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[], int statusFlight);

/**
 *
 * @param list
 * @param len
 * @param id
 * @return
 */
int findPassengerById(ePassenger* list, int len,int id);

/**
 *
 * @param list
 * @param len
 * @param id
 * @return
 */
int removePassenger(ePassenger* list, int len, int id);

/**
 *
 * @param passenger
 */
void printPassenger(ePassenger passenger);

/**
 *
 * @param list
 * @param len
 * @return
 */
int printPassengers(ePassenger* list, int len);

/**
 *
 * @param list
 * @param len
 * @param order
 * @return
 */
int sortPassengers(ePassenger* list, int len, int order);

/**
 *
 * @param list
 * @param len
 * @param order
 * @return
 */
int sortPassengersByCode(ePassenger* list, int len, int order);

/**
 *
 * @param list
 * @param len
 * @return
 */
int averagePrice(ePassenger* list, int len);
