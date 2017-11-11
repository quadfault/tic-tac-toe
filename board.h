// board.h - Tic-tac-toe boards.
// Written by quadfault
// 7/26/17

#pragma once

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#define ROW_COUNT 3
#define COL_COUNT 3

static_assert(ROW_COUNT == COL_COUNT, "Board must be NxN.");

struct board {
    char cells[ROW_COUNT][COL_COUNT];
};

void board_init(struct board *);
void board_draw(struct board const *);
bool board_in_range(struct board const *, size_t, size_t);
bool board_is_marked(struct board const *, size_t, size_t);
void board_mark(struct board *, size_t, size_t, char);
bool board_is_win(struct board const *, char);
bool board_is_draw(struct board const *);
