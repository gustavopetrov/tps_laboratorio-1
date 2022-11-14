
#ifndef PARSER_H_
#define PARSER_H_



int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);
int parser_GuardarJugadorTexto(FILE* pArchivo , LinkedList* pArrayListJugador);
int parser_guardarSeleccionesTexto(FILE* pArchivo , LinkedList* pArrayListSeleccion);

#endif /* PARSER_H_ */
