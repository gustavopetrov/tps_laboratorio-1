#include "Jugador.h"
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);
int controller_agregarJugador(LinkedList* pArrayListJugador);
int controller_editarJugador(LinkedList* pArrayListJugador);
int menuRemoverJugador(LinkedList* pArrayListJugador, int i,LinkedList* pArrayListSeleccion);
int controller_removerJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
int controller_listarJugadores(LinkedList* pArrayListJugador);
int controller_ordenarJugadores(LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

							/*-----personalizadas-----*/
void controller_listarJugadoresConvocados(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
void controller_listarJugadoresNoConvocados(LinkedList* pArrayListJugador);
int controller_jugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_desconvocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_listarJugadoresCustom(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_ordenarJugadoresNacionalidad(void* jugadorActual, void* siguienteJugador);
int controller_ordenarJugadoresNombre(void* jugadorActual, void* siguienteJugador);
int controller_ordenarJugadoresPorEdad(void* jugadorActual, void* siguienteJugador);
int controller_ordenarSeleccionesConfederacion(void* seleccionActual, void* siguienteSeleccion);


