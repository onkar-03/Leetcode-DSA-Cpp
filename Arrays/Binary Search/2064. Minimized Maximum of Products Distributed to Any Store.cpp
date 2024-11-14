#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool possibleToDistribute(int x, vector<int> &quantities, int numberOfShops)
  {
    for (int &products : quantities)
    {
      // Subtract the required number of shops for this product batch,
      // calculated by dividing the quantity by the max limit per shop, then rounding up.
      numberOfShops -= ceil((double)products / x);

      // If the required number of shops exceeds available shops, distribution isn't possible
      if (numberOfShops < 0)
      {
        return false;
      }
    }
    return true; // Distribution is possible with 'x' products per shop
  }

  // Function to find the minimized maximum number of products per shop
  int minimizedMaximum(int n, vector<int> &quantities)
  {
    // 'n' is the number of shops and 'quantities' holds the demand for each product type
    int m = quantities.size(); // Number of product types

    int l = 1;                                                  // Minimum number of products per shop
    int r = *max_element(quantities.begin(), quantities.end()); // Max possible number of products per shop
    int mid;                                                    // Middle point for binary search
    int result = INT_MAX;                                       // Variable to store minimized maximum

    // Binary search to find the minimum possible maximum number of products per shop
    while (l <= r)
    {
      mid = l + (r - l) / 2; // Midpoint to test as the maximum number of products per shop

      // If distribution is possible with 'mid' products per shop, update result and try smaller values
      if (possibleToDistribute(mid, quantities, n))
      {
        result = mid; // Update the result with the current valid maximum
        r = mid - 1;  // Look for a smaller possible maximum
      }
      else
      {
        l = mid + 1; // If not possible, increase the limit
      }
    }
    return result; // Return the minimized maximum number of products per shop
  }
};
