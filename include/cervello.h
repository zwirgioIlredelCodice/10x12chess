#pragma once

#include "pezzi.h"
#include "mosse.h"
#include "scacchiera.h"
#include "valutazione.h"

int minimax(int depth, int *game);

mossa minimaxRoot(int depth, int *game);

unsigned long int perft(int depth, int *game);

void perftRoot(int depth, int *game);

int minimax_alpha_beta(int depth, int *game, int alpha, int beta);

mossa minimax_alpha_beta_Root(int depth, int *game);