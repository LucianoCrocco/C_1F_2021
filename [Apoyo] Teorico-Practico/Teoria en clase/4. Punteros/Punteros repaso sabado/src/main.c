/*
 * main.c
 *
 *  Created on: 15 may. 2021
 *      Author: luciano
 */

#include <stdio_ext.h>
#include <stdlib.h>

int recorrerNumeros(int* numeros, int len);
int cargarNumeros (int* pNumeros, int len);

int main(void){

	setbuf(stdout,NULL);
	//Un puntero es un tipo de dato que apunta a una direccion de memoria.
	//&: (Ampersant) Direccion de memoria || *: (Indireccion) El contenido que apunta esa direccion de memoria.

	/* EJEMPLO 1
	int numero = 20;
	int* pNumero = &numero;
	printf("%d\n");*/

	/* EJEMPLO 2
	int numero = 10;
	char numeroChar = '2';

	int* punteroAlNumero = &numero;
	char* punteroChar = &numeroChar;

	printf("%d\n", *punteroAlNumero);
	printf("%c\n", *punteroChar);*/

	/* EJEMPLO 3
	int* pNumero1;
	int* pNumero2;
	int numero = 20;

	pNumero1 = &numero;
	pNumero2 = pNumero1;

	puts("Antes de modificar\n");
	printf("%d\n", *pNumero1);
	printf("%d\n", *pNumero2);

	*pNumero1 = 22;
	// Si cambio el valor en el puntero tambien cambia el contenido de la variable donde apunta.
	puts("Despues de modificar\n");
	printf("%d\n", numero);
	printf("%d\n", *pNumero1);
	printf("%d", *pNumero2);*/


	/*
	char cadena[10] = "Hola";

	//pCAdena = cadena[0];
	//pCadena apunta a la direccion de memoria del primer lugar de arrays de chars.
	char* pCadena;

	pCadena = cadena;

	printf("%c", cadena[3]);
	//Siempre apunta al mismo lugar, pero sumandole X puedo "mirar" a otros contenidos almacenados en ese array
	//Ese +X multiplica X por el sizeof del tipo de dato, permitiendonos mover por el array.*/

	int numeros[10] = {1, 2, 3, 4, 5, 6, 7 , 8, 9, 10};
	int len = 10;
	int resultado;
	//int* pNumero = numeros;
	//Puedo no crear un puntero ya que de por si un array es considerado un puntero

	if(cargarNumeros(numeros, len)){//Al ser un array no hace falta pasarle el &
		resultado = recorrerNumeros(numeros, len);
		printf("%d", resultado);
	}


	return EXIT_SUCCESS;
}

int cargarNumeros (int* pNumeros, int len){
	int i;
	int rtn;

	rtn = 1;

	if(pNumeros != NULL && len >= 0){
		for(i=0;i < len;i++){
			printf("Ingrese un numero: ");
			scanf("%d", pNumeros + i); //Direccion de memoria + (i * sizeof(dato));
		}
	} else {
		rtn = 0;
	}
	return rtn;
}

int recorrerNumeros(int* pNumeros, int len){
	int i;
	int rtn;
	rtn = 1;

	if(pNumeros != NULL && len >= 0){
		for(i=0;i<len;i++){
			printf("%d\n",*(pNumeros+i));
		}
	} else {
		rtn = 0;
	}
	return rtn;
}
