/*
 * main.c
 *
 *  Created on: 31 may. 2021
 *      Author: luciano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int legajo;
	char nombre[20];
	float nota;
}eAlumno;

int main (void){
	setbuf(stdout,NULL);

	FILE* pArchivo;
	char cadena[1000];
	char legajo[50];
	char nombre[50];
	char nota[50];
	int i = 0;

	eAlumno lectura;
	eAlumno miAlumnoArray[3]={{100,"Agustin",6.5},{101,"Luciano",9.5},{102,"Leonardo",10}};
	eAlumno miAlumno={100,"Luciano",9.5};

	//			SIN ARRAYS
	pArchivo = fopen("alumno.csv", "w");
	fprintf(pArchivo, "%d,%s,%f\n", miAlumno.legajo, miAlumno.nombre,miAlumno.nota);
	fclose(pArchivo);

	pArchivo = fopen("alumno.csv", "r");
	fgets(cadena,1000,pArchivo);
	fclose(pArchivo);

	puts(cadena);

	pArchivo = fopen("alumno.csv", "r");
	fscanf(pArchivo, "%[^,],%[^,],%[^,]\n", legajo, nombre, nota);
	printf("%s-%s-%s\n", legajo, nombre, nota);//Se lo paso a un Constructor

	//Una vez que lei esos datos con el fscanf, tengo que lograr pasarlo a una estructura.
	//Aca estoy construyendo una estructura a partir de los datos que obtengo de un archivo

	lectura.legajo = atoi(legajo);
	strcpy(lectura.nombre,nombre);
	lectura.nota = atof(nota);

	fclose (pArchivo);

	printf("\nConstruido: %d-%s-%f\n\n", lectura.legajo, lectura.nombre, lectura.nota);

	//			CON ARRAYS
	pArchivo = fopen("alumnoArray.csv", "w");

	for(i=0;i<3;i++){
		fprintf(pArchivo, "%d,%s,%f\n", miAlumnoArray[i].legajo, miAlumnoArray[i].nombre,miAlumnoArray[i].nota);
	}

	fclose(pArchivo);

	pArchivo = fopen("alumnoArray.csv", "r");
	while(!feof(pArchivo)){
		fscanf(pArchivo, "%[^,],%[^,],%[^\n]\n", legajo, nombre, nota);

		lectura.legajo = atoi(legajo);
		strcpy(lectura.nombre,nombre);
		lectura.nota = atof(nota);

		miAlumnoArray[i]= lectura;

		i++;
	}

	fclose(pArchivo);

	//CON MOCKAROO

	//fscanf(pArchivo, "%[^,],%[^,],%[^,]\n", legajo, nombre, nota);
	//Si pongo el scanf de arriba asi, no me va a leer la cabecara, es una falsa lectura para dejar el puntero debajo

	eAlumno arrayMockaroo[1000];
	pArchivo = fopen("MOCK_DATA.csv", "r");

	fscanf(pArchivo, "%[^,],%[^,],%[^\n]\n", legajo, nombre, nota);
	i = 0;
	while(!feof(pArchivo)){
		fscanf(pArchivo, "%[^,],%[^,],%[^\n]\n", legajo, nombre, nota);

		lectura.legajo = atoi(legajo);
		strcpy(lectura.nombre,nombre);
		lectura.nota = atof(nota);

		arrayMockaroo[i]=lectura;

		i++;
	}

	fclose(pArchivo);

	for(i=0;i<100;i++){
		printf("%d---%s---%f\n",arrayMockaroo[i].legajo, arrayMockaroo[i].nombre, arrayMockaroo[i].nota);
	}
	return EXIT_SUCCESS;
}
