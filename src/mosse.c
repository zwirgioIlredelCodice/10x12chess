#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "pezzi.h"
#include "mosse.h"
#include "scacchiera.h"


void fai_mossa(scacchiera *scc, unsigned char da, unsigned char a) { //--------------------------da riguardare
    
    for (int i = 0; i < 32; i++) {           //aggiorna la posizione dei pezzi
        if (scc->posizione_pezzi[i] == da) {
            scc->posizione_pezzi[i] = a;
            break;
        }
    }
    for (int i = 0; i < 32; i++) {           //aggiorna la posizione dei pezzi
        if (scc->posizione_pezzi[i] == a) {
            scc->posizione_pezzi[i] = 0;
            break;
        }
    }
    scc->posizione_pezzi[a] = scc->posizione_pezzi[da];
    scc->posizione_pezzi[da] = vuoto;

}

int mosse_pedone_bianco(scacchiera *scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    unsigned char avanti_1 = pos - 10;
    unsigned char avanti_destra = pos - 9;
    unsigned char avanti_sinistra = pos - 11;
    unsigned char avanti_2 = pos - 20;

    if (scc->sc[avanti_1] == vuoto) {
        mosse[mosse_i] = avanti_1;
        mosse_i++;
    }
    if (nero(scc->sc[avanti_sinistra])) {
        mosse[mosse_i] = avanti_sinistra;
        mosse_i++;
    }
    if (nero(scc->sc[avanti_destra])) {
        mosse[mosse_i] = avanti_destra;
        mosse_i++;
    }
    if(scc->sc[avanti_1] == vuoto && scc->sc[avanti_2] == vuoto && (pos > 30 && pos < 39)) {
            mosse[mosse_i] = avanti_2;
            mosse_i++;
    }
    return mosse_i;
}

int mosse_pedone_nero(scacchiera *scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    unsigned char avanti_1 = pos + 10;
    unsigned char avanti_destra = pos + 11;
    unsigned char avanti_sinistra = pos + 9;
    unsigned char avanti_2 = pos + 20;

    if (scc->sc[avanti_1] == vuoto) {
        mosse[mosse_i] = avanti_1;
        mosse_i++;
    }
    if (bianco(scc->sc[avanti_sinistra])) {
        mosse[mosse_i] = avanti_sinistra;
        mosse_i++;
    }
    if (bianco(scc->sc[avanti_destra])) {
        mosse[mosse_i] = avanti_destra;
        mosse_i++;
    }
    if(scc->sc[avanti_1] == vuoto && scc->sc[avanti_2] == vuoto && (pos > 80 && pos < 89)) {
            mosse[mosse_i] = avanti_2;
            mosse_i++;
    }
    return mosse_i;
}

