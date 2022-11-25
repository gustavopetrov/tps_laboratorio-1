/*
 * setter
 * int jug_setId(Jugador* this,int id);
 * int jug_getId(Jugador* this,int* id);
 * getters
 * */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inputs.h"
#include "e-s.h"
#include "jugador.h"
/*-------------------------------getters y setters-------------------------------*/
/**
 * @brief Funcion que permite generar ID autoincremental, lo escribe en un csv para que persista en memoria
 *
 * @return
 */
int obtenerID()
{
	int id;
	id = 370;
	FILE * pArchivo;

	pArchivo = fopen("listadoID.bin","rb");
	fread(&id,sizeof(int),1,pArchivo);
	id++;
	fclose(pArchivo);

	pArchivo = fopen("listadoID.bin","wb");
	fwrite(&id,sizeof(int),1,pArchivo);
	fclose(pArchivo);

	return id;
}
/**
 * @brief set para lectura desde el txt
 *
 * @param this
 * @param id
 * @return
 */
int jug_setId(Jugador* this,int id)
{
	int retorno;
	retorno = 0;

	if(this != NULL && id > 0)
	{
		retorno = 1;
		this->id = id;
	}

	return retorno;
}
/**
 * @brief obtengo el id
 *
 * @param this
 * @param id
 * @return
 */
int jug_getId(Jugador* this,int* id)
{
	int retorno;
	retorno = 0;

	if(this != NULL && id > 0)
	{
		retorno = 1;
		*id = this->id;
	}

	return retorno;
}
/**
 * @brief Settea el nombre
 *
 * @param this => hace referencia a la entidad Jugador
 * @param nombreCompleto => char string con el nombre del jugador
 * @return
 */
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno;
	retorno = 0;

	if( this != NULL && nombreCompleto != NULL)
	{
		if(isValidNombre(nombreCompleto, NOMBRE_LEN))
		{
		strncpy(this->nombreCompleto,nombreCompleto,NOMBRE_LEN);
		retorno = 1;
		}
	}
	return retorno;
}
/**
 * @brief obtengo el nombre del jugador
 *
 * @param this => hace referencia a la entidad Jugador
 * @param nombreCompleto => char* con el nombre del jugador
 * @return
 */
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno;
	retorno = 0;

	if( this != NULL  && nombreCompleto != NULL)
	{
		retorno = 1;
		strncpy(nombreCompleto,this->nombreCompleto,NOMBRE_LEN);
	}

	return retorno;
}

/**
 * @brief setter para la posición del jugador
 *
 * @param this => hace referencia a la entidad Jugador
 * @param posicion => char con la posicion del jugador
 * @return
 */
int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno;
	retorno = 0;
	if(this != NULL && posicion != NULL)
	{
		if(isValidNombre(posicion, 30))
		{
			retorno = 1;
			strncpy(this->posicion,posicion,30);
		}
	}

	return retorno;
}
/**
 * @brief getter para mostrar la posición del jugador
 *
 * @param this => hace referencia a la entidad Jugador
 * @param posicion => char con la posicion del jugador
 * @return
 */
int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno;
	retorno = 0;
	if(this != NULL && posicion != NULL)
	{
		retorno = 1;
		strncpy(posicion,this->posicion,30);
	}

	return retorno;
}

/**
 * @brief settea la nacionalidad
 *
 * @param this
 * @param nacionalidad
 * @return
 */
int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno;
	retorno = 0;
	if(this != NULL && nacionalidad != NULL)
	{
		if(isValidNombre(nacionalidad, 30))
		{
			retorno = 1;
			strncpy(this->nacionalidad,nacionalidad,30);
		}
	}
	return retorno;
}
/**
 * @brief obtengo la nacionalidad
 *
 * @param this
 * @param nacionalidad
 * @return
 */
int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno;
	retorno = 0;
	if(this != NULL && nacionalidad != NULL)
	{
		retorno = 1;
		strncpy(nacionalidad,this->nacionalidad,30);
	}

	return retorno;
}
/**
 * @brief seteo la edad del jugador
 *
 * @param this
 * @param edad
 * @return
 */
