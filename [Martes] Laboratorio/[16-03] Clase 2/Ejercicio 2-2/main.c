/******************************************************************************

Luciano Crocco 1ºF
Ejercicio 2-2

*******************************************************************************/
#include <stdio.h>
#define TAM 10

int main()
{
    int i;
    int numero;
    int contadorPares;
    int contadorImpares;
    int menorNumeroIngresado;
    int mayorNumeroPar;
    int acumuladorPositivos;
    int productoTotalNegativos;
    int acumuladorNegativos;
    int contadorNegativos;

    contadorPares = 0;
    contadorImpares = 0;
    acumuladorPositivos = 0;
    acumuladorNegativos = 0;
    contadorNegativos = 0;

    // CORRECCION, ACLARADO MAS ABAJO
    mayorNumeroPar = 0;

    printf("A continuacion ingrese %d numeros que sean distintos de 0\n", TAM);
    for(i=0;i<TAM;i++){
        printf("Ingrese el %dº numero:",i+1);
        scanf("%d", &numero);

        while(numero == 0){
            printf("Error... Ingrese SOLO numeros distintos a 0.");
            printf("\nIngrese el %dº numero: ",i+1);
            scanf("%d", &numero);
        }
        if(numero % 2 == 0){
            contadorPares++;
            //CORRECION DEL IF, PUEDO SACAR EL ELSE IF AGREGANDO CONDICIONES EN EL PRIMER IF
            if(i==0 || mayorNumeroPar > numero){
                mayorNumeroPar = numero;
            /*} else {
                if(mayorNumeroPar < numero){
                    mayorNumeroPar = numero;
                }*/
            }
        } else {
            contadorImpares++;
        }

        if(i==0){
            menorNumeroIngresado = numero;
        } else {
            if(menorNumeroIngresado > numero) {
                menorNumeroIngresado = numero;
            }
        }

        if(numero > 0){
            acumuladorPositivos += numero;
        } else {
            acumuladorNegativos += numero;
            contadorNegativos++;
        }
    }
    productoTotalNegativos = acumuladorNegativos * contadorNegativos;


    printf("\nLa cantidad de pares es %d.", contadorPares);
    printf("\nLa cantidad de impares es %d.", contadorImpares);
    printf("\nEl menor numero ingresado es %d.", menorNumeroIngresado);

    if(contadorPares != 0){
        printf("\nEl mayor numero par ingresado es %d.", mayorNumeroPar);
    } else {
        printf("\nNo se ingresaron numeros pares.");
    }


    if(acumuladorPositivos != 0){
        printf("\nLa suma de todos los numeros positivos ingresados es: %d.", acumuladorPositivos);
    } else {
        printf("\nNo se ingresaron numeros positivos.");
    }

    if(contadorNegativos == 0){
        printf("\nNo se ingresaron numeros negativos para calcular el producto.");
    } else {
        printf("\nEl total del producto entre los numeros negativos es: %d",productoTotalNegativos);
    }

    return 0;
}
