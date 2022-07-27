#include <stdlib.h>
#include <stdio.h>

#include "list.h"

struct s_node_t{
    elem value;
    struct s_node_t* next;
};

list empty(void){
    return NULL;
}

list addl(list l, elem e){ // coloca el elemento e al comienzo(izquierda) de la lista l.
    list n;
    n = malloc(sizeof(struct s_node_t));
    n->value = e;
    n->next = l;
    
    return n;
}

/* Operadores */
bool is_empty(list l){ //devuelve TRUE si lista es vacia
    return l==NULL;
}

elem head(list l){ // devuelve el primer elemento de la lista / PRE:not is_empty(l)
    return l->value;
}

list tail(list l){ //elimina el primer elemento de la lista
    l = l->next;
    return l;
}

list addr(list l, elem e){ //agrega el elemento e al final (derecha) de la lista l
    list n;
    n = malloc(sizeof(struct s_node_t));
    n->value = e;
    n->next = NULL;
    if (l == NULL){
        l = n;
    }else{
        list i;
        i = l;
        while(i->next != NULL){
            i=i->next;
        }
        i->next = n;
    }
    return l;
}
unsigned int length(list l){ //devuelve la cantidad de elementos de la lista
    unsigned int n=0;
    list i;
    i=l;
    while(i != NULL){
        i=i->next;
        n++;
    }
    return n;
}

list concat(list l, list m ){ // agrega al final de la lista l todos los elementos de la lista m
    list i;
    i=l;
    if (l == NULL){
        l = m;
    }else{
        while(i != NULL){
            i=i->next;
        }
        i->next=m;
    }
    return l;
}

elem list_index(list l, unsigned int n){ // devuelve el e-nesimo elemento de la lista / PRE: length(l) > n 
    unsigned int i=0;
    list p = l;

    while (i < n){  
        p = p->next;
        i++;
    }

    return p->value;
}

list take(list l, unsigned int n){ // devuelve una lista con los primeros n elementos
    list p = l;
    unsigned int i=0;

    while(i < n){
        p = p->next;
        i++;
    }
    p->next = NULL;
    
    return l;
}

list drop(list l, unsigned int n){ // elimina los primeros n elementos de la lista l
    unsigned int i=0;
    while (i < n){
        l = l->next;
    }

    return l;
}

list copy_list(list l){ // copia los elementos de la lista l en una nueva lista m
    list m = malloc(sizeof(struct s_node_t));
    m = l;

    return m;
}

/* Destructores */
list destroy(list l){ // libera memoria en caso de ser necesario
    list p = l;
    while (p != NULL){
        p = p->next;
        free(l);
        l = p;
    }
    return l;
}