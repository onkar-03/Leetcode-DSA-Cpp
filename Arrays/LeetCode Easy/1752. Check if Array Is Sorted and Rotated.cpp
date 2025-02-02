#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Super Brute Force)
 * - Try all possible rotations of the array and check if any of them is sorted.
 * - We create a temporary array for each rotation and compare it for sorted order.
 * ----------------------------
 * T.C : O(n^2)
 * - We perform n rotations.
 * - For each rotation, we traverse the array (O(n)) to check if it's sorted.
 * - This results in O(n^2) complexity.
 * ----------------------------
 * S.C : O(n)
 * - We use an extra array `sorted` of size n to store each rotation.
 */

class Solution
{
public:
  bool check(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the array

    vector<int> sorted(n); // Temporary array to store rotated versions

    // Try every possible rotation
    for (int r = 0; r < n; r++)
    {
      int idx = 0; // Index for the sorted array

      // Copy elements from rotation point to end
      for (int i = r; i < n; i++)
      {
        sorted[idx] = nums[i];
        idx++;
      }

      // Copy elements from start to rotation point
      for (int i = 0; i < r; i++)
      {
        sorted[idx] = nums[i];
        idx++;
      }

      // Check if the array is sorted
      bool isSorted = true;
      for (int i = 0; i < n - 1; i++)
      {
        if (sorted[i] > sorted[i + 1])
        { // If any adjacent pair is unsorted
          isSorted = false;
          break;
        }
      }

      if (isSorted)
      {
        return true; // If any rotation is sorted, return true
      }
    }

    return false; // No valid sorted rotation found
  }
};

/*
 * Approach-2 (Better Brute Force)
 * - First, create a sorted version of the original array.
 * - Try all possible rotations and check if any of them match the sorted array.
 * ----------------------------
 * T.C : O(n^2)
 * - Sorting the array takes O(n log n).
 * - Checking all n rotations takes O(n^2).
 * - Overall, this results in O(n^2) complexity.
 * ----------------------------
 * S.C : O(n)
 * - We store a sorted version of the array, which takes O(n) space.
 */

class Solution
{
public:
  bool check(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the array

    vector<int> sorted = nums;        // Copy the original array
    sort(begin(sorted), end(sorted)); // Sort the copy to get the reference sorted order

    // Try every possible rotation
    for (int r = 0; r < n; r++)
    {
      bool isSorted = true; // Flag to check if the rotation matches the sorted array

      // Compare rotated version with sorted array
      for (int i = 0; i < n; i++)
      {
        if (sorted[i] != nums[(i + r) % n])
        {                   // Circular shift check
          isSorted = false; // If any mismatch occurs, mark as false
          break;
        }
      }

      if (isSorted)
      {
        return true; // If any rotation matches the sorted array, return true
      }
    }

    return false; // No valid sorted rotation found
  }
};

/*
 * Approach-3: (Optimal) Count Pivot
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
  bool check(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the array
    int count = 0;       // Initialize the count of "breaks" in order

    // Check if the first element is greater than the last element
    // Instead of doing %n as in approach 4 we directly initially check for the first and last index values
    if (nums[0] < nums[n - 1])
      count++;

    // Traverse through the array to find "breaks" in order
    for (int i = 0; i < n - 1; i++)
    {
      // Check if the current element is greater than the next element
      if (nums[i] > nums[i + 1])
      {
        // Increment the count of "breaks"
        count++;
      }

      // If there are more than one "breaks," return false
      if (count > 1)
        return false;
    }

    // If at most one "break" is found, the array is sorted and rotated
    return true;
  }
};

/*
 * Approach-4: (Optimal) Pivot Count
 * It's the same the only difference is we dont explicitly check for the first and last element edge case that's it
 * ---------------------------
 * Time Complexity (T.C.): O(n)
 * - We iterate through the array once to count the peaks.
 * - The modulo operation % n ensures that the last element is compared with the first element in a circular manner, which takes constant time.
 * ---------------------------
 * Space Complexity (S.C.): O(1)
 * - We only use a constant amount of extra space to store the `peak` variable.
 */

class Solution
{
public:
  bool check(vector<int> &nums)
  {
    int n = nums.size();

    int peak = 0;
    for (int i = 0; i < n; i++)
    {

      // % n ensures that when i is at the last element, we compare it with the first element
      // If the current element is greater than the next element (circular comparison)
      if (nums[i] > nums[(i + 1) % n])
      {
        peak++; // We have found a peak
      }
    }

    // If there is at most one peak, the array can be rotated to be sorted
    return peak <= 1;
  }
};
