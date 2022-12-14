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

/**
 * @brief  Menu donde se elije que figu modificar
 *
 * @param figuritas
 * @param cantFiguritas
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 * @return retorno en la posicion del array el auxiliar
 */

int modificarUnaFigurita(sFiguritas figuritas[],int cantFiguritas,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

/**
 * @brief Modificar NOMBRE FIGURITA
 *
 * @param figurita
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 * @return retorno la figurita con los cambios aplicados
 */
sFiguritas figurita_ModificarNombre(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

/**
 * @brief Modifica la posicion de la figurita
 *
 * @param figurita
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 * @return retorno la figurita con los cambios aplicados
 */
sFiguritas figurita_ModificarPosicion(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

/**
 * @brief Modifica la altura de la figurita
 *
 * @param figurita
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 * @return retorno la figurita con los cambios aplicados
 */
sFiguritas figurita_ModificarAltura(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

/**
 * @brief Modifica el peso de la figurita
 *
 * @param figurita
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 * @return retorno la figurita con los cambios aplicados
 */
sFiguritas figurita_ModificarPeso(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
/**
 * @brief modifica el a??o de ingreso a la selecc
 *
 * @param figurita
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 * @return retorno la figurita con los cambios aplicados
 */
sFiguritas figurita_ModificarIngreso(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
/**
 * @brief Modifica la seleccion de la figurita
 *
 * @param figurita
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 * @return retorno la figurita con los cambios aplicados
 */
sFiguritas figurita_ModificarSeleccion(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
/**
 * @brief modifica el club de la figurita
 *
 * @param figurita
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 * @return
 */
sFiguritas figurita_ModificarClub(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
/**
 * @brief Modifica el representante asociado a la figurita
 *
 * @param figurita
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 * @return retorno la figurita con los cambios aplicados
 */
sFiguritas figurita_ModificarRepresentante(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);
/**
 * @brief Validar que no este con 22 jugadores la selecci??n que ingrese el usuario
 *
 * @param idSeleccionAux
 * @param selecciones
 * @param tamSeleccion
 * @return retorno la figurita con los cambios aplicados
 */
int validarJugadoresSelecciones(int idSeleccionAux,sSeleccion selecciones[], int tamSeleccion);

/**
 * @brief obtengo el nombre del representante mediante una relaci??n
 *
 * @param figurita
 * @param representantes
 * @param tamRepresentantes
 * @param nombreRepresentanteAux
 * @return
 */
int representantes_ObtenerNombre(sFiguritas figurita, sRepresentantes representantes[], int tamRepresentantes,char* nombreRepresentanteAux);
/**
 * @brief obtengo el nombre de la seleccion mediante una relaci??n
 *
 * @param unaFigurita
 * @param selecciones
 * @param tamSeleccion
 * @param nombreSeleccionAux
 * @return
 */
int selecciones_ObtenerNombre(sFiguritas unaFigurita, sSeleccion selecciones[], int tamSeleccion,char* nombreSeleccionAux);
/**
 * @brief obtengo el nombre del club mediante una relaci??n
 *
 * @param unaFigurita
 * @param clubes
 * @param tamClub
 * @param nombreClubAux
 * @return
 */
int clubes_ObtenerNombre(sFiguritas unaFigurita, sClub clubes[], int tamClub, char* nombreClubAux);

/**
 * @brief ordena por nombre
 *
 * @param figurita
 * @param tamFiguritas
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 * @param criterioOrdenamiento
 * @return
 */
int figuritas_sortClub(sFiguritas figurita[],int tamFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes, int criterioOrdenamiento);

/**
 * @briefo ordena por cantidad de jugadores
 *
 * @param figurita
 * @param tamFiguritas
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 * @param criterioOrdenamiento
 * @return
 */
int seleccion_sortCantJugadores(sFiguritas figurita[],int tamFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes, int criterioOrdenamiento);

/**
 * @brief ordena por precio de representante
 *
 * @param figurita
 * @param tamFiguritas
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 * @param criterioOrdenamiento
 * @return
 */
int representantes_sortHonorarios(sFiguritas figurita[],int tamFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes, int criterioOrdenamiento);


/**
 * @brief listo las figuritas asociadas al representante
 *
 * @param figuritas
 * @param cantFiguritas
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 */
void representantes_filter(sFiguritas figuritas[],int cantFiguritas,sClub clubes[],int tamClub,sSeleccion selecciones[],int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

/**
 * @brief listo figuritas asociadas a la seleccion
 *
 * @param figuritas
 * @param cantFiguritas
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 */
void selecciones_filter(sFiguritas figuritas[],int cantFiguritas,sClub clubes[],int tamClub,sSeleccion selecciones[],int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

/**
 * @brief listo figuritas asociadas al clubs
 *
 * @param figuritas
 * @param cantFiguritas
 * @param clubes
 * @param tamClub
 * @param selecciones
 * @param tamSeleccion
 * @param representantes
 * @param tamRepresentantes
 */
void clubes_filter(sFiguritas figuritas[],int cantFiguritas,sClub clubes[],int tamClub,sSeleccion selecciones[],int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);






/*----------MEN??----------*/
void menu_Perfil_Administrador(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

void menu_Perfil_Administrador_Altas(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

void menu_Perfil_Administrador_Modificaciones(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

void menu_Perfil_Administrador_Sort(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

void menu_Perfil_Administrador_Listados(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

void menu_Perfil_Administrador_SubMenuListados(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes);

#endif
