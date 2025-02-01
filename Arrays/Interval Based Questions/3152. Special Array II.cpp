#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Using cumulative sum to efficiently handle range queries
 * - We build a cumulative sum array (`cumSum`) where each element stores the count of "violating indices" up to that position.
 * - A "violating index" occurs when two consecutive elements in the array have the same parity (both even or both odd).
 * - The cumulative sum array allows us to quickly check for violations within any given range of the array.
 * - For each query, we check the difference in the cumulative sum values for the specified range.
 * - If the difference is zero, it means there are no violations in that subarray, making it "special".
 * --------------------
 * T.C: O(n + m)
 * - Building the cumulative sum array takes O(n), and processing the m queries takes O(m), so the overall time complexity is O(n + m).
 * --------------------
 * S.C: O(n)
 * - We store the cumulative sum array, which takes O(n) space.
 */

class Solution
{
public:
  vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
  {
    int n = nums.size();    // Size of the array
    int m = queries.size(); // Number of queries

    // Step 1: Initialize the cumulative sum array.
    vector<int> cumSum(n, 0); // To store cumulative count of violating indices

    // Step 2: Build the cumulative sum array.
    for (int i = 1; i < n; i++)
    {
      // Check if consecutive elements have the same parity
      if (nums[i] % 2 == nums[i - 1] % 2)
      {
        // Increment the count of violating indices
        cumSum[i] = cumSum[i - 1] + 1;
      }
      else
      {
        cumSum[i] = cumSum[i - 1]; // No violation, carry forward the previous count
      }
    }

    // Step 3: Process each query to check if the subarray is "special"
    vector<bool> result(m, false); // Store results for each query

    // Query index
    int i = 0;

    for (vector<int> &query : queries)
    {
      int start = query[0];
      int end = query[1];

      // Check if there are any violations in the range [start, end]
      if (cumSum[end] - cumSum[start] == 0) // No violations
      {
        result[i] = true; // Subarray is "special"
      }
      i++;
    }

    return result; // Return the results for all queries
  }
};

/*
 * Approach-2 (Using 2 pointers)
 * - We use a two-pointer technique to efficiently track the longest "special" subarray starting from each index.
 * - The `validRightMostIdx[i]` array stores the rightmost index `j` such that the subarray `[i..j]` is special, meaning there are no consecutive elements with the same parity.
 * - We move the `j` pointer to extend the valid subarray as far as possible, ensuring that no two consecutive elements have the same parity.
 * - Once the `validRightMostIdx` array is built, each query can be answered in constant time by checking if the end index is within the range of the special subarray starting at the query's start index.
 * --------------------
 * T.C: O(n + m)
 * - The two-pointer traversal takes O(n), as the `i` and `j` pointers traverse the array, but each pointer only moves forward once.
 * - Processing the queries takes O(m), as each query is answered in constant time by simply checking the `validRightMostIdx[start]` for the given `start` and `end`.
 * --------------------
 * S.C: O(n)
 * - We store the `validRightMostIdx` array, which takes O(n) space.
 */

class Solution
{
public:
  vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
  {
    int n = nums.size();    // Size of the array
    int m = queries.size(); // Number of queries

    vector<int> validRightMostIdx(n); // To store the rightmost index of the special subarray

    int i = 0;
    int j = 0;

    // Step 1: Build the validRightMostIdx array using two pointers
    while (i < n)
    {
      if (j < i)
      {
        j = i; // Ensure j starts at least at i
      }

      // Extend j as long as the parity of consecutive elements is different
      while (j + 1 < n && nums[j] % 2 != nums[j + 1] % 2)
      {
        j++;
      }

      validRightMostIdx[i] = j; // Store the rightmost index of the valid subarray starting at i
      i++;
    }

    vector<bool> result(m, false); // To store the result for each query

    // Step 2: Process each query
    for (int i = 0; i < m; i++)
    {
      int start = queries[i][0];
      int end = queries[i][1];

      // If the end index is within the valid range starting from 'start', mark the subarray as special
      if (end <= validRightMostIdx[start])
      {
        result[i] = true; // Subarray is special
      }
    }

    return result; // Return the results for all queries
  }
};

/*
 * Approach-3 (Using binary search)
 * - We first build a list of "violating indices" where two consecutive elements in the array have the same parity (both even or both odd).
 * - This list `vi` is maintained in sorted order as we traverse the array.
 * - For each query, we perform a binary search to check if any of the violating indices fall within the specified range.
 * - If we find a violating index in the range, we return `false` for that query, indicating that the subarray is not special.
 * - Otherwise, we return `true`, meaning the subarray is special (no violations found).
 * --------------------
 * T.C: O(n + m * log n)
 * - Building the list of violating indices takes O(n) time as we traverse the array once.
 * - Each query is processed in O(log n) time due to the binary search in the `vi` list.
 * - Thus, the overall time complexity is O(n + m * log n).
 * --------------------
 * S.C: O(n)
 * - We store the violating indices list `vi`, which takes O(n) space.
 */

class Solution
{
public:
  bool bSearch(vector<int> &vi, int sp, int ep)
  {
    int l = 0;
    int r = vi.size() - 1;

    // Perform binary search on the violating indices list
    while (l <= r)
    {
      int mid = l + (r - l) / 2;

      if (vi[mid] < sp)
      {
        l = mid + 1; // Narrow the search to the right
      }
      else if (vi[mid] > ep)
      {
        r = mid - 1; // Narrow the search to the left
      }
      else
      {
        // Found a violating index in the range
        return true;
      }
    }

    // No violating index found in the range
    return false;
  }

  vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
  {
    int m = queries.size(); // Number of queries
    int n = nums.size();    // Size of the array

    // List to store violating indices
    vector<int> vi;

    // Step 1: Build the list of violating indices (O(n))
    for (int i = 1; i < n; i++)
    {
      // Check if consecutive elements have the same parity
      if (nums[i] % 2 == nums[i - 1] % 2)
      {
        vi.push_back(i); // Add the index to the violating indices list
      }
    }

    vector<bool> result(m, false); // Store the result for each query

    // Step 2: Process each query (O(m))
    for (int i = 0; i < m; i++)
    {
      int start = queries[i][0];
      int end = queries[i][1];

      // Perform binary search to check if there are any violating indices in the range [start + 1, end]
      bool hasViolatingIndexInRange = bSearch(vi, start + 1, end); // O(log n)

      // If no violating index is found, mark the subarray as special
      if (!hasViolatingIndexInRange)
      {
        result[i] = true;
      }
    }

    return result; // Return the results for all queries
  }
};
