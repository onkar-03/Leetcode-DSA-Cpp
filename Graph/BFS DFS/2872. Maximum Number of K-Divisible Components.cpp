#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Helper function to perform DFS and calculate the subtree sums
  // Passed count by reference to actually update its original value
  int dfs(vector<vector<int>> &adj, vector<int> &values, int k, int &count, int curr, int parent = -1)
  {
    // Start with the value of the current node
    // Assign a Sum for each Node we visit
    long long sum = values[curr];

    // Traverse all neighbors of the current node
    for (auto nbr : adj[curr])
    {
      // As in Undirected Tree for 0-1, then 0 is adjacent to 1 and 1 is adjacent to 0
      // So we skip the parent node to avoid revisiting the Node again and againa dn end up in an infinite loop
      if (nbr != parent)
      {
        sum += dfs(adj, values, k, count, nbr, curr); // Add subtree sum of the child
      }
    }

    sum %= k; // Take modulo k to keep the sum manageable

    // If the subtree sum is divisible by k, increment the count
    if (sum == 0)
    {
      count++;
    }

    return sum; // Return the modulo result of the subtree sum
  }

  // Main function to calculate the maximum number of k-divisible components
  int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
  {
    vector<vector<int>> adj(n); // Adjacency list to represent the tree

    // Build the adjacency list for the undirected tree
    // For every edge [u, v], add v to the adjacency list of u and add u to the adjacency list of v
    // This ensures both nodes are aware of their connection, as the graph is undirected
    for (auto edge : edges)
    {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    // Initialize the count of k-divisible components
    int count = 0;

    // Start DFS from the root node (node 0)
    dfs(adj, values, k, count, 0);

    // Return the final count
    return count;
  }
};
