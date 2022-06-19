#ifndef UTN_H_
#define UTN_H_

/***
 * brief Toma una cadena de caracteres y la filtra para validar que sea letra. Con un limite minimo y maximo
 * y una cantidad de intentos
 * @param pStringIngresado
 * @param mensaje
 * @param mensajeError
 * @param limite
 * @param reintentos
 * @return -1 en caso de error o 0 si esta OK
 */
int utn_getString(char pStringIngresado[],char * mensaje,char * mensajeError,int limite,int reintentos);

/***
 * brief Toma una cadena de carateres y la filtra para validar que sean numeros enteros negativos o positivos
 * Con un limite minimo y maximo y una cantidad de intentos
 * @param pNumeroIngresado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param reintentos
 * @return -1 en caso de error o 0 si esta OK
 */
int utn_getInt(int *pNumeroIngresado,
		char * mensaje,char * mensajeError,int minimo,int maximo,int reintentos);
/***
 * brief Toma una cadena de carateres y la filtra para validar que sean numeros decimales negativos o positivos
 * Con un limite minimo y maximo y una cantidad de intentos
 * @param pNumeroIngresado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param reintentos
 * @return -1 en caso de error o 0 si esta OK
 */
int utn_getFloat(float *pNumeroIngresado,
		char * mensaje,char * mensajeError,int minimo,int maximo,int reintentos);
/***
 * brief Analiza una array de carateres y limpia el buffer de entrada y acorta la cadena hasta el primer salto
 * de linea y lo pisa con el catarter de finalizacion de la cadena.
 * @param cadena
 * @param len
 * @return -1 en caso de error o 0 si esta OK
 */
int myGets(char cadena[],int len);
/***
 * brief modifica una cadena de caracteres y la trasforma en numeros enteros y devuelve por puntero dicho numero
 * @param resultado
 * @return -1 en caso de error o 0 si esta OK
 */
int getInt(int * resultado);
/***
 * brief modifica una cadena de caracteres y la trasforma en numeros decimales y devuelve por puntero dicho numero
 * @param resultado
 * @return -1 en caso de error o 0 si esta OK
 */
int getFloat(float * resultado);
/***
 * Anlaiza una cadena de caracters y se fija q sea un numero entero positivo o negativo.
 * @param cadena
 * @param limite
 * @return -1 en caso NULL, 1 en caso de que sea numero 0 si no es un numero.
 */
int esNumero(char cadena[],int limite);
/***
 * Anlaiza una cadena de caracters y se fija q sea un numero decimal positivo o negativo.
 * @param cadena
 * @param limite
 * @return -1 en caso NULL, 1 en caso de que sea numero 0 si no es un numero.
 */
int esFloat(char cadena[],int limite);
/***
 * brief Pasa a minisucla primero la cadena de caraterees y pasa mayuscula la primera pocicion no vacia del array a
 * letra mayuscula tiene en cuenta espacios
 * @param string
 * @return 0 en caso de error o 1 ok
 */
int pasarMayusculaPrimerCaracter(char string[]);
/***
 * brief Analiza un cadena de carateres y valida q sea una letra y tiene en cuenta los esapcios
 * @param cadena
 * @param limite
 * @return -1 en caso NULL, 1 en caso de que sea numero 0 si no es un numero.
 */
int esLetraConEspacio(char cadena[],int limite);
/***
 * brief Toma datos de una cadena valida letras y tiene en cuenta espacios, limite y cantidad de reintentos
 * @param pStringIngresado
 * @param mensaje
 * @param mensajeError
 * @param limite
 * @param reintentos
 * @return  -1 en caso de error o 0 si esta OK
 */
int utn_getNombreCompleto(char pStringIngresado[],char * mensaje,char * mensajeError,int limite,int reintentos);
/***
 * brief valida caracteres en una cadena que sean solo letras mayusculas o minusculas
 * @param cadena
 * @param limite
 * @return  -1 en caso de NULL o 1 si esta OK o 0 en caso de error
 */
int esLetra(char cadena[],int limite);
/***
 * brief valida que se ingresen 3 carateres letra en las primeras posiciones del array y numeros consiguientes
 * @param cadena
 * @param limite
 * @return-1 en caso de NULL o 1 si esta OK o 0 en caso de error
 */
int esCodigoVuelo(char cadena[],int limite);
int esCodigoVueloCorto(char cadena[],int limite);
/***
 * brief Toma y valida q los datos de un codigo vuelo sean validos con un numero limte cadena de carateres y reintendo
 * siempre validando el ingreso de 3 letras primero seguido de numeros
 * @param pFlyCodeIngresado
 * @param mensaje
 * @param mensajeError
 * @param limite
 * @param reintentos
 * @return -1 en caso de error o 0 si esta OK
 */
int utn_getFlyCode(char pFlyCodeIngresado[],char * mensaje,char * mensajeError,int limite,int reintentos);
int utn_getFlyCodeCorto(char pFlyCodeIngresado[],char * mensaje,char * mensajeError,int limite,int reintentos);

#endif /* UTN_H_ */
