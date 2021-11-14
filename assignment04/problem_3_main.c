#include <assert.h>
#include "stack.h"

int main()
{
    int result1;
    int result2;
    int testChar;
    
    // *******************************************************************
    // Test1: Retrieve item from an empty stack
    // *******************************************************************
    // Arrange:
    result1 = -1;
    testChar = -1;
    stack_init();
    
    // Act:
    result1 = stack_pop(&testChar);
      
    // Assert:
    assert(-1 == result1);
    assert(-1 == testChar);
    
    
    // *******************************************************************
    // Test2: Successfully retrieve an item from the stack
    // *******************************************************************
    // Arrange:
    result1 = -1;
    result2 = -1;
    testChar = -1;
    stack_init();
    
    // Act:
    result1 = stack_push(1);
    result2 = stack_pop(&testChar);
    
    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    assert(1 == testChar);
    
    
    // *******************************************************************
    // Test3: Fill stack, then get all items.
    // *******************************************************************
    // Arrange:
    testChar = -1;
    stack_init();
    
    // Act:
    stack_push(1);
    stack_push(2);
    stack_push(3);                                    
    
    // Assert:
    assert(0 == stack_pop(&testChar));
    assert(3 == testChar);

    assert(0 == stack_pop(&testChar));
    assert(2 == testChar);

    assert(0 == stack_pop(&testChar));
    assert(1 == testChar);

    
    // *******************************************************************
    // Test4: Fill stack, then put one more item, should fail
    // *******************************************************************
    // Arrange:
    testChar = -1;
    stack_init();
    
    // Act:
    stack_push(1);
    stack_push(2);
    stack_push(3);
    
    // Assert:
    assert(-1 == stack_push(4));

    assert(0 == stack_pop(&testChar));
    assert(3 == testChar);

    assert(0 == stack_pop(&testChar));
    assert(2 == testChar);

    assert(0 == stack_pop(&testChar));
    assert(1 == testChar);



    // ***********************************************************************
    // Test5: Fill stack, retrieve one item, then add item, then retieve all
    // ***********************************************************************
    // Arrange:
    testChar = -1;
    stack_init();
    
    // Act:
    stack_push(1);
    stack_push(2);
    stack_push(3);
    
    // Assert:
    assert(0 == stack_pop(&testChar));
    assert(3 == testChar);

    assert(0 == stack_push(4));

    assert(0 == stack_pop(&testChar));
    assert(4 == testChar);

    assert(0 == stack_pop(&testChar));
    assert(2 == testChar);

    assert(0 == stack_pop(&testChar));
    assert(1 == testChar);

    // ***********************************************************************
    // Test6: Fill stack and retrieve all items. Do it twice in a row.
    // ***********************************************************************
    // Arrange:
    testChar = -1;
    stack_init();
    
    // Act:
    stack_push(1);
    stack_push(2);
    stack_push(3);
    
    // Assert:
    assert(0 == stack_pop(&testChar));
    assert(3 == testChar);

    assert(0 == stack_pop(&testChar));
    assert(2 == testChar);

    assert(0 == stack_pop(&testChar));
    assert(1 == testChar);

    assert(0 == stack_push(4));
    assert(0 == stack_push(5));
    assert(0 == stack_push(6));
    
    assert(-1 == stack_push(-1));

    assert(0 == stack_pop(&testChar));
    assert(6 == testChar);
   
    assert(0 == stack_pop(&testChar));
    assert(5 == testChar);

    assert(0 == stack_pop(&testChar));
    assert(4 == testChar);

    return 0;
}
