#include <stdio.h>
#include <string.h>

#include "pezzi.h"

#include "scacchiera.h"
#include "mosse.h"

//char pezzi_caratteri[14] = {'.', 'P', 'C', 'A', 'T', 'R', '#', 'p', 'c', 'a', 't', 'r', '@', '='};
char pezzi_caratteri[14][20] = {" ", "♟", "♞", "♝", "♜", "♛", "♚", "♙", "♘", "♗", "♖", "♕", "♔", "="};

const char square_coordinate[][3] = {
    "##", "##", "##", "##", "##", "##", "##", "##", "##", "##",
    "##", "##", "##", "##", "##", "##", "##", "##", "##", "##",
    "##", "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8", "##",
    "##", "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7", "##",
    "##", "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6", "##",
    "##", "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5", "##",
    "##", "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4", "##",
    "##", "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3", "##",
    "##", "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2", "##",
    "##", "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1", "##",
    "##", "##", "##", "##", "##", "##", "##", "##", "##", "##",
    "##", "##", "##", "##", "##", "##", "##", "##", "##", "##",
};

int scacchiera_0[GRANDEZZA_SC] = {
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    barriera, torre_n, cavallo_n, alfiere_n, regina_n, re_n, alfiere_n, cavallo_n, torre_n, barriera,
                    barriera, pedone_n, pedone_n, pedone_n, pedone_n, pedone_n, pedone_n, pedone_n, pedone_n, barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, pedone_b, pedone_b, pedone_b, pedone_b, pedone_b, pedone_b, pedone_b, pedone_b, barriera,
                    barriera, torre_b, cavallo_b, alfiere_b, regina_b, re_b, alfiere_b, cavallo_b, torre_b, barriera,
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    SI_ARROCCO, SI_ARROCCO, SI_ARROCCO, SI_ARROCCO, NO_PRESA_AL_VARCO, turn_white //arrocco bdx bsx ndx nsx
                };

int empty_board[GRANDEZZA_SC] = {
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    NO_ARROCCO, NO_ARROCCO, NO_ARROCCO, NO_ARROCCO, NO_PRESA_AL_VARCO, turn_white
                };

void disegna_scacchiera(int *scacchiera) {
    int numeri = 8;
    int sfaso = 1;
    printf("\n%d| ", numeri--);

    for (int i = 21; i <= 98; i++) {
        if ((i % 10) == 0) {
            sfaso++;
            printf("\n%d| ", numeri--);
        }
        if ((i + sfaso) % 2 == 0) {
            printf(GRNB);
        }

        if (strcmp(pezzi_caratteri[scacchiera[i]], "=") != 0){
            printf("%s ", pezzi_caratteri[scacchiera[i]]);
        }

        printf(reset);
    }
    printf("\n  ");

    for (int i = 1; i < 9; i++) {
        printf("--");
    }
    printf("\n   ");
    for (char i = 'A'; i <= 'H'; i++) {
        printf("%c ", i);
    }

    printf("\narrocchi %d %d %d %d ", scacchiera[arrocco_bdx], scacchiera[arrocco_bsx], scacchiera[arrocco_ndx], scacchiera[arrocco_nsx]);
    printf("\npresa al varco %d", scacchiera[presa_al_varco]);
    printf("\n");
}

void disegna_attacco(int *attacco) {
    for (int i = 0; i < 120; i++) {
        if ((i % 10) == 0) {
            printf("\n");
        }
        if (attacco[i] == 0) {
            printf(". ");
        }
        else {
            printf("%d ", attacco[i]);
        }
    }
    printf("\n");
}

int pos_lettere(char *c) {
    int pos = (90 - (c[1] - '1' + 2) * 10) + (c[0] - 'a' + 1) + 20;
    return pos;
}

enum fen_state {
    piece_placement,
    color,
    castling,
    en_passant,
    halfmove,
    fullmove
};

enum color_pice {
    white,
    black
};

void fen_to_board(char fen_string[], int board[]) {
    memcpy(board, empty_board, MEM_GRANDEZZA_SC); //reset the board

    char c = ' ';
    enum fen_state state = piece_placement;
    int pos_in_board = 21;
    int color_to_move = white;

    for (int i = 0; fen_string[i] != '\0'; i++) {
        c = fen_string[i];
        if (c == ' ' || c == '-') { //go to the next state
            state++;
            continue;
        }

        switch (state)
        {
        case piece_placement:
            if (c == 'p') {
                board[pos_in_board] = pedone_n;
                pos_in_board++;
            }
            else if (c == 'n') {
                board[pos_in_board] = cavallo_n;
                pos_in_board++;
            }
            else if (c == 'b') {
                board[pos_in_board] = alfiere_n;
                pos_in_board++;
            }
            else if (c == 'r') {
                board[pos_in_board] = torre_n;
                pos_in_board++;
            }
            else if (c == 'q') {
                board[pos_in_board] = regina_n;
                pos_in_board++;
            }
            else if (c == 'k') {
                board[pos_in_board] = re_n;
                pos_in_board++;
            }
            if (c == 'P') {
                board[pos_in_board] = pedone_b;
                pos_in_board++;
            }
            else if (c == 'N') {
                board[pos_in_board] = cavallo_b;
                pos_in_board++;
            }
            else if (c == 'B') {
                board[pos_in_board] = alfiere_b;
                pos_in_board++;
            }
            else if (c == 'R') {
                board[pos_in_board] = torre_b;
                pos_in_board++;
            }
            else if (c == 'Q') {
                board[pos_in_board] = regina_b;
                pos_in_board++;
            }
            else if (c == 'K') {
                board[pos_in_board] = re_b;
                pos_in_board++;
            }

            else if (c == '/') {
                pos_in_board += 2;
            }

            else if (c >= '1' && c <= '8') {
                pos_in_board += (c - '0');
            }

            break;
        
        case color:
            if (c == 'w') {
                board[turno] = turn_white;
            }
            else if (c == 'b') {
                board[turno] = turn_black;
            }
            break;

        case castling:
            if (c == 'K') {
                board[arrocco_bdx] = SI_ARROCCO;
            }
            else if (c == 'Q') {
                board[arrocco_bsx] = SI_ARROCCO;
            }
            else if (c == 'k') {
                board[arrocco_ndx] = SI_ARROCCO;
            }
            else if (c == 'q') {
                board[arrocco_nsx] = SI_ARROCCO;
            }
            break;
        
        case en_passant:
            ;
            int nn = pos_lettere(fen_string + i);
            board[presa_al_varco] = nn;
            state++;
            i++; //skip one char because use 2 char
            break;
        
        case halfmove:
            /* code */
            break;
        
        case fullmove:
            /* code */
            break;
        
        default:
            break;
        }
    }
}