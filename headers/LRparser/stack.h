#ifndef STACK_H
#define STACK_H

#define MAX 100

typedef enum
{
    STATE_ITEM,
    SYMBOL_ITEM,
} STACK_TYPE;

typedef struct
{
    STACK_TYPE type;

    union
    {
        int state;
        char symbol[10];
    } value;
} STACK_ITEM;

void init_stack();
void push_state(int state);
void push_symbol(const char* symbol);
void pop_item();
STACK_ITEM peek_item();
int is_stack_empty();
void print_stack();


#endif //STACK_H
