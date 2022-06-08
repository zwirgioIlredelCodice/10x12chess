#include "uci.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "scacchiera.h"
#include "cervello.h"
#include "mosse.h"

int uci_token(char *command_string, char *token, int pos)
{

    if (command_string[pos] == '\n')
    { // no more chars
        return -1;
    }
    while (command_string[pos] == ' ' || command_string[pos] == '\t')
    { // skip whitespaces
        pos++;
    }
    int pos_token_start = pos;
    while (command_string[pos] != ' ' && command_string[pos] != '\t' && command_string[pos] != '\n')
    {
        pos++;
    }
    strncpy(token, command_string + pos_token_start, (pos - pos_token_start));
    token[pos - pos_token_start] = '\0';
    return pos;
}

#define N_UCI_COMMANDS 12
char str_uci[][20] = {"uci", "quit", "debug", "on", "off", "isready", "setoption", "register", "id_ucinewgame", "position", "go", "mydebug"};

typedef enum uci_id
{
    id_uci,
    id_quit,
    id_debug,
    id_on,
    id_off,
    id_isready,
    id_setoption,
    id_register,
    id_ucinewgame,
    id_position,
    id_go,
    id_mydebug,
    id_unknown,
} uci_id;

uci_id uci_token_id(char *command_string, int *pos)
{
    char token[200];
    uci_id id = id_unknown;
    while (id == id_unknown)
    {
        memset(token, 0, strlen(token));
        *pos = uci_token(command_string, token, *pos);
        if (*pos == -1)
        {
            return id_unknown;
        }
        for (int i = 0; i < N_UCI_COMMANDS; i++)
        {
            if (strcmp(str_uci[i], token) == 0)
            {
                id = i;
                break;
            }
        }
    }
    return id;
}

void uci_mossa_to_ucimove(mossa move, char *ucimove, int *uciboard)
{
    strcpy(ucimove, square_coordinate[move.da]);
    if (move.a > 0)
    { // nessun problema
        strcat(ucimove, square_coordinate[move.a]);
    }
    else
    {
        if (move.a == pav_b_dx || move.a == pav_b_sx)
        { // presa al varco
            strcat(ucimove, square_coordinate[uciboard[presa_al_varco - 10]]);
        }
        else if (move.a == pav_n_dx || move.a == pav_n_sx)
        { // presa al varco
            strcat(ucimove, square_coordinate[uciboard[presa_al_varco + 10]]);
        }
        else
        {
            switch (move.a)
            {
            case moss_arrocco_bdx:
                strcpy(ucimove, "e1g1");
                break;
            case moss_arrocco_bsx:
                strcpy(ucimove, "e1c1");
                break;
            case moss_arrocco_ndx:
                strcpy(ucimove, "e8g8");
                break;
            case moss_arrocco_nsx:
                strcpy(ucimove, "e8c8");
                break;
            case promozione_pb_r:
                strcat(ucimove, square_coordinate[move.da - 10]);
                strcat(ucimove, "q");
                break;
            case promozione_pb_t:
                strcat(ucimove, square_coordinate[move.da - 10]);
                strcat(ucimove, "r");
                break;
            case promozione_pb_a:
                strcat(ucimove, square_coordinate[move.da - 10]);
                strcat(ucimove, "b");
                break;
            case promozione_pb_c:
                strcat(ucimove, square_coordinate[move.da - 10]);
                strcat(ucimove, "n");
                break;
            case promozione_pn_r:
                strcat(ucimove, square_coordinate[move.da + 10]);
                strcat(ucimove, "q");
                break;
            case promozione_pn_t:
                strcat(ucimove, square_coordinate[move.da + 10]);
                strcat(ucimove, "r");
                break;
            case promozione_pn_a:
                strcat(ucimove, square_coordinate[move.da + 10]);
                strcat(ucimove, "b");
                break;
            case promozione_pn_c:
                strcat(ucimove, square_coordinate[move.da + 10]);
                strcat(ucimove, "n");
                break;
            case promozione_pbdx_r:
                strcat(ucimove, square_coordinate[move.da - 9]);
                strcat(ucimove, "q");
                break;
            case promozione_pbdx_t:
                strcat(ucimove, square_coordinate[move.da - 9]);
                strcat(ucimove, "r");
                break;
            case promozione_pbdx_a:
                strcat(ucimove, square_coordinate[move.da - 9]);
                strcat(ucimove, "b");
                break;
            case promozione_pbdx_c:
                strcat(ucimove, square_coordinate[move.da - 9]);
                strcat(ucimove, "n");
                break;
            case promozione_pndx_r:
                strcat(ucimove, square_coordinate[move.da + 11]);
                strcat(ucimove, "q");
                break;
            case promozione_pndx_t:
                strcat(ucimove, square_coordinate[move.da + 11]);
                strcat(ucimove, "r");
                break;
            case promozione_pndx_a:
                strcat(ucimove, square_coordinate[move.da + 11]);
                strcat(ucimove, "b");
                break;
            case promozione_pndx_c:
                strcat(ucimove, square_coordinate[move.da + 11]);
                strcat(ucimove, "n");
                break;
            case promozione_pbsx_r:
                strcat(ucimove, square_coordinate[move.da - 11]);
                strcat(ucimove, "q");
                break;
            case promozione_pbsx_t:
                strcat(ucimove, square_coordinate[move.da - 11]);
                strcat(ucimove, "r");
                break;
            case promozione_pbsx_a:
                strcat(ucimove, square_coordinate[move.da - 11]);
                strcat(ucimove, "b");
                break;
            case promozione_pbsx_c:
                strcat(ucimove, square_coordinate[move.da - 11]);
                strcat(ucimove, "n");
                break;
            case promozione_pnsx_r:
                strcat(ucimove, square_coordinate[move.da + 9]);
                strcat(ucimove, "q");
                break;
            case promozione_pnsx_t:
                strcat(ucimove, square_coordinate[move.da + 9]);
                strcat(ucimove, "r");
                break;
            case promozione_pnsx_a:
                strcat(ucimove, square_coordinate[move.da + 9]);
                strcat(ucimove, "b");
                break;
            case promozione_pnsx_c:
                strcat(ucimove, square_coordinate[move.da + 9]);
                strcat(ucimove, "n");
                break;
            default:
                break;
            }
        }
    }
}

