#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
/**
 * @brief guardo los cambios de jugadores en csv
 *
 * @param pArchivo
 * @param pArrayListJugador
 * @return
 */
int parser_GuardarJugadorTexto(FILE* pArchivo , LinkedList* pArrayListJugador)
{
	Jugador* unJugador;
	int idAux;
	char nombreCompletoAux[NOMBRE_LEN];
	int edadAux;
	char posicionAux[100];
	char nacionalidadAux[100];
	int idSeleccionAux;
	int tam;

	tam = ll_len(pArrayListJugador);
	fprintf(pArchivo,"id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");
	for(int i = 0; i < tam; i++)
	{
		unJugador = (Jugador*)ll_get(pArrayListJugador, i);
		jug_getId(unJugador, &idAux);
		jug_getNombreCompleto(unJugador, nombreCompletoAux);
		jug_getEdad(unJugador, &edadAux);
		jug_getPosicion(unJugador, posicionAux);
		jug_getNacionalidad(unJugador, nacionalidadAux);
		jug_getSIdSeleccion(unJugador, &idSeleccionAux);
		fprintf(pArchivo,"%d,%s,%d,%s,%s,%d\n",idAux,nombreCompletoAux,edadAux,posicionAux,nacionalidadAux,idSeleccionAux);
	}
	return 0;
}
/**
 * @brief guardo los cambios de selecciones en csv
 *
 * @param pArchivo
 * @param pArrayListSeleccion
 * @return
 */
int parser_guardarSeleccionesTexto(FILE* pArchivo , LinkedList* pArrayListSeleccion)
{
	Seleccion* seleccionAux;
	int idAux;
	char paisAux[30];
	char confederacionAux[30];
	int convocadosAux;
	int tam;

	tam = ll_len(pArrayListSeleccion);
	fprintf(pArchivo,"id,pais,confederacion,convocados\n");
	for(int i = 0; i < tam; i++)
	{
		seleccionAux =(Seleccion*)ll_get(pArrayListSeleccion, i);
		selec_getId(seleccionAux, &idAux);
		selec_getPais(seleccionAux, paisAux);
		selec_getConfederacion(seleccionAux, confederacionAux);
		selec_getConvocados(seleccionAux, &convocadosAux);
		fprintf(pArchivo,"%d,%s,%s,%d\n",idAux,paisAux,confederacionAux,convocadosAux);
	}

	return 0;
}

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno;
	retorno = 0;
	Jugador* unJugador;
	char id[100];
	char nombreCompleto[NOMBRE_LEN];
	char edad[100];
	char posicion[100];
	char nacionalidad[100];
	char idSeleccion[100];


	if(pFile != NULL && pArrayListJugador != NULL)
	{
		// lectura fantasma para las cabeceras
		fscanf(pFile,"%[^,], %[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);

		while(!feof(pFile))
		{	// split

			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
			unJugador = jug_newParametros(id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);

			ll_add(pArrayListJugador, unJugador);
		}

		retorno = 1;
	}
	return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	Jugador* unJugador;

	while(!feof(pFile))
	{
		unJugador = jug_new();
		fread(unJugador,sizeof(Jugador),1,pFile);
		if(feof(pFile))
		{
			// si fread da error - por que llego al final del archivo y da basura
			jug_delete(unJugador);
			break;
		}

		ll_add(pArrayListJugador, unJugador);
	}
    return 1;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno;
	retorno = 0;
	char id[100];
	char pais[100];
	char confederacion[100];
	char convocados[100];
	Seleccion* unaSeleccion;

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		// lectura fantasma cabeceras
		fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n",id,pais,confederacion,convocados);

		while(!feof(pFile))
		{
			// split
			fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n",id,pais,confederacion,convocados);
			unaSeleccion = selec_newParametros(id, pais, confederacion, convocados);

			ll_add(pArrayListSeleccion, unaSeleccion);
		}

		retorno = 1;
	}
    return retorno;
}
