/*
 * Funciones.c
 *
 *  Created on: 29 mar. 2021
 *      Author: luciano
 */
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

void cargarNumeros(int arrayNumeros[], int tamanio, int min, int max){

	int i;
	int validacion;


	for(i=0;i<tamanio;i++){
		printf("Ingrese el %dº numero, entre los valores %d y %d: ", i+1, min, max);
		scanf("%d",&arrayNumeros[i]);
		if(min != max){
			validacion = validarNumero(arrayNumeros[i], min, max);
			while(validacion == -1){
				printf("Error al validar...\n");
				printf("Ingrese el %dº numero: ", i+1);
				scanf("%d",&arrayNumeros[i]);
				validacion = validarNumero(arrayNumeros[i], min, max);
			}
		}
	}
}

int sumarNumeros(int arrayNumeros[], int tamanio){
	int i;
	int acumulador;

	acumulador = 0;

	for(i=0;i<tamanio;i++){
		acumulador += arrayNumeros[i];
	}

	return acumulador;
}

void mostrarNumeros(int arrayNumeros[], int tamanio){

	int i;

	for(i=0;i<tamanio;i++){
		printf("El numero del vector %d es: %d \n", i, arrayNumeros[i]);
	}
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
//Agregarle un char tipo P o N y desarrollar un switch para achiar las funciones, cambiarle el nombre
int contadorPositivos(int arrayNumeros[], int tamanio){
	int contador;
	int i;

	contador = 0;

	for(i=0;i<tamanio;i++){
		if(arrayNumeros[i] >= 0){
			contador ++;
		}
	}
	return contador;
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

//Agregarle un char tipo P o N y desarrollar un switch para achiar las funciones, cambiarle el nombre
void printContadorNumerosPositivos(int arrayNumeros[], int tamanio){
	int positivos;

	positivos = contadorPositivos(arrayNumeros, tamanio);
	if(positivos != 0){
		printf("La cantidad de numeros positivos es de %d\n", positivos);
	} else {
		printf("No hay numeros positivos\n");
	}
}

void printContadorNumerosNegativos(int arrayNumeros[], int tamanio){
	int negativos;

	negativos = contadorNegativos(arrayNumeros, tamanio);
	if(negativos != 0){
		printf("La cantidad de numeros negativos es de %d\n", negativos);
	} else {
		printf("No hay numeros negativos\n");
	}
}

int sumarNumerosPares(int arrayNumeros[], int tamanio){

	int i;
	int acumulador;
	int validacion;

	acumulador = 0;

	for(i=0;i<tamanio;i++){
		validacion = verificarParidad(arrayNumeros[i], tamanio);
		if(validacion == 0){
			acumulador += arrayNumeros[i];
		}
	}

	return acumulador;
}

int verificarParidad(int numero, int tamanio){
	int validacion;

	validacion = -1;

	if(validacion == -1){
		if(numero % 2 == 0){
			validacion = 0;
		}
	}
	return validacion;
}

void printSumarNumerosPares(int arrayNumeros[], int tamanio){
	int suma;

	suma = sumarNumerosPares(arrayNumeros, tamanio);

	if(suma == 0){
		printf("No se puede hacer la suma de los pares porque no se ingresaron tales.\n");
	} else {
		printf("La suma de los numeros pares es de: %d\n", suma);
	}

}

int calcularNumeroImparMasGrande(int arrayNumeros[], int tamanio){
	int i;
	int numero;

	numero = 2;

	for(i=0;i<tamanio;i++){
		if((arrayNumeros[i] % 2 != 0 && i == 0) || (arrayNumeros[i] % 2 != 0 && (numero == 2 || numero < arrayNumeros[i]))){
			numero = arrayNumeros[i];
		}
	}

	return numero;
}

void printNumeroImparMasGrande(int arrayNumeros[], int tamanio){
	int validacion;

	validacion = calcularNumeroImparMasGrande(arrayNumeros, tamanio);
	if(validacion == 2){
		printf("No se ingresaron numeros Impares\n");
	} else {
		printf("El numero impar mas grande ingresado es: %d\n", validacion);
	}
}

void printNumerosPares(int arrayNumeros[], int tamanio){
	int i;
	int validacion;
	int contador;

	contador = 0;


	for(i=0;i<tamanio;i++){
		validacion = verificarParidad(arrayNumeros[i], tamanio);
		if(validacion == 0){
			contador++;
			printf("%dº numero par: %d\n", contador, arrayNumeros[i]);
		}
	}
	if(contador == 0){
		printf("No hay numeros pares.\n");
	}
}

void printNumerosPosImpares(int arrayNumeros[], int tamanio){
	int i;
	int contador;


	if(tamanio == 1){
		printf("No hay posiciones impares.\n");
	} else {
		for(i=0;i<tamanio;i++){
			if(i % 2 != 0){
				printf("La posicion impar %d tiene el numero: %d\n", i ,arrayNumeros[i]);
				contador++;
			}
		}
	}
}
