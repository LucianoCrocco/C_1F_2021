/*
 * Templates.h
 *
 *  Created on: 15 abr. 2021
 *      Author: luciano
 */

#ifndef TEMPLATES_H_
#define TEMPLATES_H_

/************************************************************************************************************/
/************************************************MACROS UTILES***********************************************/
/************************************************************************************************************/
//		ESPACIO
#define VACIO 0
#define OCUPADO -1
#define STRING_LENGHT 100 // lenght de mi string.

/************************************************************************************************************/
/*******************************************FUNCIONES QUE CALCULAN*******************************************/
/************************************************************************************************************/

/**
 * @brief Funcion que calcula el factorial de un dato tipo int y retrona el resultado de la funcion una vez desapilada la funcion.
 *
 * @param x El valor a calcular.
 * @return Retorna el valor del resultado.
 */
int calcularFactorial(int x);

/**
 * @brief Funcion que suma dos valores de tipo flotante y retorna el resultado de los mismo.
 *
 * @param x El primer valor que se calcula.
 * @param y El segundo valor que se calcula
 * @return Retorna el dato float calculado.
 */
float sumarNumerosFloat(float x, float y);

/**
 * @brief Funcion que resta dos valores de tipo flotante y retorna el resultado de los mismo.
 *
 * @param x El primer valor que se calcula.
 * @param y El segundo valor que se calcula
 * @return Retorna el dato float calculado.
 */
float restarNumerosFloat(float x, float y);

/**
 * @brief Funcion que divide dos valores de tipo flotante y retorna el resultado de los mismo.
 *
 * @param x El primer valor que se calcula.
 * @param y El segundo valor que se calcula
 * @return Retorna el dato float calculado.
 */
float dividirNumerosFloat(float x, float y);

/**
 * @brief Funcion que multiplica dos valores de tipo flotante y retorna el resultado de los mismo.
 *
 * @param x El primer valor que se calcula.
 * @param y El segundo valor que se calcula
 * @return Retorna el dato float calculado.
 */
float multiplicarNumerosFloat(float x, float y);


int generar_ID(int indexGenerado, int numeroInicializador);

/************************************************************************************************************/
/***********************************************PEDIR FUNCIONES**********************************************/
/************************************************************************************************************/

/**
 * @brief Funcion que permite el ingreso de un dato de tipo flotante.
 *
 * @param mensaje Es un string que muestra un mensaje.
 * @return Retorna el dato float ingresado.
 */
float pedirFloat(char mensaje[]);

/**
 * @brief Funcion que permite el ingreso de un dato de tipo flotante con rangos predeterminados.
 *
 * @param mensaje Es un string que muestra un mensaje.
 * @return Retorna el dato float ingresado.
 */
float pedirFloatConRango(char mensaje[], char mensajeError[], float minimo, float maximo);

/**
 * @brief Funcion que permite el ingreso de un dato de tipo enterno (int).
 *
 * @param mensaje Es un string que muestra un mensaje.
 * @return Retorna el dato int ingresado.
 */
int pedirEntero(char mensaje[]);

/**
 * @brief Funcion que permite el ingreso de un dato de tipo enterno (int) con rangos predeterminados.
 *
 * @param mensaje Es un string que muestra un mensaje.
 * @return Retorna el dato int ingresado.
 */
int pedirEnteroConRango(char mensaje[], char mensajeError[], int minimo, int maximo);


/************************************************************************************************************/
/************************************************VALIDACIONES************************************************/
/************************************************************************************************************/

/**
 * @brief Recibe un numero flotante, se lo convierte a un dato de tipo string con la funcion "sprintf",
 * la misma funcion devolverá la longitud del dato para que no reconozca valores basuras en caso de pasarse con la longitud del string.
 * Una vez devuelto el dato se calcula con un for en longitud-1 (para no calcular el '\0') y calcula si encuentra datos del 1 hasta el 9.
 * Si encuentra un numero rompe y retorna -1, si llega hasta char '.' rompe y retorna 1
 *
 * @param numero El numero a convertir y comprobar
 * @return Retorna 1 si llego hasta el char '.', comprobando si es un numero natural. De lo contrario devuelve -1.
 */
int comprobarEsNaturalFloat(float numero);

/**
 * @brief Comprueba si un numero de tipo INT se repite en una estructura
 *
 * @param lista Recibe el array de la estructura
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array
 * @param numero El numero que desea comparar para saber si se repite
 * @return Si no se repite retorna 1, si se repite retorna -1.
 */
int comprobarNoRepiteInt(eEstrutura lista[], int lenghtArray ,int numero);

/************************************************************************************************************/
/**************************************************UTILIDADES************************************************/
/************************************************************************************************************/

/**
 * @brief Funcion que desplega las opciones del menu.
 *
 * @return retorna un dato de tipo int con la opcion ingresada.
 */
