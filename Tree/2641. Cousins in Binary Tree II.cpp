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

// Approach-1 (2 Pass Solution)
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

    // Step1: Calculate the sum of each level of the tree and store it in the levelSums vector.
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

    // Step-2 (update each node value with cousin sum)
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

// Approach-2 (1 Pass)
// Time Complexity: O(n), where 'n' is the number of nodes in the tree.
// Space Complexity: O(n), for storing nodes in the queue during traversal.

class Solution
{
public:
  TreeNode *replaceValueInTree(TreeNode *root)
  {
    // Base case: If the root is NULL, there's no tree to process, so return the root (NULL).
    if (root == NULL)
    {
      return root;
    }

    // Initialize a queue for Breadth-First Search (BFS).
    queue<TreeNode *> que;

    // Start the BFS from the root node.
    que.push(root);

    // Initialize the sum of the current level. At the start, it's just the value of the root.
    int levelSum = root->val;

    // Continue BFS until all nodes are processed.
    while (!que.empty())
    {
      // 'size' holds the number of nodes in the current level.
      int size = que.size();

      // Initialize the sum for the next level to 0. This will store the sum of node values at the next level.
      int nextLevelSum = 0;

      // Process all nodes in the current level.
      while (size--)
      {
        // Get the current node from the front of the queue.
        TreeNode *curr = que.front();
        que.pop();

        // Update the current node's value: subtract its value from the sum of its level.
        curr->val = levelSum - curr->val;

        // Calculate the sum of sibling nodes (both left and right children).
        // If the left child exists, add its value to siblingSum, otherwise add 0.
        int siblingSum = (curr->left != NULL) ? curr->left->val : 0;

        // Similarly, add the right child's value if it exists, otherwise add 0.
        siblingSum += (curr->right != NULL) ? curr->right->val : 0;

        // If the left child exists:
        if (curr->left)
        {
          // Add the left child's value to the next level's sum.
          nextLevelSum += curr->left->val;

          // Update the left child's value with the sibling sum (since cousins aren't directly tracked here).
          curr->left->val = siblingSum;

          // Add the left child to the queue for processing in the next level.
          que.push(curr->left);
        }

        // If the right child exists:
        if (curr->right)
        {
          // Add the right child's value to the next level's sum.
          nextLevelSum += curr->right->val;

          // Update the right child's value with the sibling sum.
          curr->right->val = siblingSum;

          // Add the right child to the queue for processing in the next level.
          que.push(curr->right);
        }
      }

      // After processing all nodes at the current level, move to the next level by updating the `levelSum`.
      levelSum = nextLevelSum;
    }

    // Return the modified tree's root.
    return root;
  }
};
