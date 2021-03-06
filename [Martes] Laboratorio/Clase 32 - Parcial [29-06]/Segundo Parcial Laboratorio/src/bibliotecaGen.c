/*
 * testing.c
 *
 *  Created on: 14 may. 2021
 *      Author: luciano
 */


#include <stdio_ext.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <ctype.h>
#include "bibliotecaGen.h"

/************************************************************************************************************/
/***************************************************VIEJAS***************************************************/
/************************************************************************************************************/

/**
 * \brief Menu de opciones
 * \param pResult Puntero de la direccion de memoria de a cambiar
 * \return 0 error 1 bien
 */
int menu(int* pResult){

	if(pResult != NULL){
		printf("\t\t[OPCIONES]\n");

		printf("1. Cargar los datos de los Pilotos (modo texto)\n");
		printf("2. Cargar los datos de los Vuelos (modo texto)\n");
		printf("3. Imprimir vuelos\n");
		printf("4. Cantidad de pasajeros\n");
		printf("5. Cantidad de pasajeros a China.\n");
		printf("6. Crear archivo con vuelos de mas de 5 horas.\n");
		printf("7. Listar vuelos a portugal.\n");
		printf("8. Listar vuelos sin Alex Lifeson y Richard Bach.\n");
		printf("9. Salir.\n");
		if(get_Integer(pResult,"Ingrese una opcion: ", "Error...Ingrese una opcion valida", 1, 9, 5) == 0){
			puts("\nEror al cargar la opcion ingresada\n");
			return 0;
		}
	} else {
		return 0;
	}

	return 1;
}

/**
 * \brief Submenu de altas
 * \return retorna la opcion, en caso de error fuerza la salida
 */
int menuAltas(void){

	int rtn = 3;
	printf("\t\t[OPCIONES]\n");

	printf("1. Alta de empleado\n");
	printf("2. Alta de empleado eliminado\n");
	printf("3. Salir\n");

	if(pedirEnteroConRango(&rtn,"Ingrese una opcion: ", "Error...Ingrese una opcion valida", 1, 3, 5) == 0){
		puts("\nEror al cargar la opcion ingresada\n");
		rtn = 3;
	}


	return rtn;
}

/**
 * \brief  Funcion que permite el ingreso de un dato de tipo flotante
 * \param mensaje
 * \param pResultado
 * \return 1 bien 0 NULL
 */
int pedirFloat(char* mensaje, float* pResultado){

	int rtn;
	rtn = 1;
	if(mensaje != NULL){
		printf("%s",mensaje);
		scanf("%f", pResultado);
	} else {
		return 0;
	}

	return rtn;

}
 /**
   * \brief Funcion que permite el ingreso de un dato de tipo flotante con rangos predeterminados
  * \param pResultado
  * \param mensaje
  * \param mensajeError
  * \param minimo
  * \param maximo
  * \param reintentos
  * \return 1 bien 0 NULL
  */
int pedirFloatConRango(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos){
	float numero;
	int rtn;

	rtn = 0;

	if(mensaje !=NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
		printf("%s",mensaje);
		scanf("%f",&numero);
		while((numero < minimo || numero > maximo) && reintentos >= 0){
			printf("\n%s, reintentos restantes: %d\n\n",mensajeError, reintentos);
			printf("%s",mensaje);
			scanf("%f",&numero);
		}
	} else {
		return 0;
	}

	if((numero >= minimo && numero <= maximo) && reintentos >= 0){
		rtn = 1;
		*pResultado = numero;
	}
	return rtn;

}

/**
 * \brief Funcion que permite el ingreso de un dato de tipo enterno (int).
 * \param mensaje
 * \param pResultado
 * \return 0 error o NULL, 1 bien
 */
int pedirEntero(char* mensaje, int* pResultado){
	int rtn;
	rtn = 1;
	if(mensaje != NULL){
		printf("%s",mensaje);
		scanf("%d", pResultado);
	} else {
		return 0;
	}

	return rtn;

}

/**
 * \brief Funcion que permite el ingreso de un dato de tipo enterno (int) con rangos predeterminados.
 * \param pResultado
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 * \param reintentos
 * \return 0 error o NULL, 1 bien
 */
int pedirEnteroConRango(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int numero;
	int rtn;

	rtn = 0;

	if(mensaje !=NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){
		printf("%s",mensaje);
		scanf("%d",&numero);
		while((numero < minimo || numero > maximo) && reintentos >= 0){
			printf("\n%s, reintentos restantes: %d\n\n",mensajeError, reintentos--);
			printf("%s",mensaje);
			scanf("%d",&numero);
		}
	} else {
		return 0;
	}

	if((numero >= minimo && numero <= maximo) && reintentos >= 0){
		rtn = 1;
		*pResultado = numero;
	}

	return rtn;
}


