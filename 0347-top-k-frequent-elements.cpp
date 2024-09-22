#include <bits/stdc++.h>
using namespace std;
/*
    Given an integer array nums & an integer k, return the k most frequent elements
    Ex. nums = [1,1,1,2,2,3] k = 2 -> [1,2], nums = [1] k = 1 -> [1]

    Heap -> optimize with freq map & bucket sort (no freq can be > n), get results from end

 Time: O(n)
 Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    int n = nums.size(); // Get the size of the input array 'nums'

    // Step 1: Count the frequency of each element in the array 'nums'
    unordered_map<int, int> m; // An unordered_map to store each element and its frequency
    for (int i = 0; i < n; i++)
    {
      m[nums[i]]++; // Increment the count of nums[i] in the map
    }

    // Step 2: Create 'buckets' where each index represents the frequency
    // The vector at each index stores the elements that have that frequency.
    vector<vector<int>> buckets(n + 1); // We create n+1 buckets since no frequency can exceed n.
    for (auto it = m.begin(); it != m.end(); it++)
    {
      // For each unique element in the map, add it to the corresponding bucket
      // based on its frequency (the value in the map).
      buckets[it->second].push_back(it->first);
    }

    // Step 3: Gather the top k frequent elements
    vector<int> result; // This will store the final result

    // Iterate over the buckets starting from the back (highest frequency)
    for (int i = n; i >= 0; i--)
    {
      // If we've already collected k elements, we can stop early
      if (result.size() >= k)
      {
        break;
      }

      // If the current bucket is not empty, add all its elements to the result
      if (!buckets[i].empty())
      {
        // Insert all elements from the current bucket into the 'result' vector
        // using iterators buckets[i].begin() (points to the first element) and buckets[i].end()
        // (points just past the last element) to specify the range of elements to insert.w
        result.insert(result.end(), buckets[i].begin(), buckets[i].end());
      }
    }

    return result; // Return the top k frequent elements
  }
};

int main()
{
  Solution solution;
  vector<int> nums = {1, 1, 1, 2, 2, 3};

  int k = 2;

  vector<int> result = solution.topKFrequent(nums, k);

  for (auto it : result)
  {
    cout << it << endl;
  }

  return 0;
}