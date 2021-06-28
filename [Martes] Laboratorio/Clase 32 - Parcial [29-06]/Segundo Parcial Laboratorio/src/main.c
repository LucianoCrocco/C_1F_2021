#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "bibliotecaGen.h"
#include "nexoEstructuras.h"

int main(void){
	setbuf(stdout,NULL);

	printf("HOLA\n\n\n");

	LinkedList* listaVuelos = ll_newLinkedList();
	controller_loadFromTextVuelos("/home/luciano/HDD/eclipse-workspace/Segundo Parcial Laboratorio/src/Vuelos.csv", listaVuelos);
	LinkedList* listaPilotos = ll_newLinkedList();
	controller_loadFromTextPilotos("/home/luciano/HDD/eclipse-workspace/Segundo Parcial Laboratorio/src/Pilotos.csv", listaPilotos);

	controller_ListVuelos(listaVuelos, listaPilotos);


	return EXIT_SUCCESS;
}
