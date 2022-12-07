#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugador.h"
#include "confederacion.h"
#include "Nexo.h"
#include "inputs.h"
#include "e-s.h"

void eJugador_MostrarUno(eJugador Jugador,eConfederacion Confederacion[], int TAM_Confederacion)
{
	char nombreConfederacion[50];

	for(int j = 0; j < TAM_Confederacion; j++ )
	{
		if (Confederacion[j].isEmpty == OCUPADO)
		{
			if(Jugador.idConfederacion == Confederacion[j].idConfederacion)
			{
				strcpy(nombreConfederacion,Confederacion[j].nombre);
				break;
			}
		}
	}
	//PRINTF DE UN SOLO Jugador
	printf("\t|%6d", Jugador.idJugador);
	printf("|%23s",Jugador.nombre);
	printf("|%19s",Jugador.posicion);
	printf("|%16hd",Jugador.numeroCamiseta);
	printf("|%16s",nombreConfederacion);
	printf("| %11.2f",Jugador.salario);
	printf("|%14hd|\n",Jugador.aniosContrato);
}

int eJugador_MostrarTodos(eJugador array[], int TAM,eConfederacion arrayConfederaciones[],int TAM_Confederacion)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Jugador");
	puts("\t==================================================================================================================");
	printf("\t|%5s | %21s | %17s | %14s | %14s | %10s | %14s|\n", "ID", "Nombre", "Posicion", "NroCamiseta", "Confederacion", "Salario", "AñoContratos");
	puts("\t------------------------------------------------------------------------------------------------------------------");
	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == OCUPADO) {
				eJugador_MostrarUno(array[i],arrayConfederaciones,TAM_Confederacion);
				cantidad++;
			}
		}
		puts("\t==================================================================================================================");
	}
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eJugador_MostrarDadosDeBaja(eJugador array[], int TAM,eConfederacion arrayConfederaciones[],int TAM_Confederacion)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	puts("\t> Jugador\n");
	printf("\t|  %5s | %20s | %16s | %13s | %13s | %11s | %13s  |\n", "ID", "Nombre", "Posicion", "NumCamiseta", "Confederacion", "Salario", "AñoContratos");
	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == BAJA) {
				eJugador_MostrarUno(array[i],arrayConfederaciones,TAM_Confederacion);
				cantidad++;
			}
		}
	}
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}
eJugador eJugador_CargarDatos(eConfederacion array[], int TAM)
{
	eJugador auxiliar;
	int idConfederacionAux;

	getString(auxiliar.nombre, 50, "\nIngrese Nombre Jugador\n>>", "\nError!\n");
	getString(auxiliar.posicion,50, "\nIngrese Posicion Jugador\n>>", "\nError!\n");
	while(stricmp(auxiliar.posicion,"Arquero") && stricmp(auxiliar.posicion,"Defensor") && stricmp(auxiliar.posicion,"MedioCampista") && stricmp(auxiliar.posicion,"Delantero") )
	{
		getString(auxiliar.posicion,50, "\nIngrese una de las siguientes posiciones para el jugador: "
				"\n>>Arquero"
				"\n>>Defensor"
				"\n>>MedioCampista"
				"\n>>Delantero", "\nError!");
	}
	getShort(&auxiliar.numeroCamiseta, "\nIngrese Numero Camiseta\n>> ", "\nError!", 1, 99);
	//Listo las confederaciones
	eConfederacion_MostrarTodos(array, TAM);
	getInt(&idConfederacionAux, "\nIngrese Confederación\n>>  ", "\nError!\n", 100, 105);
	while(verificarID_Confederaciones(array,TAM,idConfederacionAux) == 0)
	{
		getInt(&idConfederacionAux, "\nIngrese Confederación\n>> ", "\nError!", 100, 105);
	}
	auxiliar.idConfederacion = idConfederacionAux;
	getFloat(&auxiliar.salario, "\nIngrese Salario Jugador, de 1000 a 9000000\n>> ", "\nError!", 1000, 9000000);
	getShort(&auxiliar.aniosContrato, "\nIngrese años de contrato, de 1 a 15\n>> ", "\nError!", 1, 15);


	return auxiliar;
}

int verificarID_Confederaciones(eConfederacion array[], int TAM, int id)
{
	int rta;
	rta = 0;
	for(int i = 0; i < TAM; i++)
	{
		if((array[i].isEmpty == OCUPADO) && (array[i].idConfederacion == id))
		{
			rta = 1;
			break;
		}
	}

	return rta;
}

