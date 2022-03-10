#include "pezzi.h"
#include "mosse.h"
#include "scacchiera.h"
#include "valutazione.h"
#include "cervello.h"

int minimax(int depth, int *game, int isMaximisingPlayer) {

    int game_used[120];
    memcpy(game_used, game, sizeof(int) * 120);

    if (depth == 0) {
        return valuta_posizione(game_used);
    }

    mossa mosse[200];
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
            memcpy(game_used, game, sizeof(int) * 120);
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
            memcpy(game_used, game, sizeof(int) * 120);
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

        printf("mossa da %d a %d valutazione %d\n", newGameMove.da, newGameMove.a, value);

        memcpy(game_used, game, sizeof(int) * 120);
        if(value >= bestMove) {
            bestMove = value;
            bestMoveFound = newGameMove;
        }
    }
    printf("#--- deciso da %d a %d punteggio %d \n\n", bestMoveFound.da, bestMoveFound.a, bestMove);
    return bestMoveFound;
};