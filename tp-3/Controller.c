#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "e-s.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	FILE * pArchivo;
	pArchivo = fopen(path,"r");
	parser_JugadorFromText(pArchivo, pArrayListJugador);
	fclose(pArchivo);
    return 1;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
    int retorno;
    retorno = 0;
    Jugador* jugadorAux;
    FILE * pArchivo;
    pArchivo = fopen(path,"rb");
    if(pArchivo != NULL)
    {
    	jugadorAux = jug_new();
    	while(!feof(pArchivo))
    	{

			fread(jugadorAux,sizeof(Jugador),1,pArchivo);
			if(feof(pArchivo))
			{
				break;
			}
			mostrarJugadorBinario(jugadorAux);

    	}


    	fclose(pArchivo);

    }

	return retorno;
}
/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */

int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	LinkedList* listaJugadoresConvocadosPorConfederacion = ll_newLinkedList();
	int retorno = 0;
	int id;
	int tamNuevaLinkedList;
	char confederacionAux[30];
	char confederacionSeleccionAux[30];
	id = idConfederacion(pArrayListJugador);
	switch(id)
	{
	case 1:
		strcpy(confederacionAux,"AFC");
		break;
	case 2:
		strcpy(confederacionAux,"CAF");
		break;
	case 3:
		strcpy(confederacionAux,"CONCACAF");
		break;
	case 4:
		strcpy(confederacionAux,"CONMEBOL");
		break;
	case 5:
		strcpy(confederacionAux,"UEFA");
		break;
	}
	Jugador* jugadorAux;
	Seleccion* seleccionAux;
	int tamJugadores;
	int tamSelecciones;
	int idSeleccionJugadorAux;
	int idSeleccion;


	tamJugadores = ll_len(pArrayListJugador);
	tamSelecciones = ll_len(pArrayListSeleccion);

	for(int i = 0; i < tamJugadores; i++)
	{
		jugadorAux = (Jugador*)ll_get(pArrayListJugador, i);
		jug_getSIdSeleccion(jugadorAux, &idSeleccionJugadorAux);
		if(idSeleccionJugadorAux != 0)
		{
			for(int j = 0; j < tamSelecciones; j++)
				{
					seleccionAux = (Seleccion*)ll_get(pArrayListSeleccion, j);
					selec_getId(seleccionAux, &idSeleccion);
					if(idSeleccion == idSeleccionJugadorAux)
					{
						selec_getConfederacion(seleccionAux, confederacionSeleccionAux);
						if(stricmp(confederacionAux,confederacionSeleccionAux) == 0)
						{
							ll_add(listaJugadoresConvocadosPorConfederacion, jugadorAux);
						}
					}
				}
		}

	}

	FILE * pArchivo;
	pArchivo = fopen(path, "wb");
	if(pArchivo != NULL)
	{
		tamNuevaLinkedList = ll_len(listaJugadoresConvocadosPorConfederacion);
		for(int i = 0; i < tamNuevaLinkedList; i++)
		{
			jugadorAux = (Jugador*)ll_get(listaJugadoresConvocadosPorConfederacion, i);
			fwrite(jugadorAux,sizeof(Jugador),1,pArchivo);
			retorno = 1;
		}

	}
	fclose(pArchivo);
	ll_deleteLinkedList(listaJugadoresConvocadosPorConfederacion);
	return retorno;
}
/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int retorno;
	retorno = 0;
	int id;
	char idAux[100];
	char nombreAux[100];
	char edadAux[100];
	char posicionAux[100];
	char nacionalidadAux[100];
	char idSeleccionAux[100] = "0";

	Jugador* unJugador;
	unJugador = NULL;

	if(pArrayListJugador != NULL)
	{
		retorno = 1;
		id = obtenerID();
		sprintf(idAux,"%d",id);
		getString(nombreAux, 100, "\nIngrese Nombre", "\nERROR!");
		getString(edadAux, 100, "\nIngrese Edad", "\nERROR!");
		getString(posicionAux, 100, "\nIngrese Posicion", "\nERROR!");
		getString(nacionalidadAux, 100, "\nIngrese Nacionalidad","\nERROR!");
		getString(idSeleccionAux, 100, "\nIngrese Seleccion", "\nERROR!");
	unJugador = jug_newParametros(idAux, nombreAux, edadAux, posicionAux, nacionalidadAux, idSeleccionAux);
	ll_add(pArrayListJugador, unJugador);
	printf("Se agrego un jugador");
	}
    return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int rta;
	int i;
	i = buscarIDLinkedList(pArrayListJugador);
	rta = menuModificacionJugadores(pArrayListJugador, i);
    return rta;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
	int rta;
	int i;
	i = buscarIDLinkedList(pArrayListJugador);
	rta = menuRemoverJugador(pArrayListJugador, i);

    return rta;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno;
	Jugador* jugadorAux;
	retorno = 0;
	int cant;
	int idAux;
	char nombreAux[100];
	int edadAux;
	char posicionAux[100];
	char nacionalidadAux[100];
	int idSeleccionAux;

	cant = ll_len(pArrayListJugador);
	printf("%d",cant);
	for(int i = 0; i < cant; i++)
	{
		jugadorAux = ll_get(pArrayListJugador, i);
		jug_getId(jugadorAux, &idAux);
		jug_getNombreCompleto(jugadorAux, nombreAux);
		jug_getEdad(jugadorAux, &edadAux);
		jug_getPosicion(jugadorAux, posicionAux);
		jug_getNacionalidad(jugadorAux, nacionalidadAux);
		jug_getSIdSeleccion(jugadorAux, &idSeleccionAux);
		printf("\n%4d | %-30s | %-25s | %-20s | %-2d | %-2d", idAux, nombreAux, posicionAux, nacionalidadAux, edadAux, idSeleccionAux );
	}


    return retorno;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int retorno;
	retorno = 0;

    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	FILE * pArchivo;
	pArchivo = fopen(path,"w");
	if(pArchivo != NULL)
	{
		parser_GuardarJugadorTexto(pArchivo,pArrayListJugador);
	}
	fclose(pArchivo);

    return 1;
}


