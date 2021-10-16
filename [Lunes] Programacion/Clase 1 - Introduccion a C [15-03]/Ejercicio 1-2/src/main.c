/******************************************************************************

Luciano Crocco 1ºF
Ejercicio 1-2

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int numero;
    int numeroMaximo;

    printf("A continuacion ingrese 3 numeros\n");

    for(i=0;i<3;i++){
        printf("Ingrese el %dº numero: ",i+1);
        scanf("%d", &numero);

        if(i==0){
            numeroMaximo = numero;
        }

        if(numeroMaximo < numero) {
            numeroMaximo = numero;
        }
    }

    printf("\nEl numero con la mayor denominación ingresado es: %d", numeroMaximo);

    return EXIT_SUCCESS;
}
