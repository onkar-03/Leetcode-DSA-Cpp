#include <bits/stdc++.h>
using namespace std;

// Definition of the TreeNode structure, representing a node in a binary tree
struct TreeNode
{
  int val;         // Value of the node
  TreeNode *left;  // Pointer to the left child
  TreeNode *right; // Pointer to the right child

  // Default constructor initializes value to 0 and children to nullptr
  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  // Constructor initializes value to a given integer, children are nullptr
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  // Constructor initializes value, left, and right children with given values
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  long kthLargestLevelSum(TreeNode *root, int k)
  {
    // Min-Heap to store the k largest level sums
    priority_queue<long, vector<long>, greater<long>> pq;

    // Queue to perform level-order traversal (BFS)
    queue<TreeNode *> que;

    // Add the root node to the queue to start BFS
    que.push(root);

    // Continue while there are nodes to process
    while (!que.empty())
    {
      // Get the number of nodes at the current level
      int n = que.size();

      // Initialize the sum of the current level to 0
      long levelSum = 0;

      // Process all nodes at the current level
      while (n--)
      {
        // Get the node at the front of the queue
        TreeNode *poppedNode = que.front();

        // Remove the node from the queue
        que.pop();

        // Add the node's value to the current level sum
        levelSum += poppedNode->val;

        // If the left child exists, add it to the queue
        if (poppedNode->left != NULL)
        {
          que.push(poppedNode->left);
        }

        // If the right child exists, add it to the queue
        if (poppedNode->right != NULL)
        {
          que.push(poppedNode->right);
        }
      }

      // Add the current level sum to the min-heap
      pq.push(levelSum);

      // If the heap size exceeds k, remove the smallest element
      if (pq.size() > k)
      {
        pq.pop();
      }
    }

    // If there are fewer than k levels, return -1; otherwise, return the k-th largest sum
    return pq.size() < k ? -1 : pq.top();
  }
};

// --- Why Min Heap ??
// In the context of finding the k-th largest level sum in a binary tree, a min-heap is employed due to its ability to efficiently maintain the largest elements while providing quick access to the smallest of these elements. By utilizing a min-heap with a fixed size of k, we can ensure that we are only storing the k largest level sums encountered during the breadth-first traversal of the tree