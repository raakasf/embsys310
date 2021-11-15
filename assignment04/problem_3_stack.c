#include "stack.h"
#define STACK_SIZE 3

int stackStore[STACK_SIZE];

int top;

// Initialize internals of the stack
void stack_init(void)
{
    top = 0;
    for(int i = 0; i < STACK_SIZE; i++)
    {
        stackStore[i] = 0;
    }
}

int is_stack_empty()
{
    return top == 0;
}

int is_stack_full()
{
    return top == STACK_SIZE;
}

int stack_push(int data)
{
    if(!is_stack_full())
    {
        stackStore[top++] = data;
    }
    else
    {
        return -1;
    }
    return 0;
}

int stack_pop()
{   
    if(!is_stack_empty())
    {
        return stackStore[--top];
    }
    else
    {
        return -1;
    }
}
