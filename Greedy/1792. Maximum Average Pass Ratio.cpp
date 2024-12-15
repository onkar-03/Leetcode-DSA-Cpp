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

    // Iterate over all the classes and calculate the average ratio
    for (int i = 0; i < n; i++)
    {
      // passRatio = passed/total
      double ratio = (double)classes[i][0] / classes[i][1];
      PR[i] = ratio;
    }

    // Step 2: Distribute the extra students one by one
    while (extraStudents--)
    { // Loop for each extra student (O(extraStudents))
      // Step 2.1: Calculate the updated pass ratios (if an extra student is added to each class)
      vector<double> updatedPR(n);

      // Iterate over all classes to calculate the updated pass ratio
      for (int i = 0; i < n; i++) // O(N)
      {
        // Add an extra student
        double newRatio = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
        updatedPR[i] = newRatio;
      }

      // Step 2.2: Find the class that provides the maximum improvement (delta) in pass ratio
      int bestClassIdx = 0;
      double bestDelta = 0;

      // Iterate over all classes to find the best one (O(n))
      for (int i = 0; i < n; i++) // O(N)
      {
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
    // Variable to store the sum of pass ratios
    double result = 0.0;
    for (int i = 0; i < n; i++) // O(N)
    {
      result += PR[i];
    }

    // Return the average pass ratio
    return result / n;
  }
};

// Approach-2:  (Choosing class with max delta/improvement everytime - Improving with max heap)
// Time Complexity: O(extraStudents * log(n)), where `n` is the number of classes.
// - Calculating delta for all classes: O(n)
// - Adding extra students: O(extraStudents * log(n)) due to heap operations.
// Space Complexity: O(n), for the max-heap.
class Solution
{
public:
// Define a shorthand for the max-heap element: {delta, index}
#define P pair<double, int>

  double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
  {
    int n = classes.size(); // Number of classes

    // Step 1: Initialize a max-heap to store the delta (improvement in pass ratio)
    // Each element in the heap is a pair: {delta, index}
    priority_queue<P> pq;

    // Calculate initial deltas for all classes and add them to the heap
    for (int i = 0; i < n; i++)
    {
      // Current pass ratio
      double current_PR = (double)classes[i][0] / classes[i][1];

      // Pass ratio after adding one student
      double new_PR = (double)(classes[i][0] + 1) / (classes[i][1] + 1);

      // Improvement in pass ratio
      double delta = new_PR - current_PR;

      // Push {delta, index} into the max-heap
      pq.push({delta, i});
    }

    // Step 2: Distribute extra students to classes with the maximum delta
    while (extraStudents--)
    { // Repeat for each extra student (O(extraStudents))
      // Step 2.1: Get the class with the maximum delta
      auto curr = pq.top(); // Top of the heap gives the max delta (O(log(n)))
      pq.pop();             // Remove the top element from the heap

      double delta = curr.first; // Current delta (max improvement)
      int idx = curr.second;     // Index of the class

      // Step 2.2: Add one extra student to the selected class
      classes[idx][0]++; // Increment passing students
      classes[idx][1]++; // Increment total students in the class

      // Step 2.3: Recalculate the delta for the updated class

      // Updated pass ratio
      double current_PR = (double)classes[idx][0] / classes[idx][1];

      // New pass ratio after adding another student
      double new_PR = (double)(classes[idx][0] + 1) / (classes[idx][1] + 1);

      // New delta (improvement in pass ratio)
      delta = new_PR - current_PR;

      // Step 2.4: Push the updated delta back into the heap
      pq.push({delta, idx}); // Push {new delta, index} back into the max-heap (O(log(n)))
    }

    // Step 3: Calculate the final average pass ratio
    double result = 0.0; // Sum of pass ratios
    for (int i = 0; i < n; i++)
    {
      // Iterate over all classes
      // Add the pass ratio of each class
      result += (double)classes[i][0] / classes[i][1];
    }

    // Return the average pass ratio
    return result / n;
  }
};
