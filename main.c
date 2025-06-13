#include <stdio.h>
#include "headers/LRparser/ACTIONtable.h"
#include "headers/LRparser/GOTOtable.h"
#include "headers/LRparser/parser.h"

int main()
{
    // 입력 문자열을 토큰 배열로 정의 (종료 기호 반드시 포함)
    const char* input1[] = {"id", "+", "id", "*", "id", "$", NULL};
    const char* input2[] = {"id", "*", "id", "+", "id", "$", NULL};
    const char* input3[] = {"(", "id", "+", "id", ")", "*", "id", "$", NULL};


    // 테이블 초기화
    init_action_table();
    init_goto_table();

    // 파싱 수행
    parse_input(input2);

    return 0;
}
