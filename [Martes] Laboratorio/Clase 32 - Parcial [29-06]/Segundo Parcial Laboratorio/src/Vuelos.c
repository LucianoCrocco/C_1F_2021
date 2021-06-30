#include "Vuelos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * \brief Constructor por defecto, reserva  memoria dinamica
 * \return ePiloto* en memoria dinamica
 */
eVuelos* vuelo_new(){

	eVuelos* auxVuelo;

	auxVuelo = (eVuelos*) calloc (sizeof(eVuelos),1);

	return auxVuelo;
}

/**
 * \brief Constructor parametrizado, parsea los datos y los devuelve para añadirlos a la linked list
 * \param idVueloStr leido del .csv
 * \param idAvionStr leido del .csv
 * \param idPilotoStr leido del .csv
 * \param diaStr leido del .csv
 * \param mesStr leido del .csv
 * \param anioStr leido del .csv
 * \param destinoStr leido del .csv
 * \param cantPasajerosStr leido del .csv
 * \param horaDespegueStr leido del .csv
 * \param horaLlegadaStr leido del .csv
 * \return Retorna el elemento parametrizado
 */
eVuelos* vuelo_newParametros(char* idVueloStr, char* idAvionStr, char* idPilotoStr, char* diaStr, char* mesStr, char* anioStr, char* destinoStr, char* cantPasajerosStr,char* horaDespegueStr,char* horaLlegadaStr){
	eVuelos* auxVuelos;


	if(idVueloStr != NULL && idAvionStr != NULL && idPilotoStr != NULL && diaStr != NULL && mesStr != NULL && anioStr != NULL && destinoStr != NULL && horaDespegueStr != NULL && horaLlegadaStr != NULL){

		auxVuelos = vuelo_new();
		if(auxVuelos != NULL){
			vuelos_setAllAtributes(auxVuelos,atoi(idVueloStr), atoi(idAvionStr), atoi(idPilotoStr), atoi(diaStr), atoi(mesStr), atoi(anioStr), destinoStr, atoi(cantPasajerosStr), atoi(horaDespegueStr), atoi(horaLlegadaStr));
		}
	}

	return auxVuelos;
}

/**
 * \brief Elimina un elemento de la memoria dinamica
 * \param this
 */
void vuelo_delete(eVuelos* this){
	if(this != NULL){
		free(this);
	}
}

/**
 * \brief Setea el ID de mi elemento
 * \param this
 * \param id
 * \return 1 bien 0 NULL
 */

int vuelo_setIdVuelo(eVuelos* this,int id){

	int rtn = 0;

	if(this != NULL && id > -1){
		this->idVuelo = id;
		rtn =  1;
	}

	return rtn;
}

/**
 * \brief Devuelve el id de mi elemento
 * \param this
 * \param id Direccion de memoria a setear el campo del elemento
 * \return 1 bien 0 NULL
 */
int vuelo_getIdVuelo(eVuelos* this,int* id){

	int rtn = 0;

	if(this != NULL){
		*id = this->idVuelo;
		rtn = 1;
	}

	return rtn;
}

/**
 * \brief Setea el ID de mi elemento
 * \param this
 * \param id
 * \return 1 bien 0 NULL
 */

int vuelo_setIdAvion(eVuelos* this,int id){

	int rtn = 0;

	if(this != NULL && id > -1){
		this->idAvion = id;
		rtn =  1;
	}

	return rtn;
}

/**
 * \brief Devuelve el id de mi elemento
 * \param this
 * \param id Direccion de memoria a setear el campo del elemento
 * \return 1 bien 0 NULL
 */
int vuelo_getIdAvion(eVuelos* this,int* id){

	int rtn = 0;

	if(this != NULL){
		*id = this->idAvion;
		rtn = 1;
	}

	return rtn;
}

/**
 * \brief Setea el ID de mi elemento
 * \param this
 * \param id
 * \return 1 bien 0 NULL
 */

int vuelo_setIdPiloto(eVuelos* this,int id){

	int rtn = 0;

	if(this != NULL && id > -1){
		this->idPiloto = id;
		rtn =  1;
	}

	return rtn;
}

/**
 * \brief Devuelve el id de mi elemento
 * \param this
 * \param id Direccion de memoria a setear el campo del elemento
 * \return 1 bien 0 NULL
 */
int vuelo_getIdPiloto(eVuelos* this,int* id){

	int rtn = 0;

	if(this != NULL){
		*id = this->idPiloto;
		rtn = 1;
	}

	return rtn;
}

/**
 * \brief Setea la fecha de mi elemento
 * \param this
 * \param dia
 * \return 1 bien 0 NULL
 */

int vuelo_setFechaDia(eVuelos* this,int dia){

	int rtn = 0;

	if(this != NULL && dia > 0 && dia < 32){
		this->fecha.dia = dia;
		rtn =  1;
	}

	return rtn;
}

