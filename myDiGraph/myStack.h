#ifndef MYSTACK_H
#define MYSTACK_H

// Data structure for the stack
typedef struct S_StackType
{
    int maxSize;    // Stack' maximum capacity
    int top;        // Index to the current top element in stack
    int* items;     // Pointer to array of thw stack's elements

} T_StackType;

/* Initialize Stack data structure */
T_StackType* initNewStack(int capacity);

/* Return the number of elements in stack */
int myStack_Size(const T_StackType* pSelf);



#endif
