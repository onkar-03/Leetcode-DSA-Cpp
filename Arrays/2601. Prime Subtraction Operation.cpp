#include <bits/stdc++.h>
using namespace std;

// Approach (Store prime and check)
// T.C : O(n * maxNum)
// S.C : O(1000) ~ O(1)
class Solution
{
public:
  // Array to store prime status of numbers up to 1000.
  bool isPrime[1000];
  void sieve()
  { // Time Complexity: O(1), as the sieve has a fixed limit of 1000.
    // Initialize all numbers up to 1000 as prime.
    fill(isPrime, isPrime + 1000, true);
    isPrime[0] = false; // 0 is not a prime number.
    isPrime[1] = false; // 1 is not a prime number.

    // Sieve algorithm to mark non-prime numbers.
    for (int i = 2; i * i < 1000; i++)
    {
      if (isPrime[i] == true)
      {
        for (int j = i * i; j < 1000; j += i)
        {
          isPrime[j] = false; // Mark multiples of `i` as non-prime.
        }
      }
    }
  }

  bool primeSubOperation(vector<int> &nums)
  {
    int n = nums.size();

    // Populate the `isPrime` array with prime status.
    sieve();

    // Traverse the array from the second last element to the beginning.
    for (int i = n - 2; i >= 0; i--)
    {
      // If `nums[i]` is already less than `nums[i+1]`, continue to the next element.
      if (nums[i] < nums[i + 1])
      {
        continue;
      }

      // If `nums[i] >= nums[i+1]`, adjust `nums[i]` by subtracting a prime number to make `nums[i] < nums[i+1]`.
      for (int p = 2; p < nums[i]; p++)
      { // Check all primes less than `nums[i]`.
        if (!isPrime[p])
        { // Skip non-prime numbers.
          continue;
        }

        // If subtracting `p` from `nums[i]` makes it less than `nums[i+1]`, apply the operation and break.
        if (nums[i] - p < nums[i + 1])
        {
          nums[i] -= p;
          break;
        }
      }

      // After attempting to subtract primes, if `nums[i]` is still >= `nums[i+1]`, return false.
      if (nums[i] >= nums[i + 1])
      {
        return false;
      }
    }

    // If the array can be made strictly increasing, return true.
    return true;
  }
};
