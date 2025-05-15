#include "../headers/states_and_tokens.h"

#include "../headers/states_and_tokens.h"

const char* token_to_string(TOKEN token)
{
    switch (token)
    {
    case t_id: return "t_id";
    case t_decimal: return "t_decimal";
    case t_logical_bang: return "t_logical_bang";
    case t_not_bang: return "t_not_bang";
    case t_remain_assign: return "t_remain_assign";
    case t_remain: return "t_remain";
    case t_logical_and: return "t_logical_and";
    case t_logical_bit_and: return "t_logical_bit_and";
    case t_logical_or: return "t_logical_or";
    case t_logical_bit_or: return "t_logical_bit_or";
    case t_open_parentheses: return "t_open_parentheses";
    case t_close_parentheses: return "t_close_parentheses";
    case t_open_brace: return "t_open_brace";
    case t_close_brace: return "t_close_brace";
    case t_open_bracket: return "t_open_bracket";
    case t_close_bracket: return "t_close_bracket";
    case t_mul: return "t_mul";
    case t_plusplus: return "t_plusplus";
    case t_plus_assign: return "t_plus_assign";
    case t_add: return "t_add";
    case t_minusminus: return "t_minusminus";
    case t_minus_assign: return "t_minus_assign";
    case t_sub: return "t_sub";
    case t_share_assign: return "t_share_assign";
    case t_share: return "t_share";
    case t_logical_equal: return "t_logical_equal";
    case t_assign: return "t_assign";
    case t_smaller_equal: return "t_smaller_equal";
    case t_smaller_than: return "t_smaller_than";
    case t_greater_equal: return "t_greater_equal";
    case t_greater_than: return "t_greater_than";
    case t_comma: return "t_comma";
    case t_semicolon: return "t_semicolon";
    case t_kw_const: return "t_kw_const";
    case t_kw_if: return "t_kw_if";
    case t_kw_else: return "t_kw_else";
    case t_kw_while: return "t_kw_while";
    case t_kw_return: return "t_kw_return";
    case t_kw_int: return "t_kw_int";
    case t_kw_void: return "t_kw_void";
    case t_error: return "t_error";
    default: return "unknown_token";
    }
}
