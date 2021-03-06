#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"
#include "Vuelos.h"
#include "Piloto.h"

#define STRING_LENGHT 128

int controller_loadFromTextVuelos(char* path , LinkedList* pArrayListVuelos);
int controller_loadFromTextPilotos(char* path , LinkedList* pArrayListPilotos);

int controller_ListVuelos(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos);
int controller_findEmployeeByID(LinkedList* pArrayListEmployee, int id);

int controller_saveAsText(char* path , LinkedList* pArrayListVuelos);

//P7
int controller_ListVuelosPortugal(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos);
//P8
int controller_GenerateNewList(LinkedList* pArrayListNew, LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos);
//P9
int controller_ListSinDosPilotos(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos);
#endif /* CONTROLLER_H_ */
