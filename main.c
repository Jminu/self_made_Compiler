#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "headers/transition_table.h"
#include "headers/lex.h"


int main()
{
    char input[256];
    printf("입력 : ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // 개행 제거

    init_transition_table(); // DFA 전이 테이블 초기화

    int i = 0;
    while (i < strlen(input))
    {
        int read_len = 0;
        TOKEN token = lex(input, i, &read_len);

        char lexeme[64] = {0};
        strncpy(lexeme, input + i, read_len);
        lexeme[read_len] = '\0';

        // 뒤쪽 공백 제거
        int L = strlen(lexeme);
        while (L > 0 && isspace((unsigned char)lexeme[L-1])) {
            lexeme[--L] = '\0';
        }

        if (token == t_id)
        {
            if (strcmp(lexeme, "int") == 0) token = t_kw_int;
            else if (strcmp(lexeme, "return") == 0) token = t_kw_return;
            else if (strcmp(lexeme, "if") == 0) token = t_kw_if;
            else if (strcmp(lexeme, "else") == 0) token = t_kw_else;
            else if (strcmp(lexeme, "while") == 0) token = t_kw_while;
            else if (strcmp(lexeme, "const") == 0) token = t_kw_const;
            else if (strcmp(lexeme, "void") == 0) token = t_kw_void;
        }

        if (token == t_error)
        {
            printf("[Error] 알 수 없는 토큰: '%c'\n", input[i]);
            i += 1;
            continue;
        }

        printf("TOKEN: %d LEXEME: ", token);
        for (int j = i; j < i + read_len; j++)
            putchar(input[j]);
        printf(" (%s)\n", token_to_string(token));

        i += read_len;
    }

    return 0;
}
