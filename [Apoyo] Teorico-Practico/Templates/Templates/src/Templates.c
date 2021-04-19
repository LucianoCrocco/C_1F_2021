/*
 ============================================================================
 Name        : Templates.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/************************************************************************************************************/
/*******************************************FUNCIONES QUE CALCULAN*******************************************/
/************************************************************************************************************/

int calcularFactorial(int x){
	int resultado;

	if(x == 0 || x == 1){
		resultado = 1;
	} else {
		resultado = x * calcularFactorial(x - 1);
	}

	return resultado;
}

float sumarNumerosFloat(float x, float y){
	float resultado;

	resultado = x + y;

	return resultado;
}

float restarNumerosFloat(float x, float y){

	float resultado;

	resultado = x - y;

	return resultado;
}

float dividirNumerosFloat(float x, float y){
	float resultado;

	resultado = x / y;

	return resultado;
}

float multiplicarNumerosFloat(float x, float y){
	float resultado;


	resultado = x * y;

	return resultado;
}


/************************************************************************************************************/
/***********************************************PEDIR FUNCIONES**********************************************/
/************************************************************************************************************/

float pedirFloat(char mensaje[]){

	float numero;

	printf("%s",mensaje);
	scanf("%f",&numero);

	return numero;

}

float pedirFloatConRango(char mensaje[], char mensajeError[], float minimo, float maximo){
	float numero;

	printf("%s",mensaje);
	scanf("%f",&numero);
	while((numero < minimo || numero > maximo)){
		printf("\n%s\n\n",mensajeError);
		printf("%s",mensaje);
		scanf("%f",&numero);
	}

	return numero;

}

int pedirEntero(char mensaje[]){

	int numero;

	printf("%s",mensaje);
	scanf("%d",&numero);

	return numero;

}

int pedirEnteroConRango(char mensaje[], char mensajeError[], int minimo, int maximo){
	int numero;

	printf("%s",mensaje);
	scanf("%d",&numero);
	while((numero < minimo || numero > maximo)){
		printf("\n%s\n\n",mensajeError);
		printf("%s",mensaje);
		scanf("%d",&numero);
	}

	return numero;

}


/************************************************************************************************************/
/************************************************VALIDACIONES************************************************/
/************************************************************************************************************/

int comprobarEsNaturalFloat(float numero){

	char buffer[51];
	int retorno;
	int longitud;
	int i;



	longitud=sprintf(buffer,"%f",numero);

	for(i=longitud-1;i>0;i--){
		if(buffer[i] >= '1' && buffer[i] <= '9'){
			retorno = -1;
			break;
		} else {
			if(buffer[i] == '.'){
				retorno = 1;
				break;
			}
		}
	}


	return retorno;
}


/************************************************************************************************************/
/**************************************************UTILIDADES************************************************/
/************************************************************************************************************/

int menu(void){

	int opcionMenu;
	printf("\nOPCIONES\n");

	opcionMenu=pedirEnteroConRango("Ingrese una opcion: ", "Error...Ingrese una opcion valida", MINIMO, MAXIMO);

	return opcionMenu;
}

/************************************************************************************************************/
/**********************************************ESTRUCTURA UNICA**********************************************/
/************************************************************************************************************/

void hardocodearDatosUnaStruct/*EL nombre puede variar despues de DATOS*/(eEstructura lista[], int lenghtArray){ //DEFINES PREDEFINIDOS: OCUPADO, VACIO, STRING_LENGHT
	int i;
	/*			DATOS A HARDCODEAR
	char string[lenghtArray][STRING_LENGHT]={"Cargador", "Computadora", "Tablet"};
	int integerOFloat[lenghtArray]= {OCUPADO, OCUPADO, OCUPADO};//OCUPADO Y LIBRE SEGUN DEFINE
*/
	for(i=0;i<lenghtArray;i++){
		/*ASIGNAR EL HARDCODEO AL ARRAY*/
	}

}

void mostrarListadoEstructura(eEstructura lista[], int lenghtArray){
	int i;
	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO){//PUEDE VARIAR, PERO ES UN ESTANDAR PARA TODAS LAS ESCRUCTURAS
			mostrarUnElementoEstrucutra(lista[i]);
		}
	}
}

void mostrarUnElementoEstrucutra(eEstructura unElemento){
	printf("printf de los elementos y sus valroes --- %15s %5d %.2f etc\n",);
}

