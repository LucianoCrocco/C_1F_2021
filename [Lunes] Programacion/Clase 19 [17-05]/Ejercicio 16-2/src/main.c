/******************************************************************************

Luciano Crocco 1ºF
Ejercicio 16-2

Realizar una función que reciba como parámetros un array de enteros y un entero por referencia.
La función calculará el valor máximo de ese array y utilizará el valor por referencia para retornar ese valor.

*******************************************************************************/
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

int funcionCalcularMaximo(int* pArrayEntero, int* pEntero);

int main()
{
	int arrayEnteros[5]={1,9,4,2,155};
	int entero = 5;
    setbuf(stdout,NULL);

    if(funcionCalcularMaximo(arrayEnteros,&entero)){
    	printf("El maximo valor del array es: %d", entero);
    } else{
    	puts("Error al cargar datos a la funcion");
    }
    return EXIT_SUCCESS;
}

int funcionCalcularMaximo(int* pArrayEntero, int* pEntero){
	int max;
	int i;

	if(pArrayEntero != NULL && pEntero != NULL){
		for(i=0;i<*pEntero;i++){
			if(i==0){
				max = *(pArrayEntero+i);

			} else {
				if(max < *(pArrayEntero+i)){
					max = *(pArrayEntero+i);
				}
			}
		}
	} else {
		return 0;
	}

	*pEntero = max;

	return 1;
}
