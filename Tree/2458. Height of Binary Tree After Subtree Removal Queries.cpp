#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  // Arrays to store the properties of nodes and levels
  int level[1000001];            // Stores the level (depth) of each node
  int height[1000001];           // Stores the height of each node
  int levelMaxHt[1000001];       // Stores the maximum height at each level
  int levelSecondMaxHt[1000001]; // Stores the second maximum height at each level

  int findHeight(TreeNode *root, int l)
  {
    if (!root)
    { // Base case: if the node is null, return height 0
      return 0;
    }

    level[root->val] = l; // Set the level of the current node

    // Calculate height of the current node as max height of left and right subtrees + 1
    height[root->val] = max(findHeight(root->left, l + 1), findHeight(root->right, l + 1)) + 1;

    // Update maximum and second maximum heights at the current level `l`
    if (levelMaxHt[l] < height[root->val])
    {                                      // If current node's height is greater than max height at this level
      levelSecondMaxHt[l] = levelMaxHt[l]; // Set previous max height as the second max
      levelMaxHt[l] = height[root->val];   // Update max height at this level
    }
    else if (levelSecondMaxHt[l] < height[root->val])
    {                                          // If current node's height is greater than second max
      levelSecondMaxHt[l] = height[root->val]; // Update the second max height
    }

    return height[root->val]; // Return the height of the current node
  }

  // Function to process queries to calculate the height of the tree after removing a node
  vector<int> treeQueries(TreeNode *root, vector<int> &queries)
  {
    vector<int> result; // Vector to store the results of each query

    findHeight(root, 0); // Preprocess to calculate heights and levels starting from level 0 at the root

    // Iterate over each query
    for (int &node : queries)
    {
      int nodeLevel = level[node]; // Get the level of the node in the query

      // Calculate the height of the tree after removing the current node
      int tempResult = nodeLevel + (levelMaxHt[nodeLevel] == height[node] ? levelSecondMaxHt[nodeLevel] : levelMaxHt[nodeLevel]) - 1;

      result.push_back(tempResult); // Add the result for this query to the result vector
    }

    return result; // Return the results for all queries
  }
};
