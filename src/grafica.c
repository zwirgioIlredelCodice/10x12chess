#include "raylib.h"

#include "pezzi.h"
#include "scacchiera.h"
#include "mosse.h"
#include "grafica.h"

Image i_pices[12];

Texture2D t_pices[12];

void loadPicesImg()
{
    Image chess = LoadImage("../assets/Chess_Pieces_Sprite.png");

    for (int ii = 0; ii < 2; ii++)
    {
        for (int i = 0; i < 6; i++)
        {
            i_pices[(ii * 6 + i)] = ImageFromImage(chess, (Rectangle){i * 200, ii * 200, 200, 200});
        }
    }
}

void loadPicesTexture()
{
    for (int i = 0; i < 12; i++)
    {
        t_pices[i] = LoadTextureFromImage(i_pices[i]);
        printf("%d ", i);
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

#define QUAD_SIZE 100

void drawBoard(int *board)
{
    int sfaso = 1;
    Vector2 pos = {0, 0};

    for (int i = 12; i <= 98; i++)
    {

        if ((i % 10) == 0)
        {
            sfaso++;
        }

        if (i % 10 != 9)
        {

            int y_quad = i / 10 - 2;
            int x_quad = i % 10 - 1;

            if ((i + sfaso) % 2 == 0)
            {
                DrawRectangle(x_quad * QUAD_SIZE, y_quad * QUAD_SIZE, QUAD_SIZE, QUAD_SIZE, BROWN);
            }
            else
            {
                DrawRectangle(x_quad * QUAD_SIZE, y_quad * QUAD_SIZE, QUAD_SIZE, QUAD_SIZE, LIGHTGRAY);
            }

            if (board[i] != vuoto)
            {
                pos.x = x_quad * QUAD_SIZE;
                pos.y = y_quad * QUAD_SIZE;

                if (board[i] != vuoto)
                {

                    switch (board[i])
                    {
                    case pedone_b:
                        DrawTextureEx(t_pices[pawn_w], pos, 0, 0.5, WHITE);
                        break;
                    case cavallo_b:
                        DrawTextureEx(t_pices[knight_w], pos, 0, 0.5, WHITE);
                        break;
                    case alfiere_b:
                        DrawTextureEx(t_pices[bishop_w], pos, 0, 0.5, WHITE);
                        break;
                    case torre_b:
                        DrawTextureEx(t_pices[rook_w], pos, 0, 0.5, WHITE);
                        break;
                    case regina_b:
                        DrawTextureEx(t_pices[queen_w], pos, 0, 0.5, WHITE);
                        break;
                    case re_b:
                        DrawTextureEx(t_pices[king_w], pos, 0, 0.5, WHITE);
                        break;
                    case pedone_n:
                        DrawTextureEx(t_pices[pawn_b], pos, 0, 0.5, WHITE);
                        break;
                    case cavallo_n:
                        DrawTextureEx(t_pices[knight_b], pos, 0, 0.5, WHITE);
                        break;
                    case alfiere_n:
                        DrawTextureEx(t_pices[bishop_b], pos, 0, 0.5, WHITE);
                        break;
                    case torre_n:
                        DrawTextureEx(t_pices[rook_b], pos, 0, 0.5, WHITE);
                        break;
                    case regina_n:
                        DrawTextureEx(t_pices[queen_b], pos, 0, 0.5, WHITE);
                        break;
                    case re_n:
                        DrawTextureEx(t_pices[king_b], pos, 0, 0.5, WHITE);
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
}

typedef enum tipo_schermata
{
    menu,
    partita,
    vittoria
} tipo_schermata;

int gui(int *sc)
{
    int sc_salvata[120];
    memcpy(sc_salvata, sc, sizeof(int) * 120);
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "10x12chess");

    loadPicesImg();
    loadPicesTexture(); // Image converted to texture, GPU memory (VRAM)

    unloadPicesImg(); // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM

    SetTargetFPS(30); // Set our game to run at 60 frames-per-second

    int turno = 1; // biachi 1 neri -1;
    Vector2 posizione_mouse;
    int mouse_scacchiera = 0;
    int px, py;

    int mosse[200];
    mossa mosse_l[200];
    int mosse_i = 0;
    int mosse_i_l = 0;

    int mossa_mouse = 0;

    tipo_schermata schermata = menu;

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        switch (schermata)
        {
        case menu:
            if (IsKeyPressed(KEY_A))
            {
                memcpy(sc, sc_salvata, sizeof(int) * 120);
                schermata = partita;
            }
            break;

        case partita:
            if (IsKeyPressed(KEY_A))
            {
                schermata = menu;
            }

            if (turno == 1)
            {
                
                mosse_i_l = mosse_legali_biachi(sc, mosse_l, mosse_i_l);

                if (mosse_i_l == 0)
                {
                    schermata = vittoria;
                }

                mosse_i_l = 0;
                
                // ---------mossa engine
                
                mossa mm = minimaxRoot(4, sc, 1);
                fai_mossa(sc, mm.da, mm.a);
                turno = -turno;
                
                /*
                if (IsMouseButtonPressed(0))
                {
                    mosse_i = 0;

                    posizione_mouse = GetMousePosition();
                    px = (int)posizione_mouse.x;
                    py = (int)posizione_mouse.y;

                    px = (px / QUAD_SIZE);
                    py = (py / QUAD_SIZE);

                    mouse_scacchiera = py * 10 + px + 21;

                    if (sc[mouse_scacchiera] != vuoto)
                    {

                        switch (sc[mouse_scacchiera])
                        {
                        case pedone_b:
                            mosse_i = mosse_pedone_bianco_l(sc, mouse_scacchiera, mosse, mosse_i);
                            break;
                        case cavallo_b:
                            mosse_i = mosse_cavallo_bianco_l(sc, mouse_scacchiera, mosse, mosse_i);
                            break;
                        case alfiere_b:
                            mosse_i = mosse_alfiere_bianco_l(sc, mouse_scacchiera, mosse, mosse_i);
                            break;
                        case torre_b:
                            mosse_i = mosse_torre_bianca_l(sc, mouse_scacchiera, mosse, mosse_i);
                            break;
                        case regina_b:
                            mosse_i = mosse_regina_bianca_l(sc, mouse_scacchiera, mosse, mosse_i);
                            break;
                        case re_b:
                            mosse_i = mosse_re_bianco_l(sc, mouse_scacchiera, mosse, mosse_i);
                            break;
                        default:
                            break;
                        }
                    }
                }*/

                if (IsMouseButtonPressed(1))
                {
                    posizione_mouse = GetMousePosition();
                    int sspx = (int)posizione_mouse.x;
                    int sspy = (int)posizione_mouse.y;

                    sspx = (sspx / QUAD_SIZE);
                    sspy = (sspy / QUAD_SIZE);

                    mossa_mouse = sspy * 10 + sspx + 21;

                    fai_mossa(sc, mouse_scacchiera, mossa_mouse);

                    turno = -turno;
                }
            }
            else if (turno == -1)
            {
                mosse_i_l = mosse_legali_neri(sc, mosse_l, mosse_i_l);

                if (mosse_i_l == 0)
                {
                    schermata = vittoria;
                }

                mosse_i_l = 0;

                if (IsMouseButtonPressed(0))
                {
                    mosse_i = 0;

                    posizione_mouse = GetMousePosition();
                    px = (int)posizione_mouse.x;
                    py = (int)posizione_mouse.y;

                    px = (px / QUAD_SIZE);
                    py = (py / QUAD_SIZE);

                    mouse_scacchiera = py * 10 + px + 21;

                    if (sc[mouse_scacchiera] != vuoto)
                    {

                        switch (sc[mouse_scacchiera])
                        {
                        case pedone_n:
                            mosse_i = mosse_pedone_nero_l(sc, mouse_scacchiera, mosse, mosse_i);
                            break;
                        case cavallo_n:
                            mosse_i = mosse_cavallo_nero_l(sc, mouse_scacchiera, mosse, mosse_i);
                            break;
                        case alfiere_n:
                            mosse_i = mosse_alfiere_nero_l(sc, mouse_scacchiera, mosse, mosse_i);
                            break;
                        case torre_n:
                            mosse_i = mosse_torre_nera_l(sc, mouse_scacchiera, mosse, mosse_i);
                            break;
                        case regina_n:
                            mosse_i = mosse_regina_nera_l(sc, mouse_scacchiera, mosse, mosse_i);
                            break;
                        case re_n:
                            mosse_i = mosse_re_nero_l(sc, mouse_scacchiera, mosse, mosse_i);
                            break;
                        default:
                            break;
                        }
                    }
                }

                if (IsMouseButtonPressed(1))
                {
                    posizione_mouse = GetMousePosition();
                    int sspx = (int)posizione_mouse.x;
                    int sspy = (int)posizione_mouse.y;

                    sspx = (sspx / QUAD_SIZE);
                    sspy = (sspy / QUAD_SIZE);

                    mossa_mouse = sspy * 10 + sspx + 21;

                    fai_mossa(sc, mouse_scacchiera, mossa_mouse);

                    turno = -turno;
                }
            }
            break;

        case vittoria:
            if (IsKeyPressed(KEY_A))
            {
                schermata = menu;
            }
            break;

        default:
            break;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        switch (schermata)
        {
        case menu:
            DrawText("MENU: a per procedere", 130, 220, 20, MAROON);
            break;

        case partita:
            drawBoard(sc);

            DrawRectangle(px * QUAD_SIZE, py * QUAD_SIZE, QUAD_SIZE, QUAD_SIZE, (Color){253, 249, 0, 100});

            for (int ii = 0; ii < mosse_i; ii++)
            {
                int ppx = (mosse[ii] % 10) - 1;
                int ppy = (mosse[ii] / 10) - 2;
                DrawRectangle(ppx * QUAD_SIZE, ppy * QUAD_SIZE, QUAD_SIZE, QUAD_SIZE, (Color){0, 228, 48, 100});
            }
            break;

        case vittoria:
            DrawText("VITTORIA: qualcuno ha vinto, a per menù", 130, 220, 20, MAROON);
            break;

        default:
            break;
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    unloadPicesTexture();

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
