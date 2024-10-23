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

// Approach-1 (2 Pass)
// T.C : O(2*n) : Traversed the Tree 2 time
// S.C : O(n)
class Solution
{
public:
  TreeNode *replaceValueInTree(TreeNode *root)
  {
    // Base case: if the root is NULL, return it directly.
    if (root == NULL)
    {
      return root;
    }

    // Initialize a queue for Breadth-First Search (BFS).
    // Start BFS from the root node.
    queue<TreeNode *> que; // O(N)
    que.push(root);

    // This vector stores the sum of node values at each level.
    vector<int> levelSums; // O(N)

    // 1. Calculate the sum of each level of the tree and store it in the levelSums vector.
    while (!que.empty())
    {
      int currentLevelSum = 0; // Initialize the sum for the current level.
      int size = que.size();   // The number of nodes in the current level.

      // Process all nodes of the current level.
      while (size--)
      {
        TreeNode *curr = que.front(); // Get the node at the front of the queue.
        que.pop();                    // Remove it from the queue.
        currentLevelSum += curr->val; // Add the value of the node to the current level's sum.

        // If the node has a left child, add it to the queue to process in the next level.
        if (curr->left)
        {
          que.push(curr->left);
        }

        // If the node has a right child, add it to the queue to process in the next level.
        if (curr->right)
        {
          que.push(curr->right);
        }
      }

      // After processing all nodes at the current level, store the sum in levelSums.
      levelSums.push_back(currentLevelSum);
    }

    // Begin updating each node's value with the sum of cousin nodes.
    // Initialize BFS again to update the nodes based on cousin sums.
    que.push(root);

    // The root node has no cousins, so we set its value to 0.
    root->val = 0;

    // Level index to start calculating sibling sums, beginning with the first level below the root.
    int i = 1;

    // Continue BFS for updating the tree.
    while (!que.empty())
    {
      int size = que.size(); // Get the number of nodes in the current level.

      // Process all nodes in the current level.
      while (size--)
      {
        TreeNode *curr = que.front(); // Get the front node.
        que.pop();                    // Remove the node from the queue.

        // Calculate the sum of the sibling nodes (left and right children).
        // If the left child exists, add its value to siblingSum, otherwise add 0.
        int siblingSum = (curr->left != NULL) ? curr->left->val : 0;

        // Similarly, add the right child's value if it exists, otherwise add 0.
        siblingSum += (curr->right != NULL) ? curr->right->val : 0;

        // Update the left child’s value:
        // New value = current level sum - sibling sum (subtract the sibling sum to get cousin sum).
        if (curr->left != NULL)
        {
          curr->left->val = levelSums[i] - siblingSum;

          // Add the left child to the queue for further processing.
          que.push(curr->left);
        }

        // Update the right child’s value similarly.
        if (curr->right != NULL)
        {
          curr->right->val = levelSums[i] - siblingSum;

          // Add the right child to the queue for further processing.
          que.push(curr->right);
        }
      }
      // Move to the next level of the tree.
      i++;
    }

    // Finally, return the updated tree root.
    return root;
  }
};
