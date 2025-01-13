#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force : TLE)
// T.C : Constructor: O(n), where n is the length of the nums array
//       Update: O(1), sumRange: O(n)
// S.C : O(n)
class NumArray
{
public:
  vector<int> num; // Stores the array elements
  int n;           // Size of the input array

  /**
   * @brief Constructor to initialize the NumArray object.
   * @param nums Input array for initialization.
   * The array is copied to a member variable for future updates and queries.
   */
  NumArray(vector<int> &nums)
  {
    num = nums;      // Copy the input array to the member variable
    n = nums.size(); // Store the size of the input array
  }

  /**
   * @brief Updates an element in the array.
   * @param index Index in the array to update.
   * @param val New value to set at the given index.
   * Updates the value of the array at the given index.
   */
  void update(int index, int val)
  {
    num[index] = val; // Directly update the value in the array
  }

  /**
   * @brief Calculates the sum of elements in a given range [left, right].
   * @param left Start index of the range.
   * @param right End index of the range.
   * @return Sum of elements in the range [left, right].
   * Uses a simple loop to calculate the sum, resulting in O(n) complexity.
   */
  int sumRange(int left, int right)
  {
    int sum = 0; // Initialize sum to 0
    for (int i = left; i <= right; i++)
    {
      // Iterate through the range
      // Add each element in the range to the sum
      sum += num[i];
    }
    return sum; // Return the calculated sum
  }
};
