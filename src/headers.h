#ifndef HEADERS_H_
#define HEADERS_H_
/**
 * @brief => funcion que calcula promedios divide confederacion / totalJugadores
 *
 * @param confederacion recibe un contador (cada confederacion es un contador conmebol etc)
 * @param totalJugadores (el total de jugadores)
 * @return
 */
float calculadoraPromedios( int confederacion, int totalJugadores);
/**
 * @brief
 * Pide un numero de tipo float, verifica que sea mayor a cero y de ser así lo retorna.
 * @param numeroFloat
 * @param minimo -> no puede ser 0
 * @param mensaje
 * @return
 */
float pedirValidarFloat(float numeroFloat, int minimo, char mensaje[]);
/**
 * @brief
 * Pide un numero entero y lo retorna
 *
 * @param mensaje
 * @return
 */
int pedirInt(char mensaje[]);
/**
 * @brief
 * El objetivo de esta funcion es permitirme validar los rangos de las confederaciones ( 1 al 6 )
 * @param numeroEntero -> Recibe un número entero
 * @param minimo -> verifica que no sea menor que 1
 * @param maximo -> verifica que no sea mayor que 6
 * @param mensaje
 * @param mensajeError
 * @return
 */
int pedirValidarInt(int numeroEntero, int minimo, int maximo, char mensaje[],char mensajeError[]);
/**
 * @brief => Valida que se hayan cargado los costos de mantenimiento y almenos 1 jugador para poder acceder al menu 3.
 *
 * @param arqueros
 * @param defensores
 * @param medioCampistas
 * @param delanteros
 * @param gastosHospedaje
 * @param gastosComida
 * @param gastosTransporte
 * @return => retorna un estado 1 todo ok -1 todo falló
 */
int validarIngresos(int arqueros, int defensores, int medioCampistas, int delanteros,float gastosHospedaje, float gastosComida, float gastosTransporte);
/**
 * @brief
 * Listado de opciones del menu principal.
 * @return retorna la selección del usuario
 */
int opcionesMenuPrincipal (float gastosHospedaje, float gastosComida, float gastosTransporte, int arqueros, int defensores, int medioCampistas,int delanteros);
/**
 * @brief => Funcion para mostrar el submenú de gastos...
 *
 * @param gastosHospedaje
 * @param gastosComida
 * @param gastosTransporte
 */
void mostrarCostos(float gastosHospedaje, float gastosComida, float gastosTransporte);
/**
 *brief => Muestro lista del equipo
 *
 * @param arqueros
 * @param defensores
 * @param medioCampistas
 * @param delanteros
 */
void mostrarJugadores(int arqueros, int defensores, int medioCampistas, int delanteros);
/**
 * @brief
 * Listado de opciones del menu de jugadores.
 * @param arqueros
 * @param defensores
 * @param medioCampistas
 * @param delanteros
 * @return -> retorna la selección del usuario.
 */
int opcionesCargaJugadores(int arqueros, int defensores, int medioCampistas, int delanteros);
/**
 * @brief -> funcion main
 *
 */
void menuPrincipal (void);







#endif /* HEADERS_H_ */
