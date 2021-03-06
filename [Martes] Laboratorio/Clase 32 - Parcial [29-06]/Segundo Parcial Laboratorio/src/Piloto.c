#include "Piloto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * \brief Constructor por defecto, reserva  memoria dinamica
 * \return ePiloto* en memoria dinamica
 */
ePiloto* piloto_new(){

	ePiloto* auxPiloto;

	auxPiloto = (ePiloto*) calloc (sizeof(ePiloto),1);

	return auxPiloto;
}

/**
 * \brief Constructor parametrizado, parsea los datos y los devuelve para añadirlos a la linked list
 * \param idStr ID leido del .csv
 * \param nombreStr Nombre leido del .csv
 * \param ApelldioStr Apellido leido del .csv
 * \return Retorna el elemento parametrizado
 */
ePiloto* piloto_newParametros(char* idStr,char* nombreStr,char* apellidoStr){
	ePiloto* auxPiloto;


	if(idStr != NULL && nombreStr != NULL && apellidoStr != NULL){

		auxPiloto = piloto_new();
		if(auxPiloto != NULL){
			if(piloto_setAllAtributes(auxPiloto,atoi(idStr), nombreStr, apellidoStr) == 0){
				free(auxPiloto);
			}
		}
	}

	return auxPiloto;
}

/**
 * \brief Elimina un elemento de la memoria dinamica
 * \param this
 */
void piloto_delete(ePiloto* this){
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

int piloto_setId(ePiloto* this,int id){

	int rtn = 0;

	if(this != NULL && id > -1){
		this->id = id;
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
int piloto_getId(ePiloto* this,int* id){

	int rtn = 0;

	if(this != NULL){
		*id = this->id;
		rtn = 1;
	}

	return rtn;
}

/**
 * \brief Setea el nombre de mi elemento
 * \param this
 * \param nombre
 * \return 1 bien 0 NULL
 */
int piloto_setNombre(ePiloto* this,char* nombre){

	int rtn = 0;

	if(this != NULL && nombre != NULL){
		strcpy(this->nombre, nombre);
		rtn =  1;
	}

	return rtn;
}
/**
 * \brief Devuelve el nombre de mi elemento
 * \param this
 * \param nombre Direccion de memoria a setear el campo del elemento
 * \return 1 bien 0 NULL
 */
int piloto_getNombre(ePiloto* this,char* nombre){

	int rtn = 0;

	if(this != NULL && nombre != NULL){
		strcpy(nombre, this->nombre);
		rtn = 1;
	}

	return rtn;

}

/**
 * \brief Setea el apellido de mi elemento
 * \param this
 * \param nombre
 * \return 1 bien 0 NULL
 */
int piloto_setApellido(ePiloto* this,char* apellido){

	int rtn = 0;

	if(this != NULL && apellido != NULL){
		strcpy(this->apellido, apellido);
		rtn =  1;
	}

	return rtn;
}
/**
 * \brief Devuelve el apellido de mi elemento
 * \param this
 * \param nombre Direccion de memoria a setear el campo del elemento
 * \return 1 bien 0 NULL
 */
int piloto_getApellido(ePiloto* this,char* apellido){

	int rtn = 0;

	if(this != NULL && apellido != NULL){
		strcpy(apellido, this->apellido);
		rtn = 1;
	}

	return rtn;

}


/**
 * \brief Setea todos los campos de mi elemento
 * \param this
 * \param id
 * \param nombre
 * \param apellido
 * \return 1 bien 0 NULL
 */
int piloto_setAllAtributes(ePiloto* this, int id, char* nombre, char* apellido){
	int rtn = 1;

	if(this != NULL && id > -1 && nombre != NULL && apellido != NULL){

		if(piloto_setId(this, id) == 0 && rtn == 1){
			rtn = 0;
		}
		if(piloto_setNombre(this, nombre) == 0 && rtn == 1){
			rtn = 0;
		}
		if(piloto_setApellido(this, apellido) == 0 && rtn == 1){
			rtn = 0;
		}
	} else {

		rtn = 0;

	}

	return rtn;
}

/**
 * \brief Devuelve todos los campos mi elemento
 * \param this
 * \param id Direccion de memoria a setear el campo del elemento
 * \param nombre Direccion de memoria a setear el campo del elemento
 * \param apellido Direccion de memoria a setear el campo del elemento
 * \return 1 bien 0 NULL
 */
int piloto_getAllAtributes(ePiloto* this, int* id, char* nombre, char* apellido){

	int rtn = 1;

	if(this != NULL && id != NULL && nombre != NULL && apellido != NULL ){

		if(piloto_getId(this, id) == 0 && rtn == 1){
			rtn = 0;
		}
		if(piloto_getNombre(this, nombre) == 0 && rtn == 1){
			rtn = 0;
		}
		if(piloto_getApellido(this, apellido) == 0 && rtn == 1){
			rtn = 0;
		}
	} else {

		rtn = 0;

	}
	return rtn;

}



