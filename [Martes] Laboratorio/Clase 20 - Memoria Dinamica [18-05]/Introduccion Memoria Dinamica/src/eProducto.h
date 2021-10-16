/*
 * eProducto.h
 *
 *  Created on: 18 may. 2021
 *      Author: luciano
 */

#ifndef EPRODUCTO_H_
#define EPRODUCTO_H_


#define VACIO 0
#define OCUPADO -1
#define STRING_LENGHT 100

typedef struct{

	int idProducto;
	char descripcion[STRING_LENGHT];
	float precio;
	int isEmpty;

}eProducto;

eProducto* cargarProducto(void);//Constructor por defecto.
eProducto* cargarProductoConParametros(int, char*, float, int); //Constructor Parametrizado || Puedo tener todos los datos o los que necesite, puedo tener varios contructores de este tipo.
void mostrarUnElementoProductos(eProducto* unProducto);
#endif /* EPRODUCTO_H_ */
