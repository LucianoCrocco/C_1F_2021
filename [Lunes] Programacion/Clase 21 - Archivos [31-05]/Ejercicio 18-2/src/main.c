/*
 * Luciano Crocco 1ºF
 * Ejercicio 18-2:
 *
 * Crear la estructura alumno (legajo, nombre, nota), un array de este tipo y hardcodearlo con 3 datos.
 * Escribir en un archivo de texto los datos del array, separando cada campo con una coma y cada alumno con un salto de línea.
 * Mostrar los datos luego de haber leído los datos desde el archivo, en un array de cadenas.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int legajo;
	char nombre[120];
	float nota;
}eAlumno;

int main (void){

	setbuf(stdout,NULL);

	FILE* pFile;
	int i;

	pFile=fopen("Archivo.txt", "w");

	eAlumno miAlumnoArray[3]={{100,"Agustin",6.5},{101,"Luciano",9.5},{102,"Leonardo",10}};

	for(i=0;i<3;i++){
		fprintf(pFile, "%d,%s,%f\n", miAlumnoArray[i].legajo, miAlumnoArray[i].nombre,miAlumnoArray[i].nota);
	}

	fclose(pFile);

	pFile=fopen("Archivo.txt", "r");

	char legajo[120];
	char nombre[120];
	char nota[120];
	eAlumno miAlumno;
	eAlumno miAlumnoArrayLectura[3];

	i=0;


	while(!feof(pFile)){
		fscanf(pFile, "%[^,],%[^,],%[^\n]\n", legajo, nombre, nota);

		miAlumno.legajo = atoi(legajo);
		strcpy(miAlumno.nombre,nombre);
		miAlumno.nota = atof(nota);

		miAlumnoArrayLectura[i] = miAlumno;

		i++;
	}

	fclose(pFile);


	for(i=0;i<3;i++){
		printf("%04d---%s---%.2f\n",miAlumnoArrayLectura[i].legajo, miAlumnoArrayLectura[i].nombre, miAlumnoArrayLectura[i].nota);
	}

	return EXIT_SUCCESS;
}

