/*
 * main.c
 *
 *  Created on: 12 abr. 2021
 *      Author: luciano
 */

struct eFecha{
	int dia;
	int mes;
	int anio;
};

typedef struct {
	int id;
	char descripcion [50];
	/*.................*/

	struct eFecha fechaElaboraicion;
	float precio;
}eProducto;

#include <stdio_ext.h>
#include <stdlib.h>

struct eFecha pedirFecha(eProducto miProducto);
eProducto pedirDatos(eProducto miProducto);
void printDatosEstructura(eProducto miProducto);

int main(void){

	eProducto unProducto;

	setbuf(stdout,NULL);

	unProducto = pedirDatos(unProducto);

	printDatosEstructura(unProducto);

	return EXIT_SUCCESS;
}

struct eFecha pedirFecha(eProducto miProducto){
	struct eFecha miFecha;

	printf("Ingrese el dia: ");
	//scanf("%d",&miProducto.fechaElaboraicion.dia);
	scanf("%d",&miFecha.dia);

	printf("Ingrese el mes: ");
	//scanf("%d",&miProducto.fechaElaboraicion.mes);
	scanf("%d",&miFecha.mes);

	printf("Ingrese el anio: ");
	//scanf("%d",&miProducto.fechaElaboraicion.anio);
	scanf("%d",&miFecha.anio);

	return miFecha;
}

eProducto pedirDatos(eProducto miProducto){
	eProducto producto;

	printf("Ingrese el ID: ");
	scanf("%d",&producto.id);

	printf("Ingrese la descripcion: ");
	__fpurge(stdin);
	scanf("%[^\n]",producto.descripcion);

	producto.fechaElaboraicion=pedirFecha(miProducto);

	printf("Ingrese el precio: ");
	scanf("%f",&producto.precio);

	return producto;
}

void printDatosEstructura(eProducto miProducto){
	printf("%d -- %s -- %d/%d/%d -- %.2f", miProducto.id, miProducto.descripcion, miProducto.fechaElaboraicion.dia, miProducto.fechaElaboraicion.mes, miProducto.fechaElaboraicion.anio, miProducto.precio);
}
