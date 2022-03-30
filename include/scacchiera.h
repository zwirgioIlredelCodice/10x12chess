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

#define GRANDEZZA_SC 125 // 124 interi
#define MEM_GRANDEZZA_SC sizeof(int) * GRANDEZZA_SC // in byte

#define arrocco_bdx 120
#define arrocco_bsx 121
#define arrocco_ndx 122
#define arrocco_nsx 123

#define presa_al_varco 124

// la scacchiera di partenza
extern int scacchiera_0[];
extern int empty_board[];

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