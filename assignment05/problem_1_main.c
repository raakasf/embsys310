#include <assert.h>

void swap_pointer(int** a, int** b);

void swap_pointer(int** a, int** b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int x = 2000000;
    int y = 1000000;
    int* xPtr = &x;
    int* yPtr = &y;
    
    swap_pointer(&xPtr, &yPtr);
    
    assert(xPtr == &y);
    assert(yPtr == &x);
    assert(x == 2000000);
    assert(y == 1000000);
    
    return 0;
}