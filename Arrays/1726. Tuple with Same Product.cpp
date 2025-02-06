#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Brute Force)
 * We iterate over all possible pairs (a, b) and (c, d) using four nested loops.
 * For each pair, we check if the product of the two numbers is the same.
 * Since each valid tuple can be arranged in 8 different ways, we multiply the count by 8.
 * ---------------------------
 * T.C: O(n^4)
 * - We have four nested loops, each iterating at most `n` times, leading to O(n^4) complexity.
 * ---------------------------
 * S.C: O(1)
 * - No extra data structures are used apart from a few integer variables.
 */
class Solution
{
public:
  int tupleSameProduct(vector<int> &nums)
  {
    // Stores the count of valid tuples
    int totalNumberOfTuples = 0;

    // Get the size of the input array
    int n = nums.size();

    // Iterate over all possible pairs (a, b)
    // Choose `a`
    for (int i = 0; i < n; i++)
    {
      // Choose `b` (ensuring distinct from `a`)
      for (int j = i + 1; j < n; j++)
      {
        // Iterate over all possible pairs (c, d)
        // Choose `c`
        for (int k = 0; k < n; k++)
        {
          // Choose `d` (ensuring distinct from `c`)
          for (int l = k + 1; l < n; l++)
          {

            // Ensure all indices are distinct
            if (i != k && i != l && j != k && j != l)
            {
              int product1 = nums[i] * nums[j]; // Compute product of (a, b)
              int product2 = nums[k] * nums[l]; // Compute product of (c, d)

              // Check if products are equal
              if (product1 == product2)
              {
                totalNumberOfTuples++; // Valid tuple found, increment count
              }
            }
          }
        }
      }
    }

    // Each unique (a, b, c, d) combination corresponds to 8 possible tuples
    // Divide by 2 to correct double-counting
    return (totalNumberOfTuples / 2) * 8;
  }

  /*
   * Example:
   * ---------
   * Given nums = {2, 3, 4, 6}, one valid tuple is {2, 6, 3, 4}.
   * This tuple can be arranged in 8 different ways:
   *
   * (2, 6, 3, 4), (2, 6, 4, 3), (6, 2, 3, 4), (6, 2, 4, 3)
   * (3, 4, 2, 6), (4, 3, 2, 6), (3, 4, 6, 2), (4, 3, 6, 2)
   *
   * Later, our loop will also pick the tuple {3, 4, 2, 6}, which
   * again results in the same 8 permutations. To avoid double
   * counting, we divide the total count by 2 before multiplying by 8.
   */
};

/*
 * Approach-2 (Improving a little more after sorting)
 * In this approach, we first sort the array to improve the efficiency
 * of finding matching products.
 * After sorting, we use four nested loops to select pairs (a, b) and (c, d), and then check if their products are equal.
 * Due to sorting we dont have to now / by 2 as we dont get repeated pairs, as we iterate just till k < j after sorting
 * ---------------------------
 * T.C: O(n^4 + nlogn)
 * - Sorting the array takes O(n log n).
 * - The four nested loops iterate through the array, giving O(n^4).
 * ---------------------------
 * S.C: O(1)
 * - No extra data structures are used apart from a few integer variables.
 */
class Solution
{
public:
  int tupleSameProduct(vector<int> &nums)
  {
    int totalNumberOfTuples = 0;  // Stores the count of valid tuples
    int n = nums.size();          // Get the size of the input array
    sort(begin(nums), end(nums)); // Sort the array to improve matching efficiency

    // Iterate over all possible pairs (a, b)
    // Choose `a`
    for (int i = 0; i < n; i++)
    {
      // Choose `b` (distinct from `a`)
      for (int j = n - 1; j > i; j--)
      {

        // Iterate over all possible pairs (c, d)
        // Choose `c`
        for (int k = i + 1; k < j; k++)
        {
          // Choose `d` (distinct from `c`)
          for (int l = j - 1; l > k; l--)
          {

            int p1 = nums[i] * nums[j]; // Compute product of (a, b)
            int p2 = nums[k] * nums[l]; // Compute product of (c, d)

            // Check if products are equal
            if (p1 == p2)
            {
              totalNumberOfTuples++; // Valid tuple found, increment count
            }
          }
        }
      }
    }

    // Each unique (a, b, c, d) combination corresponds to 8 possible tuples
    // Multiply by 8 for all permutations of the tuple
    return totalNumberOfTuples * 8;
  }
};

