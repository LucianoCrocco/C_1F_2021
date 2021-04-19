#include <stdio_ext.h>
#include <string.h>
#include "Funciones.h"


#define MAX_ALUMNOS 2
#define MAX_CADENA 30





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
            	askBajaAlumnos(legajos, notas1, notas2, promedio, nombres, MAX_ALUMNOS);
            	break;
            case 3:
            	askModificarAlumnos(legajos, notas1, notas2, promedio, nombres, MAX_ALUMNOS);
            break;
            case 4:
               MostrarTodosLosAlumnos(legajos, notas1, notas2, promedio, nombres, MAX_ALUMNOS);
            break;
        }
    }while(opcion!=10);

    return 0;
}


