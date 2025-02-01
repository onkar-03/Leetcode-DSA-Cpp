#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force Merge with Two Pointers and Extra Space
 * We will use two pointers, left and right, to traverse through nums1 and nums2.
 * A third array (arr3) will be used to merge the elements from nums1 and nums2 in sorted order.
 * Once the merging is done, we will copy the elements back into nums1.
 * ----------------------------
 * T.C: O(2* (m + n) Due to traversal of arrays and storing them in arr3 and then merging it back to nums1
 * ----------------------------
 * S.C: O(m + n) - Because we are using an extra array to store the merged result
 */
class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    vector<int> arr3(m + n); // Declare a 3rd array to store the merged result
    int left = 0;
    int right = 0;
    int index = 0;

    // Insert the elements from nums1 and nums2 into arr3 using left and right pointers
    while (left < m && right < n)
    {
      // If the current element in nums1 is smaller than the current element in nums2
      if (nums1[left] < nums2[right])
      {
        // Place the element from nums1 into arr3
        arr3[index] = nums1[left];
        // Move the left pointer to the next element in nums1
        left++;
        // Increment the index in arr3 to store the next element
        index++;
      }
      // If the current element in nums1 is equal to the current element in nums2
      else if (nums1[left] == nums2[right])
      {
        // Place the element from nums1 into arr3
        arr3[index] = nums1[left];
        // Move the left pointer to the next element in nums1
        left++;
        // Increment the index in arr3 to store the next element
        index++;

        // Place the element from nums2 into arr3
        arr3[index] = nums2[right];
        // Move the right pointer to the next element in nums2
        right++;
        // Increment the index in arr3 to store the next element
        index++;
      }
      // If the current element in nums2 is smaller than the current element in nums1
      else
      {
        // Place the element from nums2 into arr3
        arr3[index] = nums2[right];
        // Move the right pointer to the next element in nums2
        right++;
        // Increment the index in arr3 to store the next element
        index++;
      }
    }

    // If left pointer reaches the end of nums1, fill arr3 with remaining elements of nums2
    while (left < m)
    {
      arr3[index++] = nums1[left++];
    }

    // If right pointer reaches the end of nums2, fill arr3 with remaining elements of nums1
    while (right < n)
    {
      arr3[index++] = nums2[right++];
    }

    // Fill back the merged elements from arr3[] to nums1[]:
    for (int i = 0; i < m + n; i++)
    {
      nums1[i] = arr3[i];
    }
  }
};

/*
 * Approach-2: Two-Pointer Merge with Sorting
 * - The current approach attempts to merge the two arrays nums1 and nums2.
 * - First, we copy all elements from nums2 into nums1 starting from the last position in nums1 and going backwards.
 *   This effectively shifts the elements of nums1 and prepares space for the elements of nums2.
 * - After filling nums1 with elements from nums2, we sort nums1 to ensure the array is in non-decreasing order.
 *
 * T.C: O((m + n) * log(m + n)) - Sorting nums1 will take O((m + n) * log(m + n)) time.
 * S.C: O(1) - The merging is done in-place, so no extra space beyond nums1 and nums2 is used.
 */
class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    int j = 0;         // Pointer for the first element in nums2
    int i = m + n - 1; // Pointer for the last position in nums1

    // Merge nums1 and nums2 from the end to the start
    while (j < n)
    {
      nums1[i] = nums2[j]; // Place elements from nums2 into nums1
      i--;                 // Move the pointer in nums1
      j++;                 // Move the pointer in nums2
    }

    // Sort nums1 to get the final merged array
    sort(nums1.begin(), nums1.end());
  }
};

/*
 * Approach: Three-Pointer Merge
 * We will use three pointers to merge two sorted arrays in-place:
 * 1. `last` - Points to the last available position in nums1.
 * 2. `m` - Points to the last valid element in the original part of nums1.
 * 3. `n` - Points to the last element in nums2.
 * The idea is to compare the elements from the end of both arrays (nums1 and nums2),
 * and place the larger element at the end of nums1. We then decrement the pointers
 * accordingly. This process is repeated until all elements are merged into nums1.
 *
 * If nums2 still has elements left after the main loop, we copy them into nums1.
 * ----------------------------
 * T.C: O(m + n) - We traverse both arrays (nums1 and nums2) once, and each element is
 * moved at most once, making the time complexity linear in terms of the total number of elements.
 * -----------------------------
 * S.C: O(1) - The merge is done in-place, so no extra space is used except for the input arrays
 */
class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    // Pointer for the last position in nums1
    int last = m + n - 1;

    // While there are elements in both nums1 and nums2
    while (m > 0 && n > 0)
    {
      // Compare the elements from the end of nums1 and nums2
      if (nums1[m - 1] > nums2[n - 1])
      {
        // Place the larger element in the last position of nums1
        nums1[last] = nums1[m - 1];
        m--; // Move the pointer in nums1
      }
      else
      {
        // Place the larger element from nums2 in the last position of nums1
        nums1[last] = nums2[n - 1];
        n--; // Move the pointer in nums2
      }
      last--; // Move the last pointer in nums1
    }

    // If there are any remaining elements in nums2, copy them over
    while (n > 0)
    {
      nums1[last] = nums2[n - 1];
      n--;
      last--;
    }
  }
};
