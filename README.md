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
 Each Vertex can have at most two neighbors (the edge cannot point onto the same node, unless the node value is '0')
 
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
  
* DFS algorithm uses internally a stack implementation named myStack.
  The algorithm uses malloc to allocate the space needed for the stack.
  Therefore, a constructor and destructor methods are provided in myStack.h file.
  Based on implementation from https://www.techiedelight.com/stack-implementation/
    
# 3. Resource considerations
* The Adjacency Matrix data structure that was chosen to represent the directed graph uses O(N^2) space complexity, which is not the best memory usage (compared to adjacency list), especially considering the fact the from each vertex, only two edges can exist at most, thus creating a sparse matrix. However, for a small number of vertices, the adjacency matrix gives a simple solution.
* The myStack stack implementation uses a dynamically allocated array, and gives pop/push/peek operations in O(1) time complexity.

# 4. Testing
To activate the tests, please run the "run_tests.bat" file.
The test vectors are split into two directories : 
* myDiGraph\testVectors\noPath - Contains vector CSV input files that do not contain a valid path, the vertex values is out of bound, or an empty file.
* myDiGraph\testVectors\Path - Contains vector CSV input files that contain a valid path


# 5. Caveat
Not implemented TSV or JSON
