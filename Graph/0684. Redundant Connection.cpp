#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Using DFS (Depth-First Search)
 * - We maintain an adjacency list and check if adding an edge forms a cycle.
 * - Before adding an edge, we use DFS to check if a path already exists between the two nodes.
 * - If a path exists, the current edge is redundant and should be returned.
 * - Otherwise, we add the edge to the adjacency list and continue.
 *
 * T.C: O(n^2) - In the worst case, for each edge, we perform DFS traversal.
 * S.C: O(n) - We store the adjacency list and a visited array.
 * --------------------
 */

class Solution
{
public:
  bool dfs(unordered_map<int, vector<int>> &adjList, int startNode, int targetNode, vector<bool> &visited)
  {
    visited[startNode] = true;

    // If we reach the target node, return true
    if (startNode == targetNode)
    {
      return true;
    }

    // Explore all adjacent nodes
    for (int &neighbor : adjList[startNode])
    {
      if (visited[neighbor])
        continue;

      if (dfs(adjList, neighbor, targetNode, visited))
      {
        return true;
      }
    }

    return false;
  }

  vector<int> findRedundantConnection(vector<vector<int>> &edges)
  {
    int numEdges = edges.size(); // Number of edges (also equal to the number of nodes)

    unordered_map<int, vector<int>> adjList; // Adjacency list representation of the graph

    // Iterate through each edge
    for (int i = 0; i < numEdges; i++)
    {
      int nodeA = edges[i][0];
      int nodeB = edges[i][1];

      vector<bool> visited(numEdges, false);

      // If both nodes exist in the adjacency list and a path already exists, return the redundant edge
      if (adjList.find(nodeA) != adjList.end() && adjList.find(nodeB) != adjList.end() && dfs(adjList, nodeA, nodeB, visited))
      {
        return edges[i];
      }

      // Otherwise, add the edge to the graph
      adjList[nodeA].push_back(nodeB);
      adjList[nodeB].push_back(nodeA);
    }

    return {}; // Return empty vector if no redundant edge is found (shouldn't happen as per problem constraints)
  }
};
