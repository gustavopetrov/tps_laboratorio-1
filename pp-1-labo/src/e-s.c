#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "e-s.h"
#include "utilidades.h"
#include "procesos.h"
#include "perfilColeccionista.h"
//
int opcionesMenuPrincipal()
{
	int opcionMenuPrincipal;
	printf("\n\t **Bienvenido**"
			"\n1.Perfil de Administrador"
			"\n2.Perfil de Coleccionista"
			"\n3.Salir");
	scanf("%d",&opcionMenuPrincipal);

	return opcionMenuPrincipal;
}
void opcionesMenuAdministrador(eFigurita lista[],int size, eEquipos selecciones[], int sizeSelecciones)
{
	int opcionMenuAdministrador;
	int opcionModificacion;
	int id;
//	opcionMenuAdministrador = validarInt("\n1.Alta Figurita\n"
//			"2.Modificar Figuritas\n"
//			"3.Listar Figuritas\n", "Error! opción inválida.", 1, 4);
	getInt(&opcionMenuAdministrador, "\n1.Alta Figurita\n"
			"2.Modificar Figuritas\n"
			"3.Listar Figuritas\n"
			"4.Ordenar Alfabeticamente (por seleccion)\n"
			"5.Salir...\n", "Error! opción inválida.", 1, 5);


	switch(opcionMenuAdministrador)
	{
	case 1:
		printf("Cargar una figurita...\n");
		cargarVectorFiguritas(lista, size);
			break;
	case 2:
		id = modificarFigurita(lista, size);
		do
		{

		opcionModificacion = validarInt("Modificar figurita: \n"
				"1.Nombre del Jugador: \n"
				"2.Posicion del Jugador: \n"
				"3.Equipo del Jugador: \n"
				"4.Altura del Jugador: \n"
				"5.Pesaje del Jugador: \n"
				"6.Año de Ingreso: \n"
				"7.Fecha de nacimiento - DIA: \n"
				"8.Fecha de nacimiento - MES \n"
				"9.Fecha de nacimiento - AÑO\n "
				"10.Volver atrás", "Ingrese un valor válido...", 1, 10);

		switch(opcionModificacion)
		{

		case 1:
			if(id != -1)
			{
				printf("Opcion:\n \tModificar nombre del Jugador...\n");
				modificarFiguritaNombre(lista, size, id);
			}
			break;
		case 2:
			if(id != -1)
			{
				printf("Opcion:\n \tModificar Posición del Jugador...\n");
				modificarFiguritaPosicion(lista, size, id);
			}
			break;
		case 3:
			if(id != -1)
			{
				modificarFiguritaEquipo(lista, size, id);
				printf("Opcion:\n \tModificar Equipo del Jugador...\n");
			}
			break;
		case 4:
			if(id != -1)
			{
				modificarFiguritaAltura(lista, size, id);
				printf("Opcion:\n \tModificar Altura del Jugador...\n");
			}
			break;
		case 5:
			if(id != -1)
			{
				modificarFiguritaPesaje(lista, size, id);
				printf("Opcion:\n \tModificar Pesaje del Jugador...\n");
			}
			break;
		case 6:
			if(id != -1)
			{
				modificarFiguritaAnioIngresoSeleccion(lista, size, id);
				printf("Opcion:\n \tModificar Año de Ingreso del Jugador...\n");
			}
			break;
		case 7:
			if(id != -1)
			{
				modificarFiguritaDiaNacimiento(lista, size, id);
				printf("Opcion:\n \tModificar FECHA: *Día de nacimiento del Jugador...\n");
			}
			break;
		case 8:
			if(id != -1)
			{
				modificarFiguritaMesNacimiento(lista, size, id);
				printf("Opcion:\n \tModificar FECHA: *Mes de nacimiento del Jugador...\n");
			}
			break;
		case 9:
			if(id != -1)
			{
				modificarFiguritaAnioNacimiento(lista, size, id);
				printf("Opcion:\n \tModificar FECHA: *Año de nacimiento del Jugador...\n");
			}
			break;
		case 10:
			printf("\nVolviendo al meno principal...\n");
			break;
		}
		} while(opcionModificacion != 10);
			break;
	case 3:
		printf("listar figuritas");
		mostrarVectorFiguritas(lista, size, selecciones,sizeSelecciones );
			break;
	case 4:
		printf("ordenar por nombre selección");
		mostrarFiguritasOrdenadasPorSeleccion(selecciones, sizeSelecciones, lista, size);
		ordenarSelecciones(selecciones,sizeSelecciones);
			break;
	case 5:
		printf("Salir");
		break;

	}
}







