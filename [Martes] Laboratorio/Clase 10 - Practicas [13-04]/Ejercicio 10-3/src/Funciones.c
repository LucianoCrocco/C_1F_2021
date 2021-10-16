#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"

/************************************************************************************************************/
/**************************************************UTILIDADES************************************************/
/************************************************************************************************************/

int menu(void){

	int opcionMenu;
	printf("\n-----OPCIONES-----\n");
	printf("1. Alta producto\n");
	printf("2. Baja producto\n");
	printf("3. Modificacion producto\n");
	printf("4. Listado producto\n");
	printf("5. Listado producto ordenado por precio\n");
	printf("6. Listado producto ordenado por descripcion\n");;
	printf("7. El/los  productos mas caros\n");
	printf("8. Precio promedio por tipo de producto. Se deberá mostrar la descripción del tipo y a continuación el precio promedio.\n");
	printf("9. El listado de todos los productos con la descripción del tipo\n");
	printf("10. Por cada tipo la lista de productos\n");
	printf("11. Salir\n");
	opcionMenu=pedirEnteroConRango("Ingrese una opcion: ", "Error...Ingrese una opcion valida", 1, 11);

	return opcionMenu;
}

void saltoDeLinea(int cantidad){
	int i;
	for(i=0;i<cantidad;i++){
		printf("\n");
	}
}
/************************************************************************************************************/
/***********************************************PEDIR FUNCIONES**********************************************/
/************************************************************************************************************/

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


int pedirEntero(char mensaje[]){

	int numero;

	printf("%s",mensaje);
	scanf("%d",&numero);

	return numero;

}


float pedirFloat(char mensaje[]){

	float numero;

	printf("%s",mensaje);
	scanf("%f",&numero);

	return numero;

}


/************************************************************************************************************/
/************************************************VALIDACIONES************************************************/
/************************************************************************************************************/

int comprobarNoRepiteIntProducto(eProductos lista[], int lenghtArray ,int numero){
	int i;
	int retorno;

	retorno = 1;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].idProducto==numero){
			retorno = -1;
			break;
		}
	}
	return retorno;
}

/************************************************************************************************************/
/************************************************ESTRUCTURAS*************************************************/
/************************************************************************************************************/

/************************************************UTILIDADES*************************************************/

int comprobarEspaciosVaciosEstructura(eProductos lista[], int lenghtArray){
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


int comprobarEspaciosOcupadosEstructura(eProductos lista[], int lenghtArray){
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

int comprobarDatoIntEIndex(eProductos lista[], int lenghtArray, int numero){
	int i;
	int validacion;

	validacion = -1;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].idProducto == numero){
			validacion = i;
			break;
		}
	}
	return validacion;
}



/************************************************HARDCODEOS*************************************************/

void hardocodearDatosUnaStructNacionalidades(eNacionalidad lista[]){
	int i;

	int idNacionalidad[3]={1, 2, 3};
	char descripcionNacionalidad[3][STRING_LENGHT]={"EEUU", "CHINA", "OTROS"};
	int isEmpty[3]= {OCUPADO, OCUPADO, OCUPADO};

	for(i=0;i<3;i++){
		lista[i].idNacionalidad=idNacionalidad[i];
		strcpy(lista[i].descripcionNacionalidad,descripcionNacionalidad[i]);
		lista[i].isEmpty=isEmpty[i];
	}

}

void hardocodearDatosUnaStructTipoProductos(eTipoProducto lista[]){
	int i;

	int idTipo[4]={1000, 1001, 1002, 1003};
	char descripcionTipo[4][STRING_LENGHT]={"Iphone", "Ipad", "Mac", "Accesorios"};
	int isEmpty[4]= {OCUPADO, OCUPADO, OCUPADO, OCUPADO};

	for(i=0;i<4;i++){
		lista[i].idTipo=idTipo[i];
		strcpy(lista[i].descripcionTipo,descripcionTipo[i]);
		lista[i].isEmpty=isEmpty[i];
	}

}


void hardocodearDatosUnaStructProductos(eProductos lista[]){
	int i;

	int idProducto[3]={1100, 1000, 1200};
	char descripcion[3][STRING_LENGHT]={"Cargador", "Computadora", "Tablet"};
	int nacionalidad[3]={CHINA, CHINA, EEUU};
	int tipo[3]={1003, 1001, 1002};
	float precio[3]={100, 1250.40, 300};
	int isEmpty[3]= {OCUPADO, OCUPADO, OCUPADO};

	int idTipo[3]={1003, 1001, 1002};

	int idNacionalidad[3]={CHINA, CHINA, EEUU};

	for(i=0;i<3;i++){
		lista[i].idProducto=idProducto[i];
		strcpy(lista[i].descripcion,descripcion[i]);
		lista[i].nacionalidad=nacionalidad[i];
		lista[i].tipo=tipo[i];
		lista[i].precio=precio[i];
		lista[i].isEmpty=isEmpty[i];
		lista[i].idTipo=idTipo[i];
		lista[i].idNacionalidad=idNacionalidad[i];
	}

}


