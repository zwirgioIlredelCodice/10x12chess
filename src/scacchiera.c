#include <stdio.h>
#include <string.h>

#include "pezzi.h"

#include "scacchiera.h"

//char pezzi_caratteri[14] = {'.', 'P', 'C', 'A', 'T', 'R', '#', 'p', 'c', 'a', 't', 'r', '@', '='};
char pezzi_caratteri[14][20] = {" ", "♟", "♞", "♝", "♜", "♛", "♚", "♙", "♘", "♗", "♖", "♕", "♔", "="};

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