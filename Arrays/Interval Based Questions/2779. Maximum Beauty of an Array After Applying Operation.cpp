#include <bits/stdc++.h>
using namespace std;

// Approach-1: Convert the problem into intervals and find the maximum overlapping intervals.
// Time Complexity: O(n log n) - Due to sorting of ranges.
// Space Complexity: O(n) - For storing intervals and the deque.
class Solution
{
public:
  int maximumBeauty(vector<int> &nums, int k)
  {
    // Size of array
    int n = nums.size();

    // Step 1: Convert each number into an interval [num - k, num + k]
    // This represents the range of values that can contribute to "beauty".
    vector<pair<int, int>> ranges(n);

    // Iterate through the whole array and push range for each one of them in the Pair Vector
    for (int num : nums)
    {
      ranges.push_back({num - k, num + k});
    }

    // Step 2: Sort the intervals by their start points.
    // Sorting helps in processing intervals in order, allowing us to efficiently track overlaps.
    sort(ranges.begin(), ranges.end());

    // Variable to track the maximum "beauty" value.
    int maxBeauty = 0;

    // Deque to store the end points of overlapping intervals.
    deque<int> deq;

    // Step 3: Traverse through each interval in the sorted list.
    for (const auto &range : ranges)
    {
      // Remove intervals from the deque that no longer overlap with the current interval.
      // Since the deque is sorted by range endpoints, we only check the front.
      while (!deq.empty() && deq.front() < range.first)
      {
        deq.pop_front();
      }

      // Add the endpoint of the current interval to the deque.
      deq.push_back(range.second);

      // The size of the deque now represents the count of overlapping intervals,
      // which is equivalent to the current "beauty" value.
      maxBeauty = max(maxBeauty, (int)deq.size());
    }

    return maxBeauty; // Return the maximum beauty found.
  }
};

// Approach-2: Sorting and Using Binary Search
// Time Complexity: O(nlogn) : Sorting takes O(nlogn), and for each element, binary search takes O(logn), resulting in O(nlogn) overall.
// Space Complexity: O(1) - No extra space used apart from variables.
class Solution
{
public:
  int binarySearch(vector<int> &nums, int target)
  {
    int l = 0;               // Start of the search range
    int r = nums.size() - 1; // End of the search range
    int result = 0;          // Stores the index of the farthest element satisfying nums[mid] <= target

    while (l <= r) // While there are elements to search
    {
      // Calculate the mid-point to avoid integer overflow
      int mid = l + (r - l) / 2;

      // Check if the current mid value satisfies the condition
      if (nums[mid] <= target)
      {
        result = mid; // Update result to current mid, as it satisfies nums[mid] <= target
        l = mid + 1;  // Move the left pointer to search for farther valid indices
      }
      else
      {
        r = mid - 1; // If nums[mid] > target, move the right pointer to search lower values
      }
    }
    return result; // Return the farthest index found
  }
  int maximumBeauty(vector<int> &nums, int k)
  {
    // Step 1: Sort the array to prepare for binary search and range calculations
    sort(begin(nums), end(nums));

    // Stores the maximum number of elements in any valid range
    int maxBeauty = 0;

    // Iterate through each element in the array to consider it as the start of the range
    for (int i = 0; i < nums.size(); i++)
    {
      int x = nums[i];   // Current starting element of the range
      int y = x + 2 * k; // Calculate the upper bound of the range (x + 2*k)

      // [w, x, y, z]: Elements of the array sorted in ascending order.
      // For any value `k`, each element `x` can have a range of [x-k, x+k], and similarly, another element `y` will have a range of [y-k, y+k].
      // To ensure these two ranges overlap, the condition for overlap is: x-k <= y+k, which simplifies to x + 2*k >= y.

      // The condition x + 2*k >= y guarantees that the values between x and y overlap
      // in the range of [x, x + 2*k]:
      //   - `x` is the current starting value in the array.
      //   - `y` is the largest value we want to include in the range, ensuring it satisfies the overlap condition.

      // Step 2: Use binary search to find the farthest index `j` such that nums[j] <= y
      int j = binarySearch(nums, y);

      // Step 3: Calculate the number of elements in the range [x, x + 2*k] and update maxBeauty
      // j - i + 1 gives the count of elements in the range
      maxBeauty = max(maxBeauty, j - i + 1);
    }

    return maxBeauty; // Return the maximum beauty found
  }
};

// Approach-3: Using Sliding Window
// Time Complexity: O(nlogn) - Sorting takes O(nlogn), and the sliding window runs in O(n).
// Space Complexity: O(1) - No extra space used apart from variables.
class Solution
{
public:
  int maximumBeauty(vector<int> &nums, int k)
  {
    int n = nums.size(); // Get the size of the input array

    // Step 1: Sort the array to make it easier to calculate valid ranges
    sort(nums.begin(), nums.end());

    int i = 0;         // Start of the sliding window
    int j = 0;         // End of the sliding window
    int maxBeauty = 0; // Stores the maximum number of elements in any valid range

    // Step 2: Use the sliding window to find valid ranges
    while (i < n)
    { // Iterate through each element as the start of the range

      // Expand the window by increasing j as long as the range [nums[i], nums[j]] satisfies the condition
      while (j < n && nums[j] - nums[i] <= 2 * k)
      {
        j++; // Increment j to include the next element in the range
      }

      // Calculate the size of the current range and update maxBeauty
      // j - i gives the count of elements in the range [nums[i], nums[j-1]]
      maxBeauty = max(maxBeauty, j - i);

      // Slide the window by moving the start pointer i
      i++;
    }

    // Step 3: Return the maximum beauty found
    return maxBeauty;
  }
};
