#include <bits/stdc++.h>
using namespace std;

/*
 * Approach:
 * - For each test case, we are given an array and an integer k representing the maximum length of subarrays that can be reversed.
 * - If k >= n (the entire array can be reversed), it is always possible to sort the array.
 * - Otherwise, we need to check if the array can be sorted using reversals of subarrays of length at most k.
 * - The idea is that if the maximum allowed subarray length is greater than or equal to 2, it should be possible to sort the array by reversing small sections of it.
 * - If k == 1, no elements can be rearranged, and we can only check if the array is already sorted.
 *
 * T.C: O(n) for each test case because the sorting and comparison steps take O(n) time.
 * S.C: O(n) for storing the array.
 */

int main()
{
  int t;
  cin >> t; // Read the number of test cases

  // Process each test case
  while (t--)
  {
    long long n, k;
    cin >> n >> k; // Read the number of boxes (n) and the maximum subarray length (k)

    vector<long long> a(n); // Array to store the numbers on the boxes

    // Read the values on the boxes
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    // If k >= n, we can always reverse the entire array and sort it
    if (k >= n)
    {
      cout << "YES" << endl;
    }
    // If k == 1, no elements can be rearranged, check if the array is already sorted
    else if (k == 1)
    {
      bool sorted = true;
      for (int i = 1; i < n; i++)
      {
        if (a[i] < a[i - 1])
        {
          sorted = false;
          break;
        }
      }
      if (sorted)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
    // If k >= 2, it is always possible to sort the array using multiple reversals
    else
    {
      cout << "YES" << endl;
    }
  }

  return 0; // End of program
}
