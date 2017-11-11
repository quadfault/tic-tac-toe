// comp.h - Computer players.
// Written by quadfault
// 7/26/17

#pragma once

#include <stddef.h>

#include "board.h"

struct comp {
    struct board *pboard;
};

void comp_init(struct comp *, struct board *);
void comp_get_move(struct comp const *, size_t *, size_t *);
