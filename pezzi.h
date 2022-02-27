#pragma once

enum pezzi {
    vuoto,
    pedone_b,
    cavallo_b,
    alfiere_b,
    torre_b,
    regina_b,
    re_b,

    pedone_n,
    cavallo_n,
    alfiere_n,
    torre_n,
    regina_n,
    re_n,

    barriera
};

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