/*
 * main.c
 *
 *  Created on: 31 may. 2021
 *      Author: luciano
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int legajo;
	char nombre[20];
	float nota;
}eAlumno;


int main (void){
	setbuf(stdout,NULL);

	FILE* pArchivo;

	//		Estructuras sin arrays

	eAlumno miAlumno={100,"Luciano",9.5};

	pArchivo = fopen("alumno.dat", "wb");
	fwrite(&miAlumno, sizeof(eAlumno), 1, pArchivo);
	fclose(pArchivo);


	pArchivo = fopen("alumno.dat", "rb");
	fread(&miAlumno, sizeof(eAlumno), 1, pArchivo);
	fclose(pArchivo);

	printf("%d---%s---%.2f\n\n", miAlumno.legajo, miAlumno.nombre, miAlumno.nota);


	//		Estructuras con arrays

	FILE* pArchivoArray;
	eAlumno miAlumnoArray[3]={{100,"Agustin",6.5},{101,"Luciano",9.5},{102,"Leonardo",10}};

	pArchivoArray = fopen("alumnoArray.dat", "wb");
	fwrite(miAlumnoArray, sizeof(eAlumno), 3, pArchivoArray);
	fclose(pArchivoArray);


	pArchivoArray = fopen("alumnoArray.dat", "rb");
	fread(miAlumnoArray, sizeof(eAlumno), 1, pArchivoArray);
	fclose(pArchivoArray);

	for(int i= 0;i<3;i++){
		printf("%d---%s---%.2f\n", miAlumnoArray[i].legajo, miAlumnoArray[i].nombre, miAlumnoArray[i].nota);
	}
	return EXIT_SUCCESS;
}
