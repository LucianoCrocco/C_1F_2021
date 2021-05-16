/*
 * eBicicleta.h
 *
 *  Created on: 11 may. 2021
 *      Author: luciano
 */

#ifndef EBICICLETA_H_
#define EBICICLETA_H_


#define STRING_LENGHT 100
#define STRING_LENGHT_MARCA_BICI 25
#define VACIO 0
#define OCUPADO -1

typedef struct{

	int id;
	char marca[STRING_LENGHT];
	int rodado;
	char color[STRING_LENGHT];
	int isEmpty;

}eBicicleta;

void inicializarIsEmptyBicicleta(eBicicleta lista[], int lenghtArray);
void hardcodearStructBicicleta(eBicicleta listaBicicleta[]);

int comprobarEspaciosVaciosEstructuraBicicleta(eBicicleta lista[], int lenghtArray);
int comprobarEspaciosOcupadosEstructuraBicicleta(eBicicleta lista[], int lenghtArray);
int comprobarIndexOcupadoBicicleta(eBicicleta lista[], int lenghtArray, int numero);

void mostrarListadoBicicletas(eBicicleta  lista[], int lenghtArray);
void mostrarUnElementoBicicleta(eBicicleta unElemento);


#endif /* EBICICLETA_H_ */
