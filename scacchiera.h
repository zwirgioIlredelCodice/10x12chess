#pragma once

#include <stdio.h>

#include "pezzi.h"

/*
10 * 12
= = = = = = = = = = 
= = = = = = = = = = 
= T C A R # A C T = 
= P P P P P P P P = 
=                 = 
=                 = 
=                 = 
=                 = 
= p p p p p p p p = 
= t c a r @ a c t = 
= = = = = = = = = = 
= = = = = = = = = = 

0   1   2   3   4   5   6   7   8   9 
10  11  12  13  14  15  16  17  18  19 
20  21  22  23  24  25  26  27  28  29 
30  31  32  33  34  35  36  37  38  39 
40  41  42  43  44  45  46  47  48  49 
50  51  52  53  54  55  56  57  58  59 
60  61  62  63  64  65  66  67  68  69 
70  71  72  73  74  75  76  77  78  79 
80  81  82  83  84  85  86  87  88  89 
90  91  92  93  94  95  96  97  98  99 
100 101 102 103 104 105 106 107 108 109 
110 111 112 113 114 115 116 117 118 119

21  22  23  24  25  26  27  28 
31  32  33  34  35  36  37  38 
41  42  43  44  45  46  47  48 
51  52  53  54  55  56  57  58 
61  62  63  64  65  66  67  68 
71  72  73  74  75  76  77  78 
81  82  83  84  85  86  87  88 
91  92  93  94  95  96  97  98 

*/


// la scacchiera di partenza
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
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera
                };

char pezzi_caratteri[14] = {'.', 'P', 'C', 'A', 'T', 'R', '#', 'p', 'c', 'a', 't', 'r', '@', '='};
//char pezzi_caratteri[14] = {'.', '♟', '♞', '♝', '♜', '♛', '♚', '♙', '♘', '♗', '♖', '♕', '♔', '='};

void disegna_scacchiera(int *scacchiera) {
    int numeri = 8;
    printf("\n%d| ", numeri--);

    for (int i = 21; i <= 98; i++) {
        if ((i % 10) == 0) {
            printf("\n%d| ", numeri--);
        }
        if (pezzi_caratteri[scacchiera[i]] != '='){
            printf("%c ", pezzi_caratteri[scacchiera[i]]);
        }
    }
    printf("\n  ");

    for (int i = 1; i < 9; i++) {
        printf("--");
    }
    printf("\n  ");
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