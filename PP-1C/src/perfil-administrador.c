#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inputs.h"
#include "e-s.h"
#include "perfil-administrador.h"

#define LIBRE 0
#define OCUPADO 1


void menu_Perfil_Administrador(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	int option;
	do
	{
		getInt(&option, "\nIngrese opción:"
				"\n1.Menú de altas..."
				"\n2.Menú de modificaciones..."
				"\n3.Menú SORT"
				"\n4.Menú Listados..."
				"\n5.Salir", "\nError!", 1, 5);
		switch(option)
		{
		case 1:
			menu_Perfil_Administrador_Altas(figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes,tamRepresentantes);

			break;
		case 2:
			if((validarArrayCargadoClubes(clubes, tamClub) == 1 ) && ( validarArrayCargadoRepresentantes(representantes,tamRepresentantes) == 1 ) && ( validarArrayCargadoSelecciones(selecciones,tamSeleccion) == 1) && (validarArrayCargadoFiguritas( figuritas, cantFiguritas) == 1))
			{
				menu_Perfil_Administrador_Modificaciones(figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
			}else
			{
				puts("\n**PRIMERO SE DEBE CARGAR EL MENÚ DE ALTAS**\n");
				system("pause");
			}
			break;
		case 3:
			if((validarArrayCargadoClubes(clubes, tamClub) == 1 ) && ( validarArrayCargadoRepresentantes(representantes,tamRepresentantes) == 1 ) && ( validarArrayCargadoSelecciones(selecciones,tamSeleccion) == 1) && (validarArrayCargadoFiguritas( figuritas, cantFiguritas) == 1))
			{
				menu_Perfil_Administrador_Sort(figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
			}else
			{
				puts("\n**PRIMERO SE DEBE CARGAR EL MENÚ DE ALTAS**\n");
				system("pause");
			}
			break;
		case 4:
			if((validarArrayCargadoClubes(clubes, tamClub) == 1 ) && ( validarArrayCargadoRepresentantes(representantes,tamRepresentantes) == 1 ) && ( validarArrayCargadoSelecciones(selecciones,tamSeleccion) == 1) && (validarArrayCargadoFiguritas( figuritas, cantFiguritas) == 1))
			{
				menu_Perfil_Administrador_Listados(figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
			}else
			{
				puts("\n**PRIMERO SE DEBE CARGAR EL MENÚ DE ALTAS**\n");
				system("pause");
			}
			break;
		case 5:
			break;
		}
	}while(option != 5);
}

static int GenerarID(void);
static int GenerarID(void){
	static int idIncremental = 25;

	return idIncremental++;
}
int ObtenerIDIncremental(void){
	int id;

	id = GenerarID();

	return id;
}

// ALTA FIGURITA
sFiguritas generarFigurita(sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	sFiguritas figuritaAux;
	int idAuxiliarSeleccion;
	getString(figuritaAux.nombreJugador, 50, "\nIngrese el nombre del jugador\n>> ", "\nERROR!");
	getString(figuritaAux.posicion, 30, "\nIngrese posición:\n "
			"\n*Arquero"
			"\n*Defensor"
			"\n*MedioCampista"
			"\n*Delantero"
			"\n>> ", "\nError, posición no válida...\n");
	while(stricmp(figuritaAux.posicion,"arquero") && stricmp(figuritaAux.posicion,"defensor") && stricmp(figuritaAux.posicion,"mediocampista") && stricmp(figuritaAux.posicion,"delantero"))
	{
		getString(figuritaAux.posicion, 30, "\nIngrese posición:\n "
					"\n*Arquero"
					"\n*Defensor"
					"\n*MedioCampista"
					"\n*Delantero"
					"\n>> ", "\nError, posición no válida...\n");
	}
	/*--Relación Clubs--*/
	clubes_MostrarTodos(clubes, tamClub);
	getInt(&figuritaAux.idClub, "\nIngrese el ID del club", "\nError club inválido", 1, tamClub);

	/*--Relación Seleccion--*/
	selecciones_MostrarTodas(selecciones, tamSeleccion);
	getInt(&idAuxiliarSeleccion, "\nIngrese el ID de la seleccion", "\nError seleccion inválida", 1, tamSeleccion);

	/*--Validar espacio en Seleccion--*/
	while(validarJugadoresSelecciones(idAuxiliarSeleccion,selecciones, tamSeleccion) == -1 )
	{
		selecciones_MostrarTodas(selecciones, tamSeleccion);
		getInt(&idAuxiliarSeleccion, "\nIngrese el ID de la seleccion", "\nError seleccion inválida", 1, tamSeleccion);
	}
	figuritaAux.idSeleccion = idAuxiliarSeleccion;

	/*--Relación Representante--*/
	representante_MostrarTodos(representantes, tamRepresentantes);
	getInt(&figuritaAux.idRepresentante, "\nIngrese ID del representante", "\nError, representante inválido", 1, tamRepresentantes);

	getFloat(&figuritaAux.altura, "\nIngrese altura, valores admitidos 1.5 a 2.2 mts"
			"\n>> ", "\nERROR!\nvalores admitidos 1.5 a 2.2 mts\n", 1.5, 2.2);
	getFloat(&figuritaAux.peso, "\nIngrese pesaje del jugador, valores admitidos 70kgs a 100kgs"
			"\n>> ", "\nERROR!\nvalores admitidos 70kgs a 100kgs", 70, 100);
	getInt(&figuritaAux.anioIngreso, "\nIngrese el año de ingreso a la selección, valores admitidos 1987 MIN, 2004 MAX"
			"\n>> ", "ERROR!\nValores admitidos 1987 MIN, 2004 MAX", 1987, 2004);
	getInt(&figuritaAux.fechaNacimiento.dia,"\nIngrese día de nacimiento del jugador\n>> ","\nError!Día no válido",1,31);
	getInt(&figuritaAux.fechaNacimiento.mes,"\nIngrese mes de nacimiento del jugador\n>> ","\nError! Mes no válido",1,12);
	getInt(&figuritaAux.fechaNacimiento.anio,"\nIngrese año de nacimiento del jugador\n>> ","\nError! Año no válido 1987 a 2004",1987,2004);

	return figuritaAux;
}


int altaFigurita(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	sFiguritas nuevaFigurita;
	int retorno;
	int index;
	retorno = -1;
	index = figuritas_indexLibre(figuritas, cantFiguritas);
	// index -1 = LLENO
	// index != -1 = obtuve indice disponible
	if(index != -1)
	{
		nuevaFigurita = generarFigurita(clubes,tamClub,selecciones,tamSeleccion,representantes,tamRepresentantes);
		nuevaFigurita.idFigurita = ObtenerIDIncremental();
		nuevaFigurita.estado = OCUPADO;
		figuritas[index] = nuevaFigurita;

		//Exito en la carga
		retorno = 1;

	}
	return retorno;
}


void figurita_MostrarUna(sFiguritas unaFigurita,sClub clubes[],int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	char nombreRepresentanteAux[50];
	char nombreSeleccionAux[50];
	char nombreClubAux[50];


	representantes_ObtenerNombre(unaFigurita, representantes, tamRepresentantes, nombreRepresentanteAux);
	selecciones_ObtenerNombre(unaFigurita, selecciones, tamSeleccion, nombreSeleccionAux);
	clubes_ObtenerNombre(unaFigurita, clubes, tamClub, nombreClubAux);

	if( (representantes_ObtenerNombre(unaFigurita, representantes, tamRepresentantes, nombreRepresentanteAux) != -1) && (selecciones_ObtenerNombre(unaFigurita, selecciones, tamSeleccion, nombreSeleccionAux) != -1) && ( clubes_ObtenerNombre(unaFigurita, clubes, tamClub, nombreClubAux) != -1) )
	{
		printf("\n| %3d |",unaFigurita.idFigurita);
		printf(" %-20s |",unaFigurita.nombreJugador);
		printf("%-20s |",unaFigurita.posicion);
		printf(" %-20s |",nombreClubAux);
		printf(" %-20s |",nombreSeleccionAux);
		printf(" %-20s |",nombreRepresentanteAux);
		printf(" %5.2f  |",unaFigurita.altura);
		printf(" %3.2f |",unaFigurita.peso);
		printf(" %-11d |",unaFigurita.anioIngreso);
		printf(" %d/%d/%d \t     |",unaFigurita.fechaNacimiento.dia,unaFigurita.fechaNacimiento.mes,unaFigurita.fechaNacimiento.anio);

	}

}
int figurita_MostrarTodas(sFiguritas figuritas[],int cantFiguritas,sClub clubes[],int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	int retorno;
	int cantidad;
	retorno = -1;
	cantidad = 0;

	puts("\n\t>>listado de figuritas");
	if(figuritas != NULL && cantFiguritas > 0)
	{
		puts("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		printf("| %-2s | %-20s | %-20s | %-20s | %-20s | %-20s | %4s | %-5s | %4s | %4s |","ID","NOMBRE","POSICION","NOMBRE CLUB","NOMBRE SELECCION","NOMBRE REPRESENTANTE","ALTURA","PESO","AÑO INGRESO","FECHA DE NACIMIENTO");
		printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		for(int i = 0; i < cantFiguritas; i++)
		{
			if(figuritas[i].estado == OCUPADO)
			{
				figurita_MostrarUna(figuritas[i],clubes,tamClub,selecciones,tamSeleccion,representantes,tamRepresentantes);
				cantidad++;
			}
		}
		puts("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	}
	// si el retorno es igual a -1 no hay índice para libre disponible
	if(cantidad > 0)
	{
		retorno = 1;
	}

	return retorno;
}

/*--------MODIFICACIONES--------*/

sFiguritas figurita_ModificarNombre(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	sFiguritas auxiliar;
	auxiliar = figurita;

	getString(auxiliar.nombreJugador, 50, "\nIngrese el nuevo nombre", "\nERROR!");
	figurita_MostrarUna(auxiliar, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
	return auxiliar;
}
sFiguritas figurita_ModificarPosicion(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	sFiguritas auxiliar;
	auxiliar = figurita;

	getString(auxiliar.posicion, 30, "\nIngrese posición:\n "
				"\n*Arquero"
				"\n*Defensor"
				"\n*MedioCampista"
				"\n*Delantero"
				"\n>> ", "\nError, posición no válida...\n");
		while(stricmp(auxiliar.posicion,"arquero") && stricmp(auxiliar.posicion,"defensor") && stricmp(auxiliar.posicion,"mediocampista") && stricmp(auxiliar.posicion,"delantero"))
		{
			getString(auxiliar.posicion, 30, "\nIngrese posición:\n "
						"\n*Arquero"
						"\n*Defensor"
						"\n*MedioCampista"
						"\n*Delantero"
						"\n>> ", "\nError, posición no válida...\n");
		}

	figurita_MostrarUna(auxiliar, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);

	return auxiliar;
}
sFiguritas figurita_ModificarAltura(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	sFiguritas auxiliar;
	auxiliar = figurita;

	getFloat(&auxiliar.altura, "\nIngrese altura, valores admitidos 1.5 a 2.2 mts"
				"\n>> ", "\nERROR!\nvalores admitidos 1.5 a 2.2 mts\n", 1.5, 2.2);

	figurita_MostrarUna(auxiliar, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);

	return auxiliar;
}
sFiguritas figurita_ModificarPeso(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	sFiguritas auxiliar;
	auxiliar = figurita;

	getFloat(&auxiliar.peso, "\nIngrese pesaje del jugador, valores admitidos 70kgs a 100kgs"
					"\n>> ", "\nERROR!\nvalores admitidos 70kgs a 100kgs", 70, 100);

	figurita_MostrarUna(auxiliar, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);

	return auxiliar;
}
sFiguritas figurita_ModificarIngreso(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	sFiguritas auxiliar;
	auxiliar = figurita;

	getInt(&auxiliar.anioIngreso, "\nIngrese el año de ingreso a la selección, valores admitidos 1987 MIN, 2004 MAX"
						"\n>> ", "ERROR!\nValores admitidos 1987 MIN, 2004 MAX", 1987, 2004);

	figurita_MostrarUna(auxiliar, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
	return auxiliar;
}

sFiguritas figurita_ModificarFechaNacimiento(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	sFiguritas auxiliar;
	auxiliar = figurita;

	getInt(&auxiliar.fechaNacimiento.dia,"\nIngrese día de nacimiento del jugador\n>> ","\nError!Día no válido",1,31);
	getInt(&auxiliar.fechaNacimiento.mes,"\nIngrese mes de nacimiento del jugador\n>> ","\nError! Mes no válido",1,12);
	getInt(&auxiliar.fechaNacimiento.anio,"\nIngrese año de nacimiento del jugador\n>> ","\nError! Año no válido 1987 a 2004",1987,2004);

	figurita_MostrarUna(auxiliar, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
	return auxiliar;
}
sFiguritas figurita_ModificarSeleccion(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	sFiguritas auxiliar;
	sSeleccion seleccionAux;
	int indice;
	int idSeleccionAuxiliar;
	auxiliar = figurita;
	indice = selecciones_BuscarID(selecciones, tamSeleccion, auxiliar.idSeleccion);
	seleccionAux = selecciones[indice];
	selecciones_MostrarTodas(selecciones, tamSeleccion);

	getInt(&idSeleccionAuxiliar, "\nIngrese nueva selección", "\nError!", 1, tamSeleccion);
	while(auxiliar.idSeleccion == idSeleccionAuxiliar)
	{
		puts("\nEl jugador se encuentra en esa SELECCION** ");
		getInt(&idSeleccionAuxiliar, "\nIngrese nueva selección", "\nError!", 1, tamSeleccion);

	}
	while(validarJugadoresSelecciones(idSeleccionAuxiliar, selecciones, tamSeleccion) == -1)
	{
		puts("\n**ERROR**\n>> Seleccion llena");
		getInt(&idSeleccionAuxiliar, "\nIngrese nueva selección", "\nError!", 1, tamSeleccion);
	}
	seleccionAux.contador--;
	auxiliar.idSeleccion = idSeleccionAuxiliar;
	selecciones[indice] = seleccionAux;

	figurita_MostrarUna(auxiliar, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);


	return auxiliar;
}
sFiguritas figurita_ModificarClub(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	sFiguritas auxiliar;
	auxiliar = figurita;

	clubes_MostrarTodos(clubes, tamClub);
	getInt(&auxiliar.idClub, "\nIngrese el ID del club", "\nError club inválido", 1, tamClub);

	figurita_MostrarUna(auxiliar, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
	return auxiliar;
}
sFiguritas figurita_ModificarRepresentante(sFiguritas figurita,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	sFiguritas auxiliar;
	auxiliar = figurita;

	/*--Relación Representante--*/
	representante_MostrarTodos(representantes, tamRepresentantes);
	getInt(&auxiliar.idRepresentante, "\nIngrese ID del representante", "\nError, representante inválido", 1, tamRepresentantes);

	figurita_MostrarUna(auxiliar, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);

	return auxiliar;
}



int modificarUnaFigurita(sFiguritas figuritas[],int cantFiguritas,sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	sFiguritas auxiliar;
	int retorno;
	retorno = -1;
	int opcion;
	int idFigurita;
	int index;
	int flag;
	flag = 0;

	if(figurita_MostrarTodas(figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes) == 1)
	{
		flag = 1;
	}

	if(flag == 1)
	{
		getInt(&idFigurita, "\nIngrese ID de la figurita a modificar", "\nError!", 1, cantFiguritas);
		while(figuritas_BuscarID(figuritas, cantFiguritas, idFigurita) == -1)
		{
			puts("\n**NO EXISTE EL ID**");
			getInt(&idFigurita, "\nIngrese ID de la figurita a modificar", "\nError!", 1, cantFiguritas);
		}
		index = figuritas_BuscarID(figuritas, cantFiguritas, idFigurita);
		auxiliar = figuritas[index];
		do
		{
			getInt(&opcion, "\n1.Modificar NOMBRE de la figurita "
					"\n2.Modificar POSICIÓN de la figurita "
					"\n3.Modificar CLUB de la figurita "
					"\n4.Modificar ALTURA de la figurita "
					"\n5.Modificar PESO de la figurita "
					"\n6.Modificar AÑO DE INGRESO de la figurita "
					"\n7.Modificar SELECCION de la figurita "
					"\n8.Modificar REPRESENTANTE de la figurita "
					"\n9.Modificar Fecha de Nacimiento de la figurita "
					"\n10.Salir..\n>> ", "\nError!", 1, 10);

			switch(opcion)
			{
				case 1:
					auxiliar = figurita_ModificarNombre(auxiliar, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
				break;
				case 2:
					auxiliar = figurita_ModificarPosicion(auxiliar, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
				break;
				case 3:
					auxiliar = figurita_ModificarClub(auxiliar, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
				break;
				case 4:
					auxiliar = figurita_ModificarAltura(auxiliar, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
				break;
				case 5:
					auxiliar = figurita_ModificarPeso(auxiliar, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
				break;
				case 6:
					auxiliar = figurita_ModificarIngreso(auxiliar, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
				break;
				case 7:
					auxiliar = figurita_ModificarSeleccion(auxiliar, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
				break;
				case 8:
					auxiliar = figurita_ModificarRepresentante(auxiliar, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
				break;
				case 9:
					auxiliar = figurita_ModificarFechaNacimiento(auxiliar, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
				break;
				case 10:
					break;
			}
		}while(opcion != 10);

		figuritas[index] = auxiliar;
		retorno = 1;


	}
	return retorno;
}

/*----------------------------SORT----------------------------*/
int figuritas_sortClub(sFiguritas figurita[],int tamFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes, int criterioOrdenamiento)
{
	sFiguritas auxiliar;
	char nombreClubAuxI[50];
	char nombreClubAuxJ[50];
	int retorno;
	retorno = -1;

	if( (figurita != NULL&& tamFiguritas > 0) && (clubes != NULL && tamClub > 0) && (selecciones != NULL && tamSeleccion > 0) && (representantes != NULL && tamRepresentantes > 0) && (clubes != NULL && tamClub > 0) )
	{
		switch(criterioOrdenamiento)
		{
		case -1:
			for(int i = 0; i < tamFiguritas - 1; i++)
			{
				for(int j = i + 1; j < tamFiguritas; j++)
				{
					if(figurita[i].estado == OCUPADO && figurita[j].estado == OCUPADO)
					{
						clubes_ObtenerNombre(figurita[i], clubes, tamClub, nombreClubAuxI);
						clubes_ObtenerNombre(figurita[j], clubes, tamClub, nombreClubAuxJ);
						if(stricmp(nombreClubAuxI,nombreClubAuxJ) > 0)
						{

							auxiliar = figurita[i];
							figurita[i] = figurita[j];
							figurita[j] = auxiliar;
						}
					}
				}
			}
			retorno = 1;
			figurita_MostrarTodas(figurita, tamFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
			break;
		case 1:
			for(int i = 0; i < tamFiguritas - 1; i++)
			{
				for(int j = i + 1; j < tamFiguritas; j++)
				{
					if(figurita[i].estado == OCUPADO && figurita[j].estado == OCUPADO)
					{
						clubes_ObtenerNombre(figurita[i], clubes, tamClub, nombreClubAuxI);
						clubes_ObtenerNombre(figurita[j], clubes, tamClub, nombreClubAuxJ);
						if(stricmp(nombreClubAuxI,nombreClubAuxJ) < 0)
						{

							auxiliar = figurita[i];
							figurita[i] = figurita[j];
							figurita[j] = auxiliar;
						}
					}
				}
			}
			retorno = 1;
			figurita_MostrarTodas(figurita, tamFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
			break;
		default:
			retorno = -1;
			break;
		}
	}else
	{
		puts("\nERROR!");
	}



	return retorno;
}

int seleccion_sortCantJugadores(sFiguritas figurita[],int tamFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes, int criterioOrdenamiento)
{
	sSeleccion auxiliar;
	int retorno;
	retorno = -1;

	if( (figurita != NULL&& tamFiguritas > 0) && (clubes != NULL && tamClub > 0) && (selecciones != NULL && tamSeleccion > 0) && (representantes != NULL && tamRepresentantes > 0) && (clubes != NULL && tamClub > 0) )
	{
		switch(criterioOrdenamiento)
		{
		case -1:
			for(int i = 0; i < tamSeleccion - 1; i++)
			{
				for(int j = i + 1; j < tamSeleccion; j++)
				{
					if(selecciones[i].contador > selecciones[j].contador)
					{
						auxiliar = selecciones[i];
						selecciones[i] = selecciones[j];
						selecciones[j] = auxiliar;
					}
				}
			}
			retorno = 1;
			selecciones_MostrarTodas(selecciones, tamSeleccion);
			break;

		case 1:
			for(int i = 0; i < tamSeleccion - 1; i++)
			{
				for(int j = i + 1; j < tamSeleccion; j++)
				{
					if(selecciones[i].contador < selecciones[j].contador)
					{
						auxiliar = selecciones[i];
						selecciones[i] = selecciones[j];
						selecciones[j] = auxiliar;
					}
				}
			}
			retorno = 1;
			selecciones_MostrarTodas(selecciones, tamSeleccion);
			break;
		default:
			retorno = -1;
			break;
		}
	}


	return retorno;
}

int representantes_sortHonorarios(sFiguritas figurita[],int tamFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes, int criterioOrdenamiento)
{
	sRepresentantes auxiliar;
	int retorno;
	retorno = -1;

	switch(criterioOrdenamiento)
	{
	case -1:
		for(int i = 0; i < tamRepresentantes - 1; i++)
		{
			for(int j = i + 1; j < tamRepresentantes; j++)
			{
				if(representantes[i].honorarios > representantes[j].honorarios)
				{
					auxiliar = representantes[i];
					representantes[i] = representantes[j];
					representantes[j] = auxiliar;
				}
			}
		}
		retorno = 1;
		representante_MostrarTodos(representantes, tamRepresentantes);
		break;
	case 1:
		for(int i = 0; i < tamRepresentantes - 1; i++)
		{
			for(int j = i + 1; j < tamRepresentantes; j++)
			{
				if(representantes[i].honorarios < representantes[j].honorarios)
				{
					auxiliar = representantes[i];
					representantes[i] = representantes[j];
					representantes[j] = auxiliar;
				}
			}
		}
		retorno = 1;
		representante_MostrarTodos(representantes, tamRepresentantes);
		break;
	default:
		retorno = -1;
	}

	return retorno;
}







/*----------------------------FIN-SORT----------------------------*/

int representantes_ObtenerNombre(sFiguritas figurita, sRepresentantes representantes[], int tamRepresentantes,char* nombreRepresentanteAux)
{
	/*----Relación estructura sSeleccion----*/
	int retorno;
	sRepresentantes representanteAuxiliar;
	int indexRepresentante;
	int idRepresentante;
	retorno = -1;
	if(representantes != NULL && tamRepresentantes > 0 && nombreRepresentanteAux != NULL)
	{
		idRepresentante = figurita.idRepresentante;
		indexRepresentante = representantes_BuscarID(representantes, tamRepresentantes, idRepresentante);
		if(indexRepresentante != -1)
		{
			representanteAuxiliar = representantes[indexRepresentante];
			strcpy(nombreRepresentanteAux,representanteAuxiliar.nombre);
			retorno = 1;

		}
	}

	return retorno;
}

int selecciones_ObtenerNombre(sFiguritas unaFigurita, sSeleccion selecciones[], int tamSeleccion,char* nombreSeleccionAux)
{
	/*----Relación estructura sSeleccion----*/
	sSeleccion seleccionAuxiliar;
	int retorno;
	int indexSeleccion;
	int idSeleccion;
	retorno = -1;
	if(selecciones != NULL && tamSeleccion > 0 && nombreSeleccionAux != NULL)
	{
		idSeleccion = unaFigurita.idSeleccion;
		indexSeleccion = selecciones_BuscarID(selecciones, tamSeleccion, idSeleccion);

		if(indexSeleccion != -1)
		{
			seleccionAuxiliar = selecciones[indexSeleccion];
			strcpy(nombreSeleccionAux,seleccionAuxiliar.nombreSeleccion);
			retorno = 1;

		}

	}


	return retorno;
}

int clubes_ObtenerNombre(sFiguritas unaFigurita, sClub clubes[], int tamClub, char* nombreClubAux)
{
	/*----Relación estructura sClub----*/
	sClub clubAuxiliar;
	int retorno;
	int indexClub;
	int idClub;
	retorno = -1;
	if(clubes != NULL && tamClub > 0 && nombreClubAux != NULL)
	{
		idClub = unaFigurita.idClub;
		indexClub = clubes_BuscarID(clubes, tamClub, idClub);

		if(indexClub != -1)
		{
			clubAuxiliar = clubes[indexClub];
			strcpy(nombreClubAux,clubAuxiliar.nombre);
			retorno = 1;
		}
	}

	return retorno;
}

int validarJugadoresSelecciones(int idSeleccionAux,sSeleccion selecciones[], int tamSeleccion)
{
	sSeleccion seleccionAux;
	int retorno;
	int indice;
	retorno = -1;
	if(selecciones != NULL && tamSeleccion > 0)
	{
		indice = selecciones_BuscarID(selecciones, tamSeleccion, idSeleccionAux);
		seleccionAux = selecciones[indice];
		if(seleccionAux.contador < 11)
		{
			seleccionAux.contador = seleccionAux.contador + 1;
			retorno = 1;
			selecciones[indice] = seleccionAux;
			selecciones_MostrarUna(selecciones[indice]);
		}else
		{
			puts("\nError, selección llena.");
			system("pause");
		}

	}
	return retorno;
}
/*------------ FILTROS ------------*/


void representantes_filter(sFiguritas figuritas[],int cantFiguritas,sClub clubes[],int tamClub,sSeleccion selecciones[],int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	int option;

	representante_MostrarTodos(representantes, tamRepresentantes);
	getInt(&option, "\nIngrese el ID del representante\n>> ", "\nError!", 1, tamRepresentantes);
	for(int i = 0; i < tamRepresentantes; i++)
	{
		if(representantes[i].idRepresentante == option && representantes[i].estado == OCUPADO)
		{
			for(int j = 0; j < cantFiguritas; j++)
			{
				if(figuritas[j].idRepresentante == option && figuritas[j].estado == OCUPADO)
				{
					figurita_MostrarUna(figuritas[j], clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
				}
			}
		}
	}

}

void selecciones_filter(sFiguritas figuritas[],int cantFiguritas,sClub clubes[],int tamClub,sSeleccion selecciones[],int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	int option;

	selecciones_MostrarTodas(selecciones, tamSeleccion);
	getInt(&option, "\nIngrese el ID de la seleccion\n>> ", "\nERROR!", 1, tamSeleccion);

	for(int i = 0; i < tamSeleccion; i++)
	{
		if(selecciones[i].idSeleccion == option && selecciones[i].estado == OCUPADO)
		{
			for(int j = 0; j < cantFiguritas; j++)
			{
				if(figuritas[j].idSeleccion == option && figuritas[j].estado == OCUPADO)
				{
					figurita_MostrarUna(figuritas[j], clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
				}
			}
		}
	}
}

void clubes_filter(sFiguritas figuritas[],int cantFiguritas,sClub clubes[],int tamClub,sSeleccion selecciones[],int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	int option;

	clubes_MostrarTodos(clubes, tamClub);
	getInt(&option, "\nIngrese el ID del club\n>> ", "\nError!", 1, tamClub);

	for(int i = 0; i < tamClub; i++)
	{
		if(clubes[i].idClub == option && clubes[i].estado == OCUPADO)
		{
			for(int j = 0; j < cantFiguritas; j++)
			{
				if(figuritas[j].idClub == option && figuritas[j].estado == OCUPADO)
				{
					figurita_MostrarUna(figuritas[j], clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
				}
			}
		}
	}

}
/*----------MENÚ----------*/
void menu_Perfil_Administrador_Altas(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	int option;
	do
				{
					getInt(&option, "\nIngrese opción:"
									"\n1.Alta de Club..."
									"\n2.Alta Seleccion..."
									"\n3.Alta Representante..."
									"\n4.Alta Figurita..."
									"\n5.Salir", "\nError!", 1, 5);
					switch(option)
					{
						case 1:
							if(altaClub(clubes, tamClub) != -1)
							{
								puts("\n>>\tClub dada de alta exitosamente");
								clubes_MostrarTodos(clubes, tamClub);
							}else
							{
								puts("\n>>\tError sin espacio para cargar clubes");
								system("pause");
							}
							break;
						case 2:
							if(altaSeleccion(selecciones, tamSeleccion) != -1)
							{
								puts("\n>>\nSeleccion dada de alta exitosamente");
								selecciones_MostrarTodas(selecciones, tamSeleccion);

							}else
							{
								puts("\n>>\tError sin espacio para cargar selecciones");
								system("pause");
							}
						break;
						case 3:
							if(altaRepresentante(representantes, tamRepresentantes) != -1)
							{
								puts("\n>>\tRepresentante dado de alta exitosamente");
								representante_MostrarTodos(representantes, tamRepresentantes);
							}else
							{
								puts("\n>>\tError sin espacio para cargar representantes");
								system("pause");
							}
							break;
						case 4:
							if((validarArrayCargadoClubes(clubes, tamClub) == 1 ) && ( validarArrayCargadoRepresentantes(representantes,tamRepresentantes) == 1 ) && ( validarArrayCargadoSelecciones(selecciones,tamSeleccion) == 1))
							{
								if(altaFigurita(figuritas, cantFiguritas, clubes, tamClub,selecciones,tamSeleccion,representantes,tamRepresentantes) != -1)
								{
									puts("\n>>\nFigurita dada de alta exitosamente");
									figurita_MostrarTodas(figuritas, cantFiguritas,clubes,tamClub,selecciones,tamSeleccion,representantes,tamRepresentantes);
								}else
								{
									puts("\n>>\nError sin espacio para cargar figuritas");
									system("pause");
								}
							}
							else
							{
								puts("\n>> **ERROR!**\n>> Primero se debe cargar al menos 1 club, 1 selección y 1 representante...");
							}
							break;
						case 5:
							break;
					}

				}while(option != 5);

}
void menu_Perfil_Administrador_Modificaciones(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	int option;
	if((validarArrayCargadoClubes(clubes, tamClub) == 1 ) && ( validarArrayCargadoRepresentantes(representantes,tamRepresentantes) == 1 ) && ( validarArrayCargadoSelecciones(selecciones,tamSeleccion) == 1) && (validarArrayCargadoFiguritas( figuritas, cantFiguritas) == 1))
				{
					do
					{
						getInt(&option, "\nMenú de modificaciones..."
								"\n1.Modificar CLUB"
								"\n2.Modificar SELECCION"
								"\n3.Modificar REPRESENTANTE"
								"\n4.Modificar FIGURITA"
								"\n5.Salir", "\nError! opción inválida", 1, 5);
						switch(option)
						{
							case 1:
								//modificar CLUB
								if(modificarUnClub(clubes, tamClub) == 1)
								{
									puts("\n *MODIFICACION DE CLUB EXITOSA*");
								}else
								{
									puts("\nMODIFICACIÓN DE CLUB CANCELADA");
								}
							break;
							case 2:
								//Modificar SELECCION
								if( modificarUnaSeleccion(selecciones, tamSeleccion) == 1)
								{
									puts("\n *MODIFICACION DE SELECCION EXITOSA*");
								}else
								{
									puts("\nMODIFICACIÓN DE SELECIÓN CANCELADA");
								}
							break;
							case 3:
								//Modificar REPRESENTANTE
								if(modificarUnRepresentante(representantes, tamRepresentantes) == 1)
								{
									puts("\n *MODIFICACION DE REPRESENTANTES EXITOSA*");
								}else
								{
									puts("\n *MODIFICACION DE REPRESENTANTES CANCELADA*");
								}
							break;
							case 4:
								//Modificar FIGURITA
								if(modificarUnaFigurita(figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes) == 1)
								{
									puts("\n *MODIFICACION DE FIGURITAS EXITOSA*");
								}else
								{
									puts("\n *MODIFICACION DE FIGURITAS CANCELADA*");
								}
							break;
							case 5:
								puts("\nVolviendo al menú...");
								break;
						}


					}while(option != 5);

				}else
				{
					puts("\n**PRIMERO SE DEBE CARGAR EL MENÚ DE ALTAS**\n");
					system("pause");
				}
}
void menu_Perfil_Administrador_Sort(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	int option;
	int criterioOrdenamiento;
	do
	{
		getInt(&option, "\n1.Ordenamiento de equipos..."
						"\n2.Ordenamiento de selecciones..."
						"\n3.Ordenamiento de representantes..."
						"\n4.Salir...\n>> ", "\nError!", 1, 4);
		switch (option)
		{
			case 1:
				if((validarArrayCargadoClubes(clubes, tamClub) == 1 ) && ( validarArrayCargadoRepresentantes(representantes,tamRepresentantes) == 1 ) && ( validarArrayCargadoSelecciones(selecciones,tamSeleccion) == 1) && (validarArrayCargadoFiguritas( figuritas, cantFiguritas) == 1))
				{
					getInt(&criterioOrdenamiento, "\nIngrese criterio de ordenamiento...\n"
													"-1 -> Ordena equipo de A - Z\n"
													"1 -> Ordena equipo de Z - A\n>> ", "\nError!", -1, 1);
					figuritas_sortClub(figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes, criterioOrdenamiento);
				}else
				{
					puts("\n**PRIMERO SE DEBE CARGAR EL MENÚ DE ALTAS**\n");
					system("pause");
				}
				break;
			case 2:
				if((validarArrayCargadoClubes(clubes, tamClub) == 1 ) && ( validarArrayCargadoRepresentantes(representantes,tamRepresentantes) == 1 ) && ( validarArrayCargadoSelecciones(selecciones,tamSeleccion) == 1) && (validarArrayCargadoFiguritas( figuritas, cantFiguritas) == 1))
				{
					getInt(&criterioOrdenamiento, "\nIngrese criterio de ordenamiento..."
													"\n***Ordenamiento por CANTIDAD de jugadores en selección***"
													"\n-1 -> Ordena seleccion de Menor(1) a Mayor(n)"
													"\n1 -> Ordena seleccion de Mayor(n) a Menor(1)\n>> ", "\nError!", -1, 1);
					seleccion_sortCantJugadores(figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes, criterioOrdenamiento);
				}else
				{
					puts("\n**PRIMERO SE DEBE CARGAR EL MENÚ DE ALTAS**\n");
					system("pause");
				}

				break;
			case 3:
				if((validarArrayCargadoClubes(clubes, tamClub) == 1 ) && ( validarArrayCargadoRepresentantes(representantes,tamRepresentantes) == 1 ) && ( validarArrayCargadoSelecciones(selecciones,tamSeleccion) == 1) && (validarArrayCargadoFiguritas( figuritas, cantFiguritas) == 1))
				{
					getInt(&criterioOrdenamiento, "\nIngrese criterio de ordenamiento..."
													"\n-1 -> Ordena representantes según sus honorarios de contrato.\n>> Más barato(float) a Más caro(float)"
													"\n1 -> Ordena representantes según sus honorarios de contrato.\n>> Más caro(float) a Más barato(float)\n>> ", "\nError!", -1, 1);
					representantes_sortHonorarios(figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes, criterioOrdenamiento);
				}else
				{
					puts("\n**PRIMERO SE DEBE CARGAR EL MENÚ DE ALTAS**\n");
					system("pause");
				}
				break;
			case 4:
				break;
		}
	}while(option!=4);
}

void menu_Perfil_Administrador_Listados(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	int option;
	do
	{
		getInt(&option, "\n1.Listado Jugadores.."
						"\n2.Listado Clubes..."
						"\n3.Listado Selecciones..."
						"\n4.Listado Representantes..."
						"\n5.SubMenú - Listados con Filtro..."
						"\n6.Salir", "\nError!!", 1, 6);
		switch(option)
		{
		case 1:
				figurita_MostrarTodas(figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
			break;
		case 2:
				clubes_MostrarTodos(clubes, tamClub);
			break;
		case 3:
				selecciones_MostrarTodas(selecciones, tamSeleccion);
			break;
		case 4:
				representante_MostrarTodos(representantes, tamRepresentantes);
			break;
		case 5:
				menu_Perfil_Administrador_SubMenuListados(figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
			break;
		case 6:
			break;

		}

	}while(option != 6);
}

void menu_Perfil_Administrador_SubMenuListados(sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	int option;
	do
	{
		getInt(&option, "\n1.Filtro de Clubes..."
						"\n2.Filtro de Selecciones..."
						"\n3.Filtro de representantes..."
						"\n4.Salir", "\nError!", 1, 4);
		switch(option)
		{
		case 1:
			clubes_filter(figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
			puts("\n** Se MUESTRAN los jugadores relacionados al CLUB **");
			break;
		case 2:
			selecciones_filter(figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
			puts("\n** Se MUESTRAN los jugadores relacionados a la SELECCION **");
			break;
		case 3:
			representantes_filter(figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
			puts("\n**Se MUESTRAN los jugadores relacionados a los REPRESENTANTES**");
			break;
		case 4:
			break;
		}
	}while(option != 4);
}
