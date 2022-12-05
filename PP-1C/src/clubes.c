#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inputs.h"
#include "e-s.h"
#include "clubes.h"

#define LIBRE 0
#define OCUPADO 1

static int GenerarIDClub(void);
static int GenerarIDClub(void){
	static int idIncrementalClub = 4;

	return idIncrementalClub++;
}
int ObtenerIDIncrementalClub(void){
	int idClub;

	idClub = GenerarIDClub();

	return idClub;
}



void inicializarClubes(sClub clubes[], int tamClub)
{
	if(clubes != NULL && tamClub > 0)
	{
		for( int i = 0; i < tamClub; i++)
		{
			clubes[i].estado = LIBRE;
		}
	}
}

int validarArrayCargadoClubes(sClub clubes[], int tamClub)
{
	int retorno;
	retorno = 1;
	if(clubes != NULL && tamClub > 0)
	{
		for(int i = 0; i < tamClub; i++)
		{
			if(clubes[i].estado == LIBRE)
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

int clubes_IndexLibre(sClub clubes[], int tamClub)
{
	int index;
	index = -1;
	if(clubes != NULL && tamClub > 0)
	{
		for(int i = 0; i < tamClub; i++)
		{
			if(clubes[i].estado == LIBRE)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int clubes_BuscarID(sClub clubes[], int tamClub, int id)
{
	int index;
	index = -1;
	if(clubes != NULL && tamClub > 0)
	{
		for(int i = 0; i < tamClub; i++)
		{
			if(clubes[i].estado == OCUPADO && clubes[i].idClub == id)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}
void clubes_MostrarUno(sClub Club)
{
	printf("\n| %3d |",Club.idClub);
	printf(" %-20s |",Club.nombre);
	printf(" %-20s |",Club.descripcion);
	printf(" %-10d |",Club.anioCreacion);
}

int clubes_MostrarTodos(sClub clubes[], int tamClub)
{
	int retorno;
	int cantidad;
	retorno = -1;
	cantidad = 0;
	if(clubes != NULL && tamClub > 0)
	{
	printf("\n>>Listado de Clubes");
	puts("\n------------------------------------------------------------------");
	printf("| %-1s | %-21s | %-21s | %-10s |","ID","NOMBRE","DESCRIPCION","FUNDACIÓN");
	printf("\n------------------------------------------------------------------");
		for(int i = 0; i < tamClub; i++)
		{
			if(clubes[i].estado == OCUPADO)
			{
				clubes_MostrarUno(clubes[i]);
				cantidad++;
			}
		}
	printf("\n------------------------------------------------------------------");
	}

	if(cantidad > 0)
	{
		retorno = 1;
	}

	return retorno;
}

sClub generarClub()
{
	sClub clubAuxiliar;
	getString(clubAuxiliar.nombre, 50, "\nIngrese nombre del club\n>> ", "\nError!!");
	getStringAlpha(clubAuxiliar.descripcion, 1024, "\nIngrese descripción del club (descripción alfanumerica)", "\nError!");
	getInt(&clubAuxiliar.anioCreacion, "\nIngrese año de creación del club\n>> ", "\nERROR, valores aceptados:\n>> 1800 a 2021", 1800, 2021);
	return clubAuxiliar;
}

int altaClub(sClub clubes[], int tamClub)
{
	sClub clubAuxiliar;
	int retorno;
	retorno = -1;
	int index;

	index = clubes_IndexLibre(clubes, tamClub);
	// index = -1 LLENO
	// index != -1 obtuve un índice disponible
	if(index != -1)
	{
		clubAuxiliar = generarClub();
		clubAuxiliar.idClub = ObtenerIDIncrementalClub();
		clubAuxiliar.estado = OCUPADO;
		clubes[index] = clubAuxiliar;
		retorno = 1;
	}


	return retorno;
}

sClub clubes_ModificarNombre(sClub Club)
{
	sClub auxiliar;
	auxiliar = Club;

	getString(auxiliar.nombre, 50, "\nIngrese nuevo nombre...", "\nError!!");
	clubes_MostrarUno(auxiliar);
	return auxiliar;
}

sClub clubes_ModificarDescripcion(sClub Club)
{
	sClub auxiliar;
	auxiliar = Club;

	getStringAlpha(auxiliar.descripcion, 1024, "\nIngrese nueva descripción", "\nError!");
	clubes_MostrarUno(auxiliar);
	return auxiliar;
}

sClub clubes_ModificaranioCreacion(sClub Club)
{
	sClub auxiliar;
	auxiliar = Club;
	getInt(&auxiliar.anioCreacion, "\nIngrese nuevo año de creación del club\n>> ", "\nERROR, valores aceptados:\n>> 1800 a 2021", 1800, 2021);
	clubes_MostrarUno(auxiliar);
	return auxiliar;
}

int modificarUnClub(sClub clubes[],int tamClub)
{
	int retorno;
	retorno = -1;
	int opcion;
	int idClub;
	int indice;
	int flag;
	flag = 0;
	sClub auxiliar;

	if(clubes_MostrarTodos(clubes, tamClub) == 1)
	{
		flag = 1;
	}

	if(flag == 1)
	{
		getInt(&idClub, "\nIngrese ID del club a modificar", "\nError!", 1, tamClub);
		while(clubes_BuscarID(clubes, tamClub, idClub) == -1)
		{
			puts("\n**NO EXISTE EL ID**");
			getInt(&idClub, "\nRe-ingrese ID del club a modificar", "\nError!", 1, tamClub);
		}
		indice = clubes_BuscarID(clubes, tamClub, idClub);
		auxiliar = clubes[indice];
		do
		{
			getInt(&opcion, "\n1.Modificar NOMBRE del club"
					"\n2.Modificar DESCRIPCION del club"
					"\n3.Modificar AÑO DE CREACION del club"
					"\n4.Salir", "\nError opción inválida", 1, 4);
			switch(opcion)
			{
			case 1:
				auxiliar = clubes_ModificarNombre(auxiliar);
				break;
			case 2:
				auxiliar = clubes_ModificarDescripcion(auxiliar);
				break;
			case 3:
				auxiliar = clubes_ModificaranioCreacion(auxiliar);
				break;
			case 4:
				break;
			}

		}while(opcion!=4);

		clubes[indice] = auxiliar;
		retorno = 1;

	}

	return retorno;
}
