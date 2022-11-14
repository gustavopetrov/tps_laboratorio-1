#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inputs.h"
#include "Seleccion.h"
/**
 * @brief reservo espacio en memoria dinámica para crear selecciones
 *
 * @return
 */
Seleccion* selec_new()
{
	Seleccion* unaSeleccion;
	unaSeleccion = (Seleccion*)malloc(sizeof(Seleccion));
	return unaSeleccion;
}
/**
 * @brief constructor de selecciones
 *
 * @param idStr
 * @param paisStr
 * @param confederacionStr
 * @param convocadosStr
 * @return
 */
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* unaSeleccion;
	unaSeleccion = selec_new();

	unaSeleccion->id = atoi(idStr);
	strncpy(unaSeleccion->pais,paisStr,30);
	strncpy(unaSeleccion->confederacion,confederacionStr,30);
	unaSeleccion->convocados = atoi(convocadosStr);


	return unaSeleccion;
}
/**
 * @brief elimina una seleccion de memoria dinámica
 *
 * @param this
 */
void selec_delete(Seleccion* this)
{
	if(this != NULL)
	{
	free(this);
	}
}
/**
 * @brief obtengo el ID
 *
 * @param this
 * @param id
 * @return
 */
int selec_getId(Seleccion* this,int* id)
{
	int retorno;
	retorno = 0;
	if(this != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}
/**
 * @brief obtengo el pais
 *
 * @param this
 * @param pais
 * @return
 */
int selec_getPais(Seleccion* this,char* pais)
{
	int retorno;
	retorno = 0;
	if(this != NULL && pais != NULL)
	{
		strcpy(pais,this->pais);
		retorno = 1;
	}
	return retorno;
}
/**
 * @brief obtengo la confederacion
 *
 * @param this
 * @param confederacion
 * @return
 */
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	if( this != NULL && confederacion != NULL)
	{
		strcpy(confederacion,this->confederacion);
	}
	return 0;
}
/**
 * @brief setteo los convocados
 *
 * @param this
 * @param convocados
 * @return
 */
int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno;
	retorno = 0;
	if(this!= NULL)
	{
		this->convocados = convocados;
		retorno = 1;
	}
	return retorno;
}
/**
 * @brief obtengo los convocados
 *
 * @param this
 * @param convocados
 * @return
 */
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno;
	retorno = 0;
	if(this != NULL && convocados != NULL)
	{
		*convocados = this->convocados;
		retorno = 1;
	}
	return retorno;
}
/**
 * @brief listar selecciones
 *
 * @param pArrayListSeleccion
 * @return
 */
int listarSelecciones(LinkedList* pArrayListSeleccion)
{
	Seleccion* seleccionAux;
	int idSeleccion;
	char paisAux[100];
	char confederacionAux[100];

	int tam;
	tam = ll_len(pArrayListSeleccion);
	for(int i = 0; i < tam; i++)
	{
		seleccionAux = (Seleccion*)ll_get(pArrayListSeleccion, i);
		selec_getId(seleccionAux, &idSeleccion);
		selec_getPais(seleccionAux, paisAux);
		selec_getConfederacion(seleccionAux, confederacionAux);


		printf("\n | %4d | %-25s | %-20s ",idSeleccion,paisAux,confederacionAux);
	}

	return 0;
}
/**
 * @brief obtengo el ID de la seleccion y lo comparo con el ID que recibo por parámetro, si hay match retorno el índice
 *
 * @param pArrayListSeleccion
 * @param idSeleccion
 * @return
 */
int buscarIDSeleccionLinkedList(LinkedList* pArrayListSeleccion,int idSeleccion)
{
	int id;
	int retorno;
	int cant;
	Seleccion* auxiliar;
	cant = ll_len(pArrayListSeleccion);
	for(int i = 0; i < cant ; i++)
	{
		auxiliar = (Seleccion*)ll_get(pArrayListSeleccion,i);
		selec_getId(auxiliar, &id);
		if(id == idSeleccion)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}
/**
 * @brief funcion que devuelve el ID de la lista de selecciones, y si hay match entre los id aumenta en 1 los convocados
 *
 * @param pArrayListSeleccion
 * @param id
 * @return
 */
int seleccionarIDdeLaLista(LinkedList* pArrayListSeleccion,int id)
{
	int retorno;
	retorno = 0;
	Seleccion* seleccionAux;
	int tam;
	int idAux;
	int cantConvocados;
	tam = ll_len(pArrayListSeleccion);

	for(int i = 0; i < tam; i++)
	{
		seleccionAux = (Seleccion*)ll_get(pArrayListSeleccion, i);
		selec_getConvocados(seleccionAux, &cantConvocados);
		selec_getId(seleccionAux, &idAux);
		if( idAux == id )
		{
			if(cantConvocados == 22 )
			{
				printf("Error! Selección ocupada");
				break;
			}else
			{
				cantConvocados++;

				selec_setConvocados(seleccionAux, cantConvocados);

				retorno = 1;
			}

			break;
		}

	}
	return retorno;
}