void inicializarIsEmptyProductos(eProductos lista[], int lenghtArray){
    int i;
    for(i=0;i<lenghtArray;i++){
    	lista[i].isEmpty = VACIO;
    }
}


void inicializarIsEmptyTipoProductos(eTipoProducto lista[], int lenghtArray){
	int i;
	for(i=0;i<lenghtArray;i++){
		lista[i].isEmpty = VACIO;
	}
}

void inicializarIsEmptyNacionalidades(eNacionalidad lista[], int lenghtArray){
	int i;
	for(i=0;i<lenghtArray;i++){
		lista[i].isEmpty = VACIO;
	}
}

/**********************************************MOSTRAR LISTADOS***********************************************/
//								CASE 4 Y 9
void mostrarListadoProductos(eProductos lista[], int lenghtArray){
	int i;
	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO){
			mostrarUnElementoProductos(lista[i]);
		}
	}
}

void mostrarUnElementoProductos(eProductos unProducto){

	char nacionalidad[STRING_LENGHT];
	char tipo[STRING_LENGHT];

	switch(unProducto.nacionalidad){
		case EEUU:
			strcpy(nacionalidad,"EEUU");
			break;
		case CHINA:
			strcpy(nacionalidad,"CHINA");
			break;
		default:
			strcpy(nacionalidad,"OTROS");
			break;
	}
	switch(unProducto.tipo){
		case IPHONE:
			strcpy(tipo,"Iphone");
			break;
		case MAC:
			strcpy(tipo,"Mac");
			break;
		case IPAD:
			strcpy(tipo,"Ipad");
			break;
		case ACCESORIOS:
			strcpy(tipo,"Accesorios");
			break;
	}
	printf("Id del producto: %d\n", unProducto.idProducto);
	printf("Descripcion: %s\n", unProducto.descripcion);
	printf("Nacionalidad: %s\n", nacionalidad);
	printf("Tipo: %s\n", tipo);
	printf("Precio: %.2f\n\n", unProducto.precio);
}
//								CASE 1 Y 3
void mostrarListadoTipoProducto(eTipoProducto  lista[], int lenghtArray){
	int i;
	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO){
			mostrarUnElementoTipoProducto(lista[i]);
		}
	}
}


void mostrarUnElementoTipoProducto(eTipoProducto unElemento){
	printf("Id: %d\tDescripcion: %s\n", unElemento.idTipo, unElemento.descripcionTipo);
}

//								CASE 9



//								CASE 10
void mostrarListadoTipoProductoYProducto(eProductos lista[], int lenghtArray, eTipoProducto listaTipo[], int lenghtTipo){
	int i;
	int validacion;
	for(i=0;i<lenghtTipo;i++){
		if(listaTipo[i].isEmpty==OCUPADO){
			mostrarUnElementoTipoProducto(listaTipo[i]);
			saltoDeLinea(1);
			validacion = mostrarUnElementoTipoProductoYProducto(lista,lenghtArray,listaTipo[i]);
			if(validacion == -1){
				printf("\t---No hay elementos de este tipo---\n\n");
			}
		}
	}
}

int mostrarUnElementoTipoProductoYProducto(eProductos lista[], int lenghtArray, eTipoProducto unElemento){
	int i;
	int encontro;

	encontro = -1;

	for(i=0;i<lenghtArray;i++){
		if(unElemento.idTipo == lista[i].idTipo){
			mostrarUnElementoProductos(lista[i]);
			encontro = 1;
		}
	}
	return encontro;
}


/*******************************************ALTA-BAJA-MODIFICACION**********************************************/

//								CASE 1

void altaListaEstructura(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2){
	int index;

	index = comprobarEspaciosVaciosEstructura(lista, lenghtArray);
	if(index != -1){
		cargarDatosEstructura(lista, index, lista2, lenghtArray2);
	} else {
		printf("\nNo hay espacios disponibles en la memoria\n");
	}
}


