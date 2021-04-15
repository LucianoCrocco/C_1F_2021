/******************************************************************************

Luciano Crocco 1ºF
Ejercicio 2-1

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define TAM 5
#define Y "Hola World"

//El define no ocupa espacio en memoria, la constante si, por eso no es una variable global.


int main()
{
    int i;
    int numero;
    int acumuladorNumeros;
    float promedio;

    setbuf(stdout,NULL);

    acumuladorNumeros = 0;

    printf("%s",Y);
    printf("\nA continuacion ingrese %d numeros\n", TAM);
    for(i=0;i<TAM;i++){
        printf("Ingrese el %dº numero: ",i+1);
        scanf("%d", &numero);
        acumuladorNumeros += numero;
    }

    /*
    Casteo o casting: Convierte un tipo numero a otro tipo numerico (int a float, float a int, int a char, char a int).
    Parsear (en JS): Convierte una cadena (string) a un tipo numero.

    int = int/int
    float = int/float
    float = float/int
    float = float/float

    Implicito o explicito:
    El implicito no lo inidicamos, el explicito sí.
    De bajo nivel: Trabajamos cerca del hardware.
    Puedo perder datos tanto explicitamente como implicitamente
    ej del ejercicio: flot = int / int = X.0000000. (Perdi los decimales por no castear alguno de los dos enteros)

        Ejemplo Implicito:
            int x;
            float y;
            t=2.36;
            x = t;

        Ejemplo Exlicito:
            int x;
            float y;
            t=2.36;
            x = (int) t;

    */

    promedio = (float) acumuladorNumeros / TAM;

    printf("\nEl promedio es: %.2f", promedio);

    EXIT_SUCCESS;
}
