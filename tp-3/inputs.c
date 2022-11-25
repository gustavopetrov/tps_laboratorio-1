/*
 * inputs.c
 *
 *  Created on: 1 nov. 2022
 *      Author: usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 */
 int isValidNombre(char* cadena,int longitud)
{
   int i;
   int retorno;
   i = 0;
   retorno = 1;
   if( cadena != NULL && longitud > 0)
   {
	   for (i = 0; cadena[i] != '\0' && i < longitud; i++)
	   {
		   if ((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z' ) && cadena[i] != ' ' )
		   {
			   retorno = 0;
			   break;
		   }
	   }
   }
    return retorno;
}

int esNumerica(char* cadena, int limite)
{
	 int retorno;
	 int i;
	 retorno = 0; //error

	 if( cadena != NULL && limite > 0)
	 {
		 for(i = 0; cadena[i] != '\0'; i++ )
		 {
			 if( i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
			 {
				 continue;
			 }
			 if(cadena[i] < '0' || cadena[i] > '9')
			 {
				 retorno = 1;
				 break;
			 }
		 }
	 }
	 return retorno;
 }
int esNumericaPositivos(char* cadena, int limite)
{
	 int retorno;
	 int i;
	 retorno = 0; //error

	 if( cadena != NULL && limite > 0)
	 {
		 for(i = 0; cadena[i] != '\0'; i++ )
		 {
			 if( i == 0 && (cadena[i] == '+'))
			 {
				 continue;
			 }
			 if(cadena[i] < '0' || cadena[i] > '9')
			 {
				 retorno = 1;
				 break;
			 }
		 }
	 }
	 return retorno;
 }
int esFlotante(char* cadena, int limite)
{
	int retorno;
	int i;
	int contadorPunteros;
	contadorPunteros = 0;
	retorno = 0; //error

	if( cadena != NULL && limite > 0)
	{
	 for(i = 0; cadena[i] != '\0'; i++ )
	 {
		 if( i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
		 {
			 continue;
		 }
		 if(cadena[i] < '0' || cadena[i] > '9')
		 {
			 if(cadena[i] == '.' && contadorPunteros == 0)
			 {
				 contadorPunteros++;
				 retorno = 1;
			 }
			 else
			 {
				 retorno = 0;
				 break;
			 }
		 }
	 }
	}

	return retorno;
}
