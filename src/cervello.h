#pragma once

#include "pezzi.h"
#include "mosse.h"
#include "scacchiera.h"
#include "valutazione.h"

int minimax(int depth, int *game, int isMaximisingPlayer);

mossa minimaxRoot(int depth, int *game, int isMaximisingPlayer);