// board.c - Tic-tac-toe boards.
// Written by quadfault
// 7/26/17

#include <stdio.h>

#include "board.h"

// Initialize the board to be empty.
void board_init(struct board *self) {
    for (size_t row = 0; row != ROW_COUNT; ++row) {
        for (size_t col = 0; col != COL_COUNT; ++col) {
            self->cells[row][col] = ' ';
        }
    }
}

// Draw the board to stdout.
void board_draw(struct board const *self) {
    for (size_t row = 0; row != ROW_COUNT; ++row) {
        for (size_t col = 0; col != COL_COUNT; ++col) {
            printf("%c", self->cells[row][col]);
            if (col != COL_COUNT - 1) {
                printf("|");
            }
        }
        
        puts("");
        if (row != ROW_COUNT - 1) {
            // TODO: This does not account for boards != 3x3.
            puts("-----");
        }
    }
}

// Are the row 'row' and the column 'col' within range of the board's 
// dimensions?
bool board_in_range(struct board const *self, size_t row, size_t col) {
    (void) self;

    return row < ROW_COUNT && col < COL_COUNT;
}

// Has the board been marked at cell (row, col)?
bool board_is_marked(struct board const *self, size_t row, size_t col) {
    assert(board_in_range(self, row, col));

    return self->cells[row][col] != ' ';
}

// Mark the board at cell (row, col) with 'mark'.
void board_mark(struct board *self, size_t row, size_t col, char mark) {
    assert(board_in_range(self, row, col));
    assert(mark == 'X' || mark == 'O');

    self->cells[row][col] = mark;
}

// Has the player with 'mark' won?
// TODO: Split this function up.
bool board_is_win(struct board const *self, char mark) {
    // Check row wins.
    for (size_t row = 0; row < ROW_COUNT; ++row) {
        bool win = true;
        for (size_t col = 0; col < COL_COUNT; ++col) {
            if (self->cells[row][col] != mark) {
                win = false;
                break;
            }
        }
        
        if (win) {
            return true;
        }
    }
    
    // Check col wins.
    for (size_t col = 0; col < COL_COUNT; ++col) {
        bool win = true;
        for (size_t row = 0; row < ROW_COUNT; ++row) {
            if (self->cells[row][col] != mark) {
                win = false;
                break;
            }
        }
        
        if (win) {
            return true;
        }
    }
    
    // Check left-right diagonal win.
    bool win = true;
    for (size_t i = 0; i < ROW_COUNT; ++i) {
        if (self->cells[i][i] != mark) {
            win = false;
            break;
        }
    }
    
    if (win) {
        return true;
    }
    
    // Check right-left diagonal win.
    win = true;
    for (size_t i = 0; i < ROW_COUNT; ++i) {
        if (self->cells[ROW_COUNT - i - 1][i] != mark) {
            win = false;
            break;
        }
    }
    
    if (win) {
        return true;
    }
    
    return false;
}

// Is there a draw?
//
// This function must only be called if board_is_win() returns false for
// both players. Otherwise, it may report a draw when there is actually
// a win.
bool board_is_draw(struct board const *self) {
    for (size_t row = 0; row < ROW_COUNT; ++row) {
        for (size_t col = 0; col < COL_COUNT; ++col) {
            if (self->cells[row][col] == ' ') {
                return false;
            }
        }
    }
    
    return true;
}
