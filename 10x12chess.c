/*
sas malibox board representation
*/

#include <stdio.h>
#include "pezzi.h"
#include "mosse.h"
#include "scacchiera.h"
#include "valutazione.h"
#include "cervello.h"

#include "raylib.h"
#include "grafica.h"

#include "test.h"

void gioco() {
    int moss = 0;
    mossa ssa;

    while(moss == 0) {

        disegna_scacchiera(scacchiera_0);
        printf("valutazione: %d\n",valuta_posizione(scacchiera_0));
        printf("gioca bianco PC\n");
        ssa = migliore_mossa(scacchiera_0, 6);
        fai_mossa(scacchiera_0, ssa.da, ssa.a);
        disegna_scacchiera(scacchiera_0);
        printf("valutazione: %d\n",valuta_posizione(scacchiera_0));

        printf("immeti da a\n");
        char pos_c[10];
        scanf("%s", &pos_c);
        ssa.da = pos_lettere(pos_c);
        scanf("%s", &pos_c);
        ssa.a = pos_lettere(pos_c);

        fai_mossa(scacchiera_0, ssa.da, ssa.a);
        disegna_scacchiera(scacchiera_0);
        printf("valutazione: %d\n",valuta_posizione(scacchiera_0));
        printf("continuare?\n");
        scanf("%d", &moss);
    }
}

int main() {
    gui();
}