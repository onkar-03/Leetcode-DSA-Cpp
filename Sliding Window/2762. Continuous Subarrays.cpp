#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using Ordered Map)
// Time Complexity: ~O(n) - Explained in the video why this is linear.
// Space Complexity: ~O(1) - Explained in the video why this is constant.
class Solution
{
public:
  long long continuousSubarrays(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the input array.

    map<int, int> mp; // Ordered map to store the frequency of elements in the current window.

    int i = 0; // Left pointer for the sliding window.
    int j = 0; // Right pointer for the sliding window.

    long long count = 0; // Variable to store the count of valid subarrays.

    // Traverse the array using the right pointer.
    while (j < n)
    {
      mp[nums[j]]++; // Add the current element to the map and update its frequency.

      // Check if the difference between the maximum and minimum element in the window exceeds 2.
      while (abs(mp.rbegin()->first - mp.begin()->first) > 2)
      {
        // Shrink the window by moving the left pointer.
        mp[nums[i]]--; // Decrease the frequency of the element at the left pointer.

        if (mp[nums[i]] == 0)
        {
          mp.erase(nums[i]); // Remove the element from the map if its frequency becomes 0.
        }
        i++; // Move the left pointer to the right.
      }

      // Calculate the number of valid subarrays ending at index j.
      count += j - i + 1;

      // Move the right pointer to the next element.
      j++;
    }

    return count; // Return the total count of valid subarrays.
  }
};