int menu(void);

/************************************************************************************************************/
/**********************************************ESTRUCTURA UNICA**********************************************/
/************************************************************************************************************/

/**
 * @brief Hardcodea los datos de una unica estructura
 *
 * @param lista Recibe el array de la estructura
 */
void hardocodearDatosUnaStruct/*EL nombre puede variar despues de DATOS*/(eEstructura lista[]);

/**
 * @brief Muestra el listado completo de una estrucutra
 *
 * @param lista Recibe el array de la estructura
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array
 */
void mostrarListadoEstructura(eEstructura  lista[], int lenghtArray);

/**
 * @brief Muestra un solo elemento de la estrucutura
 *
 * @param unElemento La posicion del array en particular del elemento que se desea mostrar
 */
void mostrarUnElementoEstructura(eEstructura unElemento);

/**
 * @brief Inicializa los datos por default de la estructura para que todos esten vacios, estandarizamos isEmpty como referencia a VACIO u OCUPADO
 *
 * @param lista Recibe el array de la estructura
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array
 */
void inicializarIsEmptyEstructura(eEstructura lista[], int lenghtArray);

/**
 * @brief Comprueba si el index ingresado por el usuario pertenece a un ID dentro de la estructura.
 *
 * @param lista Recibe el array de la estructura
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array
 * @param numero Recibe el dato de tipo INT a buscar.
 * @return Rertorna el index si es verdadero o -1 si es falso.
 */
int comprobarDatoIntEIndex(eEstructura lista[], int lenghtArray, int numero);

/**
 * @brief Comprueba si hay espacios VACIOS dentro de la estructura. Estandarizamos la comprobacion de los datos en isEmpty.
 *
 * @param lista Recibe el array de la estructura
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array
 * @return Retorna el indice del array en el cual hay un espacio VACIO, caso que no haya retorna -1.
 */
int comprobarEspaciosVaciosEstructura(eEstructura lista[], int lenghtArray);

/**
 * @brief Comprueba si hay espacios OCUPADOS dentro de la estructura. Estandarizamos la comprobacion de los datos en isEmpty
 *
 * @param lista Recibe el array de la estructura
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array
 * @return Retorna el 1 si hay un espacio OCUPADO, caso que no haya retorna -1.
 */
int comprobarEspaciosOcupadosEstructura(eEstructura lista[], int lenghtArray);

/**
 * @brief Realiza el alta de un dato de la estructura. La utilizo en el main
 *
 * @param lista Recibe el array de la estructura
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array
 */
void altaListaEstructura(eEstructura lista[], int lenghtArray);

/**
 * @brief Se encarga de cargar los datos de la estructura.
 *
 * @param lista Recibe el array de la estructura
 * @param index Recibe el index del espacio VACIO de la estructura
 */
void cargarDatosEstructura(eEstructura lista[], int index);

/**
 * @brief Se encarga de dar de baja los datos de la estructura seteando el index de OCUPADO a VACIO. La utilizo en el main
 *
 * @param lista Recibe el array de la estructura
 * @param lenghtArray Recibe el index del espacio VACIO de la estructura
 */
void bajaListaEstructura(eEstructura lista[], int lenghtArray);

/**
 * @brief Realiza la modificacion de datos de la estructura. La utilizo en el main
 *
 * @param lista Recibe el array de la estructura
 * @param lenghtArray Recibe el index del espacio VACIO de la estructura
 */
void modificarEstructura(eEstructura lista[], int lenghtArray);

/**
 * @brief Modifica, segun el administrador, los datos de esa posicion de la estructura.
 *
 * @param lista Recibe el array de la estructura
 * @param index Recibe el index donde se realizan las modificaciones.
 */
void modificarDatosEstructura(eEstructura lista[], int index);

/************************************************************************************************************/
/****************************************ORDENAMIENTO DE UNA ESTRUCTURA**************************************/
/************************************************************************************************************/
/**
 * @brief Ordenamiento simple de una estructura con el metodo de burbujeo
 *
 * @param lista Recibe el array de la estructura
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array.
 */
void simpleBubbleSort/*Agrego que quiero ordenar al nombre*/(eEstructura lista[], int lenghtArray);

/**
 * @brief Ordenamiento simple de una estructura con el metodo de burbujeo mejorado
 *
 * @param lista Recibe el array de la estructura
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array.
 */
void efficientBubbleSort/*Agrego que quiero ordenar al nombre*/(eEstructura lista[], int lenghtArray);

/**
 * @brief Ordenamiento simple de una estructura con el metodo de insercion
 *
 * @param lista Recibe el array de la estructura
 * @param lenghtArray Recibe la cantidad de elementos que puede contener el array.
 */
void insertionSortNumb/*Agrego que quiero ordenar al nombre*/(eEstructura lista[], int lenghtArray);

#endif /* TEMPLATES_H_ */
