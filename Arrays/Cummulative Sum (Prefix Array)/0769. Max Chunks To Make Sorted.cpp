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
    for (int i = 1; i < n; i++)
    {
      prefixMax[i] = max(prefixMax[i - 1], prefixMax[i]);
    }

    // Calculate suffixMin array: minimum values from the right up to each index
    for (int i = n - 2; i >= 0; i--)
    {
      suffixMin[i] = min(suffixMin[i + 1], suffixMin[i]);
    }

    int chunksCount = 0; // Initialize the chunks counter

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