/**
 * \brief Devuelve la fecha de mi elemento
 * \param this
 * \param dia Direccion de memoria a setear el campo del elemento
 * \return 1 bien 0 NULL
 */
int vuelo_getFechaDia(eVuelos* this,int* dia){

	int rtn = 0;

	if(this != NULL){
		*dia = this->fecha.dia;
		rtn = 1;
	}

	return rtn;
}

/**
 * \brief Setea la fecha de mi elemento
 * \param this
 * \param mes
 * \return 1 bien 0 NULL
 */

int vuelo_setFechaMes(eVuelos* this,int mes){

	int rtn = 0;

	if(this != NULL && mes > -1 && mes < 13){
		this->fecha.mes = mes;
		rtn =  1;
	}

	return rtn;
}

/**
 * \brief Devuelve la fecha de mi elemento
 * \param this
 * \param mes Direccion de memoria a setear el campo del elemento
 * \return 1 bien 0 NULL
 */
int vuelo_getFechaMes(eVuelos* this,int* mes){

	int rtn = 0;

	if(this != NULL){
		*mes = this->fecha.mes;
		rtn = 1;
	}

	return rtn;
}

/**
 * \brief Setea la fecha de mi elemento
 * \param this
 * \param anio
 * \return 1 bien 0 NULL
 */

int vuelo_setFechaAnio(eVuelos* this,int anio){

	int rtn = 0;

	if(this != NULL && anio > 2018 && anio < 2022){
		this->fecha.anio = anio;
		rtn =  1;
	}

	return rtn;
}

/**
 * \brief Devuelve la fecha de mi elemento
 * \param this
 * \param anio Direccion de memoria a setear el campo del elemento
 * \return 1 bien 0 NULL
 */
int vuelo_getFechaAnio(eVuelos* this,int* anio){

	int rtn = 0;

	if(this != NULL){
		*anio = this->fecha.anio;
		rtn = 1;
	}

	return rtn;
}


/**
 * \brief Setea el destino de mi elemento
 * \param this
 * \param destino
 * \return 1 bien 0 NULL
 */
int vuelo_setDestino(eVuelos* this,char* destino){

	int rtn = 0;

	if(this != NULL && destino != NULL){
		strcpy(this->destino, destino);
		rtn =  1;
	}

	return rtn;
}
/**
 * \brief Devuelve el destino de mi elemento
 * \param this
 * \param destino Direccion de memoria a setear el campo del elemento
 * \return 1 bien 0 NULL
 */
int vuelo_getDestino(eVuelos* this,char* destino){

	int rtn = 0;

	if(this != NULL && destino != NULL){
		strcpy(destino, this->destino);
		rtn = 1;
	}

	return rtn;

}
/**
 * \brief Setea la cantidad de pasajeros de mi elemento
 * \param this
 * \param cantidad
 * \return
 */
int vuelo_setCantPasajeros(eVuelos* this,int cantidad){

	int rtn = 0;

	if(this != NULL && cantidad > -1){
		this->cantPasajeros = cantidad;
		rtn =  1;
	}

	return rtn;
}

/**
 * \brief Devuelve la cantidad de pasajeros de mi elemento
 * \param this
 * \param cantidad Direccion de memoria a setear el campo del elemento
 * \return 1 bien 0 NULL
 */
int vuelo_getCantPasajeros(eVuelos* this,int* cantidad){

	int rtn = 0;

	if(this != NULL){
		*cantidad = this->cantPasajeros;
		rtn = 1;
	}

	return rtn;
}

/**
 * \brief Setea la hora de despegue de mi elemento
 * \param this
 * \param horaDespegue
 * \return 1 bien 0 NULL
 */

int vuelo_setHoraDespegue(eVuelos* this,int horaDespegue){

	int rtn = 0;

	if(this != NULL && horaDespegue > -1 && horaDespegue < 25){
		this->horaDespegue = horaDespegue;
		rtn =  1;
	}

	return rtn;
}

/**
 * \brief Devuelve la hora de despegue de mi elemento
 * \param this
 * \param horaDespegue Direccion de memoria a setear el campo del elemento
 * \return 1 bien 0 NULL
 */
int vuelo_getHoraDespegue(eVuelos* this,int* horaDespegue){

	int rtn = 0;

	if(this != NULL){
		*horaDespegue = this->horaDespegue;
		rtn = 1;
	}

	return rtn;
}


/**
 * \brief Setea la hora de llegada de mi elemento
 * \param this
 * \param horaLlegada
 * \return 1 bien 0 NULL
 */

int vuelo_setHoraLlegada(eVuelos* this,int horaLlegada){

	int rtn = 0;

	if(this != NULL && horaLlegada > -1 && horaLlegada < 25){
		this->horaLlegada = horaLlegada;
		rtn =  1;
	}

	return rtn;
}

