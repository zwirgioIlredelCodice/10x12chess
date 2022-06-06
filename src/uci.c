#include "uci.h"
#include <stdio.h>
#include <string.h>

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
    return pos;
}

#define N_UCI_COMMANDS 5
char str_uci[][20] = {"uci", "quit", "debug", "on", "off"};

typedef enum uci_id {
    id_uci,
    id_quit,
    id_debug,
    id_on,
    id_off,
    id_unknown,
    id_end
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
    while (1)
    {
        memset(command_string,0,strlen(command_string));
        fgets(command_string, 1000, stdin); //fgets to read an entire line with spaces
        
        id = uci_token_id(command_string, &pos);

        if (id == id_uci) {
            printf("id name 10x12chess 0\n");
            printf("id author Fabio Murer\n");
            /*
            tell engine to use the uci (universal chess interface),
	        this will be sent once as a first command after program boot
	        to tell the engine to switch to uci mode.
	        After receiving the uci command the engine must identify itself with the "id" command
	        and send the "option" commands to tell the GUI which engine settings the engine supports if any.
	        After that the engine should send "uciok" to acknowledge the uci mode.
	        If no uciok is sent within a certain time period, the engine task will be killed by the GUI.
            */
            printf("uciok\n");
        }
        else if (id == id_debug) {
            id = uci_token_id(command_string, &pos);
            if (id == id_on) {
                ; //da fare
            }
            else if (id == id_off) {
                ; //da fare
            }
        }
        else if (id == id_quit) {
            break;
        }
        

        //printf("[ token %s len %d]\n", token, strlen(token));
        pos = 0;
    }
    
}