void inicializarArray(eFigurita lista[], int size)
{
	for(int i = 0; i<size;i++)
	{
		lista[i].estado = LIBRE;
	}
}
void ordenarSelecciones(eEquipos listaSelecciones[], int sizeSelecciones) {
    eEquipos aux;
    for(int i = 0; i < sizeSelecciones-1; i++) {
        for(int j = i+1; j < sizeSelecciones; j++) {
            if(strcmp(listaSelecciones[i].nombreEquipo, listaSelecciones[j].nombreEquipo) > 0) {
                aux = listaSelecciones[i];
                listaSelecciones[i] = listaSelecciones[j];
                listaSelecciones[j] = aux;
            }
        }
    }
}
void mostrarFiguritasOrdenadasPorSeleccion(eEquipos listaSelecciones[],int sizeSelecciones, eFigurita lista[], int size)
{
	ordenarSelecciones(listaSelecciones, sizeSelecciones);
	for(int i = 0; i < sizeSelecciones; i++)
	{
		for(int j = 0; j<size;j++)
		{
			if(listaSelecciones[i].idSeleccion == lista[j].idSeleccion)
			{
				mostrarFigurita(lista[j], listaSelecciones, sizeSelecciones);
			}
		}

	}
}

eFigurita altaFigurita()
{
	eFigurita nuevaFigurita;
	pedirString("Ingrese nombre jugador ", nuevaFigurita.nombreJugador);
	pedirString("Ingrese posición:\n"
			"*Delantero \n"
			"*MedioCampista \n"
			"*Defensor \n"
			"*Arquero \n ", nuevaFigurita.posicionJugador);
	nuevaFigurita.idSeleccion = validarInt("\nIngrese Equipo:\n"
				"1.Argentina\n"
				"2.Brasil\n"
				"3.Inglaterra\n"
				"4.Uruguay\n"
				"5.Alemania", "Error, opción inválida", 1, 5);
	nuevaFigurita.altura = validarFloat("Ingrese altura (1.5 a 2.1) \n", "Altura no válida (1.5 a 2.1) \n", 1.5, 2.1);
	nuevaFigurita.peso = validarFloat("Ingrese pesaje de jugador (50 a 100) \n", "Pesaje no válido (50 a 100) \n", 50, 100);
	nuevaFigurita.anioIngreso = validarInt("Ingrese año ingreso selección ( 2005 a 2022 ) \n", "Año incorrecto ( 2005 a 2022 ) \n", 2005, 2022);
	nuevaFigurita.fechaNacimiento.dia = validarInt("Ingrese día de nacimiento \n", "Error, día inválido \n", 1, 31);
	nuevaFigurita.fechaNacimiento.mes = validarInt("Ingrese mes de nacimiento \n", "Error, mes inválido \n", 1, 12);
	nuevaFigurita.fechaNacimiento.anio = validarInt("Ingrese año de nacimiento \n", "Año inválido \n", 1987, 2003);
	nuevaFigurita.estado = OCUPADO;
	// es dorada?

	return nuevaFigurita;
}
void cargarVectorFiguritas(eFigurita lista[], int size)
{
	char respuesta;
	respuesta = 's';
	for(int i = 0; i<size; i++)
	{
		if(respuesta == 's')
		{
			lista[i]= altaFigurita();
			lista[i].idFigurita = lista[i-1].idFigurita+1;
		}else{
			printf("volviendo al menú principal...");
			break;
		}
		respuesta = pedirChar("Desea continuar? s/n");
	}
}

void buscarSeleccion(eFigurita jugador, int size, eEquipos selecciones[], int sizeSeleccion, char seleccion[])
{
	for(int i = 0; i<sizeSeleccion;i++)
	{
		if(jugador.idSeleccion == selecciones[i].idSeleccion)
		{
			strncpy(seleccion,selecciones[i].nombreEquipo,1024);
		}
	}
}

