#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    //int option = 0;

    //Creacion de lista dinamica de tipo linkedlist
    LinkedList* listaEmpleados = ll_newLinkedList();
    int len;
    listaEmpleados = ll_newLinkedList();//Crea espacio de memoria dinamica en el heap


    Employee* e1;
    Employee* e2;
    Employee* e3;
    Employee* e4;
    Employee* e5;
    int i;
    Employee* aux;

    //Desarrollo de un setter y creacion de un empleado en memoria
    e1 = (Employee*) malloc (sizeof(Employee)); //Es un constructor
    e1->id=1001;
    e1->horasTrabajadas=10;
    e1->sueldo=5000;
    strcpy(e1->nombre,"Pedro");


    e2 = (Employee*) malloc (sizeof(Employee)); //Es un constructor
    e2->id=1002;
    e2->horasTrabajadas=90;
    e2->sueldo=115000;
    strcpy(e2->nombre,"Ana");


    e3 = (Employee*) malloc (sizeof(Employee)); //Es un constructor
    e3->id=1003;
    e3->horasTrabajadas=900;
    e3->sueldo=1000;
    strcpy(e3->nombre,"Ernesto");


    e4 = (Employee*) malloc (sizeof(Employee)); //Es un constructor
    e4->id=1003;
    e4->horasTrabajadas=900;
    e4->sueldo=1000;
    strcpy(e4->nombre,"Maria");


    ll_add(listaEmpleados, e1);
    ll_add(listaEmpleados, e2);
    ll_add(listaEmpleados, e3);
    ll_add(listaEmpleados, e4);


    //test de set_ll, lo utilizariamos para modificar un empleado.
    //
    e5 = (Employee*) malloc (sizeof(Employee)); //Es un constructor
    e5->id=1;
    e5->horasTrabajadas=130;
    e5->sueldo=500;
    strcpy(e5->nombre,"Harry/Mathi");

    //ll_set(listaEmpleados, 1 ,e5);

    //test de ll_push, es como el concepto de pila.
    ll_push(listaEmpleados, 2 ,e5);


    len = ll_len(listaEmpleados);

    printf("Len: %d\n\n", len);

    for(i=0;i<len;i++){
    	aux= (Employee*) ll_get(listaEmpleados, i);
    	printf("%04d%15s%4d%8d\n",aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);//Funcion mostrar empleado
    }

    printf("\nDESPUES DEL ORDENAMIENTO POR NOMBRE\n\n");

    ll_sort(listaEmpleados, employee_compareByName, 1);

    for(i=0;i<len;i++){
    	aux= (Employee*) ll_get(listaEmpleados, i);
    	printf("%04d%15s%4d%8d\n",aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);//Funcion mostrar empleado
    }

    printf("\nDESPUES DEL ORDENAMIENTO POR ID Y CREAR UN CLON\n\n");

    LinkedList* clone;
    clone = ll_clone(listaEmpleados);
    ll_sort(clone, employee_compareById, 0);

    for(i=0;i<len;i++){
    	aux= (Employee*) ll_get(clone, i);
    	printf("%04d%15s%4d%8d\n",aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);//Funcion mostrar empleado
    }


    aux = (Employee*)ll_pop(listaEmpleados, 3);
    printf("\nElimino a: %04d%15s%4d%8d\n",aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);//Funcion mostrar empleado


    int index;

    index = ll_indexOf(listaEmpleados, e3);
    printf("\n\nIndex Empleado e3: %d -- Si es -1 es porque no existe/fue borrado\n\n", index);

    index = ll_indexOf(listaEmpleados, e2);
    printf("Index Empleado e5: %d -- Si es -1 es porque no existe/fue borrado\n\n", index);




    printf("\nUtilizacion del clear - Luego del delete\n");
    ll_clear(listaEmpleados);
    len = ll_len(listaEmpleados);
    printf("Len: %d\n\n", len);

    printf("\nUtilizacion del remove - Luego del remove\n");
    ll_deleteLinkedList(listaEmpleados);
    len = ll_len(listaEmpleados);
    printf("Len: %d\n\n", len);


    /*
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);*/
    return 0;
}


