/*
 * eFabricanteDePantalla.c
 *
 *  Created on: 10 may. 2021
 *      Author: luciano
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Utilidades.h"
#include "eFabricanteDePantalla.h"

/************************************************************************************************************/
/*************************************************HARDCODEOS*************************************************/
/************************************************************************************************************/

void hardocodearDatosUnaStructFabricante(eFabricanteDePantalla lista[]){

	int idFabricante[3]={1,2,3};
	char descripcion[3][STRING_LENGHT]={"Foxconn", "Sharp", "Japan Display Inc"};
	int isEmpty[3]={OCUPADO, OCUPADO, OCUPADO};

	int i;

	for(i=0;i<3;i++){
		lista[i].idFabricante= idFabricante[i];
		strcpy(lista[i].descripcion,descripcion[i]);
		lista[i].isEmpty=isEmpty[i];
	}
}
void inicializarIsEmptyFabricante(eFabricanteDePantalla lista[], int lenghtArray){
	int i;

	for(i=0;i<lenghtArray;i++){
		lista[i].isEmpty=OCUPADO;
	}
}
