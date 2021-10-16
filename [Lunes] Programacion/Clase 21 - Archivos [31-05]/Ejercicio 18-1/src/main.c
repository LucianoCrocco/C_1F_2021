/*
 * Luciano Crocco 1ºF
 * Ejercicio 18-1
 * Crear una función que reciba como parámetros un array con 5 nombres (que estarán previamente hardcodearlos).
 * La función deberá guardar la lista de nombres en un archivo de texto.
 *
 * int EscribirNombresTXT(char* nombres, char* path);
 * Otra función se encargará de la lectura de dicha lista.
 * int LeerNombresTXT(char* nombres, char* path);
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int EscribirNombresTXT(char* nombres, char* path);
int LeerNombresTXT(char* nombres, char* path);

int main (void){

	setbuf(stdout,NULL);

	//char nombres[5][50]={{"Mick"},{"Nikita"},{"Max"},{"Sebastian"},{"Lance"}};
	char nombres[150]={"Mick, Nikita, Max, Sebastian, Lance"};
	char leerNombres[150];


	EscribirNombresTXT(nombres, "/home/luciano/Escritorio/eclipse-workspace/Ejercicio 18-1/Archivo.txt");
	LeerNombresTXT(leerNombres, "/home/luciano/Escritorio/eclipse-workspace/Ejercicio 18-1/Archivo.txt");

	printf("NOMBRES: %s", leerNombres);

	return EXIT_SUCCESS;
}


int EscribirNombresTXT(char* nombres, char* path){
	FILE* pFile;

	pFile = fopen(path, "w");
	//fwrite(nombres, sizeof(char), 150, pFile);
	fprintf(pFile, "%s",nombres);
	fclose(pFile);

	return 1;
}
int LeerNombresTXT(char* nombres, char* path){

	FILE* pFile;
	pFile = fopen(path, "r");
	fscanf(pFile,"%[^\n]",nombres);
	fclose(pFile);

	return 1;
}

/*
int manejarArchivo (FILE* pArchivo, void (*pFuncion)(char*, char*), char* nombres){
	if(pArchivo != NULL && pFuncion != NULL){
		pArchivo = EscribirNombresTXT(nombres, "/home/luciano/Escritorio/eclipse-workspace/Ejercicio 18-1/Archivo.txt");
	} else {
		return 0;
	}

	return 1;
}
*/
