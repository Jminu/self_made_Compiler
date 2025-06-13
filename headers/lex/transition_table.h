//
// transition_table을 정의
// 상태에 대해서, 특정 인풋심볼이 들어오면 다른 상태로 전이되는 테이블

#ifndef TRANSITION_TABLE_H
#define TRANSITION_TABLE_H

#include  "states_and_tokens.h"
#include "input_symbol.h"

#define STATE_COUNT 48 // 현재 이 어휘분석기에서 상태는 48, 입력 심볼은 22개이다.
#define INPUT_SYMBOL_COUNT 24

STATE transition_table[STATE_COUNT][INPUT_SYMBOL_COUNT]; // 테이블 선언
STATE get_next_state(STATE cur_state, INPUT_SYMBOL input_symbol); // 현재 상태에서 입력받았을때의 다음 상태 가져옴
void init_transition_table(); // 상태 전이 테이블 초기화

#endif //TRANSITION_TABLE_H
