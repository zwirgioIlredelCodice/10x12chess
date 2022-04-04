#pragma once

#include <stdio.h>
#include <string.h>

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

1111 //arrocchi

21  22  23  24  25  26  27  28 
31  32  33  34  35  36  37  38 
41  42  43  44  45  46  47  48 
51  52  53  54  55  56  57  58 
61  62  63  64  65  66  67  68 
71  72  73  74  75  76  77  78 
81  82  83  84  85  86  87  88 
91  92  93  94  95  96  97  98 

*/

enum board_coordinate {
    a8 = 21, b8, c8, d8, e8, f8, g8, h8,
    a7 = 31, b7, c7, d7, e7, f7, g7, h7,
    a6 = 41, b6, c6, d6, e6, f6, g6, h6,
    a5 = 51, b5, c5, d5, e5, f5, g5, h5,
    a4 = 61, b4, c4, d4, e4, f4, g4, h4,
    a3 = 71, b3, c3, d3, e3, f3, g3, h3,
    a2 = 81, b2, c2, d2, e2, f2, g2, h2,
    a1 = 91, b1, c1, d1, e1, f1, g1, h1,
};

#define GRANDEZZA_SC 126 // 126 interi
#define MEM_GRANDEZZA_SC sizeof(int) * GRANDEZZA_SC // in byte

enum board_slot {
    arrocco_bdx = 120,
    arrocco_bsx,
    arrocco_ndx,
    arrocco_nsx,
    presa_al_varco,
    turno
};

enum turn {
    turn_black = 0,
    turn_white
};

// la scacchiera di partenza
extern int scacchiera_0[];
extern int empty_board[];
extern const char square_coordinate[][3];

//Regular background
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

#define reset "\e[0m"

extern char pezzi_caratteri[14][20];

void disegna_scacchiera(int *scacchiera);

void disegna_attacco(int *attacco);

int pos_lettere(char *c);

void fen_to_board(char fen_string[], int board[]);