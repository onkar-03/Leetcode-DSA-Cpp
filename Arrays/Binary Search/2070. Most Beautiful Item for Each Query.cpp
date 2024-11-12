#include <bits/stdc++.h>
using namespace std;

// Approach: Binary Search with Preprocessing
// Time Complexity: O(n log n + n + m * log n), where n is the number of items and m is the number of queries.
// Space Complexity: O(1)
class Solution
{
public:
  // Binary Search function to find the maximum beauty within a given price range.
  // Time Complexity: O(log n), where n is the size of items.
  int customBinarySearch(vector<vector<int>> &items, int queryPrice)
  {
    int l = 0;
    int r = items.size() - 1;
    int maxBeauty = 0;

    while (l <= r)
    {
      int mid = l + (r - l) / 2;

      // If the item's price is greater than the query price, discard the current and right-side items
      if (items[mid][0] > queryPrice)
      {
        r = mid - 1; // Move left
      }
      else
      {
        // Update maxBeauty if this item offers a higher beauty within the price limit
        maxBeauty = max(maxBeauty, items[mid][1]);
        l = mid + 1; // Move right
      }
    }

    return maxBeauty;
  }

  // Main function to process items and queries to return maximum beauty for each query price
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
  {
    int n = items.size();
    int m = queries.size();
    vector<int> result(m);

    // Step 1: Sort items by price in ascending order for binary search
    // Format: {price, beauty}
    // T.C : O(logn)
    sort(begin(items), end(items));

    // Step 2: Preprocess to update each item with the maximum beauty seen up to that price
    int maxBeautySeen = items[0][1];
    for (int i = 1; i < n; i++) // O(n)
    {
      maxBeautySeen = max(maxBeautySeen, items[i][1]);
      items[i][1] = maxBeautySeen; // Update beauty to reflect max seen so far
    }

    // Step 3: For each query, perform a binary search to find maximum beauty within the query price
    for (int i = 0; i < m; i++) // O(m)
    {
      int queryPrice = queries[i];
      result[i] = customBinarySearch(items, queryPrice); // O(n logn)
    }

    return result;
  }
};
