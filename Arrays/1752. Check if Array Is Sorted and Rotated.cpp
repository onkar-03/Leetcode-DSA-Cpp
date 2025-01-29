#include <bits/stdc++.h>
using namespace std;

/*
 * Approach: Count Pivot
 * - The array is sorted but might be rotated at some pivot.
 * - There can be at most one "drop" in the array (a point where nums[i] > nums[i+1]).
 * - To determine if the array is sorted and rotated:
 *   1. Count the number of "drops" where `nums[i] > nums[i+1]`.
 *   2. If the first element is greater than the last element, it is considered a "drop."
 *   3. If the total number of "drops" is more than 1, the array is not sorted and rotated; otherwise, it is.
 * ----------------------------
 * Time Complexity (T.C.): O(n), where n is the size of the array.
 * - The array is traversed once, making it linear in time.
 * ----------------------------
 * Space Complexity (S.C.): O(1)
 * - No additional space is used apart from a few variables.
 * ----------------------------
 */

#include <vector>
using namespace std;

class Solution
{
public:
  // Function to check if the array is sorted and rotated
  bool check(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the array
    int count = 0;       // Initialize the count of "breaks" in order

    // Check if the first element is greater than the last element
    if (nums[0] < nums[n - 1])
      count++;

    // Traverse through the array to find "breaks" in order
    for (int i = 0; i < n - 1; i++)
    {
      if (nums[i] > nums[i + 1]) // Check if the current element is greater than the next element
        count++;                 // Increment the count of "breaks"

      if (count > 1) // If there are more than one "breaks," return false
        return false;
    }

    return true; // If at most one "break" is found, the array is sorted and rotated
  }
};
