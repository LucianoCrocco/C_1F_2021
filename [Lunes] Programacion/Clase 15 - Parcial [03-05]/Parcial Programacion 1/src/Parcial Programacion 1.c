/*
 ============================================================================
 Nombre: Luciano Crocco
 Division: 1ºF
 Profesor: German Scarafilo.
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>

#define STRING_LENGHT 100
#define TAM 2



typedef struct{

	int entero;
	float flotante;
	char caracter;

}eEstructura;

int contadorVocales(char cadena[], int stringLenght);
void sortSimpleEstructura(eEstructura estructura[], int lenght);
void hardcodearEstructura(eEstructura estructura[], int lenght);
void printEstructura(eEstructura estructura[], int lenght);


int main(void) {
	/*
	 * 1. Redactar un párrafo en donde se pueda apreciar la relación que existe entre los siguientes términos:
	 * Función, array, memoria, parámetro formal, parámetro actual, pasaje por valor, variable local.
	 * No serán tomadas como validas las definiciones, sino un relato sobre cómo se relacionan los conceptos. *
	 *----------------------------------------------------------------------------------------------------------------------------------
	 *----------------------------------------------------------------------------------------------------------------------------------
	 * Podemos realizar arrays de tipos de datos (int, char, double, etc), las mismas las podemos "pasar" a una función que reciba esos o mas dato.Al momento de hacer el prototipo de la funcion definiremos sus parametros formales.
	 * Cabe aclarar que las funciones que reciban los tipos de datos anteriormente descriptos solo los podemos pasar como un pasaje de valor, esto quiere decir que al pasarle
	 * el dato a la funcion, ese dato no se vera modificado, sino que se "copia" ese tipo de dato y solo lo podremos modificar dentro de la funcion, siendo asi nuestra "copia" un parametro acutal.
	 *
	 * Una vez llamada nuestra funcion con los parametros actuales, debemos verificar que el array existe en memoria, para ello podemos hacer una simple verificacion
	 * con un if, en el cual corroboraremos que sea DISTINTO de nulo, es decir, nada.
	 *
	 * Una vez dentro de nuestra funcion podremos trabajar con variables locales definidas para el funcionamiento de nuestra funcion,
	 */


	/*
	 * 2. Crear una función que reciba como parámetros una cadena de caracteres.
	 * La función permitirá contar la cantidad de vocales que posee la cadena (un contador por cada vocal).
	 * La función retornara el mayor de los contadores. Utilizar la función en el main. *
	 */

	char cadena[STRING_LENGHT];
	int mayorContador;
	printf("Ingrese un string: ");
	__fpurge(stdin);
	scanf("%[^\n]",cadena);
	mayorContador= contadorVocales(cadena, STRING_LENGHT);
	printf("El mayor de los contadores dio: %d", mayorContador);

	/*
	 * 3. Dada una estructura con un campo entero, otro flotante y un carácter.
	 * Diseñar dicha estructura y realizar una función que permita ordenar un array del tipo de la estructura por un criterio que utilice el carácter.
	 * Utilizar la función en el main. Deberá hardcodear datos. *
	 */
	eEstructura estructura[TAM];
	hardcodearEstructura(estructura,TAM);
	sortSimpleEstructura(estructura,TAM);
	printEstructura(estructura,TAM);




	setbuf(stdout,NULL);
	return EXIT_SUCCESS;
}

int contadorVocales(char cadena[], int stringLenght){
	int i;
	int contadorA;
	int contadorE;
	int contadorI;
	int contadorO;
	int contadorU;

	int retorno;

	contadorA = 0;
	contadorE = 0;
	contadorI = 0;
	contadorO = 0;
	contadorU = 0;

	for(i=0;i<stringLenght;i++){
		if(cadena[i]== 'A' || cadena[i]=='a'){
			contadorA++;
		} else {
			if(cadena[i]== 'E' || cadena[i]=='e'){
				contadorE++;
			} else {
				if(cadena[i]=='I' || cadena[i]=='i'){
					contadorI++;
				} else{
					if(cadena[i]=='O' || cadena[i]=='o'){
						contadorO++;
					} else {
						if(cadena[i]=='U' || cadena[i]=='u'){
							contadorU++;
						}
					}
				}
			}
		}
	}
	if(contadorA > contadorE && contadorA > contadorI && contadorA > contadorO && contadorA > contadorU){
		retorno = contadorA;
	} else {
		if(contadorE > contadorA && contadorE > contadorI && contadorE > contadorO && contadorE > contadorU){
			retorno = contadorE;
		} else {
			if(contadorI > contadorA && contadorI > contadorE && contadorI > contadorO && contadorI > contadorU){
				retorno = contadorI;
			} else {
				if(contadorO > contadorA && contadorO > contadorE && contadorO > contadorI && contadorO > contadorU){
					retorno = contadorO;
				} else {
					retorno = contadorU;
				}
			}
		}
	}
	return retorno;
}

void hardcodearEstructura(eEstructura estructura[], int lenght){
	int i;
	int numeros[2]={1,2};
	char caracteres[2]={'b','a'};
	float flotante[2]={2.5,3.5};

	for(i=0;i<lenght;i++){
		estructura[i].entero=numeros[i];
		estructura[i].caracter=caracteres[i];
		estructura[i].flotante=flotante[i];
	}
}

void sortSimpleEstructura(eEstructura estructura[], int lenght){
	int i;
	int j;

	eEstructura aux;

	for(i=0;i<lenght-1;i++){
		for(j=i+1;j<lenght;j++){
			if(estructura[i].caracter > estructura[j].caracter){
				aux = estructura[i];
				estructura[i]= estructura[j];
				estructura[j]=aux;
			}
		}
	}
}

void printEstructura(eEstructura estructura[], int lenght){
	int i;

	for(i=0;i<lenght;i++){
		printf("\n\nCaracter: %c",estructura[i].caracter);
		printf("\nEntero: %d", estructura[i].entero);
		printf("\nFlotante: %f", estructura[i].flotante);
	}
}
