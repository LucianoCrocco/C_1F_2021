/*
 * eTrabajo.c
 *
 *  Created on: 4 may. 2021
 *      Author: luciano
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include "Utilidades.h"
#include "eTrabajo.h"
#include <string.h>

void inicializarIsEmptyTrabajos(eTrabajo lista[], int lenghtArray){
	int i;

	for(i=0;i<lenghtArray;i++){
		lista[i].isEmpty=VACIO;
	}
}


int comprobarEspaciosVaciosEstructuraTrabajo(eTrabajo lista[], int lenghtArray){
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


int comprobarEspaciosOcupadosEstructuraTrabajo(eTrabajo lista[], int lenghtArray){
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

int comprobarIndexOcupadoTrabajo(eTrabajo lista[], int lenghtArray, int numero){
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


eFecha pedirFecha(eTrabajo miTrabajo){

	eFecha miFecha;


	miFecha.dia=pedirEnteroConRango("Ingrese el dia: ", "Error...Ingrese un dia valido", 1, 31);

	miFecha.mes=pedirEnteroConRango("Ingrese el mes: ", "Error...Ingrese un mes valido", 1, 12);

	miFecha.anio= pedirEnteroConRango("Ingrese el anio: ", "Error...Ingrese un anio valido", 1, 2022);

	return miFecha;
}

//PARTE 3:

void bajaListaEstructuraTrabajo(eTrabajo lista[], int lenghtArray){
	int datoAComparar;
	int index;

	datoAComparar = pedirEntero("Ingrese el id del trabjo a dar de baja: ");

	index = comprobarIndexOcupadoTrabajo(lista,lenghtArray,datoAComparar);
	if(index == -1){
		printf("\nError... el ID del trabajo ingresado no es valido\n");
	} else {
		lista[index].isEmpty = VACIO;
		printf("\nProducto borrado\n");
	}

}

//PARTE 4

void mostrarListadoTrabajos(eTrabajo  lista[], int lenghtArray){
	int i;
	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO){
			mostrarUnElementoTrabajos(lista[i]);
		}
	}
}


void mostrarUnElementoTrabajos(eTrabajo unElemento){
	printf("\nID: %d\n", unElemento.id);
	printf("Marca: %s\n", unElemento.marcaBicicleta);
	printf("Rodado: %d\n", unElemento.rodadoBicicleta);
	printf("ID Servicio: %d\n", unElemento.idServicio);
	printf("Fecha: %d/%d/%d\n\n",unElemento.fecha.dia, unElemento.fecha.mes, unElemento.fecha.anio);
}

void ordenarTrabajosPorAnioYMarca(eTrabajo  lista[], int lenghtArray){
	int i;
	int j;

	eTrabajo aux;

	for(i=0;i<lenghtArray-1;i++){
		if(lista[i].isEmpty == OCUPADO){
			for(j=i+1;j<lenghtArray-1;j++){
				if(lista[j].isEmpty==OCUPADO){
					if(lista[i].fecha.anio < lista[j].fecha.anio){
						aux = lista[i];
						lista[i]=lista[j];
						lista[j] = aux;
					} else {
						if(lista[i].fecha.anio == lista[j].fecha.anio && strcmp (lista[i].marcaBicicleta,lista[j].marcaBicicleta) < 0){
							aux = lista[i];
							lista[i]=lista[j];
							lista[j] = aux;
						}
					}
				}
			}
		}
	}
}

