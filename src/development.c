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

void mostrarCalculos(float mantenimiento, float promedioAFC, float promedioCAF, float promedioCONCACAF, float promedioCONMEBOL, float promedioUEFA, float promedioOFC ){
	printf("\nGastos de mantenimiento: %.2f", mantenimiento);
	printf("\nPromedio confederación AFC: %.2f ",promedioAFC);
	printf("\nPromedio confederación CAF: %.2f ",promedioCAF);
	printf("\nPromedio confederación CONCACAF: %.2f ",promedioCONCACAF);
	printf("\nPromedio confederación CONMEBOL: %.2f ",promedioCONMEBOL);
	printf("\nPromedio confederación UEFA: %.2f ",promedioUEFA);
	printf("\nPromedio confederación OFC: %.2f ",promedioOFC);
}

void mostrarCostos(float gastosHospedaje, float gastosComida, float gastosTransporte)
{
	printf("\n  Costo de hospedaje ->$%.2f ",gastosHospedaje);
	printf("\n  Costo de comida ->$%.2f ",gastosComida);
	printf("\n  Costo de transporte ->$%.2f ",gastosTransporte);
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
		{
			opcionMenuPrincipal = opcionesMenuPrincipal(gastosHospedaje,gastosComida,gastosTransporte,arqueros,defensores,medioCampistas,delanteros);

			switch(opcionMenuPrincipal)
			{
			case 1:
				do
				{
					opcionMantenimiento = opcionesMantenimiento(gastosHospedaje,gastosComida,gastosTransporte);

					switch(opcionMantenimiento)
					{
					case 1:
						gastosHospedaje = pedirValidarFloat(gastosHospedaje,0, "\nIngrese costo de hospedaje: ");
						break;

					case 2:
						gastosComida = pedirValidarFloat(gastosComida,0, "\nIngrese costo de comida: ");
						break;
					case 3:
						gastosTransporte = pedirValidarFloat(gastosTransporte,0, "\nIngrese costo de transporte: ");
						break;
					case 4:
						printf("\nVolviendo al menú...\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
						break;
					default:
						printf("\nError, seleccione una opción válida.");
						break;
					}


				}while(opcionMantenimiento != 4);
				break;
			case 2:
				do {
					opcionCargaJugadores = opcionesCargaJugadores(arqueros,defensores,medioCampistas,delanteros);

					switch(opcionCargaJugadores)
					{
					case 1:
						if(arqueros == 2){
							printf("\n ******Llegaste al límite máximo de arqueros.****** \n");
						}else{
							nroCamiseta = pedirValidarInt(nroCamiseta, 1, 99, "Ingrese número de camiseta\n", "Número ingresado no válido ...\n");
							printf("Se cargo el jugador con el nro de camiseta: %d",nroCamiseta);

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
							printf("\nAcaba de ingresar un jugador en la posición de Arquero...");
							arqueros++;
						}
						break;
					case 2:
						if(defensores == 8){
							printf("\n ******Llegaste al límite máximo de Defensores.****** \n");
						}else{
							nroCamiseta = pedirValidarInt(nroCamiseta, 1, 99, "Ingrese número de camiseta\n", "Número ingresado no válido ...\n");
							printf("Se cargo el jugador con el nro de camiseta: %d",nroCamiseta);
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
						if(medioCampistas == 8){
							printf("\n ******Llegaste al límite máximo de Medio Campistas.****** \n");
						}else{
							nroCamiseta = pedirValidarInt(nroCamiseta, 1, 99, "Ingrese número de camiseta\n", "Número ingresado no válido ...\n");
							printf("Se cargo el jugador con el nro de camiseta: %d",nroCamiseta);
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
						if(delanteros == 4){
							printf("\n ******Llegaste al límite máximo de Delanteros.****** \n");
						}else{
							nroCamiseta = pedirValidarInt(nroCamiseta, 1, 99, "Ingrese número de camiseta\n", "Número ingresado no válido ...\n");
							printf("Se cargo el jugador con el nro de camiseta: %d",nroCamiseta);
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
				validacionProcesos = validarIngresos(arqueros, defensores, medioCampistas, delanteros, gastosHospedaje, gastosComida, gastosTransporte);
				if(validacionProcesos == 1){
					validacionSalidaDeDatos = 1;
					mantenimiento = gastosHospedaje + gastosComida + gastosTransporte;
					if(uefa > afc && uefa > caf && uefa > concacaf && uefa > conmebol && uefa > ofc  ){
						// Cálculo de mantenimiento con aumento
						mantenimiento = mantenimiento + (mantenimiento * 0.35);
					}

					// Cálculo de promedios
					totalJugadores = afc + caf + concacaf + conmebol + uefa+ ofc;
					promedioAFC = (float)afc / totalJugadores;
					promedioCAF = (float)caf / totalJugadores;
					promedioCONCACAF = (float)concacaf / totalJugadores;
					promedioCONMEBOL = (float)conmebol / totalJugadores;
					promedioUEFA = (float)uefa / totalJugadores;
					promedioOFC = (float)ofc / totalJugadores;
				}else {
					printf("\n\n\n\n******No puedo procesar los datos si aún no los cargaste en el sistema!****** \n\n\n\n");
				}
				break;
			case 4:
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



