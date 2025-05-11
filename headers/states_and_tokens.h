//
// Created by 진민우 on 2025. 5. 9..
//

#ifndef STATES_AND_TOKENS_H
#define STATES_AND_TOKENS_H

typedef enum
{
    //s_ 접두사는 STATE를 의미한다.
    //-----General Tokens-----//
    //identifier DFA
    s_start,
    s_in_id,
    s_acc_id,

    //numbers DFA
    s_in_decimal,
    s_acc_decimal,

    //-----Special Symbols-----//

    //start with !
    s_after_bang,
    s_acc_logical_bang,
    s_acc_not_bang,

    //start with %
    s_after_percent,
    s_acc_remain_assign,
    s_acc_remain,

    //start with &, |
    s_after_ampersand,
    s_acc_logical_and,
    s_acc_logical_bit_and,

    s_after_vertical,
    s_acc_logical_or,
    s_acc_logical_bit_or,

    //start with 괄호들
    s_acc_open_parentheses, // (
    s_acc_close_parentheses, // )
    s_acc_open_brace, // {
    s_acc_close_brace, // }
    s_acc_open_bracket, // [
    s_acc_close_bracket, // ]

    //start with *
    s_after_star,
    s_acc_mul_assign,
    s_acc_mul,

    //start with +, -
    s_after_plus,
    s_acc_plusplus, // ++
    s_acc_plus_assign, // +=
    s_acc_add, // +
    s_after_minus,
    s_acc_minusminus, // --
    s_acc_minus_assign, // -=
    s_acc_sub, // -

    //start with /, =
    s_after_slash,
    s_acc_share_assign, // /=
    s_acc_share, // /
    s_after_equal,
    s_acc_logical_equal, // ==
    s_acc_assign, // =

    //start with <, >
    s_after_smaller,
    s_acc_smaller_equal, // <=
    s_acc_smaller_than, // <
    s_after_greater,
    s_acc_greater_equal, // >=
    s_acc_greater_than, // >

    //start with , ;
    s_acc_comma,
    s_acc_semicolon,
} STATE;

typedef enum
{
    //t_ 접두사는 TOKEN을 의미한다.
    //-----General Token-----//
    t_id,
    t_decimal,

    //-----Special Token-----//
    t_logical_bang,
    t_not_bang,

    t_remain_assign,
    t_remain,

    t_logical_and,
    t_logical_bit_and,

    t_logical_or,
    t_logical_bit_or,

    t_open_parentheses,
    t_close_parentheses,
    t_open_brace,
    t_close_brace,
    t_open_bracket,
    t_close_bracket,

    t_mul_assign,
    t_mul,

    t_plusplus,
    t_plus_assign,
    t_add,

    t_minusminus,
    t_minus_assign,
    t_sub,

    t_share_assign,
    t_share,

    t_logical_equal,
    t_assign,

    t_smaller_equal,
    t_smaller_than,

    t_greater_equal,
    t_greater_than,

    t_comma,
    t_semicolon,

    //-----keyword용 토큰-----//
    t_kw_const,
    t_kw_if,
    t_kw_else,
    t_kw_while,
    t_kw_return,
    t_kw_int,
    t_kw_void
} TOKEN;

#endif //STATES_AND_TOKENS_H
