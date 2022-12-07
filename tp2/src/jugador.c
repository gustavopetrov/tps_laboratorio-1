#include "jugador.h"
#include "confederacion.h"
#include "inputs.h"
#include "e-s.h"

static int eJugador_ObtenerID(void);
static int eJugador_ObtenerID(void) {
	static int Jugador_idIncremental = 1;
	return Jugador_idIncremental++;
}

int jugador_ObtenerID(void)
{
	return eJugador_ObtenerID();
}

void eJugador_Inicializar(eJugador array[], int TAM) {

	int i;
	if (array != NULL && TAM > 0) {

		for (i = 0; i < TAM; i++) {

			array[i].isEmpty = LIBRE;
		}
	}
}

int eJugador_ObtenerIndexLibre(eJugador array[], int TAM) {
	int rtn = -1;
	int i;


	if (array != NULL && TAM > 0) {

		for (i = 0; i < TAM; i++) {

			if (array[i].isEmpty == LIBRE) {

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


	if (array != NULL && TAM > 0) {

		for (i = 0; i < TAM; i++) {

			if (array[i].idJugador == ID && array[i].isEmpty == OCUPADO) {

				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

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

	getString(auxiliar.nombre, 50, "\nIngrese nuevo nombre\n>> ", "\nError!\n");
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

	getShort(&auxiliar.numeroCamiseta, "\nIngrese nuevo numero camiseta\n>> ", "\nError!\n", 1, 99);

	return auxiliar;
}

eJugador eJugador_ModificarSalario(eJugador Jugador)
{
	eJugador auxiliar;
	auxiliar = Jugador;

	getFloat(&auxiliar.salario, "\nIngrese nuevo salario, de 1000 a 9000000\n>> ", "\nError! ", 1000, 9000000);

	return auxiliar;
}
eJugador eJugador_ModificarContrato(eJugador Jugador)
{
	eJugador auxiliar;
	auxiliar = Jugador;

	getShort(&auxiliar.aniosContrato, "\nIngrese nuevo plazo de contrato, 1 a 10\n>> ", "\nError!\n ", 1, 10);

	return auxiliar;
}

int eJugador_SortNombre(eJugador array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eJugador aux;

	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					if (array[i].isEmpty == OCUPADO && array[j].isEmpty == OCUPADO) {
						if(strcmp(array[i].nombre, array[j].nombre) > 0) {
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

					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {

						if(strcmp(array[i].nombre, array[j].nombre) < 0) {

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

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == OCUPADO) {
				rtn = 1;
				break;
			}
		}
	}
	return rtn;
}
