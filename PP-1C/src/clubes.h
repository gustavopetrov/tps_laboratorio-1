#ifndef CLUBES
#define CLUBES
typedef struct
{
	int idClub;
	char nombre[50];
	char descripcion[1024]; // campo alfanumerico
	int anioCreacion;
	int estado;
}sClub;

/**
 * @brief Inicializo el array de clubes con el estado libre
 *
 * @param clubes
 * @param tamClub
 */
void inicializarClubes(sClub clubes[], int tamClub);

/**
 * @brief Valido que haya aun que sea un indice ocupado
 *
 * @param clubes
 * @param tamClub
 * @return -1 array vacío, 1 array ocupado
 */
int validarArrayCargadoClubes(sClub clubes[], int tamClub);
/**
 * @brief Busco en el array un elemento con el estado libre
 *
 * @param clubes
 * @param tamClub
 * @return retorno el indice del elemento disponible
 */
int clubes_IndexLibre(sClub clubes[], int tamClub);

/**
 * @brief Busco un elemento a través del ID
 *
 * @param clubes
 * @param tamClube
 * @param id
 * @return retorno el índice del elemento encontrado
 */
int clubes_BuscarID(sClub clubes[], int tamClub, int id);

/**
 * @brief printf de un club
 *
 * @param Club
 */
void clubes_MostrarUno(sClub Club);


/**
 * @brief printf de todos los clubes
 *
 * @param clubes
 * @param tamClub
 * @return
 */
int clubes_MostrarTodos(sClub clubes[], int tamClub);

/**
 * @brief creo un solo club
 *
 * @return
 */
sClub generarClub();

/**
 * @brief genero el id del club, setteo su estado en ocupado y la inserto en el array con index disponible
 *
 * @param clubes
 * @param tamClub
 * @return
 */
int altaClub(sClub clubes[], int tamClub);

int modificarUnClub(sClub clubes[],int tamClub);

sClub clubes_ModificarNombre(sClub Club);
sClub clubes_ModificarDescripcion(sClub Club);
sClub clubes_ModificaranioCreacion(sClub Club);

#endif
