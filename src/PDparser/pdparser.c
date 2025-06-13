#include "../../headers/PDparser/stack.h"
#include "../../headers/PDparser/parsing_table.h"
#include "../../headers/PDparser/production_rule.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int is_nterminal(char c);
int get_terminal_index(char c);
int get_nonterminal_index(char c);
void get_stack_string(char* out);
void print_remaining_input(char* str, int start);
void print_parse_sequence(int* parse_seq, int len);

void pdparser(char* str)
{
    init_stack();
    push('$');
    push('S');

    int i = 0;
    int step = 1;
    int parse_seq[100] = {0};
    int parse_len = 0;

    printf("%-5s %-15s %-10s %-15s %-10s\n", "Step", "Stack", "Input", "Action", "Parse");

    while (!is_empty())
    {
        char st = peek();
        char input = str[i];

        // 1. 현재 스택 문자열 만들기
        char stack_str[100] = {0};
        get_stack_string(stack_str);

        // 2. 현재 입력 문자열 만들기
        char input_str[100] = {0};
        strncpy(input_str, str + i, sizeof(input_str) - 1);

        // 3. 논터미널
        if (is_nterminal(st))
        {
            int row = get_nonterminal_index(st);
            int col = get_terminal_index(input);

            if (row == -1 || col == -1)
            {
                printf("❌ 에러: 유효하지 않은 기호 (st=%c, input=%c)\n", st, input);
                return;
            }

            int rule_num = table[row][col];

            if (rule_num == 0)
            {
                printf("❌ 에러: 파싱 테이블에 규칙 없음 (st=%c, input=%c)\n", st, input);
                return;
            }

            pop();
            const char* rhs = production_rule[rule_num];

            for (int k = strlen(rhs) - 1; k >= 0; k--)
            {
                if (rhs[k] != ' ')
                    push(rhs[k]);
            }

            parse_seq[parse_len++] = rule_num;
            printf("%-5d %-15s %-10s %-15s ", step, stack_str, input_str, "expand");
            print_parse_sequence(parse_seq, parse_len);
        }
        // 4. 터미널
        else
        {
            if (st == input)
            {
                pop();
                i++;
                printf("%-5d %-15s %-10s %-15s ", step, stack_str, input_str, "pop & advance");
                print_parse_sequence(parse_seq, parse_len);
            }
            else
            {
                printf("❌ 에러: 터미널 불일치 (스택: %c, 입력: %c)\n", st, input);
                return;
            }
        }

        step++;
    }

    // 5. 성공 여부
    if (str[i] == '\0')
    {
        printf("%-5d %-15s %-10s %-15s ", step, "$", "$", "accept");
        print_parse_sequence(parse_seq, parse_len);
        printf("✅ 파싱 성공!\n");
    }
    else
    {
        printf("❌ 파싱 실패: 입력이 남아 있음 (%s)\n", &str[i]);
    }
}

int is_nterminal(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int get_nonterminal_index(char c)
{
    if (c == 'S') return 0;
    if (c == 'A') return 1;
    return -1;
}

int get_terminal_index(char c)
{
    if (c == 'a') return 0;
    if (c == 'b') return 1;
    if (c == 'c') return 2;
    if (c == 'd') return 3;
    if (c == '$') return 4;
    return -1;
}

// 스택을 문자열로 뒤집어서 복사
void get_stack_string(char* out)
{
    int idx = 0;
    for (int i = 0; i <= top; i++)
    {
        out[idx++] = stack[i];
    }
    out[idx] = '\0';
}

// 파싱된 규칙 번호 출력
void print_parse_sequence(int* parse_seq, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d", parse_seq[i]);
    printf("\n");
}
