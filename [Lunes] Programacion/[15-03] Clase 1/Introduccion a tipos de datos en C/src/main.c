#include <stdio_ext.h> //Extension para linux, sirve para el __fpurge(stdin);
#include <stdlib.h>

int main() //Punto de acceso o entry point
{
    int edad;
    char sexo;

    printf("Ingrese la edad: ");
    scanf("%d",&edad); // 1º Mascara de entrada || 2º Direccion de memoria de la variable.

    printf("Ingrese el sexo: ");
    __fpurge(stdin); //Linux
    //fflush(stdin); //Windows
    scanf("%c",&sexo);

    printf("La edad es %d y el sexo es %c", edad, sexo);


    return EXIT_SUCCESS;
}
