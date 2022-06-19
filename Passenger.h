#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	int estadoVuelo;

}Passenger;

/**
 * Constructor
 * Crea un espacio memoria para un nuevo pasajero
 * @return Null en caso de error o el elemento en caso de exito
 */
Passenger* Passenger_new();
/**
 * Contructor
 * Se setean los parametros recibidos y se reserva un espacio en memoria
 * @param idStr
 * @param nombreStr
 * @param apellidoStr
 * @param precio
 * @param codigoVuelo
 * @param tipoPasajeroStr
 * @param estadoVuelo
 * @return  Null en caso de error o el elemento en caso de exito
 */
Passenger* Passenger_newParametrosTxt(char* idStr,char* nombreStr,char* apellidoStr,char* precio,char* codigoVuelo,char* tipoPasajeroStr,char* estadoVuelo);
/**
 * Contructor
 * Se setean los parametros recibidos y se reserva un espacio en memoria
 * @param idStr
 * @param nombreStr
 * @param apellidoStr
 * @param precio
 * @param tipoPasajeroStr
 * @param codigoVuelo
 * @param estadoVuelo
 * @return Null en caso de error o el elemento en caso de exito
 */
Passenger* Passenger_newParametros(int idStr,char* nombreStr,char* apellidoStr,float precio,int tipoPasajeroStr,char* codigoVuelo,int estadoVuelo);

/**
 * Libera espacio en memoria
 */
void Passenger_delete();

///Setters y Getters

/**
 * Settea el campo Id del elemnto
 * @param this
 * @param id
 * @return -1 en caso de error o 0 en caso de exito
 */
int Passenger_setId(Passenger* this,int id);

/**
 * Obtiene el campo Id del elemento y lo encrementa en 1
 * @param this
 * @param id
 * @return -1 en caso de error o 0 en caso de exito
 */
int Passenger_getId(Passenger* this,int* id);

 /**
  * Setea el campo nombre del elemento y valida que sean letras
  * @param this
  * @param nombre
  * @return -1 en caso de error o 0 en caso de exito
  */
int Passenger_setNombre(Passenger* this,char* nombre);

/**
 * Obtiene el campo nombre del elemento
 * @param this
 * @param nombre
 * @return -1 en caso de error o 0 en caso de exito
 */
int Passenger_getNombre(Passenger* this,char* nombre);

/**
 * Setea el campo apellido del Elemento y valida que sean letras
 * @param this
 * @param apellido
 * @return -1 en caso de error o 0 en caso de exito
 */
int Passenger_setApellido(Passenger* this,char* apellido);

/**
 * Obtiene el campo apellido del elemento
 * @param this
 * @param apellido
 * @return -1 en caso de error o 0 en caso de exito
 */
int Passenger_getApellido(Passenger* this,char* apellido);

/**
 * Setea el campo codigo de vuelo del elemento
 * @param this
 * @param codigoVuelo
 * @return -1 en caso de error o 0 en caso de exito
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/**
 * Obtiene el codigo de vuelo del elemento
 * @param this
 * @param codigoVuelo
 * @return -1 en caso de error o 0 en caso de exito
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/**
 * Setea el campo tipo del elemento
 * @param this
 * @param tipoPasajero
 * @return -1 en caso de error o 0 en caso de exito
 */
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);

/**
 * Obtiene el campo tipo del elemento
 * @param this
 * @param tipoPasajero
 * @return -1 en caso de error o 0 en caso de exito
 */
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

/**
 * Setea el campo precio del elemento
 * @param this
 * @param precio
 * @return -1 en caso de error o 0 en caso de exito
 */
int Passenger_setPrecio(Passenger* this,float precio);

/**
 * Obtiene el campo precio del elemento
 * @param this
 * @param precio
 * @return -1 en caso de error o 0 en caso de exito
 */
int Passenger_getPrecio(Passenger* this,float* precio);

/**
 * Setea el campo estado de vuelo del elemento
 * @param this
 * @param estadoVuelo
 * @return -1 en caso de error o 0 en caso de exito
 */
int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo);
/**
 * Obtiene el campo estado de vuelo del elemento
 * @param this
 * @param estadoVuelo
 * @return -1 en caso de error o 0 en caso de exito
 */
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo);