eJugador eJugador_ModificarConfederacion(eJugador Jugador, eConfederacion confederacion[], int TAM_Confederacion)
{
	eJugador auxiliar;
	auxiliar = Jugador;
	int idConfederacionAux;
	eConfederacion_MostrarTodos(confederacion, TAM_Confederacion);
	// validar que exista el ID de confederacion
	getInt(&idConfederacionAux, "\nIngrese nueva Confederación\n>> ", "\nError!", 100, 105);
	while(verificarID_Confederaciones(confederacion,TAM_Confederacion,idConfederacionAux) == 0)
	{
		getInt(&idConfederacionAux, "\nIngrese nueva Confederación\n>> ", "\nError!", 100, 105);
	}
	auxiliar.idConfederacion = idConfederacionAux;
	return auxiliar;

}

int eJugador_Alta(eJugador array[], int TAM, eConfederacion arrayConfederacion[], int TAMconfederacion)
{
	int rtn = 0;
	eJugador auxJugador;

	int index = eJugador_ObtenerIndexLibre(array, TAM);
	if (index != -1)
	{
		auxJugador = eJugador_CargarDatos(arrayConfederacion,TAMconfederacion);
		auxJugador.idJugador = jugador_ObtenerID();
		auxJugador.isEmpty = OCUPADO;
		array[index] = auxJugador;
		rtn = 1;
	}

	return rtn;
}

int eJugador_Baja(eJugador array[], int TAM,eConfederacion arrayConfederaciones[],int TAM_Confederacion)
{
	int rtn = 0;
	int idJugador;
	int index;
	int flag = 0;

	if (eJugador_MostrarTodos(array, TAM,arrayConfederaciones,TAM_Confederacion))
	{
		flag = 1;
	}
	if (flag) {
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idJugador);
		while (eJugador_BuscarPorID(array, TAM, idJugador) == -1) {
			puts("NO EXISTE ID.");
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idJugador);
		}

		index = eJugador_BuscarPorID(array, TAM, idJugador);
		array[index].isEmpty = BAJA;
		rtn = 1;
	}

	return rtn;
}

int eJugador_Modificacion(eJugador array[], int TAM,eConfederacion arrayConfederaciones[],int TAM_Confederacion)
{
	int rtn = 0;
	int option;
	int idJugador;
	int index;
	int flag = 0;
	eJugador auxiliar;

	if (eJugador_MostrarTodos(array, TAM, arrayConfederaciones,TAM_Confederacion)) {
		flag = 1;
	}
	if (flag)
	{
		getInt(&idJugador, "\nID jugador a modificar\n>> ", "\nERROR!\n", 1, 3000);
		while (eJugador_BuscarPorID(array, TAM, idJugador) == -1)
		{
			puts("NO EXISTE ID.");
			printf("INGRESE ID A DAR DE BAJA ");
			getInt(&idJugador, "\nID jugador a modificar\n>> ", "\nERROR\n!", 1, 3000);
		}
		index = eJugador_BuscarPorID(array, TAM, idJugador);
		auxiliar = array[index];
		do
		{
			getInt(&option, "\nID jugador a modificar"
									"\n1.Modificar Nombre"
									"\n2.Modificar Posición"
									"\n3.Modificar Numero Camiseta"
									"\n4.Modificar Confederación"
									"\n5.Modificar Salario"
									"\n6.Modificar Contrato"
									"\n7.Salir \n", "\nERROR!", 1, 7);
				switch(option)
				{
					case 1:
						auxiliar = eJugador_ModificarNombre(auxiliar);
						break;
					case 2:
						auxiliar = eJugador_ModificarPosicion(auxiliar);
						break;
					case 3:
						auxiliar = eJugador_ModificarNumeroCamiseta(auxiliar);
						break;
					case 4:
						auxiliar = eJugador_ModificarConfederacion(auxiliar,arrayConfederaciones, TAM_Confederacion);
						break;
					case 5:
						auxiliar = eJugador_ModificarSalario(auxiliar);
						break;
					case 6:
						auxiliar = eJugador_ModificarContrato(auxiliar);
						break;
					case 7:
						break;
				}
					}while(option != 7);

		array[index] = auxiliar;
		rtn = 1;
	}

	return rtn;
}

