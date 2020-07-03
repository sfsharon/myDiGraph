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

#define MAX_NUM_NODES 10

void initAdjMat(int adjMat[MAX_NUM_NODES][MAX_NUM_NODES]) {
    for (int i = 0; i < MAX_NUM_NODES; i++) {
        for (int j = 0; j < MAX_NUM_NODES; j++) {
            adjMat[i][j] = -1;
        }
    }
}

#define MAX_BUF_SIZE (4096)

void readCSV(const char* fileName,  /* Input        : CSV File name to parse */
             int inputArray[],      /* Input/Output : Buffer to fill in */
             int arrSize,           /* Number of elemenets in inputArray */
             int* actualArrSize)    /* Actual number of elements read */
{    
/*
Assumptions : 
- All the string is in one liner. No support currently for multi lines
- Does not check buffer overrun - Only 1024 bytes available
*/
    FILE *fp = fopen(fileName, "r");

    if (!fp) {
        printf("Can't open file\n");
        return 0;
    }

    char buf[MAX_BUF_SIZE];
    //int row_count = 0;
    int field_count = 0;

    while (fgets(buf, MAX_BUF_SIZE, fp)) {
        char *pVal = NULL;
        field_count = 0;
        pVal = strtok(buf, ",");

        while (pVal != NULL) {
            printf("[Row_cnt/Field_cnt] [%d/%d] %s\n", row_count, field_count, pVal);
            // Move to next value
            pVal = strtok(NULL, ",");
            field_count++;
        } // while(words in line are not empty)
        row_count++;
    } // while(lines in file are not empty)

    fclose(fp);
}


int main() {
    printf("My DiGraph tool\n");
    // myGraph_1 contains a path from first node to the last
    char* myGraph_1 = "myGraph_1.csv";
    // myGraph_2 does not contain a path from first node to the last
    char* myGraph_2 = "myGraph_2.csv";

    readCSV(myGraph_1);
    readCSV(myGraph_2);

    // adjacency matrix object
    int adjMat[MAX_NUM_NODES][MAX_NUM_NODES];

    initAdjMat(adjMat);

    

    return 0;
}

