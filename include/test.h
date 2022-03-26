#pragma once

#include "pezzi.h"
#include "mosse.h"
/*
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
*/

int test_vuoto[] = {
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    barriera, vuoto,    vuoto,    vuoto,     re_n,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    pedone_n,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    pedone_b,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,     re_b,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    NO_ARROCCO, NO_ARROCCO, NO_ARROCCO, NO_ARROCCO, NO_PRESA_AL_VARCO //arrocco bdx bsx ndx nsx
                };

int test1[] = {
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    barriera, torre_n, cavallo_n, alfiere_n, regina_n, re_n, alfiere_n, cavallo_n, torre_n, barriera,
                    barriera, pedone_n, torre_n, pedone_n, pedone_n,  vuoto, pedone_n, pedone_n, pedone_n, barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    pedone_n,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    regina_n,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, pedone_b, vuoto, pedone_b, pedone_b, pedone_b, pedone_b, pedone_b, pedone_b, barriera,
                    barriera, torre_b, vuoto, vuoto, vuoto, re_b,    vuoto,  vuoto, torre_b, barriera,
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    SI_ARROCCO, SI_ARROCCO, SI_ARROCCO, SI_ARROCCO, NO_PRESA_AL_VARCO//arrocco bdx bsx ndx nsx
            };

int test_pro[] = {
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    barriera, torre_n, cavallo_n, alfiere_n, regina_n, re_n, alfiere_n, cavallo_n, torre_n, barriera,
                    barriera, pedone_n, torre_n, pedone_n, pedone_n,  vuoto, pedone_n, pedone_n, pedone_n, barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    pedone_n,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    regina_n,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, pedone_n, vuoto, pedone_n, vuoto, vuoto, vuoto, vuoto, vuoto, vuoto,
                    barriera, vuoto,    vuoto,    vuoto, torre_b, torre_b,    re_b,  vuoto, vuoto, barriera,
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    NO_ARROCCO, NO_ARROCCO, NO_ARROCCO, NO_ARROCCO, NO_PRESA_AL_VARCO//arrocco bdx bsx ndx nsx
            };

int test_varco[] = {
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    barriera, torre_n, cavallo_n, alfiere_n, regina_n, re_n, alfiere_n, cavallo_n, torre_n, barriera,
                    barriera, pedone_n, torre_n, pedone_n, pedone_n,  vuoto, pedone_n, pedone_n, pedone_n, barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    pedone_n,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    regina_n,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    vuoto,    barriera,
                    barriera, pedone_n, vuoto, pedone_n, vuoto, vuoto, vuoto, vuoto, vuoto, vuoto,
                    barriera, vuoto,    vuoto,    vuoto, torre_b, torre_b,    re_b,  vuoto, vuoto, barriera,
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera, barriera,
                    NO_ARROCCO, NO_ARROCCO, NO_ARROCCO, NO_ARROCCO, NO_PRESA_AL_VARCO//arrocco bdx bsx ndx nsx
            };