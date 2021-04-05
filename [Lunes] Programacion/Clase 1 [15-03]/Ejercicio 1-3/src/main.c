/******************************************************************************

Luciano Crocco 1ºF
Ejercicio 1-3

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int numeroTres;
    int numeroMedio;

    printf("Ingrese el primer numero: ");
    scanf("%d",&numeroUno);

    printf("Ingrese el segundo numero: ");
    scanf("%d",&numeroDos);

    printf("Ingrese el tercer numero: ");
    scanf("%d",&numeroTres);

    if(numeroUno > numeroDos && numeroUno < numeroTres) {
        numeroMedio = numeroUno;
        printf("El numero medio es: %d", numeroMedio);
    } else {
        if (numeroDos > numeroUno && numeroDos < numeroTres){
            numeroMedio = numeroDos;
            printf("El numero medio es: %d", numeroMedio);
        } else {
            if (numeroTres > numeroUno && numeroTres < numeroDos) {
                numeroMedio = numeroTres;
                printf("El numero medio es: %d", numeroMedio);
            } else {
                printf("No hay numero medio");
            }
        }
    }

    return EXIT_SUCCESS;



}
