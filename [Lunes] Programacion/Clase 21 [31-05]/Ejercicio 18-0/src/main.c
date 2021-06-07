/*
 * Luciano Crocco 1ºF
 * Ejercicio 18-0
 * Guardar en una variable nombre y apellido. Guardar el dato en un archivo de texto, leerlo y luego mostrarlo.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int get_String(char* pResult, char* msg, char* errorMsg, int retries, int lenght);

int main (void){

	setbuf(stdout,NULL);

	FILE* pFile;
	char nombre[100];
	char apellido[100];
	char nombreCompleto[205];

	get_String(nombre, "Ingrese su nombre: ", "Error... El maximo de caracteres es:", 3, 100);
	get_String(apellido, "Ingrese su apellido: ", "Error... El maximo de caracteres es:", 3, 100);

	strcpy(nombreCompleto, nombre);
	strcat(nombreCompleto, ", ");
	strcat(nombreCompleto, apellido);

	pFile = fopen("Texto.txt", "w");

	fprintf(pFile, "%s" ,nombreCompleto);

	fclose(pFile);

	return EXIT_SUCCESS;
}


int get_String(char* pResult, char* msg, char* errorMsg, int retries, int lenght){
	int rtn;
	char bufferString[lenght*4];

	rtn = 0;

	if(pResult != NULL && msg != NULL && errorMsg != NULL && retries >= 0 && lenght > 0){
		do{
			printf("%s", msg);
			__fpurge(stdin);
			scanf("%[^\n]", bufferString);
			if(strlen(bufferString) > lenght-1){
				printf("%s %d\n", errorMsg, lenght-1);
				printf("Reintentos disponibles: %d\n\n", retries);
				retries--;
			} else {
				strcpy(pResult, bufferString);
				rtn = 1;
				break;
			}

		}while(retries >= 0);
	}
	return rtn;
}
