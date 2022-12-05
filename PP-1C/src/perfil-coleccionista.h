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
sAlbum inicializarAlbum(sAlbum album, int cantFiguritas);
sAlbum comprarPaquete(sAlbum album,sRepetidas figuritasRepetidas[], sFiguritas figuritas[],int cantFiguritas, int *pContadorFiguritas);
sAlbum pegarFigurita(sFiguritas figuritas[], int cantFiguritas, sAlbum album, sRepetidas figuritasRepetidas[],int figurita);
sAlbum intercambiarFigurita(sAlbum album,sRepetidas figuritasRepetidas[] ,sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
int verificarAlbumLleno(sAlbum album, int cantFiguritas);

/*--Repetidas--*/
void inicializarRepetidas(sRepetidas figuritasRepetidas[], sFiguritas figurita[], int cantFiguritas);
void mostrarFaltantes(sAlbum album,sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
int mostrarRepetidas(sRepetidas figuritasRepetidas[],sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
int mostrarFiguritasDoradas(sAlbum album,sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
int mostrarFiguritasPegadas(sAlbum album,sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
int agregarFiguritasRepetidasPila(sRepetidas figuritasRepetidas[], int cantRepetidas, int figuritaRepetida);
int verificarRepetidas(sRepetidas repetidas[],int cantFiguritas);

/*--Informes--*/
void mostrarPaquetesLleno(int sobresHastaLlenarElAlbum,sAlbum album);
void mostrarPlataGastada(int plataGastada);
void mostrarPlataGastadaHastaLlenarlo(int plataGastadaHastaLlenarAlbum,sAlbum album );



/*--Menú--*/
void menu_Perfil_Coleccionista(sAlbum album,sRepetidas figuritasRepetidas[], sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes );


#endif
