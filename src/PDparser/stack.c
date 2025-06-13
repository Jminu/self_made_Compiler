#include <stdio.h>
#include "../../headers/PDparser/stack.h"
#define MAX 100

char stack[MAX]; // 전역 배열 정의
int top = -1; // 전역 변수 정의

int is_empty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int is_full()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

void push(char item)
{
    if (is_full() == 1)
    {
        return;
    }

    top++;
    stack[top] = item;
}


int peek()
{
    return stack[top];
}

void pop()
{
    if (is_empty() == 1)
    {
        return;
    }

    top--;
}

void print_stack()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%c", stack[i]);
    }
}

void init_stack()
{
    top = -1;
}
