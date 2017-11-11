// main.c - Tic-tac-toe.
// Written by quadfault
// 7/26/17

#include <stdio.h>

#include "board.h"
#include "comp.h"

void flush_stdin(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main(void) {
    struct board board;
    board_init(&board);

    struct comp comp;
    comp_init(&comp, &board);

    // Player goes first.
    char mark = 'X';

    bool win = false;
    bool draw = false;

    for (;;) {
        size_t row, col;

        board_draw(&board);
        if (win) {
            if (mark == 'X') {
                puts("Player wins!");
            } else {
                puts("Computer wins!");
            }

            break;
        } else if (draw) {
            puts("Draw.");
            
            break;
        } else {
            printf(">> ");
        }

        if (mark == 'X') {
            // TODO: Don't use scanf(). Read a full line and then parse each
            // integer using sscanf() or something.
            int result = scanf("%zu %zu", &row, &col);
            if (result != 2) {
                puts("bad input, need row & col");
                flush_stdin();
                continue;
            } else if (!board_in_range(&board, row, col)) {
                puts("row, col must be between 0 and 2");
                continue;
            } else if (board_is_marked(&board, row, col)) {
                printf("mark already at (%zu, %zu)\n", row, col);
                continue;
            }
        } else {
            comp_get_move(&comp, &row, &col);
            printf("%zu %zu\n", row, col);
        }

        board_mark(&board, row, col, mark);
        if (board_is_win(&board, mark)) {
            win = true;

            continue;
        } else if (board_is_draw(&board)) {
            draw = true;

            continue;
        }

        mark = (mark == 'X') ? 'O' : 'X';
    }
}
