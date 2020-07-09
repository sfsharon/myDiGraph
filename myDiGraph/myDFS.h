#ifndef MYDFS_H
#define MYDFS_H

#include "adjMatrix.h"

/**
 * Traversing the graph represented by Adjacency Matrix adjMat, testing if a path exists
 * from srcVertex to dstVertex. The row dimension is designated the source Vertex, and the column
 * designated the destination Vertex.
 * @param adjMat Input Adjacency Matrix
 * @param actualArrSize Actual number of nodes available in the adjMat object.
 * @param srcVertex The starting point of the DFS graph traversal.
 * @param dstVertex The required end point of the DFS graph traversal.
 * @return '0' if a route exists between the srcVertex and the dstVertex
 *         Non zero value otherwise
 */
int myDFS_findPath(int adjMat[MAX_NUM_GRAPH_NODES][MAX_NUM_GRAPH_NODES],
                       int actualArrSize,
                       int srcVertex,
                       int dstVertex);

#endif