/************************************************************************************************************/
/***************************************************NUEVAS***************************************************/
/************************************************************************************************************/

/**
 * \brief Funcion que permite el ingreso de un dato de tipo caracter (char) con rangos predeterminados
 * \param pResult
 * \param msg
 * \param errorMsg
 * \param min
 * \param max
 * \param retries
 * \return 0 error o NULL, 1 bien
 */
int get_Char (char* pResult, char* msg, char* errorMsg, char min, char max, int retries){

	int rtn;
	char buffer;

	rtn = 0;

	if(pResult != NULL && msg != NULL && errorMsg != NULL && min <= max && retries >= 0){
		do{
			printf("%s", msg);
			__fpurge(stdin);
			scanf("%c", &buffer);
			if(buffer >= min && buffer <= max){
				*pResult = buffer;
				rtn = 1;
				break;
			} else {
				printf("%s\n", errorMsg);
				printf("Reintentos disponibles: %d\n\n", retries);
				retries--;
			}

		}while(retries >= 0);
	} else {
		puts("NO entro al if\n");
	}

	return rtn;
}

/**
 * \brief Funcion que permite el ingreso de un dato de tipo string con un maximo predeterminado
 * \param pResult
 * \param msg
 * \param errorMsg
 * \param retries
 * \param lenght
 * \return 0 error o NULL, 1 bien
 */
int get_String(char* pResult, char* msg, char* errorMsg, int retries, int lenght){
	int rtn;
	char bufferString[STRING_LENGHT_BUFFER];

	rtn = 0;

	if(pResult != NULL && msg != NULL && errorMsg != NULL && retries >= 0 && lenght > 0){
		do{
			printf("%s", msg);
			__fpurge(stdin);
			scanf("%[^\n]", bufferString);
			if(strlen(bufferString) > lenght-1){
				printf("%s %d\n", errorMsg, lenght-1);
				printf("Reintentos disponibles: %d\n\n", retries);
				retries--;
			} else {
				strcpy(pResult, bufferString);
				rtn = 1;
				break;
			}

		}while(retries >= 0);
	}
	return rtn;
}

/**
 * \brief Funcion que permite el ingreso de un nombre
 * \param pResult
 * \param retries
 * \param lenght
 * \return 0 error o NULL, 1 bien
 */
int get_Name(char* pResult, char* mensaje, char* mensajeError, int retries, int lenght){
	char buffer[STRING_LENGHT_BUFFER];
	int validacion = 0;

	if(lenght > 0 && retries >= 0){
		while(retries >= 0 && validacion == 0){
			validacion = get_String(buffer, mensaje, mensajeError, retries, lenght);
			if(validacion != 0){
				strlwr(buffer, lenght);
				normalizarCadenaAlfabetica(buffer, lenght);
				validacion = comprobarSoloAlfabetico(buffer, lenght);
				if(validacion == 0){
					retries--;
					puts("\nError al comprobar que el nombre posea solo Caracteres Alfabeticos\n");
				} else {
					strcpy(pResult,buffer);
				}
			} else {
				retries--;
			}
		}
	}
	if(retries < 0){
		return 0;
	} else {
		return 1;
	}
}


/**
 * \brief Toma la cadena y hace minusculas todos los caracteres contenidos en el array
 * \param string
 * \param len
 */
void strlwr(char* string, int len){
	int i;


	if(string != NULL && len >= 0){
		for(i=0;i<len;i++){
			if(string[i] == '\0'){
				break;
			} else {
				string[i]=tolower(string[i]);
			}
		}
	}
}

/**
 * \brief Agregar mayusculas en el primer caracter o luego de un espacio
 * \param string
 * \param len
 */
void normalizarCadenaAlfabetica(char* string, int len){
	int i;

	if(string != NULL && len >= 0){
		string[0]=toupper(string[0]);
		for(i=0;i<len;i++){
			if(string[i] == '\0'){
				break;
			} else {
				if(isspace(string[i])){
					string[i+1]=toupper(string[i+1]);
				}
			}
		}
	}
}

/**
 * \brief Comprueba si la cadena contiene solo letras del alfabeto
 * \param string
 * \param len
 * \return 0 NULL o error, 1 bien
 */
