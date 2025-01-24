#include <bits/stdc++.h>
using namespace std;

/*
 * Approach: Two Pointer No Extra Space
 * ---------------
 * We can solve this problem in-place using two pointers, i and j.
 * - i keeps track of the last unique element's position, while j traverses
 * through the array.
 * - If nums[i] is not equal to nums[j], it means nums[j] is a unique element,
 * so we increment i and assign nums[j] to nums[i].
 * - After the loop finishes, we return i + 1, which represents the length of
 * the array with unique elements.
 *
 * Time Complexity (T.C): O(n)
 * - The two-pointer approach ensures that we only traverse the array once, so
 * the time complexity is O(n), where n is the size of the array.
 *
 * Space Complexity (S.C): O(1)
 * - We only use two extra variables i and j, which require constant space, so
 * the space complexity is O(1).
 */
class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int n = nums.size();

    // If the array is empty, return 0
    if (n == 0)
      return 0;

    // i is for the unique elements, j is for iterating
    // through the array
    int i = 0, j = 1;

    // Loop to compare and shift unique elements
    while (j < n)
    {
      // If nums[i] is not equal to nums[j],
      // it's a unique element
      if (nums[i] != nums[j])
      {
        // Move the unique element to the correct position
        nums[++i] = nums[j];
      }
      j++; // Move j to the next element
    }

    return i + 1; // The number of unique elements is i + 1
  }
};
