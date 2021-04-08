/******************************************************************************

Luciano Crocco 1ºF
Introduccion a Estructuras.

*******************************************************************************/
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#define T 3
/*
Podemos definir dos tipos de Variables:
Simples(Escalables): int char void float double
Compuestas:
    Arrays
        Vectores unidimensionales.
        Matrices bidimencionales.

    Estructura: Defino bajo el mismo nombre distintos atributos de distintos tipos. Las estructuras son tipos de datos por valor
*/


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
void mostrarTodosLosAlumnos(eAlmuno miAlumno[], int lenght);

void cargarDatos(eAlmuno alumno[], int lenght);
eAlmuno pedirDatos(void);

void ordernarPorLegajo(eAlmuno alumno[], int lenght);


int main()
{
    //creacion de una variable de la estructura. Hardcodeo.
    //eAlmuno miAlumno={1000,9,8,8.5,"Juan","Juancitolala@gmai.com"};
    //eAlmuno miAlumno;

    //miAlumno = pedirDatos();
	setbuf(stdout,NULL);

    eAlmuno listaDeAlumnos[T];//={{100,5,9,7,"Juan","@"},{101,9,8,8.5,"Maria","@"},{103,6,9,7,"Jose","@"}};

    cargarDatos(listaDeAlumnos,T);
    printf("Lista sin ordenar\n\n");
    mostrarTodosLosAlumnos(listaDeAlumnos, T);
    ordernarPorLegajo(listaDeAlumnos,T);
    printf("Lista ordenada por legajo\n\n");
    mostrarTodosLosAlumnos(listaDeAlumnos, T);




    return EXIT_SUCCESS;
}

void mostrarUnAlumno(eAlmuno unAlumno){

    printf("%d %d %d %.2f %s %s",unAlumno.legajo, unAlumno.nota1, unAlumno.nota2, unAlumno.promedio, unAlumno.nombre, unAlumno.email);

}

void mostrarTodosLosAlumnos(eAlmuno miAlumno[], int lenght){
    int i;

    for(i=0;i<lenght;i++){
        mostrarUnAlumno(miAlumno[i]);
        printf("\n");
    }
}

void cargarDatos(eAlmuno alumno[], int lenght){
    int i;

    for(i=0;i<lenght;i++){
        alumno[i] = pedirDatos();
    }
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

void ordernarPorLegajo(eAlmuno alumno[], int lenght){
    int i;
    int j;

    eAlmuno auxiliar;

    for(i=0;i<lenght-1;i++){
        for(j=i+1;j<lenght;j++){
            if(alumno[i].legajo > alumno[j].legajo){
                auxiliar = alumno[i];
                alumno[j] = alumno[i];
                alumno[i] = auxiliar;
            }
        }
    }
}

