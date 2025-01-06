#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force Using unordered_set for extra space)
// Time Complexity: O(n^2) - For each box, we iterate through the indices of boxes containing '1'.
// Space Complexity: O(n) - For storing indices of boxes with '1' in the unordered_set.
class Solution
{
public:
  vector<int> minOperations(string boxes)
  {
    int n = boxes.length();
    unordered_set<int> st; // To store indices of boxes containing '1'.

    // Step 1: Populate the unordered_set with indices of boxes that contain '1'.
    for (int i = 0; i < n; i++)
    {
      if (boxes[i] == '1')
      {
        st.insert(i);
      }
    }

    vector<int> answer(n, 0); // Initialize the result array with 0.

    // Step 2: For each box, calculate the total number of operations
    // needed to move all '1's to that box.
    for (int i = 0; i < n; i++)
    {
      for (auto &idx : st)
      {
        answer[i] += abs(i - idx); // Add the distance between the current index and the '1' indices.
      }
    }

    return answer; // Return the result array containing the minimum operations for each box.
  }
};

// Approach-2: Brute Force with O(1) space
// Time Complexity: O(n^2) - Nested loops to calculate the operations for each ball
// Space Complexity: O(1) - No extra space used apart from the output vector
class Solution
{
public:
  vector<int> minOperations(string boxes)
  {
    int n = boxes.length();

    // Initialize the answer vector with 0 for all positions
    vector<int> answer(n, 0);

    // Iterate through each box to check if it contains a ball ('1')
    for (int i = 0; i < n; i++)
    {
      if (boxes[i] == '1')
      { // If the current box has a ball
        // Update the operations required to move this ball to every other box
        for (int j = 0; j < n; j++)
        {
          answer[j] += abs(j - i); // Add the distance between box i and box j
        }
      }
    }

    return answer; // Return the final vector with the minimum operations for each box
  }
};

// Approach-2: Brute Force with O(1) space
// Time Complexity: O(n^2) - Nested loops to calculate the operations for each ball
// Space Complexity: O(1) - No extra space used apart from the output vector
class Solution
{
public:
  vector<int> minOperations(string boxes)
  {
    int n = boxes.length();

    // Initialize the answer vector with 0 for all positions
    vector<int> answer(n, 0);

    // Iterate through each box to check if it contains a ball ('1')
    for (int i = 0; i < n; i++)
    {
      if (boxes[i] == '1')
      { // If the current box has a ball
        // Update the operations required to move this ball to every other box
        for (int j = 0; j < n; j++)
        {
          answer[j] += abs(j - i); // Add the distance between box i and box j
        }
      }
    }

    return answer; // Return the final vector with the minimum operations for each box
  }
};

// Approach-3: Optimal Using Cumulative Sum
// Time Complexity: O(n) - Efficiently calculates the result in a single traversal for each direction
// Space Complexity: O(1) - No extra space used apart from the output vector
class Solution
{
public:
  vector<int> minOperations(string boxes)
  {
    int n = boxes.size();
    vector<int> answer(n, 0);

    int cumValue = 0;    // Keeps track of the number of balls encountered so far
    int cumValueSum = 0; // Accumulates the total operations required for the left-to-right pass

    // Left-to-Right Cumulative Sum Calculation
    for (int i = 0; i < n; i++)
    {
      answer[i] = cumValueSum;             // Set the operations required so far for box i
      cumValue += boxes[i] == '0' ? 0 : 1; // Add 1 to cumValue if the current box contains a ball
      cumValueSum += cumValue;             // Update the cumulative operations sum
    }

    // Reset values for the Right-to-Left calculation
    cumValueSum = 0; // Reset cumulative sum
    cumValue = 0;    // Reset ball count

    // Right-to-Left Cumulative Sum Calculation
    for (int i = n - 1; i >= 0; i--)
    {
      answer[i] += cumValueSum;            // Add the operations from the right-to-left pass
      cumValue += boxes[i] == '0' ? 0 : 1; // Add 1 to cumValue if the current box contains a ball
      cumValueSum += cumValue;             // Update the cumulative operations sum
    }

    // Return the final vector with the minimum operations for each box
    return answer;
  }
};
