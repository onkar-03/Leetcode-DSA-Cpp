#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Swapping elements in nums)
// TC: O(n! * n)
// This is because there are n! permutations, and for each permutation, we spend O(n) time to add it to the result.
// S.C: O(n)
// The recursive stack uses O(n), temp and st also take O(n), and storing the results requires O(n! * n) for all permutations.
class Solution
{
public:
  int n;

  vector<vector<int>> result; // result to keep the permutation elements
  unordered_set<int> st;      // Using a set to track elements already used

  // Function to generate permutations
  void solve(vector<int> temp, vector<int> nums)
  {
    // Base case: when a permutation is complete (temp.size() == nums.size())
    if (temp.size() == nums.size())
    {
      result.push_back(temp); // Add the current permutation to the result and return
      return;
    }

    // Iterate over the elements of nums
    for (int i = 0; i < n; i++)
    {
      // If the element nums[i] is not already in set means not used till now
      if (st.find(nums[i]) == st.end())
      {
        st.insert(nums[i]);      // Mark this element as used
        temp.push_back(nums[i]); // Add it to the current permutation

        // Recursively generate permutations with the current temp
        solve(temp, nums);

        temp.pop_back();   // Backtrack by removing the last element
        st.erase(nums[i]); // Unmark this element
      }
    }
  }

  // Main function to initiate permutation generation
  vector<vector<int>> permute(vector<int> &nums)
  {
    n = nums.size();  // Store the size of nums
    vector<int> temp; // Temporary vector to hold a single permutation

    // Start the recursive generation of permutations
    solve(temp, nums);

    // Return the result which holds all permutations
    return result;
  }
};

// Approach-2 (General Backtracking Pattern for solving Subsets, Permutations, Combination Sum, etc.)

class Solution
{
public:
  int n;                      // To store the Size
  vector<vector<int>> result; // To store all the permutations

  // Function to generate permutations
  void solve(int idx, vector<int> nums)
  {
    // Base case: if we've processed all elements, add the current permutation to result
    if (idx == n)
    {
      result.push_back(nums); // Push the current permutation into the result
      return;
    }

    // Loop over all possible elements to place at position idx
    for (int i = idx; i < n; i++)
    {
      swap(nums[idx], nums[i]); // Swap element at idx with element at i to generate a new permutation
      solve(idx + 1, nums);     // Recurse with the next index
      swap(nums[idx], nums[i]); // Backtrack: swap back to restore the array
    }
  }

  vector<vector<int>> permute(vector<int> &nums)
  {
    n = nums.size(); // Store the size of the input array
    solve(0, nums);  // Start solving from index 0
    return result;   // Return all the permutations
  }
};