void cargarDatosEstructura(eProductos lista[], int index, eTipoProducto lista2[], int lenghtArray2){
	int tipo;
	int validacion;

	mostrarListadoTipoProducto(lista2, lenghtArray2);
	tipo = pedirEnteroConRango("Ingrese el ID del tipo de producto desea dar de alta: ", "Error... Ingrese una opcion valida", 1000, 1003);

	lista[index].idProducto=pedirEntero("Ingrese el ID del producto: ");
	validacion = comprobarNoRepiteIntProducto(lista, index, lista[index].idProducto);
	while(validacion == -1){
		printf("\nError... El ID ingresado ya fue asigando a otro producto, ingrese uno nuevamente\n");
		lista[index].idProducto=pedirEntero("Ingrese el ID del producto: ");
		validacion = comprobarNoRepiteIntProducto(lista, index, lista[index].idProducto);
	}

	printf("Ingrese la descripcion del producto: ");
	__fpurge(stdin);
	scanf("%[^\n]",lista[index].descripcion);

	lista[index].nacionalidad=pedirEnteroConRango("---Paises Disponibles---\n1. EEUU\n2. CHINA\n3. OTRO\nIngrese una opcion: ", "Error... Ingrese una opcion valida", 1, 3);

	lista[index].tipo=tipo;

	lista[index].isEmpty=OCUPADO;

	lista[index].precio = pedirFloat("Ingrese el precio del producto: ");

	lista[index].idTipo=tipo;

	lista[index].idNacionalidad=lista[index].nacionalidad;


}

//								CASE 2

void bajaListaEstructura(eProductos lista[], int lenghtArray){
	int datoAComparar;
	int index;

	datoAComparar = pedirEntero("Ingrese el id del producto a dar de baja: ");

	index = comprobarDatoIntEIndex(lista,lenghtArray,datoAComparar);
	if(index == -1){
		printf("\nError... el ID del producto ingresado no es valido\n");
	} else {
		lista[index].isEmpty = VACIO;
		printf("\nProducto borrado\n");
	}

}



//								CASE 3


void modificarProductos(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2){

	int datoABuscar;
	int index;

	datoABuscar = pedirEntero("\nIngrese el ID del producto para modificar los datos: ");

	index = comprobarDatoIntEIndex(lista,lenghtArray,datoABuscar);
	if(index == -1 || lista[index].isEmpty == VACIO){
		printf("\nError... el dato comparado ingresado no es valido\n");
	} else {
		modificarDatosProductos(lista, index, lista2, lenghtArray2);
	}
}

void modificarDatosProductos(eProductos lista[], int index, eTipoProducto lista2[], int lenghtArray2){
	//DATOS AUXILIARES
	int opciones;
	int flagModifico;

	flagModifico = 0;

	do {
		saltoDeLinea(1);
		opciones = pedirEnteroConRango("1. Cambiar Descripcion \n2. Cambiar Nacionalidad\n3. Cambiar Tipo\n4. Cambiar Precio\n5. Salir\nIngrese una opcion: ", "Error... Ingrese una opcion valida", 1, 5);
		switch(opciones){
			case 1:
				printf("Ingrese la nueva descripcion del producto: ");
				__fpurge(stdin);
				scanf("%[^\n]",lista[index].descripcion);
				flagModifico++;
				break;
			case 2:
				lista[index].nacionalidad=pedirEnteroConRango("---Paises Disponibles---\n1. EEUU\n2. CHINA\n3. OTRO\nIngrese una opcion: ", "Error... Ingrese una opcion valida", 1, 3);
				lista[index].idNacionalidad=lista[index].nacionalidad;
				flagModifico++;
				break;
			case 3:
				mostrarListadoTipoProducto(lista2, lenghtArray2);
				lista[index].tipo = pedirEnteroConRango("Ingrese que tipo de producto desea dar de alta: ", "Error... Ingrese una opcion valida", 1000, 1003);
				lista[index].idTipo = lista[index].tipo;
				flagModifico++;
				break;
			case 4:
				lista[index].precio = pedirFloat("Ingrese el nuevo precio del producto: ");
				flagModifico++;
				break;
		}
	}while(opciones != 5);

	if(flagModifico==0){
		printf("\nNo se modificaron datos.\n");
	} else {
		printf("\nDatos modificados correctamente.\n");
	}
}

//								CASE 8

float precioPromedioPorTipo(eProductos lista[], int lenghtArray, int tipo){
	int i;
	int coincidencias;
	float acumulador;
	float promedio;

	coincidencias=0;
	acumulador = 0;
	promedio = -1;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty == OCUPADO){
			if(lista[i].tipo==tipo){
				coincidencias++;
				acumulador += lista[i].precio;
			}
		}
	}
	if(coincidencias != 0){
		promedio = acumulador / coincidencias;
	}

	return promedio;

}