/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	FILE * pArchivo;
	pArchivo = fopen(path,"w");
	if(pArchivo != NULL)
	{
		parser_guardarSeleccionesTexto(pArchivo,pArrayListSeleccion);
	}
	fclose(pArchivo);
    return 1;
}

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	FILE * pArchivo;
	pArchivo = fopen(path, "r");
	parser_SeleccionFromText(pArchivo, pArrayListSeleccion);
	fclose(pArchivo);
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno;
	retorno = 0;
	Seleccion* seleccionAux;
	int cant;
	int idAux;
	char paisAux[100];
	char confederacionAux[100];
	int convocadosAux;

	cant = ll_len(pArrayListSeleccion);
	for(int i = 0; i < cant; i++)
	{
		seleccionAux = (Seleccion*)ll_get(pArrayListSeleccion, i);
		selec_getId(seleccionAux, &idAux);
		selec_getPais(seleccionAux, paisAux);
		selec_getConfederacion(seleccionAux, confederacionAux);
		selec_getConvocados(seleccionAux, &convocadosAux);

		printf("\n %4d | %-25s | %-20s | %-2d",idAux, paisAux, confederacionAux, convocadosAux);
		retorno = 1;
	}


    return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/**
 * @brief listo los jugadores convocados
 *
 * @param pArrayListJugador
 */
void controller_listarJugadoresConvocados(LinkedList* pArrayListJugador)
{
	Jugador* unJugador;


	int tam;
	char nombreAux[NOMBRE_LEN];
	char posicionAux[100];
	char nacionalidadAux[100];
	int edadAux;
	int idSeleccionAux;
	int idAux;


	tam = ll_len(pArrayListJugador);
	for(int i = 0; i<tam; i++)
	{
		unJugador = (Jugador*)ll_get(pArrayListJugador, i);
		jug_getSIdSeleccion(unJugador, &idSeleccionAux);
		if( idSeleccionAux != 0)
		{

			jug_getNombreCompleto(unJugador, nombreAux);
			jug_getPosicion(unJugador, posicionAux);
			jug_getNacionalidad(unJugador, nacionalidadAux);
			jug_getEdad(unJugador, &edadAux);
			jug_getId(unJugador, &idAux);
			printf("\n |%-2d |%-30s | %-25s | %-20s | %-2d",idAux, nombreAux, posicionAux, nacionalidadAux, edadAux);
		}
	}
}

