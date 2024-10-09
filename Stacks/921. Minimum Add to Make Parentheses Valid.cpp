#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minAddToMakeValid(string s)
  {
    // Declare a stack to keep track of unmatched open parentheses '('
    stack<char> st;

    // Variable to keep track of the number of unmatched closing parentheses ')'
    int open = 0;

    // Iterate through each character in the string 's'
    for (char &ch : s)
    {
      // If the current character is an opening parenthesis '('
      if (ch == '(')
      {
        // Push it onto the stack as it might need to be closed later
        st.push(ch);
      }
      // If the current character is a closing parenthesis ')'
      else if (!st.empty())
      {
        // Check if the stack is not empty, meaning we have an unmatched opening parenthesis '('
        // Pop the top element (i.e., remove the unmatched '('), as this ')' can balance it
        st.pop();
      }
      else
      {
        // If the stack is empty (no unmatched '(' to balance the current ')')
        // Increment the 'open' counter, as this ')' has no matching '('
        open++;
      }
    }

    // At the end, the stack will still contain any unmatched '(' parentheses, and 'open' will contain the number of unmatched ')' parentheses.
    // The sum of these two will give us the minimum number of parentheses to add to make the string valid.
    return open + st.size();
  }
};
