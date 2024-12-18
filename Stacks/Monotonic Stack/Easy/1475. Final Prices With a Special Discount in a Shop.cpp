#include <bits/stdc++.h>
using namespace std;
// Approach-1 (Brute Force)
// Time Complexity: O(n^2) - Due to the nested loops iterating over the array.
// Space Complexity: O(1) - No extra space used apart from the result vector (output only).
class Solution
{
public:
  vector<int> finalPrices(vector<int> &prices)
  {
    // Size of Prices Vwector
    int n = prices.size();

    // Initialize the result vector as a copy of the input prices.
    // Each element is initially assumed to have no discount applied.
    vector<int> result(begin(prices), end(prices));

    // Iterate through the prices array.
    for (int i = 0; i < n; i++)
    {
      // For each price, check the next elements for a potential discount.
      for (int j = i + 1; j < n; j++)
      {
        // If a smaller or equal price is found, it can be used as the discount.
        if (prices[j] <= prices[i])
        {
          result[i] -= prices[j]; // Apply the discount.
          break;                  // Stop searching after finding the first valid discount.
        }
      }
    }

    // Return the final array of prices after applying discounts.
    return result;
  }
};
