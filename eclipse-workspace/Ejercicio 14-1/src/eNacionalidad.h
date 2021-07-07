/*
 * eNacionalidad.h
 *
 *  Created on: 2 may. 2021
 *      Author: luciano
 */

#ifndef ENACIONALIDAD_H_
#define ENACIONALIDAD_H_


#define VACIO 0
#define OCUPADO -1
#define STRING_LENGHT 100

typedef struct {

	int idNacionalidad;
	char descripcionNacionalidad[STRING_LENGHT];
	int isEmpty;

}eNacionalidad;

/************************************************************************************************************/
/*************************************************HARDCODEOS*************************************************/
/************************************************************************************************************/

void hardocodearDatosUnaStructNacionalidades(eNacionalidad lista[]);
void inicializarIsEmptyNacionalidades(eNacionalidad lista[], int lenghtArray);


/************************************************************************************************************/
/************************************************VALIDACIONES************************************************/
/************************************************************************************************************/

int comprobarIndexOcupadoNacionalidad(eNacionalidad lista[], int lenghtArray, int numero);
int comprobarEspaciosOcupadosEstructuraNacion(eNacionalidad lista[], int lenghtArray);
int comprobarEspaciosVaciosEstructuraNacion(eNacionalidad lista[], int lenghtArray);

/************************************************************************************************************/
/****************************************************A.B.M***************************************************/
/************************************************************************************************************/

//CASE 1 Y 3 NACIONALIDAD:
void mostrarListadoNacionalidad(eNacionalidad lista[], int lenghtArray);
void mostrarUnElementoNacionalidad(eNacionalidad unElemento);

//CASE 13:
void insertionSortNumbNacionalidad(eNacionalidad listaNacion[], int lenghtArray);

//CASE 19:
void altaListaEstructuraNacionalidad(eNacionalidad listaNacion[], int lenghtArray);
void cargarDatosEstructuraNacionalidad(eNacionalidad listaNacion[], int lenghtArray, int index);

//CASE 20:
int bajaListaEstructuraNacionalidad(eNacionalidad listaNacion[], int lenghtArray);

//CASE 21:
void modificarNacionalidad(eNacionalidad listaNacion[], int lenghtArray);
void modificarDatoNacionalidad(eNacionalidad listaNacion[], int index);
#endif /* ENACIONALIDAD_H_ */
