#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "e-s.h"
#include "utilidades.h"
#include "perfilColeccionista.h"

void generar5IDSRandom(int sobreFiguritas[],int sizeSobreFiguritas)
{
	srand(time(NULL));
	for(int i = 0;i<sizeSobreFiguritas;i++)
	{
		sobreFiguritas[i] = 1 + rand() % 55;
		printf("%d\n",sobreFiguritas[i]);
	}
}

void generar5FiguritasRandom(int sobreFiguritas[],int sizeSobreFiguritas, eFigurita lista[],int size,eEquipos listaSelecciones[], int sizeSelecciones)
{
	generar5IDSRandom(sobreFiguritas,sizeSobreFiguritas);
	for(int i = 0; i<sizeSobreFiguritas;i++)
	{
		for(int j = 0; j<size;j++)
		{
			if(sobreFiguritas[i] == lista[j].idFigurita)
			{
				mostrarFigurita(lista[j], listaSelecciones, sizeSelecciones);
				break;
			}

		}
	}
}

void comprarSobreFiguritas(int sobreFiguritas[],int sizeSobreFiguritas, eFigurita lista[],int size,eEquipos listaSelecciones[], int sizeSelecciones)
{
	generar5FiguritasRandom(sobreFiguritas, sizeSobreFiguritas, lista, size, listaSelecciones, sizeSelecciones);
}

void inicializarAlbumVacio(eAlbum album, int sizeAlbum)
{
	for(int i = 0;i<sizeAlbum;i++)
	{
		album.idFigurita[i] = -1;
	}
}

void inicializarMazoRepetidas(eFigurita lista[], int size, eRepetidas listaRepetidas[], int sizeRepetidas)
{
	for(int i = 0;i < sizeRepetidas; i++)
	{
		listaRepetidas[i].idFigurita = lista[i].idFigurita;
		listaRepetidas[i].repetidas = 0;
	}
}
void agregarFiguritaAlMazoRepetidas(int sobreFiguritas[],int size, eFigurita lista[],int sizeJugadores, eRepetidas listaRepetidas[], int sizeRepetidas)
{
	// id dinamico, depende de lo que salga en el sobre es el id que necesito
	for(int i = 0; i < sizeRepetidas; i++)
	{
		for(int j = 0; j < size; j++)
		{

			if(listaRepetidas[i].idFigurita == sobreFiguritas[i])
			{
				listaRepetidas[i].idFigurita = sobreFiguritas[i];
				listaRepetidas[i].repetidas = listaRepetidas[i].repetidas + 1;
				printf("\nID: %d\n",listaRepetidas[i].idFigurita);
			}
		}
	}
}

void pegarFigurita(eFigurita lista[], int sizeJugadores,eAlbum album,int sobreFiguritas[],int size,eRepetidas listaRepetidas[], int sizeRepetidas,eEquipos listaSelecciones[], int sizeSelecciones)
{

	comprarSobreFiguritas(sobreFiguritas,size, lista, sizeJugadores, listaSelecciones, sizeSelecciones);
	for(int i = 0; i < sizeJugadores; i++)
	{
		if(album.idFigurita[i] != -1 && album.idFigurita[i] == lista[i].idFigurita)
		{

			album.idFigurita[i] = lista[i].idFigurita;
			printf("\nid figurita: %d\n",album.idFigurita[i]);
			agregarFiguritaAlMazoRepetidas(sobreFiguritas,size,lista,sizeJugadores, listaRepetidas,sizeRepetidas);
		}
	}
}

void opcionesMenuColeccionista(eFigurita lista[],int size, eAlbum album, int sobreFiguritas[], int sizeSobreFiguritas, eRepetidas listaRepetidas[], int sizeRepetidas, eEquipos listaSelecciones[], int sizeSelecciones)
{
	int opcionMenuColeccionista;
	getInt(&opcionMenuColeccionista, "\n1.Comprar Paquete Figuritas \n"
				"2.Intercambiar Figuritas \n"
				"3.Salir...\n", "Error! opción inválida.", 1, 3);

	while(opcionMenuColeccionista != 3)
	{
		switch(opcionMenuColeccionista)
		{
		case 1:
			printf("\n\t*comprando paquete de figus....\n");
			pegarFigurita(lista,size,album,sobreFiguritas,sizeSobreFiguritas,listaRepetidas, sizeRepetidas, listaSelecciones,sizeSelecciones);
			break;
		case 2:
			printf("\n intercambiar figuritas...\n");
			break;
		case 3:
			printf("\nVolviendo al menú principal...\n");
			break;
		}
	}

}






