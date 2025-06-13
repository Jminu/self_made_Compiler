/*
 * lex함수는 스트링을 읽어서 토큰을 반환하는 함수
 */

#include "../../headers/lex/states_and_tokens.h"
#include <string.h>
#include "../../headers/lex/input_symbol.h"
#include "../../headers/lex/transition_table.h"

TOKEN lex(const char* input, int start_idx, int* read_len)
{
    int i = start_idx;
    while (get_input_symbol(input[i]) == WHITESPACE && i < strlen(input)) // 공백 뛰어넘기
    {
        i++;
    }
    int lexeme_start = i;

    STATE cur_state = s_start;
    STATE next_state = -1;
    STATE last_state = -1;
    int last_pos = -1;

    //전이
    for (; i < strlen(input); i++)
    {
        INPUT_SYMBOL input_symbol = get_input_symbol(input[i]); // 입력값에 대한 심볼가져옴
        next_state = transition_table[cur_state][input_symbol]; // 다음 상태 찾음(상태전이 테이블에서)

        if (next_state == -1) // 전이 실패
        {
            if (cur_state == s_in_decimal) last_state = s_acc_decimal;
            else if (cur_state == s_in_id) last_state = s_acc_id;
            if (last_state != -1) last_pos = i - 1;
            break;
        }

        cur_state = next_state;
        switch (cur_state)
        {
        /*
         * 만약, 현재상태가 수용상태에 도달하면
         * 토큰으로 매핑해야함
         */
        case s_acc_id:
        case s_acc_decimal:
        case s_acc_not_bang:
        case s_acc_remain_assign:
        case s_acc_remain:
        case s_acc_logical_or:
        case s_acc_logical_bit_or:
        case s_acc_open_parentheses:
        case s_acc_close_parentheses:
        case s_acc_open_brace:
        case s_acc_close_brace:
        case s_acc_open_bracket:
        case s_acc_close_bracket:
        case s_acc_mul:
        case s_acc_plusplus:
        case s_acc_plus_assign:
        case s_acc_add:
        case s_acc_minusminus:
        case s_acc_minus_assign:
        case s_acc_sub:
        case s_acc_share_assign:
        case s_acc_share:
        case s_acc_logical_equal:
        case s_acc_assign:
        case s_acc_smaller_equal:
        case s_acc_smaller_than:
        case s_acc_greater_equal:
        case s_acc_greater_than:
        case s_acc_comma:
        case s_acc_semicolon:
            last_state = cur_state; // 수용상태 찾음 -> 마지막 상태 저장
            last_pos = i; // 마지막 위치 기록
            break;
        default:
            break;
        }
    }

    if (last_state == -1) // 다 돌았는데도 last_state가 -1이면 수용상태에 도달하지 못했음!
    {
        *read_len = 1;
        return t_error;
    }

    *read_len = last_pos - lexeme_start + 1; // 읽은 길이
    // 마지막 상태를 토큰으로 매핑
    switch (last_state)
    {
    case s_acc_id: return t_id;
    case s_acc_decimal: return t_decimal;
    case s_acc_not_bang: return t_logical_bang;
    case s_acc_remain_assign: return t_remain_assign;
    case s_acc_remain: return t_remain;
    case s_acc_logical_or: return t_logical_or;
    case s_acc_logical_bit_or: return t_logical_bit_or;
    case s_acc_open_parentheses: return t_open_parentheses;
    case s_acc_close_parentheses: return t_close_parentheses;
    case s_acc_open_brace: return t_open_brace;
    case s_acc_close_brace: return t_close_brace;
    case s_acc_open_bracket: return t_open_bracket;
    case s_acc_close_bracket: return t_close_bracket;
    case s_acc_mul: return t_mul;
    case s_acc_plusplus: return t_plusplus;
    case s_acc_plus_assign: return t_plus_assign;
    case s_acc_add: return t_add;
    case s_acc_minusminus: return t_minusminus;
    case s_acc_minus_assign: return t_minus_assign;
    case s_acc_sub: return t_sub;
    case s_acc_share_assign: return t_share_assign;
    case s_acc_share: return t_share;
    case s_acc_logical_equal: return t_logical_equal;
    case s_acc_assign: return t_assign;
    case s_acc_smaller_equal: return t_smaller_equal;
    case s_acc_smaller_than: return t_smaller_than;
    case s_acc_greater_equal: return t_greater_equal;
    case s_acc_greater_than: return t_greater_than;
    case s_acc_comma: return t_comma;
    case s_acc_semicolon: return t_semicolon;
    }
}
