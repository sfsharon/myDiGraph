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
#include <string.h>
#include <stdlib.h> // for strtol

#include "myStack.h"

#define MAX_NUM_NODES 10
#define MAX_BUF_SIZE (4096)

void initAdjMat(int adjMat[MAX_NUM_NODES][MAX_NUM_NODES]) {
    for (int i = 0; i < MAX_NUM_NODES; i++) {
        for (int j = 0; j < MAX_NUM_NODES; j++) {
            adjMat[i][j] = -1;
        }
    }
}



int readCSV( const char* fileName,  /* Input        : CSV File name to parse                    */
             int inputArray[],      /* Input/Output : Buffer to fill in values from CSV file    */
             int arrSize,           /* Number of elemenets in inputArray                        */
             int* actualArrSize)    /* Actual number of elements read into inputArray           */
{    
/*
*  Assumption : 
*  All the strings are in one liner. No support currently for multi lines
*  Return value : 0 on success
*                 Non zero error code if an issue encountered
*/
    int rVal = 0;                       // Initialize return value to success
    *actualArrSize = 0;

    FILE *fp = fopen(fileName, "r");

    if (!fp) {
        printf("Can't open file\n");
        return 0;
    }

    char buf[MAX_BUF_SIZE];
    //int row_count = 0;
    //int field_count = 0; // represented by *actualArrSize 

    // Iterate over lines
    while (fgets(buf, MAX_BUF_SIZE, fp)) {
        // Initialization before processing line
        char *pVal = NULL;
        //field_count = 0;

        // Get the first token, if exists
        pVal = strtok(buf, ",");

        // Iterate over comma separated tokens
        while (pVal != NULL) {
            if ((*actualArrSize) >= arrSize)
            {
                rVal = -1;
                printf(">>> readCSV : Error. actualArrSize  %d exceeds array size of %d \n", *actualArrSize, arrSize);
                break;
            }
            else
            {
                printf("[%d] %s\n", *actualArrSize, pVal);
                inputArray[*actualArrSize] = strtol(pVal, NULL, 10);       // String to long conversion
                // Move to next value
                pVal = strtok(NULL, ",");
                (*actualArrSize)++;
            }
        } // while(words in line are not empty)
        //row_count++;
    } // while(lines in file are not empty)

    fclose(fp);
}


int main() {
    printf("My DiGraph tool\n");

    int inputArray[MAX_BUF_SIZE];
    int actualArrSize = 0;    
    // myGraph_1 contains a path from first node to the last
    char* myGraph_1 = "myGraph_1.csv";
    // myGraph_2 does not contain a path from first node to the last
    char* myGraph_2 = "myGraph_2.csv";

    readCSV(myGraph_1, 
            inputArray, 
            MAX_BUF_SIZE, 
            &actualArrSize);
    //readCSV(myGraph_2,
    //    inputArray,
    //    MAX_BUF_SIZE,
    //    &actualArrSize);

    // Build Stack data structure
    T_StackType* pMyStack = initNewStack(MAX_NUM_NODES);
    if (pMyStack == NULL) {
        printf(">>> myDiGraph main : Error allocating stack\n");
        return -1;
    }

    // Test calling a method of object myStack : Stack size
    int mySize = myStack_Size(pMyStack);

    // adjacency matrix object
    int adjMat[MAX_NUM_NODES][MAX_NUM_NODES];

    initAdjMat(adjMat);



    

    return 0;
}

