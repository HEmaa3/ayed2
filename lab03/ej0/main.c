#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

#include "sort.h"

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

int main(int argc, char* argv[]) { // int argc es el numero de argumentos que se pasan en la linea de comandos y char* argv[] es una matriz de cadenas(punteros de caracteres) que representan los argumentos individuales proporcionados en al linea de comandos
    //FILE *file;
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length = 0; 
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    
    /* -- completar -- */
    char* filepath = NULL;

    filepath = parse_file(argc, argv);

    //file = fopen(filepath,"r");

    length = data_from_file(filepath,indexes,letters,MAX_SIZE);

    sort (sorted,indexes,letters,length);

    dump(sorted, length);

    return EXIT_SUCCESS;
}

