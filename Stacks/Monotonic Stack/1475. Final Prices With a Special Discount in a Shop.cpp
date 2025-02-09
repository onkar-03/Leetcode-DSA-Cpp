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
    // Size of Prices Vector
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

// Approach-2 (Monotonic Stack)
// Time Complexity: O(2 * n) ~= O(n)
//    - Each element is pushed and popped from the stack at most once.
// Space Complexity: O(n) Due to the stack that stores indices.
class Solution
{
public:
  vector<int> finalPrices(vector<int> &prices)
  {
    // Size of prices
    int n = prices.size();

    // Initialize the result vector as a copy of the input prices.
    vector<int> result(begin(prices), end(prices));

    // Stack to maintain indices of prices in a monotonic decreasing order.
    stack<int> st;

    // Iterate through the prices array.
    for (int i = 0; i < n; i++)
    {

      // While the stack is not empty and the current price is smaller than  or equal to the price at the index stored at the top of the stack:
      while (!st.empty() && prices[i] <= prices[st.top()])
      {
        // Apply the discount: Subtract the current price from the price at the index on top of the stack.
        result[st.top()] -= prices[i];
        // Pop the index from the stack since the discount has been applied.
        st.pop();
      }

      // Push the current index onto the stack.
      st.push(i);
    }

    // Return the final array of prices after applying discounts.
    return result;
  }
};
