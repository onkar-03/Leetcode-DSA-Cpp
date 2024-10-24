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

// Approach - Simple Recursion
// T.C : ~O(4*n) as we traverse the Tree 4 Times in worst Case
// S.C : O(n) system stack space because of Recursion
class Solution
{
public:
  bool flipEquiv(TreeNode *root1, TreeNode *root2)
  {

    // Base case: if both trees are empty, they are trivially flip equivalent
    if (root1 == NULL && root2 == NULL)
      return true;

    // If one tree is empty and the other is not, they can't be flip equivalent
    if (root1 == NULL || root2 == NULL)
    {
      return false;
    }

    // If the current nodes have the same value, check their children for flip equivalence
    if (root1->val == root2->val)
    {
      // 1. If the values of the current nodes in both trees are equal, then we proceed to check their child nodes for equivalence.
      // 2. If the values of the current nodes in both trees are equal, then we proceed to check their child nodes for equivalence
      return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }

    // If the values of the current nodes differ, the trees cannot be flip equivalent
    return false;
  }
};
