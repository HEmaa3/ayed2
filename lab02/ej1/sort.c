#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i) {
    /* needs implementation */
    unsigned int j;
    j=i;

    while (j>0u && goes_before(a[j],a[j-1u])){ // goes_before toma valor absoluto --- devuelve true si a[j] va antes que a[j-1u]
        swap(a,j-1u, j);
        j=j-1u;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) { // 1u = unsigned int
        /* needs implementation */
        insert(a, i);
        assert(array_is_sorted(a,i));
    }
}
