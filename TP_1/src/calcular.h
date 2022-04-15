/*
 * calcular.h
 *
 *  Created on: Apr 15, 2022
 *      Author: Cristian
 */

#ifndef CALCULAR_H_
#define CALCULAR_H_

#ifndef CALCULAR_H_INCLUDED
#define CALCULAR_H_INCLUDED



#endif // CALCULAR_H_INCLUDED

/** \brief calcula el costo del vuelo pagando con debito
 *
 * \param num int precio inicial del vuelo
 * \param resultado float* direccion de memoria del resultado
 * \return
 *
 */
void calcularCostoDebito(int num, float* resultado);

/** \brief calcula el costo del vuelo pagando con credito
 *
 * \param num int precio inicial del vuelo
 * \param resultado float* direccion de memoria del resultado
 * \return
 *
 */
void calcularCostoCredito(int num, float* resultado);

/** \brief calcula el costo del vuelo pagando con Bitcoin
 *
 * \param num int precio inicial del vuelo
 * \param resultado float* direccion de memoria del resultado
 * \return
 *
 */
void calcularCostoBtc(int num, float* resultado);

/** \brief calcula el costo por kilometro
 *
 * \param num int precio inicial del vuelo
 * \param km int kilometros ingresados
 * \param resultado float* direccion de memoria del resultado
 * \return
 *
 */
void calcularCostoUnitario(int num, int km, float* resultado);

/** \brief calcula la diferencia de precio de los vuelos
 *
 * \param num1 int precio inicial del vuelo de Aerolineas
 * \param num2 int precio inicial del vuelo de Latam
 * \param resultado float* direccion de memoria del resultado
 * \return
 *
 */
void calcularDiferencia(int num1, int num2, int* resultado);


#endif /* CALCULAR_H_ */
