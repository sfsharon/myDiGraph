#ifndef ADJMATRIX_H
#define ADJMATRIX_H

#define MAX_NUM_GRAPH_NODES 10

void adjMat_Init(int adjMat[MAX_NUM_GRAPH_NODES][MAX_NUM_GRAPH_NODES]);

int adjMat_Build(int adjMat[MAX_NUM_GRAPH_NODES][MAX_NUM_GRAPH_NODES], 
                 const int intArrayFromFile[MAX_NUM_GRAPH_NODES], 
                 int actualArrSize);

void adjMat_Print(const int adjMat[MAX_NUM_GRAPH_NODES][MAX_NUM_GRAPH_NODES], int actualArrSize);

#endif