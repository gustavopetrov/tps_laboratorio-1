#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "jugador.h"

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
typedef struct
{
	int idConfederacion;
	char nombre[50];
	char region[50];
	int anioCreacion;
	short isEmpty;
}eConfederacion;

typedef struct
{
	int idConfederacion;
	int acumuladorAnios;
	int contadorJugadores;
	float promedioJugadores;
}eConfederacionAux;

/** INICIO CABECERAS DE FUNCION*/
void eConfederacion_Inicializar(eConfederacion array[], int TAM);
int eConfederacion_ObtenerIndexLibre(eConfederacion array[], int TAM);
int eConfederacion_BuscarPorID(eConfederacion array[], int TAM, int ID);
void eConfederacion_MostrarUno(eConfederacion Jugador);
int eConfederacion_MostrarTodos(eConfederacion array[], int TAM);
int eConfederacion_MostrarDadosDeBaja(eConfederacion array[], int TAM);
eConfederacion eConfederacion_CargarDatos(void);
int eConfederacion_Alta(eConfederacion array[], int TAM);
int eConfederacion_Baja(eConfederacion array[],int TAM);
eConfederacion eConfederacion_ModificarNombre(eConfederacion confederacion);
eConfederacion eConfederacion_ModificarRegion(eConfederacion confederacion);
eConfederacion eConfederacion_ModificarCreacion(eConfederacion confederacion);

int eConfederacion_ValidarConfederacionesCargadas(eConfederacion array[], int TAM);
/* SORT CONFEDERACIONES */


eConfederacion eConfederacion_cargaPrueba(char nombre[], char region[], int anioCreacion);
#endif /* CONFEDERACION_H_ */
