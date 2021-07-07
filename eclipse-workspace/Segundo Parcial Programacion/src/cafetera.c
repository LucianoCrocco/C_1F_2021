/*
 * cafetera.c
 *
 *  Created on: 28 jun. 2021
 *      Author: luciano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cafetera.h"

eCafetera* cafetera_new(void){
	eCafetera* newCafetera;

	newCafetera = (eCafetera*) malloc(sizeof(eCafetera));

	return newCafetera;
}

eCafetera* cafetera_newParametros(int id, char* marca, int esMultiCapsula){

	eCafetera* newCafetera;

	newCafetera = cafetera_new();

	if(newCafetera != NULL && id > -1 && marca != NULL && esMultiCapsula > -1 && esMultiCapsula < 2){
		newCafetera->id=id;
		strcpy(newCafetera->marca, marca);
		newCafetera->esMultiCapsula = esMultiCapsula;
	}

	return newCafetera;
}


int cargarYMostrarBinario(char* path, void* pElement){

	int rtn = 0;
    if(pElement != NULL){
    	eCafetera* newCafeteraLectura = pElement;
		FILE* pFileLectura;
		pFileLectura = fopen(path, "rb");

		if(pFileLectura != NULL && newCafeteraLectura != NULL){
			rtn = 1;

			while(!feof(pFileLectura)){
				fread(newCafeteraLectura,sizeof(eCafetera),1,pFileLectura);
				if(feof(pFileLectura)){
					break;
				} else {
					printf("\n\n%d---%s---%d\n\n",newCafeteraLectura->id, newCafeteraLectura->marca, newCafeteraLectura->esMultiCapsula);
				}
			}
			fclose(pFileLectura);
		} else {
			puts("\nError al cargar el archivo");
			free(newCafeteraLectura);
		}
    } else {
    	puts("\nNo hay memoria para asignarle al archivo binarios\n");
    }

    return rtn;

}

int guardarBinario(char* path, void* pElement){
	int rtn = 0;


    if(pElement != NULL && path != NULL){
        eCafetera* newCafetera = pElement;
		FILE* pFile;

		pFile=fopen(path,"wb");

		fwrite(newCafetera, sizeof(eCafetera),1,pFile);

		fclose(pFile);

		rtn = 1;
    }

	return rtn;
}
