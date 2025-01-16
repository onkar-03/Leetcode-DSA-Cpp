#include <bits/stdc++.h>
using namespace std;

// Approach 1: (Using Xor property)
// T.C : O(n)
// S.C : O(1)
class Solution
{
public:
  int xorAllNums(vector<int> &nums1, vector<int> &nums2)
  {
    int m = nums1.size(); // Size of nums1
    int n = nums2.size(); // Size of nums2
    int XOR = 0;          // Variable to store the final XOR result

    // If the size of nums1 (m) is odd, then each element of nums2 contributes to the XOR result
    if (m % 2 != 0)
    {
      for (int &num : nums2)
      {
        XOR ^= num; // XOR each element of nums2
      }
    }

    // If the size of nums2 (n) is odd, then each element of nums1 contributes to the XOR result
    if (n % 2 != 0)
    {
      for (int &num : nums1)
      {
        XOR ^= num; // XOR each element of nums1
      }
    }

    // Return the final XOR result
    return XOR;
  }
};
