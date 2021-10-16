/*
 * Funciones.c
 *
 *  Created on: 29 mar. 2021
 *      Author: luciano
 */
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

void inicializarArray(int arrayNumeros[], int tamanio, int valor){
	int i;

	for(i=0;i<tamanio;i++){
		arrayNumeros[i]=valor;
	}
}

int pedirPosicion(char mensaje[], char mensajeError[], int arrayNumeros[], int tamanio){
	int posicion;
	int validacion;


	printf("%s %d posiciones: ", mensaje, tamanio);
	scanf("%d", &posicion);
	posicion--;
	validacion = validarNumero(posicion, 0, 9);
	while(validacion == -1){
		printf("%s\n %s %d posiciones: ", mensajeError, mensaje, tamanio);
		scanf("%d", &posicion);
		posicion--;
		validacion = validarNumero(posicion, 0, 9);
	}

	return posicion;
}

int validarNumero(int numero, int min, int max){
	int validacion;

	validacion = 0;

	if(validacion == 0){
		if(numero < min || numero > max){
			validacion = -1;
		}
	}
	return validacion;
}

int pedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo){
	int x;

	printf("%s",mensaje);
	scanf("%d",&x);
	if(maximo != minimo){
		while(x>maximo || x<minimo){
			printf("%s",mensajeError);
			printf("\n%s",mensaje);
			scanf("%d",&x);
		}
	}

	return x;
}

void cargarNumeroArray(int arrayNumeros[], int tamanio, int numero, int posicion){
	int i;

	for(i=0;i<tamanio;i++){
		if(i==posicion){
			arrayNumeros[i]=numero;
			printf("Numero %d en la posicion %d cargados correctamente \n", numero, posicion+1);
			break;
		}
	}
}

int sumarPosONeg(int arrayNumeros[], int tamanio, char tipo){
	int i;
	int acumulador;

	acumulador = 0;

	switch (tipo){
		case 'P':
			for(i=0;i<tamanio;i++){
				if(arrayNumeros[i] > 0){
					acumulador += arrayNumeros[i];
				}
			}
			break;
		case 'N':
			for(i=0;i<tamanio;i++){
				if(arrayNumeros[i] < 0){
					acumulador += arrayNumeros[i];
				}
			}
			break;
	}

	return acumulador;
}

int promediarPositivos(int arrayNumeros[], int tamanio){
	int i;
	int positivos;
	int cantidad;
	int resultado;

	cantidad = 0;


	positivos = sumarPosONeg(arrayNumeros, tamanio, 'P');
	if(positivos == 0){
		resultado = 0;
	} else {
		for(i=0;i<tamanio;i++){
			if(arrayNumeros[i] > 0){
				cantidad++;
			}
		}
	}

	if(cantidad != 0){
		resultado = positivos / cantidad;
	}

	return resultado;
}

void printSumaPositivos(int arrayNumeros[], int tamanio){
	int resultado;

	resultado = promediarPositivos(arrayNumeros, tamanio);

	if(resultado != 0){
		printf("El promedio de los positivos es de: %d\n", resultado);
	} else {
		printf("No se ingresaron numeros positivos.\n");
	}
}

int contadorNegativos(int arrayNumeros[], int tamanio){
	int contador;
	int i;

	contador = 0;

	for(i=0;i<tamanio;i++){
		if(arrayNumeros[i] < 0){
			contador ++;
		}
	}
	return contador;
}

int primerNumeroNegativo(int arrayNumeros[], int tamanio){
	int validacion;
	int i;
	int numero;

	numero = 0;

	validacion = contadorNegativos(arrayNumeros, tamanio);
	if(validacion == 0){
		numero = 0;
	} else {
		for(i=0;i<tamanio;i++){
			if(arrayNumeros[i] < numero){
				numero = arrayNumeros[i];
			}
		}
	}
	return numero;
}

int sumarNegAntecesores(int arrayNumeros[], int tamanio){
	int numero;
	int acumulador;
	int i;

	acumulador = 0;

	numero = primerNumeroNegativo(arrayNumeros, tamanio);

	if(numero != 0){
		for(i=numero;i==0; i++){
			acumulador += numero+i;
		}
	}

	return acumulador;
}

void printsumaNegAntecesores(int arrayNumeros[], int tamanio){
	int resultado;

	resultado = sumarNegAntecesores(arrayNumeros, tamanio);

	if(resultado == 0){
		printf("No se ingresaron numeros negativos\n");
	} else {
		printf("El resultado de la suma del menor de los negativos y sus antecesores es: %d\n", resultado);
	}
}