///Setters Txt
/**
 * Settea el campo Id del elemento tomandolo como cadena de caracteres y lo valida
 * @param this
 * @param id
 * @return -1 en caso de error o 0 en caso de exito
 */
int Passenger_setIdTxt(Passenger* this,char* id);

/**
 * Settea el campo precio del elemento tomandolo como cadena de caracteres y lo valida
 * @param this
 * @param precio
 * @return
 */
int Passenger_setPrecioTxt(Passenger* this,char* precio);

/**
 * Settea el campo estado de vuelo del elemento tomandolo como cadena de caracteres y lo valida
 * @param this
 * @param precio
 * @return -1 en caso de error o 0 en caso de exito
 */
int Passenger_setEstadoVueloTxt(Passenger* this,char* estadoVuelo);

/**
 * Settea el campo tipo del elemento tomandolo como cadena de caracteres y lo valida
 * @param this
 * @param tipoPasajero
 * @return -1 en caso de error o 0 en caso de exito
 */
int Passenger_setTipoPasajeroTxt(Passenger* this,char* tipoPasajero);

///Prints
int Passenger_showOnePassenger(Passenger* pOnePassenger);
int Passenger_showListPassenger(Passenger** arrayPassenger,int len);
/**
 * Muestra un pasajero con todos sus campos llamando al los getters para validar datos
 * @param pOnePassenger
 * @return -1 en caso de error o 0 en caso de exito
 */
int Passenger_printOneWith(Passenger* pOnePassenger);

/**
 * Busca en el array por Id
 * @param arrayPassenger
 * @param idIngresado
 * @return Devuelve el elemento encontrado o NULL en caso de error
 */
Passenger* Passenger_searchPassengerById(LinkedList* arrayPassenger,int idIngresado);

/**
 * Compara los codigos por orden alfabetico entre  los dos elementos y devuelve el resultado
 * @param passenger1
 * @param passenger2
 * @return Devuelve el resultado de la comparacion 1 si el primer elemento es menor q el primero -1 si el segundo es menor
 * o 0 si son iguales
 */
int Passenger_orderByCodigo(void* passenger1,void* passenger2);

/**
 * Compara el precio entre  los dos elementos
 * @param passenger1
 * @param passenger2
 * @return Devuelve el resultado de la comparacion 1 si el primer elemento es menor q el primero -1 si el segundo es menor
 * o 0 si son iguales
 */
int Passenger_orderByPrecio(void* passenger1,void* passenger2);

/**
 * Compara los nombres por orden alfabetico entre  los dos elementos y devuelve el resultado
 * @param passenger1
 * @param passenger2
 * @return Devuelve el resultado de la comparacion 1 si el primer elemento es menor q el primero -1 si el segundo es menor
 * o 0 si son iguales
 */
int Passenger_orderByName(void* passenger1,void* passenger2);

/**
 * Compara el dato ingresado en este caso tipo de pasajero y lo guarda en un auxiliar entero
 * @param tipoPasajero
 * @return retorna el valor del auxiliar
 */
int Passenger_tomaDeDatoTipo(char* tipoPasajero);

/**
 * Compara el dato ingresado en este caso el estado de vuelo y lo guarda en un auxiliar entero
 * @param tipoPasajero
 * @return retorna el valor del auxiliar
 */
int Passenger_tomaDeDatoEstado(char* estadoVuelo);

/**
 * brief Da de alta un pasajero y lo agrega a la lista
 * @param pArrayListPassenger
 * @return -1 en caso de error o 0 en caso exito
 */
int Passenger_addPassenger(LinkedList* pArrayListPassenger);

/**
 * brief Modifica el dato elejido del pasajero
 * @param pArrayListPassenger
 * @return -1 en caso de error o 0 en caso exito
 */
int Passenger_modPassenger(LinkedList* pArrayListPassenger);

/**
 * brief Da de baja un pasajero y lo borra de la lista
 * @param pArrayListPassenger
 * @return -1 en caso de error o 0 en caso exito
 */
int Passenger_removePassenger(LinkedList* pArrayListPassenger);

/**
 * brief Toma el dato del id en la lista y retorna el ultimo
 * @param pArrayPassenger
 * @return el id maximo
 */
int Passenger_idSiguiente(LinkedList* pArrayPassenger);

int Passenger_priceAccumulator(LinkedList* pArrayPassenger,float* precioTotal);

#endif /* PASSENGER_H_ */
