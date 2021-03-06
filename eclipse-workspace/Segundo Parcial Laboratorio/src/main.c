#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "bibliotecaGen.h"
#include "nexoEstructuras.h"

int main(void){
	setbuf(stdout,NULL);

	int opciones;
	int flagCargoPilotos = 0;
	int flagCargoVuelos = 0;

	LinkedList* listaVuelos = ll_newLinkedList();
	LinkedList* listaPilotos = ll_newLinkedList();
	LinkedList* listaDistanciaVuelos;
	LinkedList* listaSinDosPilotos;

	do{
		if(menu(&opciones) == 0){
			puts("\n\tError al cargar las opciones del menu\n\n");
			return EXIT_FAILURE;
		}

		switch(opciones){
			case 1:
				if(listaPilotos != NULL && flagCargoPilotos == 0){
					if(controller_loadFromTextPilotos("/home/luciano/HDD/eclipse-workspace/Segundo Parcial Laboratorio/src/Pilotos.csv", listaPilotos) == 0){
						puts("\n\nError al cargar los archivos de los pilotos\n");
					} else {
						puts("\n\nArchivos de pilotos cargados correctamente\n");
						flagCargoPilotos++;
					}
				} else {
					if(flagCargoPilotos == 1){
						puts("\nYa cargo a los pilotos en memoria!\n");
					} else {
						puts("\nNo hay memoria disponible para cargar Pilotos en el sistema\n");
					}
				}

				break;

			case 2:
				if(listaVuelos != NULL && flagCargoVuelos == 0){
					if(controller_loadFromTextVuelos("/home/luciano/HDD/eclipse-workspace/Segundo Parcial Laboratorio/src/Vuelos.csv", listaVuelos) == 0){
						puts("\n\nError al cargar los archivos de Vuelo\n");
					} else {
						puts("\n\nArchivos de vuelos cargados correctamente\n");
						flagCargoVuelos++;
					}
				} else {
					if(flagCargoVuelos == 1){
						puts("\nYa cargo los vuelos en memoria!\n");
					} else {
						puts("\nNo hay memoria disponible para cargar Vuelos en el sistema\n");
					}
				}
				break;

			case 3:
				if(ll_isEmpty(listaVuelos) == 0 && ll_isEmpty(listaPilotos) == 0){
					if(controller_ListVuelos(listaVuelos, listaPilotos) == 1){
						puts("\nLista cargada correctamente\n");
					} else {
						puts("\nLa lista no pudo ser cargada correctamente\n");
					}
				} else {
					puts("\nError al cargar la lista, no hay datos de los pilotos o los vuelos cargados en memoria!\n");
				}
				break;

			case 4:
				if(ll_isEmpty(listaVuelos) == 0){
					if(contadorDePasajeros(listaVuelos, 1) == 1){
						puts("\nLista cargada correctamente\n");
					} else {
						puts("\nLa lista no pudo ser cargada correctamente\n");
					}
				} else {
					puts("\nError al cargar la lista, no hay datos de los vuelos cargados en memoria!\n");
				}
				break;

			case 5:
				if(ll_isEmpty(listaVuelos) == 0){
					if(contadorDePasajeros(listaVuelos, 2) == 1){
						puts("\nLista cargada correctamente\n");
					} else {
						puts("\nLa lista no pudo ser cargada correctamente\n");
					}
				} else {
					puts("\nError al cargar la lista, no hay datos de los vuelos cargados en memoria!\n");
				}
				break;

			case 6:
				if(ll_isEmpty(listaVuelos) == 0){
					listaDistanciaVuelos = ll_filter(listaVuelos, vuelo_mayorACincoHoras);
					if(listaDistanciaVuelos != NULL){
						if(controller_saveAsText("VuelosMayoresA5Horas.csv" , listaDistanciaVuelos) == 1){
							puts("\nArchivo creado correctamente\n");
						} else {
							puts("\nError al crear correctamente el archivo\n");
						}
					}
				} else {
					puts("\nError al crear el nuevo archivo!\n");
				}
				break;

			case 7:
				if(ll_isEmpty(listaVuelos) == 0 && ll_isEmpty(listaPilotos) == 0){
					if(controller_ListVuelosPortugal(listaVuelos, listaPilotos) == 1){
						puts("\nLista cargada correctamente\n");
					} else {
						puts("\nLa lista no pudo ser cargada correctamente\n");
					}
				} else {
					puts("\nError al cargar la lista, no hay datos de los pilotos o los vuelos cargados en memoria!\n");
				}
				break;

			case 8:
				if(ll_isEmpty(listaVuelos) == 0 && ll_isEmpty(listaPilotos) == 0){
					listaSinDosPilotos = ll_filter(listaPilotos, filrar_pilotos);
					if(listaSinDosPilotos != NULL && listaVuelos != NULL){
						if(controller_ListSinDosPilotos(listaVuelos, listaSinDosPilotos) == 1 ){
							puts("\nLista cargada correctamente\n");
						} else {
							puts("\nLa lista no pudo ser cargada correctamente\n");
						}
					}
				} else {
					puts("\nError al crear el nuevo archivo!\n");
				}

				break;
			default:
				puts("\n\n\t[Saliendo...]");
				break;
		}
	}while(opciones != 9);

	return EXIT_SUCCESS;
}
