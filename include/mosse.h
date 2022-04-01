#pragma once

#include <string.h>
#include <assert.h>
#include "pezzi.h"


void fai_mossa(int *sc, int da, int a);

int mosse_pedone_bianco(int *sc, int pos, int *mosse, int mosse_i);

int mosse_pedone_nero(int *sc, int pos, int *mosse, int mosse_i);

int mosse_pedone_bianco_base(int *sc, int pos, int *mosse, int mosse_i);

int mosse_pedone_nero_base(int *sc, int pos, int *mosse, int mosse_i);

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

int mosse_re_bianco_no_arrocco(int *sc, int pos, int *mosse, int mosse_i);

int mosse_re_nero_no_arrocco(int *sc, int pos, int *mosse, int mosse_i);

void attacco_bianchi(int *sc, int *attacco);

void attacco_neri(int *sc, int *attacco);

int trova_re_bianco(int sc[]);

int trova_re_nero(int sc[]);

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

#define promozione_pb_r -5
#define promozione_pb_t -6
#define promozione_pb_a -7
#define promozione_pb_c -8

#define promozione_pn_r -9
#define promozione_pn_t -10
#define promozione_pn_a -11
#define promozione_pn_c -12

#define promozione_pbdx_r -13
#define promozione_pbdx_t -14
#define promozione_pbdx_a -15
#define promozione_pbdx_c -16

#define promozione_pndx_r -17
#define promozione_pndx_t -18
#define promozione_pndx_a -19
#define promozione_pndx_c -20

#define promozione_pbsx_r -21
#define promozione_pbsx_t -22
#define promozione_pbsx_a -23
#define promozione_pbsx_c -24

#define promozione_pnsx_r -25
#define promozione_pnsx_t -26
#define promozione_pnsx_a -27
#define promozione_pnsx_c -28

#define NO_PRESA_AL_VARCO 0

// presa al varco -> pav
#define pav_b_dx -29
#define pav_b_sx -30

#define pav_n_dx -31
#define pav_n_sx -32