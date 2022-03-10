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

int bianco(int pezzo);

int nero(int pezzo);