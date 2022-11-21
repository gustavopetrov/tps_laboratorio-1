/*---------eJugador---------*/
void eJugador_MostrarUno(eJugador Jugador,eConfederacion Confederacion[], int TAM_Confederacion);
int eJugador_MostrarTodos(eJugador array[], int TAM,eConfederacion arrayConfederaciones[],int TAM_Confederacion);
int eJugador_MostrarDadosDeBaja(eJugador array[], int TAM,eConfederacion arrayConfederaciones[],int TAM_Confederacion);
eJugador eJugador_CargarDatos(eConfederacion array[], int TAM);
int verificarID_Confederaciones(eConfederacion array[], int TAM, int id);
eJugador eJugador_ModificarConfederacion(eJugador Jugador, eConfederacion confederacion[], int TAM_Confederacion);
int eJugador_Alta(eJugador array[], int TAM, eConfederacion arrayConfederacion[], int TAMconfederacion);
int eJugador_Baja(eJugador array[], int TAM,eConfederacion arrayConfederaciones[],int TAM_Confederacion);
int eJugador_Modificacion(eJugador array[], int TAM,eConfederacion arrayConfederaciones[],int TAM_Confederacion);
int eConfederacion_ListarJugadoresDeUnaConfederacion(eConfederacion arrayConfederacion[], int TAM_Confederacion, eJugador array[], int TAM );
int mostrarTodosLosJugadoresDeUnaConfederacion(eJugador array[], int TAM, eConfederacion arrayConfederacion[], int TAM_Confederacion);



/*----------------------LISTADOS----------------------*/
void confederacionConMaximoContrato(eJugador arrayJugadores[], int TAM_Jugador, eConfederacion arrayConfederaciones[], int TAM_Confederacion);
void porcentajeJugadoresPorRegion(eJugador arrayJugadores[], int TAM_Jugador, eConfederacion arrayConfederaciones[],int TAM_Confederacion);
void regionConMasJugadores(eJugador arrayJugadores[], int TAM_Jugador, eConfederacion arrayConfederaciones[],int TAM_Confederacion);
/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR

int eJugador_Sort(eJugador array[], int TAM, int criterio, eConfederacion arrayConfederacion[], int TAM_Confederacion);
int jugador_ObtenerID(void);