void ucimain()
{
    char command_string[1000];
    int pos = 0;
    uci_id id = id_unknown;
    char token[200];

    int uci_board[GRANDEZZA_SC];
    memcpy(uci_board, scacchiera_0, MEM_GRANDEZZA_SC);

    int depth;

    while (1)
    {
        memset(command_string, 0, strlen(command_string));
        fgets(command_string, 1000, stdin); // fgets to read an entire line with spaces

        id = uci_token_id(command_string, &pos);

        switch (id)
        {
        case id_uci:
            printf("id name 10x12chess 0\n");
            printf("id author Fabio Murer\n");
            printf("uciok\n");
            break;
        case id_debug:
            id = uci_token_id(command_string, &pos);
            if (id == id_on)
            {
                ; // da fare
            }
            else if (id == id_off)
            {
                ; // da fare
            }
            break;
        case id_isready:
            printf("readyok\n");
            break;
        case id_setoption:
            break;
        case id_register:
            //"register name Stefan MK code 4359874324"
            break;
        case id_ucinewgame:
            memcpy(uci_board, scacchiera_0, MEM_GRANDEZZA_SC);
            break;
        case id_position:
            pos = uci_token(command_string, token, pos);
            if (strcmp("startpos", token) == 0)
            {
                memcpy(uci_board, scacchiera_0, MEM_GRANDEZZA_SC);
            }
            else if (strcmp("fen", token) == 0)
            {
                fen_to_board(command_string + pos + 1, uci_board);
            }
            memset(token, 0, strlen(token));
            break;
        case id_go:
            pos = uci_token(command_string, token, pos);
            if (strcmp("ponder", token) == 0)
            {
                ;
                /*
                Pondering is simply using the opponent's move time to consider
                likely opponent moves and thus gain a pre-processing advantage
                when it is our turn to move
                */
            }
            else if (strcmp("depth", token) == 0)
            {
                memset(token, 0, strlen(token));
                pos = uci_token(command_string, token, pos);
                depth = atoi(token);
            }
            else if (strcmp("infinite", token) == 0)
            {
                depth = 100; // --------- da cambiare
            }
            mossa bestmove;
            bestmove = minimax_alpha_beta_Root(depth, uci_board);
            break;
        case id_mydebug:
            disegna_scacchiera(uci_board);
            break;
        case id_quit:
            return;
            break;
        default:
            break;
        }
        pos = 0;
    }
}