#pragma once

#include <string.h>
#include "pezzi.h"


void fai_mossa(int *sc, int da, int a) {
    sc[a] = sc[da];
    sc[da] = vuoto;
}

int mosse_pedone_bianco(int *sc, int pos, int *mosse, int mosse_i) {
    int avanti_1 = pos - 10;
    int avanti_destra = pos - 9;
    int avanti_sinistra = pos - 11;

    if (sc[avanti_1] == vuoto) {
        mosse[mosse_i] = avanti_1;
        mosse_i++;
    }
    if (nero(sc[avanti_sinistra])) {
        mosse[mosse_i] = avanti_sinistra;
        mosse_i++;
    }
    if (nero(sc[avanti_destra])) {
        mosse[mosse_i] = avanti_destra;
        mosse_i++;
    }
    return mosse_i;
}

int mosse_pedone_nero(int *sc, int pos, int *mosse, int mosse_i) {
    int avanti_1 = pos + 10;
    int avanti_destra = pos + 11;
    int avanti_sinistra = pos + 9;

    if (sc[avanti_1] == vuoto) {
        mosse[mosse_i] = avanti_1;
        mosse_i++;
    }
    if (bianco(sc[avanti_sinistra])) {
        mosse[mosse_i] = avanti_sinistra;
        mosse_i++;
    }
    if (bianco(sc[avanti_destra])) {
        mosse[mosse_i] = avanti_destra;
        mosse_i++;
    }
    return mosse_i;
}

