/*
 * Utilidades.c
 *
 *  Created on: 2 may. 2021
 *      Author: luciano
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Utilidades.h"

/************************************************************************************************************/
/**************************************************UTILIDADES************************************************/
/************************************************************************************************************/

int menu(void){

	int opcionMenu;
	printf("\n-----OPCIONES-----\n");
	printf("1. Alta producto\n");
	printf("2. Baja producto\n");
	printf("3. Modificacion producto\n");
	printf("4. Listado producto\n");
	printf("5. Listado producto ordenado por precio\n");
	printf("6. Listado producto ordenado por descripcion\n");;
	printf("7. El/los  productos mas caros\n");
	printf("8. Precio promedio por tipo de producto. Se deberá mostrar la descripción del tipo y a continuación el precio promedio.\n");
	printf("9. El listado de todos los productos con la descripción del tipo\n");
	printf("10. Por cada tipo la lista de productos\n");
	printf("11. El/los tipos de productos con mas productos elaborados\n");
	printf("12. La nacionalidad que solo fabrica Iphone\n");
	printf("13. Los productos ordenados por nacionalidad alfabéticamente\n");
	printf("14. La nacionalidad con más tipos de productos fabricados\n");
	printf("15. El precio promedio de productos por nacionalidad\n");
	printf("16. Alta de Tipo de producto\n");
	printf("17. Baja de Tipo de producto\n");
	printf("18. Modificacion de Tipo de producto\n");
	printf("19. Alta de la Nacionalidad\n");
	printf("20. Baja de la Nacionalidad\n");
	printf("21. Modificacion de la Nacionalidad\n");

	printf("22. Salir\n");
	opcionMenu=pedirEnteroConRango("Ingrese una opcion: ", "Error...Ingrese una opcion valida", 1, 22);

	return opcionMenu;
}

void saltoDeLinea(int cantidad){
	int i;
	for(i=0;i<cantidad;i++){
		printf("\n");
	}
}

/************************************************************************************************************/
/***********************************************PEDIR FUNCIONES**********************************************/
/************************************************************************************************************/

int pedirEnteroConRango(char mensaje[], char mensajeError[], int minimo, int maximo){
	int numero;

	printf("%s",mensaje);
	scanf("%d",&numero);
	while((numero < minimo || numero > maximo)){
		printf("\n%s\n\n",mensajeError);
		printf("%s",mensaje);
		scanf("%d",&numero);
	}

	return numero;
}


int pedirEntero(char mensaje[]){

	int numero;

	printf("%s",mensaje);
	scanf("%d",&numero);

	return numero;

}


float pedirFloat(char mensaje[]){

	float numero;

	printf("%s",mensaje);
	scanf("%f",&numero);

	return numero;

}


/************************************************************************************************************/
/************************************************VALIDACIONES************************************************/
/************************************************************************************************************/



