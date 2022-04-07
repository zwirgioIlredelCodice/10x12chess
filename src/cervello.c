#include "pezzi.h"
#include "mosse.h"
#include "scacchiera.h"
#include "valutazione.h"
#include "cervello.h"

int minimax(int depth, int *game) {

    int game_used[GRANDEZZA_SC];
    memcpy(game_used, game, MEM_GRANDEZZA_SC);

    if (depth == 0) {
        return valuta_posizione(game_used);
    }

    mossa mosse[400];
    int mosse_i = 0;
    mosse_i = mosse_legali(game_used, mosse, mosse_i);

    if (game_used[turno] == turn_white) {
        

        if (mosse_i == 0) {
            if (re_bianco_attaccato(game_used)) {
                return -99999; //ha perso
            }
            else {
                return 0;
            }
        }

        int bestMove = -99999;
        for (int i = 0; i < mosse_i; i++) {
            fai_mossa(game_used, mosse[i].da, mosse[i].a);
            int mmOVE = minimax(depth - 1, game_used);
            if (mmOVE > bestMove) {
                bestMove = mmOVE;
            }
            memcpy(game_used, game, MEM_GRANDEZZA_SC);
        }
        return bestMove;
    } else {

        if (mosse_i == 0) {
            if (re_nero_attaccato(game_used)) {
                return +99999; //ha perso
            }
            else {
                return 0;
            }
        }

        int bestMove = 99999;
        for (int i = 0; i < mosse_i; i++) {
            fai_mossa(game_used, mosse[i].da, mosse[i].a);
            int mmOVE = minimax(depth - 1, game_used);
            if (mmOVE < bestMove) {
                bestMove = mmOVE;
            }
            memcpy(game_used, game, MEM_GRANDEZZA_SC);
        }
        return bestMove;
    }
}

mossa minimaxRoot(int depth, int *game) {

    mossa mosse[400];
    int mosse_i = 0;

    int game_used[GRANDEZZA_SC];
    memcpy(game_used, game, MEM_GRANDEZZA_SC);

    mosse_i = mosse_legali(game_used, mosse, mosse_i);

    int bestMove = 0;

    if (game_used[turno] == turn_white) {
        bestMove = -99999;
    } else {
        bestMove = +99999;
    }
    mossa bestMoveFound;

    for(int i = 0; i < mosse_i; i++) {
        mossa newGameMove = mosse[i];
        fai_mossa(game_used, mosse[i].da, mosse[i].a);
        int value = minimax(depth - 1, game_used);

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

unsigned long int perft(int depth, int *game) {

    unsigned long int nodes = 0;

    int game_used[GRANDEZZA_SC];
    memcpy(game_used, game, MEM_GRANDEZZA_SC);

    if (depth == 0) {
        return 1;
    }

    mossa mosse[400];
    int mosse_i = 0;
    mosse_i = mosse_legali(game_used, mosse, mosse_i);

    for (int i = 0; i < mosse_i; i++) {
        fai_mossa(game_used, mosse[i].da, mosse[i].a);
        nodes += perft(depth - 1, game_used);
        memcpy(game_used, game, MEM_GRANDEZZA_SC);
    }
    return nodes;
}

void perftRoot(int depth, int *game) {

    mossa mosse[400];
    int mosse_i = 0;

    int game_used[GRANDEZZA_SC];
    memcpy(game_used, game, MEM_GRANDEZZA_SC);

    mosse_i = mosse_legali(game_used, mosse, mosse_i);

    char froms[3];
    char tos[3];

    int tot = 0;

    mossa newGameMove;

    for(int i = 0; i < mosse_i; i++) {
        newGameMove = mosse[i];
        fai_mossa(game_used, mosse[i].da, mosse[i].a);
        int value = perft(depth - 1, game_used);

        tot += value;

        if (newGameMove.a >= 21 && newGameMove.a <= 98) {
            printf("%s%s: %d\n", square_coordinate[newGameMove.da], square_coordinate[newGameMove.a], value);
        } else {
            printf("move from %s to %d nodes: %d\n", square_coordinate[newGameMove.da], newGameMove.a, value);
        }

        memcpy(game_used, game, MEM_GRANDEZZA_SC);
    }
    printf("\nNodes searched: %d\n", tot);
}