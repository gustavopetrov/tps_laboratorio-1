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
    int criterioOrdenamiento;
    int opcionSalida;
    int validacionMenu;
    int saveFlag; // 1 hay que guardar cambios 0 no hay que guardar
    saveFlag = 0;
    validacionMenu = 0;
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
            	// ll_isEmpty(LinkedList* this) 1 si esta vacía, 0 si NO esta vacía
            	if( ( ll_isEmpty(listaJugadores) && ll_isEmpty(listaSelecciones) ) == 1)
            	{
            		validacionMenu = 1;
					controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
					controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones);
            	}else
            	{
            		puts("\nYa se cargaron los archivos...");
            	}

                break;
            case 2:
            	if(validacionMenu == 1)
            	{
            		saveFlag = controller_agregarJugador(listaJugadores);
            		puts(" * Jugador DADO DE ALTA EXITOSAMENTE");
            		system("pause");
            	}else
            	{
            		puts("\nError, no se cargaron los archivos!");
            	}
            	break;
            case 3:
            	if(validacionMenu == 1)
            	{
					controller_listarJugadores(listaJugadores);
					if(controller_editarJugador(listaJugadores) == 0 )
					{
						saveFlag = 1;
						puts(" * Jugador EDITADO EXITOSAMENTE");
						system("pause");
					}
            	}
            	else{
            		puts("\nError, no se cargaron los archivos!");
            	}
            	break;
            case 4:
            	if(validacionMenu == 1)
            	{
					controller_listarJugadores(listaJugadores);
					if(controller_removerJugador(listaJugadores,listaSelecciones) == 0)
					{
						saveFlag = 1;
						puts(" * Jugador DADO DE BAJA EXITOSAMENTE");
						system("pause");

					}
            	}else
            	{
            		puts("\nError, no se cargaron los archivos!");
            	}
            	break;
            case 5:
            	if(validacionMenu == 1)
            	{

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
							controller_listarJugadoresConvocados(listaJugadores, listaSelecciones);
							break;
						case 4:
							break;
						}

					}while(option!=4);
            	}else
            	{
            		puts("\nError, no se cargaron los archivos!");
            	}

            	break;
            case 6:
            	if(validacionMenu == 1)
            	{
					do{

						getInt(&option, "\n1.Convocar Jugador..."
								"\n2.Quitar de la Seleccion..."
								"\n3.Salir...", "\nERROR", 1, 3);
						switch(option)
						{
						case 1:
							controller_listarJugadoresNoConvocados(listaJugadores);
							if(controller_jugadoresConvocados(listaJugadores,listaSelecciones))
							{
								saveFlag = 1;
								puts(" * Jugador CONVOCADO EXITOSAMENTE");
								system("pause");
							}
							break;
						case 2:
							if(controller_desconvocarJugador(listaJugadores, listaSelecciones))
							{
								saveFlag = 1;
								puts(" * Jugador DESCONVOCADO EXITOSAMENTE");
								system("pause");
							}
							break;
						case 3:
							break;
						}
					}while(option !=3);
            	}else
            	{
            		puts("\nError, no se cargaron los archivos!");
            	}

            	break;
            case 7:
            	/*
            	 * criterioDeOrdenamiento = -1; //PEDIR CRITERIO DE ORDENAMIENTO
					getInt(&criterioDeOrdenamiento, "\nCriterio de ordenamiento:"
							"\n -1 -> ordenamiento ascendente (Menor a Mayor) "
							"\n 1 -> ordenamiento descendente (Mayor a Menor) ", "\nError!", -1, 1);
					while(criterioDeOrdenamiento == 0)
					{
						getInt(&criterioDeOrdenamiento, "\nCriterio de ordenamiento:"
											"\n -1 -> ordenamiento ascendente (Menor a Mayor) "
											"\n 1 -> ordenamiento descendente (Mayor a Menor) ", "\nError!", -1, 1);
					}
            	 * */
            	if(validacionMenu == 1)
            	{
					do
					{
						getInt(&option, "\n1.Ordenar jugadores por nacionalidad"
								"\n2.Ordenar selecciones por confederacion"
								"\n3.Ordenar jugadores por Edad"
								"\n4.Ordenar jugadores por nombre"
								"\n5.Salir...", "\nError!", 1, 5);
						getInt(&criterioOrdenamiento, "\nCriterio de ordenamiento:"
														"\n 0 -> ordenamiento ascendente (Menor a Mayor) "
														"\n 1 -> ordenamiento descendente (Mayor a Menor)"
														"\n 2 -> salir...\n", "\nError!", 0, 2);
						switch(option)
						{
						case 1:


								if(criterioOrdenamiento != 2)
								{
									listaJugadoresAux = ll_clone(listaJugadores);
									listaSeleccionesAux = ll_clone(listaSelecciones);
									ll_sort(listaJugadoresAux, controller_ordenarJugadoresNacionalidad,criterioOrdenamiento);
									controller_listarJugadoresCustom(listaJugadoresAux, listaSeleccionesAux);
									ll_deleteLinkedList(listaJugadoresAux);
									ll_deleteLinkedList(listaSeleccionesAux);
								}


							break;
						case 2:

								if(criterioOrdenamiento != 2)
								{
									listaSeleccionesAux = ll_clone(listaSelecciones);
									ll_sort(listaSeleccionesAux, controller_ordenarSeleccionesConfederacion,criterioOrdenamiento);
									controller_listarSelecciones(listaSeleccionesAux);
									ll_deleteLinkedList(listaSeleccionesAux);
								}


							break;
						case 3:
							if(criterioOrdenamiento != 2)
							{
								listaJugadoresAux = ll_clone(listaJugadores);
								listaSeleccionesAux = ll_clone(listaSelecciones);
								ll_sort(listaJugadoresAux, controller_ordenarJugadoresPorEdad,criterioOrdenamiento);
								controller_listarJugadoresCustom(listaJugadoresAux, listaSeleccionesAux);
								ll_deleteLinkedList(listaJugadoresAux);
								ll_deleteLinkedList(listaSeleccionesAux);
							}

							break;
						case 4:
							if(criterioOrdenamiento != 2)
							{
								listaJugadoresAux = ll_clone(listaJugadores);
								listaSeleccionesAux = ll_clone(listaSelecciones);
								ll_sort(listaJugadoresAux,controller_ordenarJugadoresNombre,criterioOrdenamiento);
								controller_listarJugadoresCustom(listaJugadoresAux, listaSeleccionesAux);
								ll_deleteLinkedList(listaJugadoresAux);
								ll_deleteLinkedList(listaSeleccionesAux);
							}
							break;
						case 5:
							break;
						}
					}while(option != 5);
            	}else
            	{
            		puts("\nError, no se cargaron los archivos!");
            	}

            	break;
            case 8:
            	if(validacionMenu == 1)
            	{
            		controller_guardarJugadoresModoBinario("jugadoresConvocados.bin",listaJugadores,listaSelecciones);
            		puts(" * Guardado de jugadores exitoso!");
					system("pause");
            	}else
            	{
            		puts("\nError, no se cargaron los archivos!");
            	}
            	break;
            case 9:
            	if(validacionMenu == 1)
            	{
					controller_cargarJugadoresDesdeBinario("jugadoresConvocados.bin",listaJugadores);
					puts(" * Se genero el archivo binario!");
					system("pause");
            	}else
            	{
            		puts("\nError, no se cargaron los archivos!");
            	}
            	break;
            case 10:
            	if(validacionMenu == 1)
            	{
					controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
					controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones);
					saveFlag = 0;
            	}else
            	{
            		puts("\nError, no se cargaron los archivos!");
            	}
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

