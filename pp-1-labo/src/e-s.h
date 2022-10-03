#define OCUPADO	1
#define LIBRE 	0

typedef struct
{
	int idSeleccion; //PK
	char nombreEquipo[1024];
	int cantidadJugadores;
	int estado;
}eEquipos;

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int idFigurita; //PK
	char nombreJugador[1024];
	char posicionJugador[1024];
	int idSeleccion; //FK equipos
	float altura;
	float peso;
	int anioIngreso;
//	int esDorada;
	int estado;

	eFecha fechaNacimiento;
}eFigurita;

//
int opcionesMenuPrincipal();
void opcionesMenuAdministrador(eFigurita lista[],int size, eEquipos selecciones[], int sizeSelecciones);
void inicializarArray(eFigurita lista[], int size);
eFigurita altaFigurita();
void cargarVectorFiguritas(eFigurita lista[], int size);
void mostrarFigurita(eFigurita lista, eEquipos seleccionJugador[], int sizeSeleccion);
void mostrarVectorFiguritas(eFigurita lista[], int size, eEquipos seleccionJugador[], int sizeSeleccion);

/*---- MODIFICACIONES ---- */

int modificarFigurita(eFigurita lista[], int size);
void modificarFiguritaNombre(eFigurita lista[],int size, int id);
void modificarFiguritaPosicion(eFigurita lista[],int size,int id);
void modificarFiguritaEquipo(eFigurita lista[], int size,int id);
void modificarFiguritaAltura(eFigurita lista[],int size,int id);
void modificarFiguritaPesaje(eFigurita lista[], int size,int id);
void modificarFiguritaAnioIngresoSeleccion(eFigurita lista[],int size,int id);
void modificarFiguritaDiaNacimiento(eFigurita lista[], int size,int id);
void modificarFiguritaMesNacimiento(eFigurita lista[],int size,int id);
void modificarFiguritaAnioNacimiento(eFigurita lista[],int size,int id);

/*---- Ordenamiento ----*/
void mostrarFiguritasOrdenadasPorSeleccion(eEquipos listaSelecciones[],int sizeSelecciones, eFigurita lista[], int size);
void ordenarSelecciones(eEquipos listaSelecciones[], int sizeSelecciones);
