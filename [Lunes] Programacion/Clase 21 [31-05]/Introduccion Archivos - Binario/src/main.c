/*
 * main.c
 *
 *  Created on: 31 may. 2021
 *      Author: luciano
 */

#include <stdio.h>
#include <stdlib.h>

int main (void){

	setbuf(stdout,NULL);

	FILE* pArchivo;
	int numero = 22;
	int numeroNuevo;
	float flotante = 0.945;
	float flotanteNuevo;

	//		ESCRITURA DE MI ARCHIVO
	pArchivo = fopen("numero.dat", "wb");

	fwrite(&numero, sizeof(int), 1, pArchivo);
	fwrite(&flotante, sizeof(int), 1, pArchivo);

	fclose(pArchivo);


	//		LECTURA DE MI ARCHIVO
	pArchivo = fopen("numero.dat", "rb");

	int x = fread(&numeroNuevo, sizeof(int), 1, pArchivo);
	//Si quiero leer otro tipo de dato que un entero o el que sea, tengo que crear otra instancia de fread distinta.
	fread(&flotanteNuevo, sizeof(float), 1, pArchivo);

	printf("El numero int que leyo: %d --- El numero float que leyo: %.3f ---Cuantos datos de tipo int pudo leer: %d\n\n", numeroNuevo, flotanteNuevo,x);


	//Si tengo un array de elementos puedo cambiar el 1 por la X cantidad de elemtnos que se guardaron.
	int arrayNumeros[5]={5,10,4,2,4};

	fwrite(arrayNumeros, sizeof(int),5,pArchivo);

	for(int i=0;i<5;i++){
		fread(arrayNumeros, sizeof(int), 5, pArchivo);
	}
	for(int i=0;i<5;i++){
		printf("Index %d, numero %d\n", i, arrayNumeros[i]);
	}

	fclose(pArchivo);

	return EXIT_SUCCESS;
}
