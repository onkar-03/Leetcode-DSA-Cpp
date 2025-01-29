#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 Basic Sorting
 * ---------------------------
 * Time Complexity: O(nlogn)
 * - The time complexity comes from the sorting operation, which is O(nlogn).
 * - This approach uses the sort() function from the C++ standard library.
 * ---------------------------
 * Space Complexity: O(1)
 * - No additional space is used apart from the input array.
 */
class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    // 1 - red
    // 2 - white
    // 3 - blue

    // Sort the array in non-decreasing order
    // The sorted array will group the 1's (red), 2's (white), and 3's (blue) together
    sort(nums.begin(), nums.end());
  }
};

/*
 * Approach-2 (Counting Sort)
 * ---------------------------
 * Time Complexity: O(N)
 * - We make two passes over the array. The first pass is to count the occurrences of 0's, 1's, and 2's.
 * - The second pass is to rewrite the array based on the counts.
 * ---------------------------
 * Space Complexity: O(1)
 * - The space complexity is O(1) since we only use a few extra variables to count the occurrences of each color.
 */
class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    // Initialize counters for 0, 1, and 2
    int count0 = 0, count1 = 0, count2 = 0;

    // Count the number of 0's, 1's, and 2's
    for (int num : nums)
    {
      if (num == 0)
      {
        count0++;
      }
      else if (num == 1)
      {
        count1++;
      }
      else
      {
        count2++;
      }
    }

    // Refill the array with the sorted colors (0's, 1's, and 2's)
    // Fill with 0's first
    for (int i = 0; i < count0; i++)
    {
      nums[i] = 0;
    }
    // Then fill with 1's
    for (int i = count0; i < count0 + count1; i++)
    {
      nums[i] = 1;
    }
    // Finally fill with 2's
    for (int i = count0 + count1; i < count0 + count1 + count2; i++)
    {
      nums[i] = 2;
    }
  }
};

/*
 * Approach-3: Using Dutch National Flag Algorithm
 * -------------------------
 * Time Complexity: O(N)
 * - We iterate over the array only once, making the time complexity O(N).
 * - The swapping operations inside the loop are constant time operations.
 * -------------------------
 * Space Complexity: O(1)
 * - We use only a few extra variables (low, mid, high), so the space complexity is O(1).
 */
class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    // Initialize three pointers: low, mid, and high
    // 3 pointers for sorting 0's, 1's, and 2's
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    /*
     * Explanation:
     * - We use three pointers: low, mid, and high.
     * - low: It points to the boundary where all elements before it are 0s.
     * - mid: It traverses the array and is responsible for sorting elements into their correct position.
     * - high: It points to the boundary where all elements after it are 2s.
     *
     * The array is divided into four sections:
     * 1. Elements from 0 to low - 1 (inclusive) are all 0s.
     * 2. Elements from low to mid - 1 (inclusive) are all 1s.
     * 3. Elements from mid to high are unsorted.
     * 4. Elements from high + 1 to n - 1 are all 2s.
     *  */

    // Iterate through the array
    while (mid <= high)
    {
      // If the current element is 0, swap it with the element at the low pointer and move both low and mid pointers forward
      if (nums[mid] == 0)
      {
        swap(nums[low], nums[mid]);
        low++;
        mid++;
      }
      // If the current element is 1, just move the mid pointer forward
      else if (nums[mid] == 1)
      {
        mid++;
      }
      // If the current element is 2, swap it with the element at the high pointer and move the high pointer backward
      else
      {
        swap(nums[mid], nums[high]);
        high--;
      }
    }
  }
};
