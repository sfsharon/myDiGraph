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

    // File containing a representation of a graph.
    char* myGraphFileName = "myGraph_1.csv";

    // Initialize Stack object
    T_StackType* pMyStack = initNewStack(MAX_NUM_GRAPH_NODES);
    if (pMyStack == NULL) {
        printf(">>> myDiGraph main : Error allocating stack\n");
        return -1;
    }

    // --------------------------------------------
    // Build Adjacency Matrix
    // --------------------------------------------
    // Read data from file
    readCSV(myGraphFileName, 
            intArrayFromFile, 
            MAX_NUM_GRAPH_NODES,
            &actualArrSize);

    adjMat_Init(adjMat);

    adjMat_Build(adjMat, intArrayFromFile, actualArrSize); // TODO 

    //// Test calling a method of object myStack : Stack size
    //int mySize = myStack_Size(pMyStack);



    return 0;
}

