#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "perfil-coleccionista.h"
#include "perfil-administrador.h"
#include "e-s.h"



void menu_Perfil_Coleccionista(sAlbum album,sRepetidas figuritasRepetidas[], sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes )
{
	int option;
	int contadorFiguritas;
	int contadorSobres;
	int sobresHastaLlenarElAlbum;
	int valorPaquete;
	int plataGastada;
	int plataGastadaHastaLlenarAlbum;
	int estadoAlbum;

	contadorFiguritas = 0;
	contadorSobres = 0;
	valorPaquete = 170;

	inicializarRepetidas(figuritasRepetidas, figuritas, cantFiguritas);
	album = inicializarAlbum(album, cantFiguritas);
	do
	{
		estadoAlbum = verificarAlbumLleno(album, cantFiguritas);
		if(estadoAlbum == 1 && album.estadoAlbum == LIBRE)
		{
			puts("\n**Se lleno el album**\n");
			album.estadoAlbum = OCUPADO;
			sobresHastaLlenarElAlbum = contadorSobres;
			plataGastadaHastaLlenarAlbum = valorPaquete * contadorSobres;
		}
		getInt(&option, "\nIngrese una opción: "
				"\n1.Pegar Figuritas"
				"\n2.Intercambiar Figuritas"
				"\n3.Listados"
				"\n4.Salir", "\nError!!", 1, 4);
		switch(option)
		{
		case 1:
			album = comprarPaquete(album, figuritasRepetidas, figuritas, cantFiguritas, &contadorFiguritas);
			contadorSobres++;
			plataGastada = valorPaquete * contadorSobres;

			break;
		case 2:
			if(verificarRepetidas(figuritasRepetidas, cantFiguritas) == 1)
			{
				album = intercambiarFigurita(album, figuritasRepetidas, figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
			}
			else
			{
				puts("No tenes figuritas repetidas");
			}
			break;
		case 3:
			do
			{
				getInt(&option, "\n1.Listado de Figuritas Pegadas..."
						"\n2.Listado de Figuritas Repetidas..."
						"\n3.Listado de figuritas doradas PEGADAS en el album..."
						"\n4.Cantidad de sobres comprados para llenar el album..."
						"\n5.Cantidad de dinero que lleva gastando el coleccionista..."
						"\n6.Cantidad de dinero que gasto el coleccionista para llenar el album..."
						"\n7.Salir", "\nError!", 1, 7);
				switch (option)
				{
				case 1:
					mostrarFiguritasPegadas(album, figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
					break;
				case 2:
					mostrarRepetidas(figuritasRepetidas, figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
					break;
				case 3:
					mostrarFiguritasDoradas(album, figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
					break;
				case 4:
					mostrarPaquetesLleno(sobresHastaLlenarElAlbum,album);
					break;
				case 5:
					mostrarPlataGastada(plataGastada);
					break;
				case 6:
					mostrarPlataGastadaHastaLlenarlo(plataGastadaHastaLlenarAlbum,album);
					break;
				case 7:
					break;
			}
			}while(option != 7);

			break;
		case 4:
			break;
		}

	}while(option != 4);

}


int generarNumeroRandom(int min, int max){
	int numRandom;

	numRandom = rand() % (max) + min;

	return numRandom;
}
sAlbum inicializarAlbum(sAlbum album, int cantFiguritas)
{
	if( cantFiguritas > 0)
	{
		for(int i = 0; i < cantFiguritas; i++)
		{
			album.idFigurita[i] = LIBRE;
			album.esDorada[i] = LIBRE;
		}
	}
	return album;
}

void inicializarRepetidas(sRepetidas figuritasRepetidas[], sFiguritas figurita[], int cantFiguritas)
{
	if(figuritasRepetidas != NULL && cantFiguritas > 0)
	{
		for(int i = 0; i < cantFiguritas; i++)
		{
			figuritasRepetidas[i].idFigurita = figurita[i].idFigurita;
			figuritasRepetidas[i].repetidas = LIBRE;
		}
	}
}

int verificarAlbumLleno(sAlbum album, int cantFiguritas)
{
	int retorno;
	int estado;
	retorno = -1;
	estado = 0;

	for(int i = 0; i < cantFiguritas; i ++)
	{
		if(album.idFigurita[i] != LIBRE)
		{
			estado++;
		}
	}
	if(estado == cantFiguritas)
	{
		retorno = 1;
	}
	return retorno;
}

int verificarRepetidas(sRepetidas figuritasRepetidas[],int cantFiguritas)
{
	int retorno;
	retorno = -1;
	for(int i = 0; i < cantFiguritas; i++)
	{
		if(figuritasRepetidas[i].repetidas > 0)
		{
			retorno = 1;
			break;
		}
	}


	return retorno;
}

sAlbum comprarPaquete(sAlbum album,sRepetidas figuritasRepetidas[], sFiguritas figuritas[],int cantFiguritas, int *pContadorFiguritas)
{
	srand(time(NULL));

	int paqueteFiguritas[CANT_FIGURITAS_SOBRE];
	int contadorFiguritas;
	contadorFiguritas = *pContadorFiguritas;
	for(int i = 0; i < CANT_FIGURITAS_SOBRE; i++)
	{
		paqueteFiguritas[i] = generarNumeroRandom(1, CANT_FIGURITAS);
		printf("\nFigurita: %d",paqueteFiguritas[i]);
		contadorFiguritas++;
		if(contadorFiguritas % 50 == 0)
		{
			printf("\nSalió una figurita dorada, ID >> %d",paqueteFiguritas[i]);
			for(int j = 0; j < cantFiguritas; j++)
			{
				if(album.esDorada[j] == LIBRE)
				{
					album.esDorada[j] = paqueteFiguritas[i];
					break;
				}
			}
		}
	}
	// ya tengo los 5 ids
	for(int i = 0; i < CANT_FIGURITAS_SOBRE; i++)
	{
		album = pegarFigurita(figuritas, cantFiguritas, album, figuritasRepetidas, paqueteFiguritas[i]);
	}

	*pContadorFiguritas = contadorFiguritas;
	printf("\nValor contadorFiguritas %d",contadorFiguritas);


	return album;
}

sAlbum pegarFigurita(sFiguritas figuritas[], int cantFiguritas, sAlbum album, sRepetidas figuritasRepetidas[],int figurita)
{
	if(figuritas != NULL && cantFiguritas > 0 && figuritasRepetidas != NULL && figurita > 0)
	{
		for(int i = 0; i < cantFiguritas; i++)
		{
			if(figuritas[i].idFigurita == figurita)
			{

				if(album.idFigurita[i] == LIBRE)
				{

					album.idFigurita[i] = figurita;

				}
				else
				{
					agregarFiguritasRepetidasPila(figuritasRepetidas, cantFiguritas, figurita);
				}
			}
		}
	}
	return album;
}

int agregarFiguritasRepetidasPila(sRepetidas figuritasRepetidas[], int cantRepetidas, int figuritaRepetida)
{
	int retorno;
	retorno = -1;
	for(int i = 0; i < cantRepetidas; i++)
	{
		if(figuritasRepetidas[i].idFigurita == figuritaRepetida)
		{
			figuritasRepetidas[i].repetidas++;
			retorno = 1;
			break;
		}
	}

	return retorno;
}

int mostrarRepetidas(sRepetidas figuritasRepetidas[],sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	int retorno;
	int hayRepetidas;
	retorno = -1;
	hayRepetidas = 0;
	if(figuritasRepetidas != NULL && figuritas != NULL && cantFiguritas > 0 && clubes != NULL && tamClub > 0 && selecciones != NULL && tamSeleccion > 0 && representantes != NULL && tamRepresentantes > 0 )
	{
		puts("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		printf("| %-2s | %-20s | %-20s | %-20s | %-20s | %-20s | %4s | %-5s | %4s | %4s |","ID","NOMBRE","POSICION","NOMBRE CLUB","NOMBRE SELECCION","NOMBRE REPRESENTANTE","ALTURA","PESO","AÑO INGRESO","FECHA DE NACIMIENTO");
		printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		for(int i = 0; i < cantFiguritas; i ++)
		{
			if(figuritasRepetidas[i].repetidas > 0)
			{
				hayRepetidas = 1;
				figurita_MostrarUna(figuritas[i], clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
				printf("\nVeces repetidas >> %2d\n",figuritasRepetidas[i].repetidas);
			}
		}
		printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		retorno = 1;
		if(hayRepetidas == 0)
		{
			puts("No hay figuritas repetidas");
			retorno = -1;
		}
	}

	return retorno;
}

void mostrarFaltantes(sAlbum album,sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{


	if( figuritas != NULL && cantFiguritas > 0 && clubes != NULL && tamClub > 0 && selecciones != NULL && tamSeleccion > 0 && representantes != NULL && tamRepresentantes > 0 )
	{
		for(int i = 0; i < cantFiguritas; i ++)
		{
			if(album.idFigurita[i] == LIBRE)
			{
				figurita_MostrarUna(figuritas[i], clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
			}
		}
	}
}

int mostrarFiguritasDoradas(sAlbum album,sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	int retorno;
	int dorada;
	retorno = -1;
	dorada = -1;

	if( figuritas != NULL && cantFiguritas > 0 && clubes != NULL && tamClub > 0 && selecciones != NULL && tamSeleccion > 0 && representantes != NULL && tamRepresentantes > 0)
	{
		for(int i = 0; i < cantFiguritas; i++)
		{
			if(album.idFigurita[i] != LIBRE)
			{
				for(int j = 0; j < cantFiguritas; j++)
				{
					if(album.esDorada[j] == album.idFigurita[i] )
					{
						dorada = 1;
						figurita_MostrarUna(figuritas[i], clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
						puts("\t**Es dorada**");
						retorno = 1;
						break;
					}
				}
			}
		}
		if(dorada == -1)
		{
			puts("\t**No hay figuritas DORADAS**");
			retorno = -1;
		}
	}


	return retorno;
}


sAlbum intercambiarFigurita(sAlbum album,sRepetidas figuritasRepetidas[] ,sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	int figuritaDeseada; // La que quiero
	int figuritaEntregada; // La que doy
	int disponibilidad; // Si la tengo o no

	disponibilidad = 0;
	if(figuritasRepetidas != NULL && figuritas != NULL && cantFiguritas > 0 && clubes != NULL && tamClub > 0 && selecciones != NULL && tamSeleccion > 0 && representantes != NULL && tamRepresentantes > 0)
	{
		mostrarFaltantes(album, figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
		getInt(&figuritaDeseada, "\nIngresar id figurita que desea: ", "\nERROR, valor inválido.", 1, 55);
		do
		{
			mostrarRepetidas(figuritasRepetidas, figuritas, cantFiguritas, clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
			getInt(&figuritaEntregada, "\nIngrese la figurita que entregara \n >> ", "\nError!", 1, cantFiguritas);
			for(int i = 0; i < cantFiguritas; i ++)
			{
				if(figuritaEntregada == figuritasRepetidas[i].idFigurita && figuritasRepetidas[i].repetidas > 0)
				{
					figuritasRepetidas[i].repetidas--;
					disponibilidad = 1;
				}
			}

			if(disponibilidad == 0)
			{
				puts("\nEsa figurita no la tenes, ingresa una que si tengas {:");
			}
		}while(disponibilidad == 0);

		puts("Figurita intercambiada exitosamente");
		album = pegarFigurita(figuritas, cantFiguritas, album, figuritasRepetidas, figuritaDeseada);
	}
	return album;
}

int mostrarFiguritasPegadas(sAlbum album,sFiguritas figuritas[], int cantFiguritas, sClub clubes[], int tamClub,sSeleccion selecciones[], int tamSeleccion,sRepresentantes representantes[], int tamRepresentantes)
{
	int retorno;
	int estado;
	retorno = -1;
	estado = 0;

	if(figuritas != NULL && cantFiguritas > 0 && clubes != NULL && tamClub > 0 && selecciones != NULL && tamSeleccion > 0 && representantes != NULL && tamRepresentantes > 0)
	{
		puts("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		printf("| %-2s | %-20s | %-20s | %-20s | %-20s | %-20s | %4s | %-5s | %4s | %4s |","ID","NOMBRE","POSICION","NOMBRE CLUB","NOMBRE SELECCION","NOMBRE REPRESENTANTE","ALTURA","PESO","AÑO INGRESO","FECHA DE NACIMIENTO");
		printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		for(int i = 0; i < cantFiguritas; i++)
		{

			if(album.idFigurita[i] != LIBRE)
			{
				estado = 1;
				figurita_MostrarUna(figuritas[i], clubes, tamClub, selecciones, tamSeleccion, representantes, tamRepresentantes);
			}
		}
		printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		retorno = 1;
		if(estado == 0)
		{
			puts("No hay figuritas pegadas");
			retorno = -1;
		}
	}

	return retorno;
}

void mostrarPaquetesLleno(int sobresHastaLlenarElAlbum,sAlbum album)
{
	if(album.estadoAlbum != OCUPADO )
		{
			puts("\n\t**No llenaste el album**");
		}else
		{
			printf("\nEl coleccionista compró %2d paquetes para llenar el album",sobresHastaLlenarElAlbum);
		}
}

void mostrarPlataGastada(int plataGastada)
{
	printf("\nEl coleccionista lleva gastando: %2d",plataGastada);
}
void mostrarPlataGastadaHastaLlenarlo(int plataGastadaHastaLlenarAlbum,sAlbum album )
{
	if(album.estadoAlbum != OCUPADO )
	{
		puts("\n\t**No llenaste el album**");
	}else
	{
		printf("\nEl coleccionista gasto %2d para completar el album.",plataGastadaHastaLlenarAlbum);
	}
}
