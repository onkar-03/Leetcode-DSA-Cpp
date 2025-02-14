#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Brute Force)
 * T.C : add() - O(1), getProduct() - O(k)
 * - The `add` function runs in O(1) as it simply appends a number to the vector.
 * - The `getProduct` function runs in O(k) since it iterates over the last k elements to compute the product.
 * ----------------------------
 * S.C : O(n) for the stream
 * - The vector `nums` stores all added numbers, requiring O(n) space.
 */
class ProductOfNumbers
{
public:
  // Stores all numbers in the stream.
  vector<int> nums;
  // Keeps track of the number of elements stored.
  int n;

  ProductOfNumbers()
  {
    nums.clear();
    n = 0;
  }

  void add(int num)
  {
    // Append the number to the stream.
    nums.push_back(num);
  }

  int getProduct(int k)
  {
    // Initialize product to 1.
    int prod = 1;

    // Get the current size of the vector.
    int n = nums.size();

    for (int i = n - k; i < n; i++)
    {
      // Multiply the last k elements.
      prod *= nums[i];
    }

    // Return the final product.
    return prod;
  }
};

/*
 * Approach-2 (Follow-up optimal in O(1))
 * T.C : O(1) for both methods
 * - The `add` function runs in O(1) as it only appends a value or resets the vector.
 * - The `getProduct` function runs in O(1) using prefix product division.
 * ----------------------------
 * S.C : O(n) for the stream
 * - The vector `nums` stores cumulative products, requiring O(n) space.
 */
class ProductOfNumbers
{
public:
  // Stores the cumulative product of added numbers.
  vector<int> nums;

  // Keeps track of the number of elements stored.
  int n;

  ProductOfNumbers()
  {
    // Clears any existing elements in nums.
    nums.clear();

    // Resets the count of elements.
    n = 0;
  }

  void add(int num)
  {
    // If the number to add is 0
    if (num == 0)
    {
      // Reset the list when a zero is encountered.
      nums = {};
      n = 0;
    }
    // If the number to add is != 0
    else
    {
      // If empty, add num directly.
      if (nums.empty())
      {
        nums.push_back(num);
      }
      // Otherwise, store cumulative product.
      else
      {
        nums.push_back(nums[n - 1] * num);
      }
      // Increment the count of numbers.
      n++;
    }
  }

  int getProduct(int k)
  {
    // If k is greater than available elements, return 0.
    if (k > n)
    {
      return 0;
    }
    // If k equals n, return the last cumulative product.
    else if (k == n)
    {
      return nums[n - 1];
    }
    // Use division to get the product of last k elements.
    return nums[n - 1] / nums[n - k - 1];
  }
};
