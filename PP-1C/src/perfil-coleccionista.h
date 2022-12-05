#ifndef PERFIL_COLECCIONISTA_H_
#define PERFIL_COLECCIONISTA_H_
#include "perfil-administrador.h"

#define LIBRE 0
#define OCUPADO 1
#define CANT_FIGURITAS_SOBRE 5
#define CANT_FIGURITAS 55
typedef struct
{
	int idFigurita; // ID de la figurita
	int repetidas; // veces que se repitio la figurita

}sRepetidas;


int generarNumeroRandom(int min, int max);
/**
 * @brief inicializo el album
 *
 * @param album
 * @param cantFiguritas
 * @return
 */
sAlbum inicializarAlbum(sAlbum album, int cantFiguritas);
/**
 * @brief compro el paquete de figuritas
 *
 * @param album
 * @param figuritasRepetidas
 * @param figuritas
 * @param cantFiguritas
 * @param pContadorFiguritas
 * @return
 */
sAlbum comprarPaquete(sAlbum album,sRepetidas figuritasRepetidas[], sFiguritas figuritas[],int cantFiguritas, int *pContadorFiguritas);
/**
 * @brief pego una figurita en el album si es que no la tengo, si altengo la añado a repetidas
 *
 * @param figuritas
 * @param cantFiguritas
 * @param album
 * @param figuritasRepetidas
 * @param figurita
 * @return
 */
sAlbum pegarFigurita(sFiguritas figuritas[], int cantFiguritas, sAlbum album, sRepetidas figuritasRepetidas[],int figurita);

/**
 * @brief intercambiar figuritas pido una que necesite doy una repetida
 *
 * @param album
 * @param figuritasRepetidas
 * @param figuritas
 * @param cantFiguritas
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 * @return
 */
sAlbum intercambiarFigurita(sAlbum album,sRepetidas figuritasRepetidas[] ,sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
int verificarAlbumLleno(sAlbum album, int cantFiguritas);

/*--Repetidas--*/
/**
 * @brief inicializo el array de repetidas
 *
 * @param figuritasRepetidas
 * @param figurita
 * @param cantFiguritas
 */
void inicializarRepetidas(sRepetidas figuritasRepetidas[], sFiguritas figurita[], int cantFiguritas);
/**
 * @brief muestro las que me faltan
 *
 * @param album
 * @param figuritas
 * @param cantFiguritas
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 */
void mostrarFaltantes(sAlbum album,sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

/**
 * @brief muestro las repetidas
 *
 * @param figuritasRepetidas
 * @param figuritas
 * @param cantFiguritas
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 * @return
 */
int mostrarRepetidas(sRepetidas figuritasRepetidas[],sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
/**
 * @brief muestro las figuritas doradas
 *
 * @param album
 * @param figuritas
 * @param cantFiguritas
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 * @return
 */
int mostrarFiguritasDoradas(sAlbum album,sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
/**
 * @brief listo las figuritas pegadas
 *
 * @param album
 * @param figuritas
 * @param cantFiguritas
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 * @return
 */
int mostrarFiguritasPegadas(sAlbum album,sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

/**
 * @brief listo la lista de figuritas repetidas
 *
 * @param figuritasRepetidas
 * @param cantRepetidas
 * @param figuritaRepetida
 * @return
 */
int agregarFiguritasRepetidasPila(sRepetidas figuritasRepetidas[], int cantRepetidas, int figuritaRepetida);
/**
 * @brief verifico si la tengo repetida o no
 *
 * @param repetidas
 * @param cantFiguritas
 * @return
 */
int verificarRepetidas(sRepetidas repetidas[],int cantFiguritas);

/*--Informes--*/
/**
 * @brief muestro cuantos paqutes me tomo llenar el album
 *
 * @param sobresHastaLlenarElAlbum
 * @param album
 */
void mostrarPaquetesLleno(int sobresHastaLlenarElAlbum,sAlbum album);
/**
 * @brief informo cuanta plata llevo gastando
 *
 * @param plataGastada
 */
void mostrarPlataGastada(int plataGastada);
/**
 * @brief informo cuanta plata me costo llenar el album
 *
 * @param plataGastadaHastaLlenarAlbum
 * @param album
 */
void mostrarPlataGastadaHastaLlenarlo(int plataGastadaHastaLlenarAlbum,sAlbum album );



/*--Menú--*/
void menu_Perfil_Coleccionista(sAlbum album,sRepetidas figuritasRepetidas[], sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes );


#endif
