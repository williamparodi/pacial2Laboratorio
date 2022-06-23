#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "menu.h"
#include "utn.h"
#define LIMITE_NOMBRE 100
#define LIMITE_CODIGO 10
#define LIMITE_ID 10
#define BUFFER 1000
#define PRIMERA  1
#define EJECUTIVO 2
#define TURISTA 3
#define ACTIVO 1
#define CANCELADO 2
#define DEMORADO 3

int static incrementaId()
{
	static int id = 1000;
	id++;
	return id;
}

Passenger* Passenger_new()
{
	Passenger * newPassenger;
	newPassenger = (Passenger*) malloc(sizeof(Passenger));
	if(newPassenger != NULL)
	{
		return newPassenger;
	}
	else
	{
		return NULL;
	}

}

Passenger* Passenger_newParametrosTxt(char* idStr,char* nombreStr,char* apellidoStr,char* precio,char* codigoVuelo,char* tipoPasajeroStr,char* estadoVuelo)
{
	Passenger * newPassengerParam = NULL;
	newPassengerParam = Passenger_new();
	if(newPassengerParam != NULL)
	{
		Passenger_setIdTxt(newPassengerParam, idStr);
		Passenger_setNombre(newPassengerParam,nombreStr);
		Passenger_setApellido(newPassengerParam,apellidoStr),
		Passenger_setPrecioTxt(newPassengerParam,precio);
		Passenger_setTipoPasajeroTxt(newPassengerParam,tipoPasajeroStr);
		Passenger_setCodigoVuelo(newPassengerParam,codigoVuelo);
		Passenger_setEstadoVueloTxt(newPassengerParam,estadoVuelo);
	}
	return newPassengerParam;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int itsOk = -1;
	if(this!= NULL && id >0)
	{
		this->id= id;
		itsOk = 0;
	}
	return itsOk;
}

int Passenger_getId(Passenger* this,int* id)
{
	int itsOk = -1;
	if(this != NULL && id != NULL && id >0)
	{
		*id = this->id;
		itsOk = 0;
	}
	return itsOk;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int itsOk = -1;
	if(this != NULL && nombre != NULL && esLetra(nombre,LIMITE_NOMBRE))
	{
		strcpy(this->nombre,nombre);
		itsOk=0;
	}
	return itsOk;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int itsOk = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		itsOk = 0;
	}
	return itsOk;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int itsOk = -1;
	if(this != NULL && apellido != NULL && esLetra(apellido,LIMITE_NOMBRE))
	{
		strcpy(this->apellido,apellido);
		itsOk=0;
	}
	return itsOk;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int itsOk = -1;
	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		itsOk=0;
	}
	return itsOk;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int itsOk = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		itsOk=0;
	}
	return itsOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int itsOk = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		itsOk=0;
	}
	return itsOk;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int itsOk = -1;
	if(this != NULL)
	{
		this->tipoPasajero = tipoPasajero;
		itsOk=0;
	}
	return itsOk;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int itsOk = -1;
	if(this != NULL && tipoPasajero != NULL && tipoPasajero >0)
	{
		*tipoPasajero = this->tipoPasajero;
		itsOk=0;
	}
	return itsOk;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int itsOk = -1;
	if(this != NULL)
	{
		this->precio = precio;
		itsOk=0;
	}
	return itsOk;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int itsOk = -1;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		itsOk=0;
	}
	return itsOk;
}

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo)
{
	int itsOk = -1;
	if(this != NULL)
	{
		this->estadoVuelo = estadoVuelo;
		itsOk=0;
	}
	return itsOk;
}

int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo)
{
	int itsOk = -1;
	if(this != NULL && estadoVuelo != NULL)
	{
		*estadoVuelo = this->estadoVuelo;
		itsOk=0;
	}
	return itsOk;
}

//Setter Txt

int Passenger_setIdTxt(Passenger* this,char* id)
{
	int itsOk = -1;
	if(this != NULL && id != NULL && esNumero(id,2000))
	{
		this->id= atoi(id);
		itsOk=0;
	}
	return itsOk;
}

int Passenger_setPrecioTxt(Passenger* this,char* precio)
{
	int itsOk = -1;
	if(this != NULL && precio != NULL && esFloat(precio,2000))
	{
		this->precio= atof(precio);
		itsOk=0;
	}
	return itsOk;
}

