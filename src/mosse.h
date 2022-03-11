#pragma once

#include <string.h>
#include <assert.h>
#include "pezzi.h"
#include "scacchiera.h"


void fai_mossa(scacchiera *scc, char da, char a);

int mosse_pedone_bianco(scacchiera *scc, char pos, char *mosse, int mosse_i);

int mosse_pedone_nero(scacchiera *scc, char pos, char *mosse, int mosse_i);

int mosse_cavallo_bianco(scacchiera *scc, char pos, char *mosse, int mosse_i);

int mosse_cavallo_nero(scacchiera *scc, char pos, char *mosse, int mosse_i);

int mosse_alfiere_bianco(scacchiera *scc, char pos, char *mosse, int mosse_i);

int mosse_alfiere_nero(scacchiera *scc, char pos, char *mosse, int mosse_i);

int mosse_torre_bianca(scacchiera *scc, char pos, char *mosse, int mosse_i);

int mosse_torre_nera(scacchiera *scc, char pos, char *mosse, int mosse_i);

int mosse_regina_bianca(scacchiera *scc, char pos, char *mosse, int mosse_i);

int mosse_regina_nera(scacchiera *scc, char pos, char *mosse, int mosse_i);

int mosse_re_bianco(scacchiera *scc, char pos, char *mosse, int mosse_i);

int mosse_re_nero(scacchiera *scc, char pos, char *mosse, int mosse_i);


void attacco_bianchi(scacchiera *scc, char *attacco);

void attacco_neri(scacchiera *scc, char *attacco);


int re_bianco_attaccato(scacchiera *scc);

int re_bianco_attaccato_mossa(scacchiera scc, char da, char a);

int re_nero_attaccato(scacchiera *scc);

int re_nero_attaccato_mossa(scacchiera scc, char da, char a);

int mosse_re_bianco_l(scacchiera scc, char pos, char *mosse, int mosse_i);

int mosse_re_nero_l(scacchiera scc, char pos, char *mosse, int mosse_i);

int mosse_pedone_bianco_l(scacchiera scc, char pos, char *mosse, int mosse_i);

int mosse_cavallo_bianco_l(scacchiera scc, char pos, char *mosse, int mosse_i);

int mosse_alfiere_bianco_l(scacchiera scc, char pos, char *mosse, int mosse_i);

int mosse_torre_bianca_l(scacchiera scc, char pos, char *mosse, int mosse_i);

int mosse_regina_bianca_l(scacchiera scc, char pos, char *mosse, int mosse_i);

int mosse_pedone_nero_l(scacchiera scc, char pos, char *mosse, int mosse_i);

int mosse_cavallo_nero_l(scacchiera scc, char pos, char *mosse, int mosse_i);

int mosse_alfiere_nero_l(scacchiera scc, char pos, char *mosse, int mosse_i);

int mosse_torre_nera_l(scacchiera scc, char pos, char *mosse, int mosse_i);

int mosse_regina_nera_l(scacchiera scc, char pos, char *mosse, int mosse_i);

typedef struct mossa {
    char da;
    char a;
} mossa;

int mosse_legali_biachi(scacchiera scc, mossa *mosse_l, int mosse_i_l);

int mosse_legali_neri(scacchiera scc, mossa *mosse_l, int mosse_i_l);