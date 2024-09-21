#include <bits/stdc++.h>
using namespace std;

/*
    Given an integer array nums, return an array such that:
    answer[i] is equal to the product of all elements of nums except nums[i].
    Example: nums = [1, 2, 3, 4] -> [24, 12, 8, 6], nums = [-1, 1, 0, -3, 3] -> [0, 0, 9, 0, 0]

    The algorithm calculates prefix products in a forward pass,
    and then computes postfix products in a backward pass.

    Time Complexity: O(n)
    Space Complexity: O(1) (excluding the output array)
*/

class Solution
{
public:
  // Function to compute the product of array elements except self
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int n = nums.size();      // Get the size of the input array
    vector<int> result(n, 1); // Initialize the result array with 1s

    int prefix = 1; // Variable to hold the prefix product
    // First pass: Calculate prefix products
    for (int i = 0; i < n; i++)
    {
      result[i] = prefix;        // Set the current index in result to the current prefix product
      prefix = prefix * nums[i]; // Update the prefix product for the next iteration
    }

    int postfix = 1; // Variable to hold the postfix product
    // Second pass: Calculate postfix products
    for (int i = n - 1; i >= 0; i--)
    {
      result[i] = result[i] * postfix; // Multiply the current index in result with the current postfix product
      postfix = postfix * nums[i];     // Update the postfix product for the next iteration
    }

    return result; // Return the final result array
  }
};

int main()
{
  Solution solution;

  vector<int> nums = {1, 2, 3, 4}; // Example input array

  vector<int> result = solution.productExceptSelf(nums); // Call the function

  // Output the result
  for (auto it : result)
  {
    cout << it << " "; // Print each element of the result array
  }
  return 0; // Return success
}
