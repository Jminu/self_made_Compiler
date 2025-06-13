#include "../../headers/LRparser/ACTIONtable.h"

void init_action_table()
{
    for(int i = 0; i < STATE_COUNT; i++)
    {
        for(int j = 0; j < TERMINAL_COUNT; j++)
        {
            action_table[i][j] = (ACTION_ENTRY){ERROR, -1};
        }
    }

    // ACTION 테이블 초기화 (스크린샷 기반)
    action_table[0][0] = (ACTION_ENTRY){SHIFT, 5};  // id
    action_table[0][3] = (ACTION_ENTRY){SHIFT, 4};  // (

    action_table[1][1] = (ACTION_ENTRY){SHIFT, 6};  // +
    action_table[1][5] = (ACTION_ENTRY){ACCEPT, 0}; // $

    action_table[2][1] = (ACTION_ENTRY){REDUCE, 2}; // +
    action_table[2][2] = (ACTION_ENTRY){SHIFT, 7};  // *
    action_table[2][4] = (ACTION_ENTRY){REDUCE, 2}; // )
    action_table[2][5] = (ACTION_ENTRY){REDUCE, 2}; // $

    action_table[3][1] = (ACTION_ENTRY){REDUCE, 4};
    action_table[3][2] = (ACTION_ENTRY){REDUCE, 4};
    action_table[3][4] = (ACTION_ENTRY){REDUCE, 4};
    action_table[3][5] = (ACTION_ENTRY){REDUCE, 4};

    action_table[4][0] = (ACTION_ENTRY){SHIFT, 5};  // id
    action_table[4][3] = (ACTION_ENTRY){SHIFT, 4};  // (

    action_table[5][1] = (ACTION_ENTRY){REDUCE, 6};
    action_table[5][2] = (ACTION_ENTRY){REDUCE, 6};
    action_table[5][4] = (ACTION_ENTRY){REDUCE, 6};
    action_table[5][5] = (ACTION_ENTRY){REDUCE, 6};

    action_table[6][0] = (ACTION_ENTRY){SHIFT, 5};  // id
    action_table[6][3] = (ACTION_ENTRY){SHIFT, 4};  // (

    action_table[7][0] = (ACTION_ENTRY){SHIFT, 5};
    action_table[7][3] = (ACTION_ENTRY){SHIFT, 4};

    action_table[8][1] = (ACTION_ENTRY){SHIFT, 6};  // +
    action_table[8][4] = (ACTION_ENTRY){SHIFT, 11}; // )

    action_table[9][1] = (ACTION_ENTRY){REDUCE, 1};
    action_table[9][2] = (ACTION_ENTRY){SHIFT, 7};
    action_table[9][4] = (ACTION_ENTRY){REDUCE, 1};
    action_table[9][5] = (ACTION_ENTRY){REDUCE, 1};

    action_table[10][1] = (ACTION_ENTRY){REDUCE, 3};
    action_table[10][2] = (ACTION_ENTRY){REDUCE, 3};
    action_table[10][4] = (ACTION_ENTRY){REDUCE, 3};
    action_table[10][5] = (ACTION_ENTRY){REDUCE, 3};

    action_table[11][1] = (ACTION_ENTRY){REDUCE, 5};
    action_table[11][2] = (ACTION_ENTRY){REDUCE, 5};
    action_table[11][4] = (ACTION_ENTRY){REDUCE, 5};
    action_table[11][5] = (ACTION_ENTRY){REDUCE, 5};
}