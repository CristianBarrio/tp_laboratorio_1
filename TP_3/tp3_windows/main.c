#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout,NULL);

	int continuar = 0;
    int flagCarga = 0;
    int flagGuardado = 1;
    int flagAlta = 0;
    int pasajerosIngresados = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();


    do{
    	system("cls");

        switch(menu())
        {
            case 1:
                if(controller_loadFromText("data.csv",listaPasajeros) && !flagCarga)
                {
                	printf("Datos cargados exitosamente desde data.csv (modo texto).\n");
                	flagCarga = 1;

                	if(pasajerosIngresados > 0)
                	{
						if(controller_changeId(listaPasajeros,pasajerosIngresados))
						{
							printf("ID modificado correctamente.\n");
						}else
						{
							printf("Hubo un problema al modificar el ID.\n");
						}
                	}

                }else
                {
                	printf("Hubo un error al cargar los datos.\n");
                }
                break;
            case 2:
            	if(controller_loadFromBinary("data.csv",listaPasajeros) && !flagCarga)
            	{
            		printf("Datos cargados exitosamente desde data.csv (modo binario).\n");
            		flagCarga = 1;

            		if(pasajerosIngresados > 0)
					{
						if(controller_changeId(listaPasajeros,pasajerosIngresados))
						{
							printf("ID modificado correctamente.\n");
						}else
						{
							printf("Hubo un problema al modificar el ID.\n");
						}
					}
            	}else
                {
                	printf("Hubo un error al cargar los datos.\n");
                }
            	break;
            case 3:
            	if(controller_addPassenger(listaPasajeros))
            	{
            		printf("Alta realizada con exito.\n");
            		flagGuardado = 0;
            		flagAlta = 1;
            		pasajerosIngresados++;

            	}else
                {
                	printf("Hubo un error al realizar el alta.\n");
                }
				break;
            case 4:
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
            case 5:
            	if(flagAlta)
            	{
					if(controller_removePassenger(listaPasajeros))
					{
						printf("Baja realizada con exito.\n");
						flagGuardado = 0;
						//pasajerosIngresados++;

						if(pasajerosIngresados > 0)
						{
							if(controller_changeId(listaPasajeros,pasajerosIngresados))
							{
								printf("ID modificado correctamente.\n");
							}else
							{
								printf("Hubo un problema al modificar el ID.\n");
							}
						}
					}else
					{
						printf("Hubo un error al realizar la baja.\n");
					}
            	}else
            	{
            		printf("No es posible realizar la baja sin haber ingresado pasajeros.\n");
            	}
				break;
            case 6:
            	if(flagAlta || flagCarga)
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
			case 7:
				// TARDA EN RESPONDER PERO FUNCIONA !!
				if(flagAlta || flagCarga)
				{
					controller_sortPassenger(listaPasajeros);
					printf("Ordenamiento realizado con exito.\n");
					flagGuardado = 0;
				}else
				{
					printf("No hay pasajeros para ordenar.\n");
				}
				break;
			case 8:
				if(controller_saveAsText("data.csv",listaPasajeros))
				{
					printf("Datos guardados con exito (modo texto).\n");
					flagGuardado = 1;
				}else
				{
					printf("Hubo un problema al guardar los datos.\n");
				}
				break;
			case 9:
				if(controller_saveAsBinary("data.csv",listaPasajeros))
				{
					printf("Datos guardados con exito (modo binario).\n");
					flagGuardado = 1;
				}else
				{
					printf("Hubo un problema al guardar los datos.\n");
				}
				break;
			case 10:
				if(flagGuardado)
				{
					continuar = 1;
					ll_deleteLinkedList(listaPasajeros);
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

