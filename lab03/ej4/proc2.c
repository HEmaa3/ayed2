#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    // Completar aqui
    if (x >= 0){
        *y = x;
    } else {
        *y = -x;
    }
}

int main(void) {
    // Completar aqui
    int a, r; // cuando yo declaro una variable estoy reservando un espacio/direccion de memoria para esa variable.
    int *res = NULL;
    a = (-98);
    
    res = &r; // esto hace falta porque si no esta, res apunta a una direccion basura o aleatoria. Entonces, hace falta definir una direccion para el puntero res.

    absolute(a, res);
    
    printf("%d\n", *res);

    r = 0;
    return r;
}

