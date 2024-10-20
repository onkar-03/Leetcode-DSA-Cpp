#include <bits/stdc++.h>
using namespace std;

// Approach (Using stack)
// T.C : O(n)
// S.C : O(n)
class Solution
{
public:
  // Helper function to apply the operator (op) to the values.
  // It takes a vector of 't'/'f' values and applies the operation based on '!', '&', or '|'.
  char solveOperator(vector<char> &values, char op)
  {
    // If the operator is '!', it inverts the single value: 't' becomes 'f' and 'f' becomes 't'.
    if (op == '!')
    {
      return values[0] == 't' ? 'f' : 't'; // There should only be one value in '!' case.
    }

    // If the operator is '&', it returns 'f' if any value in the vector is 'f' (logical AND).
    if (op == '&')
    {
      for (char &ch : values)
      {
        if (ch == 'f')
        {
          return 'f'; // If any value is 'f', the result of AND is 'f'.
        }
      }
      return 't'; // Otherwise, if all values are 't', the result is 't'.
    }

    // If the operator is '|', it returns 't' if any value in the vector is 't' (logical OR).
    if (op == '|')
    {
      for (char &ch : values)
      {
        if (ch == 't')
        {
          return 't'; // If any value is 't', the result of OR is 't'.
        }
      }
      return 'f'; // Otherwise, if all values are 'f', the result is 'f'.
    }

    // This line should never be reached because 'op' should always be '!', '&', or '|'.
    return -1;
  }

  // Main function to parse and evaluate a boolean expression.
  bool parseBoolExpr(string expression)
  {
    int n = expression.size(); // Get the size of the expression.
    stack<char> st;            // Use a stack to help evaluate the expression.

    // Loop through each character in the expression.
    for (int i = 0; i < n; i++)
    {
      char c = expression[i]; // Get the current character.

      // Skip commas as they are just delimiters and not part of the logic.
      if (c == ',')
      {
        continue;
      }

      // If we find a closing parenthesis ')', we need to evaluate the expression inside.
      if (c == ')')
      {
        vector<char> values; // To collect the values between '(' and ')'.

        // Pop values off the stack until we hit the open parenthesis '('.
        while (st.top() != '(')
        {
          values.push_back(st.top()); // Add the current value to the list.
          st.pop();                   // Remove the value from the stack.
        }

        // Pop the open parenthesis '(' from the stack.
        st.pop();

        // Get the operator (either '!', '&', or '|') from the stack.
        char op = st.top();
        st.pop(); // Remove the operator from the stack.

        // Evaluate the expression with the operator and values, then push the result back to the stack.
        st.push(solveOperator(values, op));
      }
      else
      {
        // If the character is not ')', push it onto the stack. This includes operators ('!', '&', '|'),
        // open parenthesis '(', and boolean values ('t' or 'f').
        st.push(c);
      }
    }

    // After the loop, the stack should contain only one value, the result of the entire expression.
    // If the top of the stack is 't', return true. Otherwise, return false.
    return st.top() == 't' ? true : false;
  }
};
