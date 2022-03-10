#include "pezzi.h"

int bianco(int pezzo) {
    if (pezzo > vuoto && pezzo <= re_b)
        return 1;
    else
        return 0;
}

int nero(int pezzo) {
    if (pezzo >= pedone_n && pezzo <= re_n)
        return 1;
    else
        return 0;
}