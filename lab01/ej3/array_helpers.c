#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "array_helpers.h"

unsigned int array_from_file(int array[], 
            unsigned int max_size, 
            const char* filepath) {
    //your code here!!!
    FILE* input_file; // creamos una variable de tipo FILE apuntadora (puntero-apunta a una direccion de memoria) llamada input_file
    input_file = fopen(filepath, "r"); //fopen() devuelve null si el archivo no fue abierto
    unsigned int largo;

    if (input_file == NULL){
        printf("El archivo no pudo ser abierto\n");
    }
    
    fscanf(input_file, "%u", &largo);  //* si devuelve 1 la lectura fue exitosa (validacion de la lectura) - si devuelve 0 no se pudo leer
    printf("%u\n",largo);                                    // %u es un formato utilizado para un entero sin signo ---- %d o &i enteros con signo

    for (unsigned int i=0; i < largo && i < max_size; i++){
        fscanf(input_file, "%d", &array[i]);
        printf("%d\n", array[i]); // imprime lo que va leyendo
    }

    fclose(input_file);
    printf("El archivo se ha leido correctamente\n");
    
    return largo;
}

void array_dump(int a[], unsigned int length) {
    //your code here!!!!! (mostrar por pantalla elementos que ya estan cargados en el archivo)
    printf("["); //esto lo hacemos porque no se puede devolver un arreglo como tal
    if (length == 0) {
        printf("]\n");
    }else {
        for (unsigned int i=0; i < (length-1); i++){
            printf("%d, ", a[i]);
        }
        printf("%d]\n", a[length-1]);
    }
}

//array_helpers.c es la implementacion del TAD.

