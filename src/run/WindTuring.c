#include "WindTuring.h"

static WindObject WindTuring_CELLS[WindTuring_CELL_SIZE];

static WindObject* WindTuring_HEAD = WindTuring_CELLS;

WindObject* WindTuring_begin(void)
{
        return WindTuring_CELLS;
}

WindObject* WindTuring_end(void)
{
        return WindTuring_CELLS + WindTuring_CELL_SIZE;
}
