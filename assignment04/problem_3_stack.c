#include "stack.h"
#define STACK_SIZE 3

// Backing store
int stackStore[STACK_SIZE];

// Pointers to stack elements for adding and retrieving
int* putPtr;
int* getPtr;

// FIFO stack is Empty if putPtr==getPtr;
// FIFO stack is Full if putPtr+1 > Address of last element in the stack;

// Initialize internals of the stack
void stack_init(void)
{
    putPtr = 0;
    getPtr = 0;
    for(int i=0; i<STACK_SIZE; i++)
    {
        stackStore[i] = '\0';
    }
}

// Add data to stack
// If stack is full return error
// Otherwise return success
int stack_push(int data)
{
    // stack is full
    if (getPtr == stackStore && putPtr == &stackStore[STACK_SIZE-1])
    {
        return -1;
    }
    
    //stack is empty
    if (getPtr == putPtr+1)
    {
        return -1;
    }
    
    // If getPtr has not been set
    if (getPtr == 0)
    {
        getPtr = &stackStore[0];
    }    
    
    // If putPtr has not been set OR putPtr is at the end of the stack
    if (putPtr == 0 || putPtr == &stackStore[STACK_SIZE-1])
    {
        putPtr = &stackStore[0];
    }
    else
    {
        putPtr++;
    }
    
    *putPtr = data;
    return 0;
}

// Get data from stack
// If stack is empty return error
// Otherwise return success
int stack_pop(int* data)
{   
    // stack is empty
    if (getPtr == 0)
    {
        return -1;
    }

    *data = *getPtr;
    
    // Reset getPtr & putPtr if stack becomes empty
    if (getPtr == putPtr)
    {
        
        getPtr = 0;
        putPtr = 0;
    }
    else if (getPtr == &stackStore[STACK_SIZE-1])
    {
        // wrap
        getPtr = &stackStore[0];
    }
    else
    {
        getPtr++;
    }
    
    return 0;
}