int Passenger_setTipoPasajeroTxt(Passenger* this,char* tipoPasajero)
{
	int itsOk = -1;
	int auxTipo;
	if(this != NULL && tipoPasajero != NULL)
	{
		auxTipo = Passenger_tomaDeDatoTipo(tipoPasajero);
		this->tipoPasajero= auxTipo;
		itsOk=0;
	}
	return itsOk;
}

int Passenger_setEstadoVueloTxt(Passenger* this,char* estadoVuelo)
{
	int itsOk = -1;
	int auxEstado;
	if(this != NULL && estadoVuelo != NULL)
	{
		auxEstado = Passenger_tomaDeDatoEstado(estadoVuelo);
		this->estadoVuelo = auxEstado;
		itsOk=0;
	}
	return itsOk;
}

int Passenger_showOnePassenger(Passenger* pOnePassenger)
{
	int itsOk = -1;
	int auxId;
	char auxNombre[BUFFER];
	char auxApellido[BUFFER];
	float auxPrecio;
	int auxTipoDePasajero;
	char auxCodigoDeVuelo[BUFFER];
	int auxEstadoVuelo;

	if(pOnePassenger != NULL &&
			!Passenger_getId(pOnePassenger,&auxId) &&
			!Passenger_getNombre(pOnePassenger,auxNombre) &&
			!Passenger_getApellido(pOnePassenger,auxApellido) &&
			!Passenger_getPrecio(pOnePassenger,&auxPrecio) &&
			!Passenger_getTipoPasajero(pOnePassenger,&auxTipoDePasajero) &&
			!Passenger_getCodigoVuelo(pOnePassenger,auxCodigoDeVuelo) &&
			!Passenger_getEstadoVuelo(pOnePassenger,&auxEstadoVuelo))
	{
		printf("%d,%s,%s,%.2f,%s,%d,%d\n",
						auxId,auxNombre,auxApellido,auxPrecio,auxCodigoDeVuelo,auxTipoDePasajero,auxEstadoVuelo);

		itsOk = 0;
	}
	return itsOk;
}

int Passenger_printOneWith(Passenger* pOnePassenger)
{
	int itsOk = -1;
	int auxId;
	char auxNombre[BUFFER];
	char auxApellido[BUFFER];
	float auxPrecio;
	int tipoDePasajero;
	char auxCodigoDeVuelo[BUFFER];
	int estadoVuelo;
	char auxTipoDePasajero[BUFFER];
	char auxEstadoVuelo[BUFFER];

	if(pOnePassenger != NULL &&
			!Passenger_getId(pOnePassenger,&auxId) &&
			!Passenger_getNombre(pOnePassenger,auxNombre) &&
			!Passenger_getApellido(pOnePassenger,auxApellido) &&
			!Passenger_getPrecio(pOnePassenger,&auxPrecio) &&
			!Passenger_getTipoPasajero(pOnePassenger,&tipoDePasajero) &&
			!Passenger_getCodigoVuelo(pOnePassenger,auxCodigoDeVuelo) &&
			!Passenger_getEstadoVuelo(pOnePassenger,&estadoVuelo))
	{
		switch(tipoDePasajero)
		{
		case PRIMERA:
			strcpy(auxTipoDePasajero,"PRIMERA");
			break;
		case EJECUTIVO:
			strcpy(auxTipoDePasajero,"EJECUTIVO");
			break;
		case TURISTA:
			strcpy(auxTipoDePasajero,"TURISTA");
			break;
		}
		switch(estadoVuelo)
		{
		case ACTIVO:
			strcpy(auxEstadoVuelo,"ACTIVO");
			break;
		case DEMORADO:
			strcpy(auxEstadoVuelo,"DEMORADO");
			break;
		case CANCELADO:
			strcpy(auxEstadoVuelo,"CANCELADO");
			break;
		}
		printf("%d %-15s  %-10s    %-5.f    %-15s    %-15s    %-8s\n",
				auxId,auxNombre,auxApellido,
				auxPrecio,
				auxCodigoDeVuelo,
				auxTipoDePasajero,
				auxEstadoVuelo);
		itsOk=0;
	}
	return itsOk;
}

