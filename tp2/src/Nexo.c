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
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Jugador
				eJugador_MostrarUno(array[i],arrayConfederaciones,TAM_Confederacion);
				//CONTADOR DE Jugador
				cantidad++;
			}
		}
		puts("\t==================================================================================================================");
	}

	//SI CANTIDAD == 0 - NO HUBO Jugador PARA MOSTRAR (ARRAY SIN ALTAS)
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

	//CABECERA
	puts("\t> Jugador\n");
//	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
	printf("\t|  %5s | %20s | %16s | %13s | %13s | %11s | %13s  |\n", "ID", "Nombre", "Posicion", "NumCamiseta", "Confederacion", "Salario", "AñoContratos");

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Jugador
				eJugador_MostrarUno(array[i],arrayConfederaciones,TAM_Confederacion);
				//CONTADOR DE Jugador
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Jugador PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}
eJugador eJugador_CargarDatos(eConfederacion array[], int TAM)
{
	eJugador auxiliar;
	int idConfederacionAux;

	getString(auxiliar.nombre, 50, "\nIngrese Nombre Jugador", "\nError!");
	getString(auxiliar.posicion,50, "\nIngrese Posicion Jugador", "\nError!");
	while(stricmp(auxiliar.posicion,"Arquero") && stricmp(auxiliar.posicion,"Defensor") && stricmp(auxiliar.posicion,"MedioCampista") && stricmp(auxiliar.posicion,"Delantero") )
	{
		getString(auxiliar.posicion,50, "\nIngrese una de las siguientes posiciones para el jugador: "
				"\nArquero"
				"\nDefensor"
				"\nMedioCampista"
				"\nDelantero", "\nError!");
	}
	getShort(&auxiliar.numeroCamiseta, "\nIngrese Numero Camiseta", "\nError!", 1, 99);
	//Listo las confederaciones
	eConfederacion_MostrarTodos(array, TAM);
	// validar que exista el ID de confederacion
	getInt(&idConfederacionAux, "\nIngrese Confederación", "\nError!", 100, 1000);
	while(verificarID_Confederaciones(array,TAM,idConfederacionAux) == 0)
	{
		getInt(&idConfederacionAux, "\nIngrese Confederación", "\nError!", 100, 1000);
	}
	auxiliar.idConfederacion = idConfederacionAux;
	getFloat(&auxiliar.salario, "\nIngrese Salario Jugador", "\nError!", 10000, 1000000);
	getShort(&auxiliar.aniosContrato, "\nIngrese años de contrato", "\nError!", 1, 10);


	return auxiliar;
}

// Verifico que el id que me ingresa en el ALTA exista en el array de confederaciones
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
	getInt(&idConfederacionAux, "\nIngrese nueva Confederación", "\nError!", 100, 1000);
	while(verificarID_Confederaciones(confederacion,TAM_Confederacion,idConfederacionAux) == 0)
	{
		getInt(&idConfederacionAux, "\nIngrese nueva Confederación", "\nError!", 100, 1000);
	}
	auxiliar.idConfederacion = idConfederacionAux;
	return auxiliar;

}

