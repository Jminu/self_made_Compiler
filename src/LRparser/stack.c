#include <stdio.h>
#include <string.h>
#include "../../headers/LRparser/stack.h"

static STACK_ITEM stack[MAX];
static int top = -1;

void init_stack() {
    top = -1;
}

void push_state(int state) {
    if (top < MAX - 1) {
        top++;
        stack[top].type = STATE_ITEM;
        stack[top].value.state = state;
    } else {
        printf("Stack overflow (state)\n");
    }
}

void push_symbol(const char* symbol) {
    if (top < MAX - 1) {
        top++;
        stack[top].type = SYMBOL_ITEM;
        strncpy(stack[top].value.symbol, symbol, sizeof(stack[top].value.symbol));
        stack[top].value.symbol[sizeof(stack[top].value.symbol) - 1] = '\0'; // null-terminate
    } else {
        printf("Stack overflow (symbol)\n");
    }
}

void pop_item() {
    if (top >= 0) {
        top--;
    } else {
        printf("Stack underflow\n");
    }
}

STACK_ITEM peek_item() {
    if (top >= 0) {
        return stack[top];
    } else {
        // 오류 상태 반환
        STACK_ITEM error_item;
        error_item.type = STATE_ITEM;
        error_item.value.state = -1;
        return error_item;
    }
}

int is_stack_empty() {
    return top == -1;
}

void print_stack() {
    for (int i = 0; i <= top; i++) {
        if (stack[i].type == STATE_ITEM)
            printf("%d ", stack[i].value.state);
        else
            printf("%s ", stack[i].value.symbol);
    }
}
