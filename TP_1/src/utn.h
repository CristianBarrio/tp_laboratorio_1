#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED

/** \brief menu de opciones
 *
 * \param x int kilometros del viaje
 * \param y int precio del vuelo de Aerolineas
 * \param z int precio del vuelo de Latam
 * \return retorna la opcion elegida del menu
 */
int menu(int x, int y, int z);

/** \brief valida el ingreso de km del viaje
 *
 * \param x int* puntero a la direccion de memoria de los kilometros
 * \param
 * \return retorna 0 si hubo un error, de lo contrario retorna 1
 *
 */
int ingresarKm(int* x);

/** \brief submenu para ingresar los precios de los vuelos
 *
 * \param precioAerolineas int* direccion de memoria del precio de Aerolineas
 * \param precioLatam int* direccion de memoria del precio de Latam
 * \param flagAerolineas int* direccion de memoria de la bandera del precio de Aerolineas
 * \param flagLatam int* direccion de memoria de la bandera del precio de Latam
 * \return
 *
 */
void menuPrecios(int* precioAerolineas, int* precioLatam, int* flagAerolineas, int* flagLatam);

/** \brief valida el ingreso del precio del vuelo
 *
 * \param precio int* direccion de memoria del precio del vuelo
 * \param
 * \return retorna 0 si hubo un error, de lo contrario retorna 1
 *
 */
int ingresarPrecio(int* precio);

/** \brief muestra los resultados de los calculos de Aerolineas
 *
 * \param km int kilometros ingresados
 * \param precio int precio del vuelo
 * \param debito float precio pagando con debito
 * \param credito float precio pagando con credito
 * \param btc float precio pagando con btc
 * \param unitario float valor por kilometro
 * \return
 *
 */
void mostrarResultadosAerolineas(int km, int precio, float debito, float credito, float btc, float unitario);

/** \brief muestra los resultados de los calculos de Latam
 *
 * \param precio int precio del vuelo
 * \param debito float precio pagando con debito
 * \param credito float precio pagando con credito
 * \param btc float precio pagando con btc
 * \param unitario float valor por kilometro
 * \param diferencia float diferencia de precio entre Latam y Aerolineas
 * \return
 *
 */
void mostrarResultadosLatam(int precio, float debito, float credito, float btc, float unitario, float diferencia);
