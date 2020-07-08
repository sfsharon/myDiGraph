#ifndef MYSTACK_H
#define MYSTACK_H

/* ----------------------------------------------------- 
 *  Data structure for the stack 
 * -----------------------------------------------------  */
typedef struct S_StackType
{
    int maxSize;    // Stack' maximum capacity
    int top;        // Index to the current top element in stack
    int* items;     // Pointer to array of thw stack's elements

} T_StackType;

/* -----------------------------------------------------
 *  Stack object functions
 * -----------------------------------------------------  */
/* Constructor Stack */
T_StackType* myStack_ctor(int capacity);

/* Destructor Stack */
void myStack_dtor(T_StackType* pSelf);

/* Return the number of elements in stack */
int myStack_Size(const T_StackType* pSelf);

/* Utility function to check if the stack is empty */
int myStack_isEmpty(const T_StackType* pSelf);

/* Utility function to check if the stack is full */
int myStack_isFull(const T_StackType* pSelf);

/* Utility function to add an element x in the stack */
void myStack_push(T_StackType* pSelf, int x);

/* Utility function to return the top element in the stack */
int myStack_peek(const T_StackType* pSelf);

/* Utility function to pop top element from the stack */
int myStack_pop(T_StackType* pSelf);

#endif