int mosse_cavallo_bianco(int *sc, int pos, int *mosse, int mosse_i) {
    int mosse_arr[8] = { -19, -21 , -12, -8, 19, 21 , 12, 8};
    int mossa;

    
    for (int i = 0; i < 8; i++) {
        mossa = pos + mosse_arr[i];
        if (sc[mossa] == vuoto || nero(sc[mossa])) {
                mosse[mosse_i] = mossa;
                mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_cavallo_nero(int *sc, int pos, int *mosse, int mosse_i) {
    int mosse_arr[8] = { -19, -21 , -12, -8, 19, 21 , 12, 8};
    int mossa;

    
    for (int i = 0; i < 8; i++) {
        mossa = pos + mosse_arr[i];
        if (sc[mossa] == vuoto || bianco(sc[mossa])) {
                mosse[mosse_i] = mossa;
                mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_alfiere_bianco(int *sc, int pos, int *mosse, int mosse_i) {
    int mosse_arr[4] = { -11, -9, 11, 9};
    int mossa;

    for (int i = 0; i < 4; i++) {

        mossa = pos;

        while(1) {
            mossa += mosse_arr[i];
            if (sc[mossa] == barriera || bianco(sc[mossa])) {
                break;
            }
            if (nero(sc[mossa])) {
                mosse[mosse_i] = mossa;
                mosse_i++;
                break;
            } 
            else {
                mosse[mosse_i] = mossa;
                mosse_i++;
            }
        }
    }
    return mosse_i;
}

int mosse_alfiere_nero(int *sc, int pos, int *mosse, int mosse_i) {
    int mosse_arr[4] = { -11, -9, 11, 9};
    int mossa;

    for (int i = 0; i < 4; i++) {

        mossa = pos;

        while(1) {
            mossa += mosse_arr[i];
            if (sc[mossa] == barriera || nero(sc[mossa])) {
                break;
            }
            if (bianco(sc[mossa])) {
                mosse[mosse_i] = mossa;
                mosse_i++;
                break;
            } 
            else {
                mosse[mosse_i] = mossa;
                mosse_i++;
            }
        }
    }
    return mosse_i;
}

int mosse_torre_bianca(int *sc, int pos, int *mosse, int mosse_i) {
    int mosse_arr[4] = { -10, -1, 10, 1};
    int mossa;

    for (int i = 0; i < 4; i++) {

        mossa = pos;

        while(1) {
            mossa += mosse_arr[i];
            if (sc[mossa] == barriera || bianco(sc[mossa])) {
                break;
            }
            if (nero(sc[mossa])) {
                mosse[mosse_i] = mossa;
                mosse_i++;
                break;
            } 
            else {
                mosse[mosse_i] = mossa;
                mosse_i++;
            }
        }
    }
    return mosse_i;
}

int mosse_torre_nera(int *sc, int pos, int *mosse, int mosse_i) {
    int mosse_arr[4] = { -10, -1, 10, 1};
    int mossa;

    for (int i = 0; i < 4; i++) {

        mossa = pos;

        while(1) {
            mossa += mosse_arr[i];
            if (sc[mossa] == barriera || nero(sc[mossa])) {
                break;
            }
            if (bianco(sc[mossa])) {
                mosse[mosse_i] = mossa;
                mosse_i++;
                break;
            } 
            else {
                mosse[mosse_i] = mossa;
                mosse_i++;
            }
        }
    }
    return mosse_i;
}

int mosse_regina_bianca(int *sc, int pos, int *mosse, int mosse_i) {
    mosse_i = mosse_torre_bianca(sc, pos, mosse, mosse_i);
    mosse_i = mosse_alfiere_bianco(sc, pos, mosse, mosse_i);
    return mosse_i;
}

int mosse_regina_nera(int *sc, int pos, int *mosse, int mosse_i) {
    mosse_i = mosse_torre_nera(sc, pos, mosse, mosse_i);
    mosse_i = mosse_alfiere_nero(sc, pos, mosse, mosse_i);
    return mosse_i;
}

int mosse_re_bianco(int *sc, int pos, int *mosse, int mosse_i) {
    int mosse_arr[8] = { -1, -9, -10, -11, 1, 11, 10, 9};
    int mossa;

    for (int i = 0; i < 8; i++) {
        mossa = pos + mosse_arr[i];
        if (sc[mossa] == vuoto || nero(sc[mossa])) {
            mosse[mosse_i] = mossa;
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_re_nero(int *sc, int pos, int *mosse, int mosse_i) {
    int mosse_arr[8] = { -1, -9, -10, -11, 1, 11, 10, 9};
    int mossa;

    for (int i = 0; i < 8; i++) {
        mossa = pos + mosse_arr[i];
        if (sc[mossa] == vuoto || bianco(sc[mossa])) {
            mosse[mosse_i] = mossa;
            mosse_i++;
        }
    }
    return mosse_i;
}

void attacco_bianchi(int *sc, int *attacco) { //prende un array scacchoera e in array attacco [120] che andra a popolare con calselle attaccate (0 non attaccate)
    int mosse[256]; //buffer per le mosse dei pezzi
    int mosse_i = 0;
    
    for (int i = 0; i < 120; i++) {
        switch (sc[i])
        {
        case pedone_b:
            mosse_i = mosse_pedone_bianco(sc, i, mosse, mosse_i);
            break;
        
        case cavallo_b:
            mosse_i = mosse_cavallo_bianco(sc, i, mosse, mosse_i);
            break;

        case alfiere_b:
            mosse_i = mosse_alfiere_bianco(sc, i, mosse, mosse_i);
            break;
        
        case torre_b:
            mosse_i = mosse_torre_bianca(sc, i, mosse, mosse_i);
            break;

        case regina_b:
            mosse_i = mosse_regina_bianca(sc, i, mosse, mosse_i);
            break;

        case re_b:
            mosse_i = mosse_re_bianco(sc, i, mosse, mosse_i);
            break;
        
        default:
            break;
        }
    }

    for (int i = 0; i < mosse_i; i++) {
        attacco[mosse[i]]++;
    }
}

void attacco_neri(int *sc, int *attacco) { //prende un array scacchoera e in array attacco [120] che andra a popolare con calselle attaccate (0 non attaccate)
    int mosse[256]; //buffer per le mosse dei pezzi
    int mosse_i = 0;
    
    for (int i = 0; i < 120; i++) {
        switch (sc[i])
        {
        case pedone_n:
            mosse_i = mosse_pedone_nero(sc, i, mosse, mosse_i);
            break;
        
        case cavallo_n:
            mosse_i = mosse_cavallo_nero(sc, i, mosse, mosse_i);
            break;

        case alfiere_n:
            mosse_i = mosse_alfiere_nero(sc, i, mosse, mosse_i);
            break;
        
        case torre_n:
            mosse_i = mosse_torre_nera(sc, i, mosse, mosse_i);
            break;

        case regina_n:
            mosse_i = mosse_regina_nera(sc, i, mosse, mosse_i);
            break;

        case re_n:
            mosse_i = mosse_re_nero(sc, i, mosse, mosse_i);
            break;
        
        default:
            break;
        }
    }

    for (int i = 0; i < mosse_i; i++) {
        attacco[mosse[i]]++;
    }
}

int mosse_re_bianco_l(int *sc, int pos, int *mosse, int mosse_i) {
    
    int attacco[120] = {0};
    attacco_neri(sc, attacco);

    int mosse_t[8]; 
    int mosse_i_t = 0;

    mosse_i_t = mosse_re_bianco(sc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (attacco[mosse_t[i]] == 0) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_re_nero_l(int *sc, int pos, int *mosse, int mosse_i) {
    
    int attacco[120] = {0};
    attacco_bianchi(sc, attacco);

    int mosse_t[8]; 
    int mosse_i_t = 0;

    mosse_i_t = mosse_re_nero(sc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (attacco[mosse_t[i]] == 0) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int re_bianco_attaccato(int sc[], int da, int a) {
    fai_mossa(sc, da, a);

    int attacco[120] = {0};
    attacco_neri(sc, attacco);

    //cerca il re
    int posizione_re;
    for (int i = 0; i < 120; i++) {
        if (sc[i] == re_b) {
            posizione_re = i;
            break;
        }  
    }

    //controlla che il re non sia attaccato
    if (attacco[posizione_re] == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

int re_nero_attaccato(int sc[], int da, int a) {
    fai_mossa(sc, da, a);

    int attacco[120] = {0};
    attacco_bianchi(sc, attacco);

    //cerca il re
    int posizione_re;
    for (int i = 0; i < 120; i++) {
        if (sc[i] == re_n) {
            posizione_re = i;
            break;
        }  
    }

    //controlla che il re non sia attaccato
    if (attacco[posizione_re] == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

int mosse_pedone_bianco_l(int *sc, int pos, int *mosse, int mosse_i) {
    int sc_t[120];
    memcpy(sc_t, sc, sizeof(int) * 120); //fa una copia della scacchiera così non cambia quando prova mosse

    int mosse_t[8]; 
    int mosse_i_t = 0;

    mosse_i_t = mosse_pedone_bianco(sc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_bianco_attaccato(sc_t, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_cavallo_bianco_l(int *sc, int pos, int *mosse, int mosse_i) {
    int sc_t[120];
    memcpy(sc_t, sc, sizeof(int) * 120); //fa una copia della scacchiera così non cambia quando prova mosse

    int mosse_t[8]; 
    int mosse_i_t = 0;

    mosse_i_t = mosse_cavallo_bianco(sc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_bianco_attaccato(sc_t, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_alfiere_bianco_l(int *sc, int pos, int *mosse, int mosse_i) {
    int sc_t[120];
    memcpy(sc_t, sc, sizeof(int) * 120); //fa una copia della scacchiera così non cambia quando prova mosse

    int mosse_t[20]; 
    int mosse_i_t = 0;

    mosse_i_t = mosse_alfiere_bianco(sc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_bianco_attaccato(sc_t, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_torre_bianca_l(int *sc, int pos, int *mosse, int mosse_i) {
    int sc_t[120];
    memcpy(sc_t, sc, sizeof(int) * 120); //fa una copia della scacchiera così non cambia quando prova mosse

    int mosse_t[20]; 
    int mosse_i_t = 0;

    mosse_i_t = mosse_torre_bianca(sc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_bianco_attaccato(sc_t, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_regina_bianca_l(int *sc, int pos, int *mosse, int mosse_i) {
    int sc_t[120];
    memcpy(sc_t, sc, sizeof(int) * 120); //fa una copia della scacchiera così non cambia quando prova mosse

    int mosse_t[20]; 
    int mosse_i_t = 0;

    mosse_i_t = mosse_regina_bianca(sc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_bianco_attaccato(sc_t, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_pedone_nero_l(int *sc, int pos, int *mosse, int mosse_i) {
    int sc_t[120];
    memcpy(sc_t, sc, sizeof(int) * 120); //fa una copia della scacchiera così non cambia quando prova mosse

    int mosse_t[8]; 
    int mosse_i_t = 0;

    mosse_i_t = mosse_pedone_nero(sc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_nero_attaccato(sc_t, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_cavallo_nero_l(int *sc, int pos, int *mosse, int mosse_i) {
    int sc_t[120];
    memcpy(sc_t, sc, sizeof(int) * 120); //fa una copia della scacchiera così non cambia quando prova mosse

    int mosse_t[8]; 
    int mosse_i_t = 0;

    mosse_i_t = mosse_cavallo_nero(sc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_nero_attaccato(sc_t, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_alfiere_nero_l(int *sc, int pos, int *mosse, int mosse_i) {
    int sc_t[120];
    memcpy(sc_t, sc, sizeof(int) * 120); //fa una copia della scacchiera così non cambia quando prova mosse

    int mosse_t[20]; 
    int mosse_i_t = 0;

    mosse_i_t = mosse_alfiere_nero(sc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_nero_attaccato(sc_t, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_torre_nera_l(int *sc, int pos, int *mosse, int mosse_i) {
    int sc_t[120];
    memcpy(sc_t, sc, sizeof(int) * 120); //fa una copia della scacchiera così non cambia quando prova mosse

    int mosse_t[20]; 
    int mosse_i_t = 0;

    mosse_i_t = mosse_torre_nera(sc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_nero_attaccato(sc_t, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_regina_nera_l(int *sc, int pos, int *mosse, int mosse_i) {
    int sc_t[120];
    memcpy(sc_t, sc, sizeof(int) * 120); //fa una copia della scacchiera così non cambia quando prova mosse

    int mosse_t[20]; 
    int mosse_i_t = 0;

    mosse_i_t = mosse_regina_nera(sc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_nero_attaccato(sc_t, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

typedef struct mossa {
    int da;
    int a;
} mossa;

int mosse_legali_biachi(int *sc, mossa *mosse_l, int mosse_i_l) {
    
    int mosse[256];
    int mosse_i = 0;
    
    for (int i = 0; i < 120; i++) {
        switch (sc[i]) {
        case pedone_b:
            mosse_i = mosse_pedone_bianco_l(sc, i, mosse, mosse_i);
            break;
        
        case cavallo_b:
            mosse_i = mosse_cavallo_bianco_l(sc, i, mosse, mosse_i);
            break;

        case alfiere_b:
            mosse_i = mosse_alfiere_bianco_l(sc, i, mosse, mosse_i);
            break;
        
        case torre_b:
            mosse_i = mosse_torre_bianca_l(sc, i, mosse, mosse_i);
            break;

        case regina_b:
            mosse_i = mosse_regina_bianca_l(sc, i, mosse, mosse_i);
            break;

        case re_b:
            mosse_i = mosse_re_bianco_l(sc, i, mosse, mosse_i);
            break;
        
        default:
            break;
        }
        for (int ii = 0; ii < mosse_i; ii++) {
            mosse_l[mosse_i_l].da = i;
            mosse_l[mosse_i_l].a = mosse[ii];
            mosse_i_l++;
        }
        mosse_i = 0;
    }
    return mosse_i_l;
}

int mosse_legali_neri(int *sc, mossa *mosse_l, int mosse_i_l) {
    
    int mosse[256];
    int mosse_i = 0;
    
    for (int i = 0; i < 120; i++) {
        switch (sc[i])
        {
        case pedone_n:
            mosse_i = mosse_pedone_nero_l(sc, i, mosse, mosse_i);
            break;
        
        case cavallo_n:
            mosse_i = mosse_cavallo_nero_l(sc, i, mosse, mosse_i);
            break;

        case alfiere_n:
            mosse_i = mosse_alfiere_nero_l(sc, i, mosse, mosse_i);
            break;
        
        case torre_n:
            mosse_i = mosse_torre_nera_l(sc, i, mosse, mosse_i);
            break;

        case regina_n:
            mosse_i = mosse_regina_nera_l(sc, i, mosse, mosse_i);
            break;

        case re_n:
            mosse_i = mosse_re_nero_l(sc, i, mosse, mosse_i);
            break;
        
        default:
            break;
        }
        for (int ii = 0; ii < mosse_i; ii++) {
            mosse_l[mosse_i_l].da = i;
            mosse_l[mosse_i_l].a = mosse[ii];
            mosse_i_l++;
        }
        mosse_i = 0;
    }
    return mosse_i_l;
}