#ifndef SELECCIONES
#define SELECCIONES
typedef struct {
	int idSeleccion; // PK - jugadores
	char nombreSeleccion[50];
	char directorTecnico[50];
	int estado;
	int contador;
}sSeleccion;

typedef struct
{
	int idSeleccionAux;
	int contador;
}sSeleccionAux;


/**
 * @brief Inicializo el array de selecciones con estado libre
 *
 * @param selecciones
 * @param tamSeleccion
 */
void inicializarSelecciones(sSeleccion selecciones[], int tamSeleccion);


int validarArrayCargadoSelecciones(sSeleccion selecciones[], int tamSeleccion);

/**
 * @brief Busco por un elemento que tenga el indice disponible
 *
 * @param selecciones
 * @param tamSeleccion
 * @return Retorno el indice del elemento
 */
int selecciones_IndexLibre(sSeleccion selecciones[],int tamSeleccion);

/**
 * @brief Busco el indice de un elemento a través de su ID
 *
 * @param selecciones
 * @param tamSeleccion
 * @param id
 * @return retorno el indice del elemento que busque
 */
int selecciones_BuscarID(sSeleccion selecciones[], int tamSeleccion, int id);

/**
 * @brief printf de una seleccion
 *
 * @param Seleccion
 */
void selecciones_MostrarUna(sSeleccion Seleccion);

/**
 * @brief printf de todas las selecciones
 *
 * @param selecciones
 * @param tamSeleccion
 * @return
 */
int selecciones_MostrarTodas(sSeleccion selecciones[], int tamSeleccion);

/**
 * @brief Creo una seleccion
 *
 * @return
 */
sSeleccion generarSeleccion();

/**
 * @brief gener el id de la seleccion, setteo su estado en ocupado y la inserto en el array con index disponible
 *
 * @param selecciones
 * @param tamSeleccion
 * @return 1 todo ok, -1 error
 */
int altaSeleccion(sSeleccion selecciones[], int tamSeleccion);

/**
 * @brief Modifico una selección
 *
 * @param selecciones
 * @param tamSeleccion
 * @return
 */
int modificarUnaSeleccion(sSeleccion selecciones[], int tamSeleccion);

/**
 * @brief  Modifico el DT de una selección
 *
 * @param Seleccion
 * @return retorna la selección con el nuevo DT
 */
sSeleccion selecciones_ModificarDT(sSeleccion Seleccion);

/**
 * @brief Modifico el NOMBRE de una selección
 *
 * @param Seleccion
 * @return retorna la selección con el nuevo NOMBRE
 */
sSeleccion selecciones_ModificarNombre(sSeleccion Seleccion);

#endif
