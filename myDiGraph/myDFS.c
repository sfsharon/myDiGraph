/*
* *****************************************************
*              myDFS module.
* *****************************************************
*
* Program functionality :
* -----------------------
* Implement Depth First Search graph traversal
*
* Based on implementation from https://en.wikipedia.org/wiki/Depth-first_search :
*        procedure DFS_iterative(G, v) is
*            let S be a stack
*            S.push(v)
*            while S is not empty do
*                v = S.pop()
*                if v is not labeled as discovered then
*                    label v as discovered
*                    for all edges from v to w in G.adjacentEdges(v) do
*                        S.push(w)
*
*/


