#include "pezzi.h"
#include "mosse.h"
#include "scacchiera.h"
#include "valutazione.h"
#include "cervello.h"

int minimax(int depth, int *game, int isMaximisingPlayer) {

    int game_used[GRANDEZZA_SC];
    memcpy(game_used, game, MEM_GRANDEZZA_SC);

    if (depth == 0) {
        return valuta_posizione(game_used);
    }

    mossa mosse[400];
    int mosse_i = 0;

    if (isMaximisingPlayer) {
        mosse_i = mosse_legali_biachi(game_used, mosse, mosse_i);

        if (mosse_i == 0) {
            if (re_bianco_attaccato(game_used)) {
                return -9999; //ha perso
            }
            else {
                return 0;
            }
        }

        int bestMove = -9999;
        for (int i = 0; i < mosse_i; i++) {
            fai_mossa(game_used, mosse[i].da, mosse[i].a);
            int mmOVE = minimax(depth - 1, game_used, !isMaximisingPlayer);
            if (mmOVE > bestMove) {
                bestMove = mmOVE;
            }
            memcpy(game_used, game, MEM_GRANDEZZA_SC);
        }
        return bestMove;
    } else {
        mosse_i = mosse_legali_neri(game_used, mosse, mosse_i);

        if (mosse_i == 0) {
            if (re_nero_attaccato(game_used)) {
                return +9999; //ha perso
            }
            else {
                return 0;
            }
        }

        int bestMove = 9999;
        for (int i = 0; i < mosse_i; i++) {
            fai_mossa(game_used, mosse[i].da, mosse[i].a);
            int mmOVE = minimax(depth - 1, game_used, !isMaximisingPlayer);
            if (mmOVE < bestMove) {
                bestMove = mmOVE;
            }
            memcpy(game_used, game, MEM_GRANDEZZA_SC);
        }
        return bestMove;
    }
}

mossa minimaxRoot(int depth, int *game, int isMaximisingPlayer) {

    mossa mosse[400];
    int mosse_i = 0;

    int game_used[GRANDEZZA_SC];
    memcpy(game_used, game, MEM_GRANDEZZA_SC);

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

        printf("mossa da %d a %d valutazione %d\n", newGameMove.da, newGameMove.a, value);

        memcpy(game_used, game, MEM_GRANDEZZA_SC);
        if(value >= bestMove) {
            bestMove = value;
            bestMoveFound = newGameMove;
        }
    }
    printf("#--- deciso da %d a %d punteggio %d \n\n", bestMoveFound.da, bestMoveFound.a, bestMove);
    return bestMoveFound;
};


// for testing https://wiki.sharewiz.net/doku.php?id=chess:programming:perft

unsigned long int perft(int depth, int *game, int isMaximisingPlayer) {

    unsigned long int nodes = 0;

    int game_used[GRANDEZZA_SC];
    memcpy(game_used, game, MEM_GRANDEZZA_SC);

    if (depth == 0) {
        return 1;
    }

    mossa mosse[400];
    int mosse_i = 0;

    if (isMaximisingPlayer) {
        mosse_i = mosse_legali_biachi(game_used, mosse, mosse_i);
    } 
    else if (!isMaximisingPlayer) {
        mosse_i = mosse_legali_neri(game_used, mosse, mosse_i);
    }
    for (int i = 0; i < mosse_i; i++) {
        fai_mossa(game_used, mosse[i].da, mosse[i].a);
        nodes += perft(depth - 1, game_used, !isMaximisingPlayer);
        memcpy(game_used, game, MEM_GRANDEZZA_SC);
    }
    return nodes;
}