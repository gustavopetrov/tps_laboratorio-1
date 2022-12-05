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
#include "perfil-coleccionista.h"
#include "perfil-administrador.h"
#include "album.h"


#define TAM 2
#define CANT_FIGURITAS 55
#define CANT_SELECCIONES 11
#define CANT_FIGURITAS_SOBRE 5
#define CANT_REPRESENTANTES 4
#define CANT_EQUIPOS 4


int main(void) {
	setbuf(stdout,NULL);

/*--------------Variables Menú--------------*/
	int opcionMenuPrincipal;
/*-------------- Datos de Prueba --------------*/

//funcion para probar:
//	eJugador eJugador_cargaPrueba(char nombre[], char posicion[], short numeroCamiseta, int idConfederacion, float salario, short aniosContrato)
//	{
//		eJugador auxiliar;
//
//			auxiliar.idJugador = eJugador_ObtenerID();
//			strcpy(auxiliar.nombre, nombre);
//			strcpy(auxiliar.posicion, posicion);
//			auxiliar.numeroCamiseta = numeroCamiseta;
//			auxiliar.idConfederacion = idConfederacion;
//			auxiliar.salario = salario;
//			auxiliar.aniosContrato = aniosContrato;
//			auxiliar.isEmpty = OCUPADO;
//
//		return auxiliar;
//
//	}
//	eJugador eJugador_cargaPrueba(char nombre[], char posicion[], short numeroCamiseta, int idConfederacion, float salario, short aniosContrato);

/*--------------Variables sobre de figuritas--------------*/
	sFiguritas banco_de_datos[CANT_FIGURITAS] = { 				//Selec  //CLUB	  //REPRE	//ESTADO
			{1,"Gustavo","Delantero",1.7,80.6,1990,				1,		1,			2		,1,{14,4,1995}},
			{2,"Mariano","Arquero",1.7,80.6,1990,				2,		1,			3		,1,{14,5,1995}},
			{3,"Matias","Defensor",1.7,80.6,1994,				3,		3,			3		,1,{12,6,1990}},
			{4,"Agustin","Arquero",1.8,80.9,1993,				4,		2,			4		,1,{6,2,1993}},
			{5,"German","Delantero",1.7,80.6,1994,				5,		4,			1		,1,{6,2,1993}},
			{6,"Nicolas","MedioCampista",1.7,80.6,1994,			6,		4,			2		,1,{6,2,1993}},
			{7,"Rodrigo","Defensor",1.7,80.6,1994,				7,		1,			3		,1,{6,2,1993}},
			{8,"Lionel","MedioCampista",1.7,80.6,1994,			8,		2,			4		,1,{6,2,1993}},
			{9,"Leandro","Defensor",1.7,80.6,1994,				9,		3,			3		,1,{6,2,1993}},
			{10,"Carlos","MedioCampista",1.7,80.6,1994,			10,		3,			2		,1,{6,2,1993}},
			{11,"Jose","Defensor",1.7,80.6,1994,				1,		3,			2		,1,{6,2,1993}},
			{12,"Lis","Delantero",1.7,80.6,1994,				1,		3,			2		,1,{6,2,1993}},
			{13,"Char","Arquero",1.7,80.6,1994,					2,		1,			2		,1,{6,2,1993}},
			{14,"Jinx","Defensor",1.7,80.6,1994,				3,		1,			2		,1,{6,2,1993}},
			{15,"jor","MedioCampista",1.7,80.6,1994,			4,		2,			2		,1,{6,2,1993}},
			{16,"messi","Arquero",1.7,80.6,1994,				5,		2,			4		,1,{6,2,1993}},
			{17,"siatic","Delantero",1.7,80.6,1994,				6,		2,			4		,1,{6,2,1993}},
			{18,"lobezn","Delantero",1.7,80.6,1994,				7,		1,			1		,1,{6,2,1993}},
			{19,"grunt","MedioCampista",1.7,80.6,1994,			8,		1,			1		,1,{6,2,1993}},
			{20,"arthas","Defensor",1.7,80.6,1994,				9,		2,			1		,1,{6,2,1993}},
			{21,"illidan","Arquero",1.7,80.6,1994,				10,		3,			1		,1,{6,2,1993}},
			{22,"leonida","Defensor",1.7,80.6,1994,				1,		3,			1		,1,{6,2,1993}},
			{23,"lisa","MedioCampista",1.7,80.6,1994,			1,		2,			1		,1,{6,2,1993}},
			{24,"dacia","Defensor",1.7,80.6,1994,				2,		1,			1		,1,{6,2,1993}},
			{25,"Anglo","Delantero",1.7,80.6,1994,				3,		2,			1		,1,{6,2,1993}},




			};
//	sFiguritas banco_de_datos[CANT_FIGURITAS];
//	inicializarFiguritas(banco_de_datos,CANT_FIGURITAS);
	sClub cantidad_equipos[CANT_EQUIPOS] = {
			{1,"boca","salute22",1910,1},
			{2,"riber","chau123",1920,1},
			{3,"quilmes","12hola23",1930,1},
			{4,"argentinojrs","12hola",1940,1},
	};
//	sClub cantidad_equipos[CANT_EQUIPOS];
//	inicializarClubes(cantidad_equipos, CANT_EQUIPOS);
	sSeleccion cantidad_selecciones[CANT_SELECCIONES] = {
			{1,"Argentina","scaloni",1,5},
			{2,"brazil","neymar",1,3},
			{3,"alemania","strujen",1,2},
			{4,"uruguay","mateo",1,2},
			{5,"wakanda","mateo",1,2},
			{6,"francia","mateo",1,2},
			{7,"USA","mateo",1,2},
			{8,"mexico","mateo",1,2},
			{9,"chile","mateo",1,2},
			{10,"peru","mateo",1,2},
			{11,"holanda","mateo",1,1},
	};

//	sSeleccion cantidad_selecciones[CANT_SELECCIONES];
//	inicializarSelecciones(cantidad_selecciones, CANT_SELECCIONES);
	sRepresentantes cantidad_representantes[CANT_REPRESENTANTES] = {
			{1,"Gus","Petrov","descripción1",9000,1},
			{2,"Martin","Certeza","descripción2",5000,1},
			{3,"Soledad","Locura","descripción3",100,1},
			{4,"Mariano","Rodriguez","descripción4",999999,1},
	};

//	sRepresentantes cantidad_representantes[CANT_REPRESENTANTES];
//	inicializarRepresentantes(cantidad_representantes, CANT_REPRESENTANTES);
/*--------------------------------Album y Mazo repetids--------------------------------*/
	sAlbum album;
	album.estadoAlbum = LIBRE;
	sRepetidas figuritasRepetidas[CANT_FIGURITAS];

	do {
		getInt(&opcionMenuPrincipal, "\nBienvenido a Pangiannini.."
						"\nIngrese una opción:"
						"\n1.Perfil Administrador..."
						"\n2.Perfil Coleccionista..."
						"\n3.Salir...", "\nError!", 1, 3);
		switch(opcionMenuPrincipal)
		{
		case 1:
			puts("\n\n\n\t\t\t****Perfil Administrador****");
			menu_Perfil_Administrador(banco_de_datos, CANT_FIGURITAS, cantidad_equipos, CANT_EQUIPOS,cantidad_selecciones,CANT_SELECCIONES,cantidad_representantes, CANT_REPRESENTANTES);
			break;
		case 2:
			if((validarArrayCargadoClubes(cantidad_equipos, CANT_EQUIPOS) == 1 ) && ( validarArrayCargadoRepresentantes(cantidad_representantes,CANT_REPRESENTANTES) == 1 ) && ( validarArrayCargadoSelecciones(cantidad_selecciones,CANT_SELECCIONES) == 1) && (validarArrayCargadoFiguritas( banco_de_datos, CANT_FIGURITAS) == 1))
			{
				puts("\n\n\n\t\t\t****Perfil Coleccionista****");
				menu_Perfil_Coleccionista(album, figuritasRepetidas, banco_de_datos, CANT_FIGURITAS, cantidad_equipos, CANT_EQUIPOS, cantidad_selecciones, CANT_SELECCIONES, cantidad_representantes, CANT_REPRESENTANTES);
			}else
			{
				puts("ERROR!!\n>> Cargar el menu de altas primero...");
			}
			printf("Opcion menú Coleccionista");
			break;
		case 3:
			printf("\n\t*****¡Gracias por su visita!*****");
			break;
		}

	}while(opcionMenuPrincipal != 3);

	return EXIT_SUCCESS;
}
