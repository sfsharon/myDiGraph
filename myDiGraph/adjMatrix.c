/*
* *****************************************************
*              adjMatrix module
* *****************************************************
*
* Adjacency Matrix module
* ---------------------------------
*/

#include "adjMatrix.h"

void adjMat_Init(int adjMat[MAX_NUM_GRAPH_NODES][MAX_NUM_GRAPH_NODES]) {
    for (int i = 0; i < MAX_NUM_GRAPH_NODES; i++) {
        for (int j = 0; j < MAX_NUM_GRAPH_NODES; j++) {
            adjMat[i][j] = -1;
        }
    }
}
