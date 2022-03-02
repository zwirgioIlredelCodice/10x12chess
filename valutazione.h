#pragma once

#include "pezzi.h"

int valuta_posizione(int *sc) {
    int val = 0;
    for (int i = 0; i < 120; i++) {
        switch (sc[i]) {
            case pedone_b:
                val += 10;
                break;
        
            case cavallo_b:
                val += 30;
                break;

            case alfiere_b:
                val += 30;
                break;
        
            case torre_b:
                val += 50;
                break;

            case regina_b:
                val += 90;
                break;

            case re_b:
                val += 900;
                break;

            case pedone_n:
                val -= 10;
                break;
        
            case cavallo_n:
                val -= 30;
                break;

            case alfiere_n:
                val -= 30;
                break;
        
            case torre_n:
                val -= 50;
                break;

            case regina_n:
                val -= 90;
                break;

            case re_n:
                val -= 900;
                break;
        
            default:
                break;
        }
    }
    return val;
}