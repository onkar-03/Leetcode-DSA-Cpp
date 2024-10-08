#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using stack)
// T.C : O(n)
// S.C : O(n)
class Solution
{
public:
  int minSwaps(string s)
  {
    // We use a stack to track unmatched opening brackets '['
    stack<char> st;

    // Iterate over each character in the input string 's'
    for (char &ch : s)
    {
      // If the current character is an opening bracket '['
      if (ch == '[')
        st.push(ch); // Push it onto the stack (track it as unmatched)
      else if (!st.empty())
      {
        // If the current character is a closing bracket ']' and the stack is not empty
        // This means there is at least one unmatched opening bracket '[' in the stack so we can match this closing bracket ']' with it.
        st.pop(); // Remove (pop) one unmatched opening bracket '[' from the stack
      }
    }

    // At the end of the loop, the stack contains only unmatched opening brackets.
    // Each unmatched opening bracket needs to be swapped with a closing bracket to create a valid balanced substring.
    // The formula (stack size + 1) / 2 gives the minimum number of swaps needed.
    // Since each swap can fix two misplaced brackets (one opening and one closing).
    return (st.size() + 1) / 2;
  }
};

// Approach-2: Efficient solution without using a stack
// Time Complexity: O(n) - We traverse the string once
// Space Complexity: O(1) - Constant space is used (no additional data structures)
class Solution
{
public:
  int minSwaps(string s)
  {
    // 'size' will act as a counter to track unmatched opening brackets '['
    int size = 0;

    // Iterate over each character in the input string 's'
    for (char &ch : s)
    {
      if (ch == '[')
      {
        // If the character is an opening bracket '['
        // Increment the counter 'size' to track the unmatched opening bracket
        size++;
      }
      else if (size > 0)
      {
        // If the character is a closing bracket ']' and there is at least one unmatched opening bracket
        // This means there is a potential to match this closing bracket with a previously unmatched opening bracket
        // So we decrement the counter, indicating one matching has occurred
        size--;
      }
    }

    // After the loop, 'size' will hold the count of unmatched opening brackets '['.
    // Since each swap can fix two mismatched brackets (one opening and one closing),
    // the formula (size + 1) / 2 computes the minimum number of swaps needed to balance the string.
    return (size + 1) / 2;
  }
};
