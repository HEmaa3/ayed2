/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    // completar aquí
    if (x.rank > y.rank){
        return false;
    }
    return true;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void sort(player_t a[], unsigned int length) {
    // completar aquí

    player_t aux;
    for (unsigned int i=0; i<length; i++){
        unsigned int first=i;
        for (unsigned int j=i+1; j<length; j++){
            if (goes_before(a[j],a[first])){
                first=j;
            }
        }
        aux = a[i];
        a[i] = a[first];
        a[first] = aux;
    }
}
