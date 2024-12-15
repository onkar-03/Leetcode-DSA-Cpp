#include <bits/stdc++.h>
using namespace std;

// Approach-1: Choosing the class with the maximum improvement (delta) at every step
// Note: This approach is inefficient for large inputs, as it will lead to TLE/MLE due to the high time complexity of O(extraStudents * n).
// Time Complexity: O(extraStudents * n), where `n` is the number of classes.
// Space Complexity: O(n), for storing the current pass ratios (PR) and updated pass ratios (updatedPR).
class Solution
{
public:
  double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
  {
    int n = classes.size(); // Total number of classes

    // Step 1: Calculate the initial pass ratios (PR) for all classes
    vector<double> PR(n);
    for (int i = 0; i < n; i++)
    {
      double ratio = (double)classes[i][0] / classes[i][1]; // passRatio = passed/total
      PR[i] = ratio;
    }

    // Step 2: Distribute the extra students one by one
    while (extraStudents--)
    { // Loop for each extra student (O(extraStudents))
      // Step 2.1: Calculate the updated pass ratios (if an extra student is added to each class)
      vector<double> updatedPR(n);
      for (int i = 0; i < n; i++)
      {
        double newRatio = (double)(classes[i][0] + 1) / (classes[i][1] + 1); // Add an extra student
        updatedPR[i] = newRatio;
      }

      // Step 2.2: Find the class that provides the maximum improvement (delta) in pass ratio
      int bestClassIdx = 0;
      double bestDelta = 0;

      for (int i = 0; i < n; i++)
      {
        // Iterate over all classes to find the best one (O(n))
        // Improvement in pass ratio for class `i`
        double delta = updatedPR[i] - PR[i];
        if (delta > bestDelta)
        { // Update the best class with the highest delta
          bestDelta = delta;
          bestClassIdx = i;
        }
      }

      // Step 2.3: Assign an extra student to the chosen class (with the maximum delta)
      // Update the pass ratio for the best class
      PR[bestClassIdx] = updatedPR[bestClassIdx];

      // Increment the number of students who passed
      classes[bestClassIdx][0]++;
      // Increment the total number of students in the class
      classes[bestClassIdx][1]++;
    }

    // Step 3: Calculate the final average pass ratio after distributing all extra students
    double result = 0.0; // Variable to store the sum of pass ratios
    for (int i = 0; i < n; i++)
    {
      result += PR[i];
    }

    // Return the average pass ratio
    return result / n;
  }
};
