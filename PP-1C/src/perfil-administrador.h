#ifndef PERFIL_ADMINISTRADOR
#define PERFIL_ADMINISTRADOR
#include "figuritas.h"
#include "clubes.h"
#include "selecciones.h"
#include "representantes.h"
#include "album.h"




/**
 * @brief  Creo una Figurita
 *
 * @return
 */
sFiguritas generarFigurita(sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
/**
 * @brief Genero el ID de la figurita, setteo su estado en ocupado y la inserto en el array con index disponible
 *
 * @param figuritas
 * @param cantFiguritas
 * @return 1 todo ok, 0 error
 */
int altaFigurita(sFiguritas figuritas[], int cantFiguritas,sClub clubes[],int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
/**
 * @brief  printf de una seleccion
 *
 * @param unaFigurita
 */
void figurita_MostrarUna(sFiguritas unaFigurita,sClub clubes[],int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

/**
 * @brief  printf de todas las selecciones
 *
 * @param figuritas
 * @param cantFiguritas
 * @return 1 todo ok, 0 error
 */
int figurita_MostrarTodas(sFiguritas figuritas[],int cantFiguritas,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

int modificarUnaFigurita(sFiguritas figuritas[],int cantFiguritas,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

sFiguritas figurita_ModificarNombre(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
sFiguritas figurita_ModificarPosicion(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

sFiguritas figurita_ModificarAltura(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
sFiguritas figurita_ModificarPeso(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
sFiguritas figurita_ModificarIngreso(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
sFiguritas figurita_ModificarSeleccion(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
sFiguritas figurita_ModificarClub(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
sFiguritas figurita_ModificarRepresentante(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
/**
 * @brief Validar que no este con 22 jugadores la selección que ingrese el usuario
 *
 * @param idSeleccionAux
 * @param selecciones
 * @param tamSeleccion
 * @return
 */
int validarJugadoresSelecciones(int idSeleccionAux,sSeleccion selecciones[], int tamSeleccion);

int representantes_ObtenerNombre(sFiguritas figurita, sRepresentantes representantes[], int tamRepresentantes,char* nombreRepresentanteAux);
int selecciones_ObtenerNombre(sFiguritas unaFigurita, sSeleccion selecciones[], int tamSeleccion,char* nombreSeleccionAux);
int clubes_ObtenerNombre(sFiguritas unaFigurita, sClub clubes[], int tamClub, char* nombreClubAux);


int figuritas_sortClub(sFiguritas figurita[],int tamFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes, int criterioOrdenamiento);

int seleccion_sortCantJugadores(sFiguritas figurita[],int tamFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes, int criterioOrdenamiento);

int representantes_sortHonorarios(sFiguritas figurita[],int tamFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes, int criterioOrdenamiento);



void representantes_filter(sFiguritas figuritas[],int cantFiguritas,sClub clubes[],int tamClub,sSeleccion selecciones[],int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

void selecciones_filter(sFiguritas figuritas[],int cantFiguritas,sClub clubes[],int tamClub,sSeleccion selecciones[],int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

void clubes_filter(sFiguritas figuritas[],int cantFiguritas,sClub clubes[],int tamClub,sSeleccion selecciones[],int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);






/*----------MENÚ----------*/
void menu_Perfil_Administrador(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

void menu_Perfil_Administrador_Altas(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

void menu_Perfil_Administrador_Modificaciones(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

void menu_Perfil_Administrador_Sort(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

void menu_Perfil_Administrador_Listados(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

void menu_Perfil_Administrador_SubMenuListados(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

#endif
