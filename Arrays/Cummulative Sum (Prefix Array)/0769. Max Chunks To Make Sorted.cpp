#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using prefixMax and suffixMin)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
  int maxChunksToSorted(vector<int> &arr)
  {
    int n = arr.size();

    // Create and initialize prefixMax and suffixMin arrays
    vector<int> prefixMax(begin(arr), end(arr));
    vector<int> suffixMin(begin(arr), end(arr));

    // Calculate prefixMax array: maximum values from the left up to each index
    // Start from 1 as nothing before 0th index hence the max for  0th index is the number itself
    for (int i = 1; i < n; i++)
    {
      prefixMax[i] = max(prefixMax[i - 1], prefixMax[i]);
    }

    // Calculate suffixMin array: minimum values from the right up to each index
    // Start frm n-2 as nothing after n-1 index hence the max for n-1 index is the number itself
    for (int i = n - 2; i >= 0; i--)
    {
      suffixMin[i] = min(suffixMin[i + 1], suffixMin[i]);
    }

    // Initialize the chunks counter
    int chunksCount = 0;

    // Traverse the array to calculate the number of chunks
    for (int i = 0; i < n; i++)
    {
      // pehleKaMax: maximum value to the left of the current index (inclusive)
      // If the current index is the first one, use -1 as there's no left part
      int pehleKaMax = i > 0 ? prefixMax[i - 1] : -1;

      // baadKaMin: minimum value to the right of the current index (inclusive)
      int baadKaMin = suffixMin[i];

      // If the maximum value of the left part is less than the minimum value of the right part,
      // we can split here and increment the chunk count
      if (pehleKaMax < baadKaMin)
      {
        chunksCount++;
      }
    }

    return chunksCount; // Return the total number of chunks
  }
};

// Approach-2: Using Cumulative Sum to determine the maximum number of chunks
// Time Complexity: O(n) -> Single pass through the array
// Space Complexity: O(1) -> Constant space usage (no extra space apart from a few variables)
class Solution
{
public:
  int maxChunksToSorted(vector<int> &arr)
  {
    // The size of the input array
    int n = arr.size();

    // Variables to store the cumulative sum of the array elements and indices

    // Cumulative sum of array elements
    int cumSum = 0;

    // Sum of indices (acts as expected sum if array was sorted)
    int normalSum = 0;

    // Counter to track the number of chunks that can be formed
    int chunksCount = 0;

    // Traverse through the array
    for (int i = 0; i < n; i++)
    {
      // Update the cumulative sum of array elements
      cumSum += arr[i];

      // Update the expected sum of indices if the array was sorted
      normalSum += i;

      // If the cumulative sum of elements matches the expected sum of indices (original sum), it indicates that all elements up to this point can form a sorted chunk
      if (cumSum == normalSum)
      {
        chunksCount++; // Increment the count of chunks
      }
    }

    // Return the total number of chunks that can be formed
    return chunksCount;
  }
};

// Approach-3: Using Maximum Element Check to determine the maximum number of chunks
// Time Complexity: O(n) -> Single pass through the array
// Space Complexity: O(1) -> Constant space usage (no extra space apart from variables)

class Solution
{
public:
  int maxChunksToSorted(vector<int> &arr)
  {
    // The size of the input array
    int n = arr.size();

    // Variable to track the maximum value encountered so far in the array
    int maxTillNow = -1;

    // Counter to track the number of chunks that can be formed
    int chunksCount = 0;

    // Traverse through the array
    for (int i = 0; i < n; i++)
    {
      // Update the maximum value encountered so far
      maxTillNow = max(maxTillNow, arr[i]);

      // If the maximum value encountered so far equals the current index `i`, it means all elements from the start of the array up to this point can form a sorted chunk
      if (maxTillNow == i)
      {
        chunksCount++; // Increment the count of chunks
      }
    }

    // Return the total number of chunks that can be formed
    return chunksCount;
  }
};
