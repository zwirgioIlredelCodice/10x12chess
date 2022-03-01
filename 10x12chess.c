/*
sas malibox board representation
*/

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <stdio.h>
#include "pezzi.h"
#include "mosse.h"
#include "scacchiera.h"

#include "test.h"



/*
int maxi( int depth ) {
    if ( depth == 0 ) return evaluate();
    int max = -oo;
    for ( all moves) {
        score = mini( depth - 1 );
        if( score > max )
            max = score;
    }
    return max;
}

int mini( int depth ) {
    if ( depth == 0 ) return -evaluate();
    int min = +oo;
    for ( all moves) {
        score = maxi( depth - 1 );
        if( score < min )
            min = score;
    }
    return min;
}
*/


int Perft(int *sc, int depth) {
    mossa move_list[256];
    int n_moves, i;
    int nodes = 0;

    if (depth == 0) 
        return 1ULL;

    int sc1[120];
    memcpy(sc1, sc, sizeof(int) * 120);

    n_moves = tutte_mosse_legali(sc,move_list, 0);
    for (i = 0; i < n_moves; i++) {
        fai_mossa(sc1, move_list[i].da, move_list[i].a);
        nodes += Perft(sc1, depth - 1);
        memcpy(sc, sc1, sizeof(int) * 120);
    }
    return nodes;
}

int main() {
/*
    disegna_scacchiera(scacchiera_0);
    mossa mosse_legali[100];
    int mosse_legali_i = 0;

    mosse_legali_i = tutte_mosse_legali(scacchiera_0, mosse_legali, mosse_legali_i);

    printf("\n");
    for (int i = 0; i < mosse_legali_i; i++) {
        printf("%d: da %d a %d\n", i, mosse_legali[i].da, mosse_legali[i].a);
    }
    printf("\n");
    */
    int sas = Perft(scacchiera_0, 3);
    printf("saas %d\n", sas);
}