#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "e-s.h"

/*--------------------------------------------PedirInt - ValidarInt--------------------------------------------*/

int pedirInt(char mensaje[])
{
	int numeroEntero;
	printf(mensaje);
	scanf("%d",&numeroEntero);
	return numeroEntero;
}


int validarInt(char mensaje[], char mensajeError[], int minimo, int maximo)
{
	int numeroEntero;
	numeroEntero = pedirInt(mensaje);
	while(numeroEntero < minimo || numeroEntero > maximo)
	{
		printf(mensajeError);
		numeroEntero = pedirInt(mensaje);
	}
	return numeroEntero;
}


int getInt(int* pResultado, char* mensaje, char* mensajeError, int min, int max)
{
    int retorno;
    int numero;
    char buffer[4096];

    retorno = -1;

    if(pResultado != NULL && mensaje != NULL && mensaje != NULL && min < max)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%s", buffer);

            if(esNumerica(buffer))
            {
                numero = atoi(buffer);

                if(numero >= min && numero <= max)
                {
                    *pResultado = numero;
                    retorno = 0;
                }
                else{
                    printf("%s", mensajeError);
                }
            }
            else
            {
                printf("%s", mensajeError);
            }

        }while(retorno == -1);
    }

    return retorno;
}

int esNumerica(char* string)
{
    int retorno = 1;
    int i = 0;

    if(string[0] == '-'){
        i = 1;
    }

    for( ; string[i] != '\0'; i++){
    	if(string[i] == '.')
    	{
    		if((string[i] > '9' || string[i] < '0') && (string[i] < '.')){
    		    retorno = 0;
    		    break;
    		        }
    	} else
    		{
    			if((string[i] > '9' || string[i] < '0') && (string[i] < '.')){
    				retorno = 0;
    				break;
    		 }
    	}

    }

    return retorno;
}

/*--------------------------------------------PedirFloat - ValidarFloat--------------------------------------------*/

float pedirFloat(char mensaje[])
{
	float numeroFloat;
	printf(mensaje);
	scanf("%f",&numeroFloat);

	return numeroFloat;
}

float validarFloat(char mensaje[], char mensajeError[], int minimo, int maximo)
{
	float numeroFloat;
	numeroFloat = pedirFloat(mensaje);
	while(numeroFloat < minimo || numeroFloat > maximo)
	{
		printf(mensajeError);
		numeroFloat = pedirFloat(mensaje);
	}

	return numeroFloat;
}

/*--------------------------------------------PedirChar y PedirCadena--------------------------------------------*/
char pedirChar(char mensaje[])
{
	char rta;
	printf(mensaje);
	fflush(stdin);
	scanf("%c",&rta);

	return rta;
}

void pedirString(char mensaje[], char cadena[]) {
    printf(mensaje);
    fflush(stdin);
    gets(cadena);
}
/*--------------------------------------------Recorrer Vectores--------------------------------------------*/




void recorrerVectorInts(int vector[], int size){
	for( int i = 0; i < size; i++){
	printf("%d\n",vector[i]);
	}
}

char upperCase(char caracter){
	if(caracter > 96 && caracter < 123){
	caracter -= 32;
	}
	return caracter;
}

char lowerCase(char caracter){
	if(caracter > 64 && caracter < 91){
		caracter += 32;
	}
	return caracter;
}