void mostrarFigurita(eFigurita lista, eEquipos seleccionJugador[], int sizeSeleccion)
{
	char seleccion[1024];
	if(lista.estado == OCUPADO)
	{
		buscarSeleccion(lista, sizeSeleccion, seleccionJugador, sizeSeleccion, seleccion);
		printf("\nNombre jugador: %s",lista.nombreJugador);
		printf("\nPosición jugador: %s",lista.posicionJugador);
		printf("\nEquipo del jugador: %s",seleccion);
		printf("\nAltura del jugador: %.2f",lista.altura);
		printf("\nPesaje del jugador: %.2f",lista.peso);
		printf("\nAño de ingreso del jugador: %d",lista.anioIngreso);
		printf("\nFecha de nacimiento del jugador: %d/%d/%d",lista.fechaNacimiento.dia,lista.fechaNacimiento.mes,lista.fechaNacimiento.anio);
		printf("\n\n\t *ID: %d*\n",lista.idFigurita);
		printf("\n------------------------------------------------\n");
	}

}

void mostrarVectorFiguritas(eFigurita lista[], int size,eEquipos selecciones[],int sizeSeleccion)
{
	for(int i = 0; i<size; i++)
	{
		mostrarFigurita(lista[i], selecciones, sizeSeleccion);

	}
}
// si es posible modificar o no (si existe)
int modificarFigurita(eFigurita lista[], int size)
{
	int retorno;
	int id;
	id = validarInt("\nIngrese un id entre 1 y 55\n", "Error! ingrese una ID válida...\n", 1, 55);
	retorno = -1;

	for(int i = 0; i<size; i++)
	{
		if(lista[i].idFigurita == id)
		{
			retorno = id-1;
			break;
		}
	}
	printf("Ingresaste el valor: %d\n\n",id);
	return retorno;
}

void modificarFiguritaNombre(eFigurita lista[],int size, int id)
{
		pedirString("\nIngrese nuevo nombre...\n", lista[id].nombreJugador);
}

void modificarFiguritaPosicion(eFigurita lista[],int size,int id)
{
		pedirString("\nIngrese nueva posición...\n"
				"*Delantero\n"
				"*MedioCampista\n"
				"*Defensor\n"
				"*Arquero\n ",lista[id].posicionJugador);
}

void modificarFiguritaEquipo(eFigurita lista[], int size,int id)
{
	lista[id].idSeleccion = validarInt("\nIngrese Equipo:\n"
			"1.Argentina\n"
			"2.Brasil\n"
			"3.Inglaterra\n"
			"4.Uruguay"
			"5.Alemania", "Error, opción inválida", 1, 5);
}

void modificarFiguritaAltura(eFigurita lista[],int size,int id)
{
	lista[id].altura = validarFloat("Ingrese nueva altura(1.5 a 2.1)\n", "Valor incorrecto(1.5 a 2.1)\n", 1.5, 2.1);
}

void modificarFiguritaPesaje(eFigurita lista[], int size,int id)
{
	lista[id].peso = validarFloat("Ingrese pesaje del jugador (50 a 100)\n", "Error, ingrese un valor válido(50 a 100)\n", 50, 100);
}

void modificarFiguritaAnioIngresoSeleccion(eFigurita lista[],int size,int id)
{
	lista[id].anioIngreso = validarInt("Ingrese año de ingreso a la selección...( 2005 a 2022 )\n","Error! Ingrese un valor válido...( 2005 a 2022 )\n", 2005, 2022);
}

void modificarFiguritaDiaNacimiento(eFigurita lista[], int size,int id)
{
	lista[id].fechaNacimiento.dia = validarInt("Ingrese día de nacimiento \n", "Error, día inválido \n", 1, 31);
}
void modificarFiguritaMesNacimiento(eFigurita lista[],int size,int id)
{
	lista[id].fechaNacimiento.mes = validarInt("Ingrese mes de nacimiento \n", "Error, mes inválido \n", 1, 12);
}

void modificarFiguritaAnioNacimiento(eFigurita lista[],int size,int id)
{
	lista[id].fechaNacimiento.anio = validarInt("Ingrese año de nacimiento \n", "Año inválido \n", 1987, 2003);
}

/*
 * char auxNombre[1024]
 * int rtn = strlen(auxNombre)
 * if(rtn < tam_nombre){
 * 	strncpy(miAlumno.nombre,auxnombre,rnt)
 * }else{ volver a pedir }
 * */
/*-----------buscar selección por id y mostrar el nombre en lugar del id-----------*/













