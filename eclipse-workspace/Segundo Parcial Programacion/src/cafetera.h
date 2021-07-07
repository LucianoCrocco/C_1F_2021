#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char marca[30];
    int esMultiCapsula;
}eCafetera;

eCafetera* cafetera_newParametros(int id, char* marca, int esMultiCapsula);
eCafetera* cafetera_new(void);
int guardarBinario(char* path, void* pElement);
int cargarYMostrarBinario(char* path, void* pElement);
