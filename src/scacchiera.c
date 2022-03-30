#include <stdio.h>
#include <string.h>

#include "pezzi.h"

#include "scacchiera.h"
#include "mosse.h"

//char pezzi_caratteri[14] = {'.', 'P', 'C', 'A', 'T', 'R', '#', 'p', 'c', 'a', 't', 'r', '@', '='};
char pezzi_caratteri[14][20] = {" ", "♟", "♞", "♝", "♜", "♛", "♚", "♙", "♘", "♗", "♖", "♕", "♔", "="};

int scacchiera_0[] = {
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
                    SI_ARROCCO, SI_ARROCCO, SI_ARROCCO, SI_ARROCCO, NO_PRESA_AL_VARCO //arrocco bdx bsx ndx nsx
                };

int empty_board[] = {
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
                    NO_ARROCCO, NO_ARROCCO, NO_ARROCCO, NO_ARROCCO, NO_PRESA_AL_VARCO
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
                color_to_move = white;
            }
            else if (c == 'b') {
                color_to_move = black;
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
            int pos = (90 - (fen_string[i+1] - '1' + 2) * 10) + (fen_string[i] - 'a' + 1) + 20;
            i++; //skip one char because use 2 char

            board[presa_al_varco] = pos;
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