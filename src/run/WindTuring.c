#include "WindTuring.h"

// Cells, the main storage container of the turing machine
static WindObject WindTuring_CELLS[WindTuring_CELL_SIZE];

static WindObject* WindTuring_HEAD = WindTuring_CELLS;

static const WindObject* WindTuring_END = WindTuring_CELLS + WindTuring_CELL_SIZE;

WindObject* WindTuring_begin(void)
{
        return WindTuring_CELLS;
}

const WindObject* WindTuring_end(void)
{
        return WindTuring_END;
}

void WindTuring_head_up(void)
{
        WindTuring_HEAD++;
}

void WindTuring_head_down(void)
{
        WindTuring_HEAD--;
}
