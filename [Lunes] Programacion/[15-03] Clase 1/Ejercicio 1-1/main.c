/******************************************************************************

Luciano Crocco 1ºF
Ejercicio 1-1

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int numeroUno;
    int numeroDos;
    int resultado;

    printf("Ingrese el primer numero a sumar: ");
    scanf("%d", &numeroUno);
    printf("Ingrese el segundo numero a sumar: ");
    scanf("%d", &numeroDos);

    resultado = numeroUno + numeroDos;

    printf("El resultado de los numeros sumados es de: %d", resultado);

    return EXIT_SUECCESS;
}
