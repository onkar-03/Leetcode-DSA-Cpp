#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using Stack)
// T.C: O(n) - We traverse the string once.
// S.C: O(n) - Space used by the stacks.
class Solution
{
public:
  bool canBeValid(string s, string locked)
  {
    int n = s.length();

    // If the length of the string is odd, it's impossible to make valid parentheses.
    if (n % 2 != 0)
    {
      return false;
    }

    stack<int> open;      // Stack to store indices of locked '('.
    stack<int> openClose; // Stack to store indices of unlocked characters ('0').

    // Traverse through the string.
    for (int i = 0; i < n; i++)
    {
      if (locked[i] == '0')
      {
        // If the character is unlocked ('0'), it can act as either '(' or ')'.
        openClose.push(i);
      }
      else if (s[i] == '(')
      {
        // If the character is a locked '(', push its index to the 'open' stack.
        open.push(i);
      }
      else if (s[i] == ')')
      {
        // If the character is a locked ')':
        if (!open.empty())
        {
          // If there's a '(' available in the 'open' stack, pair it and pop.
          open.pop();
        }
        else if (!openClose.empty())
        {
          // If no '(' is available, use an unlocked character as '(' and pop.
          openClose.pop();
        }
        else
        {
          // If no match is possible, the string cannot be valid.
          return false;
        }
      }
    }

    // Match any remaining '(' with available unlocked characters.
    while (!open.empty() && !openClose.empty() && open.top() < openClose.top())
    {
      open.pop();
      openClose.pop();
    }

    // If all '(' have been matched, return true, otherwise false.
    return open.empty();
  }
};

// Approach-2 (Without using stack)
// T.C: O(n) - We traverse the string twice (once from left-to-right and once from right-to-left).
// S.C: O(1) - No extra space is used apart from a few variables.
class Solution
{
public:
  bool canBeValid(string s, string locked)
  {
    int n = s.length();

    // If the length of the string is odd, it's impossible to make valid parentheses.
    if (n % 2 != 0)
    {
      return false;
    }

    // **Left-to-Right Traversal:**
    // `open` keeps track of the net count of open parentheses.
    int open = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '(' || locked[i] == '0')
      {
        // Increment `open` for locked '(' or unlocked character ('0'), which can act as '('.
        open++;
      }
      else
      {
        // Decrement `open` for locked ')'.
        open--;
      }

      // If at any point, `open` becomes negative, it means there are more ')' than '('
      // in a valid sequence up to this point. Return false as it's invalid.
      if (open < 0)
      {
        return false;
      }
    }

    // **Right-to-Left Traversal:**
    // `close` keeps track of the net count of close parentheses.
    int close = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      if (s[i] == ')' || locked[i] == '0')
      {
        // Increment `close` for locked ')' or unlocked character ('0'), which can act as ')'.
        close++;
      }
      else
      {
        // Decrement `close` for locked '('.
        close--;
      }

      // If at any point, `close` becomes negative, it means there are more '(' than ')'
      // in a valid sequence up to this point. Return false as it's invalid.
      if (close < 0)
      {
        return false;
      }
    }

    // If both traversals are valid, the string can form a valid parentheses sequence.
    return true;
  }
};
