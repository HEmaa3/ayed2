#ifndef _LIST_h
#define _LIST_h

#include <stdbool.h>

typedef int elem;

typedef struct s_node_t* list;

/*  Constructures   */
list empty(void); // crea una lista vacia

list addl(list l, elem e); // coloca el elemento e al comienzo(izquierda) de la lista l.

/* Operadores */
bool is_empty(list l); //devuelve TRUE si lista es vacia

elem head(list l); // devuelve el primer elemento de la lista / PRE:not is_empty(l)

list tail(list l); //elimina el primer elemento de la lista

list addr(list l, elem e); //agrega el elemento e al final (derecha) de la lista l

unsigned int length(list l); //devuelve la cantidad de elementos de la lista

list concat(list l, list m ); // agrega al final de la lista l todos los elementos de la lista m

elem list_index(list l, unsigned int n); // devuelve el e-nesimo elemento de la lista / PRE: length(l) > n 

list take(list l, unsigned int n); // devuelve una lista con los primeros n elementos

list drop(list l, unsigned int n); // elimina los primeros n elementos de la lista l

list copy_list(list l); // copia los elementos de la lista l en una nueva lista m

/* Destructores */
list destroy(list l); // libera memoria en caso de ser necesario

#endif