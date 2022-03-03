#pragma once

#include "pezzi.h"
#include "mosse.h"
#include "scacchiera.h"
#include "valutazione.h"

int Perft(int *sc, int depth) { // ?? '
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

#define INFINITO 100000
#define MENO_INFINITO -100000

int mini(int *sc, int profondita);
int maxi(int *sc, int profondita);

int trova_re_bianco(int sc[]) {
    int re = 0;
    for (int i = 0; i < 120; i++) {
        if (sc[i] == re_b) {
            re = 1;
            break;
        }
    }
    return re;
}

int trova_re_nero(int sc[]) {
    int re = 0;
    for (int i = 0; i < 120; i++) {
        if (sc[i] == re_n) {
            re = 1;
            break;
        }
    }
    return re;
}

int maxi(int *sc, int profondita) {
    if (profondita == 0) {
        return valuta_posizione(sc);
    }

    //generazione mosse
    mossa mosse[256];
    int mosse_i = 0;
    mosse_i = mosse_legali_biachi(sc, mosse, mosse_i);

    if(trova_re_bianco(sc) == 0) {
        return MENO_INFINITO;
    }

    if(mosse_i == 0) {
        if (re_bianco_attaccato(sc)) { //scacco matto perchè più mosse e re sotto attacco
            return MENO_INFINITO;
        }
        else {
            return 0; //patta
        }
    }

    //fai copia scacchiera
    int sc_temp[120];
    memcpy(sc_temp, sc, sizeof(int) * 120);

    int max = MENO_INFINITO; // -oo

    for (int i = 0; i < mosse_i; i++) {
        fai_mossa(sc_temp, mosse[i].da, mosse[i].a);
        int punteggio = mini(sc_temp, profondita - 1);
        
        if (punteggio > max) {
            max = punteggio;
        }

        memcpy(sc, sc_temp, sizeof(int) * 120); //resetta
    }
    return max;
}

int mini(int *sc, int profondita) {
    if (profondita == 0) {
        return valuta_posizione(sc);
    }

    //generazione mosse
    mossa mosse[256];
    int mosse_i = 0;
    mosse_i = mosse_legali_neri(sc, mosse, mosse_i);

    if(trova_re_nero(sc) == 0) {
        return INFINITO;
    }

    if(mosse_i == 0) {
        if (re_nero_attaccato(sc)) { //scacco matto perchè più mosse e re sotto attacco
            return INFINITO;
        }
        else {
            return 0; //patta
        }
    }

    //fai copia scacchiera
    int sc_temp[120];
    memcpy(sc_temp, sc, sizeof(int) * 120);

    int min = INFINITO; // +oo

    for (int i = 0; i < mosse_i; i++) {
        fai_mossa(sc_temp, mosse[i].da, mosse[i].a);
        int punteggio = maxi(sc_temp, profondita - 1);
        
        if (punteggio < min) {
            min = punteggio;
        }

        memcpy(sc, sc_temp, sizeof(int) * 120); //resetta
    }
    return min;
}

mossa migliore_mossa(int *sc, int profondita) {
    mossa mosse[256];
    int mosse_i = 0;
    mosse_i = mosse_legali_biachi(sc, mosse, mosse_i);

    mossa mossa_m;
    int sc_temp[120];
    memcpy(sc_temp, sc, sizeof(int) * 120);

    int punteggio = MENO_INFINITO;

    for (int i = 0; i < mosse_i; i++) {
        int p = maxi(sc_temp, profondita);
        if (p > punteggio) {
            punteggio = p;
            mossa_m = mosse[i];
        }
    }
    return mossa_m;
}