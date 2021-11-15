#include<assert.h>
#include"queue.h"

int main()
{
    int TEST_STACK_SIZE = 3;
    // *******************************************************************
    // Case: initialize stack, check empty and full condition
    // *******************************************************************
    stack_init();
    assert(is_stack_empty() == 1);
    assert(is_stack_full() == 0);
    
    // *******************************************************************
    // Case: pop an empty stack
    // *******************************************************************
    assert(is_stack_empty() == 1);
    assert(-1 == stack_pop());
    assert(is_stack_empty() == 1);
    
    // *******************************************************************
    // Case: add an element to the stack, stack shouldn't be empty nor full
    // *******************************************************************
    stack_push(1);
    assert(is_stack_empty() == 0);
    assert(is_stack_full() == 0);
    
    // *******************************************************************
    // Case: fill the stack to size, stack should be full
    //       then pop them all, stack should be empty
    // *******************************************************************    
    stack_init();
    stack_push(1);
    stack_push(2);
    stack_push(3);
    assert(is_stack_full() == 1);
    
    int result1 = stack_pop();
    assert(result1 == 3);
    
    result1 = stack_pop();
    assert(result1 == 2);
    
    result1 = stack_pop();
    assert(result1 == 1);
    assert(is_stack_empty() == 1);

    // *******************************************************************
    // Case: Full stack, pushing another item should fail
    // *******************************************************************
    stack_init();
    for (int i = 0; i < TEST_STACK_SIZE; i++) 
    {
        stack_push(i);
    }
    
    assert(-1 == stack_push(4));  
    
    return 0;
}