int eJugador_Alta(eJugador array[], int TAM, eConfederacion arrayConfederacion[], int TAMconfederacion)
{
	int rtn = 0;
	eJugador auxJugador;

	//BUSCO ESPACIO EN ARRAY
	int index = eJugador_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Jugador AUXILIAR
		auxJugador = eJugador_CargarDatos(arrayConfederacion,TAMconfederacion);
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxJugador.idJugador = jugador_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxJugador.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxJugador;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
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

	//LISTO TODOS LOS Jugador
	if (eJugador_MostrarTodos(array, TAM,arrayConfederaciones,TAM_Confederacion)) {
		//BANDERA EN 1 SI HAY Jugador DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Jugador PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idJugador);

		//BUSCO INDEX POR ID EN ARRAY
		while (eJugador_BuscarPorID(array, TAM, idJugador) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idJugador);
		}

		//OBTENGO INDEX DEL ARRAY DE Jugador A DAR DE BAJA
		index = eJugador_BuscarPorID(array, TAM, idJugador);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
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

	//LISTO TODOS LOS Jugador
	if (eJugador_MostrarTodos(array, TAM, arrayConfederaciones,TAM_Confederacion)) {
		//BANDERA EN 1 SI HAY Jugador DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Jugador PARA MODIFICAR
	if (flag)
	{
		//PIDO ID A MODIFICAR
		getInt(&idJugador, "\nID jugador a modificar", "\nERROR!", 0, 3000);
		//BUSCO INDEX POR ID EN ARRAY
		while (eJugador_BuscarPorID(array, TAM, idJugador) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			getInt(&idJugador, "\nID jugador a modificar", "\nERROR!", 0, 3000);
		}

		//OBTENGO INDEX DEL ARRAY DE Jugador A MODIFICAR
		index = eJugador_BuscarPorID(array, TAM, idJugador);
		do
		{
			getInt(&option, "\nID jugador a modificar"
									"\n1.Modificar Nombre"
									"\n2.Modificar Posición"
									"\n3.Modificar Numero Camiseta"
									"\n4.Modificar Confederación"
									"\n5.Modificar Salario"
									"\n6.Modificar Contrato"
									"\n7.Salir \n", "\nERROR!", 0, 3000);
				switch(option)
				{
					case 1:
						printf("\nModificar Nombre: \n");
						auxiliar = eJugador_ModificarNombre(array[index]);
						break;
					case 2:
						printf("\nModificar Posición: \n");
						auxiliar = eJugador_ModificarPosicion(array[index]);
						break;
					case 3:
						printf("\nModificar Numero Camiseta: \n");
						auxiliar = eJugador_ModificarNumeroCamiseta(array[index]);
						break;
					case 4:
						printf("\nModificar Confederación: \n");
						auxiliar = eJugador_ModificarConfederacion(array[index],arrayConfederaciones, TAM_Confederacion);
						break;
					case 5:
						printf("\nModificar Salario: \n");
						auxiliar = eJugador_ModificarSalario(array[index]);
						break;
					case 6:
						printf("\nModificar Contrato: \n");
						auxiliar = eJugador_ModificarContrato(array[index]);
						break;
					case 7:
						break;
				}
					}while(option != 7);

		//LLAMO A FUNCION QUE MODIFICA Jugador

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	//llave del if flag
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
	//Si existen los array y los límites son válidos
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
	int i;
	int j;
	int x;
	int z;
	eJugador aux;
	eConfederacion auxConfederacion;

	/** EJEMPLO DE SORT CON ID DE Jugador
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)
	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			//Ordeno jugadores alfabeticamente
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (stricmp(array[i].nombre,array[j].nombre) > 0) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			// segundo for para ordenar por confederacion
			for(x = 0; x < TAM_Confederacion - 1; x++)
			{
				for(z = x + 1; z < TAM_Confederacion; z++)
				{
					//Pregunto por el estado "OCUPADO" de ambos
					if(arrayConfederacion[x].isEmpty == OCUPADO
							&& arrayConfederacion[z].isEmpty == OCUPADO)
					//Criterio de ordenamiento
					{
						if(stricmp(arrayConfederacion[x].nombre,arrayConfederacion[z].nombre) > 0)
						{
							auxConfederacion = arrayConfederacion[x];
							arrayConfederacion[x] = arrayConfederacion[z];
							arrayConfederacion[z] = auxConfederacion;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idJugador < array[j].idJugador) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
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
					// for para recorrer el arr de jugadores y printear los que match con el id de esta confederacion[i]
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
				printf("\nLa región con más jugadores es: %s\n",regionAuxiliar);
				listarJugadoresRegion(arrayJugadores, TAM_Jugador, arrayConfederaciones, TAM_Confederacion, regionAuxiliar);
			}
}

