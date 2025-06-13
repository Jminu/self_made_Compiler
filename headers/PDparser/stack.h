#ifndef STACK_H
#define STACK_H

#define MAX 100
extern char stack[MAX];
extern int top;

int is_empty();
int is_full();
void push(char item);
int peek();
void pop();
void print_stack();
void init_stack();



#endif //STACK_H
