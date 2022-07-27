/*
  @file main.c
  @brief Main program function implementation
*/
#include <stdio.h>
#include <stdlib.h>

/** @brief structure which represent a person */
typedef struct _person {
    int age;
    char name_initial;
} person_t;

/**
 * @brief Main program function
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */

int main(void){

  int x = 1;
  person_t m = {90, 'M'};
  int a[] = {0, 1, 2, 3};

  /* Completar aquí:
     Al finalizar la ejecución las variables deben tener los siguientes valores
     x = 9
     m = (100, F)
     a[1] = 42

     Las restricciones son:
     - No usar las variables 'x', 'm' y 'a' en la parte izquierda de alguna asignación.
     - Se pueden agregar líneas de código, pero no modificar las que ya existen.
     - Se pueden declarar hasta 2 punteros.
     AYUDA: podes usar GDB para consultar valores de variables y la dirección de memoria donde estan alojadas.
  */
  // *algo -- se usa para dos cosas, para acceder el valor donde apunta ese puntero y para declarar un puntero de tipo algo.
  int *p;
  p = &x;
  *p = 9;

  person_t *h;
  h = &m;
  h->age = 100;
  h->name_initial = 'F';
  
  p = &a[1];
  *p = 42; //aca cambié la direccion de memoria a la que apunta p, por eso no me modifica x. Anteriormente p apuntaba a la direccion de memorio donde se guardaba el valor de x. Pero con esta asignacion la cambiamos.
  // Podemos cambiar de direccion de memoria sin cambiar el valor dentro de esa direccion. Y esto lo hacemos con punteros.
  
  printf("x = %d\n", x);
  printf("m = (%d, %c)\n", m.age, m.name_initial);
  printf("a[1] = %d\n", a[1]);
  
  return EXIT_SUCCESS;
}
