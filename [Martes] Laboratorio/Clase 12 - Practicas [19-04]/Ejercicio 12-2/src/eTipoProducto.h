/*
 * eTipoProducto.h
 *
 *  Created on: 2 may. 2021
 *      Author: luciano
 */

#ifndef ETIPOPRODUCTO_H_
#define ETIPOPRODUCTO_H_

#define VACIO 0
#define OCUPADO -1
#define STRING_LENGHT 100

typedef struct{

	int idTipo;
	char descripcionTipo[STRING_LENGHT];
	int isEmpty;

}eTipoProducto;

/************************************************************************************************************/
/*************************************************HARDCODEOS*************************************************/
/************************************************************************************************************/

void hardocodearDatosUnaStructTipoProductos(eTipoProducto lista[]);
void inicializarIsEmptyTipoProductos(eTipoProducto lista[], int lenghtArray);

/************************************************************************************************************/
/************************************************VALIDACIONES************************************************/
/************************************************************************************************************/

int comprobarEspaciosOcupadosEstructuraTipo(eTipoProducto lista[], int lenghtArray);
int comprobarEspaciosVaciosEstructuraTipo(eTipoProducto lista[], int lenghtArray);
int comprobarIndexOcupadoTipo(eTipoProducto lista[], int lenghtArray, int numero);

/************************************************************************************************************/
/****************************************************A.B.M***************************************************/
/************************************************************************************************************/

//CASE 1 Y 3 TIPO PRODUCTO:
void mostrarListadoTipoProducto(eTipoProducto  lista[], int lenghtArray);
void mostrarUnElementoTipoProducto(eTipoProducto unElemento);

//CASE 12:
int buscarIdTipoEspecifico(char nombre[], eTipoProducto listaTipo[], int lenghtTipo);

//CASE 16:
void altaListaEstructuraTipo(eTipoProducto listaTipo[], int lenghtTipo);
void cargarDatosEstructuraTipo(eTipoProducto listaTipo[], int lenghtTipo, int index);

//CASE 17:
void bajaListaEstructuraTipo(eTipoProducto listaTipo[], int lenghtTipo);

//CASE 18:
void modificarTipo(eTipoProducto listaTipo[], int lenghtTipo);
void modificarDatoTipo(eTipoProducto listaTipo[], int index);

#endif /* ETIPOPRODUCTO_H_ */