/**
 * @brief Convoca jugadores, obtengo el índice del jugador y traigo los datos. si se puede convocar lo convoca dond el usuario elija  y aumenta los convocados en la estructura seleccion
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return
 */
int controller_jugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int rta;
	rta = 0;
	int i;
	int id;
	int rtaJugadores;
	int rtaSelecciones;
	Jugador* unJugador;

	i = buscarIDLinkedList(pArrayListJugador);
	unJugador = (Jugador*)ll_get(pArrayListJugador, i);
	rtaJugadores = mostrarUnJugador(unJugador);
	if(rtaJugadores)
	{
		printf("\nSeleccione un ID de la lista donde lo desea convocar");
		listarSelecciones(pArrayListSeleccion);
		getInt(&id, "\nIngrese el ID de la seleccion", "\nError!", 1, 5000);

		rtaSelecciones = seleccionarIDdeLaLista(pArrayListSeleccion,id);

	}else
	{
		printf("Error!");
	}

	if(rtaSelecciones)
	{
		modificarIdSeleccion(unJugador, id);
		rta = 1;
	}
	return rta;
}
int controller_desconvocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int errores;
	int rta;
	errores = 0;
	Jugador* jugadorAux;
	Seleccion* seleccionAux;
	int i;
	int iSeleccion;
	int idNacionalidadAux = 0;
	int cantConvocados;
	controller_listarJugadoresConvocados(pArrayListJugador);
	i=buscarIDLinkedList(pArrayListJugador);
	jugadorAux = (Jugador*)ll_get(pArrayListJugador, i);
	if(jug_getSIdSeleccion(jugadorAux, &idNacionalidadAux) == 0)
	{
		errores++;
	}
	if(jug_setIdSeleccion(jugadorAux, 0) == 0)
	{
		errores++;
	}
	iSeleccion = buscarIDSeleccionLinkedList(pArrayListSeleccion,idNacionalidadAux);
	printf("\nindice seleccion: %d",iSeleccion);
	seleccionAux =(Seleccion*)ll_get(pArrayListSeleccion, iSeleccion);
	if(selec_getConvocados(seleccionAux, &cantConvocados) == 0)
	{
		errores++;
	}
	cantConvocados--;
	if(selec_setConvocados(seleccionAux, cantConvocados) == 0)
	{
		errores++;
	}
	if(errores++ > 0)
	{
		rta = 0;
	}
	else
	{
		rta = 1;
	}
	return rta;
}
/**
 * @brief  Lista jugadores con la relacion entre estructura jugador y seleccion
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return
 */
int controller_listarJugadoresCustom(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	Jugador* jugadorAux;
	Seleccion* seleccionAux;
	int tamJugadores;
	int tamSelecciones;
	//variables jugador
	int idAux;
	char nombreAux[100];
	char posicionAux[100];
	char nacionalidadAux[100];
	int edadAux;
	int idSeleccionJugadorAux;
	char nombreSeleccionJugador[100] ="No convocado";
	//variable seleccion
	int idSeleccion;



	tamJugadores = ll_len(pArrayListJugador);
	tamSelecciones = ll_len(pArrayListSeleccion);

	for(int i = 0; i < tamJugadores; i++)
	{
		strcpy(nombreSeleccionJugador,"No convocado");
		jugadorAux = (Jugador*)ll_get(pArrayListJugador, i);
		jug_getId(jugadorAux, &idAux);
		jug_getNombreCompleto(jugadorAux, nombreAux);
		jug_getEdad(jugadorAux, &edadAux);
		jug_getPosicion(jugadorAux, posicionAux);
		jug_getNacionalidad(jugadorAux, nacionalidadAux);
		jug_getSIdSeleccion(jugadorAux, &idSeleccionJugadorAux);

		for(int j = 0; j < tamSelecciones; j++)
		{

			seleccionAux = (Seleccion*)ll_get(pArrayListSeleccion, j);

			selec_getId(seleccionAux, &idSeleccion);

			if(idSeleccion == idSeleccionJugadorAux)
			{

				selec_getPais(seleccionAux, nombreSeleccionJugador);

				break;
			}
		}
		printf("\n%4d | %-30s | %-25s | %-20s | %-2d | %-25s", idAux, nombreAux, posicionAux, nacionalidadAux, edadAux, nombreSeleccionJugador );
	}

	return 0;
}
/**
 * @brief ordena jugadores segun criterio: nacionalidad
 *
 * @param jugadorActual
 * @param siguienteJugador
 * @return
 */
