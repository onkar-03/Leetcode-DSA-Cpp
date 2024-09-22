#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to find the k-th lexicographical number from 1 to n
  int findKthNumber(int n, int k)
  {
    // Start by assuming the answer is 1 (smallest number lexicographically)
    long ans = 1;

    // Loop until we reach the k-th number
    for (int i = 1; i < k;)
    {
      // Calculate the gap between the current prefix (ans) and the next prefix (ans + 1)
      const long gap = getGap(ans, ans + 1, n);

      // If adding this gap would still be less than or equal to k, move to the next prefix
      if (i + gap <= k)
      {
        // Move forward by the gap size
        i += gap;
        // Move to the next lexicographical prefix
        ++ans;
      }
      else
      {
        // Otherwise, move one step deeper into the current prefix (multiply by 10)
        ++i;
        ans *= 10;
      }
    }

    // Return the k-th lexicographical number
    return ans;
  }

private:
  // Function to calculate the gap between two lexicographical prefixes
  long getGap(long a, long b, long n)
  {
    long gap = 0;

    // While the current prefix is still within bounds
    while (a <= n)
    {
      // Calculate how many numbers fall under the range of prefix 'a' and 'b'
      // This is the difference between 'b' and 'a', but limited by 'n + 1'
      gap += min(n + 1, b) - a;
      // Move to the next level of the tree (i.e., append another digit)
      a *= 10;
      b *= 10;
    }

    // Return the total gap between prefix 'a' and 'b'
    return gap;
  }
};

int main()
{
  Solution solution;

  // Example inputs: n = 13 and k = 2
  int n = 13;
  int k = 2;

  // Call the function to find the k-th smallest lexicographical number
  int ans = solution.findKthNumber(n, k);

  // Output the result in a user-friendly format
  cout << k << "th smallest Lexicographical Number from 1 to " << n << " is : " << ans;

  return 0;
}
