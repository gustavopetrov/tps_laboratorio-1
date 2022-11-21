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


	Jugador[0] = eJugador_cargaPrueba("Gustavo Petrov", "Delantero", 10, 105, 50000, 2);
	Jugador[1] = eJugador_cargaPrueba("Armando Esteban Quito", "Defensor", 1, 103, 20000, 5);
	Jugador[2] = eJugador_cargaPrueba("Ricardo", "Arquero", 1, 102, 50000, 4);
	Jugador[3] = eJugador_cargaPrueba("Sergio Agüero", "Delantero", 1, 101, 40000, 8);
	Jugador[4] = eJugador_cargaPrueba("Megaman", "Delantero", 7, 101, 60000, 9);
	Jugador[5] = eJugador_cargaPrueba("Araceli López", "Defensor", 40, 100, 70000, 10);
	Jugador[6] = eJugador_cargaPrueba("ZubZero", "Defensor", 40, 101, 70000, 10);
	Jugador[7] = eJugador_cargaPrueba("Bruno", "Defensor", 40, 104, 70000, 10);

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

		//MENU SWITCH
		switch (option)
		{
		case 5:
			/** PREGUNTAR SI DESEA SALIR */
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
					//ORDENAR Producto
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
					promedioSalario(Jugador, TAM_Jugador);
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
			puts("No hay jugadores/confederaciones cargados");
		}
			break;
		}
	} while (option != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}
