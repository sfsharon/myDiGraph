/*
* *****************************************************
*              adjMatrix module
* *****************************************************
*
* Adjacency Matrix module
* ---------------------------------
*/
#include <stdio.h>
#include "adjMatrix.h"

void adjMat_Init(int adjMat[MAX_NUM_GRAPH_NODES][MAX_NUM_GRAPH_NODES]) 
    /* Initialize Adjacency Matrix with the value '0' which means no edge between the i and j indices */
{
    for (int i = 0; i < MAX_NUM_GRAPH_NODES; i++) 
    {
        for (int j = 0; j < MAX_NUM_GRAPH_NODES; j++) 
        {
            adjMat[i][j] = 0;
        }
    }
}

int adjMat_Build(int adjMat[MAX_NUM_GRAPH_NODES][MAX_NUM_GRAPH_NODES], /* Output - Updated matrix                   */
                 const int inputArray[MAX_NUM_GRAPH_NODES],            /* Input - Integer array received from user  */
                 int actualArrSize)                                    /* Input - Integer array actual size         */
    /*
    * Build the adjecancy matrix according to the input integer array 
    * that was read from a file.
    * Return Value : '0' on success, otherwise non-zero value.
    * Algorithm :
    *     The traversing rule for updating the Adacency atrix. Two vertices are connected, if the 
    *     input array has a connection between them, according to the following rule :
    *     Algorithm may only 'jump' forward or backwards in the array according to the
    *     value in the 'current' element (e.g. if the value at index 0 is 3 the algo may only
    *     advance to index 3. if the value at index 3 is 2 - the algo may advance to both
    *     index 5 and index 1).
    *     The row (first matrix dimension) is the source vertice, and the column (second matrix dimension) 
    *     is the destination.
    */  
{
    // Sanity test - Actual size should always be equal or smaller then MAX_NUM_GRAPH_NODES 
    if (actualArrSize > MAX_NUM_GRAPH_NODES)
    {
        printf(">> adjMat_Build : ERROR - actualArrSize %d larger then MAX_NUM_GRAPH_NODES %d\n", 
                actualArrSize, MAX_NUM_GRAPH_NODES);
        return -1;
    }

    // Traverse the inputArray, and update adjMat accordingly
    for (int i = 0; i < actualArrSize; i++)
    {
        int currJumpVal = inputArray[i];
        int fwdJumpVal = i + currJumpVal;   // Forward jump index
        int bckJumpVal = i - currJumpVal;   // Backward jump index

        /* 
         * Update Adacency matrix logic 
         */
        //Check if an edge is present between the vertice i to  i + arr[i]
        if (fwdJumpVal < actualArrSize)
        {
            // Update the value '1' in appropriate place in the adjMat
            adjMat[i][fwdJumpVal] = 1;
        }
        //Check if an edge is present between the vertice i to  i - arr[i]
        if (bckJumpVal >= 0)
        {
            // Update the value '1' in appropriate place in the adjMat
            adjMat[i][bckJumpVal] = 1;
        }
    }
    
    return 0;
}

void adjMat_Print(const int adjMat[MAX_NUM_GRAPH_NODES][MAX_NUM_GRAPH_NODES], int actualArrSize)
{
    // Print column header
    printf("  ");
    for (int k = 0; k < actualArrSize; k++)
    {
        printf("%d\t", k);
    }
    printf("\n  -------------------------------------------------------\n");

    // Print rows header
    /*printf("\t");*/
    for (int i = 0; i < actualArrSize; i++)
    {
        printf("%d|", i);
        for (int j = 0; j < actualArrSize; j++)
        {
            printf("%d\t", adjMat[i][j]);
        }
        printf("\n");
    }
}