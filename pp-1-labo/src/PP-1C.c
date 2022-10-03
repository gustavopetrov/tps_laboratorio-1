/*
 ============================================================================
 Name        : PP-1C.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "e-s.h"
#include "utilidades.h"
#include "perfilColeccionista.h"

#define TAM 2
#define CANT_FIGURITAS 55
#define CANT_SELECCIONES 5
#define CANT_FIGURITAS_SOBRE 5


int main(void) {
	setbuf(stdout,NULL);

/*--------------Variables Menú--------------*/
	int opcionMenuPrincipal;
	int sobreFiguritas[CANT_FIGURITAS_SOBRE];
/*--------------Variables sobre de figuritas--------------*/
	eEquipos selecciones[CANT_SELECCIONES] = {
			{1,"Argentina",OCUPADO},{2,"Brasil",OCUPADO},{3,"Inglaterra",OCUPADO},
			{4,"Uruguay",OCUPADO},{5,"Alemania",OCUPADO}
		};

//	eFigurita bancoDeDatos[CANT_FIGURITAS] = {
//				{1,"Gus","delantero",1,1.7,70,2009,OCUPADO,{14,4,1995}},
//				{2,"mati","mediocampista",1,1.9,80,2008,OCUPADO,{9,1,2003}},
//				{3,"agus","arquero",1,1.8,90,2007,OCUPADO,{1,3,2001}},
//				{4,"messi","delantero",2,1.6,60,2005,OCUPADO,{23,6,1987}},
//				{5,"juancito","defensor",3,1.5,65,2006,OCUPADO,{30,7,2000}}
//		};

	eFigurita bancoDeDatos[CANT_FIGURITAS];
	eRepetidas mazoRepetidas[CANT_FIGURITAS];
	eAlbum album;
	inicializarArray(bancoDeDatos, CANT_FIGURITAS);
	bancoDeDatos[0].idFigurita = 1;

	do {
		opcionMenuPrincipal = opcionesMenuPrincipal();
		switch(opcionMenuPrincipal)
		{
		case 1:

			opcionesMenuAdministrador(bancoDeDatos,CANT_FIGURITAS,selecciones,CANT_SELECCIONES);
			break;
		case 2:
			printf("Opcion menu coleccionista");
			opcionesMenuColeccionista(bancoDeDatos,CANT_FIGURITAS, album,sobreFiguritas,CANT_FIGURITAS_SOBRE, mazoRepetidas,CANT_FIGURITAS,selecciones, CANT_SELECCIONES);
			break;
		case 3:
			printf("\n\t*****¡Gracias por su visita!*****");
			break;
		}

	}while(opcionMenuPrincipal != 3);

	return EXIT_SUCCESS;
}