int comprobarSoloAlfabetico(char* string, int len){
	int i;
	int rtn;
	rtn = 0;

	if(string != NULL && len >= 0){
		for(i=0;i<len;i++){
			if(string[0] == '\0' || isspace(string[0])){
				rtn = 0;
				break;
			} else {
				if(string[i] == '\0'){
					rtn = 1;
					break;
				} else {
					if((string[i] > 'z' || string[i] < 'a') && (string[i] > 'Z' || string[i] < 'A') && !(isspace(string[i]))){
						break;
					}
				}
			}
		}
	}
	return rtn;
}


/**
 * \brief Funcion que pide un Si o No como respuestas
 * \param pResult
 * \param msg
 * \param msgError
 * \param retries
 * \return 0 error o NULL, 1 BIEN
 */
int get_YesNo(char* pResult, char* msg, char* msgError ,int retries){

	char caracter;

	if(pResult != NULL && msg != NULL && retries >= 0){

		get_Char(&caracter, msg, "Ingrese un caracter valido: ", 32, 122, retries);
		caracter=toupper(caracter);

		if(caracter != 'S' && caracter != 'N'){
			while(retries >= 0){
				retries--;
				printf("\n%s\n\n",msgError);
				get_Char(&caracter, msg, "Ingrese un caracter valido: ", 32, 122, retries);
				caracter=toupper(caracter);
				if(caracter == 'S' && caracter == 'N'){
					break;
				}
			}

		}
	} else {
		return 0;
	}

	if(retries >= 0){
		*pResult=caracter;
		return 1;
	} else {
		return 0;
	}
}



/**
 * \brief	Funcion que permite el ingreso de un dato de tipo enterno (int) con rangos predeterminados
 * \param pResultado
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 * \param reintentos
 * \return 1 bien 0 Error o NULL
 */
int get_Integer(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){

	int rtn = 0;
	int numero;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos > -1){
		int validacion = 0;
		char buffer[STRING_LENGHT_BUFFER];

		while(reintentos > 0 && validacion == 0){
			validacion = get_String(buffer, mensaje, mensajeError, reintentos, STRING_LENGHT_BUFFER);
			if(validacion != 0){
				validacion = check_onlyNumbers(buffer, STRING_LENGHT_BUFFER);
				if(validacion == 0){
					reintentos--;
					printf("\n%s ingrese solamente caracteres numericos, reintentos restantes: %d\n", mensajeError,reintentos);
				} else {
					validacion = check_overFlowSpaceInt(buffer);
					if(validacion == 0){
						reintentos--;
						printf("\n%s se excedio el limite de memoria para un entero, reintentos restantes: %d\n", mensajeError,reintentos);
					} else {
						numero = atoi(buffer);
						if(numero < minimo){
							printf("%s Ingreso un numero menor al minimo\n, reintentos restantes: %d", mensajeError, reintentos);
							reintentos--;
							validacion = 0;
						} else {
							if(numero > maximo){
								printf("%s Ingreso un numero mayor al maximo, reintentos restantes: %d\n", mensajeError, reintentos);
								reintentos --;
								validacion = 0;
							} else {
								*pResultado = numero;
								rtn = 1;
								validacion = 1;
							}
						}
					}
				}
			} else {
				reintentos--;
			}
		}
	}
	return rtn;
}

/**
 * \brief Chequea que el entero ingresado no desborde la capicidad de un INT.
 * \param string
 * \return 1 bien 0 NULL o error.
 */
int check_overFlowSpaceInt(char* string){
	int rtn = 1;
	char buffer[STRING_LENGHT_BUFFER];
	int i;

	if(string !=NULL){

		if(string[0] == '-'){
			sprintf(buffer, "%d", INT_MIN);
			int srtlenBuffer = strlen(buffer);
			int srtlenString = strlen(string);
			if(srtlenString > srtlenBuffer){
				rtn = 0;
			} else {
				if(srtlenBuffer == srtlenString){
					for(i=0;i<srtlenBuffer;i++){
						if(string[i] > buffer[i]){
							rtn = 0;
							break;
						}
					}
				}
			}

		} else {
			sprintf(buffer, "%d", INT_MAX);
			int srtlenBuffer = strlen(buffer);
			int srtlenString = strlen(string);

			if(srtlenString > srtlenBuffer){
				rtn = 0;
			} else {
				if(srtlenBuffer == srtlenString){
					for(i=0;i<srtlenBuffer;i++){
						if(string[i] > buffer[i]){
							rtn = 0;
							break;
						}
					}
				}
			}
		}
	}

	return rtn;
}


