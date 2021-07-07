/*
 * testing.h
 *
 *  Created on: 14 may. 2021
 *      Author: luciano
 */

#ifndef TESTING_H_
#define TESTING_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define STRING_LENGHT_BUFFER 500

/************************************************************************************************************/
/***************************************************VIEJAS***************************************************/
/************************************************************************************************************/

int menu(int* pResult);
int menuAltas(void);
int pedirFloat(char* mensaje, float* pResultado);
int pedirFloatConRango(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int pedirEntero(char* mensaje, int* pResultado);
int pedirEnteroConRango(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/************************************************************************************************************/
/***************************************************NUEVAS***************************************************/
/************************************************************************************************************/

int get_Char(char* pResult, char* msg, char* errorMsg, char min, char max, int retries);

int get_String(char* pResult, char* msg, char* errorMsg, int retries, int lenght);

int get_Name(char* pResult, char* mensaje, char* mensajeError, int retries, int lenght);

void strlwr(char* string, int len);

void normalizarCadenaAlfabetica(char* string, int len);

int comprobarSoloAlfabetico(char* string, int len);

int get_YesNo(char* pResult, char* msg, char* msgError ,int retries);

int get_Integer(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int check_onlyNumbers(char* string, int len);
int check_overFlowSpaceInt(char* string);

int get_Float(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int check_onlyNumbersFloat(char* string, int len);
int check_overFlowSpaceFloat(char* string);




#endif /* TESTING_H_ */
