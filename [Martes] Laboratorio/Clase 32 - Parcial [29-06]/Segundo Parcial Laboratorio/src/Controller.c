#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "bibliotecaGen.h"
#include "nexoEstructuras.h"


/** \brief Carga los datos de los vuelos desde el archivo csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVuelos LinkedList*
 * \return int
 *
 */
int controller_loadFromTextVuelos(char* path , LinkedList* pArrayListVuelos)
{
	FILE* pFile;

	int rtn = 0;

	pFile=fopen(path,"r");

	if(pFile != NULL){
		rtn = parser_VuelosFromText(pFile, pArrayListVuelos);
	}

	fclose(pFile);

    return rtn;
}

/** \brief Carga los datos de los pilotos desde el archivo csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPilotos LinkedList*
 * \return int
 *
 */
int controller_loadFromTextPilotos(char* path , LinkedList* pArrayListPilotos)
{
	FILE* pFile;

	int rtn = 0;

	if(path != NULL && pArrayListPilotos != NULL){
		pFile=fopen(path,"r");

		if(pFile != NULL){
			rtn = parser_PilotsFromText(pFile, pArrayListPilotos);
		}

		fclose(pFile);
	}

    return rtn;
}



/** \brief Lista los vuelos con sus pilotos
 *
 * \param pArrayListVuelos LinkedList*
 * \param pArrayListPilotos LinkedList*
 * \return int
 *
 */
int controller_ListVuelos(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos)
{
	int i;
	int rtn = 0;
	int len = ll_len(pArrayListVuelos);

	eVuelos* auxVuelos = NULL;
	ePiloto* auxPilotos = NULL;
	int indexPiloto;

	if(pArrayListVuelos != NULL && pArrayListPilotos != NULL){
		rtn = 1;

		for(i=0;i<len;i++){
			if(i==0){
				printf("\n\t\tLISTA DE VUELOS\n");
			}

			auxVuelos = (eVuelos*) ll_get(pArrayListVuelos, i);
			indexPiloto = piloto_findIndexPilotoByFlightID(pArrayListPilotos, auxVuelos->idPiloto);
			auxPilotos = (ePiloto*) ll_get(pArrayListPilotos, indexPiloto);

			flight_ListOneFlightWithPilot(auxVuelos, auxPilotos, i);
		}
	}

    return rtn;
}


int controller_saveAsText(char* path , LinkedList* pArrayListVuelos)
{
	FILE* pFile;

	int len;
	int i;

	len = ll_len(pArrayListVuelos);
	eVuelos* auxVuelo;

	pFile=fopen(path,"w");

	if(pFile != NULL){
		int idVuelo;
		int idAvion;
		int idPiloto;
		int dia;
		int mes;
		int anio;
		char destino[80];
		int cantPasajeros;
		int horaDespegue;
		int horaLlegada;



		fprintf(pFile,"idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");

		for(i=0;i<len;i++){//Para que no escriba los header del csv
			auxVuelo=ll_get(pArrayListVuelos, i);

			if(vuelos_getAllAtributes(auxVuelo, &idVuelo, &idAvion, &idPiloto, &dia, &mes, &anio, destino, &cantPasajeros, &horaDespegue, &horaLlegada) == 1){
				fprintf(pFile,"%d,%d,%d,%d/%d/%d,%s,%d,%d,%d\n", idVuelo, idAvion, idPiloto, dia, mes, anio, destino, cantPasajeros, horaDespegue, horaLlegada);
			}
		}
	} else {
		return 0;
	}

	fclose(pFile);

    return 1;
}


int controller_ListVuelosPortugal(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos)
{
	int i;
	int rtn = 0;
	int len = ll_len(pArrayListVuelos);

	eVuelos* auxVuelos = NULL;
	ePiloto* auxPilotos = NULL;
	int indexPiloto;

	if(pArrayListVuelos != NULL && pArrayListPilotos != NULL){
		rtn = 1;

		for(i=0;i<len;i++){
			if(i==0){
				printf("\n\t\tLISTA DE VUELOS\n");
			}

			auxVuelos = (eVuelos*) ll_get(pArrayListVuelos, i);

			if(strcmp(auxVuelos->destino, "Portugal") == 0){
				indexPiloto = piloto_findIndexPilotoByFlightID(pArrayListPilotos, auxVuelos->idPiloto);
				auxPilotos = (ePiloto*) ll_get(pArrayListPilotos, indexPiloto);
				flight_ListOneFlightWithPilot(auxVuelos, auxPilotos, i);
			}

		}
	}

    return rtn;
}


int controller_ListSinDosPilotos(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos)
{
	int i;
	int j;
	int rtn = 0;
	int flag = 0;
	int len = ll_len(pArrayListVuelos);
	int lenPilotos = ll_len(pArrayListPilotos);

	eVuelos* auxVuelos = NULL;
	ePiloto* auxPilotos = NULL;

	if(pArrayListVuelos != NULL && pArrayListPilotos != NULL){
		rtn = 1;

		for(i=0;i<lenPilotos;i++){
			for(j=0;j<len;j++){

				auxPilotos = (ePiloto*) ll_get(pArrayListPilotos, i);
				auxVuelos = (eVuelos*) ll_get(pArrayListVuelos, j);

				if(auxPilotos->id == auxVuelos->idPiloto){
					flight_ListOneFlightWithPilot(auxVuelos, auxPilotos, flag);
					flag++;
				}
			}
		}

	}

    return rtn;
}


