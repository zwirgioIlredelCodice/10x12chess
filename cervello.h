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
var minimax = function (depth, game, isMaximisingPlayer) {
    positionCount++;
    if (depth === 0) {
        return -evaluateBoard(game.board());
    }

    var newGameMoves = game.ugly_moves();

    if (isMaximisingPlayer) {
        var bestMove = -9999;
        for (var i = 0; i < newGameMoves.length; i++) {
            game.ugly_move(newGameMoves[i]);
            bestMove = Math.max(bestMove, minimax(depth - 1, game, !isMaximisingPlayer));
            game.undo();
        }
        return bestMove;
    } else {
        var bestMove = 9999;
        for (var i = 0; i < newGameMoves.length; i++) {
            game.ugly_move(newGameMoves[i]);
            bestMove = Math.min(bestMove, minimax(depth - 1, game, !isMaximisingPlayer));
            game.undo();
        }
        return bestMove;
    }
}
*/

int minimax(int depth, int *game, int isMaximisingPlayer) {

    int game_used[120];
    memcpy(game_used, game, sizeof(int) * 120);

    int positionCount;
    positionCount++;

    //printf("%d ", positionCount);

    if (depth == 0) {
        return -valuta_posizione(game_used);
    }

    mossa mosse[200];
    int mosse_i = 0;

    if (isMaximisingPlayer) {
        mosse_i = mosse_legali_biachi(game_used, mosse, mosse_i);

        int bestMove = -9999;
        for (int i = 0; i < mosse_i; i++) {
            fai_mossa(game_used, mosse[i].da, mosse[i].a);
            int mmOVE = minimax(depth - 1, game_used, !isMaximisingPlayer);
            if (mmOVE > bestMove) {
                bestMove = mmOVE;
            }
            memcpy(game, game_used, sizeof(int) * 120);
        }
        return bestMove;
    } else {
        mosse_i = mosse_legali_neri(game_used, mosse, mosse_i);

        int bestMove = 9999;
        for (int i = 0; i < mosse_i; i++) {
            fai_mossa(game_used, mosse[i].da, mosse[i].a);
            int mmOVE = minimax(depth - 1, game_used, !isMaximisingPlayer);
            if (mmOVE < bestMove) {
                bestMove = mmOVE;
            }
            memcpy(game, game_used, sizeof(int) * 120);
        }
        return bestMove;
    }
}

mossa minimaxRoot(int depth, int *game, int isMaximisingPlayer) {

    mossa mosse[200];
    int mosse_i = 0;

    int game_used[120];
    memcpy(game_used, game, sizeof(int) * 120);

    if (isMaximisingPlayer) {
        mosse_i = mosse_legali_biachi(game_used, mosse, mosse_i);
    } else {
        mosse_i = mosse_legali_neri(game_used, mosse, mosse_i);
    }
    int bestMove = -9999;
    mossa bestMoveFound;

    for(int i = 0; i < mosse_i; i++) {
        mossa newGameMove = mosse[i];
        fai_mossa(game_used, mosse[i].da, mosse[i].a);
        int value = minimax(depth - 1, game_used, !isMaximisingPlayer);
        memcpy(game, game_used, sizeof(int) * 120);
        if(value >= bestMove) {
            bestMove = value;
            bestMoveFound = newGameMove;
        }
    }
    return bestMoveFound;
};