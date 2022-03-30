#include <stdio.h>
#include <string.h>

#include "cli.h"
#include "grafica.h"
#include "scacchiera.h"

const char cli_start_text[] = 
    "## welcome to the 10x12chess chess engine\n"
    ;

const char cli_help_text[] =
    "## commands list:\n"
    "   * quit (exits the program)\n"
    "   * help (various helps)\n"
    "   * printboard (print the board in the terminal)\n"
    "   * fen (set the board with a fen notation string)\n"
    "   * playgui (play against the engine with a gui)\n"
    ;

void cli() {
    
    char command[200] = "";

    int board_used[GRANDEZZA_SC] = {0};
    memcpy(board_used, empty_board, MEM_GRANDEZZA_SC);

    printf(cli_start_text);

    while (1) {
        printf("10x12chess -> ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            printf("quitting...\n");
            break;
        }
        else if ((strcmp(command, "help") == 0)) {
            printf(cli_help_text);
        }
        else if ((strcmp(command, "printboard") == 0)) {
            disegna_scacchiera(board_used);
        }
        else if ((strcmp(command, "fen") == 0)) {
            char fen_string[256];
            printf("insert fen string notation:\n");
            scanf("%s", fen_string);
            fen_to_board(fen_string, board_used);
        }
        else if ((strcmp(command, "playgui") == 0)) { // not definitive
            gui(scacchiera_0);
        }
        else {
            printf("! %s command not found, type help for help :]\n", command);
        }

        printf("\n");
    }
}