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
  vector<int> largestValues(TreeNode *root)
  {
    // If the root is null, return an empty vector since there are no rows in the tree
    if (!root)
      return {};

    // Queue for BFS traversal, starting with the root node
    queue<TreeNode *> que;
    que.push(root);

    // Vector to store the largest values for each row
    vector<int> result;

    // Start BFS traversal
    while (!que.empty())
    {
      // Get the number of nodes at the current level
      int n = que.size();

      // Initialize maxEl to the smallest possible integer value
      // to track the maximum value in the current level
      int maxEl = INT_MIN;

      // Process all nodes in the current level
      while (n--)
      {
        // Get the front node in the queue and remove it
        TreeNode *node = que.front();
        que.pop();

        // Update maxEl with the value of the current node
        maxEl = max(maxEl, node->val);

        // If the node has a left child, add it to the queue
        if (node->left)
          que.push(node->left);

        // If the node has a right child, add it to the queue
        if (node->right)
          que.push(node->right);
      }

      // After processing all nodes in the current level,
      // add the maximum value of this level to the result
      result.push_back(maxEl);
    }

    // Return the vector containing the largest values in each row
    return result;
  }
};
