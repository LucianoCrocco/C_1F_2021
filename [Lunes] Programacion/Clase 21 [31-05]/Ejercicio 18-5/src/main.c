/*
 * Luciano Crocco 1ºF
 * Ejercicio 18-5:
 * Leer un archivo CSV (generado en mockaroo). Parsearlo y guardarlo en un array del tipo de dato correspondiente.
 * Mostrar los datos por pantalla.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int id;
	char nombre[70];
}eData;
int main (void){

	setbuf(stdout,NULL);

	FILE* pFile;
	eData listaDeData[25];
	eData lectura;

	char id[5];
	char nombre[70];

	int i = 0;

	pFile = fopen("MOCK_DATA.csv", "r");
	fscanf(pFile, "%[^,],%[^\n]", id, nombre);

	while(!feof(pFile)){
		fscanf(pFile, "%[^,],%[^\n]", id, nombre);
		lectura.id=atoi(id);
		strcpy(lectura.nombre, nombre);
		listaDeData[i]=lectura;
		i++;
	}

	fclose(pFile);

	for(i=0;i<25;i++){
		printf("%d-----%s\n",listaDeData[i].id, listaDeData[i].nombre);
	}

	return EXIT_SUCCESS;
}

