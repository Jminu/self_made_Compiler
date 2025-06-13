#include "../../headers/LRparser/GOTOtable.h"

void init_goto_table()
{
    // 모든 항목 -1로 초기화
    for (int i = 0; i < STATE_COUNT; i++)
    {
        for (int j = 0; j < NON_TERMINAL_COUNT; j++)
        {
            goto_table[i][j] = -1;
        }
    }

    // 상태별 GOTO 값 지정
    goto_table[0][0] = 1; // E
    goto_table[0][1] = 2; // T
    goto_table[0][2] = 3; // F

    goto_table[4][0] = 8; // E
    goto_table[4][1] = 2; // T
    goto_table[4][2] = 3; // F

    goto_table[6][1] = 9; // T
    goto_table[6][2] = 3; // F

    goto_table[7][2] = 10; // F
}

int get_nonterminal_index(char sym)
{
    switch (sym)
    {
    case 'E': return 0;
    case 'T': return 1;
    case 'F': return 2;
    default: return -1;
    }
}
