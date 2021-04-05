/*
 * Luciano Crocco 1ºF
 * Ejercicio 6-3
 *
 *  Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el apellido). Ninguna de las dos variables se puede modificar.
 *  Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
 *  Por ejemplo:
 *  Si el nombre es juan ignacio y el apellido es gOmEz, la salida debería ser:
 *  Gomez, Juan Ignacio
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define TAMANIO_STRING 40
#define TAMANIO_STRING_DOS 80

void strlwr(char string[], int lenght);

int main (void){

	int lenght;
	int i;

	char nombre[TAMANIO_STRING];
	char apellido[TAMANIO_STRING];
	char nombreYApellido[TAMANIO_STRING_DOS];

	setbuf(stdout,NULL);
	strcpy(nombreYApellido,"");



	printf("Ingrese el nombre: ");
	__fpurge(stdin);
	scanf("%[^\n]", nombre);
	lenght= strlen(nombre);
	while(lenght > TAMANIO_STRING){
		printf("Error... Ingreso mas carecteres de los permitidos, el maximo permitido es %d\n", TAMANIO_STRING - 1);
		printf("Ingrese el nombre: ");
		__fpurge(stdin);
		scanf("%[^\n]", nombre);
		lenght= strlen(nombre);
	}

	printf("Ingrese el apellido: ");
	__fpurge(stdin);
	scanf("%[^\n]", apellido);
	lenght= strlen(apellido);
	while(lenght > TAMANIO_STRING){
		printf("Error... Ingreso mas carecteres de los permitidos, el maximo permitido es %d\n", TAMANIO_STRING - 1);
		printf("Ingrese el apellido: ");
		__fpurge(stdin);
		scanf("%[^\n]", apellido);
		lenght= strlen(apellido);
	}

	strcat(nombreYApellido, nombre);
	strcat(nombreYApellido, ", ");
	strcat(nombreYApellido, apellido);

	strlwr(nombreYApellido,TAMANIO_STRING_DOS);

	nombreYApellido[0]=toupper(nombreYApellido[0]);
	for(i=0;i<TAMANIO_STRING_DOS;i++){
		if(nombreYApellido[i] == '\0'){
			break;
		} else {
			if(isspace(nombreYApellido[i])){
				nombreYApellido[i+1]=toupper(nombreYApellido[i+1]);
			}
		}
	}
	printf("Nombre y apellido: %s", nombreYApellido);


	//printf("Nombre y apellido: %s %s", nombre, apellido);

	return EXIT_SUCCESS;
}

void strlwr(char string[], int lenght){
	int i;

	for(i=0;i<lenght;i++){
		if(string[i] == '\0'){
			break;
		} else {
			string[i]=tolower(string[i]);
		}
	}
}
