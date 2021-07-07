/*
 * eFabricanteDePantalla.h
 *
 *  Created on: 10 may. 2021
 *      Author: luciano
 */

#ifndef EFABRICANTEDEPANTALLA_H_
#define EFABRICANTEDEPANTALLA_H_

#define VACIO 0
#define OCUPADO -1
#define STRING_LENGHT 100

typedef struct {

	int idFabricante;
	char descripcion[STRING_LENGHT];
	int isEmpty;

}eFabricanteDePantalla;

/************************************************************************************************************/
/*************************************************HARDCODEOS*************************************************/
/************************************************************************************************************/

void hardocodearDatosUnaStructFabricante(eFabricanteDePantalla lista[]);
void inicializarIsEmptyFabricante(eFabricanteDePantalla lista[], int lenghtArray);


#endif /* EFABRICANTEDEPANTALLA_H_ */
