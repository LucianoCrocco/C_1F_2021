/*
 ============================================================================
 Name        : atoi.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style


 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char numeroString[20]={"300"};
	int numero;

	numero=atoi(numeroString);

	printf("Atoi realizado %d",numero);


	/* ITOA NO ES POSIBLE
	 * This function is not defined in ANSI-C and is not part of C++, but is supported by some compilers.

	A standard-compliant alternative for some cases may be sprintf:

    sprintf(str,"%d",value) converts to decimal base.
    sprintf(str,"%x",value) converts to hexadecimal base.
    sprintf(str,"%o",value) converts to octal base.
	 *
	 * */

	return EXIT_SUCCESS;
}
