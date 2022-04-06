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
#include "cli.h"

#include "test.h"

void gioco() {
    int moss = 0;
    mossa ssa;

    while(moss == 0) {

        disegna_scacchiera(scacchiera_0);
        printf("valutazione: %d\n",valuta_posizione(scacchiera_0));
        printf("gioca bianco PC\n");
        ssa = minimaxRoot(3, scacchiera_0);
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
    //gui(test1);
    //cli();
    test_moves();
    /*
    int sas[GRANDEZZA_SC] = {0};
    fen_to_board("2r1k2r/p1ppPpb1/bn2pnp1/4N3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R b KQk - 0 2", sas);
    mossa moss[400];
    int asd = 0;
    asd = mosse_legali(sas, moss, asd);

    for (size_t i = 0; i < asd; i++)
    {
        printf("da %s a %d \n", square_coordinate[moss[i].da], moss[i].a);
    }*/
}