/*
 * main.c
 *
 *  Created on: 2 may. 2021
 *      Author: luciano
 */


#include <stdio.h>
#include <stdlib.h>

#include "Utilidades.h"
#include "eNacionalidad.h"
#include "eTipoProducto.h"
#include "eProductos.h"
#include "nexoEstructuras.h"


#define LENGHT_PRODUCTOS 25
#define LENGHT_TIPO_PRODUCTOS 10
#define LENGHT_NACIONALIDADES 9

int main(void){

	int opcion;
	int flagProductos;
	int flagTipo;
	int flagNaciones;
	int bajaCascada;

	eProductos listadoDeProductos[LENGHT_PRODUCTOS];
	inicializarIsEmptyProductos(listadoDeProductos, LENGHT_PRODUCTOS);
	hardocodearDatosUnaStructProductos(listadoDeProductos);

	eTipoProducto listadoDeTiposProductos[LENGHT_TIPO_PRODUCTOS];
	inicializarIsEmptyTipoProductos(listadoDeTiposProductos, LENGHT_PRODUCTOS);
	hardocodearDatosUnaStructTipoProductos(listadoDeTiposProductos);

	eNacionalidad listadoDeNacionalidades[LENGHT_NACIONALIDADES];
	inicializarIsEmptyNacionalidades(listadoDeNacionalidades, LENGHT_NACIONALIDADES);
	hardocodearDatosUnaStructNacionalidades(listadoDeNacionalidades);


	setbuf(stdout,NULL);

	do{
		opcion = menu();

		flagNaciones = comprobarEspaciosOcupadosEstructuraNacion(listadoDeNacionalidades, LENGHT_NACIONALIDADES);
		flagTipo = comprobarEspaciosOcupadosEstructuraTipo(listadoDeTiposProductos, LENGHT_PRODUCTOS);
		flagProductos= comprobarEspaciosOcupadosEstructura(listadoDeProductos, LENGHT_PRODUCTOS);

		switch(opcion){
			case 1:
				if(flagTipo != -1 && flagNaciones !=-1)  {
					altaListaEstructura(listadoDeProductos,LENGHT_PRODUCTOS,listadoDeTiposProductos,LENGHT_TIPO_PRODUCTOS,listadoDeNacionalidades,LENGHT_NACIONALIDADES);
					flagProductos++;
				} else {
					if(flagTipo==-1){
						printf("\n--------No hay tipos de productos cargados, la lista esta vacia--------\n");
					} else {
						if(flagNaciones == -1) {
							printf("\n--------No hay nacionalidades cargadas, la lista esta vacia--------\n");
						}
					}
				}
				break;
			case 2:
				if(flagTipo != -1 && flagNaciones != -1 && flagProductos != -1){
					saltoDeLinea(1);
					bajaListaEstructura(listadoDeProductos,LENGHT_PRODUCTOS);
				} else {
					if(flagTipo == -1){
						printf("\n--------No hay tipos de productos cargados, la lista esta vacia--------\n");
					} else {
						if(flagNaciones == -1){
							printf("\n--------No hay nacionalidades cargadas, la lista esta vacia--------\n");
						} else {
							printf("\n--------No hay productos cargados--------\n\n");
						}
					}
				}
				break;
			case 3:
				if(flagTipo != -1 && flagNaciones != -1 && flagProductos != -1){
					saltoDeLinea(1);
					modificarProductos(listadoDeProductos,LENGHT_PRODUCTOS,listadoDeTiposProductos,LENGHT_TIPO_PRODUCTOS,listadoDeNacionalidades,LENGHT_NACIONALIDADES);
				} else {
					if(flagTipo == -1){
						printf("\n--------No hay tipos de productos cargados, la lista esta vacia--------\n");
					} else {
						if(flagNaciones == -1){
							printf("\n--------No hay nacionalidades cargadas, la lista esta vacia--------\n");
						} else {
							printf("\n--------No hay productos cargados--------\n\n");
						}
					}
				}
				break;
			case 4:
				if(flagTipo != -1 && flagNaciones != -1 && flagProductos != -1){
					saltoDeLinea(1);
					mostrarListadoProductos(listadoDeProductos, LENGHT_PRODUCTOS);
				} else {
					if(flagTipo == -1){
						printf("\n--------No hay tipos de productos cargados, la lista esta vacia--------\n");
					} else {
						if(flagNaciones == -1){
							printf("\n--------No hay nacionalidades cargadas, la lista esta vacia--------\n");
						} else {
							printf("\n--------No hay productos cargados--------\n\n");
						}
					}
				}
				break;
			case 5:
				if(flagTipo != -1 && flagNaciones != -1 && flagProductos != -1){
					insertionSortNumbPrecio(listadoDeProductos, LENGHT_PRODUCTOS);
					saltoDeLinea(1);
					mostrarListadoProductos(listadoDeProductos, LENGHT_PRODUCTOS);
				} else {
					if(flagTipo == -1){
						printf("\n--------No hay tipos de productos cargados, la lista esta vacia--------\n");
					} else {
						if(flagNaciones == -1){
							printf("\n--------No hay nacionalidades cargadas, la lista esta vacia--------\n");
						} else {
							printf("\n--------No hay productos cargados--------\n\n");
						}
					}
				}
				break;
			case 6:
				if(flagTipo != -1 && flagNaciones != -1 && flagProductos != -1){
					insertionSortNumbDescripcion(listadoDeProductos, LENGHT_PRODUCTOS);
					saltoDeLinea(1);
					mostrarListadoProductos(listadoDeProductos, LENGHT_PRODUCTOS);
				} else {
					if(flagTipo == -1){
						printf("\n--------No hay tipos de productos cargados, la lista esta vacia--------\n");
					} else {
						if(flagNaciones == -1){
							printf("\n--------No hay nacionalidades cargadas, la lista esta vacia--------\n");
						} else {
							printf("\n--------No hay productos cargados--------\n\n");
						}
					}
				}
				break;
			case 7:
				if(flagTipo != -1 && flagNaciones != -1 && flagProductos != -1){
					saltoDeLinea(1);
					productosMasCaros(listadoDeProductos, LENGHT_PRODUCTOS);
				} else {
					if(flagTipo == -1){
						printf("\n--------No hay tipos de productos cargados, la lista esta vacia--------\n");
					} else {
						if(flagNaciones == -1){
							printf("\n--------No hay nacionalidades cargadas, la lista esta vacia--------\n");
						} else {
							printf("\n--------No hay productos cargados--------\n\n");
						}
					}
				}
				break;

			case 8:
				if(flagTipo != -1 && flagNaciones != -1 && flagProductos != -1){
					printPromediosPorTipo(listadoDeProductos,LENGHT_PRODUCTOS,listadoDeTiposProductos,LENGHT_TIPO_PRODUCTOS);
				} else {
					if(flagTipo == -1){
						printf("\n--------No hay tipos de productos cargados, la lista esta vacia--------\n");
					} else {
						if(flagNaciones == -1){
							printf("\n--------No hay nacionalidades cargadas, la lista esta vacia--------\n");
						} else {
							printf("\n--------No hay productos cargados--------\n\n");
						}
					}
				}
				break;
			case 9:
				if(flagTipo != -1 && flagNaciones != -1 && flagProductos != -1){
					mostrarListadoProductosConDescTipo(listadoDeProductos,LENGHT_PRODUCTOS,listadoDeTiposProductos,LENGHT_TIPO_PRODUCTOS);
				} else {
					if(flagTipo == -1){
						printf("\n--------No hay tipos de productos cargados, la lista esta vacia--------\n");
					} else {
						if(flagNaciones == -1){
							printf("\n--------No hay nacionalidades cargadas, la lista esta vacia--------\n");
						} else {
							printf("\n--------No hay productos cargados--------\n\n");
						}
					}
				}
				break;
			case 10:
				if(flagTipo != -1 && flagNaciones != -1 && flagProductos != -1){
					mostrarListadoTipoProductoYProducto(listadoDeProductos,LENGHT_PRODUCTOS,listadoDeTiposProductos,LENGHT_TIPO_PRODUCTOS);
				} else {
					if(flagTipo == -1){
						printf("\n--------No hay tipos de productos cargados, la lista esta vacia--------\n");
					} else {
						if(flagNaciones == -1){
							printf("\n--------No hay nacionalidades cargadas, la lista esta vacia--------\n");
						} else {
							printf("\n--------No hay productos cargados--------\n\n");
						}
					}
				}
				break;

			case 11:
				if(flagTipo != -1 && flagNaciones != -1 && flagProductos != -1){
					calcularTiposConMasProductos(listadoDeProductos,LENGHT_PRODUCTOS,listadoDeTiposProductos,LENGHT_TIPO_PRODUCTOS);
				} else {
					if(flagTipo == -1){
						printf("\n--------No hay tipos de productos cargados, la lista esta vacia--------\n");
					} else {
						if(flagNaciones == -1){
							printf("\n--------No hay nacionalidades cargadas, la lista esta vacia--------\n");
						} else {
							printf("\n--------No hay productos cargados--------\n\n");
						}
					}
				}
				break;
			case 12:
				if(flagTipo != -1 && flagNaciones != -1 && flagProductos != -1){
					calcularNacionalidadFabricaIphone(listadoDeProductos,LENGHT_PRODUCTOS,listadoDeTiposProductos,LENGHT_TIPO_PRODUCTOS, listadoDeNacionalidades, LENGHT_NACIONALIDADES);
				} else {
					if(flagTipo == -1){
						printf("\n--------No hay tipos de productos cargados, la lista esta vacia--------\n");
					} else {
						if(flagNaciones == -1){
							printf("\n--------No hay nacionalidades cargadas, la lista esta vacia--------\n");
						} else {
							printf("\n--------No hay productos cargados--------\n\n");
						}
					}
				}
				break;
			case 13:
				if(flagTipo != -1 && flagNaciones != -1 && flagProductos != -1){
					insertionSortNumbNacionalidad(listadoDeNacionalidades, LENGHT_NACIONALIDADES);
					saltoDeLinea(2);
					printProductosOrdenadosPorNacionalidad(listadoDeProductos, LENGHT_PRODUCTOS, listadoDeNacionalidades, LENGHT_NACIONALIDADES);
				} else {
					if(flagTipo == -1){
						printf("\n--------No hay tipos de productos cargados, la lista esta vacia--------\n");
					} else {
						if(flagNaciones == -1){
							printf("\n--------No hay nacionalidades cargadas, la lista esta vacia--------\n");
						} else {
							printf("\n--------No hay productos cargados--------\n\n");
						}
					}
				}
				break;
			case 14:
				if(flagTipo != -1 && flagNaciones != -1 && flagProductos != -1){
					saltoDeLinea(2);
					calcularNacionConMasProductos(listadoDeProductos, LENGHT_PRODUCTOS, listadoDeNacionalidades, LENGHT_NACIONALIDADES);
				} else {
					if(flagTipo == -1){
						printf("\n--------No hay tipos de productos cargados, la lista esta vacia--------\n");
					} else {
						if(flagNaciones == -1){
							printf("\n--------No hay nacionalidades cargadas, la lista esta vacia--------\n");
						} else {
							printf("\n--------No hay productos cargados--------\n\n");
						}
					}
				}
				break;
			case 15:
				if(flagTipo != -1 && flagNaciones != -1 && flagProductos != -1){
					saltoDeLinea(1);
					printPromediosPorNacion(listadoDeProductos, LENGHT_PRODUCTOS, listadoDeNacionalidades, LENGHT_NACIONALIDADES);
				} else {
					if(flagTipo == -1){
						printf("\n--------No hay tipos de productos cargados, la lista esta vacia--------\n");
					} else {
						if(flagNaciones == -1){
							printf("\n--------No hay nacionalidades cargadas, la lista esta vacia--------\n");
						} else {
							printf("\n--------No hay productos cargados--------\n\n");
						}
					}
				}
				break;
			case 16:
					altaListaEstructuraTipo(listadoDeTiposProductos, LENGHT_TIPO_PRODUCTOS);
					flagTipo++;
				break;
			case 17:
				if(flagTipo != -1){
					bajaCascada = bajaListaEstructuraTipo(listadoDeTiposProductos, LENGHT_TIPO_PRODUCTOS);
					cascadaProductosYTipo(listadoDeProductos, LENGHT_PRODUCTOS, bajaCascada);
				} else {
					printf("\n--------No hay tipos de productos cargados--------\n\n");
				}
				break;
			case 18:
				if(flagTipo != -1){
					modificarTipo(listadoDeTiposProductos, LENGHT_TIPO_PRODUCTOS);
				} else {
					printf("\n--------No hay tipos de productos cargados--------\n\n");
				}
				break;
			case 19:
				altaListaEstructuraNacionalidad(listadoDeNacionalidades, LENGHT_NACIONALIDADES);
				flagNaciones++;
				break;
			case 20:
				if(flagNaciones != -1){
					bajaCascada = bajaListaEstructuraNacionalidad(listadoDeNacionalidades, LENGHT_NACIONALIDADES);
					cascadaProductosYNacionalidad(listadoDeProductos, LENGHT_PRODUCTOS, bajaCascada);
				} else {
					printf("\n--------No hay nacionalidades cargadas--------\n\n");
				}
				break;
			case 21:
				if(flagNaciones != -1){
					modificarNacionalidad(listadoDeNacionalidades, LENGHT_NACIONALIDADES);
				} else {
					printf("\n--------No hay nacionalidades cargadas--------\n\n");
				}
				break;
			default:
				printf("\nGracias por utilizar el programa.");
				break;
		}

	}while(opcion != 22);

	return EXIT_SUCCESS;
}
