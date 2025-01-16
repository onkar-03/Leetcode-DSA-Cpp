#include <bits/stdc++.h>
using namespace std;

// Approach-1: Using Frequency Count and XOR Property
// Time Complexity: O(n) - Iterates through nums1 and nums2 once.
// Space Complexity: O(n) - Uses an unordered_map to store frequencies.
class Solution
{
public:
  // Function to compute XOR of all possible pairwise sums of elements from two arrays
  int xorAllNums(vector<int> &nums1, vector<int> &nums2)
  {
    int m = nums1.size(); // Size of nums1
    int n = nums2.size(); // Size of nums2

    unordered_map<int, long> mp; // Map to store frequency contributions of each element

    // Step 1: Count the frequency of each element in nums1 multiplied by the size of nums2
    for (int &num : nums1)
    {
      mp[num] += n;
    }

    // Step 2: Count the frequency of each element in nums2 multiplied by the size of nums1
    for (int &num : nums2)
    {
      mp[num] += m;
    }

    int result = 0; // Variable to store the final XOR result

    // Step 3: Compute XOR for elements with an odd frequency
    for (auto &it : mp)
    {
      int num = it.first;   // The number
      int freq = it.second; // Its total frequency across both arrays

      if (freq % 2 != 0)
      {                // If frequency is odd
        result ^= num; // Include the number in the XOR result
      }
    }

    // Step 4: Return the final XOR result
    return result;
  }
};

// Approach 2: (Using Xor property)
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
