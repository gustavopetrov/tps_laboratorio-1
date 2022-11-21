#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "inputs.h"


/*-------inputs desde el buffer-------*/


													/*-------esNumerica-------*/
int esNumericaBuffer(char* string){
    int retorno = 1;
    int i = 0;

    if(string[0] == '-'){
        i = 1;
    }

    for( ; string[i] != '\0'; i++){
        if(string[i] == '.')
        {
            if((string[i] > '9' || string[i] < '0') && (string[i] != '.')){
                retorno = 0;
                break;
            }
        } else
            {
                if((string[i] > '9' || string[i] < '0') && (string[i] != '.')){
                    retorno = 0;
                    break;
             }
        }

    }

    return retorno;
}


/*-------getInt-------*/
int getInt(int* pResultado, char* mensaje, char* mensajeError, int min, int max){
	int retorno;
	int numero;
	char buffer[4096];

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensaje != NULL && min < max){
		do{
			printf("%s", mensaje);
			scanf("%s", buffer);

			if(esNumericaBuffer(buffer)){
				numero = atoi(buffer);

				if(numero >= min && numero <= max){
					*pResultado = numero;
					retorno = 0;
				}
				else{
					printf("%s", mensajeError);
				}
			}
			else{
				printf("%s", mensajeError);
			}

		}while(retorno == -1);
	}

	return retorno;
}
									/*-------getFloat-------*/
int getFloat(float* pResultado, char* mensaje, char* mensajeError, float min, float max){
	int retorno;
	float numero;
	char buffer[4096];

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensaje != NULL && min < max){
		do{
			printf("%s", mensaje);
			scanf("%s", buffer);

			if(esNumericaBuffer(buffer)){
				numero = atof(buffer);

				if(numero >= min && numero <= max){
					*pResultado = numero;
					retorno = 0;
				}
				else{
					printf("%s", mensajeError);
				}
			}
			else{
				printf("%s", mensajeError);
			}

		}while(retorno == -1);
	}

	return retorno;
}
									/*-------getChar-------*/
int getChar(char* pCaracter, char* mensaje, char* mensajeError, char min, char max){
	int retorno;
	char buffer;

	retorno = -1;

	if(pCaracter != NULL && mensaje != NULL && mensaje != NULL && min < max){
		do{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &buffer);

			if(buffer >= min && buffer <= max){
				*pCaracter = buffer;
				retorno = 0;
			}
			else{
				printf("%s", mensajeError);
			}

		}while(retorno == -1);
	}

	return retorno;
}
										/*-------getString-------*/
int getStringAlpha(char string[], int sizeString, char* mensaje, char* mensajeError){
	int retorno;
	char buffer[1024];

	retorno = -1;

	if(string != NULL && mensaje != NULL && mensaje != NULL && sizeString > 0){
		do{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%[^\n]", buffer); // El %[^\n] marca que va a leer hasta q detecte un salto de linea

			if(strlen(buffer) < sizeString){
				strcpy(string, buffer);
				retorno = 0;
			}
			else{
				printf("%s", mensajeError);
			}

		}while(retorno == -1);
	}

	return retorno;
}
										/*-------getShort-------*/
int getShort(short* pResultado, char* mensaje, char* mensajeError, short min, short max){
	int retorno;
	short numero;
	char buffer[4096];

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensaje != NULL && min < max){
		do{
			printf("%s", mensaje);
			scanf("%s", buffer);

			if(esNumericaBuffer(buffer)){
				numero = atoi(buffer);

				if(numero >= min && numero <= max){
					*pResultado = numero;
					retorno = 0;
				}
				else{
					printf("%s", mensajeError);
				}
			}
			else{
				printf("%s", mensajeError);
			}

		}while(retorno == -1);
	}

	return retorno;
}



int getString(char string[], int sizeString, char* mensaje, char* mensajeError)
{
	getStringAlpha(string, sizeString, mensaje, mensajeError);
	while(isValidNombre(string, sizeString) == 0)
	{
		getStringAlpha(string, sizeString, mensaje, mensajeError);
	}

	return 0;
}
