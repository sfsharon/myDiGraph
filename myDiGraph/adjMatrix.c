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
    /* Initialize Adjacency Matrix with the value '-1' which is an invalid value in this application */
{
    for (int i = 0; i < MAX_NUM_GRAPH_NODES; i++) 
    {
        for (int j = 0; j < MAX_NUM_GRAPH_NODES; j++) 
        {
            adjMat[i][j] = -1;
        }
    }
}

int adjMat_Build(int adjMat[MAX_NUM_GRAPH_NODES][MAX_NUM_GRAPH_NODES],
                 int inputArray[MAX_NUM_GRAPH_NODES],
                 int actualArrSize)
    /*
    * Build the adjecancy matrix according to the input integer array 
    * that was read from a file.
    * The traversing rule :
    * Algorithm may only 'jump' forward or backwards in the array according to the
    * value in the 'current' element (e.g. if the value at index 0 is 3 the algo may only
    * advance to index 3. if the value at index 3 is 2 - the algo may advance to both
    * index 5 and index 1).
    */  
{
    // Sanity test - Actual size should always be equal or smaller then MAX_NUM_GRAPH_NODES 
    if (actualArrSize > MAX_NUM_GRAPH_NODES)
    {
        printf(">> adjMat_Build : ERROR - actualArrSize %d larger then MAX_NUM_GRAPH_NODES %d\n", actualArrSize, MAX_NUM_GRAPH_NODES);
        return -1;
    }

    // Traverse the inputArray, and update adjMat accordingly
    for (int i = 0; i < actualArrSize; i++)
    {
        //int currJumpVal = 
    }
    return 0;
}