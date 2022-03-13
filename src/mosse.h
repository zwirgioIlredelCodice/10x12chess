#pragma once

#include <string.h>
#include <assert.h>
#include "pezzi.h"


void fai_mossa(int *sc, int da, int a);

int mosse_pedone_bianco(int *sc, int pos, int *mosse, int mosse_i);

int mosse_pedone_nero(int *sc, int pos, int *mosse, int mosse_i);

int mosse_cavallo_bianco(int *sc, int pos, int *mosse, int mosse_i);

int mosse_cavallo_nero(int *sc, int pos, int *mosse, int mosse_i);

int mosse_alfiere_bianco(int *sc, int pos, int *mosse, int mosse_i);

int mosse_alfiere_nero(int *sc, int pos, int *mosse, int mosse_i);

int mosse_torre_bianca(int *sc, int pos, int *mosse, int mosse_i);

int mosse_torre_nera(int *sc, int pos, int *mosse, int mosse_i);

int mosse_regina_bianca(int *sc, int pos, int *mosse, int mosse_i);

int mosse_regina_nera(int *sc, int pos, int *mosse, int mosse_i);

int mosse_re_bianco(int *sc, int pos, int *mosse, int mosse_i);

int mosse_re_nero(int *sc, int pos, int *mosse, int mosse_i);

void attacco_bianchi(int *sc, int *attacco);

void attacco_neri(int *sc, int *attacco);

int re_bianco_attaccato(int sc[]);

int re_bianco_attaccato_mossa(int sc[], int da, int a);

int re_nero_attaccato(int sc[]);

int re_nero_attaccato_mossa(int sc[], int da, int a);

int mosse_re_bianco_l(int *sc, int pos, int *mosse, int mosse_i);

int mosse_re_nero_l(int *sc, int pos, int *mosse, int mosse_i);

int mosse_pedone_bianco_l(int *sc, int pos, int *mosse, int mosse_i);

int mosse_cavallo_bianco_l(int *sc, int pos, int *mosse, int mosse_i);

int mosse_alfiere_bianco_l(int *sc, int pos, int *mosse, int mosse_i);

int mosse_torre_bianca_l(int *sc, int pos, int *mosse, int mosse_i);

int mosse_regina_bianca_l(int *sc, int pos, int *mosse, int mosse_i);

int mosse_pedone_nero_l(int *sc, int pos, int *mosse, int mosse_i);

int mosse_cavallo_nero_l(int *sc, int pos, int *mosse, int mosse_i);

int mosse_alfiere_nero_l(int *sc, int pos, int *mosse, int mosse_i);

int mosse_torre_nera_l(int *sc, int pos, int *mosse, int mosse_i);

int mosse_regina_nera_l(int *sc, int pos, int *mosse, int mosse_i);

typedef struct mossa {
    int da;
    int a;
} mossa;

int mosse_legali_biachi(int *sc, mossa *mosse_l, int mosse_i_l);

int mosse_legali_neri(int *sc, mossa *mosse_l, int mosse_i_l);

int tutte_mosse_legali(int *sc, mossa *mosse_l, int mosse_i_l);

#define SI_ARROCCO 1
#define NO_ARROCCO 0
#define moss_arrocco_bdx -1
#define moss_arrocco_bsx -2
#define moss_arrocco_ndx -3
#define moss_arrocco_nsx -4