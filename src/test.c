#include "pezzi.h"
#include "mosse.h"
#include "scacchiera.h"
#include "cervello.h"

/*
site https://wiki.sharewiz.net/doku.php?id=chess:programming:perft
*/

void test_moves() {
        printf("start testing moves\n");

        int passed = 0;
        int not_passed = 0;

        int test_board[GRANDEZZA_SC] = {0};

        int depth = 0;
        unsigned long int result = 0;

        //test 0 startpos
        printf("\ntest 0 startpos:\n");

        fen_to_board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", test_board);
        depth = 5;
        unsigned long int result_0[6] = {20, 400, 8902, 197281, 4865609, 119060324};
        for (int i = 1; i <= depth; i++) {
                result = perft(i, test_board);

                if (result == result_0[i-1]) {
                        printf("depth %d pass :)\n", i);
                        passed++;
                } else {
                        printf("depth %d FAILED expected %lu find %lu\n", i, result_0[i-1], result);
                        not_passed++;
                }
        }

        //test 1 general
        printf("\ntest 1 general:\n");

        fen_to_board("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1", test_board);
        depth = 4;
        unsigned long int result_1[6] = {48, 2039, 97862, 4085603, 193690690, 8031647685};
        for (int i = 1; i <= depth; i++) {
                result = perft(i, test_board);

                if (result == result_1[i-1]) {
                        printf("depth %d pass :)\n", i);
                        passed++;
                } else {
                        printf("depth %d FAILED expected %lu find %lu\n", i, result_1[i-1], result);
                        not_passed++;
                }
        }

        //test 2 promotion
        printf("\ntest 2 promotion:\n");

        fen_to_board("n1n5/PPPk4/8/8/8/8/4Kppp/5N1N b - - 0 1 ", test_board);
        depth = 5;
        unsigned long int result_2[6] = {24, 496, 9483, 182838, 3605103, 71179139};
        for (int i = 1; i <= depth; i++) {
                result = perft(i, test_board);

                if (result == result_2[i-1]) {
                        printf("depth %d pass :)\n", i);
                        passed++;
                } else {
                        printf("depth %d FAILED expected %lu find %lu\n", i, result_2[i-1], result);
                        not_passed++;
                }
        }

        printf("recap: %d passed, %d failed\n", passed, not_passed);
}