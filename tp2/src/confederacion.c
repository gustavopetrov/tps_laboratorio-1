#include "confederacion.h"
#include "inputs.h"
#include "e-s.h"
#include "jugador.h"

static int eConfederacion_ObtenerID(void);
static int eConfederacion_ObtenerID(void) {
	static int Confederacion_idIncremental = 100;
	return Confederacion_idIncremental++;
}

int confederacion_ObtenerID(void)
{
	return eConfederacion_ObtenerID();
}

void eConfederacion_Inicializar(eConfederacion array[], int TAM)
{
	int i;
	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			array[i].isEmpty = LIBRE;
		}
	}
}

int eConfederacion_ObtenerIndexLibre(eConfederacion array[], int TAM)
{
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

int eConfederacion_BuscarPorID(eConfederacion array[], int TAM, int ID)
{
	int rtn = -1;
	int i;

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].idConfederacion == ID && array[i].isEmpty == OCUPADO) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eConfederacion_MostrarUno(eConfederacion confederacion)
{

	printf("\t|%6d ", confederacion.idConfederacion);
	printf("|  %10s ", confederacion.nombre);
	printf("|  %25s ", confederacion.region);
	printf("|  %12d |\n", confederacion.anioCreacion);
}

int eConfederacion_MostrarTodos(eConfederacion array[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	puts("\n\t> LISTADO Confederacion");
	puts("\t====================================================================");
	printf("\t|  %5s | %20s | %16s | %13s |\n", "ID", "Nombre", "Region", "Año Creación");
	puts("\t--------------------------------------------------------------------");
	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == OCUPADO) {
				eConfederacion_MostrarUno(array[i]);
				cantidad++;
			}
		}
	}
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eConfederacion_MostrarDadosDeBaja(eConfederacion array[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;
	puts("\t> Jugador\n");
	printf("\t|  %5s | %20s | %16s | %13s |\n", "ID", "Nombre", "Region", "Año Creación");

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == BAJA) {
				eConfederacion_MostrarUno(array[i]);
				cantidad++;
			}
		}
	}
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eConfederacion eConfederacion_CargarDatos(void)
{
	eConfederacion auxiliar;
	getString(auxiliar.nombre, 50, "\nIngrese nombre confederación\n>> ", "\nError!\n");
	getString(auxiliar.region, 50, "\nIngrese nombre de la región\n>> ", "\nError!\n");
	getInt(&auxiliar.anioCreacion, "\nIngrese año de creación\n>>", "\nError!\n", 1, 10000);

	return auxiliar;
}

int eConfederacion_Alta(eConfederacion array[], int TAM)
{
	int rtn = 0;
	eConfederacion auxConfederacion;
	int index = eConfederacion_ObtenerIndexLibre(array, TAM);

	if( index != -1 )
	{
		auxConfederacion = eConfederacion_CargarDatos();
		auxConfederacion.idConfederacion = eConfederacion_ObtenerID();
		auxConfederacion.isEmpty = OCUPADO;
		array[index] = auxConfederacion;
		rtn = 1;
	}
	return rtn;
}

int eConfederacion_Baja(eConfederacion array[],int TAM)
{
	int rtn;
	rtn = 0;
	int idConfederacion;
	int index;
	int flag;
	flag = 0;

	if(eConfederacion_MostrarTodos(array, TAM))
	{
		flag = 1;
	}
	if(flag)
	{

		getInt(&idConfederacion, "\nIngrese ID confederación a dar de baja\n>> ", "\nError!", 100, 105);

		while(eConfederacion_BuscarPorID(array, TAM, idConfederacion) == -1)
		{
			puts("No existe el ID");
			getInt(&idConfederacion, "\nRe-Ingrese ID confederación a dar de baja\n>> ", "\nError!", 100, 105);
		}
		index = eConfederacion_BuscarPorID(array, TAM, idConfederacion);
		array[index].isEmpty = BAJA;
		rtn = 1;
	}


	return rtn;
}

eConfederacion eConfederacion_ModificarNombre(eConfederacion confederacion)
{
	eConfederacion auxiliar;
	auxiliar = confederacion;
	getString(auxiliar.nombre, 50, "\nIngrese nuevo nombre\n>> ", "\nError!\n");

	return auxiliar;
}

eConfederacion eConfederacion_ModificarRegion(eConfederacion confederacion)
{
	eConfederacion auxiliar;
	auxiliar = confederacion;
	getString(auxiliar.region, 50, "\nIngrese nueva región\n>> ", "\nError!\n");

	return auxiliar;
}


eConfederacion eConfederacion_ModificarCreacion(eConfederacion confederacion)
{
	eConfederacion auxiliar;
	auxiliar = confederacion;
	getInt(&auxiliar.anioCreacion, "\nIngrese nuevo año de creación\n>> ", "\nError!\n", 1, 10000);

	return auxiliar;
}

int eConfederacion_Modificacion(eConfederacion array[], int TAM)
{
	int rtn = 0;
	int option;
	int idConfederacion;
	int index;
	int flag = 0;
	eConfederacion auxiliar;

	if(eConfederacion_MostrarTodos(array, TAM))
	{
		flag = 1;
	}
	if(flag)
	{
		getInt(&idConfederacion, "\nIngrese confederacion a Modificar\n>> ", "\nError!", 0, 1000);
		while(eConfederacion_BuscarPorID(array, TAM, idConfederacion) == -1)
		{
			puts("No existe el ID");
			getInt(&idConfederacion, "\nRe-ingrese confederacion a Modificar\n>> ", "\nError!", 0, 1000);

		}
		index = eConfederacion_BuscarPorID(array, TAM, idConfederacion);
		auxiliar = array[index];
		do
		{
			getInt(&option, "\nID confederacion a modificar"
												"\n1.Modificar Nombre"
												"\n2.Modificar Region"
												"\n3.Modificar Año de Creación \n", "\nERROR!", 0, 3000);
			switch(option)
							{
								case 1:
									printf("\nModificar Nombre \n");
									auxiliar = eConfederacion_ModificarNombre(auxiliar);
									break;
								case 2:
									printf("\nModificar Region \n");
									auxiliar = eConfederacion_ModificarRegion(auxiliar);
									break;
								case 3:
									printf("\nModificar Año de Creación \n");
									auxiliar = eConfederacion_ModificarCreacion(auxiliar);
									break;
								case 4:
									puts("\nvolviendo al menú...");
									break;
							}
		}while(option != 4);
		array[index] = auxiliar;
		rtn = 1;
	}

	return rtn;
}

eConfederacion eConfederacion_cargaPrueba(char nombre[], char region[], int anioCreacion)
{
	eConfederacion auxiliar;

	auxiliar.idConfederacion = eConfederacion_ObtenerID();
	strcpy(auxiliar.nombre,nombre);
	strcpy(auxiliar.region,region);
	auxiliar.anioCreacion = anioCreacion;
	auxiliar.isEmpty = OCUPADO;

	return auxiliar;

}

int eConfederacion_ValidarConfederacionesCargadas(eConfederacion array[], int TAM)
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
