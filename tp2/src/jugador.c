#include "jugador.h"
#include "confederacion.h"
#include "inputs.h"
#include "e-s.h"

static int eJugador_ObtenerID(void);
static int eJugador_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eJugador_ObtenerID();
	static int Jugador_idIncremental = 0;
	return Jugador_idIncremental++;
}

int jugador_ObtenerID(void)
{
	return eJugador_ObtenerID();
}

void eJugador_Inicializar(eJugador array[], int TAM) {

	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}
/*----VALIDAR JUGADORES CARGADOS---*/
int eJugador_ObtenerIndexLibre(eJugador array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int eJugador_BuscarPorID(eJugador array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idJugador == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

// Cantidad jugadores
int eJugador_ContarJugadores(eJugador array[], int TAM)
{
	int contadorJugadores;
	contadorJugadores = 0;
	if(array != NULL && TAM > 0) {
		for(int i = 0; i < TAM; i++) {
			if(array[i].isEmpty == OCUPADO) {
				contadorJugadores++;
			}
		}
	}
	return contadorJugadores;
}
//Obtener salario total de jugadores
float acumularSalariosTotales(eJugador array[], int TAM)
{
	float acumuladorSalario = 0;
	for(int i = 0; i < TAM; i++) {
		if(array[i].isEmpty == OCUPADO) {
			acumuladorSalario += array[i].salario;
		}
	}

	return acumuladorSalario;
}

// salario total / cant jugadores = promedio salarios totales

float promedioSalario(eJugador array[], int TAM)
{
	int contadorJugadores;
	float acumuladorSalarios;
	float promedioSalarial;
	contadorJugadores = eJugador_ContarJugadores(array, TAM);
	acumuladorSalarios = acumularSalariosTotales(array, TAM);

	promedioSalarial = acumuladorSalarios / contadorJugadores;
	printf("\n*Salarios totales: %.2f ",acumuladorSalarios);
	printf("\n*Promedio Salarial: %.2f ",promedioSalarial);

	return promedioSalarial;
}

int obtenerJugadoresConSalarioMaximo(eJugador array[], int TAM)
{
	int contadorJugadores;
	int salarioPromedio;
	salarioPromedio = promedioSalario(array, TAM);
	for(int i = 0; i < TAM; i++)
	{
		if(array[i].isEmpty == OCUPADO)
		{
			if(array[i].salario > salarioPromedio)
			{
				contadorJugadores++;
			}
		}
	}
	printf("\nCantidad de Jugadores con el salario máximo: %d \n ",contadorJugadores);
	return contadorJugadores;
}

eJugador eJugador_ModificarNombre(eJugador Jugador) {
	eJugador auxiliar;
	auxiliar = Jugador;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	getString(auxiliar.nombre, 50, "\nIngrese nuevo nombre...", "\nError!");

	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

eJugador eJugador_ModificarPosicion(eJugador Jugador)
{
	eJugador auxiliar;
	auxiliar = Jugador;

	getString(auxiliar.posicion,50, "\nIngrese una de las siguientes posiciones para el jugador: "
						"\nArquero"
						"\nDefensor"
						"\nMedioCampista"
						"\nDelantero", "\nError!");
	while(stricmp(auxiliar.posicion,"Arquero") && stricmp(auxiliar.posicion,"Defensor") && stricmp(auxiliar.posicion,"MedioCampista") && stricmp(auxiliar.posicion,"Delantero") )
		{
			getString(auxiliar.posicion,50, "\nIngrese una de las siguientes posiciones para el jugador: "
					"\nArquero"
					"\nDefensor"
					"\nMedioCampista"
					"\nDelantero", "\nError!");
		}

	return auxiliar;
}

eJugador eJugador_ModificarNumeroCamiseta(eJugador Jugador)
{
	eJugador auxiliar;
	auxiliar = Jugador;

	getShort(&auxiliar.numeroCamiseta, "\nIngrese nuevo numero camiseta", "\nError!", 1, 99);

	return auxiliar;
}

eJugador eJugador_ModificarSalario(eJugador Jugador)
{
	eJugador auxiliar;
	auxiliar = Jugador;

	getFloat(&auxiliar.salario, "\nIngrese nuevo salario: ", "\nError! ", 10000, 1000000);

	return auxiliar;
}
eJugador eJugador_ModificarContrato(eJugador Jugador)
{
	eJugador auxiliar;
	auxiliar = Jugador;

	getShort(&auxiliar.aniosContrato, "\nIngrese nuevo plazo de contrato ", "\nError! ", 1, 10);

	return auxiliar;
}

int eJugador_SortNombre(eJugador array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eJugador aux;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO && array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if(strcmp(array[i].nombre, array[j].nombre) > 0) {
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
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if(strcmp(array[i].nombre, array[j].nombre) < 0) {
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

eJugador eJugador_cargaPrueba(char nombre[], char posicion[], short numeroCamiseta, int idConfederacion, float salario, short aniosContrato)
{
	eJugador auxiliar;

		auxiliar.idJugador = eJugador_ObtenerID();
		strcpy(auxiliar.nombre, nombre);
		strcpy(auxiliar.posicion, posicion);
		auxiliar.numeroCamiseta = numeroCamiseta;
		auxiliar.idConfederacion = idConfederacion;
		auxiliar.salario = salario;
		auxiliar.aniosContrato = aniosContrato;
		auxiliar.isEmpty = OCUPADO;

	return auxiliar;

}


/*----------Validar----------*/

int eJugador_ValidarJugadoresCargados(eJugador array[], int TAM)
{
	int rtn = 0;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == OCUPADO) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = 1;
				break;
			}
		}
	}
	return rtn;
}
