#include <stdio.h>    /* printf(), scanf() */
#include <stdbool.h>  /* tipo bool         */

#include <assert.h>   /* assert() */

#define ARRAY_SIZE 10

struct max_min_result { // struct nos permite agrupar diferentes "tipos" de variables
    int max_value; // variable de tipo int llamada max_value - idem con las demas
    int min_value;
    unsigned int max_position; // sin signo (unsigned)
    unsigned int min_position; // sin signo (unsigned)
}; 

/* el nombre del struct es max_min_result. Para acceder a alguna de estas 
variables llamo a "max_min_result". Pero tambien mi struct es una variable 
de tipo. Por lo tanto yo puedo crear una variable nueva de tipo "max_min_result".
Por ejemplo dentro del main digo -> "max_min_result MAR" y entonces aqui es creado
una variable llamada MAR de tipo max_min_result y dentro de MAR estan las variables 
creadas en el struct.
Para acceder a una variable dentro de MAR digo -> "MAR.max_value" que ya sabemos 
es de tipo "int"
*/
struct max_min_result compute_max_min(int array[], unsigned int length) /* esta es una funcion
llamada "compute_max_min" que me devuelve un struct de tipo max_min_result y tiene como argu-
mento un arreglo de tipo int y la longitud del arreglo
La variable length vive dentro de esta funcion, unicamente, y adopa el valor que le doy como
argumento.
Lo mismo con array[] 
*/
{
    assert(length > 0);
    //array=array;
    struct max_min_result result; /* aca estoy creando una variable nueva
    llamada result de tipo "max_min_result"
    */
    result.max_value = 2;
    result.min_value = 2;

    // IMPLEMENTAR 
    int i=0;
    while (i < ARRAY_SIZE)
    {
        if(array[i]>result.max_value)
        {
            result.max_value = array[i];
            result.max_position = i;
        }
        if(array[i]<result.min_value){
            
            result.min_value = array[i];
            result.min_position = i;
        }
        else{

        }
        i++;
    }

    return result;
}

int main(void)
{
    int array[ARRAY_SIZE];
    int i=0;
    // PEDIR AL USUARIO QUE INGRESE LOS ELEMENTOS DEL ARREGLO
    while (i < ARRAY_SIZE)
    {
            
            printf("Ingrese los elementos del arreglo, respectivamente: \n");
            scanf("%d",&array[i]);
            i++;

    }

    struct max_min_result result = compute_max_min(array, ARRAY_SIZE);
    printf("Máximo: %d\n", result.max_value);
    printf("Posición del máximo: %u\n", result.max_position);
    printf("Mínimo: %d\n", result.min_value);
    printf("Posición del mínimo: %u\n", result.min_position);
    return 0;
}

