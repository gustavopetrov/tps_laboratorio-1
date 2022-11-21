#ifndef eJugador_H_
#define eJugador_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//*** eJugador
typedef struct
{
	int idJugador;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
} eJugador;


/** INICIO CABECERAS DE FUNCION*/
void eJugador_Inicializar(eJugador array[], int TAM);
int eJugador_ObtenerIndexLibre(eJugador array[], int TAM);
int eJugador_BuscarPorID(eJugador array[], int TAM, int ID);

eJugador eJugador_ModificarNombre(eJugador Jugador);
eJugador eJugador_ModificarPosicion(eJugador Jugador);
eJugador eJugador_ModificarNumeroCamiseta(eJugador Jugador);
eJugador eJugador_ModificarSalario(eJugador Jugador);
eJugador eJugador_ModificarContrato(eJugador Jugador);

int eJugador_ContarJugadores(eJugador array[], int TAM);
float acumularSalariosTotales(eJugador array[], int TAM);
float promedioSalario(eJugador array[], int TAM);
int obtenerJugadoresConSalarioMaximo(eJugador array[], int TAM);

int eJugador_ValidarJugadoresCargados(eJugador array[], int TAM);

/* pruebas */
eJugador eJugador_cargaPrueba(char nombre[], char posicion[], short numeroCamiseta, int idConfederacion, float salario, short aniosContrato);
/** FIN CABECERAS DE FUNCION*/


#endif
