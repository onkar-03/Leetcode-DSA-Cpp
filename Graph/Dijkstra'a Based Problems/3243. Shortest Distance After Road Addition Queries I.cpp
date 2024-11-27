#include <bits/stdc++.h>
using namespace std;

// Approach 1 (Using BFS (edges are unweighted)
// T.C : O(q * (E log(V)) , V = number of vertices and E = number of edges
// S.C : O(V+E)
class Solution
{
public:
  int bfs(int n, unordered_map<int, vector<int>> adj)
  {
    queue<int> que; // Queue for BFS traversal
    que.push(0);    // Start BFS from the source node (0)

    vector<int> visited(n, false); // To keep track of visited nodes
    visited[0] = true;             // Mark the source node as visited

    int level = 0; // Initialize the level (distance) from the source

    // Basic Level wise BFS Code
    while (!que.empty())
    {
      int size = que.size(); // Number of nodes at the current level

      // Until que is empty we perform bfs for each adn every node present in there
      while (size--)
      {
        int curr = que.front(); // Get the current node
        que.pop();              // Pop the curr node from the queue

        // If we reach the destination node (n-1), return the level
        if (curr == n - 1)
        {
          return level;
        }

        // Traverse all neighbors of the current node
        for (auto &neighbor : adj[curr])
        {
          if (!visited[neighbor]) // If the neighbor is not visited
          {
            visited[neighbor] = true; // Mark it as visited
            que.push(neighbor);       // Push it to the queue for BFS
          }
        }
      }
      level++; // Increment the level after processing all nodes at the current level
    }
    return -1; // If node n-1 is not reachable, return -1
  }

  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
  {
    // Create an adjacency list to represent the graph
    unordered_map<int, vector<int>> adj;

    // Build the initial graph with direct connections from i to i+1
    for (int i = 0; i <= n - 2; i++)
    {
      adj[i].push_back(i + 1); // Node i is connected to node i+1
    }

    int q = queries.size(); // Number of queries
    vector<int> result;     // To store the shortest distance for each query

    // Process each query
    for (auto &query : queries)
    {
      int u = query[0]; // Start node of the new edge
      int v = query[1]; // End node of the new edge

      // Add the new edge to the graph
      adj[u].push_back(v);

      // Perform BFS to find the shortest distance from node 0 to node n-1
      int dist = bfs(n, adj);

      // Store the result of the current query
      result.push_back(dist);
    }
    return result; // Return the results of all queries
  }
};
