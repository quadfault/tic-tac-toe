// comp.c - Computer players.
// Written by quadfault
// 7/26/17

#include "comp.h"

// Initialize the computer player with the board '*pboard'.
void comp_init(struct comp *self, struct board *pboard) {
    self->pboard = pboard;
}

// Make the computer move and return its selected row and column.
void comp_get_move(struct comp const *self, size_t *prow, size_t *pcol) {
    for (size_t row = 0; row != ROW_COUNT; ++row) {
        for (size_t col = 0; col != COL_COUNT; ++col) {
            if (!board_is_marked(self->pboard, row, col)) {
                *prow = row;
                *pcol = col;
                return;
            }
        }
    }

    // TODO: Hmmm...
    *prow = 0;
    *pcol = 0;
}



