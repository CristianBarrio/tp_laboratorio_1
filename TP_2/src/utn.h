/*
 * utn.h
 *
 *  Created on: May 9, 2022
 *      Author: Barrio Cristian
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#endif /* UTN_H_ */

/**
 *
 * @param cadena
 * @param longitud
 * @return
 */
int myGets(char *cadena, int longitud);

/**
 *
 * @param pResultado
 * @return
 */
int getInt(int *pResultado);

/**
 *
 * @param cadena
 * @return
 */
int esNumerica(char *cadena);

/**
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @return
 */
int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo);

/**
 *
 * @param pResultado
 * @return
 */
int getFloat(float *pResultado);

/**
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @return
 */
int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo);

/**
 *
 * @param cadena
 * @param mensaje
 * @param mensajeError
 * @return
 */
int utn_getName(char* cadena, char* mensaje, char* mensajeError);


/**brief
 *
 * @return
 */
int menu();

/**brief
 *
 * @return
 */
int menuModificacion();

/**brief
 *
 * @return
 */
int menuInformes();
