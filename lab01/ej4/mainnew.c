/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

#define MAX_SIZE 100000

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the file path given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1]; // me devuelve el segundo parametro, ya que argv[0] es el primer parametro (./reader)

    return result;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);
    
    /*dumping the array*/
    array_dump(array, length);

    /* me devuelve si esta ordenado o si no esta ordenado */
    array_is_sorted (array, length);

    return EXIT_SUCCESS;
}


/* Ciclo de un archivo de escritura -> fopen(), fscanf() y fclose()
fscanf() -> int fscanf(FILE *stream, const char *format, ...) la unica diferencia que tiene con el scanf() es que no lee los archivos
            que el usuario le pasa como valores sino que lee los valores que estan en el archivo que le pasamos como parametro (FILE *stream).

fopen() -> FILE *fopen(const char *pathname, const char *mode)
            char * = string
            fopen() lo que hace es abrir un archivo
            pathname = ruta de acceso del archivo
            mode = modo en que vamos a abrir el archivo (lectura,escritura o binario) "r" para lectura

fclose() -> int fclose(FILE *stream) cierra el archivo

*/
