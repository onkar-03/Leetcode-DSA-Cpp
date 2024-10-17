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

class Solution
{
public:
  int maximumSwap(int num)
  {
    // Convert the integer 'num' to a string to easily access individual digits
    string s = to_string(num);
    int n = s.length(); // Get the number of digits in the number

    // Create a vector 'maxRight' of size 10 (digits 0-9), initialized with -1
    // This will store the last occurrence index of each digit in the number
    vector<int> maxRight(10, -1);

    // Traverse through the digits and store the last occurrence of each digit
    for (int i = 0; i < n; i++)
    {
      // Convert the character 's[i]' to its integer value (e.g., '2' -> 2)
      int idx = s[i] - '0';
      // Store the index of this digit in the maxRight array
      maxRight[idx] = i;
    }

    // Traverse the number from left to right to find the first opportunity to swap
    for (int i = 0; i < n; i++)
    {
      // Current character (digit) in the string
      char currChar = s[i];
      // Convert character to integer
      int currDigit = currChar - '0';

      // Check if there exists a larger digit (from 9 to currentDigit + 1)
      for (int digit = 9; digit > currDigit; digit--)
      {
        // If a larger digit exists and appears after the current position, perform the swap
        if (maxRight[digit] > i)
        {
          // Swap current digit with the larger digit
          swap(s[i], s[maxRight[digit]]);
          // Convert the string back to integer and return the result
          return stoi(s);
        }
      }
    }

    // If no swap was made, return the original number
    return num;
  }
};
