/******************************************************************************

Luciano Crocco 1ºF


*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int mostrarPuntero(int*);

int main(void)
{
    setbuf(stdout,NULL);

    int unEntero;

    unEntero = 5;

    if(mostrarPuntero(NULL)){
        puts("El dato se mostro correctamente.\n");
    } else {
        puts("Error al mostrar el dato.\n");
    }

    if(mostrarPuntero(&unEntero)){
        puts("El dato se mostro correctamente.\n");
    } else {
        puts("Error al mostrar el dato.\n");
    }

    return EXIT_SUCCESS;
}

//Los retornos de funciones no pueden ser void, deben devolver algo. Salvo casos de funciones que muestren algo.
int mostrarPuntero(int* pEntero){

    int retorno = -1;

    // Cuando utilizemos memoria dinamica, si no encontro la cantidad de memoria necesaria devolvera NULL, por eso las verificaciones.

    if(pEntero != NULL){
        printf("El valor es: %d\n", *pEntero);
        retorno = 1;
    }

    return retorno;
}

