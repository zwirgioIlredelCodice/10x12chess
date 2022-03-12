#pragma once

#include "pezzi.h"
#include "mosse.h"
#include "scacchiera.h"
#include "valutazione.h"
#include "scacchiera.h"

int minimax(int depth, scacchiera game, int isMaximisingPlayer);

mossa minimaxRoot(int depth, scacchiera game, int isMaximisingPlayer);