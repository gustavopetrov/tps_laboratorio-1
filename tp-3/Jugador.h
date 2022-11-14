#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED
#define NOMBRE_LEN 100


typedef struct
{
	int id;
	char nombreCompleto[NOMBRE_LEN];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr);

void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

int obtenerID();
int buscarIDLinkedList(LinkedList* pArrayListJugador);
int modificarNombre(LinkedList* pArrayListJugador, int i);
int modificarEdad(LinkedList* pArrayListJugador, int i);
int modificarPosicion(LinkedList* pArrayListJugador, int i);
int modificarNacionalidad(LinkedList* pArrayListJugador, int i);
int modificarIdSeleccion(Jugador* jugadorAux, int idSeleccionAux);
int menuModificacionJugadores(LinkedList* pArrayListJugador, int i);
int menuRemoverJugador(LinkedList* pArrayListJugador, int i);
int mostrarUnJugador(Jugador* unJugador);
int idConfederacion(LinkedList* pArrayListJugador);
void mostrarJugadorBinario(Jugador* unJugador);


#endif // jug_H_INCLUDED
