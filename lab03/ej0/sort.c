#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "helpers.h"

unsigned int data_from_file (const char* path, unsigned int indexes[], char letters[], unsigned int max_size){
    FILE* input_file; // creamos una variable de tipo archivo apuntadora.
    input_file = fopen(path,"r"); // a esa variable le asignamos el archivo que vamos a leer o ver
    unsigned int largo;
    unsigned int i=0;

    if(input_file==NULL){
        printf("El archivo no pudo ser abierto\n"); //esto es para comprobar que el archivo pudo ser abierto
    }

    while(!feof(input_file) && i < max_size){  // eof = end of file - mientras no llega al final del archivo es decir mientras lo esta leyendo
        fscanf(input_file, "%u %*c%c%*c\n", &indexes[i], &letters[i]); // %u entero sin signo - aca me lee los enteros del fichero o archivo
        printf("%u", indexes[i]);                    // importante -> %*c se utiliza para saltear un caracter !!!!!!
        printf(" %c\n", letters[i]);
        i++;
    }

    largo = i;
    fclose(input_file);
    printf("El archivo se ha leido correctamente\n");

    return largo;
}

char* parse_file(int argc, char* argv[]){
    char* result;

    bool valid_args_count = (argc == 2);
    
    if (!valid_args_count) {
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

void sort (char sorted[], unsigned int indexes[], char letters[], unsigned int length){

    for(unsigned int i=0; i< length; i++){
        for(unsigned int j=0; j<length; j++){
            if (indexes[j] == i){
                sorted[i] = letters[j];
            }else{
            }
        }
    }
}
