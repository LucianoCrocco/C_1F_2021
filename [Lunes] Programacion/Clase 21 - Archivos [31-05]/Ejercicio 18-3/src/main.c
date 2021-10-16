/*
 * Luciano Crocco 1ºF
 * Ejercicio 18-3:
 * Escribir y leer un archivo binario con 5 números enteros. Mostrar los datos luego de la lectura del archivo
 *
 */
#include <stdio.h>
#include <stdlib.h>
int main (void){

	setbuf(stdout,NULL);

	FILE* pFile;
	int i;
	int numeros[5]={132,122,344,1553,10000};
	int arrayLecturaEnteros[5];

	pFile=fopen("Archivo.dat", "wb");
	fwrite(numeros, sizeof(int), 5, pFile);
	fclose(pFile);

	pFile=fopen("Archivo.dat", "rb");
	int numero;

	while(!feof(pFile)){
		fread(&numero, sizeof(int), 1, pFile);
		arrayLecturaEnteros[i] = numero;
		i++;
	}
	fclose(pFile);

	for(i=0;i<5;i++){
		printf("Index: %d---Numeros: %d\n", i, arrayLecturaEnteros[i]);
	}


	return EXIT_SUCCESS;
}

