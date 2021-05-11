/******************************************************************************

Luciano Crocco
Ejercicio 15-2

Realizar una función que reciba como parámetro un puntero a entero. La función le pedirá al usuario que cargue un valor por medio del puntero. Retornara si pudo cargarlo o no.


*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int CargarPuntero(int*);
int MostrarPuntero(int*);
int CargarEntero(int *);

int main(void) {

	setbuf(stdout,NULL);

	int unEntero;

	if(CargarPuntero(&unEntero))
	{
		if(MostrarPuntero(&unEntero)){
			puts("Dato cargado y mostrado correctamente\n");
		} else {
			puts("Error al mostrar el dato...\n");
		}
	} else {
	    puts("Error al cargar el dato...\n");
	}

	return EXIT_SUCCESS;
}

int CargarPuntero(int* pEntero) //Innecesaria xq tengo el cargarEntero
{
	int retorno = -1;

	if(pEntero!=NULL)
	{
		CargarEntero(pEntero);
		retorno = 1;
	}

	return retorno;
}

int MostrarPuntero(int* pEntero)
{
	int retorno = -1;
	if(pEntero!=NULL)
	{
		printf("El valor es: %d\n", *pEntero);
		retorno = 1;
	}

	return retorno;
}

int CargarEntero(int * pEntero){

	int retorno = -1;
	if(pEntero!=NULL)
	{
		printf("Ingrese un entero: ");
		scanf("%d", pEntero);
	}

	return retorno;
}
