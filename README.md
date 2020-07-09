# 1. Introduction

## 1.1 Scope of document

This document describes a program to check if a path exists in an unsigned integer vector, according to the rule :

* Traversing rules:
  * The first index is 0, that’s where the algorithm starts.
  * Algorithm may only ‘jump’ forward or backwards in the array according to the value in the ‘current’ element (e.g. if the value at index 0 is 3 the algo may only advance to index 3. if the value at index 3 is 2 – the algo may advance to both index 5 and index 1).

# 2. System Overview

* Adjacency matrix, with a fixed and static size of :

```
#ifndef ADJMATRIX_H
#define ADJMATRIX_H

#define MAX_NUM_GRAPH_NODES 10

void adjMat_Init(int adjMat[MAX_NUM_GRAPH_NODES][MAX_NUM_GRAPH_NODES]);

int adjMat_Build(int adjMat[MAX_NUM_GRAPH_NODES][MAX_NUM_GRAPH_NODES], 
                 const int intArrayFromFile[MAX_NUM_GRAPH_NODES], 
                 int actualArrSize);

void adjMat_Print(const int adjMat[MAX_NUM_GRAPH_NODES][MAX_NUM_GRAPH_NODES], int actualArrSize);

#endif
```    
        
* The module csvMng reads the input file, and outputs an integer array. The module csvMng uses standard tokenization functions such as **strtok**.

```
// Iterate over lines
while (fgets(buf, MAX_BUF_SIZE, fp)) {
    // Initialization before processing line
    char *pVal = NULL;
    //field_count = 0;

    // Get the first token, if exists
    pVal = strtok(buf, ",");
```

* The Adjacency Matrix is built using the values parsed by readCSV().
 Each Vertex can have at most two neighbors (from the node outwards - This is a directed graph)
 
* DFS graph traversal is activated on the Adjacency Matrix.
  The DFS starting point is the first Vertex from the input non-negative Integer vector.
  If during the traversal, the last node is reached, the DFS stops and '0' (success) is returned. Otherwise, a non-zero value is returned. The DFS algorithm iterative implementation is based on https://en.wikipedia.org/wiki/Depth-first_search :
```
procedure DFS_iterative(G, v) is
    let S be a stack
    S.push(v)
    while S is not empty do
        v = S.pop()
        if v is not labeled as discovered then
            label v as discovered
            for all edges from v to w in G.adjacentEdges(v) do
                S.push(w)
```
  