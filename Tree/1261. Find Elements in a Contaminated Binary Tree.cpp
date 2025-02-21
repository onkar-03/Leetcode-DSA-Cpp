#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using DFS)
// T.C : O(n)
// S.C : O(n)
class FindElements
{
public:
  unordered_set<int> st;
  void dfs(TreeNode *root, int x)
  {
    if (!root)
      return;

    root->val = x;
    st.insert(x);
    dfs(root->left, 2 * x + 1);
    dfs(root->right, 2 * x + 2);
  }
  FindElements(TreeNode *root)
  {
    st.clear();
    dfs(root, 0);
  }

  bool find(int target)
  {
    return st.count(target);
  }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */