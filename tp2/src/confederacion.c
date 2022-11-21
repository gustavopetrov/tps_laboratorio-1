#include "confederacion.h"
#include "inputs.h"
#include "e-s.h"
#include "jugador.h"

static int eConfederacion_ObtenerID(void);
static int eConfederacion_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eConfederacion_ObtenerID();
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
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}

int eConfederacion_ObtenerIndexLibre(eConfederacion array[], int TAM)
{
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

int eConfederacion_BuscarPorID(eConfederacion array[], int TAM, int ID)
{
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idConfederacion == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eConfederacion_MostrarUno(eConfederacion confederacion)
{
	//PRINTF DE UN SOLO Confederacion
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

	//CABECERA
	puts("\n\t> LISTADO Confederacion");
	puts("\t====================================================================");
	printf("\t|  %5s | %20s | %16s | %13s |\n", "ID", "Nombre", "Region", "Año Creación");
	puts("\t--------------------------------------------------------------------");
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Jugador
				eConfederacion_MostrarUno(array[i]);
				//CONTADOR DE Jugador
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Jugador PARA MOSTRAR (ARRAY SIN ALTAS)
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

	//CABECERA
	puts("\t> Jugador\n");
//	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
	printf("\t|  %5s | %20s | %16s | %13s |\n", "ID", "Nombre", "Region", "Año Creación");

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Jugador
				eConfederacion_MostrarUno(array[i]);
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

eConfederacion eConfederacion_CargarDatos(void)
{
	/*acá no guardo ni ID ni estado, se hace en el alta */
	eConfederacion auxiliar;
	getString(auxiliar.nombre, 50, "\nIngrese nombre confederación...", "\nError!");
	getString(auxiliar.region, 50, "\nIngrese nombre de la región", "\nError!");
	getInt(&auxiliar.anioCreacion, "\nIngrese año de creación", "\nError!", 1, 10000);

	return auxiliar;
}

int eConfederacion_Alta(eConfederacion array[], int TAM)
{
	int rtn = 0;
	eConfederacion auxConfederacion;
	int index = eConfederacion_ObtenerIndexLibre(array, TAM);
	//index == -1 array lleno
	// index != -1 obtengo el indice en pos libre del array

	if( index != -1 )
	{
		// PIDO DATOS - Cargo confederación auxiliar
		auxConfederacion = eConfederacion_CargarDatos();
		//Setteo el ID unico
		auxConfederacion.idConfederacion = eConfederacion_ObtenerID();
		//Cambio su estado a ocupado
		auxConfederacion.isEmpty = OCUPADO;
		//Seteo el array con auxiliar en index libre obtenido previamente
		array[index] = auxConfederacion;
		//Retorno 1 para saber que fue dado de alta satisfactoriamente
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

	//Listar Confederaciones
	if(eConfederacion_MostrarTodos(array, TAM))
	{
		//Bandera en 1 si hay confederaciones dados de alta para listar
		flag = 1;
	}
	if(flag)
	{
		//Pido ID a dar de baja
		getInt(&idConfederacion, "\nIngrese ID confederación a dar de baja", "\nError!", 0, 100);
		//Busco el INDEX por ID en el array
		while(eConfederacion_BuscarPorID(array, TAM, idConfederacion) == -1)
		{
			puts("No existe el ID");
			getInt(&idConfederacion, "\nRe-Ingrese ID confederación a dar de baja", "\nError!", 0, 100);
		}
		//Obtener index del array de confederacion a dar de baja
		index = eConfederacion_BuscarPorID(array, TAM, idConfederacion);
		//Se realizo la baja y se cambio el estado a "BAJA"
		array[index].isEmpty = BAJA;

		//Retorno 1 si se dio correctamente la baja
		rtn = 1;
	}


	return rtn;
}

eConfederacion eConfederacion_ModificarNombre(eConfederacion confederacion)
{
	eConfederacion auxiliar;
	auxiliar = confederacion;
	// Modifico el nombre
	getString(auxiliar.nombre, 50, "\nIngrese nuevo nombre... ", "\nError! ");

	return auxiliar;
}

eConfederacion eConfederacion_ModificarRegion(eConfederacion confederacion)
{
	eConfederacion auxiliar;
	auxiliar = confederacion;
	getString(auxiliar.region, 50, "\nIngrese nueva región... ", "\nError !");

	return auxiliar;
}


eConfederacion eConfederacion_ModificarCreacion(eConfederacion confederacion)
{
	eConfederacion auxiliar;
	auxiliar = confederacion;
	getInt(&auxiliar.anioCreacion, "\nIngrese nuevo año de creación...", "\nError!", 1, 10000);

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

	//Listar todas las confederaciones
	if(eConfederacion_MostrarTodos(array, TAM))
	{
		//Bandera en 1 si hay confederaciones en alta para mostrar
		flag = 1;
	}
	//Si hay confederaciones para MODIFICAR
	if(flag)
	{
		getInt(&idConfederacion, "\nIngrese confederacion a Modificar", "\nError!", 0, 1000);
		//Busco el indice por id en array
		while(eConfederacion_BuscarPorID(array, TAM, idConfederacion) == -1)
		{
			puts("No existe el ID");
			getInt(&idConfederacion, "\nRe-ingrese confederacion a Modificar", "\nError!", 0, 1000);

		}
		//Obtengo el indice del array de confederaciones a modificar en función del ID
		index = eConfederacion_BuscarPorID(array, TAM, idConfederacion);
		do
		{
			getInt(&option, "\nID confederacion a modificar"
												"\n1.Modificar Nombre"
												"\n2.Modificar Region"
												"\n3.Modificar Año de Creación \n", "\nERROR!", 0, 3000);
			switch(option)
							{
								case 1:
									printf("\nModificar Nombre: \n");
									auxiliar = eConfederacion_ModificarNombre(array[index]);
									break;
								case 2:
									printf("\nModificar Region: \n");
									auxiliar = eConfederacion_ModificarRegion(array[index]);
									break;
								case 3:
									printf("\nModificar Año de Creación: \n");
									auxiliar = eConfederacion_ModificarCreacion(array[index]);
									break;
								case 4:
									puts("\nvolviendo al menú...");
									break;
							}
		}while(option != 4);
		//Modificacion aceptada, agrego el elemento AUXILIAR en el índice del array
		array[index] = auxiliar;
		//Retorno 1 si se modifico correctamente
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
