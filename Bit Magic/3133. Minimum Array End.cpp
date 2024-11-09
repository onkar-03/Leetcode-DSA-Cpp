#include <bits/stdc++.h>
using namespace std;

// Approach - Simple using AND and OR
// T.C : O(n)
// S.C : O(1)
class Solution
{
public:
  long long minEnd(int n, int x)
  {
    // Initialize num with the initial value of x
    long long num = x;

    // Loop through n-1 times to perform the operation
    for (int i = 1; i < n; i++)
    {
      // Perform a bitwise OR operation on (num+1) and x
      // This will combine the bits of num+1 and x, updating num
      num = (num + 1) | x;
    }

    // Return the final computed value of num after all operations
    return num;
  }
};