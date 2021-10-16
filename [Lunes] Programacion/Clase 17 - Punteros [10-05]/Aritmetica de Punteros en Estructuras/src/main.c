/******************************************************************************

Luciano Crocco

*******************************************************************************/
#include <stdio_ext.h>
#include <stdlib.h>

typedef struct{

    int entero;
    float flotante;
    char caracter;

}dato;

//Una estructura es un valor y no una referencia.

int mostrarDatos(dato* arrayDato, int tam);
int mostrarUnDato(dato* unDato);
int cargarDatos(dato* arrayDato, int tam);

int main()
{
	setbuf(stdout,NULL);

    dato miDato={1,3.52,'a'};
    dato* pDato;
    pDato = &miDato; //Una estructura es un valor y no una referencia.

    //printf("%d-%d-%d-%d-%d\n\n",sizeof(int*), sizeof(dato), sizeof(float*), sizeof(char*), sizeof(float*));

    printf("%d --- %f --- %c\n", (*pDato).entero,(*pDato).flotante,(*pDato).caracter);
    printf("%d --- %f --- %c\n", pDato->entero, pDato->flotante, pDato->caracter); //El operador flecha lo que hace es atraer el operador * y .
    //pDato es una direccion de memoria, para llegar al valor necesito un asterisco, si el asterisco lo pongo x fuera de los parentesis de pDato estoy accediendo al campo entero.
    //printf("%d --- %f --- %c\n",miDato.entero, miDato.flotante, miDato.caracter);



    dato lista[3];//={{1,4.6,'H'},{3,1.1,'B'},{9,5.5,'C'}}; //Una estructura es un valor y no una referencia. Pero en este caso es un ARRAY de estructuras, por lo tanto lo tratamos como una referencia.
    dato* pLista;
    pLista = lista;

    /*for(int i=0; i<3; i++){
        //printf("%d --- %f --- %c\n", pLista[i].entero, pLista[i].flotante, pLista[i].caracter);
        //printf("%d --- %f --- %c\n", (*(pLista+i)).entero, (*(pLista+i)).flotante, (*(pLista+i)).caracter); //Con aritmetica de punteros.
        printf("%d --- %f --- %c\n", (pLista+i)->entero, (pLista+i)->flotante, (pLista+i)->caracter); //El operador flecha lo que hace es atraer el operador * y .

    }*/


    if(cargarDatos(pLista, 3) != 1){
        puts("\nError al cargar datos en la lista\n");
    }

    if(mostrarDatos(pLista, 3)){
        puts("\nLista desplegada correctamente\n");
    } else {
        puts("\nNo se pudo desplegar la lista\n");
    }


    return EXIT_SUCCESS;
}

int cargarDatos(dato* arrayDato, int tam){
    int i;
    int retorno;

    retorno = -1;

    if(arrayDato != NULL && tam > 0){
        for(i=0;i<tam;i++){
            printf("Ingrese un entero: ");
            scanf("%d",&arrayDato[i].entero);//Sin aritmetica de punteros. Con aritmetica: scanf("%d", &(lista+i)->entero);

            printf("Ingrese un flotante: ");
            scanf("%f",&(arrayDato+i)->flotante);//Con aritmetica de punteros.

            printf("Ingrese un char: ");
            __fpurge(stdin);
            scanf("%c",&(arrayDato+i)->caracter);//Con aritmetica de punteros.

        }
        retorno = 1;
    }
    return retorno;
}

int mostrarDatos(dato* arrayDato, int tam){
    int retorno;
    int i;
    retorno = -1;

    if(arrayDato != NULL && tam > 0){
        for(i=0;i<tam;i++){
            if(mostrarUnDato(arrayDato+i) != 1){
                retorno = -1;
                puts("\nError al mostrar un dato.\n");
                break;
            }
        }
    }

    return retorno;
}

int mostrarUnDato(dato* unDato){
    int retorno = -1;
    if(unDato != NULL){
        printf("%d --- %f --- %c\n", unDato->entero, unDato->flotante, unDato->caracter); //El operador flecha lo que hace es atraer el operador * y .
        retorno = 1;
    }
    return retorno;
}
