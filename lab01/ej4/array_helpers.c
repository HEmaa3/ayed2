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
                                       // %u es un formato utilizado para un entero sin signo ---- %d o &i enteros con signo

    for (unsigned int i=0; i < largo && i < max_size; i++){
        fscanf(input_file, "%d", &array[i]);
    }

    fclose(input_file);
    
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

bool array_is_sorted (int a[], unsigned int max_size){
    int first = a[0];
    bool b = 1;

    for (unsigned int i=1; i < max_size; i++){
        if (first <= a[i]){
            first = a[i];
        }else{
            b = 0;
        }
    }

    if (b==1){
        printf("El arreglo está ordenado\n");
    }else{
        printf("El arreglo no está ordenado\n");
    }

    return 0;
}

//array_helpers.c es la implementacion del TAD.

// compilamos primero array_helpers.c y mainnew.c por separado y luego creamos el ejecutable 
// incluyendo ambos archivos

// Ejemplo:
/*  gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c
    gcc -Wall -Werror -Wextra -pedantic -std=c99 -c mainnew.c

y finalmente:
    gcc -Wall -Werror -Wextra -pedantic -std=c99 array_helpers.o main.o -o reader

    luego ./reader input/...
*/