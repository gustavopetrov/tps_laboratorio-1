#ifndef ALBUM
#define ALBUM

#define CANT_FIGURITAS 55
#define PACK 5

typedef struct {
	int idFigurita[CANT_FIGURITAS]; // Guardara los IDs que voy sacando en los Packs de 5 Figus
	int esDorada[CANT_FIGURITAS]; // Guardara los IDs que son DORADAS
	int estadoAlbum;
}sAlbum;


#endif /* ALBUM_H_ */
