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



int main() {
    int a_mosse[20];
    int a_i = 0;
    disegna_scacchiera(test1);
    a_i = mosse_pedone_bianco_l(test1, 33, a_mosse, a_i);

    for (int i = 0; i < a_i; i++) {
        printf("%d ", a_mosse[i]);
    }
    printf("\n");
}