int Passenger_showListPassenger(Passenger** arrayPassenger,int len)
{
	int itsOk = -1;
	if(arrayPassenger != NULL && len >0)
	{
		for(int i=0;i < len;i++)
		{
			Passenger_showOnePassenger(*(arrayPassenger + i));
		}
		itsOk = 0;
	}
	return itsOk;
}


Passenger* Passenger_newParametros(int id,char* nombre,char* apellido,float precio,int tipoPasajero,char* codigoVuelo,int estadoVuelo)
{
	Passenger * newPassengerParam=NULL;
	newPassengerParam = Passenger_new();
	if(newPassengerParam != NULL)
	{
		Passenger_setId(newPassengerParam,id);
		Passenger_setNombre(newPassengerParam,nombre);
		Passenger_setApellido(newPassengerParam,apellido);
		Passenger_setPrecio(newPassengerParam,precio);
		Passenger_setTipoPasajero(newPassengerParam,tipoPasajero);
		Passenger_setCodigoVuelo(newPassengerParam,codigoVuelo);
		Passenger_setEstadoVuelo(newPassengerParam,estadoVuelo);
	}
	return newPassengerParam;
}



Passenger* Passenger_searchPassengerById(LinkedList* arrayPassenger,int idIngresado)
{
	Passenger* auxPassenger=NULL;
	Passenger* retorno;
	int auxId;
	int len;
	if(arrayPassenger != NULL && idIngresado >0)
	{
		len= ll_len(arrayPassenger);
		for(int i=0;i<len;i++)
		{
			auxPassenger= ll_get(arrayPassenger,i);
			Passenger_getId(auxPassenger,&auxId);
			if(idIngresado == auxId && auxPassenger != NULL)
			{
				retorno = auxPassenger;
				break;
			}
		}
	}
	return retorno;
}

int Passenger_orderByName(void* passenger1,void* passenger2)
{
	int retorno;
	char auxNombre1[BUFFER];
	char auxNombre2[BUFFER];

	if(passenger1 != NULL && passenger2 != NULL)
	{
		Passenger_getNombre(passenger1,auxNombre1);
		Passenger_getNombre(passenger2,auxNombre2);
        retorno = stricmp(auxNombre1,auxNombre2);
	}
	return retorno;
}

