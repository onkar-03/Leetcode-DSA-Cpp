#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using stack)
// T.C : O(n)
// S.C : O(n)
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

// Approach-2 (Without Using stack)
// T.C : O(n)
// S.C : O(1)
class Solution
{
public:
  // This function calculates the minimum number of parentheses to be added to make the string valid
  int minAddToMakeValid(string s)
  {
    // 'size' keeps track of the number of unmatched opening parentheses '('
    int size = 0;

    // 'open' keeps track of the number of unmatched closing parentheses ')'
    int open = 0;

    // Loop through each character in the string 's'
    for (char &ch : s)
    {
      // If the current character is an opening parenthesis '('
      if (ch == '(')
      {
        // Increment 'size' because we have an unmatched '(' that needs to be closed
        size++;
      }
      // If the current character is a closing parenthesis ')'
      else if (size > 0)
      {
        // If there's an unmatched '(' (i.e., size > 0), we decrement 'size'
        // because this ')' can balance a previous '('
        size--;
      }
      else
      {
        // If there are no unmatched opening parentheses '(' to balance the current ')'
        // Increment 'open' to keep track of unmatched closing parentheses ')'
        open++;
      }
    }

    // The total number of parentheses to add will be the sum of:
    // 1. 'open': unmatched closing parentheses ')'
    // 2. 'size': unmatched opening parentheses '('
    return open + size;
  }
};

// --- Why we used the open var here adn no in question 1963 ??
// - In this question, the issue arises from an uneven number of opening and closing parentheses, necessitating the tracking of unmatched closing parentheses ) that lack corresponding opening parentheses (.
// - In contrast, 1963. Minimum Number of Swaps to Make the String Balanced deals with a string that has an even number of brackets [], where the goal is to rearrange them through swaps, ensuring that the count of opening and closing brackets is equal but may be incorrectly ordered.