#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Piloto.h"
#include "Vuelos.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_PilotsFromText(FILE* pFile , LinkedList* pArrayListPilots)
{

	char id[15];
	char nombre[128];
	char apellido[128];
	ePiloto* auxPiloto;

	int flag = 0;

	if(pFile != NULL && pArrayListPilots != NULL){

		while(!feof(pFile)){
			if(flag == 0){
				fscanf(pFile,"%[^,],%[^,],%[^\n]\n", id, nombre, apellido);
				flag++;
			} else {

				fscanf(pFile,"%[^,],%[^,],%[^\n]\n", id, nombre, apellido);

				auxPiloto=piloto_newParametros(id, nombre, apellido);

				if(auxPiloto != NULL){
					ll_add(pArrayListPilots, auxPiloto);
				} else {
					return 0;
				}


			}
		}
	} else {
		return 0;
	}

    return 1;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_VuelosFromText(FILE* pFile , LinkedList* pArrayListVuelos)
{

	char idVuelo[25];
	char idAvion[25];
	char idPiloto[25];
	char dia[15];
	char mes[15];
	char anio[15];
	char destino[128];
	char cantPasajeros[25];
	char horaDespegue[25];
	char horaLlegada[25];
	char fecha[25];

	eVuelos* auxVuelo;

	int flag = 0;

	if(pFile != NULL && pArrayListVuelos != NULL){

		while(!feof(pFile)){
			if(flag == 0){
				fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
				flag++;
			} else {

				fscanf(pFile,"%[^,],%[^,],%[^,],%[^/]/%[^/]/%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVuelo, idAvion, idPiloto, dia, mes, anio, destino, cantPasajeros, horaDespegue, horaLlegada);

				auxVuelo=vuelo_newParametros(idVuelo, idAvion, idPiloto, dia, mes, anio, destino, cantPasajeros,horaDespegue, horaLlegada);


				if(auxVuelo != NULL){
					ll_add(pArrayListVuelos, auxVuelo);
				} else {
					return 0;
				}


			}
		}
	} else {
		return 0;
	}

    return 1;
}
