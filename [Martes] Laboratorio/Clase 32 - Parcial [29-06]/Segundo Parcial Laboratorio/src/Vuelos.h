#ifndef VUELOS_H_
#define VUELOS_H_
#define STRING_LENGHT_VUELOS 100


typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct {
	int idVuelo;
	int idAvion;
	int idPiloto; //FK
	eFecha fecha;
	char destino[STRING_LENGHT_VUELOS];
	int cantPasajeros;
	int horaDespegue;
	int horaLlegada;
}eVuelos;

eVuelos* vuelo_new();
eVuelos* vuelo_newParametros(char* idVueloStr, char* idAvionStr, char* idPilotoStr, char* diaStr, char* mesStr, char* anioStr, char* destinoStr, char* cantPasajerosStr,char* horaDespegueStr,char* horaLlegadaStr);
void vuelo_delete(eVuelos* this);

int vuelo_setIdVuelo(eVuelos* this,int id);
int vuelo_getIdVuelo(eVuelos* this,int* id);
int vuelo_setIdAvion(eVuelos* this,int id);
int vuelo_getIdAvion(eVuelos* this,int* id);
int vuelo_setIdPiloto(eVuelos* this,int id);
int vuelo_getIdPiloto(eVuelos* this,int* id);
int vuelo_setFechaDia(eVuelos* this,int dia);
int vuelo_getFechaDia(eVuelos* this,int* dia);
int vuelo_setFechaMes(eVuelos* this,int mes);
int vuelo_getFechaMes(eVuelos* this,int* mes);
int vuelo_setFechaAnio(eVuelos* this,int anio);
int vuelo_getFechaAnio(eVuelos* this,int* anio);
int vuelo_setDestino(eVuelos* this,char* destino);
int vuelo_getDestino(eVuelos* this,char* destino);
int vuelo_setCantPasajeros(eVuelos* this,int cantidad);
int vuelo_getCantPasajeros(eVuelos* this,int* cantidad);
int vuelo_setHoraDespegue(eVuelos* this,int horaDespegue);
int vuelo_getHoraDespegue(eVuelos* this,int* horaDespegue);
int vuelo_setHoraLlegada(eVuelos* this,int horaLlegada);
int vuelo_getHoraLlegada(eVuelos* this,int* horaLlegada);

int vuelos_setAllAtributes(eVuelos* this, int idVuelo, int idAvion, int idPiloto, int dia, int mes, int anio, char* destino, int cantPasajeros, int horaDespegue, int horaLlegada);
int vuelos_getAllAtributes(eVuelos* this, int* idVuelo, int* idAvion, int* idPiloto, int* dia, int* mes, int* anio, char* destino, int* cantPasajeros,int* horaDespegue, int* horaLlegada);

#endif /* VUELOS_H_ */
