#pragma once

#include "raylib.h"

#include "pezzi.h"
#include "scacchiera.h"

Image i_pices[12];

Texture2D t_pices[12];

void loadPicesImg()
{
    Image chess = LoadImage("Chess_Pieces_Sprite.png");

    for (int ii = 0; ii < 2; ii++)
    {
        for (int i = 0; i < 6; i++)
        {
            i_pices[(ii*6+i)] = ImageFromImage(chess, (Rectangle){i*200, ii*200, 200, 200});
        }
    }
}

void loadPicesTexture()
{
    for (int i = 0; i < 12; i++)
    {
        t_pices[i] = LoadTextureFromImage(i_pices[i]);
    }
    
}

void unloadPicesImg()
{
    for (int i = 0; i < 12; i++)
    {
        UnloadImage(i_pices[i]);
    }
}

void unloadPicesTexture()
{
    for (int i = 0; i < 12; i++)
    {
        UnloadTexture(t_pices[i]);
    }
}



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

int remap_pices[] = {re_b, regina_b, alfiere_b, cavallo_b, torre_b, pedone_b, re_n, regina_n, alfiere_n, cavallo_n, torre_n, pedone_n, vuoto};

#define QUAD_SIZE 100

void drawBoard(int *board) 
{
    int sfaso = 0;
    Vector2 pos = { 0, 0};

    for(int i = 12; i <= 98; i++) {

        sfaso++;
    
        if (i % 10 != 9) {
            int y_quad = i / 10 - 2;
            int x_quad = i % 10 - 1;

            if (sfaso % 2 == 0) {
                DrawRectangle(x_quad * QUAD_SIZE, y_quad * QUAD_SIZE, QUAD_SIZE, QUAD_SIZE, BROWN);
            }
            else {
            DrawRectangle(x_quad * QUAD_SIZE, y_quad * QUAD_SIZE, QUAD_SIZE, QUAD_SIZE, LIGHTGRAY);
            }
            if (board[i] != empty)
            {
                pos.x = x_quad * QUAD_SIZE;
                pos.y = y_quad * QUAD_SIZE;


                if (board[i] == re_b) {
                    DrawTextureEx(t_pices[king_w], pos, 0, 0.5, WHITE);
                }

                if (board[i] == re_n) {
                    DrawTextureEx(t_pices[queen_w], pos, 0, 0.5, WHITE);
                }

                else if (board[i] != vuoto) {
                    DrawTextureEx(t_pices[remap_pices[board[i]]], pos, 0, 0.5, WHITE);
                }
            }
        }   
    }
}


Vector2 position = { 100, 100};
int gui()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 800;
    
    InitWindow(screenWidth, screenHeight, "Chesso");
    
    loadPicesImg(); 
    loadPicesTexture();          // Image converted to texture, GPU memory (VRAM)

    unloadPicesImg();   // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM

    SetTargetFPS(10);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        drawBoard(scacchiera_0);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    
    unloadPicesTexture();
    
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
