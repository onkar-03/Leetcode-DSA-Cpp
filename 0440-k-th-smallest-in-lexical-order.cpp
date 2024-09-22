#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to find the k-th lexicographical number from 1 to n
  int findKthNumber(int n, int k)
  {
    long curr = 1; // Start with the smallest lexicographical number
    k--;           // Adjust k since we are starting at 1 (to account for 0-based indexing)

    // Loop until we find the k-th number
    while (k > 0)
    {
      // Count how many numbers exist between the current prefix (curr) and the next prefix (curr + 1)
      long countNum = count(curr, curr + 1, n);

      // If adding this count would still be less than or equal to k, move to the next prefix
      if (k >= countNum) // If k is greater than or equal to count
      {
        k -= countNum; // Decrease k by count since we can skip this entire range
        curr++;        // Move to the next prefix
      }
      else
      {
        // We have a number in the current prefix, so we go one step deeper
        curr *= 10; // Go deeper into the current prefix
        k--;        // We visited one more number in this case
      }
    }

    // Return the k-th lexicographical number
    return curr;
  }

private:
  // Function to calculate the count of numbers between two lexicographical prefixes
  long count(long curr, long next, long n)
  {
    long count = 0; // Initialize count of numbers in the range

    // While the current prefix is still within bounds
    while (curr <= n)
    {
      // Count how many numbers fall under the range of prefix 'curr' to 'next'
      count += min(n + 1, next) - curr; // The difference limited by 'n + 1'

      // Move to the next level of the tree (i.e., append another digit)
      curr *= 10; // Go to the next level of the tree
      next *= 10; // Update next to the next prefix
    }

    // Return the total count between prefix 'curr' and 'next'
    return count;
  }
};

int main()
{
  Solution solution;

  // Example inputs: n = 22 and k = 14
  int n = 22; // The upper limit for lexicographical numbers
  int k = 14; // The k-th number to find

  // Call the function to find the k-th smallest lexicographical number
  int ans = solution.findKthNumber(n, k);

  // Output the result in a user-friendly format
  cout << ans; // Print the k-th lexicographical number

  return 0;
}
