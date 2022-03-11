#include <stdio.h>
#include <string.h>

#include "pezzi.h"

#include "scacchiera.h"

//char pezzi_caratteri[14] = {'.', 'P', 'C', 'A', 'T', 'R', '#', 'p', 'c', 'a', 't', 'r', '@', '='};
char pezzi_caratteri[14][20] = {" ", "♟", "♞", "♝", "♜", "♛", "♚", "♙", "♘", "♗", "♖", "♕", "♔", "="};

char posizione_iniziale[] = {
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
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera
                };
char arrocco_iniziale[] = {1, 1, 1, 1};
char pezzi_iniziale[] = {
                        31, 32, 33, 34, 35, 36, 37, 38,
                        22, 27, 
                        23, 26, 
                        21, 28, 
                        24, 
                        25,

                        81, 82, 83, 84, 85, 86, 87, 88,
                        92, 97,
                        93, 96,
                        91, 98,
                        94,
                        95
                        }; //bianchi 8 pedoni 2 cavalli, 2 alfieri, 2 torri, regina, re neri ...

scacchiera scacchiera_0;
memcpy(scacchiera_0.sc, posizione_iniziale, 120);
memcpy(scacchiera_0.posizione_pezzi, pezzi_iniziale, 32);
memcpy(scacchiera_0.arrocco, arrocco_iniziale, 4);

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