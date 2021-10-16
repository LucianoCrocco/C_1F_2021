/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void cargarVector (int* vector, int tam);

int main()
{
    int numeros[5];//={5,1,8,3,6};
    int* pInt;

    pInt = numeros;
    //pInt = numeros[0]; Las 3 son validas.
    //pInt = &numeros;

    cargarVector(pInt, 5);

    for(int i=0;i<5;i++){
        printf("%d\n", *(pInt+i));
        //printf("%d\n", pInt[i]); //Es valido, pq es como veniamos trabajando un array, Un array es interpretado como un puntero de X cantidad de enteros. Porque un array se representa como una referencia y no un valor.
        //printf("%d\n", *pInt+i); NO, pq va a sumar el primer elemento del array y le suma i
    }
    return EXIT_SUCCESS;
}

void cargarVector (int* vector, int tam){

    for(int i=0;i<5;i++){
        printf("Ingrese un entero: ");
        //scanf("%d", &vector[i]);
        //o
        scanf("%d", vector+i); //Con aritmetica de punteros.
    }

}


