#include <bits/stdc++.h>
using namespace std;

// Approach: Simple Indegree Check
// Time Complexity: O(m + n), where m is the number of edges and n is the number of nodes
// Space Complexity: O(n), for storing the indegree of each node

class Solution
{
public:
  int findChampion(int n, vector<vector<int>> &edges)
  {
    // Step 1: Initialize an indegree array for all nodes
    vector<int> inDegree(n, 0);

    // Step 2: Traverse through each edge and calculate indegree of nodes
    for (vector<int> &edge : edges)
    {
      int u = edge[0]; // Starting node of the edge
      int v = edge[1]; // Ending node of the edge

      // Since the edge is directed from u to v, increase indegree of v
      inDegree[v]++;
    }

    // Step 3: Identify the potential "champion" node
    int champ = -1; // Variable to store the champion node (if any)
    int count = 0;  // Counter to track the number of nodes with indegree 0

    for (int i = 0; i < n; i++)
    {
      // If a node has indegree 0, it could be the "champion"
      if (inDegree[i] == 0)
      {
        champ = i; // Update the champion to the current node
        count++;   // Increment the count of nodes with indegree 0

        // If more than one node has indegree 0, return -1 (no single champion exists)
        if (count > 1)
        {
          return -1;
        }
      }
    }

    // Step 4: Return the identified champion or -1 if no such node exists
    return champ;
  }
};
