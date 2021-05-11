/******************************************************************************

Luciano Crocco 1ºF

Realizar el ordenamiento de un vector de enteros. Para ello deberán crear una función que se encargue de realizar el intercambio de valores.

Ejercicio 15-1

******************************************************************************
APUNTES EJERCICIO

Todo lo anterior lo solucionamos utilizando punteros.

La direcion de memoria de un dato de X bytes va a ser el primer BIT que encuentre cuando se guarda en memoria (0x00C0, 0X00C1, 0x... es nuestro dato, la direccion de memoria va a ser el primero).
Para conocer la direccion de memoria de una variable podemos utilizar: printf("%p", &miVariable);

Un puntero es una variable que guarda una direccion de memoria. En principio esa variable va a ser la direccion de memoria de otra variable (nos robamos una direccion del heap).



*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void ordenamientoDeVectoresEnteros(int numeros[], int lenght);
void swap(int* x, int* y);
void mostrarNumeros(int numeros[], int lenght);

int main()
{
    setbuf(stdout,NULL);
    
    int numeros[5]={2,6,1,3,8};
    
    mostrarNumeros(numeros, 5);
    
    puts("\n\n");
    ordenamientoDeVectoresEnteros(numeros, 5);
    
    
    mostrarNumeros(numeros, 5);


    return EXIT_SUCCESS;
}

void ordenamientoDeVectoresEnteros(int numeros[], int lenght){
    int i;
    int j;
    
    for(i=0;i<lenght-1;i++){
        for(j=i+1;j<lenght;j++){
            if(numeros[j] < numeros[i]){
                swap(&numeros[j], &numeros[i]);
            }
        }
    }
}

void swap(int* x, int* y){
    int z;
    
    z = *x;
    *x = *y;
    *y = z;
    
}

void mostrarNumeros(int numeros[], int lenght){
    int i;
    
    for(i=0;i<lenght;i++){
            
        printf("%d\n",numeros[i]);
    }
    
}





