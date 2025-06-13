#include "../../headers/PDparser/parsing_table.h"

void init_table()
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 5; j++)
            table[i][j] = 0;

    table[0][0] = 1;
    table[0][1] = 2;
    table[1][2] = 4;
    table[1][3] = 3;
}
