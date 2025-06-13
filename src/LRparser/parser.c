#include <stdio.h>
#include <string.h>
#include "../../headers/LRparser/parser.h"
#include "../../headers/LRparser/stack.h"
#include "../../headers/LRparser/ACTIONtable.h"
#include "../../headers/LRparser/GOTOtable.h"

typedef struct {
    const char* lhs;
    int rhs_len;
} Production;

Production rules[] = {
    {"S", 1},      // dummy (0-based index)
    {"E", 3},      // 1: E → E + T
    {"E", 1},      // 2: E → T
    {"T", 3},      // 3: T → T * F
    {"T", 1},      // 4: T → F
    {"F", 3},      // 5: F → ( E )
    {"F", 1}       // 6: F → id
};

int get_terminal_index(const char* symbol) {
    if (strcmp(symbol, "id") == 0) return 0;
    if (strcmp(symbol, "+") == 0) return 1;
    if (strcmp(symbol, "*") == 0) return 2;
    if (strcmp(symbol, "(") == 0) return 3;
    if (strcmp(symbol, ")") == 0) return 4;
    if (strcmp(symbol, "$") == 0) return 5;
    return -1;
}

void print_input(const char* input[], int ip) {
    for (int i = ip; input[i] != NULL; i++) {
        printf("%s ", input[i]);
    }
}

void parse_input(const char* input[]) {
    init_stack();
    push_state(0);

    int ip = 0;
    int step = 1;

    while (1) {
        STACK_ITEM top_item = peek_item();
        int state = (top_item.type == STATE_ITEM) ? top_item.value.state : -1;

        const char* current_token = input[ip];
        int terminal_index = get_terminal_index(current_token);
        ACTION_ENTRY action = action_table[state][terminal_index];

        printf("%-5d ", step++);
        print_stack();
        printf("\t");
        print_input(input, ip);
        printf("\t");

        if (action.type == SHIFT) {
            printf("shift %d\n", action.value);
            push_symbol(current_token);
            push_state(action.value);
            ip++;
        } else if (action.type == REDUCE) {
            int rule_no = action.value;
            int pop_count = rules[rule_no].rhs_len * 2;
            for (int i = 0; i < pop_count; i++) pop_item();

            STACK_ITEM top_after_pop = peek_item();
            int prev_state = (top_after_pop.type == STATE_ITEM) ? top_after_pop.value.state : -1;

            const char* lhs = rules[rule_no].lhs;
            int lhs_index = get_nonterminal_index(lhs[0]);

            printf("reduce %d: %s → (len=%d)\n", rule_no, lhs, rules[rule_no].rhs_len);

            push_symbol(lhs);
            push_state(goto_table[prev_state][lhs_index]);
        } else if (action.type == ACCEPT) {
            printf("accept\n");
            break;
        } else {
            printf("syntax error\n");
            break;
        }
    }
}
