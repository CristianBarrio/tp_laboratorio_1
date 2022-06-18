/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// TP4 Barrio Cristian 1°D

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "UTN.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv.
     2. Alta de pasajero
     3. Modificar datos de pasajero
     4. Baja de pasajero
     5. Listar pasajeros
     6. Ordenar pasajeros
     7. Guardar los datos en una sublista.
     8. Guardar los datos de los pasajeros en el archivo data.csv.
     9. Salir
*****************************************************/

int main(void)
{
	setbuf(stdout,NULL);

	/*startTesting(1);  // ll_newLinkedList  usada
	startTesting(2);  // ll_len  usada
	startTesting(3);  // getNode - test_getNode  usada en ll_get
	startTesting(4);  // addNode - test_addNode  usada en ll_add
	startTesting(5);  // ll_add  usada
	startTesting(6);  // ll_get  usada
	startTesting(7);  // ll_set  usada en ll_sort
	startTesting(8);  // ll_remove  usada en ll_pop
	startTesting(9);  // ll_clear  usada
	startTesting(10); // ll_deleteLinkedList  usada
	startTesting(11); // ll_indexOf usada en ll_contains
	startTesting(12); // ll_isEmpty usada
	startTesting(13); // ll_push
	startTesting(14); // ll_pop  usada
	startTesting(15); // ll_contains   usada en ll_containsAll
	startTesting(16); // ll_containsAll  usada
	startTesting(17); // ll_subList   usada en ll_clone
	startTesting(18); // ll_clone   usada
	startTesting(19); // ll_sort   usada*/


	int continuar = 0;
	int flagCarga = 0;
	int flagGuardado = 1;
	int flagAlta = 0;
	int flagCopia = 0;

	LinkedList* listaPasajeros = ll_newLinkedList();
	LinkedList* copiaListaPasajeros = ll_newLinkedList();

	do{
		system("cls");

		switch(menu())
		{
			case 1:
				if(!flagCarga)
				{
					if(controller_loadFromText("data.csv",listaPasajeros))
					{
						printf("Datos cargados exitosamente desde data.csv.\n");
						flagCarga = 1;
					}else
					{
						printf("Hubo un error al cargar los datos.\n");
					}
				}else
				{
					printf("Ya se han cargado los datos.\n");
				}
				break;
			case 2:
				if(flagCarga)
				{
					if(controller_addPassenger(listaPasajeros))
					{
						printf("Alta realizada con exito.\n");
						flagGuardado = 0;
						flagAlta = 1;

					}else
					{
						printf("Hubo un error al realizar el alta.\n");
					}
				}else
				{
					printf("No se puede realizar el alta sin antes cargar los datos.\n");
				}
				break;
			case 3:
				if(flagAlta)
				{
					if(controller_editPassenger(listaPasajeros))
					{
						printf("Modificacion realizada con exito.\n");
						flagGuardado = 0;
					}else
					{
						printf("Hubo un error al realizar la modificacion.\n");
					}
				}else
				{
					printf("No es posible realizar la modificacion sin haber ingresado pasajeros.\n");
				}
				break;
			case 4:
				if(flagAlta)
				{
					if(controller_removePassenger(listaPasajeros))
					{
						printf("Baja realizada con exito.\n");
						flagGuardado = 0;
					}else
					{
						printf("Hubo un error al realizar la baja.\n");
					}
				}else
				{
					printf("No es posible realizar la baja sin haber ingresado pasajeros.\n");
				}
				break;
			case 5:
				if(!ll_isEmpty(listaPasajeros))
				{
					if(controller_ListPassenger(listaPasajeros))
					{
						printf("Informes realizados con exito.\n");
					}else
					{
						printf("Hubo un error al realizar los informes.\n");
					}
				}else
				{
					printf("No hay pasajeros para mostrar.\n");
				}
				break;
			case 6:
				// TARDA EN RESPONDER PERO FUNCIONA !!
				if(!ll_isEmpty(listaPasajeros))
				{
					controller_sortPassenger(listaPasajeros);
					printf("Ordenamiento realizado con exito.\n");
					flagGuardado = 0;
				}else
				{
					printf("No hay pasajeros para ordenar.\n");
				}
				break;
			case 7:
				ll_clear(copiaListaPasajeros);
				copiaListaPasajeros = ll_clone(listaPasajeros);
				flagCopia = 1;
				printf("Se ha creado una copia de la lista.\n");
				break;
			case 8:
				if(!flagGuardado)
				{
					if(!flagCopia)
					{
						if(controller_saveAsText("data.csv",listaPasajeros))
						{
							printf("Datos guardados con exito.\n");
							flagGuardado = 1;
						}else
						{
							printf("Hubo un problema al guardar los datos.\n");
						}
					}else
					{
						if(ll_containsAll(listaPasajeros, copiaListaPasajeros))
						{
							ll_clear(listaPasajeros);
							listaPasajeros = ll_clone(copiaListaPasajeros);
							ll_clear(copiaListaPasajeros);
							if(controller_saveAsText("data.csv",listaPasajeros))
							{
								printf("Datos guardados con exito.\n");
								flagGuardado = 1;
							}else
							{
								printf("Hubo un problema al guardar los datos.\n");
							}
							flagCopia = 0;
						}else
						{
							printf("Ambas listas son iguales.\n");
							flagCopia = 0;
						}
					}
				}else
				{
					printf("No se han realizado cambios a la lista.\n");
				}
				break;
			case 9:
				if(flagGuardado)
				{
					continuar = 1;
					ll_deleteLinkedList(listaPasajeros);
					ll_deleteLinkedList(copiaListaPasajeros);
					printf("Se elimino el LinkedList. Finaliza el programa.\n");
				}else
				{
					printf("No se puede salir del sistema sin antes guardar los datos.\n");
				}
				break;
		}
		system("pause");
	}while(continuar != 1);

    return EXIT_SUCCESS;
}

































