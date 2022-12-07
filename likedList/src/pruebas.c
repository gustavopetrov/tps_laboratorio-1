/*
 * pruebas.c
 *
 *  Created on: 26 nov. 2022
 *      Author: usuario
 */


/// @brief Filtra los elementos de la lista utilizando la funcion recibida como parametro
///	/* llama a pFunc y le pasa un elemento, si pFunc devuelve 1, lo carga/
/// @param LinkedList* Puntero a la lista
/// @param fn (*fn) Puntero a la funcion de filtrado
/// @return Retorno la lista filtrada si se pudo filtrar
/// 		NULL si no se filtro

//LinkedList* ll_filter(LinkedList this, int (*fn)(void*))
//{
//	void *pElement;
//	LinkedList* filterArray = NULL;
//	int size;
//
//	if (this != NULL && fn != NULL)
//	{
//		filterArray = ll_newLinkedList();
//
//		size = ll_len(this);
//
//		for (int i = 0; i < size; i++)
//		{
//			pElement = ll_get(this, i);
//
//			if (fn(pElement) == 1)
//			{
//				ll_add(filterArray, pElement);
//			}
//		}
//
//	}
//
//	return filterArray;
//}


/// @brief Mapea los elementos de la lista utilizando la funcion recibida como parametro
///
/// @param this LinkedList* Puntero a la lista
/// @param fn (*fn) Puntero a la funcion de mapeo
/// @return Retorna (1) si la funcion se ejecuto correctamente
/// 			    (-1) si hubo un error
//int ll_map(LinkedList* this, int (fn)(void))
//{
//    int retorno = -1;
//    void* pElement = NULL;
//    int tam;
//
//    if(this != NULL && fn != NULL)
//    {
//		tam =  ll_len(this);
//      for(int i = 0; i < tam; i++)
//      {
//          pElement = ll_get(this, i);
//
//          if(pElement != NULL)
//          {
//              fn(pElement);
//              retorno = 1;
//          }
//      }
//   }
//
//    return retorno;
//}


/// @brief  Recorre elementos de una lista y acumula valores pasados por funcion.
///
/// @param this LinkedList* Puntero a la lista
/// @param fn (*fn) Puntero a la funcion de conteo
/// @return Retorno el valor acumulado
//	int ll_count(LinkedList* this, int (*fn)(void*))
//	{
//		void* pElemento;
//		int acumulador = 0;
//		int numeroActual;
//		int tam;
//
//		if(this!=NULL && fn!=NULL)
//		{
//		tam = ll_len(this);
//
//		for (int i = 0; i < tam; i++)
//		{
//			pElemento = ll_get(this, i);
//
//			numeroActual = fn(pElemento);
//
//			if (numeroActual!=-1) // si la variable es distinto de -1, me copio el valor.
//			{
//				acumulador += numeroActual; //sumo el numero a mi acumulador
//			}
//		}
//	}
//
//	return acumulador;
//}
