#ifndef PILOTO_H_
#define PILOTO_H_

#define STRING_LENGHT_PILOT 100

typedef struct{
	int id;
	char nombre[STRING_LENGHT_PILOT];
	char apellido[STRING_LENGHT_PILOT];
}ePiloto;


ePiloto* piloto_new();

ePiloto* piloto_newParametros(char* idStr,char* nombreStr,char* apellidoStr);

void piloto_delete(ePiloto* this);

int piloto_setId(ePiloto* this,int id);
int piloto_getId(ePiloto* this,int* id);
int piloto_setNombre(ePiloto* this,char* nombre);
int piloto_getNombre(ePiloto* this,char* nombre);
int piloto_setApellido(ePiloto* this,char* apellido);
int piloto_getApellido(ePiloto* this,char* apellido);
int piloto_setAllAtributes(ePiloto* this, int id, char* nombre, char* apellido);
int piloto_getAllAtributes(ePiloto* this, int* id, char* nombre, char* apellido);



#endif /* PILOTO_H_ */
