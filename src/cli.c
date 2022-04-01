#include <stdio.h>
#include <string.h>

#include "cli.h"
#include "grafica.h"
#include "scacchiera.h"
#include "cervello.h"
#include "test.h"

const char cli_start_text[] = 
    "## welcome to the 10x12chess chess engine\n"
    ;

const char cli_help_text[] =
    "## commands list:\n"
    "   * quit (exits the program)\n"
    "   * help (various helps)\n"
    "   * printboard (print the board in the terminal)\n"
    "   * fen (set the board with a fen notation string)\n"
    "   * perft (see al node in the position for testing)\n"
    "   * test (test suite)\n"
    "   * playgui (play against the engine with a gui)\n"
    ;

void fen_fn(int board[]) {
    char fen_string[256];
    printf("insert fen string notation:\n");
    scanf("%s", fen_string);
    fen_to_board(fen_string, board);
}

void cli() {
    
    char command[200] = "";

    int board_used[GRANDEZZA_SC] = {0};
    memcpy(board_used, empty_board, MEM_GRANDEZZA_SC);

    printf(cli_start_text);

    while (1) {
        printf("10x12chess -> ");
        fgets(command, 200, stdin); //fgets to read an entire line with spaces

        if (strcmp(command, "quit\n") == 0) {
            printf("quitting...\n");
            break;
        }
        else if ((strcmp(command, "help\n") == 0)) {
            printf(cli_help_text);
        }
        else if ((strcmp(command, "printboard\n") == 0)) {
            disegna_scacchiera(board_used);
        }
        else if ((strcmp(command, "fen\n") == 0)) {
            char fen_string[256];
            printf("insert fen string notation:\n");
            fgets(fen_string, 256, stdin);
            fen_to_board(fen_string, board_used);
        }
        else if ((strcmp(command, "perft\n") == 0)) {
            int depth;
            printf("insert perft depth:\n");
            scanf("%d", &depth);
            unsigned long int nodes = perft(depth, board_used, 1); //ismaximising temp
            printf("nodes found: %lu \n", nodes);
        }
        else if ((strcmp(command, "test\n") == 0)) {
            test_moves();
        }
        else if ((strcmp(command, "playgui\n") == 0)) { // not definitive
            gui(scacchiera_0);
        }
        else {
            printf("! %s command not found, type help for help :]\n", command);
        }

        printf("\n");
    }
}