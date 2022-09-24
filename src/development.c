#include <stdio.h>
#include "headers.h"

float pedirValidarFloat(float numeroFloat, int minimo, char mensaje[])
{
	printf(mensaje);
	scanf("%f",&numeroFloat);
	while(numeroFloat <= minimo)
	{
			printf("Error, no puede ser 0!!!");
			scanf("%f",&numeroFloat);
		}
	return numeroFloat;
}

int pedirInt(char mensaje[])
{
	int numeroEntero;
	printf(mensaje);
	scanf("%d",&numeroEntero);
	return numeroEntero;
}

int pedirValidarInt(int numeroEntero, int minimo, int maximo, char mensaje[],char mensajeError[])
{
	printf(mensaje);
	scanf("%d",&numeroEntero);
	while(numeroEntero < minimo || numeroEntero > maximo)
	{
		printf(mensajeError);
		scanf("%d",&numeroEntero);
	}
	return numeroEntero;
}
float calculadoraPromedios( int confederacion, int totalJugadores)
{
	float promedio;
	promedio = (float)confederacion / totalJugadores;
	return promedio;
}

void mostrarCalculos(float mantenimiento, float promedioAFC, float promedioCAF, float promedioCONCACAF, float promedioCONMEBOL, float promedioUEFA, float promedioOFC ){
	printf("\nGastos de mantenimiento: %.2f", mantenimiento);
	printf("\nPromedio confederación AFC: %.2f ",promedioAFC);
	printf("\nPromedio confederación CAF: %.2f ",promedioCAF);
	printf("\nPromedio confederación CONCACAF: %.2f ",promedioCONCACAF);
	printf("\nPromedio confederación CONMEBOL: %.2f ",promedioCONMEBOL);
	printf("\nPromedio confederación UEFA: %.2f ",promedioUEFA);
	printf("\nPromedio confederación OFC: %.2f\n\n ",promedioOFC);
}

void mostrarCostos(float gastosHospedaje, float gastosComida, float gastosTransporte)
{
	printf("\n  Costo de hospedaje ->$%.2f ",gastosHospedaje);
	printf("\n  Costo de comida ->$%.2f ",gastosComida);
	printf("\n  Costo de transporte ->$%.2f\n ",gastosTransporte);
}

void mostrarJugadores(int arqueros, int defensores, int medioCampistas, int delanteros)
{
	printf("\n  Arqueros -> %d",arqueros);
	printf("\n  Defensores -> %d",defensores);
	printf("\n  Medio Campistas -> %d",medioCampistas);
	printf("\n  Delanteros -> %d",delanteros);
}

int opcionesMenuPrincipal (float gastosHospedaje, float gastosComida, float gastosTransporte, int arqueros, int defensores, int medioCampistas, int delanteros)
{
	int opcionMenuPrincipal;
	printf("\t\t Menú Principal\n");
	printf("\n1. Ingreso de los costos de mantenimiento");
	mostrarCostos(gastosHospedaje,gastosComida,gastosTransporte);
	printf("\n2. Carga de jugadores");
	mostrarJugadores(arqueros,defensores,medioCampistas,delanteros);
	printf("\n3. Realizar todos los cálculos");
	printf("\n4. Informar todos los resultados");
	printf("\n5. Salir");
	opcionMenuPrincipal = pedirInt("\nIngrese una de las opciones...");
	return opcionMenuPrincipal;
}

int opcionesMantenimiento(float gastosHospedaje, float gastosComida, float gastosTransporte)
{
	int opcionMantenimiento;
	mostrarCostos(gastosHospedaje, gastosComida, gastosTransporte);
	printf("\n\n1. hospedaje ");
	printf("\n2. comida ");
	printf("\n3. transporte");
	printf("\n4. Salir");
	opcionMantenimiento = pedirInt("\n\nIngrese una de las opciones...");
	return opcionMantenimiento;
}

