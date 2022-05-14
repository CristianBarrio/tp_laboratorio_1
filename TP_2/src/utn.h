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

/** Pide una cadena y cambia el ultimo elemento de '\n' a \0'
 *
 * @param cadena
 * @param longitud
 * @return retorna -1 si hubo un error, de lo contrario 0
 */
int myGets(char *cadena, int longitud);

/** Recibe una cadena y devuelve 1 si el texto solo esta compuesto por numeros
 *
 * @param pResultado
 * @return retorna -1 si hubo un error, de lo contrario 0
 */
int getInt(int *pResultado);

/** recorre la cadena para verificar que todos sus elementos sean numericos
 *
 * @param cadena
 * @return retorna -1 si hubo un error, de lo contrario 0
 */
int esNumerica(char *cadena);

/** Recibe un texto convertido a entero, imprime un mensaje y un mensaje de error
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @return retorna -1 si hubo un error, de lo contrario 0
 */
int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo);

/** Pide un texto, lo almacena como cadena, valida y lo convierte a numero
 *
 * @param pResultado
 * @return retorna -1 si hubo un error, de lo contrario 0
 */
int getFloat(float *pResultado);

/**
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @return retorna -1 si hubo un error, de lo contrario 0
 */
int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo);

/** recibe un texto y valida que sea solo compuesto por caracteres
 *
 * @param cadena
 * @param mensaje
 * @param mensajeError
 * @return retorna -1 si hubo un error, de lo contrario 0
 */
int utn_getName(char* cadena, char* mensaje, char* mensajeError);


/**brief menu de opciones del ABM
 *
 * @return retorna la opcion elegida
 */
int menu();

/**brief menu de opciones de la modificacion
 *
 * @return retorna la opcion elegida
 */
int menuModificacion();

/**brief menu de opciones de ordenamiento
 *
 * @return retorna la opcion elegida
 */
int menuInformes();

