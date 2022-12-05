#ifndef REPRESENTANTES
#define REPRESENTANTES
typedef struct{
	int idRepresentante; //PK
	char nombre[50];
	char apellido[50];
	char descripcion[1024]; // Campo alfanumerico
	float honorarios;
	int estado;
}sRepresentantes;

/**
 * @brief Inicializo el array de representantes con sus espacios en libre
 *
 * @param representantes
 * @param tamRepresentantes
 */
void inicializarRepresentantes(sRepresentantes representantes[], int tamRepresentantes);


/**
 * @brief Valido que haya aun que sea un indice ocupado
 *
 * @param representantes
 * @param tamRepresentantes
 * @return -1 array vacío, 1 array ocupado
 */
int validarArrayCargadoRepresentantes(sRepresentantes representantes[], int tamRepresentantes);

/**
 * @brief  Busco por un elemento que tenga el indice disponible
 *
 * @param representantes
 * @param tamRepresentantes
 * @return Retorno el indice del elemento
 */
int representantes_IndexLibre(sRepresentantes representantes[], int tamRepresentantes);

/**
 * @brief Busco el indice de un elemento a través de su ID
 *
 * @param representantes
 * @param tamRepresentantes
 * @param id
 * @return retorno el indice del elemento que busque
 */
int representantes_BuscarID(sRepresentantes representantes[], int tamRepresentantes, int id);

/**
 * @brief printf de un representante
 *
 * @param Representante
 * @return
 */
void representante_MostrarUno(sRepresentantes Representante);

/**
 * @brief printf de todas las confederacion
 *
 * @param representantes
 * @param tamRepresentantes
 * @return 1 todo ok, -1 error
 */
int representante_MostrarTodos(sRepresentantes representantes[], int tamRepresentantes);

/**
 * @brief Creo un Representante
 *
 * @return
 */
sRepresentantes generarRepresentante();

/**
 * @brief gener el id de la confederacion, setteo su estado en ocupado y la inserto en el array con index disponible
 *
 * @param representantes
 * @param tamRepresentantes
 * @return 1 todo ok, -1 error
 */
int altaRepresentante(sRepresentantes representantes[], int tamRepresentantes);
/**
 * @brief menu de representantes con switch y control de estado (si puedo modificar o no)
 *
 * @param representantes
 * @param tamRepresentantes
 * @return
 */
int modificarUnRepresentante(sRepresentantes representantes[], int tamRepresentantes);

/**
 * @brief modifico nombre del representante
 *
 * @param Representante
 * @return
 */
sRepresentantes representantes_ModificarNombre(sRepresentantes Representante);
/**
 * @brief modifico apellido del representante
 *
 * @param Representante
 * @return
 */
sRepresentantes representantes_ModificarApellido(sRepresentantes Representante);
/**
 * @brief modifico Descripción del representante
 *
 * @param Representante
 * @return
 */
sRepresentantes representantes_ModificarDescripcion(sRepresentantes Representante);
/**
 * @brief modifico honorarios(cuanto cobra)  del representante
 *
 * @param Representante
 * @return
 */
sRepresentantes representantes_ModificarHonorarios(sRepresentantes Representante);
#endif
