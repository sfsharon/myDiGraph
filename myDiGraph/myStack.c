/*
* *****************************************************
*              myStack module.
* *****************************************************
*
* Program functionality :
* -----------------------
* Implement an integer stack
* Implementation :
               - An int array the size of 'capcity' for saving integers is created. 
*                Empty stack implies variable 'top' for stack index to be '-1'.
* Comments : Implementation uses dynamic allocation. TODO : 
*           1. Create a new implemention, using a static memory allocation solution (global staic variable in module 'myStack').
*           2. Check error for malloc, and decide on error handling procedure.
*           3. Make sure that calling module will free memory after intialization 
*
* Based on implementation from https://www.techiedelight.com/stack-implementation/
*
*/


#include <stdio.h>
#include <stdlib.h>

#include "myStack.h"

T_StackType* initNewStack(int capacity)
{
    /*
    * Initialize stack management and array data. 
    * An int array the size of 'capcity' for saving integers is created.
    * Empty stack implies that the stack index variable 'top' value is '-1'.
    */

    // Create object attributes
    // --------------------------------------
    // Allocate memory for the Stack management's data structure
    T_StackType* pStack = (T_StackType*)malloc(sizeof(T_StackType));
    // malloc error handling
    if (pStack == NULL) {
        printf(">>> initNewStack : Error initializing Stack management data\n");
        return NULL;
    }
    // Initialize Stack's internal management variables
    pStack->maxSize = capacity;
    pStack->top = -1;
    // Allocate memory for the Stack's integer array data
    pStack->items = (int*)malloc(sizeof(int) * capacity);
    // malloc error handling
    if (pStack->items == NULL) {
        printf(">>> initNewStack : Error initializing Stack array data\n");
        return NULL;
    }
}

int myStack_Size(const T_StackType* pSelf) {
    return (pSelf->top + 1);
}

int myStack_isEmpty(const T_StackType* pSelf) {
    /* Utility function to check if the stack is empty */
    return (pSelf->top == -1);
}

int myStack_isFull(const T_StackType* pSelf) {
    /* Utility function to check if the stack is full */
    return (pSelf->top == pSelf->maxSize -1);
}

void myStack_push(T_StackType* pSelf, int x) {
    /* Utility function to add an element x in the stack */

    // Verify stack is not full
    if (myStack_isFull(pSelf))
    {
        printf(">>> myStack_push : Overflow. Terminating\n");
        exit(EXIT_FAILURE);
    }

    printf(">>> myStack_push : Inserting %d\n", x);

    // Add an element, and increment the top index
    pSelf->top++;
    pSelf->items[pSelf->top] = x;

}

int myStack_peek(const T_StackType* pSelf)
    /* Utility function to return the top element in the stack */
{
    if (!myStack_isEmpty(pSelf))
    {
        return (pSelf->items[pSelf->top]);
    }
    else
    { 
        printf(">>> myStack_peek error : Stack is empty\n");
        exit(EXIT_FAILURE);
    }

}