int mosse_cavallo_bianco(scacchiera *scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    unsigned char mosse_arr[8] = { -19, -21 , -12, -8, 19, 21 , 12, 8};
    unsigned char mossa;

    
    for (int i = 0; i < 8; i++) {
        mossa = pos + mosse_arr[i];
        if (scc->sc[mossa] == vuoto || nero(scc->sc[mossa])) {
                mosse[mosse_i] = mossa;
                mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_cavallo_nero(scacchiera *scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    unsigned char mosse_arr[8] = { -19, -21 , -12, -8, 19, 21 , 12, 8};
    unsigned char mossa;

    
    for (int i = 0; i < 8; i++) {
        mossa = pos + mosse_arr[i];
        if (scc->sc[mossa] == vuoto || bianco(scc->sc[mossa])) {
                mosse[mosse_i] = mossa;
                mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_alfiere_bianco(scacchiera *scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    unsigned char mosse_arr[4] = { -11, -9, 11, 9};
    unsigned char mossa;

    for (int i = 0; i < 4; i++) {

        mossa = pos;

        while(1) {
            mossa += mosse_arr[i];
            if (scc->sc[mossa] == barriera || bianco(scc->sc[mossa])) {
                break;
            }
            if (nero(scc->sc[mossa])) {
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

int mosse_alfiere_nero(scacchiera *scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    unsigned char mosse_arr[4] = { -11, -9, 11, 9};
    unsigned char mossa;

    for (int i = 0; i < 4; i++) {

        mossa = pos;

        while(1) {
            mossa += mosse_arr[i];
            if (scc->sc[mossa] == barriera || nero(scc->sc[mossa])) {
                break;
            }
            if (bianco(scc->sc[mossa])) {
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

int mosse_torre_bianca(scacchiera *scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    unsigned char mosse_arr[4] = { -10, -1, 10, 1};
    unsigned char mossa;

    for (int i = 0; i < 4; i++) {

        mossa = pos;

        while(1) {
            mossa += mosse_arr[i];
            if (scc->sc[mossa] == barriera || bianco(scc->sc[mossa])) {
                break;
            }
            if (nero(scc->sc[mossa])) {
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

int mosse_torre_nera(scacchiera *scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    unsigned char mosse_arr[4] = { -10, -1, 10, 1};
    unsigned char mossa;

    for (int i = 0; i < 4; i++) {

        mossa = pos;

        while(1) {
            mossa += mosse_arr[i];
            if (scc->sc[mossa] == barriera || nero(scc->sc[mossa])) {
                break;
            }
            if (bianco(scc->sc[mossa])) {
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

int mosse_regina_bianca(scacchiera *scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    mosse_i = mosse_torre_bianca(scc, pos, mosse, mosse_i);
    mosse_i = mosse_alfiere_bianco(scc, pos, mosse, mosse_i);
    return mosse_i;
}

int mosse_regina_nera(scacchiera *scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    mosse_i = mosse_torre_nera(scc, pos, mosse, mosse_i);
    mosse_i = mosse_alfiere_nero(scc, pos, mosse, mosse_i);
    return mosse_i;
}

int mosse_re_bianco(scacchiera *scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    unsigned char mosse_arr[8] = { -1, -9, -10, -11, 1, 11, 10, 9};
    unsigned char mossa;

    for (int i = 0; i < 8; i++) {
        mossa = pos + mosse_arr[i];
        if (scc->sc[mossa] == vuoto || nero(scc->sc[mossa])) {
            mosse[mosse_i] = mossa;
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_re_nero(scacchiera *scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    unsigned char mosse_arr[8] = { -1, -9, -10, -11, 1, 11, 10, 9};
    unsigned char mossa;

    for (int i = 0; i < 8; i++) {
        mossa = pos + mosse_arr[i];
        if (scc->sc[mossa] == vuoto || bianco(scc->sc[mossa])) {
            mosse[mosse_i] = mossa;
            mosse_i++;
        }
    }
    return mosse_i;
}

void attacco_bianchi(scacchiera *scc, unsigned char *attacco) { //prende un array scacchoera e in array attacco [120] che andra a popolare con calselle attaccate (0 non attaccate)
    unsigned char mosse[256]; //buffer per le mosse dei pezzi
    int mosse_i = 0;


    for (int i = 0; i < 8; i++) { //pedoni
        if (scc->posizione_pezzi[i] != 0) {
            mosse_i = mosse_pedone_bianco(scc, scc->posizione_pezzi[i], mosse, mosse_i);
        }
    }

    //cavalli
    if (scc->posizione_pezzi[8] != 0) {
        mosse_i = mosse_cavallo_bianco(scc, scc->posizione_pezzi[8], mosse, mosse_i);
    }
    if (scc->posizione_pezzi[9] != 0) {
        mosse_i = mosse_cavallo_bianco(scc, scc->posizione_pezzi[9], mosse, mosse_i);
    }

    //alfieri
    if (scc->posizione_pezzi[10] != 0) {
        mosse_i = mosse_alfiere_bianco(scc, scc->posizione_pezzi[10], mosse, mosse_i);
    }
    if (scc->posizione_pezzi[11] != 0) {
        mosse_i = mosse_alfiere_bianco(scc, scc->posizione_pezzi[11], mosse, mosse_i);
    }

    //torri
    if (scc->posizione_pezzi[12] != 0) {
        mosse_i = mosse_alfiere_bianco(scc, scc->posizione_pezzi[12], mosse, mosse_i);
    }
    if (scc->posizione_pezzi[13] != 0) {
        mosse_i = mosse_alfiere_bianco(scc, scc->posizione_pezzi[13], mosse, mosse_i);
    }

    //regina
    if (scc->posizione_pezzi[14] != 0) {
        mosse_i = mosse_regina_bianca(scc, scc->posizione_pezzi[14], mosse, mosse_i);
    }

    //re
    if (scc->posizione_pezzi[15] != 0) {
        mosse_i = mosse_re_bianco(scc, scc->posizione_pezzi[15], mosse, mosse_i);
    }

    for (int i = 0; i < mosse_i; i++) {
        attacco[mosse[i]]++;
    }
}

void attacco_neri(scacchiera *scc, unsigned char *attacco) { //prende un array scacchoera e in array attacco [120] che andra a popolare con calselle attaccate (0 non attaccate)
    unsigned char mosse[256]; //buffer per le mosse dei pezzi
    int mosse_i = 0;
    
    for (int i = 16; i < 24; i++) { //pedoni
        if (scc->posizione_pezzi[i] != 0) {
            mosse_i = mosse_pedone_nero(scc, scc->posizione_pezzi[i], mosse, mosse_i);
        }
    }

    //cavalli
    if (scc->posizione_pezzi[24] != 0) {
        mosse_i = mosse_cavallo_nero(scc, scc->posizione_pezzi[24], mosse, mosse_i);
    }
    if (scc->posizione_pezzi[25] != 0) {
        mosse_i = mosse_cavallo_nero(scc, scc->posizione_pezzi[25], mosse, mosse_i);
    }

    //alfieri
    if (scc->posizione_pezzi[26] != 0) {
        mosse_i = mosse_alfiere_nero(scc, scc->posizione_pezzi[26], mosse, mosse_i);
    }
    if (scc->posizione_pezzi[27] != 0) {
        mosse_i = mosse_alfiere_nero(scc, scc->posizione_pezzi[27], mosse, mosse_i);
    }

    //torri
    if (scc->posizione_pezzi[28] != 0) {
        mosse_i = mosse_alfiere_nero(scc, scc->posizione_pezzi[28], mosse, mosse_i);
    }
    if (scc->posizione_pezzi[29] != 0) {
        mosse_i = mosse_alfiere_nero(scc, scc->posizione_pezzi[29], mosse, mosse_i);
    }

    //regina
    if (scc->posizione_pezzi[30] != 0) {
        mosse_i = mosse_regina_nera(scc, scc->posizione_pezzi[30], mosse, mosse_i);
    }

    //re
    if (scc->posizione_pezzi[31] != 0) {
        mosse_i = mosse_re_nero(scc, scc->posizione_pezzi[31], mosse, mosse_i);
    }

    for (int i = 0; i < mosse_i; i++) {
        attacco[mosse[i]]++;
    }
}

int re_bianco_attaccato(scacchiera *scc) {
    unsigned char attacco[120] = {0};
    attacco_neri(scc, attacco);

    //cerca il re
    unsigned char posizione_re = scc->posizione_pezzi[15];

    assert(posizione_re != 0);

    //controlla che il re non sia attaccato
    if (attacco[posizione_re] == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

int re_bianco_attaccato_mossa(scacchiera scc, unsigned char da, unsigned char a) { //----------------forse non funzia
    fai_mossa(&scc, da, a);
    return re_bianco_attaccato(&scc);
}

int re_nero_attaccato(scacchiera *scc) {
    unsigned char attacco[120] = {0};
    attacco_neri(scc, attacco);

    //cerca il re
    unsigned char posizione_re = scc->posizione_pezzi[31];

    assert(posizione_re != 0);

    //controlla che il re non sia attaccato
    if (attacco[posizione_re] == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

int re_nero_attaccato_mossa(scacchiera scc, unsigned char da, unsigned char a) {
    fai_mossa(&scc, da, a);
    return re_nero_attaccato(&scc);
}

int mosse_re_bianco_l(scacchiera scc, unsigned char pos, unsigned char *mosse, int mosse_i) {

    unsigned char mosse_t[8]; 
    unsigned char mosse_i_t = 0;

    mosse_i_t = mosse_re_bianco(&scc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_bianco_attaccato_mossa(scc, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_re_nero_l(scacchiera scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    
    unsigned char mosse_t[8]; 
    unsigned char mosse_i_t = 0;

    mosse_i_t = mosse_re_nero(&scc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_bianco_attaccato_mossa(scc, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_pedone_bianco_l(scacchiera scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    
    unsigned char mosse_t[8]; 
    unsigned char mosse_i_t = 0;

    mosse_i_t = mosse_pedone_bianco(&scc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_bianco_attaccato_mossa(scc, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_cavallo_bianco_l(scacchiera scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    
    unsigned char mosse_t[8]; 
    unsigned char mosse_i_t = 0;

    mosse_i_t = mosse_cavallo_bianco(&scc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_bianco_attaccato_mossa(scc, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_alfiere_bianco_l(scacchiera scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    
    unsigned char mosse_t[8]; 
    unsigned char mosse_i_t = 0;

    mosse_i_t = mosse_alfiere_bianco(&scc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_bianco_attaccato_mossa(scc, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_torre_bianca_l(scacchiera scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    
    unsigned char mosse_t[8]; 
    unsigned char mosse_i_t = 0;

    mosse_i_t = mosse_torre_bianca(&scc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_bianco_attaccato_mossa(scc, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_regina_bianca_l(scacchiera scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    
    unsigned char mosse_t[8]; 
    unsigned char mosse_i_t = 0;

    mosse_i_t = mosse_regina_bianca(&scc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_bianco_attaccato_mossa(scc, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_pedone_nero_l(scacchiera scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    
    unsigned char mosse_t[8]; 
    unsigned char mosse_i_t = 0;

    mosse_i_t = mosse_pedone_nero(&scc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_nero_attaccato_mossa(scc, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_cavallo_nero_l(scacchiera scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    
    unsigned char mosse_t[8]; 
    unsigned char mosse_i_t = 0;

    mosse_i_t = mosse_cavallo_nero(&scc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_nero_attaccato_mossa(scc, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_alfiere_nero_l(scacchiera scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    
    unsigned char mosse_t[8]; 
    unsigned char mosse_i_t = 0;

    mosse_i_t = mosse_alfiere_nero(&scc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_nero_attaccato_mossa(scc, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_torre_nera_l(scacchiera scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    
    unsigned char mosse_t[8]; 
    unsigned char mosse_i_t = 0;

    mosse_i_t = mosse_torre_nera(&scc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_nero_attaccato_mossa(scc, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_regina_nera_l(scacchiera scc, unsigned char pos, unsigned char *mosse, int mosse_i) {
    
    unsigned char mosse_t[8]; 
    unsigned char mosse_i_t = 0;

    mosse_i_t = mosse_regina_nera(&scc, pos, mosse_t, mosse_i_t);

    for (int i = 0; i < mosse_i_t; i++) {
        if (!re_nero_attaccato_mossa(scc, pos, mosse_t[i])) {
            mosse[mosse_i] = mosse_t[i];
            mosse_i++;
        }
    }
    return mosse_i;
}

int mosse_legali_biachi(scacchiera scc, mossa *mosse_l, int mosse_i_l) {
    
    unsigned char mosse[256]; //buffer per le mosse dei pezzi
    int mosse_i = 0;


    for (int i = 0; i < 8; i++) { //pedoni
        mosse_i = 0;
        if (scc.posizione_pezzi[i] != 0) {
            mosse_i = mosse_pedone_bianco_l(scc, scc.posizione_pezzi[i], mosse, mosse_i);
            
            for (int ii = 0; ii < mosse_i; ii++) {
                mosse_l[mosse_i_l].da = scc.posizione_pezzi[i];
                mosse_l[mosse_i_l].a = mosse[ii];
                mosse_i_l++;
            }
        }
    }

    //cavalli
    mosse_i = 0;
    if (scc.posizione_pezzi[8] != 0) {
        mosse_i = mosse_cavallo_bianco_l(scc, scc.posizione_pezzi[8], mosse, mosse_i);

        for (int ii = 0; ii < mosse_i; ii++) {
            mosse_l[mosse_i_l].da = scc.posizione_pezzi[8];
            mosse_l[mosse_i_l].a = mosse[ii];
            mosse_i_l++;
        }
    }
    mosse_i = 0;
    if (scc.posizione_pezzi[9] != 0) {
        mosse_i = mosse_cavallo_bianco_l(scc, scc.posizione_pezzi[9], mosse, mosse_i);

        for (int ii = 0; ii < mosse_i; ii++) {
            mosse_l[mosse_i_l].da = scc.posizione_pezzi[9];
            mosse_l[mosse_i_l].a = mosse[ii];
            mosse_i_l++;
        }
    }

    //alfieri
    mosse_i = 0;
    if (scc.posizione_pezzi[10] != 0) {
        mosse_i = mosse_alfiere_bianco_l(scc, scc.posizione_pezzi[10], mosse, mosse_i);

        for (int ii = 0; ii < mosse_i; ii++) {
            mosse_l[mosse_i_l].da = scc.posizione_pezzi[10];
            mosse_l[mosse_i_l].a = mosse[ii];
            mosse_i_l++;
        }
    }
    mosse_i = 0;
    if (scc.posizione_pezzi[11] != 0) {
        mosse_i = mosse_alfiere_bianco_l(scc, scc.posizione_pezzi[11], mosse, mosse_i);

        for (int ii = 0; ii < mosse_i; ii++) {
            mosse_l[mosse_i_l].da = scc.posizione_pezzi[11];
            mosse_l[mosse_i_l].a = mosse[ii];
            mosse_i_l++;
        }
    }

    //torri
    mosse_i = 0;
    if (scc.posizione_pezzi[12] != 0) {
        mosse_i = mosse_alfiere_bianco_l(scc, scc.posizione_pezzi[12], mosse, mosse_i);

        for (int ii = 0; ii < mosse_i; ii++) {
            mosse_l[mosse_i_l].da = scc.posizione_pezzi[12];
            mosse_l[mosse_i_l].a = mosse[ii];
            mosse_i_l++;
        }
    }
    mosse_i = 0;
    if (scc.posizione_pezzi[13] != 0) {
        mosse_i = mosse_alfiere_bianco_l(scc, scc.posizione_pezzi[13], mosse, mosse_i);

        for (int ii = 0; ii < mosse_i; ii++) {
            mosse_l[mosse_i_l].da = scc.posizione_pezzi[13];
            mosse_l[mosse_i_l].a = mosse[ii];
            mosse_i_l++;
        }
    }

    //regina
    mosse_i = 0;
    if (scc.posizione_pezzi[14] != 0) {
        mosse_i = mosse_regina_bianca_l(scc, scc.posizione_pezzi[14], mosse, mosse_i);

        for (int ii = 0; ii < mosse_i; ii++) {
            mosse_l[mosse_i_l].da = scc.posizione_pezzi[14];
            mosse_l[mosse_i_l].a = mosse[ii];
            mosse_i_l++;
        }
    }

    //re
    mosse_i = 0;
    if (scc.posizione_pezzi[15] != 0) {
        mosse_i = mosse_re_bianco_l(scc, scc.posizione_pezzi[15], mosse, mosse_i);

        for (int ii = 0; ii < mosse_i; ii++) {
            mosse_l[mosse_i_l].da = scc.posizione_pezzi[15];
            mosse_l[mosse_i_l].a = mosse[ii];
            mosse_i_l++;
        }
    }
    
    return mosse_i_l;
}

int mosse_legali_neri(scacchiera scc, mossa *mosse_l, int mosse_i_l) {
    
    unsigned char mosse[256]; //buffer per le mosse dei pezzi
    int mosse_i = 0;


    for (int i = 0; i < 8; i++) { //pedoni
        mosse_i = 0;
        if (scc.posizione_pezzi[i] != 0) {
            mosse_i = mosse_pedone_nero_l(scc, scc.posizione_pezzi[i], mosse, mosse_i);
            
            for (int ii = 0; ii < mosse_i; ii++) {
                mosse_l[mosse_i_l].da = scc.posizione_pezzi[i];
                mosse_l[mosse_i_l].a = mosse[ii];
                mosse_i_l++;
            }
        }
    }

    //cavalli
    mosse_i = 0;
    if (scc.posizione_pezzi[8] != 0) {
        mosse_i = mosse_cavallo_nero_l(scc, scc.posizione_pezzi[8], mosse, mosse_i);

        for (int ii = 0; ii < mosse_i; ii++) {
            mosse_l[mosse_i_l].da = scc.posizione_pezzi[8];
            mosse_l[mosse_i_l].a = mosse[ii];
            mosse_i_l++;
        }
    }
    mosse_i = 0;
    if (scc.posizione_pezzi[9] != 0) {
        mosse_i = mosse_cavallo_nero_l(scc, scc.posizione_pezzi[9], mosse, mosse_i);

        for (int ii = 0; ii < mosse_i; ii++) {
            mosse_l[mosse_i_l].da = scc.posizione_pezzi[9];
            mosse_l[mosse_i_l].a = mosse[ii];
            mosse_i_l++;
        }
    }

    //alfieri
    mosse_i = 0;
    if (scc.posizione_pezzi[10] != 0) {
        mosse_i = mosse_alfiere_nero_l(scc, scc.posizione_pezzi[10], mosse, mosse_i);

        for (int ii = 0; ii < mosse_i; ii++) {
            mosse_l[mosse_i_l].da = scc.posizione_pezzi[10];
            mosse_l[mosse_i_l].a = mosse[ii];
            mosse_i_l++;
        }
    }
    mosse_i = 0;
    if (scc.posizione_pezzi[11] != 0) {
        mosse_i = mosse_alfiere_nero_l(scc, scc.posizione_pezzi[11], mosse, mosse_i);

        for (int ii = 0; ii < mosse_i; ii++) {
            mosse_l[mosse_i_l].da = scc.posizione_pezzi[11];
            mosse_l[mosse_i_l].a = mosse[ii];
            mosse_i_l++;
        }
    }

    //torri
    mosse_i = 0;
    if (scc.posizione_pezzi[12] != 0) {
        mosse_i = mosse_alfiere_nero_l(scc, scc.posizione_pezzi[12], mosse, mosse_i);

        for (int ii = 0; ii < mosse_i; ii++) {
            mosse_l[mosse_i_l].da = scc.posizione_pezzi[12];
            mosse_l[mosse_i_l].a = mosse[ii];
            mosse_i_l++;
        }
    }
    mosse_i = 0;
    if (scc.posizione_pezzi[13] != 0) {
        mosse_i = mosse_alfiere_nero_l(scc, scc.posizione_pezzi[13], mosse, mosse_i);

        for (int ii = 0; ii < mosse_i; ii++) {
            mosse_l[mosse_i_l].da = scc.posizione_pezzi[13];
            mosse_l[mosse_i_l].a = mosse[ii];
            mosse_i_l++;
        }
    }

    //regina
    mosse_i = 0;
    if (scc.posizione_pezzi[14] != 0) {
        mosse_i = mosse_regina_nera_l(scc, scc.posizione_pezzi[14], mosse, mosse_i);

        for (int ii = 0; ii < mosse_i; ii++) {
            mosse_l[mosse_i_l].da = scc.posizione_pezzi[14];
            mosse_l[mosse_i_l].a = mosse[ii];
            mosse_i_l++;
        }
    }

    //re
    mosse_i = 0;
    if (scc.posizione_pezzi[15] != 0) {
        mosse_i = mosse_re_nero_l(scc, scc.posizione_pezzi[15], mosse, mosse_i);

        for (int ii = 0; ii < mosse_i; ii++) {
            mosse_l[mosse_i_l].da = scc.posizione_pezzi[15];
            mosse_l[mosse_i_l].a = mosse[ii];
            mosse_i_l++;
        }
    }
    
    return mosse_i_l;
}