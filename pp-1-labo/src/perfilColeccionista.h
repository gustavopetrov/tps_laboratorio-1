typedef struct
{
	int idFigurita[55];
	int esDorada[55];
	int estado;
}eAlbum;

typedef struct
{
	int idFigurita;
	int repetidas;

}eRepetidas;

void opcionesMenuColeccionista(eFigurita lista[],int size, eAlbum album, int sobreFiguritas[], int sizeSobreFiguritas, eRepetidas listaRepetidas[], int sizeRepetidas, eEquipos listaSelecciones[], int sizeSelecciones);
void generar5IDSRandom(int sobreFiguritas[],int size);
void generar5FiguritasRandom(int sobreFiguritas[],int size, eFigurita lista[],int sizeJugadores,eEquipos listaSelecciones[], int sizeSelecciones);
void comprarSobreFiguritas(int sobreFiguritas[],int size, eFigurita lista[],int sizeJugadores,eEquipos listaSelecciones[], int sizeSelecciones);
void inicializarAlbumVacio(eAlbum album, int sizeAlbum);
void inicializarMazoRepetidas(eFigurita lista[], int size, eRepetidas listaRepetidas[], int sizeRepetidas);
void agregarFiguritaAlMazoRepetidas(int sobreFiguritas[],int size, eFigurita lista[],int sizeJugadores, eRepetidas listaRepetidas[], int sizeRepetidas);
void pegarFigurita(eFigurita lista[], int sizeJugadores,eAlbum album,int sobreFiguritas[],int size,eRepetidas listaRepetidas[], int sizeRepetidas,eEquipos listaSelecciones[], int sizeSelecciones);