/**
 * \brief Devuelve la hora de llegada de mi elemento
 * \param this
 * \param horaLlegada Direccion de memoria a setear el campo del elemento
 * \return 1 bien 0 NULL
 */
int vuelo_getHoraLlegada(eVuelos* this,int* horaLlegada){

	int rtn = 0;

	if(this != NULL){
		*horaLlegada = this->horaLlegada;
		rtn = 1;
	}

	return rtn;
}


/**
 * \brief Setea todos los atributos de mi campo elementos
 * \param this
 * \param idVuelo
 * \param idAvion
 * \param idPiloto
 * \param dia
 * \param mes
 * \param anio
 * \param destino
 * \param cantPasajeros
 * \param horaDespegue
 * \param horaLlegada
 * \return
 */
int vuelos_setAllAtributes(eVuelos* this, int idVuelo, int idAvion, int idPiloto, int dia, int mes, int anio, char* destino, int cantPasajeros, int horaDespegue, int horaLlegada){
	int rtn = 1;

	if(this != NULL && idVuelo > -1 && idAvion > -1 && idPiloto > -1 && (dia > -1 && dia < 32) && (mes > 0 && mes < 13) && (anio > 2018 && anio < 2022) && destino != NULL && (horaDespegue > -1 && horaDespegue < 25) && (horaLlegada > -1 && horaLlegada < 25)){

		if(vuelo_setIdVuelo(this, idVuelo) == 0 && rtn == 1){
			rtn = 0;
		}
		if(vuelo_setIdAvion(this, idAvion) == 0 && rtn == 1){
			rtn = 0;
		}
		if(vuelo_setIdPiloto(this, idPiloto) == 0 && rtn == 1){
			rtn = 0;
		}
		if(vuelo_setFechaDia(this, dia) == 0 && rtn == 1){
			rtn = 0;
		}
		if(vuelo_setFechaMes(this, mes) == 0 && rtn == 1){
			rtn = 0;
		}
		if(vuelo_setFechaAnio(this, anio) == 0 && rtn == 1){
			rtn = 0;
		}
		if(vuelo_setDestino(this, destino) == 0 && rtn == 1){
			rtn = 0;
		}
		if(vuelo_setCantPasajeros(this, cantPasajeros) == 0 && rtn == 1){
			rtn = 0;
		}
		if(vuelo_setHoraDespegue(this, horaDespegue) == 0 && rtn == 1){
			rtn = 0;
		}

		if(vuelo_setHoraLlegada(this, horaLlegada) == 0 && rtn == 1){
			rtn = 0;
		}
	} else {

		rtn = 0;

	}

	return rtn;
}

/**
 * \brief Devuelve todos los atributos de mis campos elementos
 * \param this
 * \param idVuelo
 * \param idAvion
 * \param idPiloto
 * \param dia
 * \param mes
 * \param anio
 * \param destino
 * \param cantPasajeros
 * \param horaDespegue
 * \param horaLlegada
 * \return
 */
int vuelos_getAllAtributes(eVuelos* this, int* idVuelo, int* idAvion, int* idPiloto, int* dia, int* mes, int* anio, char* destino, int* cantPasajeros,int* horaDespegue, int* horaLlegada){
	int rtn = 1;

	if(this != NULL && idVuelo != NULL && idAvion != NULL && idPiloto != NULL && dia != NULL  && mes != NULL && anio != NULL && destino != NULL && horaDespegue != NULL && horaLlegada != NULL){

		if(vuelo_getIdVuelo(this, idVuelo) == 0 && rtn == 1){
			rtn = 0;
		}

		if(vuelo_getIdAvion(this, idAvion) == 0 && rtn == 1){
			rtn = 0;
		}

		if(vuelo_getIdPiloto(this, idPiloto) == 0 && rtn == 1){
			rtn = 0;
		}

		if(vuelo_getFechaDia(this, dia) == 0 && rtn == 1){
			rtn = 0;
		}

		if(vuelo_getFechaMes(this, mes) == 0 && rtn == 1){
			rtn = 0;
		}
		if(vuelo_getFechaAnio(this, anio) == 0 && rtn == 1){
			rtn = 0;
		}

		if(vuelo_getDestino(this, destino) == 0 && rtn == 1){
			rtn = 0;
		}

		if(vuelo_getCantPasajeros(this, cantPasajeros) == 0 && rtn == 1){
			rtn = 0;
		}

		if(vuelo_getHoraDespegue(this, horaDespegue) == 0 && rtn == 1){
			rtn = 0;
		}

		if(vuelo_getHoraLlegada(this, horaLlegada) == 0 && rtn == 1){
			rtn = 0;
		}



	} else {

		rtn = 0;

	}

	return rtn;
}
