#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using brute force) - Passes 95/101 test cases
// T.C : O(n^2)
// S.C : O(1)
class Solution
{
public:
  int maxWidthRamp(vector<int> &nums)
  {
    int n = nums.size();
    int ramp = 0;
    for (int i = 0; i < n; ++i)
    {
      for (int j = i + 1; j < n; ++j)
      {
        if (nums[i] <= nums[j])
        {
          ramp = max(ramp, j - i);
        }
      }
    }
    return ramp;
  }
};