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

int myGets(char *cadena, int longitud);
int getInt(int *pResultado);
int esNumerica(char *cadena);
int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo);
int getFloat(float *pResultado);
int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo);
int utn_getName(char* cadena, char* mensaje, char* mensajeError);

/*
/**brief Imprime el mensaje deseado y pide el ingreso de un numero entero positivo, y
 * valida si es correcto
 *
 * @param mensaje char[]
 * @param numero int
 * @return retorna -1 si hubo un error, de lo contrario retorna 0
 *//*
int obtenerIntPositivo(char mensaje[], int* numero);

/**brief
 *
 * @param mensaje
 * @param numero
 * @return retorna -1 si hubo un error, de lo contrario retorna 0
 *//*
int obtenerFloatPositivo(char mensaje[], float* numero);

/**brief
 *
 * @param mensaje
 * @param cadena
 * @return retorna -1 si hubo un error, de lo contrario retorna 0
 *//*
int obtenerCadena(char mensaje[], char cadena[]);

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
