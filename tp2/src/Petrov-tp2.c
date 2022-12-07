#include "Jugador.h"
#include "confederacion.h"
#include "Nexo.h"
#include "inputs.h"
#include "e-s.h"
#define TAM_Jugador 3000
#define TAM_Confederacion 6

int main(void) {
	setbuf(stdout, NULL);

	int option;
	int rtaAux;
	int rtaAuxBis;
	int criterioDeOrdenamiento;

	//CREO ARRAY DE ESTRUCTURA
	eJugador Jugador[TAM_Jugador];
	eConfederacion Confederacion[TAM_Confederacion];

	//INICIALIAZO ARRAY DE ESTRUCTURA JUGADOR
	eJugador_Inicializar(Jugador, TAM_Jugador);
	//INICIALIZO ARRAY ESTRUCTURA CONFEDERACION
	eConfederacion_Inicializar(Confederacion, TAM_Confederacion);


	Jugador[1] = eJugador_cargaPrueba("Emiliano Martinez", "ARQUERO", 1, 100, 100000, 4);
	Jugador[2] = eJugador_cargaPrueba("Juan Musso", "ARQUERO", 12, 100, 80000, 2);
	Jugador[3] = eJugador_cargaPrueba("Leo Messi", "DELANTERO", 10, 100, 80000, 4);
	Jugador[4] = eJugador_cargaPrueba("Almirez Ali", "DELANTERO", 9, 100, 55000, 1);
	Jugador[5] = eJugador_cargaPrueba("Harry Maguire", "DEFENSOR", 2, 101, 70000, 4);
	Jugador[6] = eJugador_cargaPrueba("Eric Dier", "DEFENSOR", 3, 101, 60000, 2);
	Jugador[7] = eJugador_cargaPrueba("Harry Kane", "DELANTERO", 10, 101, 3000, 2);
	Jugador[8] = eJugador_cargaPrueba("Alfred Gomis", "ARQUERO", 1, 101, 9000, 1);
	Jugador[9] = eJugador_cargaPrueba("Abdelkarim Hassan", "MEDIOCAMPISTA", 8, 101, 48000, 1);
	Jugador[10] = eJugador_cargaPrueba("Guillermo Ochoa", "ARQUERO", 1, 104, 90000, 4);
	Jugador[11] = eJugador_cargaPrueba("Tecatito", "DELANTERO", 11, 104, 100000, 3);
	Jugador[12] = eJugador_cargaPrueba("Luis Romo", "MEDIOCAMPISTA", 7, 104, 100000, 2);
	Jugador[13] = eJugador_cargaPrueba("Bamba Dieng", "DELANTERO", 9, 103, 100000, 2);
	Jugador[14] = eJugador_cargaPrueba("Demba Seck", "DELANTERO", 11, 103, 6000, 2);
	Jugador[15] = eJugador_cargaPrueba("Tarek Salman", "DEFENSOR", 6, 102, 78000, 5);

	Confederacion[0] = eConfederacion_cargaPrueba("CONMEBOL","SUDAMERICA",1916);
	Confederacion[1] = eConfederacion_cargaPrueba("UEFA","EUROPA",1954);
	Confederacion[2] = eConfederacion_cargaPrueba("AFC", "ASIA",1954);
	Confederacion[3] = eConfederacion_cargaPrueba("CAF", "AFRUCA",1957);
	Confederacion[4] = eConfederacion_cargaPrueba("CONCACAF", "NORTE Y CENTRO AMERICA",1961);
	Confederacion[5] = eConfederacion_cargaPrueba("OFC", "OCEANIA",1966);


	//BUCLE DE MENU
	do {
		getInt(&option, "\nIngrese una opción:"
				"\n1.Alta Jugador... "
				"\n2.Baja Jugador... "
				"\n3.Menú Modificacion..."
				"\n4.Menú Listados..."
				"\n5.Salir... ", "\nError!", 1, 6);

		switch (option)
		{
		case 5:

			getInt(&option, "\nDesea salir?"
					"\n1.Sí."
					"\n2.No.", "\nError!", 1, 2);
			if(option == 1)
			{
				option = 0;

			}
			break;
		case 1:
			//ALTA
			if (eJugador_Alta(Jugador, TAM_Jugador,Confederacion,TAM_Confederacion)) {
				puts(" * Jugador DADO DE ALTA EXITOSAMENTE");
			} else {
				puts(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS Jugador");
			}
			system("pause");
			break;
		case 2:
			//BAJA
			if (eJugador_Baja(Jugador, TAM_Jugador,Confederacion,TAM_Confederacion)) {
				puts("\n * BAJA DE Jugador EXITOSA");
				eJugador_MostrarTodos(Jugador, TAM_Jugador,Confederacion,TAM_Confederacion);
			} else {
				puts("\n * BAJA DE Jugador CANCELADA");
			}
			system("pause");
			break;
		case 3:
			//MODIFICACION
			if (eJugador_Modificacion(Jugador, TAM_Jugador,Confederacion,TAM_Confederacion)) {
				puts("\n * MODIFICACION DE Jugador EXITOSA\n");
				eJugador_MostrarTodos(Jugador, TAM_Jugador,Confederacion,TAM_Confederacion);
			} else {
				puts("\n * MODIFICACION DE Jugador CANCELADA");
			}
			system("pause");
			break;
		case 4:
			//LISTADO Jugador
			rtaAux = eJugador_ValidarJugadoresCargados(Jugador, TAM_Jugador);
			rtaAuxBis = eConfederacion_ValidarConfederacionesCargadas(Confederacion, TAM_Confederacion);
			if(rtaAux && rtaAuxBis)
			{
				do
				{
				getInt(&option, "\nIngrese opción:"
						"\n1.★ Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador."
						"\n2.★ Listado de confederaciones con sus jugadores."
						"\n3.★ Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio."
						"\n4.★ Informar la confederación con mayor cantidad de años de contratos total."
						"\n5.★ Informar porcentaje de jugadores por cada confederación"
						"\n6.★ Informar cual es la región con más jugadores y el listado de los mismos"
						"\n7.Salir...", "\nError!", 1, 7);
				switch(option)
				{
				case 1:

					criterioDeOrdenamiento = -1; //PEDIR CRITERIO DE ORDENAMIENTO
					getInt(&criterioDeOrdenamiento, "\nCriterio de ordenamiento:"
							"\n -1 -> ordenamiento ascendente (Menor a Mayor) "
							"\n 1 -> ordenamiento descendente (Mayor a Menor) ", "\nError!", -1, 1);
					while(criterioDeOrdenamiento == 0)
					{
						getInt(&criterioDeOrdenamiento, "\nCriterio de ordenamiento:"
											"\n -1 -> ordenamiento ascendente (Menor a Mayor) "
											"\n 1 -> ordenamiento descendente (Mayor a Menor) ", "\nError!", -1, 1);
					}
					eJugador_Sort(Jugador, TAM_Jugador, criterioDeOrdenamiento,Confederacion,TAM_Confederacion);
					mostrarTodosLosJugadoresDeUnaConfederacion(Jugador,TAM_Jugador, Confederacion, TAM_Confederacion);
					system("pause");
					break;
				case 2:
					if( eJugador_MostrarTodos(Jugador, TAM_Jugador,Confederacion, TAM_Confederacion) && eConfederacion_MostrarTodos(Confederacion, TAM_Confederacion) )
					{
						system("pause");
					}else{
						puts("\nNo Hay jugadores cargados...");
					}
					break;
				case 3:
					eJugador_ContarJugadores(Jugador, TAM_Jugador);
					acumularSalariosTotales(Jugador, TAM_Jugador);
					obtenerJugadoresConSalarioMaximo(Jugador, TAM_Jugador);
					system("pause");
					break;
				case 4:
					confederacionConMaximoContrato(Jugador, TAM_Jugador, Confederacion, TAM_Confederacion);
					system("pause");
					break;
				case 5:
					porcentajeJugadoresPorRegion(Jugador, TAM_Jugador, Confederacion, TAM_Confederacion);
					system("pause");
					break;
				case 6:
					regionConMasJugadores(Jugador, TAM_Jugador, Confederacion, TAM_Confederacion);
					system("pause");
					break;
				case 7:
					break;
				}

			}while(option != 7);
		}
		else
		{
			puts("\t**No hay jugadores cargados**");
		}
			break;
		}
	} while (option != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}
