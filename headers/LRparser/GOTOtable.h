#ifndef GOTOTABLE_H
#define GOTOTABLE_H

#define STATE_COUNT 12
#define NON_TERMINAL_COUNT 3


int goto_table[STATE_COUNT][NON_TERMINAL_COUNT]; // 다음 상태 번호

void init_goto_table();
int get_nonterminal_index(char sym);

#endif //GOTOTABLE_H
