#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "Piloto.h"
#include "Vuelos.h"
#include "nexoEstructuras.h"
#include "LinkedList.h"


/**
 * \brief Lista un vuelo conlos datos del piloto
 * \param vuelo
 * \param piloto
 * \param primeraIteracion
 */
void flight_ListOneFlightWithPilot(eVuelos* vuelo, ePiloto* piloto, int primeraIteracion){

	if(vuelo != NULL && piloto != NULL){
		int idVuelo;
		int idAvion;
		int idPiloto;
		int dia;
		int mes;
		int anio;
		char destino[STRING_LENGHT_NEXO];
		int cantPasajeros;
		int horaDespegue;
		int horaLlegada;

		char nombre[STRING_LENGHT_NEXO];
		char apellido[STRING_LENGHT_NEXO];


		vuelos_getAllAtributes(vuelo, &idVuelo, &idAvion, &idPiloto, &dia, &mes, &anio, destino, &cantPasajeros, &horaDespegue, &horaLlegada);
		piloto_getNombre(piloto, nombre);
		piloto_getApellido(piloto, apellido);

		if(primeraIteracion == 0){
			printf("\n[ID VUELO]\t[ID AVION]\t  [FECHA]\t[DESTINO]\t    [DATOS PILOTO]\t [HORA DESPEGUE] [HORA LLEGADA]\t[CANTIDAD DE PASAJEROS]\n\n");
			printf("    %02d\t\t    %02d\t\t %d/%d/%d %13s \tID:%2d  %s %s\t       %02d\t       %02d\t\t %03d\n", idVuelo, idAvion, dia, mes, anio, destino, idPiloto, nombre, apellido,horaDespegue, horaLlegada, cantPasajeros);
		} else {
			printf("    %02d\t\t    %02d\t\t %d/%d/%d %13s \tID:%2d  %s %s\t       %02d\t       %02d\t\t %03d\n", idVuelo, idAvion, dia, mes, anio, destino, idPiloto, nombre, apellido,horaDespegue, horaLlegada, cantPasajeros);
		}
	}
}


/**
 * \brief Encuentra un ID en la linkedlist y retorna su indice
 * \param pArrayListEmployee
 * \param id
 * \return index
 */
int piloto_findIndexPilotoByFlightID(LinkedList* pArrayListPilotos, int idVuelo_Piloto){
	int rtn = -1;

	if(pArrayListPilotos != NULL && idVuelo_Piloto > -1){
		int i;
		int len = ll_len(pArrayListPilotos);
		ePiloto* findPiloto = NULL;

		for(i=0;i<len;i++){
			findPiloto = ll_get (pArrayListPilotos,i);
			if(findPiloto->id == idVuelo_Piloto){
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

/**
 * \brief Cuenta la cantidad de pasajeros segun el criterio elegido en las opciones.
 * \param pArrayListVuelos
 * \param opcion
 * \return
 */
int contadorDePasajeros (LinkedList* pArrayListVuelos, int opcion){
	int rtn = 0;
	if(pArrayListVuelos != NULL && opcion > -1){
		rtn = 1;
		int cantidadPasajeros;
		int cantidadPasajerosAChina;
		switch(opcion){
			case 1:
				cantidadPasajeros = ll_count(pArrayListVuelos, cantidadDePasajeros);
				printf("\n\n[\tLa cantidad total de pasajeros cargados en el sistema es de: %d\t]", cantidadPasajeros);
				break;
			default:
				cantidadPasajerosAChina =  ll_count(pArrayListVuelos, cantidadDePasajerosAChina);
				printf("\n\n[\tLa cantidad total de pasajeros cargados en el sistema que viajan a china es de: %d\t]", cantidadPasajerosAChina);
				break;
		}
	}
	return rtn;
}

/**
 * \brief Contador de cantidad de pasajeros
 * \param pElement
 * \return
 */
int cantidadDePasajeros (void* pElement){
	int rtn = -1;
	int acumulador = 0;
	eVuelos* e1;

	if(pElement != NULL){
		rtn = 1;
		e1 = pElement;
		acumulador = e1->cantPasajeros;
		return acumulador;
	}

	return rtn;

}

/**
 * \brief contador de cantidad de pasajeros a China
 * \param pElement
 * \return
 */
int cantidadDePasajerosAChina (void* pElement){
	int rtn = -1;
	int acumulador = 0;
	eVuelos* e1;

	if(pElement != NULL){
		rtn = 1;
		e1 = pElement;

		if(strcmp(e1->destino,"China") == 0){
			acumulador = e1->cantPasajeros;
		}
		return acumulador;
	}

	return rtn;

}


int vuelo_mayorACincoHoras (void* pElement){
	int rtn = -1;
	int resultado;

	eVuelos* e1;

	if(pElement != NULL){
		rtn = 1;
		e1 = pElement;

		resultado = e1->horaLlegada - e1->horaDespegue;

		if(resultado < 6){
			rtn = 0;
		}
	}

	return rtn;
}


int filrar_pilotos (void* pElement){
	int rtn = -1;
	ePiloto* e1;


	if(pElement != NULL){
		rtn = 1;
		e1 = pElement;

		if(strcmp(e1->nombre, "Alex") == 0 && strcmp (e1->apellido, "Lifeson") == 0){
			rtn = 0;
		} else if (strcmp(e1->nombre, "Richard") == 0 && strcmp (e1->apellido, "Bach") == 0){
			rtn = 0;
		}
	}

	return rtn;
}




