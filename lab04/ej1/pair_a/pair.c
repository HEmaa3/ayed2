#include "pair.h"

pair_t pair_new(int x, int y){
    pair_t p;

    p.fst = x;
    p.snd = y;
    
    return p;

    /* otra forma es hacerlo asi p = {x, y};
                                 return p;
    */                             
}

int pair_first(pair_t p){
    return p.fst;
}
/*
 * DESC: Returns the first component of p
 *
 * PRE: {p --> (x, y)}
 *
 *  fst = pair_first(p);
 *
 * POS: {fst == x}
 */

int pair_second(pair_t p){
    return p.snd;
}
/*
 * DESC: Returns the second component of p
 *
 * PRE: {p --> (x, y)}
 *
 *  snd = pair_second(p);
 *
 * POS: {snd == y}
 */

pair_t pair_swapped(pair_t p){
    pair_t s = {p.snd, p.fst};
    return s;
}
/*
 * DESC: Return a NEW pair with the components of p reversed
 *
 * PRE: {p --> (x, y)}
 *
 *  q = pair_swapped(p)
 *
 * POS: {q --> (y, x)}
 *
 */

pair_t pair_destroy(pair_t p){
    return p;
}
/*
 * DESC: Free memory if its necesary
 *
 */