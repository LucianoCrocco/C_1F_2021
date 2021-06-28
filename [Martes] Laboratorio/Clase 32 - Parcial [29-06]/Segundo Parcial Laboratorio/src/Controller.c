#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "bibliotecaGen.h"
#include "nexoEstructuras.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
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

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
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

		if(pFile != NULL){
			printf("\n\nNO ERROR");
		} else {
			printf("ERROR\n\n");
		}

		fclose(pFile);
	}

    return rtn;
}



/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListVuelos(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos)
{
	int i;
	int len = ll_len(pArrayListVuelos);

	eVuelos* auxVuelos = NULL;
	ePiloto* auxPilotos = NULL;
	int indexPiloto;

	for(i=0;i<len;i++){
		if(i==0){
			printf("\n\t\tLISTA DE VUELOS\n");
		}

		auxVuelos = (eVuelos*) ll_get(pArrayListVuelos, i);
		indexPiloto = piloto_findIndexPilotoByFlightID(pArrayListPilotos, auxVuelos->idPiloto);
		auxPilotos = (ePiloto*) ll_get(pArrayListPilotos, indexPiloto);

		flight_ListOneFlightWithPilot(auxVuelos, auxPilotos, i);
	}
    return 1;
}


