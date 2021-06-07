/*
 * Luciano Crocco 1ºF
 * Ejercicio 18-4:
 * Escribir y leer un archivo binario con 5 alumnos (utilizar la estructura del ejercicio 18-2). Mostrar los datos luego de la lectura del archivo.
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

	pFile=fopen("Archivo.dat", "wb");
	eAlumno miAlumnoArray[3]={{100,"Agustin",6.5},{101,"Luciano",9.5},{102,"Leonardo",10}};
	fwrite(miAlumnoArray, sizeof(eAlumno), 3 ,pFile);
	fclose(pFile);



	pFile=fopen("Archivo.dat", "rb");

	eAlumno miAlumno;
	eAlumno miAlumnoArrayLectura[3];

	i=0;

	while(!feof(pFile)){
		fread(&miAlumno, sizeof(eAlumno), 1, pFile);
		miAlumnoArrayLectura[i] = miAlumno;
		i++;
	}

	fclose(pFile);

	for(i=0;i<3;i++){
		printf("%04d---%s---%.2f\n",miAlumnoArrayLectura[i].legajo, miAlumnoArrayLectura[i].nombre, miAlumnoArrayLectura[i].nota);
	}

	return EXIT_SUCCESS;
}

