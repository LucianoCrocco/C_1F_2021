/******************************************************************************

Luciano Crocco 1ºF
Ejercicio 2-3

*******************************************************************************/
#include <stdio_ext.h>
#include <ctype.h>

#define PRECIO_VIAJE 600
#define DESCUENTO 25



int main()
{
    int cantidadDePasajeros;
    int idCliente;
    char sexo;
    char estadoCivil;
    int edad;
    int temperaturaCorporal;
    int contadorViudos;
    int auxEdadMujerJoven;
    int auxIdClienteMujerJoven;
    int contadorMujeres;
    int precioTotal;
    int contadorMayores;
    float auxCantidadPasajeros;
    float precioTotalConDescuento;
    float auxCalcularDescuento;

    int i;

    contadorViudos = 0;
    contadorMujeres = 0;
    contadorMayores = 0;

    printf("Bienvenido a FlechaPlus! A continuacion ingrese la cantidad de pasajes que desea comprar, solo para mayores de 17 años: ");
    scanf("%d",&cantidadDePasajeros);
    while(cantidadDePasajeros <= 0 || cantidadDePasajeros > 100){
        printf("Error... el minimo a comprar es 1, el maximo 100");
        printf("\nIngrese la cantidad de pasajeros que viajarán: ");
        scanf("%d",&cantidadDePasajeros);
    }

    printf("\nLa cantidad de pasajes comprados es correcta, a continuacion ingrese los datos de cada pasajero: ");
    for(i=0;i<cantidadDePasajeros;i++){

        printf("\nIngrese el numero (ID) de cliente: ");
        scanf("%d",&idCliente);
        while(idCliente <= 0){
            printf("Error... Ingrese un ID de cliente valido");
            printf("\nIngrese el numero (ID) de cliente: ");
            scanf("%d",&idCliente);
        }

        printf("Ingrese el sexo del pasajero: \"M\" masculino - \"F\" Femenino - \"O\" No binario: ");
        __fpurge(stdin);
        scanf("%c",&sexo);
        sexo = toupper(sexo);
        while(sexo != 'F' && sexo != 'M' && sexo != 'O'){
            printf("Error... Ingrese un sexo valido");
            printf("\nIngrese el sexo del pasajero: \"M\" masculino - \"F\" Femenino - \"O\" No binario: ");
            __fpurge(stdin);
            scanf("%c",&sexo);
            sexo = toupper(sexo);
        }

        printf("Ingrese el estado civil del pasajero: \"S\" Soltero - \"C\" Casado - \"V\" Viudo: ");
        __fpurge(stdin);
        scanf("%c",&estadoCivil);
        estadoCivil = toupper(estadoCivil);
        while(estadoCivil != 'S' && estadoCivil != 'C' && estadoCivil != 'V'){
            printf("Error... Ingrese un estado civil valido");
            printf("\nIngrese el estado civil del pasajero: \"S\" Soltero - \"C\" Casado - \"V\" Viudo: ");
            __fpurge(stdin);
            scanf("%c",&estadoCivil);
            estadoCivil = toupper(estadoCivil);
        }

        printf("Ingrese la edad del pasajero: ");
        scanf("%d",&edad);
        while(edad < 18 || edad > 100) {
            printf("Error.. Ingrese una edad valida.");
            printf("\nIngrese la edad del pasajero: ");
            scanf("%d",&edad);
        }

        printf("Ingrese la temperatura corporal del pasajero: ");
        scanf("%d",&temperaturaCorporal);
        while(temperaturaCorporal<35 || temperaturaCorporal >42){
            printf("Error.. Ingrese una temperatura valida.");
            printf("\nIngrese la temperatura corporal del pasajero: ");
            scanf("%d",&temperaturaCorporal);
        }

        if(estadoCivil == 'V' && edad >= 60){
            contadorViudos++;
        }

        if(sexo == 'F'){
            contadorMujeres++;
        }
        //EJERCICIO 2-2, LA MISMA CORRECION PUEDE SER APLICADA ACA.
        if(i==0 && sexo == 'F'){
            auxEdadMujerJoven = edad;
            auxIdClienteMujerJoven = idCliente;
        } else {
            if(sexo == 'F' && auxEdadMujerJoven < edad) {
                auxEdadMujerJoven = edad;
                auxIdClienteMujerJoven = idCliente;
            }
        }
        if(edad>=60){
            contadorMayores++;
        }
    }

    precioTotal = cantidadDePasajeros * PRECIO_VIAJE;

    auxCantidadPasajeros = (float) cantidadDePasajeros / 2;

    if(contadorViudos == 0){
        printf("\nNo viajan viudos mayores a 60 años");
    } else {
        printf("\nLa cantidad de viudos mayores de 60 años es de: %d", contadorViudos);
    }

    if(contadorMujeres==0){
        printf("\nNo viajan mujeres");
    } else{
        printf("\nLa mujer mas joven tiene: %d años y su numero de cliente es: %d", auxEdadMujerJoven, auxIdClienteMujerJoven);
    }

    printf("\nEl precio total sin descuento es de: %d",precioTotal);

    if(auxCantidadPasajeros > contadorMayores){
        printf("\nNo hay 25 porciento de descuento al no tener un 50 porciento o mas de pasajeros mayores a 60");
    } else {
        auxCalcularDescuento = (float) precioTotal * DESCUENTO / 100;
        precioTotalConDescuento = (float) precioTotal - auxCalcularDescuento;
        printf("\nHay 25 porciento de descuento al tener un 50 porciento o mas de pasajeros mayores a 60. El precio total con descuento es de: %.2f ", precioTotalConDescuento);
    }


    return 0;
}
