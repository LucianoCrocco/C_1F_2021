/******************************************************************************

Luciano Crocco 1ºF

Realizar una función que reciba un puntero a char y dos char.
La función deberá reemplazar en la cadena cada ocurrencia del primer carácter recibido, por el segundo.
Retornando la cantidad de reemplazos o -1 en caso de error.

*******************************************************************************/
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

int reemplazarChar(char* pCacter, char primerCaracter,char segundoCaracter);
int get_Char (char* pResult, char* msg, char* errorMsg, char min, char max, int retries);
int get_String(char* pResult, char* msg, char* errorMsg, int retries, int lenght);


int main()
{
    setbuf(stdout,NULL);
    char string[30];
    /*char* pString = NULL;
    pString = string;*/
    char caracter;
    char caracterARemplazar;
    int reemplazo;

    if(get_String(string, "Ingrese la cadena: ", "Error... El maximo de caracteres permitidos es: ", 3, 30) == 0){
    	puts("Error al cargar el string");
    }

    if(get_Char(&caracter,"Ingrese el caracter a reemplazar en al cadena: ", "Error... ingrese un caracter valido", 65, 122, 3) == 0){
		puts("Error al cargar el caracter");
	}

    if(get_Char(&caracterARemplazar,"Ingrese el caracter que se inserta en la cadena: ", "Error... ingrese un caracter valido", 65, 122, 3) == 0){
    	puts("Error al cargar el caracter");
    }


    reemplazo = reemplazarChar(string,caracter, caracterARemplazar);

    if(reemplazo != -1){
        printf("\n%s\n", string);
        printf("Se reemplazo en la cadena el caracter '%c' por el caracter '%c' %d veces", caracterARemplazar, caracter, reemplazo);
    } else {
        puts("\nError\n");
    }

    return EXIT_SUCCESS;
}

int reemplazarChar(char* pCadena, char primerCaracter,char segundoCaracter){
    int i;
    int coincidencias;
    int len;

    coincidencias=0;

    len = strlen(pCadena);

    if(pCadena != NULL && len >= 0){
        for(i=0;i<len;i++){
            if((*(pCadena+i)) != '\0'){
                if((*(pCadena+i)) == primerCaracter){
                    coincidencias++;
                    (*(pCadena+i))=segundoCaracter;
                }
            }
        }
    } else {
        return -1;
    }

    return coincidencias;

}

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

int get_String(char* pResult, char* msg, char* errorMsg, int retries, int lenght){
	int rtn;
	char bufferString[lenght*4];

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
