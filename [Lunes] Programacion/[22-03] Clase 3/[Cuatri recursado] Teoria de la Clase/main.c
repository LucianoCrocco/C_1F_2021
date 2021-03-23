#include <stdio.h>
#include <stdlib.h>

/*
1. Depuracion:
2. Reutilizacion :
3. Independencia de codigo -> Acoplamiento
*/

//prototipo - declaracion - firma
int SumarNumeros(int , int);

int main()
{
    //uso - llamada - invocacion

    int resultado;
    int primerNumero;
    int segundoNumero;

    resultado = SumarNumeros(500,9);//Paramentros actuales
    if(resultado>500)
    {
        printf("Hola a todos...");
    }
    else
    {
        printf("Chau a todos...");
    }



    resultado = SumarNumeros(primerNumero, segundoNumero); //Paramentros actuales
    printf("El resultado es: %d\n", resultado);


    return 0;
}

//Implementacion - desarrollo - Hacer el codigo
int SumarNumeros(int primerNumero, int segundoNumero)//Paramentros formales
{
   int resultado;


   resultado = primerNumero + segundoNumero;

   return resultado;
}
