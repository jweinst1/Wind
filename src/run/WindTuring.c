#include "WindTuring.h"

// Cells, the main storage container of the turing machine
static WindCell WindTuring_CELLS[WindTuring_CELL_SIZE];

static WindCell* WindTuring_HEAD = WindTuring_CELLS;

static const WindCell* WindTuring_END = WindTuring_CELLS + WindTuring_CELL_SIZE;

WindCell* WindTuring_begin(void)
{
        return WindTuring_CELLS;
}

const WindCell* WindTuring_end(void)
{
        return WindTuring_END;
}

WindCell* WindTuring_head(void)
{
        return WindTuring_HEAD;
}

void WindTuring_head_up(void)
{
        if(!(WindTuring_HEAD == WindTuring_END)) WindTuring_HEAD++;
}

void WindTuring_head_down(void)
{
        if(!(WindTuring_HEAD == WindTuring_CELLS)) WindTuring_HEAD--;
}

int WindTuring_full(void)
{
        return WindTuring_HEAD == WindTuring_END;
}
