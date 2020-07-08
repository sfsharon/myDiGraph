/*
* *****************************************************
*              myDFS module.
* *****************************************************
*
* Program functionality :
* -----------------------
* Implement Depth First Search graph traversal
*
* Based on implementation from https://en.wikipedia.org/wiki/Depth-first_search :
*        procedure DFS_iterative(G, v) is
*            let S be a stack
*            S.push(v)
*            while S is not empty do
*                v = S.pop()
*                if v is not labeled as discovered then
*                    label v as discovered
*                    for all edges from v to w in G.adjacentEdges(v) do
*                        S.push(w)
*
*/

#include <stdio.h>
#include <string.h>
#include "adjMatrix.h"
#include "myStack.h"

int myDFS_traverse(int adjMat[MAX_NUM_GRAPH_NODES][MAX_NUM_GRAPH_NODES], 
                   int actualArrSize)
{
    // Visited matrix, to hold if DFS has visited this node.
    int visitedNode[MAX_NUM_GRAPH_NODES];
    // Initialize all elements to '0', means element has not been visited
    memset(visitedNode, 0, sizeof(visitedNode));

    if ((actualArrSize <= 0) ||
        (actualArrSize >= MAX_NUM_GRAPH_NODES))
    {
        printf(">>> myDFS_traverse : Number of nodes %d is out of range\n", actualArrSize);
        return -1;
    }

    // Initialize Stack object
    T_StackType* pMyStack = myStack_ctor(actualArrSize);
    if (pMyStack == NULL) {
        printf(">>> myDFS_traverse : Error allocating stack\n");
        return -1;
    }

    // Setup - Insert the first node which is in index '0' into the stack
    myStack_push(pMyStack, 0);

    // Graph DFS traversal
    while (myStack_isEmpty(pMyStack) == 0)
    {
        int currNode = myStack_pop(pMyStack);
        
        // If the current node has not been labeled as 'Visited'
        if (visitedNode[currNode] == 0) {

            // Visiting a node
            printf("myDFS_traverse : Visiting node : %d\n", currNode);

            // Label current node as visited
            visitedNode[currNode] = 1;

            // for all edges from currNode to w in adjMat do : myStack_push(w)
            for (int i = 0; i < actualArrSize; i++)
            {
                // If edge exists from vertix [currNode] to vertix [i], push to stack
                if (adjMat[currNode][i] != 0) {
                    myStack_push(pMyStack, i);
                }
            }
        } // If (not visited node)  
    } // while (stack is not empty)

    // Destroy Stack object
    myStack_dtor(pMyStack);

}