/*
 * Approach-3 (Better Brute Force)
 * In this approach, we optimize the brute force solution by using an unordered set.
 * After sorting the array, for each pair (a, b), we calculate their product.
 * For each subsequent value `c`, we check if the corresponding `d` value (product/c) exists using a set to store previously seen numbers
 * (a * b / c) = result, check if it is in the set i.e already encountered or not if yes we have a tuple else not
 * ---------------------------
 * T.C: O(n^3)
 * - The outer two loops (i and j) iterate over all pairs, and the inner loop (k) checks for possible matching pairs.
 *   This leads to a total of O(n^3) operations.
 * ---------------------------
 * S.C: O(n)
 * - The unordered set `st` is used to store the previously seen numbers, which takes O(n) space.
 */
class Solution
{
public:
  int tupleSameProduct(vector<int> &nums)
  {
    int totalNumberOfTuples = 0; // Stores the count of valid tuples
    int n = nums.size();         // Get the size of the input array

    sort(begin(nums), end(nums)); // Sort the array to optimize matching

    // Iterate over all possible pairs (a, b)
    for (int i = 0; i < n; i++)
    { // Choose `a`
      for (int j = n - 1; j > i; j--)
      { // Choose `b` (distinct from `a`)

        int product = nums[i] * nums[j]; // Compute product of (a, b)
        unordered_set<int> st;           // Set to store previously seen `c` values

        // Iterate over all possible `c`
        for (int k = i + 1; k < j; k++)
        { // Choose `c`

          if (product % nums[k] == 0)
          {                                 // Check if product is divisible by `c`
            int lValue = product / nums[k]; // Compute corresponding `d`

            // Check if `lValue` already exists in the set
            if (st.count(lValue))
            {
              totalNumberOfTuples++; // Valid tuple found, increment count
            }

            // Insert `c` into the set
            st.insert(nums[k]);
          }
        }
      }
    }

    // Each unique (a, b, c, d) combination corresponds to 8 possible tuples
    return totalNumberOfTuples * 8; // Multiply by 8 for all permutations of the tuple
  }
};

/*
 * Approach-4 (Optimized with a Hash Map)
 * In this approach, we use a hash map to store the frequency of each product of pairs (a, b).
 * For each pair (a, b), we compute their product and increment the frequency of that product in the map.
 * After processing all pairs, we calculate the number of valid tuples based on the frequency of each product.
 * We then multiply by 8 for the 8 permutations of each tuple.
 * ---------------------------
 * T.C: O(n^2)
 * - We use two nested loops to calculate the product of every pair (a, b), which takes O(n^2) time.
 * ---------------------------
 * S.C: O(n^2)
 * - The unordered map `mp` stores the products of pairs, and in the worst case, there are O(n^2) distinct products.
 */
class Solution
{
public:
  int tupleSameProduct(vector<int> &nums)
  {
    int n = nums.size();        // Get the size of the input array
    unordered_map<int, int> mp; // Map to store product frequencies

    // Calculate the product of every pair (i, j) and store the frequency
    for (int i = 0; i < n; i++)
    { // Choose `a`
      for (int j = i + 1; j < n; j++)
      {                               // Choose `b` (distinct from `a`)
        int prod = nums[i] * nums[j]; // Compute product of (a, b)
        mp[prod]++;                   // Increment frequency of this product
      }
    }

    int tuples = 0; // Stores the total number of valid tuples

    // For each product, calculate the number of valid tuples
    for (auto &it : mp)
    {
      int prod = it.first;  // The product
      int freq = it.second; // The frequency of this product

      // The number of ways to choose two pairs with the same product
      tuples += freq * (freq - 1) / 2; // Combination of freq items taken 2 at a time
    }

    // Each valid combination corresponds to 8 permutations of the tuple
    return tuples * 8; // Multiply by 8 for all permutations of the tuple
  }
};