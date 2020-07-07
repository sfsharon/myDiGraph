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
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

// User private library headres
#include "myStack.h"
#include "csvMng.h"

#define MAX_NUM_GRAPH_NODES 10

void initAdjMat(int adjMat[MAX_NUM_GRAPH_NODES][MAX_NUM_GRAPH_NODES]) {
    for (int i = 0; i < MAX_NUM_GRAPH_NODES; i++) {
        for (int j = 0; j < MAX_NUM_GRAPH_NODES; j++) {
            adjMat[i][j] = -1;
        }
    }
}

int main() {
    printf(">>> My DiGraph tool <<<\n");

    int intArrayFromFile[MAX_NUM_GRAPH_NODES];
    int actualArrSize = 0;    
    // myGraphFileName contains a path from first node to the last
    char* myGraphFileName = "myGraph_1.csv";

    readCSV(myGraphFileName, 
            intArrayFromFile, 
            MAX_NUM_GRAPH_NODES,
            &actualArrSize);

    // Initialize Stack object
    T_StackType* pMyStack = initNewStack(MAX_NUM_GRAPH_NODES);
    if (pMyStack == NULL) {
        printf(">>> myDiGraph main : Error allocating stack\n");
        return -1;
    }

    //// Test calling a method of object myStack : Stack size
    //int mySize = myStack_Size(pMyStack);

    // adjacency matrix object
    int adjMat[MAX_NUM_GRAPH_NODES][MAX_NUM_GRAPH_NODES];

    initAdjMat(adjMat);   

    return 0;
}

