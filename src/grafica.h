#pragma once

#include "raylib.h"

#include "pezzi.h"
#include "scacchiera.h"
#include "mosse.h"

extern Image i_pices[];

extern Texture2D t_pices[];

void loadPicesImg();

void loadPicesTexture();

void unloadPicesImg();

void unloadPicesTexture();

enum pieces
{
    king_w,
    queen_w,
    bishop_w,
    knight_w,
    rook_w,
    pawn_w,
    king_b,
    queen_b,
    bishop_b,
    knight_b,
    rook_b,
    pawn_b,
    empty
};

#define QUAD_SIZE 100

void drawBoard(int *board);

typedef enum tipo_schermata
{
    menu,
    partita,
    vittoria
} tipo_schermata;

int gui(int *sc);