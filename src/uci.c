#include "uci.h"
#include <stdio.h>
#include <string.h>

#include "scacchiera.h"

int uci_token(char * command_string, char * token, int pos) {

    if (command_string[pos] == '\n') { //no more chars
        return -1;
    }
    while (command_string[pos] == ' ' || command_string[pos] == '\t') { //skip whitespaces
        pos++;
    }
    int pos_token_start = pos;
    while (command_string[pos] != ' ' && command_string[pos] != '\t' && command_string[pos] != '\n') {
        pos++;
    }
    strncpy(token, command_string+pos_token_start, (pos - pos_token_start));
    token[pos - pos_token_start] = '\0';
    return pos;
}

#define N_UCI_COMMANDS 11
char str_uci[][20] = {"uci", "quit", "debug", "on", "off", "isready", "setoption", "register", "id_ucinewgame", "position", "mydebug"};

typedef enum uci_id {
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
    id_mydebug,
    id_unknown,
} uci_id;

uci_id uci_token_id(char * command_string, int * pos) {
    char token[200];
    uci_id id = id_unknown;
    while (id == id_unknown) {
        memset(token,0,strlen(token));
        *pos = uci_token(command_string, token, *pos);
        if (*pos == -1) {
            return id_unknown;
        }
        for (int i = 0; i < N_UCI_COMMANDS; i++) {
            if (strcmp(str_uci[i], token) == 0) {
                id = i;
                break;
            }
        }
    }
    return id;
}

void ucimain() {
    char command_string[1000];
    int pos = 0;
    uci_id id = id_unknown;
    char token[200];

    int uci_board[GRANDEZZA_SC];
    memcpy(uci_board, scacchiera_0, MEM_GRANDEZZA_SC);

    while (1)
    {
        memset(command_string,0,strlen(command_string));
        fgets(command_string, 1000, stdin); //fgets to read an entire line with spaces
        
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
            if (id == id_on) {
                ; //da fare
            }
            else if (id == id_off) {
                ; //da fare
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
            if (strcmp("startpos", token) == 0) {
                memcpy(uci_board, scacchiera_0, MEM_GRANDEZZA_SC);
            }
            else if (strcmp("fen", token) == 0) {
                fen_to_board(command_string + pos + 1, uci_board);
            }
            memset(token,0,strlen(token));
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