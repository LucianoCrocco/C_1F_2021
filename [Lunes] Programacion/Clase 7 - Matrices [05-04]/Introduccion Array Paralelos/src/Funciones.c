/*
 * Funciones.c
 *
 *  Created on: 18 abr. 2021
 *      Author: luciano
 */

#include <stdio_ext.h>
#include <string.h>
#include "Funciones.h"

void InicializarAlumnos(int legajos[], int tam)
{
     int i;

    for(i=0; i<tam; i++)
    {
        legajos[i] = -1;
    }
}

int BuscarLibre(int legajos[], int tam)
{
    int i;
    int index;

    index = -1;

    for(i=0; i<tam; i++)
    {
        if(legajos[i]==-1)//encontre espacio libre
        {
            index = i;
            break;
        }
    }

    return index;
}

void MostrarUnAlumno(int legajo, float nota1, float nota2, float promedio, char nombre[])
{
     printf("%d -- %f -- %f -- %f -- %s\n", legajo, nota1, nota2, promedio, nombre);
}

void MostrarTodosLosAlumnos(int legajos[], float notas1[], float notas2[], float promedios[], char nombres[][30], int tam)
{
    int i;
    for(i=0; i<MAX_ALUMNOS; i++)
    {
        if(legajos[i]!=-1)
        {
            MostrarUnAlumno(legajos[i], notas1[i], notas2[i], promedios[i], nombres[i]);
        }

    }
}

int CargarUnAlumno(int legajos[], float notas1[], float notas2[], float promedios[], char nombres[][30], int tam)
{
    int index;
    index = BuscarLibre(legajos, tam);
    if(index!=-1)//encontro espacio
    {
        printf("Ingrese legajo: ");
		scanf("%d", &legajos[index]);

		printf("Ingrese nombre: ");
		__fpurge(stdin);
		scanf("%[^\n]",nombres[index]);

		printf("Ingrese nota 1: ");
		scanf("%f", &notas1[index]);

		printf("Ingrese nota 2: ");
		scanf("%f", &notas2[index]);

		//calcular el promedio
		promedios[index] = notas1[index] / notas2[index];

		index = 0;
    }

    return index;
}

void askModificarAlumnos(int legajos[], float notas1[], float notas2[], float promedios[], char nombres[][30], int tam){

	int legajo;
	int validacion;

	printf("Ingrese el legajo del alumno a modificar: ");
	scanf("%d",&legajo);
	validacion=buscarLegajo(legajos,legajo,tam);
	if(validacion == -1){
		printf("No se encontro el legajo a modificar. \n");
	} else {
		modificarUnLegajo(validacion, notas1, notas2, promedios, nombres);
	}
}

int buscarLegajo(int legajos[], int legajoABuscar, int tam){

	int retorno;
	int i;

	retorno = -1;

	for(i=0;i<tam;i++){
		if(legajos[i]==legajoABuscar){
			retorno = i;
			break;
		}
	}

	return retorno;
}

void modificarUnLegajo(int posicion, float notas1[], float notas2[], float promedios[], char nombres[][30]){

	printf("Ingrese nombre: ");
	__fpurge(stdin);
	scanf("%[^\n]",nombres[posicion]);

	printf("Ingrese nota 1: ");
	scanf("%f", &notas1[posicion]);

	printf("Ingrese nota 2: ");
	scanf("%f", &notas2[posicion]);

	promedios[posicion] = notas1[posicion] / notas2[posicion];
}

void askBajaAlumnos(int legajos[], float notas1[], float notas2[], float promedios[], char nombres[][30], int tam){

	int legajo;
	int validacion;

	printf("Ingrese el legajo del alumno a dar de baja: ");
	scanf("%d",&legajo);

	validacion=buscarLegajo(legajos,legajo,tam);
	if(validacion == -1){
		printf("No se encontro el legajo de la persona a dar de baja. \n");
	} else {
		legajos[validacion] = -1;
	}
}
