#include <stdio.h>
#include <string.h>
#include "Employee.h"

//Encapsulamiento - Abstraccion - Herencia - Polimorfismo
int employee_compareByName(void* e1, void* e2){//Se castea implicitamente al llamar a la funcion
	int comp;
	//Verificar nulidades, etc.
	//Utilizar los getters y setters
	Employee* emp1;
	Employee* emp2;

	//Unboxing/Desecampsulamiento de algo generico a algo particular
	emp1 = (Employee*) e1;
	emp2 = (Employee*) e2;

	if(strcmp(emp1->nombre,emp2->nombre) > 0){
		comp = 1;
	} else {
		if(strcmp(emp1->nombre,emp2->nombre) < 0){
			comp = -1;
		} else {
			comp = 0;
		}
	}

	return comp;
}


int employee_compareById(void* e1, void* e2){

	int comp;
	//Utilizar los getters y setters
	Employee* emp1;
	Employee* emp2;

	comp = 0;

	emp1 = (Employee*) e1;
	emp2 = (Employee*) e2;

	if(emp1->id > emp2->id){
		comp = 1;
	} else {
		if(emp1->id < emp2->id){
			comp = -1;
		}
	}

	return comp;
}
