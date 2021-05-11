/******************************************************************************

Luciano Crocco 1ºF
Introduccion a Estructuras.

*******************************************************************************/

/*
Podemos definir dos tipos de Variables:
Simples(Escalables): int char void float double
Compuestas:
    Arrays
        Vectores unidimensionales.
        Matrices bidimencionales.

    Estructura: Defino bajo el mismo nombre distintos atributos de distintos tipos. Las estructuras son tipos de datos por valor
*/

#include <stdio_ext.h>
#include <stdlib.h>

typedef struct {

    //campos o atributos
    int legajo;
    int nota1;
    int nota2;
    float promedio;
    char nombre[25];
    char email[60];

}eAlmuno;

void mostrarUnAlumno(eAlmuno);

eAlmuno pedirDatos(void);

int main()
{
    //creacion de una variable de la estructura. Hardcodeo.
    //eAlmuno miAlumno={1000,9,8,8.5,"Juan","Juancitolala@gmai.com"};
    eAlmuno miAlumno;

    setbuf(stdout,NULL);
    miAlumno = pedirDatos();

    mostrarUnAlumno(miAlumno);




    return EXIT_SUCCESS;
}

void mostrarUnAlumno(eAlmuno unAlumno){

    printf("%d %d %d %.2f %s %s",unAlumno.legajo, unAlumno.nota1, unAlumno.nota2, unAlumno.promedio, unAlumno.nombre, unAlumno.email);

}

eAlmuno pedirDatos(void){

    eAlmuno almunoIngresado;

    printf("Ingrese un legajo: ");
    scanf("%d",&almunoIngresado.legajo);

    printf("Ingrese la primer nota: ");
    scanf("%d",&almunoIngresado.nota1);

    printf("Ingrese la segunda nota: ");
    scanf("%d",&almunoIngresado.nota2);

    printf("Ingrese el nombre: ");
    __fpurge(stdin);
    scanf("%[^\n]",almunoIngresado.nombre);

    printf("Ingrese el Email: ");
    __fpurge(stdin);
    scanf("%[^\n]",almunoIngresado.email);

    almunoIngresado.promedio= (float) (almunoIngresado.nota1 + almunoIngresado.nota2) / 2;

    return almunoIngresado;
}
