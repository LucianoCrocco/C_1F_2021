#include <stdio_ext.h>
#include <stdlib.h>
#include "Piloto.h"
#include "Vuelos.h"
#include "nexoEstructuras.h"
#include "LinkedList.h"


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
			printf("    %02d\t\t    %02d\t\t %d/%d/%d %13s \tID:%2d  %s %s\t       %02d\t      %02d\t\t%03d\n", idVuelo, idAvion, dia, mes, anio, destino, idPiloto, nombre, apellido,horaDespegue, horaLlegada, cantPasajeros);
		} else {
			printf("    %02d\t\t    %02d\t\t %d/%d/%d %13s \tID:%2d  %s %s\t       %02d\t      %02d\t\t%03d\n", idVuelo, idAvion, dia, mes, anio, destino, idPiloto, nombre, apellido,horaDespegue, horaLlegada, cantPasajeros);
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