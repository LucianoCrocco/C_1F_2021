/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	setbuf(stdout,NULL);

    int numero;
    int* pInt;
    pInt=&numero;

    printf("%d\n",&numero);
    printf("%d\n",pInt);
    printf("%d\n",pInt+0);
    printf("%d\n",pInt+1);
    printf("%d\n",pInt+2);
    printf("%d\n",pInt+3);

    //Podemos deducir que un array a bajo nivel es un puntero.
    //Cuando hacemos miVector[0], quiere decir que es la direccion de memoria +0 byte (Los byte varian segun el tamaño del dato, en este caso sumarle 1 es sumarle 4 por el tamaño de int)
    //Cuando hacemos miVector[1], quiere decir que es la direccion de memoria +1 byte

    pInt++; //Si incrementamos la funcion, no es lo mismo que el +1, ya que cambiamos la posicion de origen del puntero, en cambio el +1 suma solo una posicion.
    puts("\nLuego del incremento pInt++\n");
    printf("%d\n",pInt+0);
    printf("%d\n",pInt+1);
    printf("%d\n",pInt+2);
    printf("%d\n",pInt+3);

    return EXIT_SUCCESS;
}

