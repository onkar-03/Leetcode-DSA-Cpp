#include <bits/stdc++.h>
using namespace std;

/*
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space.
*/

class Solution
{
public:
  // Depth-First Search function to generate numbers in lexicographical order
  void dfs(int curr, int n, vector<int> &ans)
  {
    // Base case: if the current number exceeds n, return
    if (curr > n)
      return;

    // Add the current number to the result list
    ans.push_back(curr);

    // Generate the next numbers by appending digits 0 to 9
    for (int i = 0; i <= 9; i++)
    {
      // Recursive call: multiply the current number by 10 and add the new digit
      dfs(curr * 10 + i, n, ans); // This creates numbers like
    }
  }

  // Main function to initiate the DFS process
  vector<int> LexicalOrder(int n)
  {
    vector<int> ans; // Vector to store the results

    // Start the DFS from each digit 1 to 9
    for (int i = 1; i <= 9; i++)
    {
      dfs(i, n, ans); // Call the DFS for each starting digit
    }

    return ans; // Return the final list of numbers in lexicographical order
  }
};

int main()
{
  Solution solution;

  int num = 10;

  vector<int> result = solution.LexicalOrder(num);

  for (auto it : result)
  {
    cout << it << " ";
  }
  return 0;
}