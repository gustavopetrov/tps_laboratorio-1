#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inputs.h"
#include "e-s.h"
#include "figuritas.h"
#define LIBRE 0
#define OCUPADO 1


int validarArrayCargadoFiguritas(sFiguritas figuritas[], int cantFiguritas)
{
	int retorno;
	retorno = 1;
	if(figuritas != NULL && cantFiguritas > 0)
	{
		for(int i = 0; i < cantFiguritas; i++)
		{
			if(figuritas[i].estado == LIBRE)
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

int figuritas_indexLibre(sFiguritas figuritas[], int cantFiguritas)
{
	int index;
	index = -1;
	// checkeo los parámetros que sean válidos
	if(figuritas != NULL && cantFiguritas > 0)
	{
		//Recorro el array en busca de un índice libre
		for(int i = 0; i < cantFiguritas; i++)
		{
			if(figuritas[i].estado == LIBRE)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}
// buscar figurita por ID
int figuritas_BuscarID(sFiguritas figuritas[],int cantFiguritas, int ID)
{
	int index;
	index = -1;
	// checkeo los parámetros que sean válidos
	if(figuritas != NULL && cantFiguritas > 0)
	{
		//Recorro el array en busca del ID y estado ocupado
		for(int i = 0; i < cantFiguritas; i++)
		{
			if(figuritas[i].idFigurita == ID && figuritas[i].estado == OCUPADO)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}

// Inicializo el banco de datos de figuritas
void inicializarFiguritas(sFiguritas figuritas[], int cantFiguritas)
{
	// verifico los params
	if(figuritas != NULL && cantFiguritas > 0)
	{
		//Recorro e inicializo en libre
		for(int i = 0; i < cantFiguritas; i++)
		{
			figuritas[i].estado = LIBRE;
		}
	}
}









