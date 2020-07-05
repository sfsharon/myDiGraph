#ifndef MYSTACK_H
#define MYSTACK_H

// Data structure for the stack
typedef struct S_StackType
{
    int maxSize;    // Stack' maximum capacity
    int top;        // Index to the current top element in stack
    int* items;     // Pointer to array of thw stack's elements

    int(*size)(const struct T_StackType* pSelf);
} T_StackType;

T_StackType* initNewStack(int capacity);

#endif
