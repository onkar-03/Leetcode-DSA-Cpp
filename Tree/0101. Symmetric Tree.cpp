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

// Approach : Using Tricky DFS (Recursively)
// T.C : O(n) : As we travel each level once
// S.C : O(n) : Recursion using system Stack for Storing all Nodes
class Solution
{
public:
  // Helper function to check if two subtrees are symmetric
  bool solve(TreeNode *L, TreeNode *R)
  {
    // Base case: If both nodes are NULL, the subtrees are symmetric
    if (L == NULL && R == NULL)
    {
      return true; // Both subtrees are empty
    }

    // If one node is NULL but the other is not, the subtrees are not symmetric
    if (L == NULL || R == NULL)
    {
      return false; // One subtree is missing
    }

    // If the values of the current nodes are different, the subtrees are not symmetric
    if (L->val != R->val)
    {
      return false; // Mismatched values
    }

    // Recursively check symmetry:
    // - The left child of the left subtree must match the right child of the right subtree
    // - The right child of the left subtree must match the left child of the right subtree
    return solve(L->left, R->right) && solve(L->right, R->left);
  }

  // Main function to determine if a binary tree is symmetric
  bool isSymmetric(TreeNode *root)
  {
    // An empty tree or a tree with only one node is symmetric by definition
    if (root == NULL)
    {
      return true;
    }

    // Check symmetry of the left and right subtrees starting from the root
    return solve(root->left, root->right);
  }
};