void inicializarIsEmptyEstructura(eEstructura lista[], int lenghtArray){
    int i;

    for(i=0;i<lenghtArray;i++){
    	lista[i].isEmpty = VACIO;
    }

}

int comprobarDatoIntEIndex(eEstructura lista[], int lenghtArray, int numero){
	int i;
	int validacion;

	validacion = -1;

	for(i=0;i<lenghtArray;i++){
		if(/*Dato de la estructura a buscar para comparar, ejemplo lista[i].id*/ == numero){
			validacion = i;
			break;
		}
	}
	return validacion;
}

int comprobarEspaciosVaciosEstructura(eEstructura lista[], int lenghtArray){
    int i;
    int retorno;

    retorno = -1;

    for(i=0;i<lenghtArray;i++){
        if(lista[i].isEmpty==VACIO){
        	retorno = i;
			break;
        }
    }

    return retorno;
}

int comprobarEspaciosOcupadosEstructura(eEstructura lista[], int lenghtArray){
    int i;
    int retorno;

    retorno = -1;

    for(i=0;i<lenghtArray;i++){
        if(lista[i].isEmpty==OCUPADO){
        	retorno = 1;
			break;
        }
    }
    return retorno;
}

void altaListaEstrucutra(eProductos lista[], int lenghtArray){
	int index;

	index = comprobarEspaciosVaciosEstructura(lista, lenghtArray);
	if(index != -1){
		cargarDatosEstructura(lista, index);
	} else {
		printf("\nNo hay espacios disponibles en la memoria\n");
	}
}

void cargarDatosEstructura(eEstructura lista[], int index){
	/*
	 * CARGO LOS DATOS DE LA ESTRUCTURA CON PRINTF Y SCANF.
	 */
}

void bajaListaEstrucutra(eEstructura lista[], int lenghtArray){
	int datoAComparar;
	int index;

	// PERSONALIZAR LOS MENSAJES, estandarizados en index.
	datoAComparar = pedirEntero("Ingrese el dato a buscar/comparar para dar de a dar de baja: ");

	index = comprobarDatoIntEIndex(lista,lenghtArray,datoAComparar);
	if(index == -1){
		printf("\nError... el index ingresado no es valido\n");
	} else {
		lista[index].isEmpty = VACIO;
		printf("\nElemento de la estructura borrado\n");
	}

}

void modificarEstructura(eEstructura lista[], int lenghtArray){

	int datoABuscar;
	int index;

	// PERSONALIZAR LOS MENSAJES, estandarizados en index.
	datoABuscar = pedirEntero("Ingrese el dato a buscar/comparar para modificar la estructura : ", "Error... el index no es valido");

	index = comprobarDatoIntEIndex(lista,lenghtArray,datoABuscar);
	if(index == -1){
		printf("\nError... el dato comparado ingresado no es valido\n");
	} else {
		modificarDatosEstructura(lista, index);
	}
}

void modificarDatosEstructura(eEstructura lista[], int index){
	//DATOS AUXILIARES
	int opciones;
	do {
		opciones = pedirEnteroConRango("1. Cambiar X\n2. Cambiar Y\n3. Cambiar Z\n4. Salir\nIngrese una opcion: ", "Error... Ingrese una opcion valida", MINIMO, MAXIMO);
		switch(opciones){
			case 1:
				break;
			default:
				break;
		}
	}while(opciones != 666);

}
/************************************************************************************************************/
/*****************************************ORDENAMIENTO DE ESTRUCTURAS****************************************/
/************************************************************************************************************/

int simpleBubbleSort/*Agrego que quiero ordenar al nombre*/(eEstructura lista[], int lenghtArray){
	int i;
	int j;
	eEstructura auxiliar;

	for(i=0;i<lenghtArray-1;i++){
		for(j=i+1;j<lenghtArray;j++){
			if(/*CONDICION > CONDICION*/){
				auxiliar = lista[i];
				lista[i] = lista[j];
				lista[j] = auxiliar;
			}
		}
	}
}

void insertionSortNumb/*Agrego que quiero ordenar al nombre*/(eEstructura lista[], int lenghtArray){
	int i;
	int j;
	eEstructura auxiliar;


	for(i=1;i<lenghtArray;i++){
		auxiliar = lista[i];
		j=i-1;
		while(j>=0 && /*CONDICION DE COMPRARACION*/){
			lista[j+1] = lista[j];
			j--;
		}
		lista[j+1]= auxiliar;
	}
}
