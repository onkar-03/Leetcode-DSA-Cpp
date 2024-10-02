#include <bits/stdc++.h>
using namespace std;

// Approach (Using Array + Lazy Propagation)
// Time Complexity : push : O(1), pop : O(1), increment : O(1)
// Space Complexity : O(maxSize)

// Custom stack class definition
class CustomStack
{
public:
  // Vector to store the stack elements
  vector<int> st;

  // Vector to store the increments for lazy propagation
  vector<int> increments;

  // Integer to store the maximum size of the stack
  int n;

  // Constructor to initialize the stack with a maximum size
  CustomStack(int maxSize)
  {
    n = maxSize; // Set the maximum size to 'n'
  }

  // Method to push an element onto the stack
  void push(int x)
  {
    // Check if the stack has space to push another element
    if (st.size() < n)
    {
      // Push the element to the stack
      st.push_back(x);

      // Initialize the increment value for this element to 0
      increments.push_back(0);
    }
  }

  // Method to pop the top element from the stack
  int pop()
  {
    // If the stack is empty, return -1
    if (st.size() == 0)
    {
      return -1;
    }

    // Get the index of the top element
    int idx = st.size() - 1; // top element index

    // Lazy propagate the increment to the element just below the top
    if (idx > 0)
    {
      increments[idx - 1] += increments[idx]; // Transfer the increment value
    }

    // Add the lazy increment to the top element
    int top_val = st[idx] + increments[idx];

    // Remove the top element from the stack
    st.pop_back();

    // Remove the increment associated with the top element
    increments.pop_back();

    // Return the value of the popped element
    return top_val;
  }

  // Method to increment the bottom 'k' elements by 'val'
  void increment(int k, int val)
  {
    // Find the index of the last element to be incremented
    int idx = min(k, (int)st.size()) - 1;

    // If the index is valid (greater than or equal to 0)
    if (idx >= 0)
    {
      // Add the increment value to the appropriate position
      increments[idx] += val;
    }
  }
};
