/*
 * main.c
 *
 *  Created on: 31 may. 2021
 *      Author: luciano
 */

#include <stdio.h>
#include <stdlib.h>

int main (void){

	setbuf(stdout,NULL);

	FILE* pArchivo;
	char nombre[30]="Luciano";
	char apellido[30]="Agustin";
	char lectura[90];

	// Puedo abrir un archivo para escribirlo/leerlo.

	//		CREACION DE ARCHIVOS

	pArchivo = fopen("archivo_texto.txt","w");//w: Si el archivo no existe lo crea, y si el archivo existe lo pisa.
	//(escribir texto: "w" - leer texto: "r" - escribir binario: "wb" - leer binario: "rb").
	//el metodo "a" va a anexar el contenido ya escrito y no lo va a pisar.

	fprintf(pArchivo, "Luciano\n");//Escribo mi archivo.
	//O para pasarle cadenas
	fprintf(pArchivo, "%s\n", apellido);
	//Para combinar cadenas
	fprintf(pArchivo, "%s\n" "%s", nombre, apellido);

	fclose(pArchivo);//Cierro mi archivo.


	//		LECTURA DE ARCHIVOS
	pArchivo = fopen("archivo_texto.txt","r");
	if(pArchivo != NULL){
		//fscanf o fgets para leer
		/*fgets(lectura,90,pArchivo);//El fgets lee una linea, cuando encuentra un \n deja un puntero en esa linea (para que lo continue otro fgets) y se deja de ejecutar.
		puts(lectura);			   //Lo mismo ocurre con las demas funciones y el comportamiento de los punteros
		fgets(lectura,90,pArchivo);
		puts(lectura);
		fclose(pArchivo);*/

		//Para evitar los problemas de los \n anteriormente mencionados, vamos a utilizar feof

		while(!feof(pArchivo)){	//feof: Find end of file
			fgets(lectura,90,pArchivo);
			puts(lectura);
			//Cuidado con los \n, pueden duplicar la ultima salida de texto.
		}
		fclose(pArchivo);
	}

	return EXIT_SUCCESS;
}