int opcionesCargaJugadores(int arqueros, int defensores, int medioCampistas, int delanteros)
{
	int opcionCargaJugadores;
	mostrarJugadores(arqueros, defensores, medioCampistas, delanteros);
	printf("\n\n1. Arqueros");
	printf("\n2. Defensores");
	printf("\n3. Medio Campistas");
	printf("\n4. Delanteros");
	printf("\n5. Salir");
	opcionCargaJugadores = pedirInt( "\n\nIngrese una de las opciones...");

	return opcionCargaJugadores;

}

int validarIngresos(int arqueros, int defensores, int medioCampistas, int delanteros,float gastosHospedaje, float gastosComida, float gastosTransporte)
{
	int retorno;
	retorno = -1;
	if((arqueros > 0 || defensores > 0 || medioCampistas > 0 || delanteros > 0) && ( gastosComida > 0 && gastosHospedaje > 0 && gastosTransporte > 0) ){
		retorno = 1;
	}
	return retorno;
}
// función menu principal
void menuPrincipal (void){
	// ------ 1. Ingreso de los costos de Mantenimiento --------
		float gastosTransporte;
		float gastosHospedaje;
		float gastosComida;
		float mantenimiento;
		gastosTransporte = 0;
		gastosHospedaje = 0;
		gastosComida = 0;
		mantenimiento = 0;
	// ------ 2. Carga de jugadores --------
		int arqueros;
		int defensores;
		int medioCampistas;
		int delanteros;
		int nroCamiseta;
		int confederaciones;
		int afc;
		int caf;
		int concacaf;
		int conmebol;
		int uefa;
		int ofc;
		afc = 0;
		caf = 0;
		concacaf = 0;
		conmebol = 0;
		uefa = 0;
		ofc = 0;
		arqueros = 0;
		defensores = 0;
		medioCampistas = 0;
		delanteros = 0;
		confederaciones = 0;

	//	------ 3. Realizar todos los cálculos ------
		int validacionProcesos;
		int totalJugadores;
		float promedioAFC;
		float promedioCAF;
		float promedioCONCACAF;
		float promedioCONMEBOL;
		float promedioUEFA;
		float promedioOFC;

	//	------ 4. Informar todos los resultados ------
		int validacionSalidaDeDatos;
		validacionSalidaDeDatos = -1;

	// ------ menú --------

		int opcionMenuPrincipal;
		int opcionMantenimiento;
		int opcionCargaJugadores;

		do
		{	// recibo una opción y la atajo en opcionMenuPrincipal
			opcionMenuPrincipal = opcionesMenuPrincipal(gastosHospedaje,gastosComida,gastosTransporte,arqueros,defensores,medioCampistas,delanteros);
			// utilizo la respuesta para entrar al switch
			switch(opcionMenuPrincipal)
			{
			case 1:
				do
				{
					// Selecciono la primer opción, listo un menú con opciones de mantenimiento y atajo su respuesta en opcionMantenimiento
					opcionMantenimiento = opcionesMantenimiento(gastosHospedaje,gastosComida,gastosTransporte);
					// con la opción que eligió verifico que hacer
					switch(opcionMantenimiento)
					{
					case 1:
						// pido y valido los datos de gastos de hospedaje
						gastosHospedaje = pedirValidarFloat(gastosHospedaje,0, "\nIngrese costo de hospedaje: ");
						break;

					case 2:
						// pido y valido los datos de gastos comida
						gastosComida = pedirValidarFloat(gastosComida,0, "\nIngrese costo de comida: ");
						break;
					case 3:
						// pido y valido los datos de gastos de transporte
						gastosTransporte = pedirValidarFloat(gastosTransporte,0, "\nIngrese costo de transporte: ");
						break;
					case 4:
						// opción para volver al menú principal
						printf("\nVolviendo al menú...\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						break;
					default:
						// en caso de presionar cualquier tecla
						printf("\nError, seleccione una opción válida.");
						break;
					}


				}while(opcionMantenimiento != 4);
				break;
			case 2:
				do {
					// caso 2, listo el menu de opcionesCargaJugadores para elegir que posición cargar
					opcionCargaJugadores = opcionesCargaJugadores(arqueros,defensores,medioCampistas,delanteros);
					// con la respuesta atajada en opcioncargaJugadores, entro al switch
					switch(opcionCargaJugadores)
					{
					case 1:
						// verifico no exceder el límite permitido
						if(arqueros == 2){
							printf("\n ******Llegaste al límite máximo de arqueros.****** \n");
						}else{
							// pido y valido la  camiseta
							nroCamiseta = pedirValidarInt(nroCamiseta, 1, 99, "Ingrese número de camiseta\n", "Número ingresado no válido ...\n");
							printf("Se cargo el jugador con el nro de camiseta: %d",nroCamiseta);
							// pregunto y valido la confederación
							confederaciones = pedirValidarInt(confederaciones, 1, 6, "\n Ingrese confederación del jugador\n"
							"\n1. AFC"
							"\n2. CAF"
							"\n3. CONCACAF"
							"\n4. CONMEBOL"
							"\n5. UEFA"
							"\n6. OFC","Error, el rango válido es de 1 a 6.");
							// ataje la confederacion y checkeo que valor ingreso en el switch, dependiendo del valor incremento esa confederación
							switch(confederaciones){
							case 1:
								afc++;
								break;
							case 2:
								caf++;
								break;
							case 3:
								concacaf++;
								break;
							case 4:
								conmebol++;
								break;
							case 5:
								uefa++;
								break;
							case 6:
								ofc++;
								break;
							default:
								// en caso de presionar cualquierc osa
								printf("\nError, seleccione una opción válida.");
								break;
							}
							printf("\nAcaba de ingresar un jugador en la posición de Arquero...");
							arqueros++;
						}
						break;
					case 2:
						// verifico no exceder el límite permitido
						if(defensores == 8){
							printf("\n ******Llegaste al límite máximo de Defensores.****** \n");
						}else{
							// pido y valido la  camiseta
							nroCamiseta = pedirValidarInt(nroCamiseta, 1, 99, "Ingrese número de camiseta\n", "Número ingresado no válido ...\n");
							printf("Se cargo el jugador con el nro de camiseta: %d",nroCamiseta);
							// pregunto y valido la confederación
							confederaciones = pedirValidarInt(confederaciones, 1, 6, "\n Ingrese confederación del jugador\n"
							"\n1. AFC"
							"\n2. CAF"
							"\n3. CONCACAF"
							"\n4. CONMEBOL"
							"\n5. UEFA"
							"\n6. OFC","Error, el rango válido es de 1 a 6.");
							switch(confederaciones){
							case 1:
								afc++;
								break;
							case 2:
								caf++;
								break;
							case 3:
								concacaf++;
								break;
							case 4:
								conmebol++;
								break;
							case 5:
								uefa++;
								break;
							case 6:
								ofc++;
								break;
							default:
								printf("Error, seleccione una opción válida.");
								break;
							}
							defensores++;
						}
						break;
					case 3:
						// verifico no exceder el límite permitido
						if(medioCampistas == 8){
							printf("\n ******Llegaste al límite máximo de Medio Campistas.****** \n");
						}else{
							// pido y valido la  camiseta
							nroCamiseta = pedirValidarInt(nroCamiseta, 1, 99, "Ingrese número de camiseta\n", "Número ingresado no válido ...\n");
							printf("Se cargo el jugador con el nro de camiseta: %d",nroCamiseta);
							// pregunto y valido la confederación
							confederaciones = pedirValidarInt(confederaciones, 1, 6, "\n Ingrese confederación del jugador\n"
							"\n1. AFC"
							"\n2. CAF"
							"\n3. CONCACAF"
							"\n4. CONMEBOL"
							"\n5. UEFA"
							"\n6. OFC","Error, el rango válido es de 1 a 6.");
							switch(confederaciones){
							case 1:
								afc++;
								break;
							case 2:
								caf++;
								break;
							case 3:
								concacaf++;
								break;
							case 4:
								conmebol++;
								break;
							case 5:
								uefa++;
								break;
							case 6:
								ofc++;
								break;
							default:
								printf("Error, seleccione una opción válida.");
								break;
							}
							medioCampistas++;
						}
						break;
					case 4:
						// verifico no exceder el límite permitido
						if(delanteros == 4){
							printf("\n ******Llegaste al límite máximo de Delanteros.****** \n");
						}else{
							// pido y valido la  camiseta
							nroCamiseta = pedirValidarInt(nroCamiseta, 1, 99, "Ingrese número de camiseta\n", "Número ingresado no válido ...\n");
							printf("Se cargo el jugador con el nro de camiseta: %d",nroCamiseta);
							// pregunto y valido la confederación
							confederaciones = pedirValidarInt(confederaciones, 1, 6, "\n Ingrese confederación del jugador\n"
							"\n1. AFC"
							"\n2. CAF"
							"\n3. CONCACAF"
							"\n4. CONMEBOL"
							"\n5. UEFA"
							"\n6. OFC","Error, el rango válido es de 1 a 6.");
							switch(confederaciones){
							case 1:
								afc++;
								break;
							case 2:
								caf++;
								break;
							case 3:
								concacaf++;
								break;
							case 4:
								conmebol++;
								break;
							case 5:
								uefa++;
								break;
							case 6:
								ofc++;
								break;
							default:
								printf("\nError, seleccione una opción válida.");
								break;
							}
							delanteros++;
						}
						break;
					case 5:
						printf("\nVolviendo al menú...\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						break;
					default:
						printf("\nError, seleccione una opción válida.");
						break;
					}
				}while(opcionCargaJugadores != 5);
				break;
			case 3:
				// valido que se hayan cargado los ingresos y haya almenos 1 jugador y atajo la respuesta
				validacionProcesos = validarIngresos(arqueros, defensores, medioCampistas, delanteros, gastosHospedaje, gastosComida, gastosTransporte);
				// si el retorno de la función validarIngresos fue 1, todo ok
				if(validacionProcesos == 1){
					// seteo la validacionDeDatos para el punto 4
					validacionSalidaDeDatos = 1;
					// calculo el mantenimiento (la suma de los 3 costos)
					mantenimiento = gastosHospedaje + gastosComida + gastosTransporte;
					// pregunto si UEFA es la confederación con mas jugadores, de ser así aplico un 35% de aumento.
					if(uefa > afc && uefa > caf && uefa > concacaf && uefa > conmebol && uefa > ofc  ){
						// Cálculo de mantenimiento con aumento
						mantenimiento = mantenimiento + (mantenimiento * 0.35);
					}

					// la sumatoria de los jugadores por confedereación me da por resultado el total de jugadores
					totalJugadores = afc + caf + concacaf + conmebol + uefa+ ofc;
					// Cálculo de promedios
					promedioAFC = calculadoraPromedios(afc, totalJugadores);
					promedioCAF = calculadoraPromedios(caf, totalJugadores);
					promedioCONCACAF = calculadoraPromedios(concacaf, totalJugadores);
					promedioCONMEBOL = calculadoraPromedios(conmebol, totalJugadores);
					promedioUEFA = calculadoraPromedios(uefa, totalJugadores);
					promedioOFC = calculadoraPromedios(ofc, totalJugadores);
				}else {
					printf("\n\n\n\n******No puedo procesar los datos si aún no los cargaste en el sistema!****** \n\n\n\n");
				}
				break;
			case 4:
				// si se cumple la condición del punto 3 puedo mostrar los calculos
				if(validacionSalidaDeDatos == 1){
					mostrarCalculos(mantenimiento, promedioAFC, promedioCAF, promedioCONCACAF, promedioCONMEBOL, promedioUEFA, promedioOFC);
				}else{
					printf("\n\t ****** No puedo printear algo que todavía no procesé! ****** \n\n\n\n");
				}

				break;
			case 5:
				printf("\nGracias por su visita!");
				break;
			default:
				printf("\nError, seleccione una opción válida.");
				break;
			}

		}while(opcionMenuPrincipal != 5);
}



