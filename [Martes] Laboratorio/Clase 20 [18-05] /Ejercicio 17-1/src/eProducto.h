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

eProducto* crearProductoHardcodeado(void);
void mostrarUnElementoProductos(eProducto* unProducto);
#endif /* EPRODUCTO_H_ */
