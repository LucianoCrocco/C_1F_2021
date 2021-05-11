/******************************************************************************

Luciano Crocco 1ºF

Realizar el ordenamiento de un vector de enteros. Para ello deberán crear una función que se encargue de realizar el intercambio de valores.

******************************************************************************
APUNTES EJERCICIO 15-1 SIN PUNTEROS
Lo que se intercambia son los valores locales de la funcion, no los valores del main. Por lo tanto la funcion swap solo sirve en tal y no tiene efecto en el ordenamiento.

Solamente cuando pasamos un vector es posible, ya que pasamos por referencia (no por valor) y el vector es un puntero de por sí.

Todo lo que venimos haciendo hasta ahora se guarda en la pila

Cuando llamamos en la funcion, tanto el main como el swap se ejecutan en la pila. Se crean variables locales en el swap y cuando dejamos de llamarla se desapila y no tiene efecto en main (pasaje por valores).

******************************************************************************
APUNTES EJERCICIO 15-1 con punteros

Todo lo anterior lo solucionamos utilizando punteros.

La direcion de memoria de un dato de X bytes va a ser el primer BIT que encuentre cuando se guarda en memoria (0x00C0, 0X00C1, 0x... es nuestro dato, la direccion de memoria va a ser el primero).
Para conocer la direccion de memoria de una variable podemos utilizar: printf("%p", &miVariable);

Un puntero es una variable que guarda una direccion de memoria. En principio esa variable va a ser la direccion de memoria de otra variable (nos robamos una direccion del heap).

Cuando utilizemos memoria dinamica, si no encontro la cantidad de memoria necesaria devolvera NULL, por eso las verificaciones.

Un array es interpretado como un puntero de X cantidad de enteros. Porque un array se representa como una referencia y no un valor.

Un puntero siempre va a pesar lo mismo que un entero.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    setbuf(stdout,NULL);

    int unEntero;
    int* pEntero = NULL; //Todo puntero lo vamos a inicializar en 0. El NULL no es 0, es un concepto que significa "vacio".
    // '*' Operador de indireccion -> Se utiliza para operar sobre punteros y acceder a los valores a los que estos apuntan || Si no apunta a algun lado especifico, va a apuntar a basura (cualquier lado).


    unEntero = 5;

    pEntero =& unEntero; //pENtero apunta a la direccion de memoria de unEntero \\ GUARDA la direccion de memoria de esa variable.
    //Si nos olvidamos de inicializar/apuntar el puntero, el programa puede romperse. A veces puede inicializar el puntero en 0 o NULL, eso puede evitar que rompa.
    //Al inicializarlo en NULL, con una simple verificacion podemos evitar errores a la hora de programar, digamos que es un "practica", como con los contadores..

    if(pEntero != NULL){
        printf("%d\n", unEntero); // Va a mostrar el valor de unEntero.
        printf("%d\n", &unEntero); // Va a mostrar la direccion de memoria de unEntero.
        printf("%d\n\n",pEntero); // Va a mostrar la direccion de memoria, porque es lo que esta guardando esa variable.

        printf("%d\n", *pEntero); // Va a mostrar el valor guardado dentro de la direccion de memoria que apunta mi puntero.
        printf("%d\n", &pEntero); // Va a mostrar el valor de la direccion de memoria de nuestro puntero.
    } else {
        puts("El puntero no apunta a nada.");
    }


    return EXIT_SUCCESS;
}



