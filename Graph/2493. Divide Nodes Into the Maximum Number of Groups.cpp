#include <bits/stdc++.h>
using namespace std;

/*
 * Approach - Using Bipartite, DFS, and BFS
 * - We first check if the graph is **bipartite** using **DFS**. If it’s not bipartite, return -1.
 * - If the graph is bipartite, we find the **maximum levels** in each component using **BFS**.
 * - Finally, we compute the **maximum group size** for each connected component using **DFS**.
 * --------------------
 * T.C: O(V * (V+E))
 * - **Bipartite Check**: O(V * (V+E)) (DFS traversal for each component)
 * - **BFS Levels Calculation**: O(V * (V+E)) (Running BFS for each node)
 * - **Finding Maximum Group Size**: O(V * (V+E)) (DFS traversal for each component)
 * --------------------
 */

class Solution
{
public:
    // Function to check if the graph is bipartite using DFS
    bool isBipartite(unordered_map<int, vector<int>> &adj, int curr, vector<int> &colors, int currColor)
    {
        // Assign current node a color (1 or 0)
        colors[curr] = currColor;

        // Iterate through all neighbors of the current node
        for (int &ngbr : adj[curr])
        {
            // If the neighbor has the same color as the current node, it's not bipartite
            if (colors[ngbr] == colors[curr])
            {
                return false;
            }

            // If the neighbor is not colored, recursively color it with the opposite color
            if (colors[ngbr] == -1)
            {
                if (isBipartite(adj, ngbr, colors, 1 - currColor) == false)
                {
                    return false;
                }
            }
        }

        // If no conflicts found, return true
        return true;
    }

    // Function to calculate maximum levels in a component using BFS
    int bfs(unordered_map<int, vector<int>> &adj, int currNode, int n)
    {
        // Queue to perform BFS
        queue<int> que;
        // Visited array to keep track of visited nodes
        vector<bool> visited(n, false);

        // Push the current node into the queue and mark it as visited
        que.push(currNode);
        visited[currNode] = true;

        // Level counter to track maximum depth of BFS traversal
        int level = 1;
        while (!que.empty())
        {
            int size = que.size(); // Number of nodes at the current level

            // Process all nodes at the current level
            while (size--)
            {
                int curr = que.front();
                que.pop();

                // Traverse all neighbors
                for (int &ngbr : adj[curr])
                {
                    // Skip already visited nodes
                    if (visited[ngbr])
                        continue;

                    // Mark as visited and push into queue
                    que.push(ngbr);
                    visited[ngbr] = true;
                }
            }
            // Increment level after processing all nodes at the current level
            level++;
        }

        // Return the maximum depth of BFS traversal
        return level - 1;
    }

    // Function to compute the maximum group size for each connected component using DFS
    int getMaxFromEachComp(unordered_map<int, vector<int>> &adj, int curr, vector<bool> &visited, vector<int> &levels)
    {
        // Store the maximum level for the current node
        int maxGrp = levels[curr];
        // Mark the node as visited
        visited[curr] = true;

        // Traverse all neighbors
        for (int &ngbr : adj[curr])
        {
            // If neighbor is not visited, recursively find max group size
            if (!visited[ngbr])
            {
                maxGrp = max(maxGrp, getMaxFromEachComp(adj, ngbr, visited, levels));
            }
        }

        // Return the maximum group size found
        return maxGrp;
    }

    // Main function to determine the maximum number of magnificent sets
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        // Adjacency list representation of the graph
        unordered_map<int, vector<int>> adj;

        // Construct adjacency list from the given edges
        for (auto &edge : edges)
        {
            int u = edge[0] - 1; // Convert to 0-based index
            int v = edge[1] - 1;

            // Add bidirectional edges
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Array to store colors for bipartite check (-1 means uncolored)
        vector<int> colors(n, -1);

        // Perform bipartite check for each unvisited node
        for (int node = 0; node < n; node++)
        {
            if (colors[node] == -1)
            {
                // If the graph is not bipartite, return -1
                if (isBipartite(adj, node, colors, 1) == false)
                {
                    return -1;
                }
            }
        }

        // Array to store the maximum levels for each node using BFS
        vector<int> levels(n, 0);
        for (int node = 0; node < n; node++)
        {
            // Compute the maximum levels in the component containing the node
            levels[node] = bfs(adj, node, n);
        }

        // Variable to store the maximum group size from each component
        int maxGroupEachComp = 0;
        // Visited array to track processed nodes
        vector<bool> visited(n, false);

        // Traverse each node and find the maximum group size in each component
        for (int node = 0; node < n; node++)
        {
            if (!visited[node])
            {
                maxGroupEachComp += getMaxFromEachComp(adj, node, visited, levels);
            }
        }

        // Return the total number of magnificent sets
        return maxGroupEachComp;
    }
};
