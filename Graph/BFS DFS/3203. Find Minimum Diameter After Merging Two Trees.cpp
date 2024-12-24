#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int n;
  // Helper function to perform BFS and find the farthest node and its distance from the source node
  pair<int, int> BFS(unordered_map<int, vector<int>> &adj, int source)
  {
    queue<int> que;
    que.push(source);

    unordered_map<int, bool> visited; // Keeps track of visited nodes
    visited[source] = true;

    int distance = 0;          // Tracks the level of BFS, which represents the distance
    int farthestNode = source; // Stores the farthest node from the source

    while (!que.empty())
    {
      int size = que.size(); // Number of nodes at the current level

      while (size--)
      {
        int curr = que.front();
        que.pop();

        farthestNode = curr; // Update the farthest node

        // Traverse all neighbors of the current node
        for (auto &nbr : adj[curr])
        {
          if (!visited[nbr])
          { // If the neighbor is not visited
            visited[nbr] = true;
            que.push(nbr);
          }
        }
      }

      // Increment distance if there are nodes in the next level
      if (!que.empty())
      {
        distance++;
      }
    }

    // Return the farthest node and the distance to it
    return {farthestNode, distance};
  }

  // Function to find the diameter of a tree using BFS
  int findDiameter(unordered_map<int, vector<int>> adj)
  {
    // Step 1: Find the farthest node from a random starting node (e.g., node 0)
    auto [farthestNode, dist] = BFS(adj, 0);

    // Step 2: The farthest node found above is one end of the tree's diameter
    // Step 3: Perform BFS from this farthest node to find the other end and calculate the diameter
    auto [otherEndNode, diameter] = BFS(adj, farthestNode);

    return diameter;
  }

  // Helper function to build an adjacency list from the edges
  unordered_map<int, vector<int>> buildAdj(vector<vector<int>> &edges)
  {
    unordered_map<int, vector<int>> adj;

    for (auto &edge : edges)
    {
      int u = edge[0];
      int v = edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    return adj;
  }

  // Main function to compute the minimum possible diameter after merging two trees
  int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
  {
    // Build adjacency lists for both trees
    unordered_map<int, vector<int>> adj1 = buildAdj(edges1);
    unordered_map<int, vector<int>> adj2 = buildAdj(edges2);

    // Calculate the diameters of both trees
    int d1 = findDiameter(adj1);
    int d2 = findDiameter(adj2);

    // Compute the new combined diameter after merging
    // Each diameter is halved and combined with an additional edge for merging
    int combined = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;

    // Return the maximum diameter after merging
    return max({d1, d2, combined});
  }
};
