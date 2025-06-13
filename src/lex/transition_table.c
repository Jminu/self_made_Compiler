//
// 상태전이 테이블 관련
//


#include "../../headers/lex/transition_table.h"
#include "../../headers/lex/input_symbol.h"
#include <string.h>

//테이블 초기화
void init_transition_table()
{
    for (int i = 0; i < STATE_COUNT; i++)
        memset(transition_table[i], -1, sizeof(STATE) * INPUT_SYMBOL_COUNT); // 일단 -1로 테이블 초기화

    // 2) Identifier DFA (s_start, s_in_id -> s_acc_id)
    transition_table[s_start][LETTER] = s_in_id;
    transition_table[s_in_id][LETTER] = s_in_id;
    transition_table[s_in_id][DIGIT] = s_in_id;
    transition_table[s_in_id][WHITESPACE] = s_acc_id;
    transition_table[s_in_id][SYMBOL_EOF] = s_acc_id;

    // 3) Number DFA (s_start, s_in_decimal -> s_acc_decimal)
    transition_table[s_start][DIGIT] = s_in_decimal;
    transition_table[s_in_decimal][DIGIT] = s_in_decimal;
    transition_table[s_in_decimal][WHITESPACE] = s_acc_decimal;
    transition_table[s_in_decimal][SYMBOL_EOF] = s_acc_decimal;

    // 4) !, != DFA (s_start, s_after_bang -> s_acc_not_bang / s_acc_logical_bang)
    transition_table[s_start][BANG] = s_after_bang;
    transition_table[s_after_bang][EQUAL] = s_acc_not_bang;
    transition_table[s_after_bang][WHITESPACE] = s_acc_logical_bang;
    transition_table[s_after_bang][SYMBOL_EOF] = s_acc_logical_bang;

    // 5) % , %= DFA
    transition_table[s_start][PERCENT] = s_after_percent;
    transition_table[s_after_percent][EQUAL] = s_acc_remain_assign;
    transition_table[s_after_percent][WHITESPACE] = s_acc_remain;
    transition_table[s_after_percent][SYMBOL_EOF] = s_acc_remain;

    // 6) &, && DFA
    transition_table[s_start][AMPERSAND] = s_after_ampersand;
    transition_table[s_after_ampersand][AMPERSAND] = s_acc_logical_and;
    transition_table[s_after_ampersand][WHITESPACE] = s_acc_logical_bit_and;
    transition_table[s_after_ampersand][SYMBOL_EOF] = s_acc_logical_bit_and;

    // 7) |, || DFA
    transition_table[s_start][VERTICAL] = s_after_vertical;
    transition_table[s_after_vertical][VERTICAL] = s_acc_logical_or;
    transition_table[s_after_vertical][WHITESPACE] = s_acc_logical_bit_or;
    transition_table[s_after_vertical][SYMBOL_EOF] = s_acc_logical_bit_or;

    // 8) Parentheses, Braces, Brackets, Comma, Semicolon
    transition_table[s_start][OPEN_PAREN] = s_acc_open_parentheses;
    transition_table[s_start][CLOSE_PAREN] = s_acc_close_parentheses;
    transition_table[s_start][OPEN_BRACE] = s_acc_open_brace;
    transition_table[s_start][CLOSE_BRACE] = s_acc_close_brace;
    transition_table[s_start][OPEN_BRACKET] = s_acc_open_bracket;
    transition_table[s_start][CLOSE_BRACKET] = s_acc_close_bracket;
    transition_table[s_start][COMMA] = s_acc_comma;
    transition_table[s_start][SEMICOLON] = s_acc_semicolon;

    // 9) *, *= DFA
    transition_table[s_start][STAR] = s_after_star;
    transition_table[s_after_star][EQUAL] = s_acc_mul_assign;
    transition_table[s_after_star][WHITESPACE] = s_acc_mul;
    transition_table[s_after_star][SYMBOL_EOF] = s_acc_mul;

    // 10) +, ++, += DFA
    transition_table[s_start][PLUS] = s_after_plus;
    transition_table[s_after_plus][PLUS] = s_acc_plusplus;
    transition_table[s_after_plus][EQUAL] = s_acc_plus_assign;
    transition_table[s_after_plus][WHITESPACE] = s_acc_add;
    transition_table[s_after_plus][SYMBOL_EOF] = s_acc_add;

    // 11) -, --, -= DFA
    transition_table[s_start][MINUS] = s_after_minus;
    transition_table[s_after_minus][MINUS] = s_acc_minusminus;
    transition_table[s_after_minus][EQUAL] = s_acc_minus_assign;
    transition_table[s_after_minus][WHITESPACE] = s_acc_sub;
    transition_table[s_after_minus][SYMBOL_EOF] = s_acc_sub;

    // 12) /, /= DFA
    transition_table[s_start][SLASH] = s_after_slash;
    transition_table[s_after_slash][EQUAL] = s_acc_share_assign;
    transition_table[s_after_slash][WHITESPACE] = s_acc_share;
    transition_table[s_after_slash][SYMBOL_EOF] = s_acc_share;

    // 13) =, == DFA
    transition_table[s_start][EQUAL] = s_after_equal;
    transition_table[s_after_equal][EQUAL] = s_acc_logical_equal;
    transition_table[s_after_equal][WHITESPACE] = s_acc_assign;
    transition_table[s_after_equal][SYMBOL_EOF] = s_acc_assign;

    // 14) <, <= DFA (input_symbol.h에 SMALLER/LESS 추가 필요)
    transition_table[s_start][SMALLER] = s_after_smaller;
    transition_table[s_after_smaller][EQUAL] = s_acc_smaller_equal;
    transition_table[s_after_smaller][WHITESPACE] = s_acc_smaller_than;
    transition_table[s_after_smaller][SYMBOL_EOF] = s_acc_smaller_than;

    // 15) >, >= DFA (input_symbol.h에 GREATER 추가 필요)
    transition_table[s_start][GREATER] = s_after_greater;
    transition_table[s_after_greater][EQUAL] = s_acc_greater_equal;
    transition_table[s_after_greater][WHITESPACE] = s_acc_greater_than;
    transition_table[s_after_greater][SYMBOL_EOF] = s_acc_greater_than;
}

STATE get_next_state(STATE cur_state, INPUT_SYMBOL input_symbol)
{
    return transition_table[cur_state][input_symbol]; // 다음 상태를 반환
}
