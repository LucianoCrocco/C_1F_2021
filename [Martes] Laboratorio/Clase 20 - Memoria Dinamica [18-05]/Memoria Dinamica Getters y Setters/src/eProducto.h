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

eProducto* cargarProducto(void);
eProducto* cargarProductoConParametros(int, char*, float, int);
void mostrarUnElementoProductos(eProducto* unProducto);

//getters y setters
int eProducto_setId(eProducto*, int);//Puntero a la estructura y el ID que voy a implementar.
int eProducto_getId(eProducto*);
int eProducto_getId(eProducto* this, int* id);//Otra forma de get
#endif /* EPRODUCTO_H_ */
