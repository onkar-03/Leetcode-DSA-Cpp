#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Sorting array with indices)
// T.C : O(nlogn) for Sorting and O(N) for Traversal, hence overall Time Complexity is O(nlogn)
// S.C : O(n), as we take a visited array of size n
class Solution
{
public:
  long long findScore(vector<int> &nums)
  {
    int n = nums.size();

    // To store elements and their indices as pairs
    vector<pair<int, int>> vec(n);

    // Initialize vec with elements and their indices
    for (int i = 0; i < n; i++)
    {
      vec[i] = {nums[i], i};
    }

    // Sort the elements by their values (ascending order) while keeping track of indices
    sort(vec.begin(), vec.end()); // O(N LogN)

    // To calculate overall Score
    long long score = 0;

    // To mark elements and their neighbors as "processed"
    vector<bool> visited(n, false);

    // Iterate over sorted elements to calculate the score
    for (int i = 0; i < n; i++) // O(N)
    {
      int element = vec[i].first; // Value of the element
      int idx = vec[i].second;    // Original index of the element

      // Process the element if it hasn't been visited yet
      if (!visited[idx])
      {
        score += element;    // Add the element's value to the score
        visited[idx] = true; // Mark the current element as visited

        // Mark the left neighbor (if it exists) as visited
        if (idx - 1 >= 0 && visited[idx - 1] == false)
        {
          visited[idx - 1] = true; // Mark left neighbor
        }

        // Mark the right neighbor (if it exists) as visited
        if (idx + 1 < n && visited[idx + 1] == false) // Corrected boundary condition
        {
          visited[idx + 1] = true; // Mark right neighbor
        }
      }
    }

    return score; // Return the final calculated score
  }
};


