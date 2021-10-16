/******************************************************************************

Luciano Crocco 1ºF

Realizar el ordenamiento de un vector de enteros. Para ello deberán crear una función que se encargue de realizar el intercambio de valores.

Ejercicio 15-1

******************************************************************************

Lo que se intercambia son los valores locales de la funcion, no los valores del main. Por lo tanto la funcion swap solo sirve en tal y no tiene efecto en el ordenamiento.

Solamente cuando pasamos un vector es posible, ya que pasamos por referencia (no por valor) y el vector es un puntero de por sí.

Todo lo que venimos haciendo hasta ahora se guarda en la pila

Cuando llamamos en la funcion, tanto el main como el swap se ejecutan en la pila. Se crean variables locales en el swap y cuando dejamos de llamarla se desapila y no tiene efecto en main (pasaje por valores).


*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void ordenamientoDeVectoresEnteros(int numeros[], int lenght);
void swap(int x, int y);
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
                swap(numeros[j], numeros[i]);
            }
        }
    }
}

void swap(int x, int y){
    int z;

    z = x;
    x = y;
    y = z;

}

void mostrarNumeros(int numeros[], int lenght){
	int i;

	for(i=0;i<lenght;i++){
        printf("%d\n",numeros[i]);
    }

}