int controller_ordenarJugadoresNacionalidad(void* jugadorActual, void* siguienteJugador)
{
	int retorno;
	Jugador* jugadorActualAux;
	char jugadorActualNacionalidad[30];
	Jugador* jugadorSiguienteAux;
	char jugadorSiguienteNacionalidad[30];
	jugadorSiguienteAux = (Jugador*)siguienteJugador;
	jugadorActualAux = (Jugador*)jugadorActual;
	retorno = 0;

	jug_getNacionalidad(jugadorActualAux, jugadorActualNacionalidad);
	jug_getNacionalidad(jugadorSiguienteAux, jugadorSiguienteNacionalidad);

	if(strcmp(jugadorActualNacionalidad,jugadorSiguienteNacionalidad) > 0)
	{
		retorno = 1;
	}

	return retorno;
}
/**
 * @brief ordena jugadores segun criterio: Edad
 *
 * @param jugadorActual
 * @param siguienteJugador
 * @return
 */
int controller_ordenarJugadoresPorEdad(void* jugadorActual, void* siguienteJugador)
{
	int retorno;
	retorno = 0;

	Jugador* jugadorActualAux;
	int jugadorActualEdad;
	Jugador* jugadorSiguienteAux;
	jugadorActualAux = (Jugador*)jugadorActual;
	jugadorSiguienteAux = (Jugador*)siguienteJugador;
	int jugadorSiguienteEdad;
	jug_getEdad(jugadorActualAux, &jugadorActualEdad);
	jug_getEdad(jugadorSiguienteAux,&jugadorSiguienteEdad);
	if(jugadorActualEdad > jugadorSiguienteEdad)
	{
		retorno = 1;
	}


	return retorno;
}
/**
 * @brief ordena jugadores segun criterio: Nombre
 *
 * @param jugadorActual
 * @param siguienteJugador
 * @return
 */
int controller_ordenarJugadoresNombre(void* jugadorActual, void* siguienteJugador)
{
	int retorno;
	Jugador* jugadorActualAux;
	char jugadorActualNombre[NOMBRE_LEN];
	Jugador* jugadorSiguienteAux;
	jugadorSiguienteAux = (Jugador*)siguienteJugador;
	jugadorActualAux = (Jugador*)jugadorActual;
	char jugadorSiguienteNombre[NOMBRE_LEN];
	retorno = 0;

	jug_getNombreCompleto(jugadorActualAux, jugadorActualNombre);
	jug_getNombreCompleto(jugadorSiguienteAux, jugadorSiguienteNombre);

	if(stricmp(jugadorActualNombre,jugadorSiguienteNombre) > 0)
	{
		retorno = 1;
	}

	return retorno;
}
/**
 * @brief ordena jugadores segun criterio: Confederacion
 *
 * @param seleccionActual
 * @param siguienteSeleccion
 * @return
 */
int controller_ordenarSeleccionesConfederacion(void* seleccionActual, void* siguienteSeleccion)
{
	int retorno;
	Seleccion* seleccionActualAux;
	char seleccionActualConfederacion[30];
	Seleccion* siguienteSeleccionAux;
	char siguienteSeleccionConfederacion[30];
	seleccionActualAux = (Seleccion*)seleccionActual;
	siguienteSeleccionAux = (Seleccion*)siguienteSeleccion;

	selec_getConfederacion(seleccionActualAux, seleccionActualConfederacion);
	selec_getConfederacion(siguienteSeleccionAux, siguienteSeleccionConfederacion);

	if(strcmp(seleccionActualConfederacion,siguienteSeleccionConfederacion) > 0)
	{
		retorno = 1;
	}

	return retorno;
}
