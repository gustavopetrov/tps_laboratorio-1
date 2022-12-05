#ifndef FIGURITAS
#define FIGURITAS
typedef struct
{
	int dia;
	int mes;
	int anio;
}sFecha;


typedef struct
{
	int idFigurita;
	char nombreJugador[50];
	char posicion[30];
//	char equipo[30];
	float altura;
	float peso;
	int anioIngreso;
	int idSeleccion; //FK - SELECCIONES
	int idClub; //FK - CLUB del JUGADOR
	int idRepresentante; //FK - REPRESENTANTE
	int estado;

	sFecha fechaNacimiento;
}sFiguritas;
/**
 * @brief Inicializo el array de figuritas con el estado libre
 *
 * @param figuritas
 * @param cantFiguritas
 */
void inicializarFiguritas(sFiguritas figuritas[], int cantFiguritas);

/**
 * @brief  Busco por un elemento que tenga el indice disponible
 *
 * @param figuritas
 * @param cantFiguritas
 * @return Retorno el indice del elemento
 */
int figuritas_indexLibre(sFiguritas figuritas[], int cantFiguritas);

/**
 * @brief  Busco el indice de un elemento a través de su ID
 *
 * @param figuritas
 * @param cantFiguritas
 * @param ID
 * @return retorno el indice del elemento que busque
 */
int figuritas_BuscarID(sFiguritas figuritas[],int cantFiguritas,int ID);

/**
 * @brief Valido que el array contenga almenos 1 elemento
 *
 * @param figuritas
 * @param cantFiguritas
 * @return retorno el índice del priemr elemento encontrado
 */
int validarArrayCargadoFiguritas(sFiguritas figuritas[], int cantFiguritas);
#endif
