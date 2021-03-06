#ifndef NEXOESTRUCTURAS_H_
#define NEXOESTRUCTURAS_H_
#include "Piloto.h"
#include "Vuelos.h"
#include "nexoEstructuras.h"
#include "LinkedList.h"

#define STRING_LENGHT_NEXO 100

void flight_ListOneFlightWithPilot(eVuelos* vuelo, ePiloto* piloto, int primeraIteracion);
int piloto_findIndexPilotoByFlightID(LinkedList* pArrayListPilotos, int idVuelo_Piloto);
int contadorDePasajeros (LinkedList* pArrayListVuelos, int opcion);
int cantidadDePasajeros (void* pElement);
int cantidadDePasajerosAChina (void* pElement);

//P6
int vuelo_mayorACincoHoras(void* pElement);
//P8
int filrar_pilotos (void* pElement);
#endif /* NEXOESTRUCTURAS_H_ */
