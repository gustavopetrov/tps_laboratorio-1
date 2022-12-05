#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inputs.h"
#include "e-s.h"
#include "representantes.h"
#define LIBRE 0
#define OCUPADO 1

static int GenerarIDRepresentante(void);
static int GenerarIDRepresentante(void){
	static int idIncrementalRepresentante = 4;

	return idIncrementalRepresentante++;
}
int ObtenerIDIncrementalRepresentante(void){
	int idRepresentante;

	idRepresentante = GenerarIDRepresentante();

	return idRepresentante;
}

void inicializarRepresentantes(sRepresentantes representantes[], int tamRepresentantes)
{
	if(representantes != NULL && tamRepresentantes > 0)
	{
		for(int i = 0; i < tamRepresentantes; i++)
		{
			representantes[i].estado = LIBRE;
		}
	}
}

int validarArrayCargadoRepresentantes(sRepresentantes representantes[], int tamRepresentantes)
{
	int retorno;
	retorno = 1;
	if(representantes != NULL && tamRepresentantes > 0)
	{
		for(int i = 0; i < tamRepresentantes; i++)
		{
			if(representantes[i].estado == LIBRE)
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

int representante_IndexLibre(sRepresentantes representantes[], int tamRepresentantes)
{
	int index;
	index = -1;

	if(representantes != NULL && tamRepresentantes > 0)
	{
		for(int i = 0; i < tamRepresentantes; i++)
		{
			if(representantes[i].estado == LIBRE)
			{
				index = i;
				break;
			}
		}
	}


	return index;
}
int representantes_BuscarID(sRepresentantes representantes[], int tamRepresentantes, int id)
{
	int index;
	index = -1;
	if(representantes != NULL && tamRepresentantes > 0)
	{
		for(int i = 0; i < tamRepresentantes; i++)
		{
			if(representantes[i].estado == OCUPADO && representantes[i].idRepresentante == id)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

void representante_MostrarUno(sRepresentantes Representante)
{
	printf("\n| %-2d |",Representante.idRepresentante);
	printf("%-20s  |",Representante.nombre);
	printf(" %-20s |",Representante.apellido);
	printf(" %-20s  |",Representante.descripcion);
	printf(" %9.2f  |",Representante.honorarios);
}

int representante_MostrarTodos(sRepresentantes representantes[], int tamRepresentantes)
{
	int retorno;
	int cantidad;
	retorno = -1;
	cantidad = 0;

	if(representantes != NULL && tamRepresentantes > 0)
	{
		printf("\n>>Listado de Representantes");
		puts("\n----------------------------------------------------------------------------------------");
		printf("| %-2s | %-20s | %-20s | %-20s | %-4s |","ID","NOMBRE","APELLIDO","DESCRIPCION","HONORARIOS");
		printf("\n----------------------------------------------------------------------------------------");
		for(int i = 0; i < tamRepresentantes; i++)
		{
			if(representantes[i].estado == OCUPADO)
			{
				representante_MostrarUno(representantes[i]);
				cantidad++;
			}
		}
		puts("\n----------------------------------------------------------------------------------------");
	}
	if(cantidad > 0)
	{
		retorno = 1;
	}

	return retorno;
}

sRepresentantes generarRepresentante()
{
	sRepresentantes representanteAux;

	getString(representanteAux.nombre, 50, "\n Ingrese nombre del representante\n>> ", "\nERROR!");
	getString(representanteAux.apellido, 50, "\nIngrese apellido del representante\n>> ", "\nERROR!");
	getStringAlpha(representanteAux.descripcion, 1024, "\nIngrese descripción(Campo alfanumerico)\n>> ", "Error");
	getFloat(&representanteAux.honorarios, "\nIngrese honorarios del representante\n>> ", "\n>>    Error!", 1, 99999999);

	return representanteAux;

}

int altaRepresentante(sRepresentantes representantes[], int tamRepresentantes)
{
	sRepresentantes nuevoRepresentante;
	int retorno;
	retorno = -1;
	int index;

	index = representante_IndexLibre(representantes, tamRepresentantes);
	// index = -1 LLENO
	// index != -1 obtuve un índice disponible

	if(index != -1)
	{
		nuevoRepresentante = generarRepresentante();
		nuevoRepresentante.idRepresentante = ObtenerIDIncrementalRepresentante();
		nuevoRepresentante.estado = OCUPADO;
		representantes[index] = nuevoRepresentante;
		retorno = 1;
	}

	return retorno;
}

sRepresentantes representantes_ModificarNombre(sRepresentantes Representante)
{
	sRepresentantes auxiliar;
	auxiliar = Representante;

	getString(auxiliar.nombre, 50, "\nIngrese nuevo Nombre: ", "\nERROR!");
	representante_MostrarUno(auxiliar);

	return auxiliar;
}
sRepresentantes representantes_ModificarApellido(sRepresentantes Representante)
{
	sRepresentantes auxiliar;
	auxiliar = Representante;
	getString(auxiliar.apellido, 50, "\nIngrese nuevo Apellido: ", "\nError!!");
	representante_MostrarUno(auxiliar);

	return auxiliar;
}
sRepresentantes representantes_ModificarDescripcion(sRepresentantes Representante)
{
	sRepresentantes auxiliar;
	auxiliar = Representante;
	getStringAlpha(auxiliar.descripcion, 1024, "\nIngrese nueva descripción(Campo alfanumerico) ", "\nError!!!");
	representante_MostrarUno(auxiliar);

	return auxiliar;
}
sRepresentantes representantes_ModificarHonorarios(sRepresentantes Representante)
{
	sRepresentantes auxiliar;
	auxiliar = Representante;

	getFloat(&auxiliar.honorarios, "\nIngrese nuevos honorarios", "\nError!", 1, 99999999);
	representante_MostrarUno(auxiliar);
	return auxiliar;
}

int modificarUnRepresentante(sRepresentantes representantes[], int tamRepresentantes)
{
	int retorno;
	retorno = -1;
	int opcion;
	int idRepresentante;
	int index;
	int flag;
	flag = 0;
	sRepresentantes auxiliar;

	if(representante_MostrarTodos(representantes, tamRepresentantes) == 1)
	{
		flag = 1;
	}
	if(flag == 1)
	{
		getInt(&idRepresentante, "\nIngrese ID del representante a modificar", "\nERROR!!", 1, tamRepresentantes);
		while(representantes_BuscarID(representantes, tamRepresentantes, idRepresentante) == -1)
		{
			puts("\n**NO EXISTE EL ID**");
			getInt(&idRepresentante, "\nIngrese ID del representante a modificar", "\nERROR!!", 1, tamRepresentantes);
		}
		index = representantes_BuscarID(representantes, tamRepresentantes, idRepresentante);
		auxiliar = representantes[index];
		do
		{
			getInt(&opcion, "\n1.Modificar NOMBRE del representante "
					"\n2.Modificar APELLIDO del representante "
					"\n3.Modificar DESCRIPCIÓN del representante "
					"\n4.Modificar HONORARIOS del representante "
					"\n5.Salir ", "\nError!!", 1, 5);
			switch(opcion)
			{
			case 1:
				auxiliar = representantes_ModificarNombre(auxiliar);
			break;
			case 2:
				auxiliar = representantes_ModificarApellido(auxiliar);
			break;
			case 3:
				auxiliar = representantes_ModificarDescripcion(auxiliar);
			break;
			case 4:
				auxiliar = representantes_ModificarHonorarios(auxiliar);
			break;
			case 5:
			break;
			}


		}while(opcion != 5);

		representantes[index] = auxiliar;
		retorno = 1;

	}
	return retorno;
}





