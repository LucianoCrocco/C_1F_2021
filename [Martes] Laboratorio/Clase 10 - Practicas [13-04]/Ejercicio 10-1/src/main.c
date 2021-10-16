/*
 * Luciano Crocco 1ºF
 * Ejercicio 10-1
 * Dada la estructura eAlumno (legajo, nombre, nota1, nota2, promedio),
 * de qué manera la podría relacionar con la estructura eCurso (idCurso, descripcion, duracion),
 * teniendo en cuenta que un alumno puede cursar solo un curso
 *
 */

#include <stdio_ext.h>
#include <stdlib.h>

struct eCurso {
	int idCurso; // Primary Key
	char descripcion [50];
	int duracion;
};


struct eAlumno{
	int legajo; //Primary Key
	char nombre[50];
	int nota1;
	int nota2;
	float promedio;
	// Foreign Key - Al crear un dato de tipo eAlumno, le puedo asignar un ID de curso que contenga los datos de ese curso que el alumno cursa.
	int idCurso;
};

int main(void){

	setbuf(stdout,NULL);


	return EXIT_SUCCESS;
}
