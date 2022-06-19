#include <stdio.h>
#include <stdlib.h>

void menuPassenger()
{
	printf("--------- Menu Pasajeros ---------------\n");
	printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n");
	printf("3. Alta de pasajero\n");
	printf("4. Modificar datos de pasajero\n");
	printf("5. Baja de pasajero\n");
	printf("6. Listar pasajeros\n");
	printf("7. Ordenar pasajeros\n");
	printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n");
	printf("10. Salir\n");
}

void menuModificarPasajero()
{
	printf("1-Modificar Nombre\n");
	printf("2-Modificar Apellido\n");
	printf("3-Modificar Precio de vuelo\n");
	printf("4-Clase\n");
	printf("5-Codigo de vuelo\n");
	printf("6-Salir\n");
}


