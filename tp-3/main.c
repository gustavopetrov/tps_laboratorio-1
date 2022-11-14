#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "e-s.h"

int main()
{
	setbuf(stdout,NULL);
    int option;
    int opcionSalida;
    int saveFlag; // 1 hay que guardar cambios 0 no hay que guardar
    saveFlag = 0;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    LinkedList* listaJugadoresAux = ll_newLinkedList();
    LinkedList* listaSeleccionesAux = ll_newLinkedList();

    do{
    	getInt(&option, "\n1.CARGA DE ARCHIVOS"
    			"\n2.ALTA DE JUGADOR"
    			"\n3.MODIFICACIÓN DE JUGADOR"
    			"\n4.BAJA DE JUGADOR"
    			"\n5.LISTADOS:(menuPropio)"
    			"\n6.CONVOCAR JUGADORES(menuPropio)"
    			"\n7.ORDENAR Y LISTAR(menuPropio)"
    			"\n8.GENERAR ARCHIVO BINARIO:"
    			"\n9.CARGAR ARCHIVO BINARIO"
    			"\n10.GUARDAR ARCHIVOS .CSV"
    			"\n11.SALIR", "\nError!", 1, 11);

        switch(option)
        {
            case 1:
            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
            	controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones);
                break;
            case 2:
            	saveFlag = controller_agregarJugador(listaJugadores);
            	break;
            case 3:
            	controller_listarJugadores(listaJugadores);
            	if(controller_editarJugador(listaJugadores) == 0 )
            	{
            		saveFlag = 1;
            	}
            	break;
            case 4:
            	controller_listarJugadores(listaJugadores);
            	if(controller_removerJugador(listaJugadores) == 0)
            	{
            	saveFlag = 1;

            	}
            	break;
            case 5:
            	do{
            	getInt(&option, "\n1.Listar-Jugadores"
            			"\n2.Listar-Selecciones"
            			"\n3.Listar-Convocados"
            			"\n4.Salir", "\nERROR!", 1, 4);

            		switch(option)
					{
					case 1:
						controller_listarJugadoresCustom(listaJugadores, listaSelecciones);
						break;
					case 2:
						controller_listarSelecciones(listaSelecciones);
						break;
					case 3:
						controller_listarJugadoresConvocados(listaJugadores);
						break;
					case 4:
						break;
					}

            	}while(option!=4);

            	break;
            case 6:
            	do{

            		getInt(&option, "\n1.Convocar Jugador..."
            				"\n2.Quitar de la Seleccion..."
            				"\n3.Salir...", "\nERROR", 1, 3);
            		switch(option)
            		{
            		case 1:
            			if(controller_jugadoresConvocados(listaJugadores,listaSelecciones))
            			{
            				saveFlag = 1;
            			}
            			break;
            		case 2:
            			if(controller_desconvocarJugador(listaJugadores, listaSelecciones))
            			{
            				saveFlag = 1;
            			}
            			break;
            		case 3:
            			break;
            		}
            	}while(option !=3);

            	break;
            case 7:
            	do
            	{
            		getInt(&option, "\n1.Ordenar jugadores por nacionalidad"
            				"\n2.Ordenar selecciones por confederacion"
            				"\n3.Ordenar jugadores por Edad"
            				"\n4.Ordenar jugadores por nombre"
            				"\n5.Salir...", "\nError!", 1, 5);
            		switch(option)
            		{
            		case 1:
            			listaJugadoresAux = ll_clone(listaJugadores);
            			ll_sort(listaJugadoresAux, controller_ordenarJugadoresNacionalidad,1);
            			controller_listarJugadores(listaJugadoresAux);
            			ll_deleteLinkedList(listaJugadoresAux);
            			break;
            		case 2:
            			listaSeleccionesAux = ll_clone(listaSelecciones);
						ll_sort(listaSeleccionesAux, controller_ordenarSeleccionesConfederacion,1);
						controller_listarSelecciones(listaSeleccionesAux);
						ll_deleteLinkedList(listaSeleccionesAux);
            			break;
            		case 3:
            			listaJugadoresAux = ll_clone(listaJugadores);
						ll_sort(listaJugadoresAux, controller_ordenarJugadoresPorEdad,1);
						controller_listarJugadores(listaJugadoresAux);
						ll_deleteLinkedList(listaJugadoresAux);
            			break;
            		case 4:
            			listaJugadoresAux = ll_clone(listaJugadores);
						ll_sort(listaJugadoresAux,controller_ordenarJugadoresNombre,1);
						controller_listarJugadores(listaJugadoresAux);
						ll_deleteLinkedList(listaJugadoresAux);
            			break;
            		case 5:
            			break;
            		}
            	}while(option != 5);

            	break;
            case 8:
            	controller_guardarJugadoresModoBinario("jugadoresConvocados.bin",listaJugadores,listaSelecciones);
            	break;
            case 9:
            	controller_cargarJugadoresDesdeBinario("jugadoresConvocados.bin",listaJugadores);
            	break;
            case 10:
            	controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
            	controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones);
            	break;
            case 11:
            	if(saveFlag == 1)
            	{
            		do
            		    {
            		    printf("\nQuiere salir sin guardar?");
            		    getInt(&opcionSalida, "Tenes Cambios sin guardar, desea salir?"
										"\n 1.Guardar Cambios"
										"\n 2.Salir sin Guardar", "ERROR", 1, 2);

            		        switch(opcionSalida)
            		        {
            		            case 1: // guardar y salir
            		            	controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
            		            	controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones);
            		                printf("\nCambios guardados.");
            		            break;
            		            case 2: // salir sin guardar
            		            break;
            		        }
            		    }while(opcionSalida < 1 || opcionSalida >2 );
            	}
            	break;
        	}
    }while(option != 11);
    printf("\nGracias por su visita");
    return 0;
}
