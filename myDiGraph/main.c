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
* Test cases :
* 1. Empty array
* 2. Input array larger then the maximum supported size
* 3. Array with self loop - Index zero. Subcases :
*       2.1 Zero index at the start of the array
*       2.2 Zero index at the end of the array
*       2.3 Zero index at the middle of the array
*       2.4 All of the array is zero
* 4. Out of bound indices of the input array
*       3.1 Out of bound index at the start of the array
*       3.2 Out of bound index at the end of the array
*       3.3 Out of bound index at the middle of the array
* 5. calling myDFS_traverse() with out of bounds for srcVertex and dstVertex.
* 6. Randomly generated array - Check validity against python script ? Monte-carlo testing ?
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

// User library headres
#include "csvMng.h"
#include "adjMatrix.h"
#include "myDFS.h"

int main(int argc, char **argv) {
    printf(">>> My DiGraph Search Path tool <<<\n");


    if (argc != 2) {
        printf("Usage : myDiGraph fileName.csv");
        exit(1);
    }
	
    // File name, which contains the integer input array 
    /*char* myGraphFileName = "myGraph_2.csv";*/
    char* myGraphFileName = argv[1];


    /* -----------------------------------------------------
     *  Initialize Data 
     * -----------------------------------------------------  */
    // Integer array of values, read from input file
    int intArrayFromFile[MAX_NUM_GRAPH_NODES];
    int actualArrSize = 0;  

    // Adjacency Matrix object
    // This is the directed graph representation of the input Integer array
    // Each node has at most two adjacent nodes
    int adjMat[MAX_NUM_GRAPH_NODES][MAX_NUM_GRAPH_NODES];

    // Initialize adjacancy matrix to zeros, meaning no edges 
    adjMat_Init(adjMat);

    /* -----------------------------------------------------
     *  Build Adjacency Matrix
     * -----------------------------------------------------  */
    // Read data from file
    int rVal = readCSV(myGraphFileName, 
                       intArrayFromFile, 
                       MAX_NUM_GRAPH_NODES,
                       &actualArrSize);
    if (rVal != 0) {
        printf(">>> main : Error reading file %s\n", myGraphFileName);
        return rVal;
    }

    // Build Adjacency Matrix
    adjMat_Build(adjMat, intArrayFromFile, actualArrSize); 

    // Print Adjacency Matrix
    adjMat_Print(adjMat, actualArrSize);
    
    // Run DFS traversal and test if path exists from source Vertex '0'
    // to destination (actualArrSize - 1) 
    rVal = myDFS_findPath(adjMat, actualArrSize, 0, (actualArrSize - 1));

    // Print algorithm results
    if (rVal == 0) {
        printf(">>> main : Found path\n");
    }
    else  {
        printf(">>> main : No path\n");
    }
    

    return rVal;
}

