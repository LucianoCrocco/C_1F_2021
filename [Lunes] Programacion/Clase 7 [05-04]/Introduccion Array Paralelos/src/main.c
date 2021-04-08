#include <stdio_ext.h>
#include <string.h>

#define MAX_ALUMNOS 2
#define MAX_CADENA 30

void InicializarAlumnos(int[], int);

int BuscarLibre(int[], int);

void MostrarUnAlumno(int, float, float, float, char[]);

void MostrarTodosLosAlumnos(int[], float[], float[], float[], char[][30], int);

/*-1 si no encontro espacio disponible */

int CargarUnAlumno(int[], float[], float[], float[], char[][30], int);

int main()
{
    int legajos[MAX_ALUMNOS];// = {1000, 1004, 1100};
	float notas1[MAX_ALUMNOS];//  = {10, 5.5, 7.5};
	float notas2[MAX_ALUMNOS];//  = {5, 10, 5.5};
	float promedio[MAX_ALUMNOS];

	//char nombres[FILAS][COLUMNAS];
	char nombres[MAX_ALUMNOS][MAX_CADENA];//  = {"Juan", "Pepe", "Ana"};
    int opcion;
    int index;

    InicializarAlumnos(legajos, MAX_ALUMNOS);

    do
    {
        printf("1. ALTA\n");
        printf("2. BAJA\n");
        printf("3. MODIFICACION\n");
        printf("4. ORDENAR y MOSTRAR\n");
        printf("10. Salir\n");
        printf("Elija una opcion:");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:

            	index = CargarUnAlumno(legajos, notas1, notas2, promedio, nombres, MAX_ALUMNOS);
	            if(index==-1)
	            {
	                printf("No hay espacio disponible en la lista...");
	            }
	            else
	            {
	                printf("Alumno cargado con exito!!!");
	            }

            break;
            case 2:

            case 3:

            break;
            case 4:
               MostrarTodosLosAlumnos(legajos, notas1, notas2, promedio, nombres, MAX_ALUMNOS);
            break;
        }
    }while(opcion!=10);

    return 0;
}

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

		printf("Ingrese nota 1: ");
		scanf("%f", &notas1[index]);

		printf("Ingrese nota 2: ");
		scanf("%f", &notas2[index]);

		printf("Ingrese nombre: ");
		__fpurge(stdin);
		scanf("%[^\n]",nombres[index]);

		//calcular el promedio
		index = 0;
    }

    return index;
}

