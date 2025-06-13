#ifndef ACTIONTABLE_H
#define ACTIONTABLE_H

#define STATE_COUNT 12
#define TERMINAL_COUNT 6

typedef enum
{
    SHIFT,
    REDUCE,
    ACCEPT,
    ERROR
} ACTION_TYPE;

typedef struct
{
    ACTION_TYPE type;
    int value; // SHIFT / REDUCE시 규칙 번호
} ACTION_ENTRY;

ACTION_ENTRY action_table[STATE_COUNT][TERMINAL_COUNT];

void init_action_table();


#endif //ACTIONTABLE_H
