//
// input_symbol 관련
//
#include "../../headers/lex/input_symbol.h"
#include <ctype.h>

int get_input_symbol(char ch)
{
    if (isalpha((unsigned char)ch) || ch == '_') // 알파벳이면
        return LETTER;

    if (isdigit((unsigned char)ch)) // 숫자면
        return DIGIT;

    switch (ch) //그 외 기호면
    {
    case '+': return PLUS;
    case '-': return MINUS;
    case '*': return STAR;
    case '/': return SLASH;
    case '%': return PERCENT;
    case '!': return BANG;
    case '=': return EQUAL;
    case '&': return AMPERSAND;
    case '|': return VERTICAL;
    case '(': return OPEN_PAREN;
    case ')': return CLOSE_PAREN;
    case '{': return OPEN_BRACE;
    case '}': return CLOSE_BRACE;
    case '[': return OPEN_BRACKET;
    case ']': return CLOSE_BRACKET;
    case ';': return SEMICOLON;
    case ',': return COMMA;
    case '<': return SMALLER;
    case '>': return GREATER;
    case ' ': return WHITESPACE;
    case '\0': return SYMBOL_EOF;
    }

    //모르는 기호면
    return UNKNOWN;
}
