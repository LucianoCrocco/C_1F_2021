/******************************************************************************

Luciano Crocco 1ºF
Ejercicio 16-3

Realizar una función que respete el siguiente prototipo:
int Calculador(int, int(*pFunc)(int, int), int, int*);

Dicha función deberá recibir dos operandos y un operador representado mediante la función pasada como parámetro.
El puntero a entero, servirá como parámetro de salida y guardará el resultado de la operación.


*******************************************************************************/
#include <stdio_ext.h>
#include <stdlib.h>

int Calculador(int, int(*pFunc)(int, int), int, int*);
int sumarNumeros(int numeroUno, int numeroDos);
int restarNumeros(int numeroUno, int numeroDos);

int main()
{
	int numeroUno = 20;
	int numeroDos = 7;
	int resultado;
    setbuf(stdout,NULL);

    if(Calculador(numeroUno,sumarNumeros, numeroDos, &resultado)){
    	printf("El resultado de la suma es: %d\n", resultado);
    } else{
    	puts("Error al llamar a la funcion Calculador\n");
    }

    if(Calculador(numeroUno,restarNumeros, numeroDos, &resultado)){
    	printf("El resultado de la resta es: %d\n", resultado);
    } else{
    	puts("Error al llamar a la funcion Calculador\n");
    }
    return EXIT_SUCCESS;
}

int Calculador(int primerOperando, int(*pFunc)(int , int ), int segundoOperando, int* pResultado){

	if(pFunc != NULL && pResultado != NULL){
		*pResultado=pFunc(primerOperando,segundoOperando);
	} else {
		return 0;
	}

	return 1;
}

int sumarNumeros(int numeroUno, int numeroDos){
	int resultado;

	resultado = numeroUno + numeroDos;

	return resultado;
}

int restarNumeros(int numeroUno, int numeroDos){
	int resultado;

	resultado = numeroUno - numeroDos;

	return resultado;
}