void printPromediosPorTipo(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2){
	int i;

	for(i=0;i<lenghtArray2;i++){
		if(lista2[i].isEmpty == OCUPADO){
			printf("\nID del tipo: %2d\tDescripcion: %10s\n",lista2[i].idTipo, lista2[i].descripcionTipo);
			printUnPromedioTipoProducto(lista,lenghtArray, lista2, lenghtArray2, lista2[i].idTipo);
		}
	}
}

void printUnPromedioTipoProducto(eProductos lista[], int lenghtArray, eTipoProducto lista2[], int lenghtArray2, int tipo){

	float promedio;

	promedio=precioPromedioPorTipo(lista,lenghtArray,tipo);

	if(promedio != -1){
		printf("\nEl promedio es: %.2f\n", promedio);
	} else {
		printf("\nNo se ingresaron datos de este tipo \n");
	}
}

//								CASE 7

void printProductosMasCaros(eProductos lista[], int lenghtArray){
	int i;

	for(i=0;i<lenghtArray;i++){
		if(lista[i].isEmpty==OCUPADO){
			mostrarUnElementoProductos(lista[i]);
		}
	}
}

void productosMasCaros(eProductos lista[], int lenghtArray){

	eProductos auxiliar[lenghtArray];

	inicializarIsEmptyProductos(auxiliar,lenghtArray);

	int i;
	int j;

	j=0;

	auxiliar[0]=lista[0];

	for(i=1;i<lenghtArray;i++){
		if(auxiliar[j].precio == lista[i].precio && lista[i].isEmpty == OCUPADO){
			j++;
			auxiliar[j]=lista[i];
		} else {
			if(auxiliar[j].precio < lista[i].precio && lista[i].isEmpty == OCUPADO){
				inicializarIsEmptyProductos(auxiliar,lenghtArray);
				auxiliar[0]=lista[i];
				j=0;
			}
		}
	}

	printProductosMasCaros(auxiliar,lenghtArray);
}


/*******************************************ORDENAMIENTO DE eARRAYS**********************************************/
//								CASE 5
void insertionSortNumbPrecio(eProductos lista[], int lenghtArray){
	int i;
	int j;
	eProductos aux;


	for(i=1;i<lenghtArray;i++){
		aux = lista[i];
		j=i-1;
		while(j>=0 && aux.precio < lista[j].precio){
			lista[j+1] = lista[j];
			j--;
		}
		lista[j+1]= aux; //insercion
	}
}

//								CASE 6
void insertionSortNumbDescripcion(eProductos lista[], int lenghtArray){
	int i;
	int j;
	eProductos aux;


	for(i=1;i<lenghtArray;i++){
		aux = lista[i];
		j=i-1;
		while(j>=0 && strcmp(aux.descripcion,lista[j].descripcion) < 0){
			lista[j+1] = lista[j];
			j--;
		}
		lista[j+1]= aux; //insercion
	}
}


/**********************************************PRUEBAS************************************************/


/*
void productosMasCaros(eProductos lista[], int lenghtArray){

	eProductos auxiliar[lenghtArray];

	inicializarIsEmptyProductos(auxiliar,lenghtArray);

	int i;
	int j;

	for(i=0;i<lenghtArray;i++){
		j=i-1;
		if(i==0 || auxiliar[j].precio <= lista[i].precio){
			auxiliar[i]=lista[i];
			j--;
			while(auxiliar[j].precio < lista[i].precio && i > 0 && auxiliar[j].isEmpty == OCUPADO){
				auxiliar[j].isEmpty=VACIO;
				j--;
			}
		}
	}

	printProductosMasCaros(auxiliar,lenghtArray);
}*/

/*
void productosMasCaros(eProductos lista[], int lenghtArray){

	eProductos auxiliar[lenghtArray];

	inicializarIsEmptyProductos(auxiliar,lenghtArray);

	int i;
	int j;

	j=0;

	auxiliar[0]=lista[0];

	for(i=1;i<lenghtArray;i++){
		if(auxiliar[j].precio == lista[i].precio){
			j++;
			auxiliar[j]=lista[i];
		} else {
			while(j>=0 && auxiliar[j].precio < lista[i].precio){
				auxiliar[i-j].isEmpty=VACIO;
				auxiliar[j]=lista[i];
				j--;
			}
		}
	}

	printProductosMasCaros(auxiliar,lenghtArray);
}
*/


