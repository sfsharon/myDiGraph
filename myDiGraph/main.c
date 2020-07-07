/*
* *****************************************************
*              myDiGraph main module.
* *****************************************************
*
* Program functionality :
* -----------------------
* 1. Receive a vector of non-negative integers
* 2. Process into a directed graph representation
* 3. Search for a path from first node to the last.
*    Each node is connected to two other nodes at most. The node value is the 
*    jump value added or decremented to this node's current index, representing the
*    connected edge from this node to the next.
*
* ReadCSV function is based on https://codingboost.com/parsing-csv-files-in-c
*
*
* "An advanced beginner, C is what I see now"
* Soumik Ranjan Dasgupta
*
* Test cases :
* 1. Empty array
* 2. Input array larger then the maximum supported size
* 3. Array with self loop - Index zero. Subcases :
*       2.1 Zero index at the start of the array
*       2.2 Zero index at the end of the array
*       2.3 Zero index at the middle of the array
*       2.4 All of the array is zero
* 4. Out of bound indices 
*       3.1 Out of bound index at the start of the array
*       3.2 Out of bound index at the end of the array
*       3.3 Out of bound index at the middle of the array
* 5. Randomly generated array - Check validity against python script ? Monte-carlo testing ?
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

// User private library headres
#include "myStack.h"
#include "csvMng.h"
#include "adjMatrix.h"



int main() {
    printf(">>> My DiGraph tool <<<\n");

    // --------------------------------------------
    // Initialize data 
    // --------------------------------------------
    // Integer array of values read from input file
    int intArrayFromFile[MAX_NUM_GRAPH_NODES];
    int actualArrSize = 0;  

    // Adjacency Matrix object
    int adjMat[MAX_NUM_GRAPH_NODES][MAX_NUM_GRAPH_NODES];

    adjMat_Init(adjMat);

    // File containing a representation of a graph.
    char* myGraphFileName = "myGraph_1.csv";

    // Initialize Stack object
    T_StackType* pMyStack = initNewStack(MAX_NUM_GRAPH_NODES);
    if (pMyStack == NULL) {
        printf(">>> myDiGraph main : Error allocating stack\n");
        return -1;
    }

    //// Test calling a method of object myStack : Stack size
    //int mySize = myStack_Size(pMyStack);
    myStack_push(pMyStack, 3);
    myStack_push(pMyStack, 100);
    myStack_push(pMyStack, 2);

    // --------------------------------------------
    // Build Adjacency Matrix
    // --------------------------------------------
    // Read data from file
    readCSV(myGraphFileName, 
            intArrayFromFile, 
            MAX_NUM_GRAPH_NODES,
            &actualArrSize);

    // Build Adjacency Matrix
    adjMat_Build(adjMat, intArrayFromFile, actualArrSize); // TODO 

    // Print Adjacency Matrix
    adjMat_Print(adjMat, actualArrSize);
    

    return 0;
}

