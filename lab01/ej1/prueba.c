#include <stdio.h>

int main (){
    FILE* prueba;
    prueba = fopen("input/example-easy.in", "r");
    int result;

    while ((fscanf(prueba, "%d", &result)) != EOF){
        printf("%d\n", result);
    }

    fclose(prueba);
    return 0;
}

// ejemplo de como lee un archivo o fichero, por cada lectura exitosa (un numero del fichero, separado por espacios o enter)
// cuando es EOF es porque el archivo no tiene mas numeros por leer 