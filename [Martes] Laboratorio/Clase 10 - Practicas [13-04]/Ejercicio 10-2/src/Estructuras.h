/*
 * Estructuras.h
 *
 *  Created on: 13 abr. 2021
 *      Author: luciano
 */

#ifndef ESTRUCTURAS_H_
#define ESTRUCTURAS_H_
#define STRING_LENGHT 100

// ******** A ********


typedef struct{

	char localidad[STRING_LENGHT];
	char nombreCalle[STRING_LENGHT];
	int numeroCalle;
	char timbre[STRING_LENGHT];

}eDireccion;



typedef struct {
	int idProveedor;//PK
	char razonSocial[STRING_LENGHT];
	eDireccion direccion;


}eProveedor;

typedef struct {

	int idProducto;//PK
	char descripcion[STRING_LENGHT];
	float precio;

	int idProveedor;//FK

}eProducto;

// ******** B ********

struct eRaza{
	int idRaza;
	char nombreDeAnimal[TRING_LENGHT];
	char nombreDeLaRaza[STRING_LENGHT];
};
struct eDuenio {
	int idDuenio;//PK
	char nombre[STRING_LENGHT];
	int edad;
	char sexo;
};

struct eMascota{
	int idMascota;
	char nombre[STRING_LENGHT];
	struct eRaza raza;
	char sexo;

	int idDuenio;//FK
};

// ******** C ********

typedef struct{

	int idLocalidad;
	char descripcion[STRING_LENGHT];
	int codigoPostal;


}eLocalidad;

typedef struct{
	int idAlumno;//PK
	char nombre[STRING_LENGHT];

	int idLocalidad;//FK

}eAlumno;



#endif /* ESTRUCTURAS_H_ */
