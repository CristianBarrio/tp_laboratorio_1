/*
 * utn.h
 *
 *  Created on: May 9, 2022
 *      Author: Cristian
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
 * @param mensaje
 * @param numero
 * @return
 */
int obtenerIntPositivo(char mensaje[], int* numero);

/**
 *
 * @param mensaje
 * @param numero
 * @return
 */
int obtenerFloatPositivo(char mensaje[], float* numero);

/**
 *
 * @param mensaje
 * @param cadena
 * @return
 */
int obtenerCadena(char mensaje[], char cadena[]);

/**
 *
 * @return
 */
int menu();

/**
 *
 * @return
 */
int menuModificacion();

/**
 *
 * @return
 */
int menuInformes();