/**
 * \brief Verifica que solo se hayan ingresado numeros o '-' o '+' en la primera posicion del string
 * \param string
 * \param len
 * \return 1 bien, 0 NULL o error
 */
int check_onlyNumbers(char* string, int len){
	int i;
	int rtn = 0;
	int flag = 0;
	int flagNumero = 0;

	if(string != NULL && len > -1){
		for(i=0;i<len;i++){
			if(string[i] == '\0'){
				rtn = 1;
				break;
			} else {
				if((string[0] == '+' || string[0] == '-') && flag == 0){
					flag++;
				} else {
					if((string[i] < '0' || string[i] > '9')){
						return 0;
					} else {
						flagNumero++;
					}
				}
			}
		}
	}

	if(flag == 1 && flagNumero == 0){
		rtn = 0;
	} else {
		if(flagNumero == 0){
			rtn = 0;
		}
	}
	return rtn;
}


/**
 * \brief Funcion que permite el ingreso de un dato de tipo flotante con rangos predeterminados.
 * \param pResultado
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 * \param reintentos
 * \return 1 bien 0 error o NULL
 */
int get_Float(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos){

	int rtn = 0;
	float numero;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos > -1){
		int validacion = 0;
		char buffer[STRING_LENGHT_BUFFER];

		while(reintentos > 0 && validacion == 0){
			validacion = get_String(buffer, mensaje, mensajeError, reintentos, STRING_LENGHT_BUFFER);
			if(validacion != 0){
				validacion = check_onlyNumbersFloat(buffer, STRING_LENGHT_BUFFER);
				if(validacion == 0){
					reintentos--;
					printf("\n%s ingrese solamente caracteres numericos, reintentos restantes: %d\n", mensajeError,reintentos);
				} else {
					validacion = check_overFlowSpaceFloat(buffer);
					if(validacion == 0){
						reintentos--;
						printf("\n%s se excedio el limite de memoria para un flotante, reintentos restantes: %d\n", mensajeError,reintentos);
					} else {
						numero = atof(buffer);
						if(numero < minimo){
							printf("%s Ingreso un numero menor al minimo, reintentos restantes: %d\n", mensajeError, reintentos);
							reintentos--;
							validacion = 0;
						} else {
							if(numero > maximo){
								printf("%s Ingreso un numero mayor al maximo, reintentos restantes: %d\n", mensajeError, reintentos);
								reintentos --;
								validacion = 0;
							} else {
								*pResultado = numero;
								rtn = 1;
								validacion = 1;
							}
						}
					}
				}
			} else {
				reintentos--;
			}
		}
	}
	return rtn;
}

/**
 * \brief Verifica que solo se hayan ingresado numeros y '.' (una sola vez) o '-', '+' en la primera posicion del string
 * \param string
 * \param len
 * \return 1 bien 0 NULL o error
 */
int check_onlyNumbersFloat(char* string, int len){
	int i;
	int rtn = 0;
	int flag = 0;
	int flagNumero = 0;
	int flagPunto = 0;

	if(string != NULL && len > -1){
		for(i=0;i<len;i++){
			if(string[i] == '\0'){
				rtn = 1;
				break;
			} else {
				if((string[0] == '+' || string[0] == '-') && flag == 0){
					flag++;
				} else {
					if((string[i] < '0' || string[i] > '9') && string[i] != '.'){
						return 0;
					} else {
						flagNumero++;
					}
					if(string[i] == '.'){
						flagPunto++;
					}
				}
			}
		}
	}
	if(flag == 1 && flagNumero == 0){
		rtn = 0;
	} else if (flagPunto > 1){
		rtn = 0;
	} else if (flagNumero == 0){
		rtn = 0;
	}
	return rtn;
}

/**
 * \brief Chequea que el flotante ingresado no desborde la capicidad de un FLOAT.
 * \param string
 * \return 1 bien, 0 NULL o error.
 */
int check_overFlowSpaceFloat(char* string){
	int rtn = 1;
	char buffer[STRING_LENGHT_BUFFER];
	int i;

	if(string !=NULL){
		sprintf(buffer, "%f", FLT_MAX);
		int srtlenBuffer = strlen(buffer);
		int srtlenString = strlen(string);

		if(srtlenString > srtlenBuffer){
			rtn = 0;
		} else {
			if(srtlenBuffer == srtlenString){
				for(i=0;i<srtlenBuffer;i++){
					if(string[i] > buffer[i]){
						rtn = 0;
						break;
					}
				}
			}
		}
	}

	return rtn;
}

