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

int WindTuring_is_begin(WindCell* cell)
{
        return cell == WindTuring_CELLS;
}

int WindTuring_is_end(WindCell* cell)
{
        return cell == WindTuring_END;
}

int WindTuring_is_head(WindCell* cell)
{
        return cell == WindTuring_HEAD;
}

void WindTuring_clear(void)
{
        unsigned char* cleaner = (unsigned char*)WindTuring_CELLS;
        unsigned char* cleanEnd = (unsigned char*)WindTuring_HEAD;
        while(cleaner != cleanEnd) *cleaner++ = 0;
}

int WindTuring_full(void)
{
        return WindTuring_HEAD == WindTuring_END;
}

size_t WindTuring_from_begin(WindCell* cell)
{
        return cell - WindTuring_CELLS;
}
