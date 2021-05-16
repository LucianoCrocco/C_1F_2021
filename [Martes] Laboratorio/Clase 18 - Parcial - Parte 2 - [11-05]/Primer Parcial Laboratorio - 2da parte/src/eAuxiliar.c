/*
 * eAuxiliar.c
 *
 *  Created on: 11 may. 2021
 *      Author: luciano
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include "eAuxiliar.h"
#include "Utilidades.h"

int calcularMaximoServicio(eAuxiliar listaAuxiliar[], int lenghtServicios){

	int i;
	int flag;
	int j;
	int contadorMaximo;

	flag = 0;
	contadorMaximo = 0;

	for(i=0;i<lenghtServicios;i++){
		if(listaAuxiliar[i].isEmpty==OCUPADO && flag == 0){
			j = i;
			contadorMaximo = listaAuxiliar[j].contador;
			flag++;
		} else {
			if(listaAuxiliar[j].contador < listaAuxiliar[i].contador){
				j = i;
				contadorMaximo = listaAuxiliar[j].contador;
			}
		}
	}
	return contadorMaximo;
}
