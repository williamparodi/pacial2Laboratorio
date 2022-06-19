#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int itsOk = -1;
	char aux[7] [1000];
	int cantidad;
	Passenger* auxPassenger = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n,",aux[0],aux[1],aux[2],aux[3],aux[4],aux[5],aux[6]);
		do
		{
			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n,",aux[0],aux[1],aux[2],aux[3],aux[4],aux[5],aux[6]);
			if(cantidad <7)
			{
				break;
			}

			auxPassenger = Passenger_newParametrosTxt(aux[0],aux[1],aux[2],aux[3],aux[4],aux[5],aux[6]);
			if(auxPassenger != NULL)
			{
				ll_add(pArrayListPassenger,auxPassenger);
				itsOk = 0;
			}
		}while(!feof(pFile));
	}
    return itsOk;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int itsOk = -1;
	int cantidad;
	int auxId;
	char auxNombre[1000];
	char auxApellido[1000];
	float auxPrecio;
	char auxCodigo[1000];
	int auxTipo;
	int auxEstado;
	Passenger* auxPassenger = NULL;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		do
		{
			auxPassenger = Passenger_new();
			cantidad = fread(auxPassenger,sizeof(Passenger),1,pFile);

			if(auxPassenger != NULL && cantidad == 1)
			{
				if(!Passenger_getId(auxPassenger,&auxId) &&
				   !Passenger_getNombre(auxPassenger,auxNombre)&&
				   !Passenger_getApellido(auxPassenger,auxApellido)&&
				   !Passenger_getPrecio(auxPassenger,&auxPrecio)&&
				   !Passenger_getCodigoVuelo(auxPassenger, auxCodigo)&&
				   !Passenger_getTipoPasajero(auxPassenger,&auxTipo) &&
				   !Passenger_getEstadoVuelo(auxPassenger,&auxEstado))
				{
					ll_add(pArrayListPassenger,auxPassenger);
					itsOk = 0;
				}
			}
		}while(!feof(pFile));
	}
    return itsOk;
}

int parser_PassengerFromText2(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int itsOk = -1;
	char auxId[100];
	char auxNombre[100];
	char auxApellido[100];
	char auxPrecio[100];
	char auxCodigo[100];
	char auxTipo[100];
	char auxEstado[100];
	int cantidad;

	Passenger* auxPassenger = NULL;

	if(pFile != NULL)
	{
		cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n,",auxId,auxNombre,auxApellido,
				auxPrecio, auxTipo, auxCodigo, auxEstado);
		do
		{
			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n,",auxId, auxNombre,
					auxApellido, auxPrecio, auxTipo, auxCodigo, auxEstado);
			if(cantidad <7)
			{
				break;
			}

			auxPassenger = Passenger_newParametrosTxt(auxId, auxNombre, auxApellido, auxPrecio, auxTipo, auxCodigo, auxEstado);
			if(auxPassenger != NULL)
			{
				ll_add(pArrayListPassenger,auxPassenger);
				itsOk = 0;
			}
		}while(!feof(pFile));
	}
    return itsOk;
}
