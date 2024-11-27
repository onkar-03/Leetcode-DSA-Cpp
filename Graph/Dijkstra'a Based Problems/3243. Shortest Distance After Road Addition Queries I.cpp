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

// Approach (Using Dijkstra's Algorithm - Assuming each edge weight is 1)
// T.C : O(q * (V+E)) , V = number of vertices and E = number of edges
// S.C : O(V+E)
class Solution
{
public:
// Define a pair for priority queue to store (distance, node)
#define P pair<int, int>

  // Adjacency list to represent the graph
  unordered_map<int, vector<P>> adj;

  // Function to find the shortest distance from node 0 to node n-1 using Dijkstra's Algorithm
  int dijkstra(int n)
  {
    vector<int> result(n, INT_MAX); // Initialize distances to all nodes as infinity (INT_MAX)
    result[0] = 0;                  // Distance to source node (0) is 0

    // Min-heap (priority queue) to store (distance, node), sorted by distance
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0}); // Start with the source node (0) with distance 0

    // Continue until all reachable nodes are processed
    while (!pq.empty())
    {
      int d = pq.top().first;     // Distance to the current node
      int node = pq.top().second; // Current node
      pq.pop();

      // If we have already found a shorter distance to the current node, skip
      if (d > result[node])
        continue;

      // If we reach the destination node (n-1), return its shortest distance
      if (node == n - 1)
        return result[n - 1];

      // Traverse all adjacent nodes of the current node
      for (P &p : adj[node])
      {
        int adjNode = p.first; // Neighboring node
        int dist = p.second;   // Distance (weight of the edge)

        // If a shorter path to adjNode is found, update it
        if (d + dist < result[adjNode])
        {
          result[adjNode] = d + dist;   // Update the shortest distance
          pq.push({d + dist, adjNode}); // Push updated distance to the priority queue
        }
      }
    }
    // If destination node (n-1) is unreachable, return its distance as it will remain INT_MAX
    return result[n - 1];
  }

  // Function to process queries and return shortest distances after each query
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
  {
    vector<int> result; // To store the results for each query

    // Build the initial graph with direct connections from i to i+1
    for (int i = 0; i < n - 1; ++i)
    {
      adj[i].push_back({i + 1, 1}); // Connect node i to i+1 with weight 1
    }

    // Process each query
    for (auto query : queries)
    {
      int u = query[0]; // Start node of the new edge
      int v = query[1]; // End node of the new edge

      // Add the new edge to the graph with weight 1
      adj[u].push_back({v, 1});

      // Run Dijkstra's algorithm to find the shortest distance from node 0 to node n-1
      int d = dijkstra(n);

      // Store the result of the current query
      result.push_back(d);
    }

    return result; // Return the results for all queries
  }
};
