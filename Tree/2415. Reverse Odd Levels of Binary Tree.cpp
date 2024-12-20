#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Approach-1 - Simple BFS
// T.C : O(n) : As we travel each level once
// S.C : O(n) : as we store all Nodes in a vector
class Solution
{
public:
  TreeNode *reverseOddLevels(TreeNode *root)
  {
    // Initialize a queue to perform level-order traversal
    queue<TreeNode *> que;
    que.push(root);

    // Start from level 0 (root level)
    int level = 0;

    // Perform level-order traversal
    while (!que.empty())
    {
      int size = que.size();         // Get the number of nodes at the current level
      vector<TreeNode *> levelNodes; // Vector to store nodes at the current level

      // Process all nodes at the current level
      while (size--)
      {
        TreeNode *temp = que.front(); // Get the front node in the queue
        que.pop();

        levelNodes.push_back(temp); // Add the node to the vector

        // Push left and right children to the queue (if they exist)
        if (temp->left)
        {
          que.push(temp->left);
        }
        if (temp->right)
        {
          que.push(temp->right);
        }
      }

      // Reverse the node values if the current level is odd
      if (level % 2 != 0)
      {
        int l = 0;
        int r = levelNodes.size() - 1;

        // Swap values between nodes symmetrically
        while (l < r)
        {
          int tempval = levelNodes[l]->val;        // Temporarily store the value of the left node
          levelNodes[l]->val = levelNodes[r]->val; // Assign the value of the right node to the left
          levelNodes[r]->val = tempval;            // Assign the stored value to the right node

          l++; // Move left pointer inward
          r--; // Move right pointer inward
        }
      }

      // Move to the next level
      level++;
    }

    // Return the modified tree
    return root;
  }
};

// Approach-2 - Tricky DFS (explained the trick on how to write such DFS)
// T.C : O(n) : As we travel each level once
// S.C : O(n) : Recursion using system Stack for Storing all Nodes
class Solution
{
public:
  void solve(TreeNode *L, TreeNode *R, int level)
  {
    // Base case: if either of the nodes is NULL, return
    if (L == NULL || R == NULL)
    {
      return;
    }

    // If the current level is odd, swap the values of the nodes
    if (level % 2 == 1)
    {
      TreeNode *temp = L; // Temporarily store the left node
      L = R;              // Assign the right node to the left
      R = temp;           // Assign the stored node to the right
    }

    // Recursively call for the next level
    // Proceed symmetrically: left of L with right of R and right of L with left of R
    solve(L->left, R->right, level + 1);
    solve(L->right, R->left, level + 1);
  }

  TreeNode *reverseOddLevels(TreeNode *root)
  {
    // Start the recursive function with the left and right children of the root at level 1
    solve(root->left, root->right, 1);

    // Return the modified tree
    return root;
  }
};
