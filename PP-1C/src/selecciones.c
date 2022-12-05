#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "selecciones.h"
#include "inputs.h"
#include "e-s.h"
#define LIBRE 0
#define OCUPADO 1

static int GenerarIDSeleccion(void);
static int GenerarIDSeleccion(void){
	static int idIncrementalSeleccion = 11;

	return idIncrementalSeleccion++;
}
int ObtenerIDIncrementalSeleccion(void){
	int idSeleccion;

	idSeleccion = GenerarIDSeleccion();

	return idSeleccion;
}

void inicializarSelecciones(sSeleccion selecciones[], int tamSeleccion)
{
	if(selecciones != NULL && tamSeleccion > 0)
	{
		for(int i = 0; i < tamSeleccion; i++)
		{
			selecciones[i].estado = LIBRE;
		}
	}
}

int validarArrayCargadoSelecciones(sSeleccion selecciones[], int tamSeleccion)
{
	int retorno;
	retorno = 1;
	if(selecciones != NULL && tamSeleccion > 0)
	{
		for(int i = 0; i < tamSeleccion; i++)
		{
			if(selecciones[i].estado == LIBRE)
			{
				retorno = -1;
				break;
			}
		}
	}

	return retorno;
}
int selecciones_IndexLibre(sSeleccion selecciones[],int tamSeleccion)
{
	int index;
	index = -1;
	if(selecciones != NULL && tamSeleccion > 0)
	{
		for(int i = 0; i < tamSeleccion; i++)
		{
			if(selecciones[i].estado == LIBRE)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}
int selecciones_BuscarID(sSeleccion selecciones[], int tamSeleccion, int id)
{
	int index;
	index = -1;
	if(selecciones != NULL && tamSeleccion > 0)
	{
		for(int i = 0; i < tamSeleccion; i++)
		{
			if(selecciones[i].estado == OCUPADO && selecciones[i].idSeleccion == id)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

void selecciones_MostrarUna(sSeleccion Seleccion)
{
	printf("\n| %2d |",Seleccion.idSeleccion);
	printf(" %-19s      |",Seleccion.nombreSeleccion);
	printf(" %-20s |",Seleccion.directorTecnico);
	printf(" %4d\t\t    |",Seleccion.contador);

}

int selecciones_MostrarTodas(sSeleccion selecciones[], int tamSeleccion)
{
	int retorno;
	int cantidad;
	retorno = -1;
	cantidad = 0;

	if(selecciones != NULL && tamSeleccion > 0)
	{
	printf("\n>>Listado de selecciones");
	puts("\n-----------------------------------------------------------------------------");
	printf("| %-2s | %-24s | %-20s | %-2s |","ID","SELECCION","DT","CANTIDAD JUGADORES" );
	printf("\n-----------------------------------------------------------------------------");
		for(int i = 0; i < tamSeleccion; i++)
		{
			if(selecciones[i].estado == OCUPADO)
			{
				selecciones_MostrarUna(selecciones[i]);
				cantidad++;
			}
		}
		printf("\n-----------------------------------------------------------------------------");
	}
	if( cantidad > 0)
	{
		retorno = 1;
	}

	return retorno;
}

sSeleccion generarSeleccion()
{
	sSeleccion seleccionAux;
	getString(seleccionAux.nombreSeleccion, 50, "\nIngrese el nombre de la selección\n>> ", "\nERROR!");
	getString(seleccionAux.directorTecnico, 50, "\nIngrese el nombre del DT\n>> ", "\nERROR");

	return seleccionAux;

}
int altaSeleccion(sSeleccion selecciones[], int tamSeleccion)
{
	sSeleccion nuevaSeleccion;
	int retorno;
	int index;
	retorno = -1;
	index = selecciones_IndexLibre(selecciones, tamSeleccion);
	// index -1 = LLENO
	// index != -1 = obtuve un índice disponible
	if(index != -1)
	{
		nuevaSeleccion = generarSeleccion();
		nuevaSeleccion.idSeleccion = ObtenerIDIncrementalSeleccion();
		nuevaSeleccion.contador = 0;
		nuevaSeleccion.estado = OCUPADO;
		selecciones[index] = nuevaSeleccion;
		//éxtio en la carga
		retorno = 1;
	}

	return retorno;
}

sSeleccion selecciones_ModificarNombre(sSeleccion Seleccion)
{
	sSeleccion auxiliar;
	auxiliar = Seleccion;
	getString(auxiliar.nombreSeleccion, 50, "\nIngrese nuevo nombre...", "\nERROR!");
	selecciones_MostrarUna(auxiliar);

	return auxiliar;
}

sSeleccion selecciones_ModificarDT(sSeleccion Seleccion)
{
	sSeleccion auxiliar;
	auxiliar = Seleccion;
	getString(auxiliar.directorTecnico, 50, "\nIngrese nuevo DT", "\nERROR!");
	selecciones_MostrarUna(auxiliar);

	return auxiliar;
}

int modificarUnaSeleccion(sSeleccion selecciones[], int tamSeleccion)
{
	int retorno;
	retorno = -1;
	int opcion;
	int idSeleccion;
	int index;
	int flag;
	flag = 0;
	sSeleccion auxiliar;

	if(selecciones_MostrarTodas(selecciones, tamSeleccion) == 1)
	{
		// Bandera en 1 si hay selecciones creadas
		flag = 1;
	}
	if(flag == 1)
	{
		getInt(&idSeleccion, "\nID de la selección a modificar", "\nError!", 1, tamSeleccion);

		while(selecciones_BuscarID(selecciones, tamSeleccion, idSeleccion) == -1)
		{
			puts("\n**NO EXISTE EL ID**");
			getInt(&idSeleccion, "\nID de la selección a modificar", "\nError!", 1, tamSeleccion);
		}

		index = selecciones_BuscarID(selecciones, tamSeleccion, idSeleccion);
		auxiliar = selecciones[index];
		do
		{
			getInt(&opcion, "\n1.Modificar NOMBRE seleccion"
					"\n2.Modificar DT de la seleccion"
					"\n3.Salir...", "\nERROR", 1, 3);
			switch(opcion)
			{

				case 1:
					printf("\nModificar NOMBRE de la selección");
					auxiliar = selecciones_ModificarNombre(auxiliar);
				break;
				case 2:
					printf("\nModificar DT de la selección");
					auxiliar = selecciones_ModificarDT(auxiliar);
				break;
				case 3:
					break;
			}
		}while(opcion != 3);

		selecciones[index] = auxiliar;
		retorno = 1;
	}

	return retorno;
}