int Passenger_orderByPrecio(void* passenger1,void* passenger2)
{
	int retorno = 0;
	float auxPrecio1;
	float auxPrecio2;
	if(passenger1 != NULL && passenger2 != NULL)
	{
		Passenger_getPrecio(passenger1,&auxPrecio1);
		Passenger_getPrecio(passenger2,&auxPrecio2);

		if(auxPrecio1 > auxPrecio2)
		{
			retorno = 1;
		}
		else if(auxPrecio1 < auxPrecio2)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int Passenger_orderByCodigo(void* passenger1,void* passenger2)
{
	int retorno;
	char auxCodigo1[BUFFER];
	char auxCodigo2[BUFFER];

	if(passenger1 != NULL && passenger2 != NULL)
	{
		Passenger_getCodigoVuelo(passenger1,auxCodigo1);
		Passenger_getCodigoVuelo(passenger2,auxCodigo2);
        retorno = stricmp(auxCodigo1,auxCodigo2);
	}
	return retorno;
}

int Passenger_tomaDeDatoTipo(char* tipoPasajero)
{
	int auxTipo;
	if(tipoPasajero != NULL)
	{
		if(!strcmp(tipoPasajero,"PRIMERA"))
		{
			auxTipo = 1;
		}
		else if(!strcmp(tipoPasajero,"EJECUTIVO"))
		{
			auxTipo = 2;
		}
		else if(!strcmp(tipoPasajero,"TURISTA"))
		{
			auxTipo = 3;
		}
	}
	return auxTipo;
}

int Passenger_tomaDeDatoEstado(char* estadoVuelo)
{
	int auxEstado;
	if(estadoVuelo != NULL)
	{
		if(!strcmp(estadoVuelo,"ACTIVO"))
		{
			auxEstado = 1;
		}
		else if(!strcmp(estadoVuelo,"CANCELADO"))
		{
			auxEstado = 2;
		}
		else if(!strcmp(estadoVuelo,"DEMORADO"))
		{
			auxEstado = 3;
		}
	}
	return auxEstado;
}


int Passenger_addPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* newPassenger=NULL;
	int itsOk = -1;
	int auxid;
	char auxNombre[BUFFER];
	char auxApellido[BUFFER];
	float auxPrecio;
	char auxCodigo[BUFFER];
	int auxTipo;
	int auxEstado;

	if(pArrayListPassenger != NULL)
	{
		if(!utn_getNombreCompleto(auxNombre,"Ingrese nombre del pasajero:\n","Error,solo letras\n",LIMITE_NOMBRE,5)&&
		   !utn_getNombreCompleto(auxApellido,"Ingrese apellido del pasajero:\n","Error,solo letras\n",LIMITE_NOMBRE,5)&&
		   !utn_getFloat(&auxPrecio,"Ingrese Precio de Vuelo:\n","Error, solo precios mayores a 1000 y menores a 10 millon\n",1000,10000000,5)&&
		   !utn_getFlyCode(auxCodigo,"Ingrese el codigo de vuelo:\n",
						"Error,el codigo tiene 3 letras iniciales y hasta 4 numeros(Ejemplo ARD0013)\n",LIMITE_CODIGO,5) &&
		   !utn_getInt(&auxTipo,
						"Ingrese la clase:\n "
						"1-Primera clase\n "
						"2-Ejecutivo\n "
						"3-Turista\n",
						"Error,clase incorrecta",1,3,5) &&
		   !utn_getInt(&auxEstado,
						"Ingrese estado de vuelo:\n "
						"1-ACTIVO\n "
						"2-DEMORADO\n "
						"3-CANCELADO\n","Error,estado erroneo\n",1,3,5))
		{
			auxid = Passenger_idSiguiente(pArrayListPassenger);
			auxid = incrementaId();
			newPassenger = Passenger_newParametros(auxid, auxNombre, auxApellido, auxPrecio, auxTipo, auxCodigo,auxEstado);
		}
		if(newPassenger != NULL)
		{
			ll_add(pArrayListPassenger,newPassenger);
			itsOk=0;
		}
	}
	return itsOk;
}

int Passenger_modPassenger(LinkedList* pArrayListPassenger)
{
	int itsOk = -1;
	int opcion;
	int id;
	char auxNombre[BUFFER];
	char auxApellido[BUFFER];
	float auxPrecio;
	char auxCodigoVuelo[BUFFER];
	int auxTipoPasajero;
	Passenger* auxPassenger;

	if(pArrayListPassenger != NULL)
	{
		printf("--------Modificar Pasajero ----------\n");
		printf("Id  Nombre  Apellido  Precio   Codigo de vuelo  Clase\n");
		controller_ListPassenger(pArrayListPassenger);
		if(!utn_getInt(&id,"\nIngrese el id del pasajero a Modificar:\n","Error,id incorrecto\n",1,5000,5))
		{
			auxPassenger = Passenger_searchPassengerById(pArrayListPassenger,id);
			if(auxPassenger != NULL)
			{
				itsOk=0;
				Passenger_printOneWith(auxPassenger);
				do
				{
					menuModificarPasajero();
					if(!utn_getInt(&opcion,"Que campo desea modificar?\n",
							"Error,opcion incorrecta\n",1,6,5))
					{
						switch(opcion)
						{
						case 1:
							if(!utn_getNombreCompleto(auxNombre,"Ingrese el nombre nuevo:\n","Error,solo letras\n",50,5))
							{
								Passenger_setNombre(auxPassenger,auxNombre);
								printf("Nombre modificado\n");
							}
							else
							{
								printf("Error al modificar nombre\n");
							}
							break;
						case 2:
							if(!utn_getNombreCompleto(auxApellido,"Ingrese el apellido nuevo:\n","Error,solo letras\n",50,5))
							{
								Passenger_setApellido(auxPassenger,auxApellido);
								printf("Apellido modificado\n");
							}
							else
							{
								printf("Error al modificar\n");
							}
							break;
						case 3:
							if(!utn_getFloat(&auxPrecio,"Ingrese el nuevo precio:\n",
									"Error,precios mayores a 1000 y menores a 10 millones",1000,10000000,5))
							{
								Passenger_setPrecio(auxPassenger,auxPrecio);
								printf("Precio modificado\n");
							}
							else
							{
								printf("Error al  modificar\n");
							}
							break;
						case 4:
							if(!utn_getInt(&auxTipoPasajero,
									"Ingrese la nueva clase:\n "
									"1-Primera clase\n "
									"2-Ejecutivo\n "
									"3-Turista\n",
									"Error,clase incorrecta",1,3,5))
							{
								Passenger_setTipoPasajero(auxPassenger,auxTipoPasajero);
								printf("Clase modificada\n");
							}
							else
							{
								printf("Error al modificar\n");
							}
							break;
						case 5:
							if(!utn_getFlyCode(auxCodigoVuelo,"Ingrese el nuevo codigo de vuelo:\n",
									"Error,el codigo tiene 3 letras iniciales y hasta 4 numeros(Ejemplo ARD0013)\n",LIMITE_CODIGO,5))
							{
								Passenger_setCodigoVuelo(auxPassenger, auxCodigoVuelo);
								printf("Codigo de Vuelo modificado\n");
							}
							else
							{
								printf("Error al modificar\n");
							}
							break;

						case 6:
							printf("Se vuelve al menu principal\n");
							break;
						}
					}

				}while(opcion != 6);
			}
			else
			{
				printf("Id incorrecto\n");
			}
		}
	}
	return itsOk;
}

int Passenger_removePassenger(LinkedList* pArrayListPassenger)
{
	int itsOk = -1;
	int index;
	int opcion;
	int id;
	Passenger* auxPassenger = NULL;

	if(pArrayListPassenger != NULL)
	{
		printf("-----------------------------Baja--de--Pasajero----------------------------------------------------\n");
		printf("Id   Nombre   	      Apellido       Precio     Codigo de Vuelo    Clase         Estado de vuelo   \n");
		printf("---------------------------------------------------------------------------------------------------\n");
		controller_ListPassenger(pArrayListPassenger);
		if(!utn_getInt(&id,"\nIngrese el id del pasajero a borrar:\n","Error,id incorrecto\n",1,5000,5))
		{
			auxPassenger = Passenger_searchPassengerById(pArrayListPassenger,id);
			if(auxPassenger!= NULL)
			{
				printf("Pasajero a Borrar: \n");
				Passenger_printOneWith(auxPassenger);
				if(!utn_getInt(&opcion,"Esta seguro que quiere borrar este Pasajero? 1-Si o 2-No\n",
						"Error,opcion incorrecta\n",1,2,5))
				{
					if(opcion ==1)
					{
						index = ll_indexOf(pArrayListPassenger,auxPassenger);
						ll_pop(pArrayListPassenger,index);// o puedo usar remove
						Passenger_delete(auxPassenger);
						printf("Pasajero borrado\n");
						itsOk=0;
					}
					else
					{
						printf("Baja cancelada\n");
						itsOk=1;
					}
				}
			}
		}
	}
	return itsOk;
}

int Passenger_idSiguiente(LinkedList* pArrayPassenger)
{
	Passenger* auxPassenger = NULL;
	int id;
	int len;
	int maximo;

	if(pArrayPassenger != NULL)
	{
		len = ll_len(pArrayPassenger);
		for(int i = 0; i < len ; i++)
		{
			auxPassenger = ll_get(pArrayPassenger,i);
			Passenger_getId(auxPassenger, &id);
			if(id > maximo || i == 0)
			{
				maximo = id;
			}
		}
	}
	return maximo;
}


int Passenger_tipoTurista(void* passenger)
{
	int retorno = -1;
	int auxTipo;

	if(passenger != NULL)
	{
		Passenger_getTipoPasajero(passenger,&auxTipo);
		if(auxTipo == 3)
		{
			retorno = 0;
		}
	}
	return retorno;
}

int Passenger_tipoPrimera(void* passenger)
{
	int retorno = -1;
	int auxTipo;

	if(passenger != NULL)
	{
		Passenger_getTipoPasajero(passenger,&auxTipo);
		if(auxTipo == 1)
		{
			retorno = 0;
		}
	}
	return retorno;
}

int Passenger_tipoEjecutivo(void* passenger)
{
	int retorno = -1;
	int auxTipo;

	if(passenger != NULL)
	{
		Passenger_getTipoPasajero(passenger,&auxTipo);
		if(auxTipo == 2)
		{
			retorno = 0;
		}
	}
	return retorno;
}
