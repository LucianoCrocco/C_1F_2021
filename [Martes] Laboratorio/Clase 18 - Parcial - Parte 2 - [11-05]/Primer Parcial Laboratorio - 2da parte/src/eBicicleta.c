/*
 * eBicicleta.c
 *
 *  Created on: 11 may. 2021
 *      Author: luciano
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "Utilidades.h"
#include "eBicicleta.h"
#include <string.h>

void inicializarIsEmptyBicicleta(eBicicleta lista[], int lenghtArray){
	int i;

	for(i=0;i<lenghtArray;i++){
		lista[i].isEmpty=VACIO;
	}
}

void hardcodearStructBicicleta(eBicicleta listaBicicleta[]){
	int i;

	int id[5]={25,26,27,28,29};
	char marca[5][STRING_LENGHT_MARCA_BICI]={"Amazon", "El Diegote", "BMX", "Harley Devinson", "Pro Bici 360"};
	int rodado[5]={9,7,11,7,9};
	char color[5][STRING_LENGHT]={"Amarillo y Azul", "Amarillo", "Rojo", "Verde", "Violeta"};
	int isEmpty[5]={OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

	for(i=0;i<5;i++){
		listaBicicleta[i].id=id[i];
		strcpy(listaBicicleta[i].marca,marca[i]);
		listaBicicleta[i].rodado=rodado[i];
		strcpy(listaBicicleta[i].color,color[i]);
		listaBicicleta[i].isEmpty=isEmpty[i];
	}
}


int comprobarEspaciosVaciosEstructuraBicicleta(eBicicleta lista[], int lenghtArray){
    int i;
    int retorno;

    retorno = -1;

    for(i=0;i<lenghtArray;i++){
        if(lista[i].isEmpty==VACIO){
        	retorno = i;
			break;
        }
    }

    return retorno;
}

int comprobarEspaciosOcupadosEstructuraBicicleta(eBicicleta lista[], int lenghtArray){
    int i;
    int retorno;

    retorno = -1;

    for(i=0;i<lenghtArray;i++){
        if(lista[i].isEmpty==OCUPADO){
        	retorno = 1;
			break;
        }
    }
    return retorno;
}


void mostrarListadoBicicletas(eBicicleta  lista[], int lenghtArray){
	int i;
	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO){
			mostrarUnElementoBicicleta(lista[i]);
		}
	}
}


void mostrarUnElementoBicicleta(eBicicleta unElemento){
	printf("Id: %d\tMarca: %s\tRodado: %d\tColor: %s\n\n", unElemento.id, unElemento.marca, unElemento.rodado, unElemento.color);
}

int comprobarIndexOcupadoBicicleta(eBicicleta lista[], int lenghtArray, int numero){
	int i;
	int retorno;

	retorno = -1;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].id == numero && lista[i].isEmpty == OCUPADO){
			retorno = i;
			break;
		}
	}
	return retorno;
}

