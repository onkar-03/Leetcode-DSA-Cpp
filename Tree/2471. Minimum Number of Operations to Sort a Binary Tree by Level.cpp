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

// Approach: Breadth-First Search (BFS) with an added step to calculate the minimum swaps required to sort node values at each level of the binary tree.
// Time Complexity: O(n + level * w logw), where `level` is the total number of levels, and `w` is the number of nodes in a level.
// Space Complexity: O(n), where `n` is the total number of nodes in the binary tree.
class Solution
{
public:
  // Helper function to count the minimum number of swaps required to sort an array.
  int countMinSwapsToSort(vector<int> &vec)
  {
    int swaps = 0;                               // Initialize swap counter
    vector<int> sortedVec(begin(vec), end(vec)); // Create a copy of the array for sorting

    // Sort the copied vector
    sort(begin(sortedVec), end(sortedVec));

    // Map to track the indices of the elements in the original vector
    // Key: value in vec, Value: index of that value in vec
    unordered_map<int, int> mp; 
    for (int i = 0; i < vec.size(); i++)
    {
      mp[vec[i]] = i; // Populate the map
    }

    // Iterate through the array to calculate swaps
    for (int i = 0; i < vec.size(); i++)
    {
      if (vec[i] == sortedVec[i])
      {
        continue; // Skip if the current element is already in the correct position
      }

      // Swap the current element with the element at its correct position
      int currIdx = mp[sortedVec[i]]; // Index of the correct element
      mp[vec[i]] = currIdx;           // Update map for the swapped element
      mp[vec[currIdx]] = i;           // Update map for the current element
      swap(vec[currIdx], vec[i]);     // Perform the swap
      swaps++;                        // Increment swap counter
    }

    return swaps; // Return total swaps
  }

  // Main function to calculate the minimum number of operations to make each level of the tree sorted.
  int minimumOperations(TreeNode *root)
  {
    queue<TreeNode *> que; // Queue to perform BFS
    que.push(root);        // Start with the root of the tree

    int result = 0; // Initialize the total number of operations

    // Perform BFS to traverse the tree level by level
    while (!que.empty())
    {
      int n = que.size(); // Number of nodes at the current level
      vector<int> vec;    // Vector to store node values at the current level

      // Process all nodes at the current level
      while (n--)
      {
        TreeNode *temp = que.front(); // Get the front node
        que.pop();                    // Remove it from the queue
        vec.push_back(temp->val);     // Add its value to the vector

        // Add the left and right children to the queue for the next level
        if (temp->left)
        {
          que.push(temp->left);
        }
        if (temp->right)
        {
          que.push(temp->right);
        }
      }

      // Add the minimum swaps required to sort the current level to the result
      result += countMinSwapsToSort(vec);
    }

    return result; // Return the total operations required
  }
};