int jug_setEdad(Jugador* this,int edad)
{
	int retorno;
	retorno = 0;
	if(this != NULL && edad >=18)
	{
		retorno = 1;
		this->edad = edad;
	}

	return retorno;
}
/**
 * @brief obtengo la edad del jugador
 *
 * @param this
 * @param edad
 * @return
 */
int jug_getEdad(Jugador* this,int* edad)
{
	int retorno;
	retorno = 0;
	if(this != NULL && edad != NULL)
		{
			retorno = 1;
			*edad = this->edad;
		}
	return retorno;
}
/**
 * @brief seteo el id de seleccion
 *
 * @param this
 * @param idSeleccion
 * @return
 */
int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno;
	retorno = 0;

	if( this != NULL && idSeleccion >= 0)
	{
		retorno = 1;
		this->idSeleccion = idSeleccion;
	}

	return retorno;
}
/**
 * @brief obtengo con un getter le id de seleccion del jugador
 *
 * @param this
 * @param idSeleccion
 * @return
 */
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno;
	retorno = 0;

	if( this != NULL && idSeleccion >= 0)
	{
		retorno = 1;
		*idSeleccion = this->idSeleccion;
	}

	return retorno;
}
/*-------------------------------abm-------------------------------*/
/**
 * @brief reservo espacio en memoria dinamica para la estructura jugador y lo retorno
 *
 * @return
 */
Jugador* jug_new()
{
	Jugador* unJugador;

	unJugador = (Jugador*)malloc(sizeof(Jugador));

	return unJugador;
}
/**
 * @brief Constructor para crear un jugador nuevo recibe parámetros de tipo string que son parseados
 *
 * @param idStr
 * @param nombreCompletoStr
 * @param edadStr
 * @param posicionStr
 * @param nacionalidadStr
 * @param idSeleccionStr
 * @return
 */
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr)
{
	Jugador* unJugador;
	unJugador = jug_new();
	if( idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSeleccionStr != NULL)
	{
		jug_setId(unJugador, atoi(idStr));
		jug_setNombreCompleto(unJugador, nombreCompletoStr);
		jug_setEdad(unJugador, atoi(edadStr));
		jug_setPosicion(unJugador, posicionStr);
		jug_setNacionalidad(unJugador, nacionalidadStr);
		jug_setIdSeleccion(unJugador, atoi(idSeleccionStr));
	}
	// encadenar if con las funciones y settear el pntero en null => video 18 min 18:23
	return unJugador;
}
/**
 * @brief elimina el jugador liberando espacio en memoria dinámica
 *
 * @param this
 */
void jug_delete(Jugador* this)
{
	if(this != NULL)
	{
	free(this);
	}
}
/*---------- Modificacaciones----------*/
/**
 * @brief El usuario ingresa un ID, lo busco en el linkedlist y devuelvo la posicion/indice de ese jugador
 *
 * @param pArrayListJugador -> linkedlist
 * @return => retorno el índice del jugador
 */
