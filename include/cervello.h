#pragma once

#include "pezzi.h"
#include "mosse.h"
#include "scacchiera.h"
#include "valutazione.h"

int minimax(int depth, int *game);

mossa minimaxRoot(int depth, int *game);

unsigned long int perft(int depth, int *game);