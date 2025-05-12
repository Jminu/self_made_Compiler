//
// 상태전이 테이블 관련
//


#include "../headers/transition_table.h"
#include "../headers/input_symbol.h"
#include <string.h>

//테이블 초기화
void init_transition_table()
{
    for (int i = 0; i < STATE_COUNT; i++)
        memset(transition_table[i], -1, INPUT_SYMBOL_COUNT); // 일단 -1로 테이블 초기화

    /*-----식별자-----*/
    transition_table[s_start][LETTER] = s_in_id;
    transition_table[s_in_id][LETTER] = s_in_id;
    transition_table[s_in_id][DIGIT] = s_in_id;

    /*-----숫자-----*/
    transition_table[s_start][DIGIT] = s_in_decimal;
    transition_table[s_in_decimal][DIGIT] = s_in_decimal;
}

STATE get_next_state(STATE cur_state, INPUT_SYMBOL input_symbol)
{
    return transition_table[cur_state][input_symbol]; // 다음 상태를 반환
}