int buscarIDLinkedList(LinkedList* pArrayListJugador)
{

	int id;
	int idAux;
	int retorno;
	getInt(&id, "\nIngrese el ID del jugador", "\nError!", 1, 999);
	int cant;
	Jugador* auxiliar;
	cant = ll_len(pArrayListJugador);
	for(int i = 0; i < cant ; i++)
	{
		auxiliar = (Jugador*)ll_get(pArrayListJugador,i);
		jug_getId(auxiliar, &idAux);
		if(id == idAux)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}
/**
 * @brief modifica el nombre del jugador
 *
 * @param pArrayListJugador
 * @param i
 * @return
 */
int modificarNombre(LinkedList* pArrayListJugador, int i)
{
	int rta;
	Jugador* jugadorAux;
	char nombreAux[NOMBRE_LEN];
	// ll_get devuelve un jugador en la posición i
	jugadorAux = (Jugador*)ll_get(pArrayListJugador, i);
	getString(nombreAux, NOMBRE_LEN, "\nIngrese Nombre Completo", "\nERROR!");
	jug_setNombreCompleto(jugadorAux, nombreAux);
	rta = ll_set(pArrayListJugador, i, jugadorAux);
	return rta;
}
/**
 * @brief modifica la edad del jugador
 *
 * @param pArrayListJugador
 * @param i
 * @return
 */
int modificarEdad(LinkedList* pArrayListJugador, int i)
{
	int rta;
	Jugador* jugadorAux;
	int edadAux;
	jugadorAux = (Jugador*)ll_get(pArrayListJugador, i);
	getInt(&edadAux, "\nIngrese Edad","\nError!", 18, 50);
	jug_setEdad(jugadorAux, edadAux);
	rta = ll_set(pArrayListJugador, i, jugadorAux);
	return rta;
}
/**
 * @brief modifica la posicion del jugador
 *
 * @param pArrayListJugador
 * @param i
 * @return
 */
int modificarPosicion(LinkedList* pArrayListJugador, int i)
{
	int rta;
	Jugador* jugadorAux;
	char posicionAux[100];
	jugadorAux = (Jugador*)ll_get(pArrayListJugador, i);
	getString(posicionAux, 100, "\nIngrese Posicion: "
					"\nPortero - Defensa Central - Lateral Izquierdo - Lateral Derecho - Pivote \nMedio Centro - Extremo Izquierdo - Extremo Derecho - Media Punta - Delantero Central\n", "\nERROR!");
	while(stricmp(posicionAux,"Portero") && stricmp(posicionAux,"Defensa Central") && stricmp(posicionAux,"Lateral Izquierdo") && stricmp(posicionAux,"Lateral Derecho") && stricmp(posicionAux,"Pivote") && stricmp(posicionAux,"Medio Centro") && stricmp(posicionAux,"Extremo Izquierdo") && stricmp(posicionAux,"Extremo Derecho") && stricmp(posicionAux,"Media Punta") && stricmp(posicionAux,"Delantero Central") )
	{
		getString(posicionAux, 100, "\nIngrese Posicion: "
						"\nPortero - Defensa Central - Lateral Izquierdo - Lateral Derecho - Pivote \nMedio Centro - Extremo Izquierdo - Extremo Derecho - Media Punta - Delantero Central\n", "\nERROR!");
	}
	jug_setPosicion(jugadorAux, posicionAux);
	rta =ll_set(pArrayListJugador, i, jugadorAux);
	return rta;

}
/**
 * @brief modifica la nacionalidad
 *
 * @param pArrayListJugador
 * @param i
 * @return
 */
int modificarNacionalidad(LinkedList* pArrayListJugador, int i)
{
	int rta;
	Jugador* jugadorAux;
	char nacionalidadAux[100];
	jugadorAux = (Jugador*)ll_get(pArrayListJugador, i);
	getString(nacionalidadAux, 100, "\nIngrese Posicion: "
								"\nArgentino - Brasilero - Uruguayo - Portugués - Inglés - Alemán - Mexicano - Estadounidense - Cameunes - Senegales - Australiano - Qatarí \n", "\nERROR!");
	while(stricmp(nacionalidadAux,"Argentino") && stricmp(nacionalidadAux,"Brasilero") && stricmp(nacionalidadAux,"Uruguayo") && stricmp(nacionalidadAux,"Inglés") && stricmp(nacionalidadAux,"Alemán") && stricmp(nacionalidadAux,"Mexicano") && stricmp(nacionalidadAux,"Estadounidense") && stricmp(nacionalidadAux,"Cameunes") && stricmp(nacionalidadAux,"Senegales") && stricmp(nacionalidadAux,"Australiano") && stricmp(nacionalidadAux,"Qatari") )
	{
		getString(nacionalidadAux, 100, "\nIngrese Posicion: "
						"\nArgentino - Brasilero - Uruguayo - Portugués - Inglés - Alemán - Mexicano - Estadounidense - Cameunes - Senegales - Australiano - Qatarí \n", "\nERROR!");
	}
	jug_setNacionalidad(jugadorAux, nacionalidadAux);
	rta = ll_set(pArrayListJugador, i, jugadorAux);
	return rta;
}
/**
 * @brief Modifica el ID de la seleccion
 *
 * @param jugadorAux
 * @param idSeleccionAux
 * @return
 */
int modificarIdSeleccion(Jugador* jugadorAux, int idSeleccionAux)
{
	int rta;
	rta =jug_setIdSeleccion(jugadorAux, idSeleccionAux);
	return rta;
}
/**
 * @brief display del menu de modificacion
 *
 * @param pArrayListJugador
 * @param i
 * @return
 */
int menuModificacionJugadores(LinkedList* pArrayListJugador, int i)
{
	// Ya encontre el ID
	int option;
	int rta;

	getInt(&option, "\n1.Modificar Nombre"
			"\n2.Modificar Edad"
			"\n3.Modificar Posicion"
			"\n4.Modificar Nacionalidad", "Error!", 1, 4);
	switch(option)
	{
	case 1:

		printf("\nEntraste a modificar nombre");
		rta = modificarNombre(pArrayListJugador, i);
		break;
	case 2:
		printf("\nEntraste a modificar edad");
		rta = modificarEdad(pArrayListJugador,i);
		break;
	case 3:
		printf("\nEntraste a modificar posicion");
		rta = modificarPosicion(pArrayListJugador,i);
		break;
	case 4:
		printf("\nEntraste a modificar nacionalidad");
		rta = modificarNacionalidad(pArrayListJugador, i);
		break;
	}
	return rta;
}
/**
 * @brief recibe el índice al jugador que se desea eliminar y libera espacio en memoria
 *
 * @param pArrayListJugador
 * @param i
 * @return
 */
int menuRemoverJugador(LinkedList* pArrayListJugador, int i)
{
	int rta;
	Jugador* jugadorAux;
	jugadorAux = (Jugador*)ll_get(pArrayListJugador, i);
	rta = ll_remove(pArrayListJugador, i);
	free(jugadorAux);
	return rta;
}

					/*----------6.A----------*/
/**
 * @brief muestra un jugador que , si está convocado , retornara un estado
 *
 * @param unJugador
 * @return
 */
int mostrarUnJugador(Jugador* unJugador)
{
	int retorno;
	retorno = 0;
	char nombreAux[NOMBRE_LEN];
	char posAux[100];
	char nacionalidadAux[100];
	int idSeleccionaAux;

	jug_getNombreCompleto(unJugador, nombreAux);
	jug_getPosicion(unJugador, posAux);
	jug_getNacionalidad(unJugador, nacionalidadAux);
	jug_getSIdSeleccion(unJugador, &idSeleccionaAux);
	printf("\n | Jugador: %-25s | Posicion: %-25s | Nacionalidad: %-10s",nombreAux,posAux,nacionalidadAux);

	if(idSeleccionaAux == 0)
		{
			retorno = 1;

		}else{
			printf("\nError el jugador ya fue convocado.");
		}
	return retorno;
}
/**
 * @brief muestra jugadores que cargo en binario
 *
 * @param unJugador
 */
void mostrarJugadorBinario(Jugador* unJugador)
{
	int idAux;
	char nombreAux[NOMBRE_LEN];
	char posAux[100];
	char nacionalidadAux[100];

	jug_getId(unJugador, &idAux);
	jug_getNombreCompleto(unJugador, nombreAux);
	jug_getPosicion(unJugador, posAux);
	jug_getNacionalidad(unJugador, nacionalidadAux);
	printf("\n|ID: %-2d | Jugador: %-25s | Posicion: %-25s | Nacionalidad: %-10s",idAux,nombreAux,posAux,nacionalidadAux);
}
/**
 * @brief pido al usuario que ingrese una opción que utilizo para identificar la confederacion
 *
 * @param pArrayListJugador
 * @return
 */
int idConfederacion(LinkedList* pArrayListJugador)
{
	int option;
	getInt(&option, "\nIngresar confederacion: "
			"\n1.AFC "
			"\n2.CAF "
			"\n3.CONCACAF "
			"\n4.CONMEBOL "
			"\n5.UEFA ", "\nError!", 1, 5);
	return option;
}
