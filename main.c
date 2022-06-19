#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menu.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option=0;
    int cantidadPasajeros=0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	menuPassenger();
    	if(!utn_getInt(&option,"Ingrese una opcion:","Error,opcion invalida\n",1,10,5))
    	{
    		switch(option)
			{
				case 1:
					if(!controller_loadFromText("data.csv",listaPasajeros))
					{
						printf("Datos cargados con exito\n");
						cantidadPasajeros = ll_len(listaPasajeros);
					}
					else
					{
						printf("Error al cargar los datos\n");
					}
					break;
				case 2:
					if(!controller_loadFromBinary("data.bin",listaPasajeros))
					{
						printf("Datos cargados con exito\n");
						cantidadPasajeros = ll_len(listaPasajeros);
					}
					else
					{
						printf("Error al cargar los datos\n");
					}
					break;
				case 3:
					if(!controller_addPassenger(listaPasajeros))
					{
						printf("Alta de pasajero exitosa!\n");
						cantidadPasajeros = ll_len(listaPasajeros);
					}
					else
					{
						printf("Error al dar el alta\n");
					}
					break;
				case 4:
					if(cantidadPasajeros >0)
					{
						if(!controller_editPassenger(listaPasajeros))
						{
							printf("Modificacion exitosa!\n");
						}
						else
						{
							printf("Error al modificar\n");
						}
					}
					else
					{
						printf("Primero deberia dar de alta Pasajeros\n");
					}
					break;
				case 5:
					if(cantidadPasajeros >0)
					{
						if(!controller_removePassenger(listaPasajeros))
						{
							printf("Baja con exito\n");
							cantidadPasajeros = ll_len(listaPasajeros);
						}
						else
						{
							printf("Baja cancelada\n");
						}
					}
					else
					{
						printf("Primero deberia dar de alta pasajeros\n");
					}
					break;
				case 6:
					if(cantidadPasajeros >0)
					{
						if(!controller_ListPassenger(listaPasajeros))
						{
							printf("Listado exitoso\n");
						}
						else
						{
							printf("Error, al mostrar listado\n");
						}
					}
					else
					{
						printf("Primero deberia dar de alta pasajeros\n");
					}
					break;
				case 7:
					if(cantidadPasajeros >0)
					{
						if(!controller_sortPassenger(listaPasajeros))
						{
							printf("Sort con exito\n");
						}
						else
						{
							printf("Error al ordenar\n");
						}
					}
					else
					{
						printf("Primero deberia dar de alta pasajeros\n");
					}
					break;
				case 8:
					if(cantidadPasajeros >0)
					{
						if(!controller_saveAsText("data.csv",listaPasajeros))
						{
							printf("Se guardo con exito\n");
						}
						else
						{
							printf("Error al guardar el archivo\n");
						}
					}
					else
					{
						printf("No hay datos cargados\n");
					}
					break;
				case 9:
					if(cantidadPasajeros >0)
					{
						if(!controller_saveAsBinary("data.bin",listaPasajeros))
						{
							printf("Guardado exitoso\n");
						}
						else
						{
							printf("Error al guardar\n");
						}
					}
					else
					{
						printf("No hay datos guardados\n");
					}
					break;
				case 10:
					printf("Gracias por utilizar nuestro programa\n");
					option=10;
					break;
			}
    	}
    }while(option != 10);

    ll_deleteLinkedList(listaPasajeros);
    return 0;
}

