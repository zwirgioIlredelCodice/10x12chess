#include "pezzi.h"
#include "mosse.h"
#include "scacchiera.h"
#include "valutazione.h"
#include "cervello.h"

int minimax(int depth, scacchiera game, int isMaximisingPlayer) {

    if (depth == 0) {
        return valuta_posizione(&game);
    }

    mossa mosse[200];
    int mosse_i = 0;

    if (isMaximisingPlayer) {
        mosse_i = mosse_legali_biachi(game, mosse, mosse_i);

        if (mosse_i == 0) {
            if (re_bianco_attaccato(&game)) {
                return -9999; //ha perso
            }
            else {
                return 0;
            }
        }

        int bestMove = -9999;
        for (int i = 0; i < mosse_i; i++) {
            fai_mossa(&game, mosse[i].da, mosse[i].a);
            int mmOVE = minimax(depth - 1, game, !isMaximisingPlayer);
            if (mmOVE > bestMove) {
                bestMove = mmOVE;
            }
        }
        return bestMove;
    } else {
        mosse_i = mosse_legali_neri(game, mosse, mosse_i);

        if (mosse_i == 0) {
            if (re_nero_attaccato(&game)) {
                return +9999; //ha perso
            }
            else {
                return 0;
            }
        }

        int bestMove = 9999;
        for (int i = 0; i < mosse_i; i++) {
            fai_mossa(&game, mosse[i].da, mosse[i].a);
            int mmOVE = minimax(depth - 1, game, !isMaximisingPlayer);
            if (mmOVE < bestMove) {
                bestMove = mmOVE;
            }
        }
        return bestMove;
    }
}

mossa minimaxRoot(int depth, scacchiera game, int isMaximisingPlayer) {

    mossa mosse[200];
    int mosse_i = 0;

    if (isMaximisingPlayer) {
        mosse_i = mosse_legali_biachi(game, mosse, mosse_i);
    } else {
        mosse_i = mosse_legali_neri(game, mosse, mosse_i);
    }
    int bestMove = -9999;
    mossa bestMoveFound;

    for(int i = 0; i < mosse_i; i++) {
        mossa newGameMove = mosse[i];
        fai_mossa(&game, mosse[i].da, mosse[i].a);
        int value = minimax(depth - 1, game, !isMaximisingPlayer);

        printf("mossa da %d a %d valutazione %d\n", newGameMove.da, newGameMove.a, value);

        if(value >= bestMove) {
            bestMove = value;
            bestMoveFound = newGameMove;
        }
    }
    printf("#--- deciso da %d a %d punteggio %d \n\n", bestMoveFound.da, bestMoveFound.a, bestMove);
    return bestMoveFound;
};