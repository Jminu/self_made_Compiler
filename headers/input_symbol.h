//
// input symbol을 정의함
//

#ifndef INPUT_SYMBOL_H
#define INPUT_SYMBOL_H

#define INPUT_SYMBOL_COUNT 30  // 문자 유형 개수

typedef enum
{
    LETTER, // a~zA~Z, _
    DIGIT, // 0~9
    PLUS, // +
    MINUS, // -
    STAR, // *
    SLASH, // /
    PERCENT, // %
    BANG, // !
    EQUAL, // =
    AMPERSAND, // &
    VERTICAL, // |
    OPEN_PAREN, // (
    CLOSE_PAREN, // )
    OPEN_BRACE, // {
    CLOSE_BRACE, // }
    OPEN_BRACKET, // [
    CLOSE_BRACKET, // ]
    SEMICOLON, // ;
    COMMA, // ,

    WHITESPACE, // 공백
    UNKNOWN, //모르는 문자
    SYMBOL_EOF //파일의 끝
} INPUT_SYMBOL;

int get_input_symbol(char ch);

#endif //INPUT_SYMBOL_H
