#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximumSwap(int num)
  {
    // Convert the integer 'num' into a string to easily access each digit
    string s = to_string(num);
    int n = s.length(); // Get the length of the string (number of digits in the number)

    // Vector 'maxRight' stores the index of the largest element to the right of each digit
    vector<int> maxRight(n);

    // Initialize the last element of maxRight to its own index
    maxRight[n - 1] = n - 1;

    // Traverse from the second last element to the first (right to left)
    for (int i = n - 2; i >= 0; i--)
    {
      int rightMaxIdx = maxRight[i + 1];    // Get the index of the maximum element to the right
      int rightMaxElement = s[rightMaxIdx]; // Get the maximum element value itself

      // If the current element is greater than the max element to its right, update maxRight[i] to i
      // Otherwise, keep the current maxRight[i+1] as the max index for this position
      maxRight[i] = (s[i] > rightMaxElement) ? i : rightMaxIdx;
    }

    // Traverse the digits from left to right to find the first swap opportunity
    for (int i = 0; i < n; i++)
    {
      int maxRightIdx = maxRight[i];        // Get the index of the largest element to the right
      int maxRightElement = s[maxRightIdx]; // Get the value of the largest element to the right

      // If the current element is smaller than the largest element to its right, swap them
      if (s[i] < maxRightElement)
      {
        swap(s[i], s[maxRightIdx]); // Perform the swap
        return stoi(s);             // Convert the string back to an integer and return the result
      }
    }

    // If no swap was made, return the original number
    return num;
  }
};