int mostrarTodosLosJugadoresDeUnaConfederacion(eJugador array[], int TAM, eConfederacion arrayConfederacion[], int TAM_Confederacion)
{
	int rta;
	int cantidad;
	rta = 0;
	cantidad = 0;
	puts("\n\t> LISTADO Jugador");
	printf("\t|%5s | %21s | %17s | %14s | %14s | %10s | %14s|\n", "ID", "Nombre", "Posicion", "NroCamiseta", "Confederacion", "Salario", "AñoContratos");
	if(array != NULL && TAM > 0 && arrayConfederacion != NULL && TAM_Confederacion > 0)
	{
		for(int i = 0; i < TAM_Confederacion; i++)
		{
			if(arrayConfederacion[i].isEmpty == OCUPADO)
			{
				for(int j = 0; j < TAM; j++)
				{
					if(array[j].isEmpty == OCUPADO)
					{
						if(arrayConfederacion[i].idConfederacion == array[j].idConfederacion)
						{
							cantidad++;
							eJugador_MostrarUno(array[j], arrayConfederacion, TAM_Confederacion);
						}
					}
				}
			}
		}
	}

	if(cantidad > 0)
	{
		rta = 1;
	}

	return rta;
}

int eJugador_Sort(eJugador array[], int TAM, int criterio, eConfederacion arrayConfederacion[], int TAM_Confederacion)
{
	int rtn = 0;
	eJugador auxJugador;
	eConfederacion auxConfederacion;

	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for(int i = 0; i < TAM - 1; i++)
			{
				for(int j = i + 1; j < TAM; j++)
				{
					if(stricmp(array[i].nombre,array[j].nombre) > 0)
					{
						auxJugador = array[i];
						array[i] = array[j];
						array[j] = auxJugador;
					}
				}
			}
			for(int x = 0; x < TAM_Confederacion - 1; x++)
			{
				for(int z = x + 1; z < TAM_Confederacion; z++)
				{
					if( stricmp(arrayConfederacion[x].nombre,arrayConfederacion[z].nombre) > 0)
					{
						auxConfederacion = arrayConfederacion[x];
						arrayConfederacion[x] = arrayConfederacion[z];
						arrayConfederacion[z] = auxConfederacion;
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for(int i = 0; i < TAM - 1; i++)
			{
				for(int j = i + 1; j < TAM; j++)
				{
					if(stricmp(array[i].nombre,array[j].nombre) < 0)
					{
						auxJugador = array[i];
						array[i] = array[j];
						array[j] = auxJugador;
					}
				}
			}
			for(int x = 0; x < TAM_Confederacion - 1; x++)
			{
				for(int z = x + 1; z < TAM_Confederacion; z++)
				{
					if(stricmp(arrayConfederacion[x].nombre,arrayConfederacion[z].nombre) < 0)
					{
						auxConfederacion = arrayConfederacion[x];
						arrayConfederacion[x] = arrayConfederacion[z];
						arrayConfederacion[z] = auxConfederacion;
					}
				}
			}
			rtn = 1;
			break;
		default:
			rtn = 0;
			break;
		}
	}
	return rtn;
}

/*----------------------LISTADOS----------------------*/
//	★ Informar la confederación con mayor cantidad de años de contratos total.
void confederacionConMaximoContrato(eJugador arrayJugadores[], int TAM_Jugador, eConfederacion arrayConfederaciones[], int TAM_Confederacion)
{
	int i;
	int j;
	int flag;
	flag = 0;
	int aniosContrato;
	int aniosContratoMaximo;
	char confederacionAux[50];
	aniosContrato = 0;

	if( (arrayJugadores != NULL && TAM_Jugador >= 0) && (arrayConfederaciones != NULL && TAM_Confederacion >= 0) )
	{
		for(i = 0; i < TAM_Confederacion; i++ )
		{
			if(arrayConfederaciones[i].isEmpty == OCUPADO)
			{
				for(j = 0; j < TAM_Jugador; j++ )
				{
					if(arrayJugadores[j].isEmpty == OCUPADO)
					{
						if(arrayJugadores[j].idConfederacion == arrayConfederaciones[i].idConfederacion)
						{
							aniosContrato += arrayJugadores[j].aniosContrato;
						}
					}
				}
			}
			if(aniosContrato > aniosContratoMaximo || flag == 0)
				{
					flag = 1;
					aniosContratoMaximo = aniosContrato;
					strcpy(confederacionAux,arrayConfederaciones[i].nombre);
				}
			aniosContrato = 0;
		}
	}
	printf("\nconfederacion con maximo años de contrato: %s y tiene %d años de contrato \n",confederacionAux,aniosContratoMaximo);
}

void porcentajeJugadoresPorRegion(eJugador arrayJugadores[], int TAM_Jugador, eConfederacion arrayConfederaciones[],int TAM_Confederacion)
{
	int i;
	int j;
	int cantidadJugadoresTotales;
	int contadorJugadores;
	float promedioJugadores;
	contadorJugadores = 0;
	cantidadJugadoresTotales = eJugador_ContarJugadores(arrayJugadores, TAM_Jugador);

	if( (arrayJugadores != NULL && TAM_Jugador >= 0) && (arrayConfederaciones != NULL && TAM_Confederacion >= 0) )
		{
			for(i = 0; i < TAM_Confederacion; i++ )
			{
				if(arrayConfederaciones[i].isEmpty == OCUPADO)
				{
					for(j = 0; j < TAM_Jugador; j++ )
					{
						if(arrayJugadores[j].isEmpty == OCUPADO)
						{
							if(arrayJugadores[j].idConfederacion == arrayConfederaciones[i].idConfederacion)
							{
								contadorJugadores++;
							}
						}
					}
				}
				promedioJugadores = (float)(contadorJugadores *  100) / cantidadJugadoresTotales;
				printf("\nRegión: %s, porcentaje de jugadores: %.2f \n",arrayConfederaciones[i].nombre,promedioJugadores);
				contadorJugadores = 0;
			}
		}
}

void listarJugadoresRegion(eJugador arrayJugadores[], int TAM_Jugador, eConfederacion arrayConfederaciones[], int TAM_Confederacion, char region[])
{
	int i;
	int j;
	if((TAM_Jugador >= 0) && (arrayConfederaciones != NULL && TAM_Confederacion >= 0))
	{
		for(i = 0; i < TAM_Confederacion; i++)
		{
			if(arrayConfederaciones[i].isEmpty == OCUPADO)
			{
				if( stricmp(arrayConfederaciones[i].nombre,region) == 0)
				{
					for(j = 0; j < TAM_Jugador; j++)
					{
						if(arrayJugadores[j].isEmpty == OCUPADO)
						{
							if(arrayConfederaciones[i].idConfederacion == arrayJugadores[j].idConfederacion)
							{
								printf("\t|%6d", arrayJugadores[j].idJugador);
								printf("|%23s",arrayJugadores[j].nombre);
								printf("|%19s",arrayJugadores[j].posicion);
								printf("|%16hd",arrayJugadores[j].numeroCamiseta);
								printf("|%16s",region);
								printf("| %11.2f",arrayJugadores[j].salario);
								printf("|%14hd|\n",arrayJugadores[j].aniosContrato);
							}
						}
					}

				}
			}
		}
	}
}

void regionConMasJugadores(eJugador arrayJugadores[], int TAM_Jugador, eConfederacion arrayConfederaciones[],int TAM_Confederacion)
{
	int i;
	int j;
	int flag;
	int contadorJugadores;
	int jugadoresMaximos;
	char regionAuxiliar[50];
	flag = 0;
	contadorJugadores = 0;
	if( (arrayJugadores != NULL && TAM_Jugador >= 0) && (arrayConfederaciones != NULL && TAM_Confederacion >= 0) )
			{
				for(i = 0; i < TAM_Confederacion; i++ )
				{
					if(arrayConfederaciones[i].isEmpty == OCUPADO)
					{
						for(j = 0; j < TAM_Jugador; j++ )
						{
							if(arrayJugadores[j].isEmpty == OCUPADO)
							{
								if(arrayJugadores[j].idConfederacion == arrayConfederaciones[i].idConfederacion)
								{
									contadorJugadores++;

								}
							}
						}
					}
					if(contadorJugadores > jugadoresMaximos || flag == 0)
					{
						flag = 1;
						jugadoresMaximos = contadorJugadores;
						strcpy(regionAuxiliar,arrayConfederaciones[i].nombre);
					}
					contadorJugadores = 0;
				}
				printf("\n\nLa región con más jugadores es: %s\n",regionAuxiliar);
				listarJugadoresRegion(arrayJugadores, TAM_Jugador, arrayConfederaciones, TAM_Confederacion, regionAuxiliar);
			}
}

