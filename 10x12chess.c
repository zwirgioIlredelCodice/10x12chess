/*
sas malibox board representation
*/

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <stdio.h>
#include "pezzi.h"
#include "mosse.h"
#include "scacchiera.h"
#include "valutazione.h"
#include "cervello.h"

#include "test.h"

int main() {
/*
    disegna_scacchiera(scacchiera_0);
    mossa mosse_legali[100];
    int mosse_legali_i = 0;

    mosse_legali_i = tutte_mosse_legali(scacchiera_0, mosse_legali, mosse_legali_i);

    printf("\n");
    for (int i = 0; i < mosse_legali_i; i++) {
        printf("%d: da %d a %d\n", i, mosse_legali[i].da, mosse_legali[i].a);
    }
    printf("\n");
    */
    migliore_mossa(test1, 3);

    int moss = 0;
    mossa ssa;

    while(moss == 0) {

        disegna_scacchiera(scacchiera_0);
        printf("gioca bianco PC\n");
        ssa = migliore_mossa(scacchiera_0, 3);
        fai_mossa(scacchiera_0, ssa.da, ssa.a);
        disegna_scacchiera(scacchiera_0);

        printf("immeti da a\n");
        scanf("%d", &ssa.da);
        scanf("%d", &ssa.a);
        fai_mossa(scacchiera_0, ssa.da, ssa.a);
        disegna_scacchiera(scacchiera_0);

        printf("continuare?\n");
        scanf("%d", &moss);
    }
}